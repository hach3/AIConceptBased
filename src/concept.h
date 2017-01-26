#ifndef CONCEPT_H
#define CONCEPT_H

#include <string>
#include <vector>

/*
This contain all the english concept languages like wh, name, verb, auxiliair...

*/
typedef struct CONCEPT_WH CONCEPT_WH;
struct CONCEPT_WH {
    std::string WH_PARENT; //Which is child of who.
    std::string WH_NAME;
    std::vector<std::string> WH_WORDS; //CONCEPT_WH({"what", "when", "where", blabla...
};

typedef struct CONCEPT_BE CONCEPT_BE;
struct CONCEPT_BE {
    std::string temps;
    std::string I;
    std::string You;
    std::string He;
    std::string We;
    std::string YouP;
    std::string They;
};

typedef struct CONCEPT_AUX CONCEPT_AUX;
struct CONCEPT_AUX {
    std::string name;
    std::string temps;
    std::string I;
    std::string You;
    std::string He;
    std::string We;
    std::string YouP;
    std::string They;
};


typedef struct CONCEPT_SUBJECT CONCEPT_SUBJECT;
struct CONCEPT_SUBJECT {
	std::string name;
    std::string I;
    std::string You;
	std::vector<std::string> He;
    std::string We;
    std::string YouP;
    std::string They;
};


typedef struct CONCEPT_SUBJECT_CHILD CONCEPT_SUBJECT_CHILD;
struct CONCEPT_SUBJECT_CHILD {
    //CONCEPT_SUBJECT* parent;
	std::string parent;
    std::string name;
    std::string I;
    std::string You;
    std::vector<std::string> He;
    std::string We;
    std::string YouP;
    std::string They;
};


typedef struct CONCEPT_VERB CONCEPT_VERB;
struct CONCEPT_VERB {
    std::string name;
    std::vector<std::string> verbWords;
};


typedef struct CONCEPT_COMPLEMENTS CONCEPT_COMPLEMENTS;
struct CONCEPT_COMPLEMENTS {
    std::string name;
    std::vector<std::string> conceptWords;
};


typedef struct CONCEPT_COMPLEMENTS_CHILD CONCEPT_COMPLEMENTS_CHILD;
struct CONCEPT_COMPLEMENTS_CHILD {
   // CONCEPT_COMPLEMENTS* parent;
	std::string parent;
	std::string name;
    std::vector<std::string> conceptWords;
};


typedef struct CONCEPT_EXPRESSION CONCEPT_EXPRESSION;
struct CONCEPT_EXPRESSION {
    std::string value;
    std::string answer;
};

#endif // CONCEPT_H
