#ifndef MAIN_H  
#define MAIN_H

#define MAX_STRING_SIZE 80
#define ARRAY_SIZE 200
#define LINE_SIZE 80
#define INITIAL_SIZE 1
#define DATA_SIZE 9


int menu_int;

/*
typedef struct connection_S
{
    char cell_num[MAX_STRING_SIZE];
    char mac[MAX_STRING_SIZE];
    char essid[MAX_STRING_SIZE];
    char mode[MAX_STRING_SIZE];
    char channel[MAX_STRING_SIZE];
    char en_key[MAX_STRING_SIZE];
    char quality[MAX_STRING_SIZE];
    char freq[MAX_STRING_SIZE];
    char signal_l[MAX_STRING_SIZE];
} connection;
*/

//this is our Node struct
typedef struct Node_t {
    char cell_num[MAX_STRING_SIZE];
    char mac[MAX_STRING_SIZE];
    char essid[MAX_STRING_SIZE];
    char mode[MAX_STRING_SIZE];
    char channel[MAX_STRING_SIZE];
    char en_key[MAX_STRING_SIZE];
    char quality[MAX_STRING_SIZE];
    char freq[MAX_STRING_SIZE];
    char signal_l[MAX_STRING_SIZE];
    struct Node_t *next;
} Node;

int cell_num;
Node *header_Node;

void create_Node();

/*
void append(Node **head_ref, Node *new_Node);
void delete_Node(Node **head_ref, char ESSID[]);
*/

void clear_list(Node *head_ref);


//this is our struct of connections
//connection *p_connections;


void print_menu();
int choose_cell();
#endif
