#include "CollConceptComplement.h"

CollConceptComplement::CollConceptComplement()
	: CollConcept()
{

}
CollConceptComplement::~CollConceptComplement()
{
	this->_ComplementWords.clear();
}
void CollConceptComplement::Init()
{
	std::vector<std::string> nameWords;
	nameWords.push_back("NAME");
	this->addComplement("CONCEPT_NAME", nameWords);

	std::vector<std::string> carWords;
	carWords.push_back("CAR");
	this->addComplement("CONCEPT_CAR", carWords);

	std::vector<std::string> loveWords;
	loveWords.push_back("HEARTH");
	loveWords.push_back("LOVE");
	this->addComplement("CONCEPT_LOVE", loveWords);


}
/* Check if the wh exists by checking the name in the whwords vector */
bool CollConceptComplement::checkIfExist(std::string Complement_Name)
{
	bool found = false;
	for (unsigned int i = 0; i < this->_ComplementWords.size(); i++)
	{
		if (this->_ComplementWords.at(i).name == Complement_Name)
		{
			found = true;
		}
	}
	return found;
}
bool CollConceptComplement::checkIfExistByWord(std::string word)
{
	bool found = false;
	for (unsigned int i = 0; i < this->_ComplementWords.size(); i++)
	{
		for (int y = 0; y < this->_ComplementWords.at(i).conceptWords.size(); y++)
		{
			if (this->_ComplementWords.at(i).conceptWords.at(y) == word)
			{
				found = true;
			}
		}
	}
	return found;
}
bool CollConceptComplement::checkIfExistByWordInVector(std::vector<std::string> userSentence)
{
	bool found = false;
	for (int a = 0; a < userSentence.size(); a++)
	{
		for (unsigned int i = 0; i < this->_ComplementWords.size(); i++)
		{
			for (int y = 0; y < this->_ComplementWords.at(i).conceptWords.size(); y++)
			{
				if (this->_ComplementWords.at(i).conceptWords.at(y) == userSentence.at(a))
				{
					found = true;
					this->_currentConceptWord = userSentence.at(a);
				}
			}
		}
	}
	return found;
}

bool CollConceptComplement::checkIfExistByWordInVector(std::string &save, std::vector<std::string> userSentence)
{
	bool found = false;
	for (int a = 0; a < userSentence.size(); a++)
	{
		for (unsigned int i = 0; i < this->_ComplementWords.size(); i++)
		{
			for (int y = 0; y < this->_ComplementWords.at(i).conceptWords.size(); y++)
			{
				if (this->_ComplementWords.at(i).conceptWords.at(y) == userSentence.at(a))
				{
					found = true;
					save = this->putToUpperCase(userSentence.at(a));
				}
			}
		}
	}
	return found;
}


void CollConceptComplement::deleteAll()
{
    this->_ComplementWords.clear();
}
//Return the concept of a word.
std::string CollConceptComplement::containInto(std::string word)
{
	std::string conceptName;
	for (unsigned int i = 0; i < this->_ComplementWords.size(); i++)
	{
		for (int y = 0; y < this->_ComplementWords.at(i).conceptWords.size(); y++)
		{
			if (this->_ComplementWords.at(i).conceptWords.at(y) == word)
			{
				conceptName = this->_ComplementWords.at(i).name;
			}
		}
	}
	return conceptName;
}

//check if a word is contain in a concept
bool CollConceptComplement::containIntoConcept(std::string name,
                                              std::string word)
{
	bool found;
	for (unsigned int i = 0; i < this->_ComplementWords.size(); i++)
	{
		for (int y = 0; y < this->_ComplementWords.at(i).conceptWords.size(); y++)
		{
			if (this->_ComplementWords.at(i).name == name && this->_ComplementWords.at(i).conceptWords.at(y) == word)
			{
				found = true;
			}
		}
	}
	return found;
}

void CollConceptComplement::addComplement(std::string name, 
	std::vector<std::string> words)
{
	CONCEPT_COMPLEMENTS complement = { name, words };
	this->_ComplementWords.push_back(complement);
}