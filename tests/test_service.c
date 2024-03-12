#include "../service/service.h"
#include "../repository/repo.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>

void test_add_medication() {
    repo* repository = construct_repo();
    add_medication(repository, 1, "Paracetamol", 500, 100);
    assert(repository->length == 1);
    assert(repository->inventory[0]->id == 1);
    assert(strcmp(repository->inventory[0]->name, "Paracetamol") == 0);
    assert(repository->inventory[0]->concentration == 500);
    assert(repository->inventory[0]->units == 100);
    destruct_med(repository->inventory[0]);
}

void test_update_medication() {
    repo* repository = construct_repo();
    add_medication(repository, 1, "Paracetamol", 500, 100);
    update_medication(repository, 1, "Paracetamol", 100);
    assert(repository->inventory[0]->concentration == 100);

    add_medication(repository, 2, "Ibuprofen", 200, 0);
    update_medication(repository, 2, "Ibuprofen", 400);
    // nu ar trebui sa se modifice pentru ca numarul de unitati este 0
    assert(repository->inventory[1]->concentration == 200);
    
    destruct_med(repository->inventory[0]);
    destruct_med(repository->inventory[1]);
}

void all_service_tests() {
    test_add_medication();
    test_update_medication();
    printf("All Service tests passed!\n");
}