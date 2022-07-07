#include "msfsm.hpp"
#include <iostream>

using namespace std;


class Up {};
class Down {};
class testevent{};
class setupEvent{};

class Admin : public msfsm::Fsm<Admin> {
public:
    Admin() {
        cout<<"\n Administrator Transitioning\n";

        transition(CommsState);
    }

private:
    friend Fsm;

    class State : public Fsm::State {
        friend Fsm;
        using Fsm::State::State;
        virtual void event(Up)   { cout << "Ignoring Up event" << endl; }
        virtual void event(Down) { cout << "Ignoring Down event" << endl; }
        virtual void event(testevent) {cout << "Ignoring Test event" << endl;  }
        virtual void event(setupEvent) {cout << "Ignoring setup event" << endl;  }

    };

    class HW_State : public State {
        friend Fsm;
        using State::State;
        
        void entry() {
            cout << "Entering HW_State" << endl;
        }
        void event(Down) override {
            transition(fsm.CommsState);
        }
        void event(testevent) override{
            cout<<"\t Test Event parsed by HW_State\n";
            transition(fsm.HW_State);

        }

        void event(setupEvent){
                        cout<<"\t Going to Setup State\n";
                                               transition(fsm.ObjectSetup);


        }
        void exit() override{
            //transition(fsm.HW_State);
            cout<<"\t Exiting HW_State State\n";

        }

        
    } HW_State {this};

    class CommsState : public State {
        friend Fsm;
        using State::State;
        void entry() {
            cout << "Entering CommsState" << endl;
        }
        void event(Up) override {
            transition(fsm.HW_State);
        }
        void exit() override {
            cout << "\tExiting CommsState" << endl;
        }
    } CommsState {this};

    class ObjectSetup : public State {
        friend Fsm;
        using State::State;
        void entry() {
            cout << "Entering ObjectSetup" << endl;
        }
      
        void exit() override {
            cout << "\tExiting ObjectSetup\n" << endl;
        }

        void event(setupEvent)override{
                        cout << "Setup Event\n" << endl;

        }
    } ObjectSetup {this};
};

int main(int argc, char *argv[])
{
    Admin administrator;
    administrator.handle(Up());
    administrator.handle(Up());
    administrator.handle(Down());
    administrator.handle(Down());
        administrator.handle(Up());

    administrator.handle(testevent());
    administrator.handle(setupEvent());

    return 0;
}