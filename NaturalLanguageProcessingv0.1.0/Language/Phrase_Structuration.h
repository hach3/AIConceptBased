#ifndef PHRASE_STRUCTURATION_H
#define PHRASE_STRUCTURATION_H

#include "Language.h"

class Phrase_Structuration {
public:
	Phrase_Structuration();
	~Phrase_Structuration();

	void init();
	void initQuestions();
	void initAffirmations();
	void initNegations();
	

	void getStructure(vector<WORD_AND_TYPE> sentenceTypes);

	
protected:
private:
	vector<vector<WORDS_TYPE>> _phraseTypes;
};

#endif //PHRASE_STRUCTURATION_H