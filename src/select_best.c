#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../incl/select_best.h"
#include "../incl/main.h"
#include "../incl/collect.h"
#include "../incl/display_all.h"

Node *HQ_Node;
/*
The following function shows the detailed information about 
the access point to any network that offers the highest quality
*/ 
void select_b()
{
       
    int highest = best();
    

    printf("The best connection data is: \n");
    printf("\n%s %s %s %s %s %s %s %s %s\n",
               HQ_Node->cell_num,
               HQ_Node->mac,
               HQ_Node->essid,
               HQ_Node->mode,
               HQ_Node->channel,
               HQ_Node->en_key,
               HQ_Node->quality,
               HQ_Node->freq,
               HQ_Node->signal_l);
    printf("The highest quality is: %i\n", highest);
    
    printf("\nPress any key to go to the menu: ");
    scanf("%s", &any_key);
    if(sizeof(any_key) == (sizeof(char) || sizeof(int)))
    {
        system("clear");
    }    
}


int best()
{
    Node *aux;
    aux = header_Node;
    //int x=0;
    int biggest;
    int smaller;

    char *p_biggest;
    char *p_smaller;

    p_biggest = (char*) calloc(1, 10*sizeof(char));
    p_smaller = (char*) calloc(1, 10*sizeof(char));

    HQ_Node = aux;
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
                HQ_Node = aux;
            }
        aux = aux->next;
    }
    while (aux != NULL);
    
    return biggest;
}

/*
int quality2int(char *quality_string)
{
    int quality_value;
    
    char *aux_string;

    aux_string = (char*) calloc(1, 10*sizeof(char));

    strcat(aux_string, (quality_string + 8));
    quality_value = atoi(aux_string); 
    
    return quality_value;
}
*/