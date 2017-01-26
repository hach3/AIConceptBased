#ifndef COLLCONCEPTAUX_H
#define COLLCONCEPTAUX_H

#include "CollConcept.h"

class CollConceptAux : public CollConcept {
public:
    CollConceptAux();
    ~CollConceptAux();
    void Init();
    /* Check if the wh exists by checking the name in the whwords vector */
    bool checkIfExist(std::string aux_Name);
    bool checkIfExist(std::string aux_Name, std::string temps);

     /* Renvoie be conjugué à la intieme personne */
    std::string getAuxConjugue(std::string name, std::string temps, int personne);

    void addAux(std::string name, std::string temps, std::string i, std::string you, std::string he,
               std::string we, std::string youp, std::string they);

    void deleteAll();


protected:
private:
    std::vector<CONCEPT_AUX> _auxWords;

};


#endif // COLLCONCEPTBE_H
