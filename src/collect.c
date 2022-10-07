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
    return -1; //error
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

void put_conn_to_struct(int cell_num, char mac[MAX_STRING_SIZE], char essid[MAX_STRING_SIZE],
                        char mode[MAX_STRING_SIZE], int channel, char en_key[MAX_STRING_SIZE],
                        char quality, char freq[MAX_STRING_SIZE], char signal_l[MAX_STRING_SIZE])
{
    int index = 0;

    if(index < ARRAY_SIZE)
    {
        conn_array[index].cell_num = cell_num;
        strcpy(conn_array[index].mac, mac);
        strcpy(conn_array[index].essid, essid);
        strcpy(conn_array[index].mode, mode);
        conn_array[index].channel = channel;
        strcpy(conn_array[index].en_key, en_key);
        conn_array[index].quality = quality;
        strcpy(conn_array[index].freq, freq);
        strcpy(conn_array[index].signal_l, signal_l);

        printf("Network read from %s (added to position %i of the array)\n", name_file, index);
        printf("\n%i %s %s %s %i %s %i %s %s\n", conn_array[index].cell_num, conn_array[index].mac, conn_array[index].essid, 
                conn_array[index].mode, conn_array[index].channel, conn_array[index].en_key,
                conn_array[index].quality, conn_array[index].freq, conn_array[index].signal_l);

        index++;
    } else {
        printf("Error: the array is full and it can not store further conn_array, to reset the storage please restart the program");
    }
}
