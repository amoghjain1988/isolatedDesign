#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of vertices in the graph

#define MACROSTR(k) #k

/// List of Events
#define TM_STATES_NUMBERS \
       X(NOT_YET_STARTED  ) \
       X(STATE_BOOTUP   ) \
       X(STATE_WATER_ON   ) \
       X(STATE_WATER_OFF ) \
       X(STATE_ROUTINE  ) \
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
       X(BOOTUP_CHECK_START   ) \
       X(BOOTUP_CHECK_FINISHED   ) \
       X(BLE_NOT_INIT ) \
       X(KVS_GET_FLASH_VALUES  ) \
       X(KVS_SET_FLASH_VALUES  ) \
       X(WAKEUP_SRC_POWERON  ) \
       X(WAKEUP_SRC_USERBTN  ) \
       X(WAKEUP_SRC_INLINE_SENSOR  ) \
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

// Data structure to store a graph object
struct Graph
{
    // An array of pointers to Node to represent an adjacency list
    struct Node* AdjList[MAX_VERTICES];
};
 
// Data structure to store adjacency list nodes of the graph
struct Node
{
    SYSTEM_STATE    next_state;
    TM_EVENTS_t     event;
    struct Node*    next;
};
 
// Data structure to store a graph edge
struct Edge 
{
    SYSTEM_STATE    curr_state;
    TM_EVENTS_t     event;
    pEventHandler   event_action;
    SYSTEM_STATE    next_state;

};
 
// Function to create an adjacency list from specified edges
struct Graph* createGraph(struct Edge edges[], int n)
{
    // allocate storage for the graph data structure
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
 
    // initialize head pointer for all vertices
    for (int i = 0; i < MAX_VERTICES; i++) 
    {
        graph->AdjList[i] = NULL;
    }
 
    // add edges to the directed graph one by one
    for (int i = 0; i < n; i++)
    {
        // get the source and destination vertex
        SYSTEM_STATE src    = edges[i].curr_state;
        SYSTEM_STATE dest   = edges[i].next_state;
        TM_EVENTS_t event   = edges[i].event;
 
        // allocate a new node of adjacency list from src to dest
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->next_state = dest;
        newNode->event = event;
 
        // point new node to the current head
        newNode->next = graph->AdjList[src];
 
        // point head pointer to the new node
        graph->AdjList[src] = newNode;
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
        struct Node* ptr = graph->AdjList[i];

        if(!ptr)
        {
            printf("\t\t No EDGES");
            continue;
        }
        while (ptr != NULL)
        {
            printf("\n\t\t\t\t Adjlist => Event [%s] => State [%s]\t", kEvntStr[ptr->event],kSystemStatesStr[ptr->next_state]);
            
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

// Weighted Directed graph implementation in C
int main(void)
{
    // input array containing edges of the graph (as per the above diagram)
    // (x, y, w) tuple represents an edge from x to y having weight `w`
    struct Edge edges[] =
    {
        {NOT_YET_STARTED,   BOOTUP_CHECK_START,             BootUpAction,  STATE_BOOTUP    },          // Stay in Routine until Finished is Released..        
        {STATE_BOOTUP,      BOOTUP_CHECK_START,             BootUpAction,  STATE_BOOTUP    },          // Stay in Routine until Finished is Released..
        {STATE_BOOTUP,      BOOTUP_CHECK_FINISHED,          BootUpAction,  STATE_ROUTINE   }, 
        {STATE_WATER_ON,    SYSTEM_STATE_WATER_ON,          BootUpAction,  STATE_WATER_ON  },          // Stay in Water On State if Water is Found..
        {STATE_WATER_ON,    SYSTEM_STATE_WATER_OFF,         BootUpAction,  STATE_WATER_OFF },          // Water On Transitions to Water Off..
        {STATE_WATER_OFF,   SYSTEM_STATE_WATER_OFF,         BootUpAction,  STATE_ROUTINE   }, 
        {STATE_ROUTINE,     SYSTEM_STATE_LIGHT_SLEEP_INIT,  BootUpAction,  STATE_SLEEP     }, 
        {STATE_ROUTINE,     SYSTEM_STATE_DEEP_SLEEP_INIT,   BootUpAction,  STATE_SLEEP     }, 

    };
 
    // calculate the total number of edges
    int edge_count = sizeof(edges)/sizeof(edges[0]);
    printf("\n Edge Count : [%d]", edge_count);

    // construct a graph from the given edges
    struct Graph *graph = createGraph(edges, edge_count);
 

    // Function to print adjacency list representation of a graph
    printStateTransitionTable(graph);

     printf("\n CUrrent State : %s", kSystemStatesStr[graph->AdjList[0]->next_state]);
     printf("\n CUrrent Event Waiting for : %s\n \n", kEvntStr[graph->AdjList[0]->event]);
    //  graph->AdjList[1]->next

    return 0;
}