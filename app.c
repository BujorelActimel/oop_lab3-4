#include <stdio.h>
#include "domain/med.h"

int main() {
    printf("Application entrypoint!\n");

    struct med* med1 = construct_med(1, "Paracetamol", 500, 20);

    print_med(med1);
    
    destruct_med(med1);

    return 0;
}
