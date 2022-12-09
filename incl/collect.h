#ifndef COLLECT_H
#define COLLECT_H

#include "../incl/main.h"

int line_counter;
int network_counter;
Node *first_Node;
// Node *new_Node;


void cell_collect();
int get_input_num();
void read_cell(char file_name[]);
void append_Node(Node *last_Node);
void fill_Node(char buffer[]);
/*void insert_new_connection(int cell_num, char mac[], char essid[],
                              char mode[], int channel, char en_key[],
                              char quality, char freq[], char signal_l[]);
*/
#endif 
