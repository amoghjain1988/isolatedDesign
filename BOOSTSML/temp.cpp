#include "boost_SML.h"


// $CXX -std=c++14 data.cpp
#include <cassert>
#include <iostream>

namespace sml = boost::sml;

namespace {
struct connect {
  int id{};
};
struct disconnect {};
struct interrupt {};

struct Disconnected {};
struct Connected {
  int id{};  /// per state data
};
struct Interrupted {
  int id{};  /// per state data
};

class data {
  using Self = data;

 public:
  explicit data(const std::string& address) : address{address} {}

  auto operator()() {
    using namespace boost::sml;

    const auto set = [](const auto& event, Connected& state) { state.id = event.id; };
    const auto update = [](Connected& src_state, Interrupted& dst_state) { dst_state.id = src_state.id; };

    return make_transition_table(
      * state<Disconnected> + event<connect>    / (set, &Self::print)    = state<Connected>
      , state<Connected>    + event<interrupt>  / (update, &Self::print) = state<Interrupted>
      , state<Interrupted>  + event<connect>    / (set, &Self::print)    = state<Connected>
      , state<Connected>    + event<disconnect> / (&Self::print)         = X
    );
  }

 private:
  void print(Connected& state) { std::cout << address << ':' << state.id << '\n'; };

  std::string address{};  /// shared data between states
};
}  // namespace

int main() {
  data d{std::string{"127.0.0.1"}};
  sml::sm<data> sm{d, Connected{1}};
  sm.process_event(connect{1028});
  sm.process_event(interrupt{});
  sm.process_event(connect{1025});
  sm.process_event(disconnect{});
  assert(sm.is(sml::X));

  return 0;
}
