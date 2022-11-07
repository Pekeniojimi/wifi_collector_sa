#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../incl/collect.h"
#include "../incl/main.h"

//printf("%s", buffer);

//extern char file_name[];

//The following function collects the cell

void cell_collect()
{
    char y_n;
    int pick = choose_cell();
    char final_cell[MAX_STRING_SIZE];

    //int to string
    sprintf(final_cell, "%i", pick);  
    char file_name[20] = {"../files/info_cell_"};
    

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
        cell_collect();
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

// The following function reads the information in the file and returns the data in a struct
void read_cell(char file_name[MAX_STRING_SIZE])
{

    //int index = 0;
    char buffer[LINE_SIZE];
    FILE * cell_file = fopen(file_name, "r");

    if(!cell_file)
    {
        printf("File was not found.");
    }
    else
    {

        while(fgets(buffer, LINE_SIZE, cell_file))
        {
               
            if(network_counter % INITIAL_SIZE == 0 && network_counter != 0)
            {
            p_connections = (connection*) realloc(p_connections, (network_counter + INITIAL_SIZE) * sizeof(connection));
            }

            insert_new_connection(buffer);
            if(line_counter == 8)
            {
                line_counter = 0;
                network_counter++;
                printf("\n");
            }
            else
            {
                line_counter++;
            }
        }
    }
    fclose(cell_file);
}

// The following method inserts a new connection 
void insert_new_connection (char buffer[]){
    
    switch(line_counter) {

            case 0  :
                strcpy((p_connections)[network_counter].cell_num, buffer);
                printf("%s", (p_connections)[network_counter].cell_num);
            break; /* optional */
	
            case 1  :
                strcpy((p_connections)[network_counter].mac, buffer);
                printf("%s", (p_connections)[network_counter].mac);
            break; /* optional */

            case 2  :
                strcpy((p_connections)[network_counter].essid, buffer);
                printf("%s", (p_connections)[network_counter].essid);
            break; /* optional */

            case 3  :
                strcpy((p_connections)[network_counter].mode, buffer);
                printf("%s", (p_connections)[network_counter].mode);
            break; /* optional */

            case 4  :
                strcpy((p_connections)[network_counter].channel, buffer);
                printf("%s", (p_connections)[network_counter].channel);
            break; /* optional */

            case 5  :
                strcpy((p_connections)[network_counter].en_key, buffer);
                printf("%s", (p_connections)[network_counter].en_key);
            break; /* optional */

            case 6  :
                strcpy((p_connections)[network_counter].quality, buffer);
                printf("%s", (p_connections)[network_counter].quality);
            break; /* optional */

            case 7  :
                strcpy((p_connections)[network_counter].freq, buffer);
                printf("%s", (p_connections)[network_counter].freq);
            break; /* optional */

            case 8  :
                strcpy((p_connections)[network_counter].signal_l, buffer);
                printf("%s", (p_connections)[network_counter].signal_l);
            break; /* optional */

       }
}
