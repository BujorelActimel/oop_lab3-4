#pragma once


#include "../domain/med.h"
#include "../repository/repo.h"

/**
 * @brief creeaza si adauga un medicament in repository
 * @param repository pointer la repository
 * @param id id-ul medicamentului
 * @param name numele medicamentului
 * @param concentration concentratia medicamentului
 * @param quantity cantitatea medicamentului
*/
void add_medication(repo* repository, int id, char* name, float concentration, int quantity);


/**
 * @brief actualizeaza numele si concentratia unui medicament daca au numarul de unitati > 0
 * @param repository pointer la repository
 * @param id id-ul medicamentului
 * @param name numele medicamentului
 * @param concentration concentratia medicamentului
*/
void update_medication(repo* repository, int id, char* name, float concentration);


/**
 * TODO:
 * @brief seteaza numarul de unitati al unui medicament la 0
 * @param repository pointer la repository
 * @param id id-ul medicamentului
*/
void empty_stock(repo* repository, int med_id);


/**
 * TODO:
 * @brief returneaza toate medicamentele din repository sortate dupa nume si numar de unitati
 * @param repository pointer la repository
 * @return med** lista de medicamente
*/
med** sorted_meds(repo* repository);


/**
 * TODO:
 * @brief returneaza toate medicamentele din repository care au numarul de unitati mai mic decat max_stock si incep cu name_initial
 * @param repository pointer la repository
 * @param max_stock numarul maxim de unitati
 * @param name_initial litera cu care incepe numele medicamentului
 * @return med** lista de medicamente
*/
med** filtered_meds(repo* repository, int max_stock, char name_initial);