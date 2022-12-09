#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../incl/select_best.h"
#include "../incl/main.h"
#include "../incl/collect.h"
#include "../incl/display_all.h"

/*
The following function shows the detailed information about 
the access point to any network that offers the highest quality
*/ 
void select_b()
{
    //Node *aux = header_Node; 

    int z = best();
    aux = header_Node;
    while ( *aux->quality != z)
    {
        aux = aux->next;
    }
    printf("The best connection data is: \n");
    printf("\n%s %s %s %s %s %s %s %s %s\n",
               aux->cell_num,aux->mac,
               aux->essid,aux->mode,
               aux->channel,aux->en_key,
               aux->quality,aux->freq,
               aux->signal_l);
    
    printf("\nPress any key to go to the menu: ");
    scanf("%s", &any_key);
    if(sizeof(any_key) == (sizeof(char) || sizeof(int)))
    {
        system("clear");
    }    
}


int best()
{
    aux = header_Node;
    //int x=0;
    int biggest;
    int smaller;

    char *p_biggest;
    char *p_smaller;

    p_biggest = (char*) calloc(1, 10*sizeof(char));
    p_smaller = (char*) calloc(1, 10*sizeof(char));

    strcat(p_biggest, (aux->quality + 8));
    //printf("%s\n",p_biggest);
    biggest = atoi(p_biggest); 
    //printf("%i\n",biggest);  

    do
    { 
        strcpy(p_smaller, (aux->quality + 8));
        //printf("%i : ", i);
        //printf(" %s smaller - ", p_smaller);
        smaller = atoi(p_smaller);   
        //printf("%i \n", smaller);   
            if(biggest < smaller)
            {
                biggest = smaller;
            }
        aux = aux->next;
    }
    while (aux->next != NULL);
    
    return biggest;
}