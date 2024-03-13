#include <stdio.h>
#include <stdlib.h>
#include "domain/med.h"
#include "repository/repo.h"
#include "service/service.h"
#include "ui/ui.h"

int main() {
    repo* repository = construct_repo();

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
            int id = get_id();
            char* name = get_name();
            float concentration = get_concentration();
            int units = get_units();

            add_medication(
                repository, 
                id, 
                name, 
                concentration, 
                units
            );

            free(name);
            printf("Medicament adaugat cu succes\n");
            press_enter();
        }
        else if (command == 2) {

            int id = get_id();
            char* name = get_name();
            float concentration = get_concentration();

            update_medication(
                repository, 
                id, 
                name, 
                concentration
            );

            free(name);
            printf("Medicament modificat cu succes\n");
            press_enter();
        }
        else if (command == 3) {
            break;
        }
        else if (command == 4) {
            for (int i = 0; i < repository->length; i++) {
                print_med(repository->inventory[i]);
            }
            press_enter();
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
