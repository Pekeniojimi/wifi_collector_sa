#include <stdio.h>
#include <stdlib.h>

#include "../incl/main.h"

int main()
{
    system("clear");

    char response;

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
            cell_collect(file_name);
            break;
        case 10:
            
        default:
            printf("At this moment this functionality is not available.\n\n");
            break ;
        }
    } while (1);
    return 0;

}

void print_menu()
{
    printf("[2022] SUCEM S.L Wifi Collector\n\n");
    printf("[ 1] wificollector_quit\n");
    printf("[ 2] wificollector_collect\n");
    printf("[ 3] wificollector_show_data_one_network\n");
    printf("[ 4] wificollector_select_best\n");
    printf("[ 5] wificollector_select_worst\n");
    printf("[ 6] wificollector_delete_net\n");
    printf("[ 7] wificollector_sort\n");
    printf("[ 8] wificollector_export\n");
    printf("[ 9] wificollector_import\n");
    printf("[10] wificollector_display\n");
    printf("[11] wificollector_display_all\n");
    printf("Option: ");
}
