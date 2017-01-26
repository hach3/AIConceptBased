#ifndef COLLCONCEPTBE_H
#define COLLCONCEPTBE_H

#include "CollConcept.h"

class CollConceptBe : public CollConcept {
public:
    CollConceptBe();
    ~CollConceptBe();
    void Init();
    /* Check if the wh exists by checking the name in the whwords vector */
    bool checkIfExist(std::string be_Name);
	bool checkIfExistInVector(std::vector<std::string> userSentence);
	bool checkIfExistInVector(std::string &save, std::vector<std::string> userSentence);
    /* Renvoie be conjugué à la intieme personne */
    std::string getBeConjugue(std::string temps, int personne);

    void addBe(std::string temps, std::string i, std::string you, std::string he,
               std::string we, std::string youp, std::string they);


    void deleteAll();


protected:
private:
    std::vector<CONCEPT_BE> _BeWords;
	std::string _currentConceptWord;
};


#endif // COLLCONCEPTBE_H
