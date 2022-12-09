#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "../incl/quit.h"

// this function offers you to quit the program or continue
char  response = 0;
//void quit(char response)
void quit()
{

    printf("Are you sure you want to exit? [y/N]:");
    scanf("%c",&response);
    while(getchar() != '\n'); //Clear input buffer.
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
