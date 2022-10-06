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
    int pick = choose_cell();
    char final_cell[MAX_STRING_SIZE];

    sprintf(final_cell, "%i", pick );  

    char name_file[] = {"./files/info_cell_"};
    strcat(name_file,final_cell);
    strcat(name_file, ".txt");


    
}

void read_cell(char name_file){

    int index = 0;

    FILE *entrada; //la entrada es cell_file

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
            {
            printf("Network read from %s (added to position %i of the array)\n", name_file, index++ )
            //insertar datos en el struct para luego meter en el array
            }
        }
    }
	
      
    return 0;

}

 //aqui hago codigo para lectura de líneas (creo que tiene que ir en el main)
    
    void leerporlineas(void)
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

    // en vez de almacenar ints definimos con el struct una variable que se va a llamar conexiones (qu conexiones a su vez van a ser arrays)
    

    typedef struct
    
