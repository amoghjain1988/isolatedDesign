#ifndef EventsBridge
#define EventsBridge
class eventbrAbstract{

public:
eventbrAbstract(){};
~eventbrAbstract(){};
// virtual void updateEventList()  =0;
// virtual void ExtractEvent()     =0;
// virtual void update(){}=s;
};


class myEventBridge{

public:

template<typename ev>
void UpdateStateMachine(ev myeve){


}

};

extern myEventBridge eventBridge;


#endif
