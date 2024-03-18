#include <stdio.h>
#include <stdlib.h>
#include "../domain/med.h"

void clear_screen() {
    system("clear");
}

void print_menu() {
    printf("MENIU DE OPTIUNI:\n");
    printf("1 - Adaugare de noi medicamente\n");
    printf("2 - Actualizare medicamente\n");
    printf("3 - Stergerea stocului unui medicament\n");
    printf("4 - Vizualizare medicamente din stoc\n");
    printf("5 - Vizualizare lista de medicamente filtrate dupa un criteriu\n");
    printf("0 - exit");
}

int get_command() {
    int command = -1;
    printf("\n>>> ");
    scanf("%d", &command);

    return command;
}

void press_enter() {
    printf("Apasati ENTER pentru a continua\n");

    // Clear the input buffer
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);

    // Wait for the user to press enter
    getchar();
}

int get_id() {
    int id;
    printf("Introduceti ID-ul medicamentului: ");
    scanf("%d", &id);
    return id;
}

char* get_name() {
    char* name = (char*)malloc(100 * sizeof(char));
    printf("Introduceti numele medicamentului: ");
    scanf("%s", name);
    return name;
}

float get_concentration() {
    float concentration;
    printf("Introduceti concentratia medicamentului: ");
    scanf("%f", &concentration);
    return concentration;
}

int get_units() {
    int units;
    printf("Introduceti cantitatea medicamentului: ");
    scanf("%d", &units);
    return units;
}

void print_med(med* med) {
    printf("Medicamentul %s cu concentratia %.2f mg si %d unitati\n", med->name, med->concentration, med->units);
}

void print_med_list(med** med_list, int size) {
    for (int i = 0; i < size; i++) {
        print_med(med_list[i]);
    }
}