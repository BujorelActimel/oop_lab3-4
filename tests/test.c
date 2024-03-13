#include "test_domain.h"
#include "test_repo.h"
#include <stdio.h>

int main() {
    all_domain_tests();
    all_repo_tests();
    printf("All tests passed!\n");
    return 0;
}
