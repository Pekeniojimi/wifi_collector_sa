#include <stdio.h>
#include <stdlib.h>

#include "../incl/collect.h"
#include "../incl/struct.h"

void choose_cell()
{
    int cell_num;

    printf("What cell do you want to collect? (1 - 21):");
    scanf("%d", &cell_num);
    if(cell_num >= 1 || cell_num <= 21){
        read_cell(cell_num);
    }elsif{
        while(cell_num <= 0 || cell_num >= 22){
            printf("Please enter a valid number for the cell. (1-21)");
            scanf("%d", &cell_num);
        }
    }

    
    
}

void read_cell(int cell_num){

     //import head from cells.c
    extern Node *head;
    cell aux;
    
	FILE *of;
	of = fopen("info_cell_"+ cell_num +".txt","r");
    
 
}