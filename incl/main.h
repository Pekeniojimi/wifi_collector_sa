#ifndef MAIN_H  
#define MAIN_H

#include "../incl/quit.h"
#include "../incl/collect.h"
#include "../incl/display.h"

#define MAX_STRING_SIZE 80
#define ARRAY_SIZE 200
#define LINE_SIZE 80

int menu_int;

typedef struct connections
{
    int cell_num;
    char mac[MAX_STRING_SIZE];
    char essid[MAX_STRING_SIZE];
    char mode[MAX_STRING_SIZE];
    int channel;
    char en_key[MAX_STRING_SIZE];
    int quality;
    char freq[MAX_STRING_SIZE];
    char signal_l[MAX_STRING_SIZE];
} connection_t;

struct connections conn_array[ARRAY_SIZE];

// pretendemos hacer un array de structs

// collect data celda 21, hacemos un leerporlineas, nos devuelve una salida (txt), esta salida la guardamos en connections es un array, 

// en vez de almacenar ints definimos con el struct una variable que se va a llamar conexiones (qu conexiones a su vez van a ser arrays)

//hay que crear una funcion que saque lo leido de un file y lo meta en un struct

void print_menu();

#endif
