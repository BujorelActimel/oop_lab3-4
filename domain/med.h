#ifndef MED_H
#define MED_H

typedef struct {
    int id;
    char* name;
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

#endif