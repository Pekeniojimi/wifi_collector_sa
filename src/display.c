#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../incl/display.h"
#include "../incl/main.h"

void print_cell()
{
    int num_of_cell;
    char input_of_String[20];
    int count_v = 0;

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
    
    for (int i = 0; i < LINE_SIZE; i++)
    {
        if(conn_array )
    }
    
    
}

void put_conn_to_struct(int cell_num, char mac[MAX_STRING_SIZE], char essid[MAX_STRING_SIZE],
                        char mode[MAX_STRING_SIZE], int channel, char en_key[MAX_STRING_SIZE],
                        char quality, char freq[MAX_STRING_SIZE], char signal_l[MAX_STRING_SIZE])
{
    int index = 0;

    if(index < ARRAY_SIZE)
    {
        conn_array[index].cell_num = cell_num;
        strcpy(conn_array[index].mac, mac);
        strcpy(conn_array[index].essid, essid);
        strcpy(conn_array[index].mode, mode);
        conn_array[index].channel = channel;
        strcpy(conn_array[index].en_key, en_key);
        strcpy(conn_array[index].quality, quality);
        strcpy(conn_array[index].freq, freq);
        strcpy(conn_array[index].signal_l, signal_l);

        printf("Network read from %s (added to position %i of the array)\n", name_file, index);
        printf("%i %s %s %s %i %s %s %s %s", conn_array[index].cell_num, conn_array[index].mac, conn_array[index].essid, conn_array[index].mode, conn_array[index].channel, conn_array[index].en_key, conn_array[index].quality, conn_array[index].freq, conn_array[index].signal_l);

        index++;
    }else{
        printf("Error: the array is full and it can not store further conn_array, to reset the storage please restart the program");
    }
}

