#include <stdio.h>
#include <stdlib.h>

#include "../incl/collect.h"
void choose_cell()
{
    int cell_num;

    printf("What cell do you want to collect? (1 - 21):");
    scanf("%d", &cell_num);
    
}

void read_cell(void){

    FILE * demo;

    demo = fopen("info_cell_1.txt","r");
}