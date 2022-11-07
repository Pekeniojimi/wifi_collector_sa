#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../incl/display_all.h"
#include "../incl/main.h"
#include "../incl/collect.h"

// The following function prints the information contained by all cells
void print_all()
{
    for (int i = 0; i < network_counter; i++)
    {
        if(strlen((p_connections)[i].cell_num) != 0)
        {

            printf("\n%s %s %s %s %s %s %s %s %s\n",
                (p_connections)[i].cell_num, (p_connections)[i].mac,
                (p_connections)[i].essid, (p_connections)[i].mode,
                (p_connections)[i].channel, (p_connections)[i].en_key,
                (p_connections)[i].quality, (p_connections)[i].freq,
                (p_connections)[i].signal_l);

        }
    }

    printf("\nPress any key to go to the menu: ");
    scanf("%s", &any_key);
    if(sizeof(any_key) == (sizeof(char) || sizeof(int)))
    {
        system("clear");
    }    
}