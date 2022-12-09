#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../incl/select_worst.h"
#include "../incl/main.h"
#include "../incl/collect.h"
#include "../incl/display_all.h"

Node *LQ_Node;
/*
The following function shows the detailed information about 
the access point to any network that offers the lowest quality
*/ 
void select_w()
{
    
    int lowest = worst();
    
    printf("the worst connection data is: \n");
    printf("\n%s %s %s %s %s %s %s %s %s\n",
                LQ_Node->cell_num, LQ_Node->mac,
                LQ_Node->essid, LQ_Node->mode,
                LQ_Node->channel, LQ_Node->en_key,
                LQ_Node->quality, LQ_Node->freq,
                LQ_Node->signal_l);
    printf("The lowest quality is: %i\n", lowest);

    printf("\nPress any key to go to the menu: ");
    scanf("%s", &any_key);
    if(sizeof(any_key) == (sizeof(char) || sizeof(int)))
    {
        system("clear");
    }    
}


int worst()
{
    Node *aux;
    aux = header_Node;
    int smallest;
    int bigger;

    char *p_smallest;
    char *p_bigger;

    p_smallest =(char*) calloc(1, 10*sizeof(char));
    p_bigger =(char*) calloc(1, 10*sizeof(char));

    LQ_Node = aux;
    strcat(p_smallest, aux->quality + 8);
    //printf("%s\n",p_smallest);
    smallest = atoi(p_smallest);   
    //printf("%i\n",smallest);

    do
    {
        strcpy(p_bigger, (aux->quality + 8));
        //printf("%i : ", i);
        //printf(" %s bigger - ", p_bigger);
        bigger = atoi(p_bigger);
        //printf("%i \n", bigger);  
            if(smallest > bigger)
            {
                smallest = bigger;
                LQ_Node = aux;

            }
        aux = aux->next;
    }
    while (aux != NULL);

    return smallest;
}