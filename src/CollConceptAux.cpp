#include "CollConceptAux.h"

CollConceptAux::CollConceptAux()
	: CollConcept()
{

}
CollConceptAux::~CollConceptAux()
{
	this->_auxWords.clear();
}
void CollConceptAux::Init()
{
	/*
	Function to init auxiliary words
	*/
	this->addAux("DO", "PRESENT", "DO", "DO", "DO", "DO", "DO", "DO");
}
/* Check if the wh exists by checking the name in the whwords vector */
bool CollConceptAux::checkIfExist(std::string aux_Name)
{
	bool found = false;
	for (unsigned int i = 0; i < this->_auxWords.size(); i++)
	{
		if (this->_auxWords.at(i).name == aux_Name)
		{
			found = true;
		}
	}
	return found;
}
bool CollConceptAux::checkIfExist(std::string aux_Name,
                                  std::string temps)
{
	bool found = false;
	for (unsigned int i = 0; i < this->_auxWords.size(); i++)
	{
		if (this->_auxWords.at(i).name == aux_Name && this->_auxWords.at(i).temps == temps)
		{
			found = true;
		}
	}
	return found;
}
void CollConceptAux::deleteAll()
{
    this->_auxWords.clear();
}
/* Renvoie be conjugué à la intieme personne */
std::string CollConceptAux::getAuxConjugue(std::string name,
                                           std::string temps,
                                           int personne)
{
	std::string auxConjugue;
	for(unsigned int i = 0; i < this->_auxWords.size(); i++)
	{
		if (this->_auxWords.at(i).name == name && this->_auxWords.at(i).temps == temps)
		{
			switch (personne)
			{
			case 1:
				auxConjugue = this->_auxWords.at(i).I;
			case 2:
				auxConjugue = this->_auxWords.at(i).You;
			case 3:
				auxConjugue = this->_auxWords.at(i).He;
			case 4:
				auxConjugue = this->_auxWords.at(i).We;
			case 5: 
				auxConjugue = this->_auxWords.at(i).YouP;
			case 6:
				auxConjugue = this->_auxWords.at(i).They;
			}
		}
	}
	return auxConjugue;
}

void CollConceptAux::addAux(std::string name,
                            std::string temps,
                            std::string i,
                            std::string you,
                            std::string he,
                            std::string we,
                            std::string youp,
                            std::string they)
{
	CONCEPT_AUX aux = { name, temps, i, you, he, we, youp, they };
	this->_auxWords.push_back(aux);
}

