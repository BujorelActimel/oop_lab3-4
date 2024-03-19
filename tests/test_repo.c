#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "../domain/med.h"
#include "../repository/repo.h"

void test_construct_repo() {
    repo* repository = construct_repo();
    assert(repository->length == 0);
    assert(repository->capacity == 1);
    destroy_repo(repository);
}

void test_add_med() {
    repo* repository = construct_repo();

    med* item = construct_med(1, "Paracetamol", 500, 10);
    add_med(repository, item);

    assert(repository->length == 1);
    assert(repository->inventory[0]->id == 1);
    assert(strcmp(repository->inventory[0]->name, "Paracetamol") == 0);
    assert(repository->inventory[0]->concentration == 500);
    assert(repository->inventory[0]->units == 10);

    // Nu se adauga un medicament cu acelasi nume, ci se adauga cantitatea la cel existent
    med* item2 = construct_med(2, "Paracetamol", 500, 10);
    add_med(repository, item2);

    assert(repository->length == 1);
    assert(repository->inventory[0]->id == 1);
    assert(repository->inventory[0]->units == 20);

    // testeaza dublarea capacitatii
    med* item3 = construct_med(3, "Ibuprofen", 200, 10);
    add_med(repository, item3);
    assert(repository->length == 2);
    assert(repository->capacity == 2);

    destroy_repo(repository);
}

int main() {
    test_construct_repo();
    test_add_med();
    printf("All Repository tests passed!\n");
    return 0;
}
