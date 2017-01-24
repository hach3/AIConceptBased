#include "ai.h"
#include <iostream>
#include <algorithm>


AI::AI()
{
    this->Initialization();
}
AI::~AI()
{
    //Delete all the content in collectionner
    this->_souvenirs.deleteAll();

    this->_conceptAux.deleteAll();
    this->_conceptBe.deleteAll();
    this->_conceptComplement.deleteAll();
    this->_ConceptComplementChild.deleteAll();
    this->_ConceptSubject.deleteAll();
    this->_ConceptSubjectChild.deleteAll();
    this->_ConceptVerb.deleteAll();
    this->_ConceptWH.deleteAll();
    this->_Expression.deleteAll();
}

void AI::Initialization()
{
    //Example of initialization
    this->_souvenirs.Init();

    this->_conceptAux.Init();
    this->_conceptBe.Init();
    this->_conceptComplement.Init();
    this->_ConceptComplementChild.Init();
    this->_ConceptSubject.Init();
    this->_ConceptSubjectChild.Init();
    this->_ConceptVerb.Init();
    this->_ConceptWH.Init();
    this->_Expression.Init();
}

void AI::saySomething()
{
	if (this->sentenceToSay == "")
	{
		this->sentenceToSay = "So many concepts are still unknown to me...";
	}
	this->sentenceToSay = this->putToLowerCase(this->sentenceToSay);
	std::cout << this->sentenceToSay << std::endl;

	//Let's convert the string to say in wstring
	std::wstring text(this->sentenceToSay.begin(), this->sentenceToSay.end());

	ISpVoice * pVoice = NULL;

	if (FAILED(::CoInitialize(NULL)))
	{

	}
	else
	{
		HRESULT hr = CoCreateInstance(CLSID_SpVoice, NULL, CLSCTX_ALL, IID_ISpVoice, (void **)&pVoice);
		if (SUCCEEDED(hr))

		{

			hr = pVoice->Speak(text.c_str(), 0, NULL);
			pVoice->Release();
			pVoice = NULL;
		}

		::CoUninitialize();

	}

}


bool AI::checkIfQuestionWHBeSC(std::string &wh, std::string &be, std::string &subject, std::string &complement, std::vector<std::string> vectorSentence)
{
	bool isWHBeSC = false;

	if (this->_ConceptWH.checkIfExistInVector(wh, vectorSentence) &&
		this->_conceptBe.checkIfExistInVector(be, vectorSentence) &&
		(this->_ConceptSubject.checkIfExistInVector(subject, vectorSentence) ||
		this->_ConceptSubjectChild.checkIfExistInVector(subject, vectorSentence)) &&
		(this->_conceptComplement.checkIfExistByWordInVector(complement, vectorSentence) ||
		this->_ConceptComplementChild.checkIfExistByWordInVector(complement, vectorSentence))
		)
	{
		isWHBeSC = true;
	}
	return isWHBeSC;
}

bool AI::checkIfQuestionWHBeS(std::string &wh, std::string &be, std::string &subject, std::vector<std::string> vectorSentence)
{
	bool isWHBeS = false;

	if (this->_ConceptWH.checkIfExistInVector(wh, vectorSentence) &&
		this->_conceptBe.checkIfExistInVector(be, vectorSentence) &&
		(this->_ConceptSubject.checkIfExistInVector(subject, vectorSentence) ||
		this->_ConceptSubjectChild.checkIfExistInVector(subject, vectorSentence))
		)
		
	{
		isWHBeS = true;
	}
	return isWHBeS;
}



bool AI::checkIfQuestionWHBeC(std::string &wh, std::string &be, std::string &complement, std::vector<std::string> vectorSentence)
{
	bool isWHBeC = false;

	if (this->_ConceptWH.checkIfExistInVector(wh, vectorSentence) &&
		this->_conceptBe.checkIfExistInVector(be, vectorSentence) &&
		(this->_conceptComplement.checkIfExistByWordInVector(complement, vectorSentence) ||
		this->_ConceptComplementChild.checkIfExistByWordInVector(complement, vectorSentence))
		)
	{
		isWHBeC = true;
	}
	return isWHBeC;
}









/* Turn a string to uppercase and return it. I use it to turn the userSentence concepts to uppercase to compare them with the AI's concepts*/
std::string AI::putToUpperCase(std::string s)
{
	std::transform(s.begin(), s.end(), s.begin(), ::toupper);

	return s;
}
std::string AI::putToLowerCase(std::string s)
{
	std::transform(s.begin(), s.end(), s.begin(), ::tolower);

	return s;
}
/* Extract the word of a string in a vector and return it*/
std::vector<std::string> AI::split(const std::string& s)
{
	std::vector<std::string> ret;
	typedef std::string::size_type string_size;
	string_size i = 0;

	// invariant: we have processed characters [original value of i, i)
	while (i != s.size()) {
		// ignore leading blanks
		// invariant: characters in range [original i, current i) are all spaces
		while (i != s.size() && isspace(s[i]))
			++i;

		// find end of next word
		string_size j = i;
		// invariant: none of the characters in range [original j, current j)is a space
		while (j != s.size() && !isspace(s[j]))
			j++;

		// if we found some nonwhitespace characters
		if (i != j) {
			// copy from s starting at i and taking j - i chars
			ret.push_back(s.substr(i, j - i));
			i = j;
		}
	}
	return ret;
}
