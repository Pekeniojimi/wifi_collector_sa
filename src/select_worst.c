#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../incl/select_worst.h"
#include "../incl/main.h"
#include "../incl/collect.h"
#include "../incl/display_all.h"
/*
The following function shows the detailed information about 
the access point to any network that offers the lowest quality
*/ 
void select_w()
{
    int z = worst(p_connections);
    printf("the worst connection data is: \n");
    printf("\n%s %s %s %s %s %s %s %s %s\n",
                (p_connections)[z].cell_num, (p_connections)[z].mac,
                (p_connections)[z].essid, (p_connections)[z].mode,
                (p_connections)[z].channel, (p_connections)[z].en_key,
                (p_connections)[z].quality, (p_connections)[z].freq,
                (p_connections)[z].signal_l);

    printf("\nPress any key to go to the menu: ");
    scanf("%s", &any_key);
    if(sizeof(any_key) == (sizeof(char) || sizeof(int)))
    {
        system("clear");
    }    
}


int worst(connection *ptr)
{
    int x=0;
    int smallest;
    int bigger;

    char *p_smallest;
    char *p_bigger;

    p_smallest =(char*) calloc(1, 10*sizeof(char));
    p_bigger =(char*) calloc(1, 10*sizeof(char));

    strcat(p_smallest, (ptr)[x].quality + 8);
    //printf("%s\n",p_smallest);
    smallest = atoi(p_smallest);   
    //printf("%i\n",smallest);

    for(int i=1; i<network_counter; i++)
    {
        strcpy(p_bigger, (ptr)[i].quality + 8);
        //printf("%i : ", i);
        //printf(" %s bigger - ", p_bigger);
        bigger = atoi(p_bigger);
        //printf("%i \n", bigger);  
            if(smallest > bigger)
            {
                x=i;
                smallest = bigger;
            }
    }

    return x;
}