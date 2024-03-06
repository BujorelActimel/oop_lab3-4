#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "med.h"

struct med* construct_med(int id, char* name, float concentration, int units) {
    struct med* new_med = (struct med*)malloc(sizeof(struct med));
    new_med->id = id;
    strncpy(new_med->name, name, MAX_NAME_LENGTH - 1);
    new_med->name[MAX_NAME_LENGTH - 1] = '\0';  // Asigura terminare nula
    new_med->concentration = concentration;
    new_med->units = units;
    return new_med;
}

void update_med(struct med* med, char* name, float concentration, int units) {
    strncpy(med->name, name, MAX_NAME_LENGTH - 1);
    med->name[MAX_NAME_LENGTH - 1] = '\0';  // Asigura terminare nula
    med->concentration = concentration;
    med->units = units;
}

void destruct_med(struct med* med) {
    free(med);
}

void print_med(struct med* med) {
    printf("Medicamentul %s cu concentratia %.2f si %d unitati\n", med->name, med->concentration, med->units);
}

void print_med_list(struct med** med_list, int size) {
    for (int i = 0; i < size; i++) {
        print_med(med_list[i]);
    }
}
