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
