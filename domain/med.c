#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "med.h"

med* construct_med(int id, char* name, float concentration, int units) {
    med* new_med = (med*)malloc(sizeof(med));
    new_med->id = id;
    new_med->name = (char*)malloc(strlen(name) + 1);
    strncpy(new_med->name, name, strlen(name) + 1);
    new_med->name[strlen(new_med->name)] = '\0';  // Asigura terminare nula
    new_med->concentration = concentration;
    new_med->units = units;
    return new_med;
}

void update_med(med* med, char* name, float concentration, int units) {
    free(med->name);
    med->name = (char*)malloc(strlen(name) + 1);
    strncpy(med->name, name, strlen(name) + 1);
    med->name[strlen(name)] = '\0';  // Asigura terminare nula
    med->concentration = concentration;
    med->units = units;
}

void destruct_med(med* med) {
    free(med->name);
    free(med);
}
