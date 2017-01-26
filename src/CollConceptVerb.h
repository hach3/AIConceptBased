#ifndef COLLCONCEPTVERB_H
#define COLLCONCEPTVERB_H

#include "CollConcept.h"

class CollConceptVerb : public CollConcept {
public:
    CollConceptVerb();
    ~CollConceptVerb();
    void Init();
    /* Check if the wh exists by checking the name in the whwords vector */
    bool checkIfExist(std::string verb_name);

    //Return the concept of a word.
    std::string containInto(std::string word);

    //check if a word is contain in a concept
    bool containIntoConcept(std::string name, std::string word);

	void addVerb(std::string name, std::vector<std::string> conceptWords);

    void deleteAll();
protected:
private:
    std::vector<CONCEPT_VERB> _verbWords;

};


#endif // COLLCONCEPTVERB_H
