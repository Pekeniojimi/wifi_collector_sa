#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../incl/display.h"
#include "../incl/main.h"
#include "../incl/collect.h"



// The following function prints the information in the cell
 void print_cell(){

    char y_n;
    printer();   

    printf("Do you want to print the information of another cell? [y/N]:");
        scanf("%s", &y_n);
        
        switch (y_n)
        {
            case 'y':
            case 'Y':
                print_cell();

            case 'n':
            case 'N':
            system("clear");
                break;

            default:
                printf("\n ERROR, input is not valid, try it again!\n");
                system("clear");
                break;
        }
        
        
    }


    void printer()
    {
        Node *aux = header_Node;
        char input_of_String[MAX_STRING_SIZE];
        int count_v = 0;
        
        char cell_name[20] = {"Cell "};
        int value;

        int picker = choose_cell();
   
       //int to string
        sprintf(input_of_String, "%i", picker); 
        strcat(cell_name, input_of_String);
        
        while(aux->cell_num != cell_name) {
            aux = (Node*) aux->next;
        }
         printf("\n%s %s %s %s %s %s %s %s %s\n",
               aux->cell_num,aux->mac,
               aux->essid,aux->mode,
               aux->channel,aux->en_key,
               aux->quality,aux->freq,
               aux->signal_l);

        /*for(int i = 0; i < network_counter; i++)
        {        
            value = checker(i, cell_name);
            if(value == strlen(cell_name))
            {
                printf("\n%s %s %s %s %s %s %s %s %s\n", aux->cell_num,
                        aux->mac, aux->essid, aux->mode, 
                        aux->channel, aux->en_key,aux->quality, 
                        aux->freq, aux->signal_l);
            }
            else
            {
                count_v++;
                if(count_v == 80)
                {
                    printf("\nScan the cell first, you can do this by pressing number 2 in th main menu\n");
                    break;
                }
            }
        }
        */
    }

    /*int checker(int iterator, char cell_name[]){
        int counter3 = 0;
        //we check the whole name of the pos array so we can state if it matches
        for(int j=0; j<strlen((p_connections)[iterator].cell_num); j++)
        {
            if((p_connections)[iterator].cell_num[j] == cell_name[j])
            {
                counter3++;
            }
        }
        return counter3;
        
    }
    */



