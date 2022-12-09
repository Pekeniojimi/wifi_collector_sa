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
    //Node *aux = header_Node;

    int z = worst();
    aux = header_Node;
    while ( *aux->quality != z)
    {
        aux = aux->next;
    }
    printf("the worst connection data is: \n");
    printf("\n%s %s %s %s %s %s %s %s %s\n",
                aux->cell_num, aux->mac,
                aux->essid, aux->mode,
                aux->channel, aux->en_key,
                aux->quality, aux->freq,
                aux->signal_l);

    printf("\nPress any key to go to the menu: ");
    scanf("%s", &any_key);
    if(sizeof(any_key) == (sizeof(char) || sizeof(int)))
    {
        system("clear");
    }    
}


int worst()
{
    aux = header_Node;
    int x=0;
    int smallest;
    int bigger;

    char *p_smallest;
    char *p_bigger;

    p_smallest =(char*) calloc(1, 10*sizeof(char));
    p_bigger =(char*) calloc(1, 10*sizeof(char));

    strcat(p_smallest, aux->quality + 8);
    //printf("%s\n",p_smallest);
    smallest = atoi(p_smallest);   
    //printf("%i\n",smallest);

    do
    {
        strcpy(p_bigger, aux->quality + 8);
        //printf("%i : ", i);
        //printf(" %s bigger - ", p_bigger);
        bigger = atoi(p_bigger);
        //printf("%i \n", bigger);  
            if(smallest > bigger)
            {
                smallest = bigger;
            }
    }
    while (aux->next != NULL);

    return x;
}