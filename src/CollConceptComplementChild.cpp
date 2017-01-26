#include "CollConceptComplementChild.h"

CollConceptComplementChild::CollConceptComplementChild()
	: CollConcept()
{

}
CollConceptComplementChild::~CollConceptComplementChild()
{
	this->_ComplementChildWords.clear();
}
void CollConceptComplementChild::Init()
{
	std::vector<std::string> firstNameWords;
	firstNameWords.push_back("FIRSTNAME");
	this->addConcept("CONCEPT_NAME", "CONCEPT_NAME", firstNameWords);
}
/* Check if the wh exists by checking the name in the whwords vector */
bool CollConceptComplementChild::checkIfExist(std::string ComplementChild_Name)
{
	bool found = false;
	for (unsigned int i = 0; i < this->_ComplementChildWords.size(); i++)
	{
		if (this->_ComplementChildWords.at(i).name == ComplementChild_Name)
		{
			found = true;
		}
	}
	return found;
}
bool CollConceptComplementChild::checkIfExistByWord(std::string word)
{
	bool found = false;
	for (unsigned int i = 0; i < this->_ComplementChildWords.size(); i++)
	{
		for (int y = 0; y < this->_ComplementChildWords.at(i).conceptWords.size(); y++)
		{
			if (this->_ComplementChildWords.at(i).conceptWords.at(y) == word)
			{
				found = true;
			}
		}
	}
	return found;
}
bool CollConceptComplementChild::checkIfExistByWordInVector(std::vector<std::string> userSentence)
{
	bool found = false;
	for (int a = 0; a < userSentence.size(); a++)
	{
		for (unsigned int i = 0; i < this->_ComplementChildWords.size(); i++)
		{
			for (int y = 0; y < this->_ComplementChildWords.at(i).conceptWords.size(); y++)
			{
				if (this->_ComplementChildWords.at(i).conceptWords.at(y) == userSentence.at(a))
				{
					found = true;
					this->_currentConceptWord = userSentence.at(a);
				}
			}
		}
	}
	return found;
}

bool CollConceptComplementChild::checkIfExistByWordInVector(std::string &save, std::vector<std::string> userSentence)
{
	bool found = false;
	for (int a = 0; a < userSentence.size(); a++)
	{
		for (unsigned int i = 0; i < this->_ComplementChildWords.size(); i++)
		{
			for (int y = 0; y < this->_ComplementChildWords.at(i).conceptWords.size(); y++)
			{
				if (this->_ComplementChildWords.at(i).conceptWords.at(y) == userSentence.at(a))
				{
					found = true;
					save = this->putToUpperCase(userSentence.at(a));
				}
			}
		}
	}
	return found;
}


void CollConceptComplementChild::deleteAll()
{
    this->_ComplementChildWords.clear();
}
//Return the concept of a word.
std::string CollConceptComplementChild::containInto(std::string word)
{
	std::string conceptName;
	for (unsigned int i = 0; i < this->_ComplementChildWords.size(); i++)
	{
		for (int y = 0; y < this->_ComplementChildWords.at(i).conceptWords.size(); y++)
		{
			if (this->_ComplementChildWords.at(i).conceptWords.at(y) == word)
			{
				conceptName = this->_ComplementChildWords.at(i).name;
			}
		}
	}
	return conceptName;
}
//check if a word is contain in a concept
bool CollConceptComplementChild::containIntoConcept(std::string name,
                                                    std::string word)
{
	bool found;
	for (unsigned int i = 0; i < this->_ComplementChildWords.size(); i++)
	{
		for (int y = 0; y < this->_ComplementChildWords.at(i).conceptWords.size(); y++)
		{
			if (this->_ComplementChildWords.at(i).name == name && this->_ComplementChildWords.at(i).conceptWords.at(y) == word)
			{
				found = true;
			}
		}
	}
	return found;
}
void CollConceptComplementChild::addConcept(std::string parent,
											std::string name, 
											std::vector<std::string> words)
{
	CONCEPT_COMPLEMENTS_CHILD complementChild = { parent, name, words };
	this->_ComplementChildWords.push_back(complementChild);
}