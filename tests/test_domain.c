#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "../domain/med.h"

void test_construct_med() {
    med* med1 = construct_med(1, "Paracetamol", 500, 20);
    assert(med1->id == 1);
    assert(strcmp(med1->name, "Paracetamol") == 0);
    assert(med1->concentration == 500);
    assert(med1->units == 20);
    destruct_med(med1);
}

void test_update_med() {
    med* med1 = construct_med(1, "Paracetamol", 500, 20);
    assert(med1->id == 1);
    assert(strcmp(med1->name, "Paracetamol") == 0);
    assert(med1->concentration == 500);
    assert(med1->units == 20);

    update_med(med1, "Paracetamol", 1000, 10);

    assert(med1->id == 1);
    assert(strcmp(med1->name, "Paracetamol") == 0);
    assert(med1->concentration == 1000);
    assert(med1->units == 10);

    destruct_med(med1);
}

void all_domain_tests() {
    test_construct_med();
    test_update_med();
    printf("All Domain tests passed!\n");
}
