#ifndef REPO_H
#define REPO_H

#include "../domain/med.h"

typedef struct {
    med* inventory[100];
    int length;
} repo;

/**
 * @brief constructorul tipului repo
 * @return un pointer catre un obiect de tip repo
*/
repo* construct_repo();


/**
 * @brief destructorul tipului repo
 * @param repository pointer catre obiectul de tip repo
*/
void destroy_repo(repo* repository);


/**
 * @brief adauga un medicament in stoc
 * @param repository pointer catre obiectul de tip repo
 * @param new_med pointer catre obiectul de tip med
*/
void add_med(repo* repository, med* new_med);


/**
 * @brief actualizeaza atributele unui obiect de tip med
 * @param repository pointer catre obiectul de tip repo
 * @param item_id id-ul medicamentului
 * @param new_name noul nume al medicamentului
 * @param new_concentration noua concentratie a medicamentului
*/
void update_med_repo(repo* repository, int item_id, char* new_name, float new_concentration, int new_units);

#endif