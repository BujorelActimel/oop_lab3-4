#include <string.h>
#include <stdlib.h>
#include "service.h"
#include "../domain/med.h"
#include "../repository/repo.h"

void add_medication(repo* repository, int id, char* name, float concentration, int quantity) {
    med* new_med = construct_med(id, name, concentration, quantity);
    add_med(repository, new_med);
}

void update_medication(repo* repository, int id, char* name, float concentration) {
    for (int i = 0; i < repository->length; i++) {
        med* current_med = repository->inventory[i];
        if (current_med->id == id && current_med->units > 0) {
            update_med(current_med, name, concentration, current_med->units);
            return;
        }
    }
}

void delete_med_stock(repo* repository, int item_id) {
    for (int i = 0; i < repository->length; i++) {
        med* item = repository->inventory[i];
        if (item->id == item_id) {
            item->units = 0;
        }
    }
}

int num_of_meds_in_stock(med** inventory, int length) {
    int count = 0;
    for (int i = 0; i < length; i++) {
        if (inventory[i]->units > 0) {
            count++;
        }
    }
    return count;
}

med** sort_meds_in_stock(med** inventory, int length, int reverse) {
    int new_length = num_of_meds_in_stock(inventory, length);
    med** sorted_inventory = (med**)malloc(new_length * sizeof(med*));

    // elimina medicamentele care nu sunt in stoc
    int k = 0;
    for (int i = 0; i < length; i++) {
        if (inventory[i]->units > 0) {
            sorted_inventory[k++] = inventory[i];
        }
    }
    // sortare dupa nume si numar de unitati crescator/descrescator
    for (int i = 0; i < new_length - 1; i++) {
        for (int j = i + 1; j < new_length; j++) {
            if (reverse) {
                if (strcmp(sorted_inventory[i]->name, sorted_inventory[j]->name) < 0) {
                    med* temp = sorted_inventory[i];
                    sorted_inventory[i] = sorted_inventory[j];
                    sorted_inventory[j] = temp;
                }
            }
            else {
                if (strcmp(sorted_inventory[i]->name, sorted_inventory[j]->name) > 0) {
                    med* temp = sorted_inventory[i];
                    sorted_inventory[i] = sorted_inventory[j];
                    sorted_inventory[j] = temp;
                }
            }
        }
    }

    return sorted_inventory;
}

int num_of_meds_by_units(med** inventory, int length, int value) {
    int count = 0;
    for (int i = 0; i < length; i++) {
        if (inventory[i]->units < value) {
            count++;
        }
    }
    return count;
}

med** filter_meds_by_units(med** inventory, int length, int value) {
    int new_length = num_of_meds_by_units(inventory, length, value);
    med** filtered_inventory = (med**)malloc(new_length * sizeof(med*));

    int k = 0;
    for (int i = 0; i < length; i++) {
        if (inventory[i]->units < value) {
            filtered_inventory[k++] = inventory[i];
        }
    }

    return filtered_inventory;
}

int num_of_meds_by_initial_letter(med** inventory, int length, char letter) {
    int count = 0;
    for (int i = 0; i < length; i++) {
        if (inventory[i]->name[0] == letter) {
            count++;
        }
    }
    return count;
}

med** filter_meds_by_initial_letter(med** inventory, int length, char letter) {
    int new_length = num_of_meds_by_initial_letter(inventory, length, letter);
    med** filtered_inventory = (med**)malloc(new_length * sizeof(med*));

    int k = 0;
    for (int i = 0; i < length; i++) {
        if (inventory[i]->name[0] == letter) {
            filtered_inventory[k++] = inventory[i];
        }
    }

    return filtered_inventory;
}
