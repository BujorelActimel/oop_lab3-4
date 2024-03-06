#define MAX_NAME_LENGTH 100

struct med {
    int id;
    char name[MAX_NAME_LENGTH];
    float concentration;
    int units;
};

struct med* construct_med(int id, char* name, float concentration, int units);

void destruct_med(struct med* med);

void update_med(struct med* med, char* name, float concentration, int units);

void print_med(struct med* med);

void print_med_list(struct med** med_list, int size);
