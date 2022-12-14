#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../incl/display_all.h"
#include "../incl/collect.h"
#include "../incl/main.h"

Node *first_Node;

//printf("%s", first_Node);
//extern char file_name[];
//The following function collects the cell: rellena los nodos y añade nuevos nodos
//void cell_collect(Node *first_Node)

void cell_collect()
{ 
    first_Node = header_Node;
    while (first_Node->next != NULL)
    {
        first_Node = first_Node->next;
    }

    // first_Node es el primer nodo vacío que vamos a rellenar en cell_collect()
    char y_n;
    int pick = choose_cell();
    char final_cell[MAX_STRING_SIZE];

    //int to string
    sprintf(final_cell, "%i", pick);  
    char file_name[MAX_STRING_SIZE] = {"../files/info_cell_"};
    

    //Concatenating strings together to form the filename
    //file_name declared in .h
    strcat(file_name, final_cell);
    strcat(file_name, ".txt");
    

    read_cell(file_name);

    printf("\nDo you want to add another access point? [y/N]: ");
    scanf("%s", &y_n);

    switch (y_n)
    {
    case 'y':
    case 'Y':
        append_Node();
        cell_collect();
    case 'n':
    case 'N':
        system("clear");
        break;
    
    default:
        printf("\n ERROR, input is not valid, try it again!\n");
       printf("\nPress any key to go to the menu: ");
             scanf("%s", &any_key);
            if(sizeof(any_key) == (sizeof(char) || sizeof(int)))
            {
            system("clear");
        }
        break;
    }
}

// The following function reads the information in the file and returns the data in a struct
void read_cell(char file_name[MAX_STRING_SIZE])
{
    //Node *head_ref;
    line_counter = 0;
    network_counter = 0;
    short end_of_data = 0;

    char buffer[LINE_SIZE];

    FILE * cell_file = fopen(file_name, "r");

    if(!cell_file)
    {
        printf("File was not found.");
    }
    else
    {

        while(end_of_data == 0)
        {                 
            
            if (fgets(buffer, LINE_SIZE, cell_file))
            {
                if (network_counter > 0 && line_counter == 0)
                {
                    append_Node();
                }

                fill_Node(buffer);
                line_counter++;
                
                if(line_counter == DATA_SIZE)
                {
                    line_counter = 0;
                    network_counter++;
                    printf("\n");
                }
            }
            else
            {
                end_of_data = 1;
            }
        }
        fclose(cell_file);
    }
}


void append_Node(){   
    
    /*
    if(*last_Node == NULL){
        return;
    }
    */

   Node *aux = (Node*) calloc(INITIAL_SIZE, sizeof(Node));
   first_Node->next = aux;
   first_Node = aux;

   return;

}

// The following method inserts a new connection 
void fill_Node (char buffer[]){

    switch(line_counter) {

            case 0  :
                strcpy(first_Node->cell_num, buffer);
                printf("%s", first_Node->cell_num);
            break; 
	
            case 1  :
                strcpy(first_Node->mac, buffer);
                printf("%s", first_Node->mac);
            break; 

            case 2  :
                strcpy(first_Node->essid, buffer);
                printf("%s", first_Node->essid);
            break; 

            case 3  :
                strcpy(first_Node->mode, buffer);
                printf("%s", first_Node->mode);
            break; 

            case 4  :
                strcpy(first_Node->channel, buffer);
                printf("%s", first_Node->channel);
            break; 

            case 5  :
                strcpy(first_Node->en_key, buffer);
                printf("%s", first_Node->en_key);
            break; 

            case 6  :
                strcpy(first_Node->quality, buffer);
                printf("%s", first_Node->quality);
            break; 

            case 7  :
                strcpy(first_Node->freq, buffer);
                printf("%s", first_Node->freq);
            break; 

            case 8  :
                strcpy(first_Node->signal_l, buffer);
                printf("%s", first_Node->signal_l);
            break; 

       }
}
