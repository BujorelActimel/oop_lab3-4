#!/bin/bash

# Compile source files
gcc -c -Wall -g -fprofile-arcs -ftest-coverage domain/med.c -o domain/med.o
gcc -c -Wall -g -fprofile-arcs -ftest-coverage repository/repo.c -o repository/repo.o
gcc -c -Wall -g -fprofile-arcs -ftest-coverage service/service.c -o service/service.o

# Compile test files
gcc -c -Wall -g -fprofile-arcs -ftest-coverage tests/test_domain.c -o tests/test_domain.o
gcc -c -Wall -g -fprofile-arcs -ftest-coverage tests/test_repo.c -o tests/test_repo.o
gcc -c -Wall -g -fprofile-arcs -ftest-coverage tests/test_service.c -o tests/test_service.o
gcc -c -Wall -g -fprofile-arcs -ftest-coverage tests/test.c -o tests/test.o

# Link the object files and run the tests
gcc -o test domain/med.o repository/repo.o service/service.o tests/test_domain.o tests/test_repo.o tests/test_service.o tests/test.o -fprofile-arcs -ftest-coverage
./test

# Run gcov on the source files to generate the coverage reports
gcov domain/med.c
gcov repository/repo.c
gcov service/service.c