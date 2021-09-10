#include <iostream>
#include <typeinfo>
/**
 * The base State class declares methods that all Concrete State should
 * implement and also provides a backreference to the CurrentState object, associated
 * with the State. This backreference can be used by States to transition the
 * CurrentState to another State.
 */

class CurrentState;

class State {
  /**
   * @var CurrentState
   */
 protected:
  CurrentState *context_;

 public:
  virtual ~State() {}

  void set_Current_State(CurrentState *context) {
    this->context_ = context;
  }

  virtual void Handle_InitialState() = 0;
  virtual void Handle_PassState()       = 0;
//   virtual void Handle_FailState()       = 0;

};

/**
 * The CurrentState defines the interface of interest to clients. It also maintains a
 * reference to an instance of a State subclass, which represents the current
 * state of the CurrentState.
 */
class CurrentState {
  /**
   * @var State A reference to the current state of the CurrentState.
   */
 private:
  State *state_;

 public:
  CurrentState(State *state) : state_(nullptr) {
    this->TransitionTo(state);
  }
  ~CurrentState() {
    delete state_;
  }
  /**
   * The CurrentState allows changing the State object at runtime.
   */
  void TransitionTo(State *state) {
    std::cout << "CurrentState: Transition to " << typeid(*state).name() << ".\n";
    if (this->state_ != nullptr)
      delete this->state_;
    this->state_ = state;
    this->state_->set_Current_State(this);
  }
  /**
   * The CurrentState delegates part of its behavior to the current State object.
   */
  void Initial_State() {
    this->state_->Handle_InitialState();
  }
  void Pass_State() {
    this->state_->Handle_PassState();
  }
};

/**
 * Concrete States implement various behaviors, associated with a state of the
 * CurrentState.
 */

class FirstCommunication : public State {
 public:
  void Handle_InitialState() override;

  void Handle_PassState() override {
    std::cout << "FirstCommunication handles request2.\n";
  }
};

class RoutineCommunication : public State {
 public:
  void Handle_InitialState() override {
    std::cout << "RoutineCommunication handles request1.\n";
  }
  void Handle_PassState() override {
    std::cout << "RoutineCommunication handles request2.\n";
    std::cout << "RoutineCommunication wants to change the state of the context.\n";
    this->context_->TransitionTo(new FirstCommunication);
  }
};

void FirstCommunication::Handle_InitialState() {
  {
    std::cout << "FirstCommunication handles request1.\n";
    std::cout << "FirstCommunication wants to change the state of the context.\n";

    this->context_->TransitionTo(new RoutineCommunication);
  }
}

/**
 * The client code.
 */
void ClientCode() {
  CurrentState *context = new CurrentState(new FirstCommunication);
  context->Initial_State();
  context->Pass_State();
  delete context;
}

int main() {
  ClientCode();
  return 0;
}