#ifndef STRUCT_H
#define STRUCT_H

#include "../incl/main.h"

typedef struct conexions{
    int nconn;
    char mac[MAX_STRING_SIZE];
    char essid[MAX_STRING_SIZE];
    char mode[MAX_STRING_SIZE];
    int channel;
    char en_key[MAX_STRING_SIZE];
    int quality;
    char freq[MAX_STRING_SIZE];
    char signal_l[MAX_STRING_SIZE];
}conn;

//the declaration for each of our nodes with conn structure inside of the cells(1-21).
typedef struct Node{
    conn info;
    struct Node *next;
}Node

//New node creation & insertion & delete & delete_all

Node *create_node(conn info);
void insert(Node **head_ref, Node *new_node);
void delete(Node **head_ref, char essid[]);
void delete_all(Node **head_ref);

#endif