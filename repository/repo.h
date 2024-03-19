#ifndef REPO_H
#define REPO_H

#include "../domain/med.h"

typedef struct {
    med** inventory;
    int length;
    int capacity;
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


#endif