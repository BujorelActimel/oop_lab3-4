#ifndef REPO_H
#define REPO_H

#include "../domain/med.h"

typedef struct {
    med* inventory[100];
    int length;
} repo;

repo* construct_repo();
void destroy_repo(repo* repository);
void add_med(repo* repository, med* new_med);
void update_med_repo(repo* repository, int item_id, char* new_name, float new_concentration);
void delete_med_stock(repo* repository, int item_id);

#endif