#ifndef COLLECT_H
#define COLLECT_H

int line_counter;
int network_counter;

void cell_collect();
int get_input_num();
void read_cell(char file_name[]);
void insert_new_connection(char buffer[]);
/*void insert_new_connection(int cell_num, char mac[], char essid[],
                              char mode[], int channel, char en_key[],
                              char quality, char freq[], char signal_l[]);
*/
#endif 
