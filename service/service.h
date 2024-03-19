#pragma once
#include "../repository/repo.h"

/**
 * @brief adauga un medicament in repository
 * @param repository pointer la repository
 * @param id id-ul medicamentului
 * @param name numele medicamentului
 * @param concentration concentratia medicamentului
 * @param quantity cantitatea medicamentului
 */
void add_medication(repo* repository, int id, char* name, float concentration, int quantity);

/**
 * @brief actualizeaza un medicament din repository daca are numarul de unitati > 0
 * @param repository pointer la repository
 * @param id id-ul medicamentului
 * @param name numele medicamentului
 * @param concentration concentratia medicamentului
 */
void update_medication(repo* repository, int id, char* name, float concentration);

/**
 * @brief asigneaza 0 la atributul units al obiectului de tip med
 * @param repository pointer catre obiectul de tip repo
 * @param item_id id-ul medicamentului
*/
void delete_med_stock(repo* repository, int item_id);

/**
 * @brief numara medicamentele din stoc
 * @param inventory pointer la lista de medicamente
 * @param length lungimea listei de medicamente
 * @return numarul de medicamente din stoc
 */
int num_of_meds_in_stock(med** inventory, int length);

/**
 * @brief sorteaza medicamentele din stoc dupa nume si numar de unitati
 * @param inventory pointer la lista de medicamente
 * @param length lungimea listei de medicamente
 * @return pointer la lista de medicamente sortata
 */
med** sort_meds_in_stock(med** inventory, int length, int reverse);

/**
 * @brief numara medicamentele care au numarul de unitati mai mic decat o valoare data
 * @param inventory pointer la lista de medicamente
 * @param length lungimea listei de medicamente
 * @param value numarul de unitati
 * @return numarul de medicamente care au numarul de unitati mai mic decat o valoare data
 */
int num_of_meds_by_units(med** inventory, int length, int value);

/**
 * @brief filtreaza medicamentele care au numarul de unitati mai mic decat o valoare data
 * @param inventory pointer la lista de medicamente
 * @param length lungimea listei de medicamente
 * @param value numarul de unitati
 * @return pointer la lista de medicamente filtrata
 */
med** filter_meds_by_units(med** inventory, int length, int value);

/**
 * @brief numara medicamentele care incep cu o litera data
 * @param inventory pointer la lista de medicamente
 * @param length lungimea listei de medicamente
 * @param letter litera
 * @return numarul de medicamente care incep cu litera data
 */
int num_of_meds_by_initial_letter(med** inventory, int length, char letter);

/**
 * @brief filtreaza medicamentele care incep cu o litera data
 * @param inventory pointer la lista de medicamente
 * @param length lungimea listei de medicamente
 * @param letter litera
 * @return pointer la lista de medicamente filtrata
 */
med** filter_meds_by_initial_letter(med** inventory, int length, char letter);
