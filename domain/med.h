#ifndef MED_H
#define MED_H
#define MAX_NAME_LENGTH 100

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    float concentration;
    int units;
} med;

/**
 * @brief constructorul tipului med
 * @param id id-ul medicamentului
 * @param name numele medicamentului
 * @param concentration concentratia medicamentului
 * @param units numarul de unitati in stoc
 * @return un pointer catre un obiect de tip med
*/
med* construct_med(int id, char* name, float concentration, int units);


/**
 * @brief destructorul tipului med
 * @param med pointer catre obiectul de tip med
*/
void destruct_med(med* med);


/**
 * @brief actualizeaza atributele unui obiect de tip med
 * @param med pointer catre obiectul de tip med
 * @param name noul nume al medicamentului
 * @param concentration noua concentratie a medicamentului
 * @param units noul numar de unitati in stoc
*/
void update_med(med* med, char* name, float concentration, int units);


/**
 * @brief tipareste atributele unui obiect de tip med
 * @param med pointer catre obiectul de tip med
*/
void print_med(med* med);


/**
 * @brief tipareste atributele unei liste de obiecte de tip med
 * @param med_list lista de pointeri catre obiecte de tip med
 * @param size dimensiunea listei
*/
void print_med_list(med** med_list, int size);

#endif