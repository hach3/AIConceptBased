#ifndef COLLCONCEPT_H
#define COLLCONCEPT_H

#include <vector>
#include <string>
#include "concept.h"


class CollConcept {
public:
    CollConcept();
    ~CollConcept();
	std::string getCurrentConceptWord();
	std::string putToUpperCase(std::string s);
	std::string putToLowerCase(std::string s);
protected:
	std::string _currentConceptWord;
private:
	


};
#endif // COLLCONCEPT_H
