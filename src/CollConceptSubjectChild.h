#ifndef COLLCONCEPTSUBJECTCHILD_H
#define COLLCONCEPTSUBJECTCHILD_H

#include "CollConcept.h"

class CollConceptSubjectChild : public CollConcept {
public:
    CollConceptSubjectChild();
    ~CollConceptSubjectChild();
    void Init();
    /* Check if the wh exists by checking the name in the whwords vector */
    bool checkIfExist(std::string subjectChild_Name);
	bool checkIfExistInVector(std::vector<std::string> userSentence);
	bool checkIfExistInVector(std::string &save, std::vector<std::string> userSentence);

    std::string getSubjectChild(std::string name, int person);
	std::string getSubjectForMemory(std::string subject);


	void addSubject(std::string parent, std::string name, std::string i, 
		std::string you, std::vector<std::string> he, std::string we, std::string youp, std::string they);

    void deleteAll();
protected:
private:
    std::vector<CONCEPT_SUBJECT_CHILD> _subjectChildWords;

};


#endif // COLLCONCEPTSUBJECTCHILD_H
