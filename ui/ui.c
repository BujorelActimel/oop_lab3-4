#include <stdio.h>
#include <stdlib.h>

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

    if (command >= 0 && command <= 5) {
        return command;
    }
    return -1;
}

void press_enter() {
    printf("Apasati ENTER pentru a continua\n");

    // Clear the input buffer
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);

    // Wait for the user to press enter
    getchar();
}
