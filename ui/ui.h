#ifndef UI_H
#define UI_H

/**
 * @brief curata ecranul
*/
void clear_screen();


/**
 * @brief tipareste meniul principal
*/
void print_menu();


/**
 * @brief cere input de la utilizator comanda dorita
 * @return comanda utilizatorului
*/
int get_command();


/**
 * @brief asteapta ca utilizatorul sa apese enter
*/
void press_enter();


/**
 * @brief cere input de la utilizator id-ul unui medicament
 * @return id-ul medicamentului
*/
int get_id();


/**
 * @brief cere input de la utilizator numele unui medicament
 * @return numele medicamentului
*/
char* get_name();


/**
 * @brief cere input de la utilizator concentratia unui medicament
 * @return concentratia medicamentului
*/
float get_concentration();


/**
 * @brief cere input de la utilizator numarul de unitati al unui medicament
 * @return numarul de unitati al medicamentului
*/
int get_units();


/**
 * @brief tipareste atributele unui obiect de tip med
 * @param med pointer catre obiectul de tip med
*/
void print_med(med* med);


/**
 * @brief tipareste atributele unei liste de obiecte de tip med
 * @param med_list lista de pointeri catre obiecte de tip med
 * @param size dimensiunea listei
*/
void print_med_list(med** med_list, int size);

#endif