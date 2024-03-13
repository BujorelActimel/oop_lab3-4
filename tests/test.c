#include "test_domain.h"
#include "test_repo.h"
#include "test_service.h"
#include <stdio.h>

int main() {
    all_domain_tests();
    all_repo_tests();
    all_service_tests();
    printf("All tests passed!\n");
    return 0;
}
