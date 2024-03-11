#include <stdio.h>
#include "domain/med.h"
#include "ui/ui.h"

int main() {

    while (1) {
        clear_screen();
        print_menu();
        
        int command = get_command();

        if (command == 0) {
            clear_screen();
            printf("La revedere\n");
            break;
        }
        else if (command == 1) {
            break;
        }
        else if (command == 2) {
            break;
        }
        else if (command == 3) {
            break;
        }
        else if (command == 4) {
            break;
        }
        else if (command == 5) {
            break;
        }
        else {
            printf("Comanda Invalida\n");
            press_enter();
        }
    }

    return 0;
}
