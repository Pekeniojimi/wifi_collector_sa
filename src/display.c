#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../incl/display.h"

void print_cell()
{
    int num_of_cell;
    char input_of_String[20];
    int count_v = 0;
    char y_n;

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
    
    for(int i = 0; i < LINE_SIZE; i++)
    {
        if(conn_array[i].cell_num == num_of_cell)
        {
            printf("\n%i %s %s %s %i %s %i %s %s\n", conn_array[i].cell_num, conn_array[i].mac, 
                    conn_array[i].essid, conn_array[i].mode, conn_array[i].channel, conn_array[i].en_key,
                    conn_array[i].quality, conn_array[i].freq, conn_array[i].signal_l);
        }

        if(conn_array[i].cell_num != num_of_cell)
        {
            count_v++;
        }

        if(count_v == 80)
        {
            printf("\nScan the cell first, you can do this by pressing number 2 in th main menu\n");
            break;
        }

        printf("Do you want to print the information of another cell? [y/N]:");
        scanf("%s", &y_n);

        switch (y_n)
        {
            case 'y':
            case 'Y':
                print_cell();

            case 'n':
            case 'N':
                break;

            default:
                printf("\n ERROR, input is not valid, try it again!\n");
                system("clear");
                break;
        }
    }


}
