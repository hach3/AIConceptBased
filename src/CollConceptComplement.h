#ifndef COLLCONCEPTCOMPLEMENT_H
#define COLLCONCEPTCOMPLEMENT_H

#include "CollConcept.h"

class CollConceptComplement : public CollConcept {
public:
    CollConceptComplement();
    ~CollConceptComplement();
    void Init();
    /* Check if the wh exists by checking the name in the whwords vector */
    bool checkIfExist(std::string Complement_Name);
	bool checkIfExistByWord(std::string word);
	bool checkIfExistByWordInVector(std::vector<std::string> userSentence);
	bool checkIfExistByWordInVector(std::string &save, std::vector<std::string> userSentence);

     //Return the concept of a word.
    std::string containInto(std::string word);

    //check if a word is contain in a concept
    bool containIntoConcept(std::string name, std::string word);
	void addComplement(std::string name, std::vector<std::string> words);

    void deleteAll();

protected:
private:
    std::vector<CONCEPT_COMPLEMENTS> _ComplementWords;

};


#endif // COLLCONCEPTCOMPLEMENTCHILD_H
