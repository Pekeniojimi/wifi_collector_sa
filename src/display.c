#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../incl/display.h"
#include "../incl/main.h"

void print_cell()
{
    int num_of_cell;
    char input_of_String[20];

    printf("Indicate the number of the cell for which you want to know its information (1 - 21):");

    do
    {
        scanf("%s\n", input_of_String);
        getchar();

        num_of_cell = atoi(input_of_String);

        if (num_of_cell<1 || num_of_cell>21)
        {
            printf("\nError: please enter a number between 1 and 21 (both included)");
            break;
        }
        

    } while (num_of_cell < 1 || num_of_cell > 21);
    
    
}

void put_connection_to_struct(int cell_num, char mac[MAX_STRING_SIZE], char essid[MAX_STRING_SIZE],
                             char mode[MAX_STRING_SIZE], int channel, char en_key[MAX_STRING_SIZE],
                             int quality, char freq[MAX_STRING_SIZE], char signal_l[MAX_STRING_SIZE])
{
    int index = 0;

    if(index < ARRAY_SIZE)
    {
        connections[index].cell_num = cell_num;
        strcpy(connections[index].mac, mac);
        



    }


}

