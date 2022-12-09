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
    
    int z = best();
    printf("The best connection data is: \n");
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


int best()
{
    Node *aux = header_Node;
    int x=0;
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
                x=i;
                biggest = smaller;
            }
        aux = aux->next;
    }
    while (aux->next != NULL)
    
    return x;
}