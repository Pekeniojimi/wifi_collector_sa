#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../incl/collect.h"

int choose_cell()
{
    int cell_num;

    printf("What cell do you want to collect? (1 - 21):");
    scanf("%d", &cell_num);
    if(cell_num >= 1 || cell_num <= 21)
    {
        return cell_num;
    } else {
        while(cell_num <= 0 || cell_num >= 22)
        {
            printf("Please enter a valid number for the cell. (1-21)");
            scanf("%d", &cell_num);
        }
    }
}

void cell_collect(char file_name[MAX_STRING_SIZE])
{
    char y_n;
    int pick = choose_cell();
    char final_cell[MAX_STRING_SIZE];

    //string to char
    sprintf(final_cell, "%i", pick );  

    //Concatenating strings together to form the filename
    //file_name declared in .h
    strcat(file_name, final_cell);
    strcat(file_name, ".txt");

    read_cell(file_name);

    printf("Do you want to add another access point? [y/N]: ");
    scanf("%s", &y_n);

    switch (y_n)
    {
    case 'y':
    case 'Y':
        cell_collect(file_name);

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

void read_cell(char file_name[MAX_STRING_SIZE])
{

    int index = 0;

    FILE * cell_file = fopen(file_name, "r");

    int cell_num;
    char mac[LINE_SIZE];
    char essid[LINE_SIZE];
    char mode[LINE_SIZE];
    int channel;
    char en_key[LINE_SIZE];
    int quality;
    char freq[LINE_SIZE];
    char signal_l[LINE_SIZE];

    if(cell_file == NULL)
    {
        printf("Error opening file: %s\n", file_name); //error message w filename
    } else {
        while(fscanf(cell_file, "%i %s %s %s %i %s %i %s %s", &cell_num, mac, essid, mode, &channel, en_key, &quality, freq, signal_l) != EOF)
        {
            //insertar datos en el struct para luego meter en el array
            put_connection_to_struct(cell_num, mac, essid, mode, channel, en_key, quality, freq, signal_l);
        }
        fclose(cell_file);
    }
}
