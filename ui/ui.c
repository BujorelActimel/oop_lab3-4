#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

int get_reverse() {
    int reverse;
    printf("Introduceti 1 pentru sortare descrescatoare sau 0 pentru sortare crescatoare: ");
    scanf("%d", &reverse);
    return reverse;
}

int get_filter_option() {
    int value;
    printf("Introduceti optiunea de filtrare (\n1 - numar maxim de unitati,\n2 - initiala numelui\n): ");
    scanf("%d", &value);
    return value;
}

int get_value() {
    int value;
    printf("Introduceti valoarea: ");
    scanf("%d", &value);
    return value;
}

char get_letter() {
    char letter;
    printf("Introduceti litera: ");
    scanf(" %c", &letter);
    return letter;
}

int validate_id(int id) {
    if (id < 0) {
        printf("ID-ul trebuie sa fie un numar pozitiv\n");
        press_enter();
        return 0;
    }
    return 1;
}

int validate_name(char* name) {
    if (strlen(name) == 0) {
        printf("Numele medicamentului nu poate fi vid\n");
        press_enter();
        return 0;
    }
    return 1;
}

int validate_concentration(float concentration) {
    if (concentration < 0) {
        printf("Concentratia medicamentului trebuie sa fie un numar pozitiv\n");
        press_enter();
        return 0;
    }
    return 1;
}

int validate_units(int units) {
    if (units < 0) {
        printf("Cantitatea medicamentului trebuie sa fie un numar pozitiv\n");
        press_enter();
        return 0;
    }
    return 1;
}

int validate_reverse(int reverse) {
    if (reverse != 0 && reverse != 1) {
        printf("Optiunea de sortare trebuie sa fie 0 sau 1\n");
        press_enter();
        return 0;
    }
    return 1;
}

int validate_filter_option(int filter_option) {
    if (filter_option != 1 && filter_option != 2) {
        printf("Optiunea de filtrare trebuie sa fie 1 sau 2\n");
        press_enter();
        return 0;
    }
    return 1;
}

int validate_value(int value) {
    if (value < 0) {
        printf("Valoarea trebuie sa fie un numar pozitiv\n");
        press_enter();
        return 0;
    }
    return 1;
}

int validate_letter(char letter) {
    if ((letter < 'A' && letter > 'Z') || (letter < 'a' && letter > 'z')) {
        printf("Litera invalida\n");
        press_enter();
        return 0;
    }
    return 1;
}
