#include "repo.h"
#include "../domain/med.h"
#include <string.h>
#include <stdlib.h>

repo* construct_repo() {
    repo* repository = (repo*)malloc(sizeof(repo));
    repository->length = 0;
    return repository;
}

void destroy_repo(repo* repository) {
    for (int i = 0; i < repository->length; i++) {
        destruct_med(repository->inventory[i]);
    }
    free(repository);
}

void add_med(repo* repository, med* item) {
    for (int i = 0; i < repository->length; i++) {
        med* current_item = repository->inventory[i];
        if (strcmp(current_item->name, item->name) == 0) {
            current_item->units += item->units;
            return;
        }
    }

    repository->inventory[repository->length++] = item;
}

void update_med_repo(repo* repository, int item_id, char* new_name, float new_concentration, int new_units) {
    for (int i = 0; i < repository->length; i++) {
        med* item = repository->inventory[i];
        if (item->id == item_id) {
            update_med(item, new_name, new_concentration, new_units);
            return;
        }
    }
}