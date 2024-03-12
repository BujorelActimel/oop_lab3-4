#ifndef MED_H
#define MED_H
#define MAX_NAME_LENGTH 100

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    float concentration;
    int units;
} med;

med* construct_med(int id, char* name, float concentration, int units);
void destruct_med(med* med);
void update_med(med* med, char* name, float concentration, int units);
void print_med(med* med);
void print_med_list(med** med_list, int size);

#endif /* MED_H */