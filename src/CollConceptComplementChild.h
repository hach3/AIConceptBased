#ifndef COLLCONCEPTCOMPLEMENTCHILD_H
#define COLLCONCEPTCOMPLEMENTCHILD_H

#include "CollConcept.h"

class CollConceptComplementChild : public CollConcept {
public:
    CollConceptComplementChild();
    ~CollConceptComplementChild();
    void Init();
    /* Check if the wh exists by checking the name in the whwords vector */
    bool checkIfExist(std::string ComplementChild_Name);
	bool checkIfExistByWord(std::string word);
	bool checkIfExistByWordInVector(std::vector<std::string> userSentence);
	bool checkIfExistByWordInVector(std::string &save, std::vector<std::string> userSentence);

    //Return the concept of a word.
    std::string containInto(std::string word);

    //check if a word is contain in a concept
    bool containIntoConcept(std::string name, std::string word);
	void addConcept(std::string parent, std::string name, std::vector<std::string> words);

    void deleteAll();
protected:
private:
    std::vector<CONCEPT_COMPLEMENTS_CHILD> _ComplementChildWords;

};


#endif // COLLCONCEPTCOMPLEMENTCHILD_H
