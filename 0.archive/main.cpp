#include <iostream>
#include <typeinfo>
#include <chrono>
#include <thread>

/**
 * The base State class declares methods that all Concrete State should
 * implement and also provides a backreference to the CurrentState object, associated
 * with the State. This backreference can be used by States to transition the
 * CurrentState to another State.
 */
bool EventSendStatus;


class CurrentState;

class State {

 protected:
            CurrentState *context_;

 public:
            virtual ~State() {}

            void set_Current_State(CurrentState *context) {
                this->context_ = context;
            }

            virtual void Handle_Queue_Data()        = 0;
            virtual void Handle_PassState()         = 0;
            virtual void Handle_FailState()         = 0;

};


class CurrentState {
    
 private:
            State *state_;

 public:
            CurrentState(State *state) : state_(nullptr) {
                this->TransitionTo(state);
            }
            ~CurrentState() {
                delete state_;
            }
        
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
            void Send_Queue_Data() {
                this->state_->Handle_Queue_Data();
            }
            void Pass_State() {
                this->state_->Handle_PassState();
            }

            void Fail_State(){
                this->state_->Handle_FailState();
            }
};


class FirstCommunication : public State {
 public:
            void Handle_Queue_Data() override{
            std::cout<<"\n 1. Sending Startup Event!!";

            this->Handle_PassState();

            }

            void Handle_PassState() override ;
            void Handle_FailState() override {
                std::cout<<"\n Handle Fail State for Initial";
            }

};

class RoutineCommunication : public State {
 public:
            void Handle_Queue_Data() override {
                std::cout << "RoutineCommunication handles Queue Parse Statw.\n";
            }
            void Handle_PassState() override {
                std::cout << "RoutineCommunication handles Pass Event.\n";
                std::cout << "RoutineCommunication wants to change the state of the context.\n";
                this->Handle_Queue_Data();
                // this->context_->TransitionTo(new FirstCommunication);
            }
            void Handle_FailState() override {
                std::cout<<"\n Handle Fail State for Routine";
            }

};

void FirstCommunication::Handle_PassState() {
  {
    std::cout << "FirstCommunication handles Pass State.\n";
    std::cout << "FirstCommunication wants to change the state of the context.\n";
    // this->Handle_PassState();

    this->context_->TransitionTo(new RoutineCommunication);
  }
}




    using namespace std::this_thread; // sleep_for, sleep_until
    using namespace std::chrono; // nanoseconds, system_clock, seconds

int main() {
  
  CurrentState *context = new CurrentState(new FirstCommunication);
  while(1)
  {
        context->Send_Queue_Data();
        sleep_until(system_clock::now() + seconds(2));


  }
//   context->Pass_State();
  delete context;
  
  return 0;
}