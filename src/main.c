#include <stdio.h>
#include <stdlib.h>

#include "../incl/main.h"
#include "../incl/quit.h"
#include "../incl/collect.h"
#include "../incl/display_all.h"
#include "../incl/display.h"
#include "../incl/select_best.h"
#include "../incl/select_worst.h"


int cell_num;


int main()
{
    system("clear");

    char response;

    p_connections = (connection*) calloc(INITIAL_SIZE, sizeof(connection));

    do
    {
        print_menu();
        scanf("%d", &menu_int);

        switch (menu_int)
        {
        case 1:
            response = getchar();
            quit(response);
            break;
        case 2: 
            cell_collect();
            break;
        case 4:
            select_b();
            break;
        case 5:
            select_w();
            break;
        case 10:
            print_cell();
            break;
        case 11:
            print_all();
            break;    
        default:
            printf("\nAt this moment this functionality is not available.\n\n");
            break ;
        }
    } while (1);
    return 0;

}

void print_menu()
{
    printf("[2022] SUCEM S.L Wifi Collector\n\n");
    printf("\t[ 1] wificollector_quit\n");
    printf("\t[ 2] wificollector_collect\n");
    printf("\t[ 3] wificollector_show_data_one_network\n");
    printf("\t[ 4] wificollector_select_best\n");
    printf("\t[ 5] wificollector_select_worst\n");
    printf("\t[ 6] wificollector_delete_net\n");
    printf("\t[ 7] wificollector_sort\n");
    printf("\t[ 8] wificollector_export\n");
    printf("\t[ 9] wificollector_import\n");
    printf("\t[10] wificollector_display\n");
    printf("\t[11] wificollector_display_all\n");
    printf("\tOption: ");
}


// This function is for choosing the cell we want to collect, 
// It only works if a number within 1-21 is entered, if not
// It will ask you to enter a valid number (1-21)

int choose_cell()
{

    printf("\nWhat cell do you want to focus? (1 - 21):");
    scanf("%d", &cell_num);
    if(cell_num >= 1 && cell_num <= 21)
    {
        return cell_num;
    } 
    else 
    {
        while(cell_num <= 0 || cell_num >= 22)
        {
            printf("Please enter a valid number for the cell. (1-21)");
            scanf("%d", &cell_num);
        }
        return cell_num;
    }
    return 0; //error
}
