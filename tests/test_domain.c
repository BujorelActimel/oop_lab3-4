#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "../domain/med.h"

void test_construct_med() {
    struct med* med1 = construct_med(1, "Paracetamol", 500, 20);
    assert(med1->id == 1);
    assert(strcmp(med1->name, "Paracetamol") == 0);
    assert(med1->concentration == 500);
    assert(med1->units == 20);
    destruct_med(med1);
}

int main() {
    test_construct_med();
    printf("All tests passed!\n");
    return 0;
}
