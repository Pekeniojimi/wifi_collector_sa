#ifndef COLLECT_H
#define COLLECT_H

#include "../incl/main.h"

char name_file[20] = {"../files/info_cell_"};

void cell_collect(char name_file[]);
int choose_cell();
int get_input_num();
void read_cell(char name_file[]);
void put_connection_to_struct(int cell_num, char mac[], char essid[],
                              char mode[], int channel, char en_key[],
                              char quality, char freq[], char signal_l[]);

#endif 
