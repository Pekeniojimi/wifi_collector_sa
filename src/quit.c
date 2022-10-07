#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "../incl/quit.h"

void quit(char response)
{
    printf("Are you sure you want to exit? [y/N]:");
    scanf("%c",&response);

    switch (response)
    {
        case 'y':
        case 'Y':
            printf("Goodbye!\n");
            exit(0);

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
