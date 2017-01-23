#include "CollConceptBe.h"

CollConceptBe::CollConceptBe()
{

}
CollConceptBe::~CollConceptBe()
{
	this->_BeWords.clear();
}
void CollConceptBe::Init()
{
	this->addBe("PRESENT", "AM", "ARE", "IS", "ARE", "ARE", "ARE");
}
/* Check if the wh exists by checking the name in the whwords vector */
bool CollConceptBe::checkIfExist(std::string be_Name)
{
	bool found = false;
	for (unsigned int i = 0; i < this->_BeWords.size(); i++)
	{
		if (this->_BeWords.at(i).I == be_Name || this->_BeWords.at(i).You == be_Name || 
			this->_BeWords.at(i).He == be_Name || this->_BeWords.at(i).We == be_Name || 
			this->_BeWords.at(i).YouP == be_Name || this->_BeWords.at(i).They == be_Name)
		{
			found = true;
		}
	}
	return found;
}
void CollConceptBe::deleteAll()
{
    this->_BeWords.clear();
}
/* Renvoie be conjugu� � la intieme personne */
std::string CollConceptBe::getBeConjugue(std::string temps,
                                         int personne)
{
	std::string beConjugue;
	for (unsigned int i = 0; i < this->_BeWords.size(); i++)
	{
		if (this->_BeWords.at(i).temps == temps)
		{
			switch (personne)
			{
			case 1:
				beConjugue = this->_BeWords.at(i).I;
			case 2:
				beConjugue = this->_BeWords.at(i).You;
			case 3:
				beConjugue = this->_BeWords.at(i).He;
			case 4:
				beConjugue = this->_BeWords.at(i).We;
			case 5:
				beConjugue = this->_BeWords.at(i).YouP;
			case 6:
				beConjugue = this->_BeWords.at(i).They;
			}
		}
	}
	return beConjugue;
}

void CollConceptBe::addBe(std::string temps,
                          std::string i,
                          std::string you,
                          std::string he,
                          std::string we,
                          std::string youp,
                          std::string they)
{
	CONCEPT_BE be = { temps, i, you, he, we, youp, they };
	this->_BeWords.push_back(be);
}

