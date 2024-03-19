#include "repo.h"
#include "../domain/med.h"
#include <string.h>
#include <stdlib.h>

repo* construct_repo() {
    repo* repository = (repo*)malloc(sizeof(repo));
    repository->length = 0;
    repository->capacity = 1;
    repository->inventory = (med**)malloc(1 * sizeof(med*));
    return repository;
}

void destroy_repo(repo* repository) {
    for (int i = 0; i < repository->length; i++) {
        destruct_med(repository->inventory[i]);
    }
    free(repository->inventory);
    free(repository);
}

void add_med(repo* repository, med* item) {
    for (int i = 0; i < repository->length; i++) {
        med* current_item = repository->inventory[i];
        if (strcmp(current_item->name, item->name) == 0) {
            current_item->units += item->units;
            destruct_med(item);
            return;
        }
    }

    if (repository->length == repository->capacity) {
        int new_capacity = repository->capacity * 2;
        med** new_inventory = (med**)malloc(new_capacity * sizeof(med*));
        for (int i = 0; i < repository->length; i++) {
            new_inventory[i] = repository->inventory[i];
        }
        free(repository->inventory);
        repository->inventory = new_inventory;
        repository->capacity = new_capacity;
    }

    repository->inventory[repository->length++] = item;
}
