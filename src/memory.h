#ifndef MEMORY_H
#define MEMORY_H

#include <string>
#include <vector>

/*
This header create souvenir structure. It takes a concept_verb and a concept_name. It allows to answer question.
Example :

What is your name ?
What = getWhat() -> wh
is = concept_be 3eme person.
subject = your name;
your = concept_subject child.
name = concept_complement child. concept_name -> NAME

getWhat() from souvenirs where "who" = "you", and concept_verb = "be", "concept_name" = "name".

*/
struct Souvenir {

    
	//1, 2, 3, 4, 5, 6//
    std::string WHO;
    std::string WHY;
    std::string WHERE;
    std::string WHEN;
    std::string WHAT;
    std::string HOW;

	
	std::string CONCEPT_VERB;
	std::string CONCEPT_NAME;


    bool is;
    bool have;



};


#endif // MEMORY_H
