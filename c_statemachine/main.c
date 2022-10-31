#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of vertices in the graph
#define N 10

#define MACROSTR(k) #k

/// List of Events
#define TM_STATES_NUMBERS \
       X(NOT_YET_SET  ) \
       X(STATE_BOOTUP   ) \
       X(STATE_WATER_ON   ) \
       X(STATE_WATER_OFF ) \
       X(STATE_ROUTINE  ) \
       X(STATE_SLEEP  ) \
       X(STATE_ERROR  ) \
       X(STATE_NOT_UNUSED   )


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


// Data structure to store a graph object
struct Graph
{
    // An array of pointers to Node to represent an adjacency list
    struct Node* head[N];
};
 
// Data structure to store adjacency list nodes of the graph
struct Node
{
    SYSTEM_STATE dest;
    TM_EVENTS_t event;
    struct Node* next;
};
 
// Data structure to store a graph edge
struct Edge 
{
    SYSTEM_STATE curr_state;
    TM_EVENTS_t event;
    SYSTEM_STATE next_state;

};
 
// Function to create an adjacency list from specified edges
struct Graph* createGraph(struct Edge edges[], int n)
{
    // allocate storage for the graph data structure
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
 
    // initialize head pointer for all vertices
    for (int i = 0; i < N; i++) 
    {
        graph->head[i] = NULL;
    }
 
    // add edges to the directed graph one by one
    for (int i = 0; i < n; i++)
    {
        // get the source and destination vertex
        int src = edges[i].curr_state;
        int dest = edges[i].next_state;
        int event = edges[i].event;
 
        // allocate a new node of adjacency list from src to dest
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->dest = dest;
        newNode->event = event;
 
        // point new node to the current head
        newNode->next = graph->head[src];
 
        // point head pointer to the new node
        graph->head[src] = newNode;
    }
 
    return graph;
}
 
// Function to print adjacency list representation of a graph
void printStateTransitionTable(struct Graph* graph)
{
    for (int i = 0; i < N; i++)
    {
        // print current vertex and all its neighbors
        struct Node* ptr = graph->head[i];
        while (ptr != NULL)
        {
            printf("\n State [%s] + Event [%s] => State [%s]\t", kSystemStatesStr[i], kEvntStr[ptr->event],kSystemStatesStr[ptr->dest]);
            ptr = ptr->next;
        }
 
    }

    printf("\n\n");
}
 
// Weighted Directed graph implementation in C
int main(void)
{
    // input array containing edges of the graph (as per the above diagram)
    // (x, y, w) tuple represents an edge from x to y having weight `w`
    struct Edge edges[] =
    {
        {STATE_BOOTUP,      BOOTUP_CHECK_START,             STATE_BOOTUP    },          // Stay in Routine until Finished is Released..
        {STATE_BOOTUP,      BOOTUP_CHECK_FINISHED,          STATE_ROUTINE   }, 
        {STATE_WATER_ON,    SYSTEM_STATE_WATER_ON,          STATE_WATER_ON  },        // Stay in Water On State if Water is Found..
        {STATE_WATER_ON,    SYSTEM_STATE_WATER_OFF,         STATE_WATER_OFF },       // Water On Transitions to Water Off..
        {STATE_WATER_OFF,   SYSTEM_STATE_WATER_OFF,         STATE_ROUTINE   }, 
        {STATE_ROUTINE,     SYSTEM_STATE_LIGHT_SLEEP_INIT,  STATE_SLEEP     }, 
        {STATE_ROUTINE,     SYSTEM_STATE_DEEP_SLEEP_INIT,   STATE_SLEEP     }, 

    };
 
    // calculate the total number of edges
    int n = sizeof(edges)/sizeof(edges[0]);
 
    // construct a graph from the given edges
    struct Graph *graph = createGraph(edges, n);
 
    // Function to print adjacency list representation of a graph
    printStateTransitionTable(graph);


    return 0;
}