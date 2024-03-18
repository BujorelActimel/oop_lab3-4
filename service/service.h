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