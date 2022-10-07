#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../incl/collect.h"
#include "../incl/main.h"
#include "../incl/display.h"

int choose_cell()
{
    int cell_num;

    printf("What cell do you want to collect? (1 - 21):");
    scanf("%d", &cell_num);
    if(cell_num >= 1 || cell_num <= 21){
         return cell_num;
    }else{
        while(cell_num <= 0 || cell_num >= 22){
            printf("Please enter a valid number for the cell. (1-21)");
            scanf("%d", &cell_num);
        }
    }
}

void cell_collect()
{
    char y_n;
    int pick = choose_cell();
    char final_cell[MAX_STRING_SIZE];

    //string to char
    sprintf(final_cell, "%i", pick );  

    //Concatenating strings together to form the filename
    char name_file[] = {"./files/info_cell_"};
    strcat(name_file, final_cell);
    strcat(name_file, ".txt");

    read_cell(name_file);

    printf("Do you want to add another access point? [y/N]: ");
    scanf("%s", &y_n);

    switch (y_n)
    {
    case 'y':
    case 'Y':
        cell_collect();

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

void read_cell(char name_file){

    int index = 0;

    FILE * entrada; //la entrada es cell_file

    int cell_num;
    char mac[LINE_SIZE];
    char essid[LINE_SIZE];
    char mode[LINE_SIZE];
    int channel;
    char en_key[LINE_SIZE];
    int quality;
    char freq[LINE_SIZE];
    char signal_l[LINE_SIZE];

    entrada = fopen(name_file,"r");

    if(entrada == NULL) {
        printf("Error opening file: %s\n", name_file);
    }else{
        while(fscanf(entrada, "%i %s %s %s %i %s %i %s %s", cell_num, mac, essid, mode, channel,en_key, quality, freq, signal_l) != EOF){
            //insertar datos en el struct para luego meter en el array
            put_connection_to_struct(cell_num, mac, essid, mode, channel, en_key, quality, freq, signal_l);
        }
        fclose(name_file);
    }
}

 //aqui hago codigo para lectura de líneas (creo que tiene que ir en el main)
    
 /*   void leerporlineas(void)
    {

    char texto[150];
    // entrada = fopen("info_cell_" + cell_num + ,"r");
    entrada = fopen("info_cell_.txt"  ,"r");

    if(entrada == NULL){
        printf("El archivo no puede abrirse.\n");
        exit(1); //no sabemos si 0 o 1
    }
    
    if((salida = fopen("salida.txt","w"))== NULL){
        printf("El archivo no puede abrirse/crearse\n");
    }
 
    while(fgets(texto, 150, entrada)){ //la cadena donde almacenaremos el texto, el tamaño/ numero de caracteres, y el archivo 
        fputs(texto, salida); // la cadena que vamos a escribir y el archivo donde vamos a escribir
    }

    fclose(entrada);
    fclose(salida);

    return 0;
    
    }
*/
    // en vez de almacenar ints definimos con el struct una variable que se va a llamar conexiones (qu conexiones a su vez van a ser arrays)
    

    
    
