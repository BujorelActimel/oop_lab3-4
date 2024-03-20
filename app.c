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
            destroy_repo(repository);
            clear_screen();
            printf("La revedere\n");
            break;
        }
        else if (command == 1) {
            int id = get_id();
            if (!validate_id(id)) {
                continue;
            }

            char* name = get_name();
            if (!validate_name(name)) {
                free(name);
                continue;
            }

            float concentration = get_concentration();
            if (!validate_concentration(concentration)) {
                free(name);
                continue;
            }

            int units = get_units();
            if (!validate_units(units)) {
                free(name);
                continue;
            }

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
            if (!validate_id(id)) {
                continue;
            }

            char* name = get_name();
            if (!validate_name(name)) {
                free(name);
                continue;
            }

            float concentration = get_concentration();
            if (!validate_concentration(concentration)) {
                free(name);
                continue;
            }

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
            int id = get_id();
            if (!validate_id(id)) {
                continue;
            }

            delete_med_stock(
                repository, 
                id
            );

            printf("Stocul medicamentului a fost eliminat\n");
            press_enter();
        }
        else if (command == 4) {
            printf("Medicamentele din stoc ordonate dupa nume, cantitate (crescator/descrescator).\n");
            
            int reverse = get_reverse();
            if (!validate_reverse(reverse)) {
                continue;
            }

            med** sorted_inventory = sort_meds_in_stock(
                repository->inventory, 
                repository->length,
                reverse
            );

            int length = num_of_meds_in_stock(
                repository->inventory, 
                repository->length
            );
            if (length == 0) {
                printf("Nu exista medicamente in stoc\n");
                press_enter();
                free(sorted_inventory);
                continue;
            }

            print_med_list(
                sorted_inventory, 
                length
            );
            
            free(sorted_inventory);

            press_enter();
        }
        else if (command == 5) {
            printf("Medicamentele din stoc filtrate dupa un criteriu.\n");
            int option = get_filter_option();
            if (!validate_filter_option(option)) {
                continue;
            }

            if (option == 1) {
                int value = get_value();
                if (!validate_value(value)) {
                    continue;
                }

                med** filtered_inventory = filter_meds_by_units(
                    repository->inventory, 
                    repository->length, 
                    value
                );

                int length = num_of_meds_by_units(
                    repository->inventory, 
                    repository->length, 
                    value
                );
                if (length == 0) {
                    printf("Nu exista medicamente in stoc cu mai putin de %d unitati\n", value);
                    press_enter();
                    free(filtered_inventory);
                    continue;
                }

                print_med_list(
                    filtered_inventory, 
                    length
                );

                press_enter();
                free(filtered_inventory);
            }
            else if (option == 2) {
                char letter = get_letter();
                if (!validate_letter(letter)) {
                    continue;
                }

                med** filtered_inventory = filter_meds_by_initial_letter(
                    repository->inventory, 
                    repository->length, 
                    letter
                );

                int length = num_of_meds_by_initial_letter(
                    repository->inventory, 
                    repository->length, 
                    letter
                );
                if (length == 0) {
                    printf("Nu exista medicamente in stoc care incep cu litera %c\n", letter);
                    press_enter();
                    free(filtered_inventory);
                    continue;
                }

                print_med_list(
                    filtered_inventory, 
                    length
                );
                
                press_enter();
                free(filtered_inventory);
            }
            else {
                printf("Optiune invalida\n");
            }
        }
        else {
            printf("Comanda Invalida\n");
            press_enter();
        }
    }

    return 0;
}
