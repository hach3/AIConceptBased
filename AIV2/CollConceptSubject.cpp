#include "CollConceptSubject.h"


CollConceptSubject::CollConceptSubject()
{

}
CollConceptSubject::~CollConceptSubject()
{
	this->_subjectWords.clear();
}
void CollConceptSubject::Init()
{
	std::vector<std::string> heValues;
	heValues.push_back("HE");
	heValues.push_back("SHE");
	heValues.push_back("IT");
	heValues.push_back("THIS");
	this->addSubject("CONCEPT_SUBJECT", "I", "YOU", heValues, "WE", "YOU", "THEY");
}
/* Check if the wh exists by checking the name in the whwords vector */
bool CollConceptSubject::checkIfExist(std::string subject_Name)
{
	bool found = false;
	for (unsigned int i = 0; i < this->_subjectWords.size(); i++)
	{
		if (i == 2)
		{
			for (int y = 0; y < this->_subjectWords.at(i).He.size(); y++)
			{
				if (this->_subjectWords.at(i).He.at(y) == subject_Name)
				{
					found = true;
				}
			}
		}
		
		if (this->_subjectWords.at(i).I == subject_Name || this->_subjectWords.at(i).You == subject_Name
			|| this->_subjectWords.at(i).We == subject_Name || this->_subjectWords.at(i).YouP == subject_Name
			|| this->_subjectWords.at(i).They == subject_Name)
		{
			found = true;
		}
	}
	return found;
}
void CollConceptSubject::deleteAll()
{
    this->_subjectWords.clear();
}
std::string CollConceptSubject::getSubject(int person)
{
	int machinePerson = person - 1;
	std::string subject;
	switch (machinePerson)
	{
	case 0:
		subject = this->_subjectWords.at(0).I;
	case 1:
		subject = this->_subjectWords.at(0).You;
	case 2:
		subject = this->_subjectWords.at(0).He.at(0);
	case 3:
		subject = this->_subjectWords.at(0).We;
	case 4:
		subject = this->_subjectWords.at(0).YouP;
	case 5:
		subject = this->_subjectWords.at(0).They;
	}
	return subject;
}
std::string CollConceptSubject::getSubjectByName(std::string subject)
{
	
	if (subject == this->_subjectWords.at(0).I)
	{
		return this->getSubject(1);
	}
	else if (subject == this->_subjectWords.at(0).You)
	{
		return this->getSubject(2);
	}
	else if (subject == this->_subjectWords.at(0).He.at(0))
	{
		return this->getSubject(3);
	}
	else if (subject == this->_subjectWords.at(0).We)
	{
		return this->getSubject(4);
	}
	else if (subject == this->_subjectWords.at(0).YouP)
	{
		return this->getSubject(5);
	}
	else if (subject == this->_subjectWords.at(0).They)
	{
		return this->getSubject(6);
	}
	
}

void CollConceptSubject::addSubject(std::string name, std::string i, std::string you, std::vector<std::string> he, std::string  we, std::string youp, std::string they)
{
	
	CONCEPT_SUBJECT subject = { name, i, you, he, we, youp, they };
	this->_subjectWords.push_back(subject);
}
