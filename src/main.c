#include <stdio.h>

#include "../incl/quit.h"

int main(void)
{
    int menu_int;
    char response;


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
    printf("[11] wificollector_display_all\n\n");
    printf("Option: ");
    printf("QUE LO QUEEE CABRONEE, SOY EL VELDADERO GITHUBIANO");
    printf("MERA MAMAME EL BICHO");
    
    scanf("%d", &menu_int);

    switch (menu_int)
    {
    case 1:
        response = getchar();
        quit(response);
        break;
    
    default:
        break;
    }
    return 0;

}
