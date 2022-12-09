#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include "../incl/quit.h"
#include "../incl/display_all.h"
// this function offers you to quit the program or continue
char  response = 0;

//void quit(char response)
void quit()
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
            printf("\nPress any key to go to the menu: ");
             scanf("%s", &any_key);
            if(sizeof(any_key) == (sizeof(char) || sizeof(int)))
            {
            system("clear");
        }
        break;
    }

}
