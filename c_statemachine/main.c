#include <stdio.h>
#include <stdlib.h>
#include <time.h>
       #include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>
// Define the maximum number of vertices in the graph

#define MACROSTR(k) #k
#define MACROFUNSTR(func_name) #func_name

/// List of Events defined using xMacro
#define TM_STATES_NUMBERS \
       X(NOT_YET_STARTED  ) \
       X(STATE_FACTORY_RESET  ) \
       X(STATE_ANY_ALL  ) \
       X(STATE_BOOTUP   ) \
       X(STATE_WOKEUP   ) \
       X(STATE_WATER_ON   ) \
       X(STATE_WATER_OFF ) \
       X(STATE_ROUTINE  ) \
       X(STATE_IDLE  ) \
       X(STATE_SLEEP  ) \
       X(STATE_ERROR  ) \
       X(STATE_NOT_UNUSED   )

#define MAX_VERTICES STATE_NOT_UNUSED

typedef enum 
{
    // Generates the list of Events
    #define X(Enum)       Enum,
        TM_STATES_NUMBERS
    #undef X
} SYSTEM_STATE;

static char *kSystemStatesStr[] = 
{
    // generates a list of strings
    #define X(String) MACROSTR(String),
        TM_STATES_NUMBERS
    #undef X
};


/// List of Events
#define TM_EVENTS_NUMBERS \
       X(NO_EVENTS  ) \
       X(ANY_EVENTS  ) \
       X(BOOTUP_CHECK_START   ) \
       X(BOOTUP_CHECK_FINISHED   ) \
       X(BLE_NOT_INIT ) \
       X(KVS_GET_FLASH_VALUES  ) \
       X(KVS_SET_FLASH_VALUES  ) \
       X(USER_BTN_SHORT_PRESS  ) \
       X(USER_BTN_LONG_PRESS  ) \
       X(WAKEUP_SRC_POWERON  ) \
       X(WAKEUP_SRC_USERBTN  ) \
       X(WAKEUP_SRC_INLINE_SENSOR  ) \
       X(UPDATE_HW_VALUES  ) \
       X(SYSTEM_STATE_WATER_ON  ) \
       X(SYSTEM_STATE_WATER_OFF  ) \
       X(SYSTEM_STATE_ROUTINE  ) \
       X(SYSTEM_STATE_SLEEP_LIGHT  ) \
       X(SYSTEM_STATE_SLEEP_DEEP  ) \
       X(SYSTEM_STATE_LIGHT_SLEEP_INIT  ) \
       X(SYSTEM_STATE_DEEP_SLEEP_INIT  ) \
       X(EVENT_ERROR  ) \
       X(EVENT_COUNT   )
    

typedef enum 
{
    // Generates the list of Events
    #define X(Enum)       Enum,
        TM_EVENTS_NUMBERS
    #undef X
} TM_EVENTS_t;


static char *kEvntStr[] = 
{
    // generates a list of strings
    #define X(String) MACROSTR(String),
        TM_EVENTS_NUMBERS
    #undef X
};

typedef TM_EVENTS_t(*pEventHandler)();

// Data structure to store a graph edge
struct Edge 
{
    SYSTEM_STATE    curr_state;
    TM_EVENTS_t     event;
    pEventHandler   event_action;
    SYSTEM_STATE    next_state;

};

// Data structure to store adjacency list nodes of the graph
struct Node
{
    struct Edge     curr_event;
    struct Node*    next;
};




// Data structure to store a graph object
struct Graph
{
    // An array of pointers to Node to represent an adjacency list
    struct Node* TransitionTable[MAX_VERTICES];
};


// Function to create an adjacency list from specified edges
struct Graph* createGraph(struct Edge edges[], int edge_count)
{
    // allocate storage for the graph data structure
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
 
    // initialize head pointer for all vertices
    for (int i = 0; i < MAX_VERTICES; i++) 
    {
        graph->TransitionTable[i] = NULL;
    }
 
    // add edges to the directed graph one by one
    for (int i = 0; i < edge_count; i++)
    {
        // get the source and destination vertex
        SYSTEM_STATE src    = edges[i].curr_state;
        SYSTEM_STATE dest   = edges[i].next_state;
        TM_EVENTS_t event   = edges[i].event;
        pEventHandler ev_action = edges[i].event_action;

        //printf("\n i:[%d], src :[%s], event: [%s], dest:[%s]",i, kSystemStatesStr[src], kEvntStr[event], kSystemStatesStr[dest]);

        // allocate a new node of adjacency list from src to dest
        struct Node* newNode    = (struct Node*)malloc(sizeof(struct Node));
        
        newNode->curr_event.next_state      = dest;
        newNode->curr_event.event           = event;
        newNode->curr_event.curr_state      = src;
        newNode->curr_event.event_action    = ev_action;

        // point new node to the current head
        newNode->next = graph->TransitionTable[src];
 
        // point head pointer to the new node
        graph->TransitionTable[src] = newNode;
    }
 
    return graph;
}
 
// Function to print adjacency list representation of a graph
void printStateTransitionTable(struct Graph* graph)
{
    for (int i = 0; i < MAX_VERTICES; i++)
    {
        // print current vertex and all its neighbors
        printf("\n ------ [%s]------", kSystemStatesStr[i]);
        struct Node* ptr = graph->TransitionTable[i];

        if(!ptr)
        {
            printf("\t\t No EDGES");
            continue;
        }
        while (ptr != NULL)
        {
            printf("\n\t\t\t\t ==> Event [%s] => State [%s]\t", kEvntStr[ptr->curr_event.event],kSystemStatesStr[ptr->curr_event.next_state]);
            
            ptr = ptr->next;
        }

 
    }

    printf("\n\n");
}
 
TM_EVENTS_t BootUpAction()
{
    printf("\n Bootup Function");
    return STATE_ROUTINE;
}


void EventCycler()
{

}

bool EventFoundInState(struct Node* NodeList, SYSTEM_STATE current_state,TM_EVENTS_t current_event, SYSTEM_STATE *next_state )
{
    if(!NodeList)
    {
       // printf("'\n Invalid State. No Events Attached to this state yet..");
        return false;
    }
    while(NodeList!=NULL)
    {

        if(!NodeList->curr_event.next_state)
        {
            // printf("\n Event ")
            return false;

        }
        SYSTEM_STATE transition_to_state    = NodeList->curr_event.next_state;
        TM_EVENTS_t transition_event        = NodeList->curr_event.event;

        const char *str_next_state          = kSystemStatesStr[transition_to_state];
        const char *str_transition_event    = kEvntStr[transition_event];
        
        // printf("\n Start State[#%d]  = : %s", current_state, kSystemStatesStr[current_state]);
        // printf(" ||\tTransition Event : %s", str_transition_event);
        // printf(" ||\tNext State [#%d]  = : %s", next_state, str_next_state);

        if(current_event == transition_event)
        {
           // printf("\t Event [%s] Found in state : [%s]. [Action Fn Called]",kEvntStr[current_event], kSystemStatesStr[current_state]);
            *next_state = transition_to_state;
            // NodeList->event_found_action();
            return true;
        }

        NodeList = NodeList->next;

    }
    // printf("\n Ignoring Event [%s]  as it is not Associated with Current State [%s]... ",kEvntStr[current_event], kSystemStatesStr[current_state]);
    return false;
}

int random_generator(int min, int max){
    
    return min + rand() / (RAND_MAX / (max - min + 1) + 1);
}


void MakeAdjancencyList(struct Edge edges[])
{
    
}

// Weighted Directed graph implementation in C
int main(void)
{   
    srand(time(NULL));
    
    // input array containing edges of the graph (as per the above diagram)
    struct Edge edges[] =
    {

        // Events applicable to ANY STATE
        {STATE_ANY_ALL,     USER_BTN_LONG_PRESS,            BootUpAction,  STATE_FACTORY_RESET },          
        {STATE_ANY_ALL,     SYSTEM_STATE_LIGHT_SLEEP_INIT,  BootUpAction,  STATE_SLEEP     },

        {STATE_ERROR,       ANY_EVENTS,                     BootUpAction,  STATE_ERROR   },          


        {NOT_YET_STARTED,   BOOTUP_CHECK_START,             BootUpAction,  STATE_BOOTUP    },              
        {STATE_BOOTUP,      BOOTUP_CHECK_START,             BootUpAction,  STATE_BOOTUP    },          
        {STATE_BOOTUP,      BOOTUP_CHECK_FINISHED,          BootUpAction,  STATE_IDLE      }, 
        
        {STATE_WATER_ON,    SYSTEM_STATE_WATER_ON,          BootUpAction,  STATE_WATER_ON  },          
        {STATE_WATER_OFF,   SYSTEM_STATE_WATER_OFF,         BootUpAction,  STATE_ROUTINE   }, 
        
        {STATE_WATER_ON,    SYSTEM_STATE_WATER_OFF,         BootUpAction,  STATE_WATER_OFF },          

        {STATE_WATER_ON,    USER_BTN_SHORT_PRESS,           BootUpAction,  STATE_WATER_OFF },   
        {STATE_SLEEP,       USER_BTN_SHORT_PRESS,           BootUpAction,  STATE_WOKEUP},  



        {STATE_ROUTINE,     SYSTEM_STATE_DEEP_SLEEP_INIT,   BootUpAction,  STATE_SLEEP     },

        {STATE_ROUTINE,     EVENT_ERROR,                    BootUpAction,  STATE_ERROR     },
        
        {STATE_IDLE,        UPDATE_HW_VALUES,               BootUpAction,  STATE_ROUTINE   }, 
        {STATE_WATER_ON,    UPDATE_HW_VALUES,               BootUpAction,  STATE_ROUTINE   },          
        {STATE_WATER_OFF,   UPDATE_HW_VALUES,               BootUpAction,  STATE_ROUTINE   },



    };
 
    // calculate the total number of edges
    int edge_count = sizeof(edges)/sizeof(edges[0]);
    printf("\n Edge Count : [%d]\n", edge_count);

    // construct a graph from the given edges
    struct Graph *graph = createGraph(edges, edge_count);
 

    // Function to print adjacency list representation of a graph
    //printStateTransitionTable(graph);


    int x = 0;

    SYSTEM_STATE random_state = random_generator(NOT_YET_STARTED+1, STATE_NOT_UNUSED-1);

    while(x<200)
    {
        // printf("\n\t\t ~~~~~~~~~~~~~~~~ x=[%d]~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~", x);

        struct Node* NodeList = (struct Node*)malloc(sizeof( struct Node));

        x++;
        TM_EVENTS_t random_event = random_generator(ANY_EVENTS, EVENT_COUNT-1);

        const char* random_state_str = kSystemStatesStr[random_state];
        const char* random_event_str = kEvntStr[random_event];


        NodeList = graph->TransitionTable[random_state];
        SYSTEM_STATE *outputState = malloc(sizeof(SYSTEM_STATE)); 

        if(EventFoundInState(NodeList,random_state,random_event,outputState))
        {
            printf("\n State : [%s], Event : [%s], Next State : [%s]",random_state_str,  random_event_str,kSystemStatesStr[*outputState]);     
            random_state = *outputState;
        }
        

        free(NodeList);
        // sleep(1);

    }


    printf("\n ~~~~~~~~~~~~~~~~~~~~~~END ~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");

    return 0;
}