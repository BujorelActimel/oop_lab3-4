#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "../domain/med.h"
#include "../repository/repo.h"

void test_add_med() {
    repo* repository = construct_repo();
    assert(repository->length == 0);
    med* item = construct_med(1, "Paracetamol", 500, 10);
    add_med(repository, item);
    assert(repository->length == 1);
    assert(repository->inventory[0]->id == 1);
    assert(strcmp(repository->inventory[0]->name, "Paracetamol") == 0);
    assert(repository->inventory[0]->concentration == 500);
    assert(repository->inventory[0]->units == 10);
    destroy_repo(repository);
}

void test_update_med_repo() {
    repo* repository = construct_repo();
    med* item = construct_med(1, "Paracetamol", 500, 10);
    add_med(repository, item);
    update_med_repo(repository, 1, "Ibuprofen", 200, 10);
    assert(strcmp(repository->inventory[0]->name, "Ibuprofen") == 0);
    assert(repository->inventory[0]->concentration == 200);
    destroy_repo(repository);
}

void all_repo_tests() {
    test_add_med();
    test_update_med_repo();
    printf("All Repository tests passed!\n");
}
