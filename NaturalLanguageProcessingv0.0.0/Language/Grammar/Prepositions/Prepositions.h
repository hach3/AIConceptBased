#ifndef PREPOSITIONS_H
#define PREPOSITIONS_H


#include "..\..\Words.h"

/*
LORD MOTHER OF ALL PRONOUNS

*/


class Prepositions : public Words {
public:
	Prepositions(void);
	Prepositions(string value, WORDS wordType, WORDS_TYPE type);
	~Prepositions(void);

	string getInfinitiveForm();
	string getIngForm();
	string getPassiveForm();
	string getParticipateForm();
	vector<string> getPresentForm();
	vector<string> getPastForm();

protected:

private:

};

#endif //PREPOSITIONS_H