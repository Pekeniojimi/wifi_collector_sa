#ifndef COLLECT_H
#define COLLECT_H

#include "../incl/main.h"
#include "../incl/display.h"

char name_file[20] = {"../files/info_cell_"};

void cell_collect(char name_file[]);
int choose_cell();
int get_input_num();
void read_cell(char name_file[]);

#endif 
