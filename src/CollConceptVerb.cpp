#include "CollConceptVerb.h"

CollConceptVerb::CollConceptVerb()
	: CollConcept()
{
	
}
CollConceptVerb::~CollConceptVerb()
{
	this->_verbWords.clear();
}

void CollConceptVerb::Init()
{
	std::vector<std::string> eatConcept;
	eatConcept.push_back("EAT");
	this->addVerb("CONCEPT_EAT", eatConcept);
}

/* Check if the wh exists by checking the name in the whwords vector */
bool CollConceptVerb::checkIfExist(std::string verb_name)
{
	bool found = false;
	for (int i = 0; i < this->_verbWords.size(); i++)
	{
		if (this->_verbWords.at(i).name == verb_name)
		{
			found = true;
		}
	}
	return found;
}
void CollConceptVerb::deleteAll()
{
    this->_verbWords.clear();
}
//Return the concept of a word.
std::string CollConceptVerb::containInto(std::string word)
{
	std::string container;
	for (int i = 0; i < this->_verbWords.size(); i++)
	{
		for (int y = 0; y < this->_verbWords.at(i).verbWords.size(); y++)
		{
			if (this->_verbWords.at(i).verbWords.at(y) == word)
			{
				container = this->_verbWords.at(i).name;
			}
		}
	}
	return container;
}

//check if a word is contain in a concept
bool CollConceptVerb::containIntoConcept(std::string name,
                                         std::string word)
{
	bool found;
	for (int i = 0; i < this->_verbWords.size(); i++)
	{
		for (int y = 0; y < this->_verbWords.at(i).verbWords.size(); y++)
		{
			if (this->_verbWords.at(i).name == name && this->_verbWords.at(i).verbWords.at(y) == word)
			{
				found = true;
			}
		}
	}
	return found;
}

void CollConceptVerb::addVerb(std::string name, std::vector<std::string> conceptWords)
{
	CONCEPT_VERB verb = { name, conceptWords };
	this->_verbWords.push_back(verb);
}