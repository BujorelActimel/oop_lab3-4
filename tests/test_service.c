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

    destroy_repo(repository);
}

void test_update_medication() {
    repo* repository = construct_repo();

    add_medication(repository, 1, "Paracetamol", 500, 100);

    update_medication(repository, 1, "Ibuprofren", 100);
    assert(repository->length == 1);
    assert(repository->inventory[0]->id == 1);
    assert(strcmp(repository->inventory[0]->name, "Ibuprofren") == 0);
    assert(repository->inventory[0]->concentration == 100);
    assert(repository->inventory[0]->units == 100);

    destroy_repo(repository);
}

void test_delete_med_stock() {
    repo* repository = construct_repo();

    add_medication(repository, 1, "Paracetamol", 500, 100);

    delete_med_stock(repository, 1);
    assert(repository->length == 1);
    assert(repository->inventory[0]->id == 1);
    assert(strcmp(repository->inventory[0]->name, "Paracetamol") == 0);
    assert(repository->inventory[0]->concentration == 500);
    assert(repository->inventory[0]->units == 0);

    destroy_repo(repository);
}

void test_num_of_meds_in_stock() {
    repo* repository = construct_repo();

    add_medication(repository, 1, "Paracetamol", 500, 100);
    add_medication(repository, 2, "Ibuprofren", 100, 200);
    add_medication(repository, 3, "Aspirin", 300, 300);

    int count = num_of_meds_in_stock(repository->inventory, repository->length);
    assert(count == 3);

    delete_med_stock(repository, 1);

    count = num_of_meds_in_stock(repository->inventory, repository->length);
    assert(count == 2);

    destroy_repo(repository);
}

void test_sort_meds_in_stock() {
    repo* repository = construct_repo();

    add_medication(repository, 1, "Paracetamol", 500, 100);
    add_medication(repository, 2, "Ibuprofren", 100, 200);
    add_medication(repository, 3, "Aspirin", 300, 300);

    med** sorted_inventory = sort_meds_in_stock(repository->inventory, repository->length, 0);
    assert(strcmp(sorted_inventory[0]->name, "Aspirin") == 0);
    assert(strcmp(sorted_inventory[1]->name, "Ibuprofren") == 0);
    assert(strcmp(sorted_inventory[2]->name, "Paracetamol") == 0);

    free(sorted_inventory);
    destroy_repo(repository);


    repo* repository2 = construct_repo();

    add_medication(repository2, 3, "Aspirin", 300, 300);
    add_medication(repository2, 2, "Ibuprofren", 100, 200);
    add_medication(repository2, 1, "Paracetamol", 500, 100);

    med** sorted_inventory2 = sort_meds_in_stock(repository2->inventory, repository2->length, 1);
    assert(strcmp(sorted_inventory2[0]->name, "Paracetamol") == 0);
    assert(strcmp(sorted_inventory2[1]->name, "Ibuprofren") == 0);
    assert(strcmp(sorted_inventory2[2]->name, "Aspirin") == 0);

    free(sorted_inventory2);
    destroy_repo(repository2);
}

void test_filter_meds_by_units() {
    repo* repository = construct_repo();

    add_medication(repository, 1, "Paracetamol", 500, 100);
    add_medication(repository, 2, "Ibuprofren", 100, 200);
    add_medication(repository, 3, "Aspirin", 300, 300);

    med** filtered_inventory = filter_meds_by_units(repository->inventory, repository->length, 300);
    assert(filtered_inventory[0]->id == 1);
    assert(filtered_inventory[0]->units == 100);
    assert(filtered_inventory[1]->id == 2);
    assert(filtered_inventory[1]->units == 200);

    free(filtered_inventory);
    destroy_repo(repository);
}

void test_filter_meds_by_initial_letter() {
    repo* repository = construct_repo();

    add_medication(repository, 1, "Paracetamol", 500, 100);
    add_medication(repository, 2, "Ibuprofren", 100, 200);
    add_medication(repository, 3, "Aspirin", 300, 300);

    med** filtered_inventory = filter_meds_by_initial_letter(repository->inventory, repository->length, 'P');
    assert(filtered_inventory[0]->id == 1);
    assert(strcmp(filtered_inventory[0]->name, "Paracetamol") == 0);

    free(filtered_inventory);
    destroy_repo(repository);
}

int main() {
    test_add_medication();
    test_update_medication();
    test_delete_med_stock();
    test_num_of_meds_in_stock();
    test_sort_meds_in_stock();
    test_filter_meds_by_units();
    test_filter_meds_by_initial_letter();
    printf("All Service tests passed!\n");
    return 0;
}
