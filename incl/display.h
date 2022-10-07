#ifndef DISPLAY_H
#define DISPLAY_H

#include "../incl/main.h"

void print_cell();
void put_connection_to_struct(int cell_num, char mac[], char essid[],
                              char mode[], int channel, char en_key[],
                              char quality, char freq[], char signal_l[]);

#endif
