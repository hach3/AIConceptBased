#include "CollConceptSubjectChild.h"

CollConceptSubjectChild::CollConceptSubjectChild()
	: CollConcept()
{

}
CollConceptSubjectChild::~CollConceptSubjectChild()
{
	this->_subjectChildWords.clear();
}

void CollConceptSubjectChild::Init()
{
	std::vector<std::string> heValues;
	heValues.push_back("HIS");
	heValues.push_back("HER");
	heValues.push_back("ITS");
	this->addSubject("CONCEPT_SUBJECT", "CONCEPT_POSSESSION_PRONOM", "MY", "YOUR", heValues, "OUR", "YOURS", "THEIR");
}

/* Check if the wh exists by checking the name in the whwords vector */
bool CollConceptSubjectChild::checkIfExist(std::string subjectChild_Name)
{
	bool found = false;
	for (unsigned int i = 0; i < this->_subjectChildWords.size(); i++)
	{
		if (i == 2)
		{
			for (int y = 0; y < this->_subjectChildWords.at(i).He.size(); y++)
			{
				if (this->_subjectChildWords.at(i).He.at(y) == subjectChild_Name)
				{
					found = true;
				}
			}
		}

		if (this->_subjectChildWords.at(i).I == subjectChild_Name || this->_subjectChildWords.at(i).You == subjectChild_Name
			|| this->_subjectChildWords.at(i).We == subjectChild_Name || this->_subjectChildWords.at(i).YouP == subjectChild_Name
			|| this->_subjectChildWords.at(i).They == subjectChild_Name)
		{
			found = true;
		}
	}
	return found;
}

bool CollConceptSubjectChild::checkIfExistInVector(std::vector<std::string> userSentence)
{
	bool found = false;
	for (int a = 0; a < userSentence.size(); a++)
	{
		for (unsigned int i = 0; i < this->_subjectChildWords.size(); i++)
		{
			if (i == 2)
			{
				for (int y = 0; y < this->_subjectChildWords.at(i).He.size(); y++)
				{
					if (this->_subjectChildWords.at(i).He.at(y) == userSentence.at(a))
					{
						found = true;
						this->_currentConceptWord = userSentence.at(a);
					}
				}
			}

			if (this->_subjectChildWords.at(i).I == userSentence.at(a) || this->_subjectChildWords.at(i).You == userSentence.at(a)
				|| this->_subjectChildWords.at(i).We == userSentence.at(a) || this->_subjectChildWords.at(i).YouP == userSentence.at(a)
				|| this->_subjectChildWords.at(i).They == userSentence.at(a))
			{
				found = true;
				this->_currentConceptWord = userSentence.at(a);
			}
		}
		
	}
	return found;
}


bool CollConceptSubjectChild::checkIfExistInVector(std::string &save, std::vector<std::string> userSentence)
{
	bool found = false;
	for (int a = 0; a < userSentence.size(); a++)
	{
		for (unsigned int i = 0; i < this->_subjectChildWords.size(); i++)
		{
			if (i == 2)
			{
				for (int y = 0; y < this->_subjectChildWords.at(i).He.size(); y++)
				{
					if (this->_subjectChildWords.at(i).He.at(y) == userSentence.at(a))
					{
						found = true;
						save = this->putToUpperCase(userSentence.at(a));
					}
				}
			}

			if (this->_subjectChildWords.at(i).I == userSentence.at(a) || this->_subjectChildWords.at(i).You == userSentence.at(a)
				|| this->_subjectChildWords.at(i).We == userSentence.at(a) || this->_subjectChildWords.at(i).YouP == userSentence.at(a)
				|| this->_subjectChildWords.at(i).They == userSentence.at(a))
			{
				found = true;
				save = this->putToUpperCase(userSentence.at(a));
			}
		}

	}
	return found;
}



void CollConceptSubjectChild::deleteAll()
{
    this->_subjectChildWords.clear();
}

std::string CollConceptSubjectChild::getSubjectChild(std::string name,
                                                     int person)
{
	int machinePerson = person - 1;
	std::string subject;
	for (int i = 0; i < this->_subjectChildWords.size(); i++)
	{
		if (this->_subjectChildWords.at(i).name == name)
		{
			switch (machinePerson)
			{
			case 0:
				subject = this->_subjectChildWords.at(i).I;
			case 1:
				subject = this->_subjectChildWords.at(i).You;
			case 2:
				subject = this->_subjectChildWords.at(i).He.at(0);
			case 3:
				subject = this->_subjectChildWords.at(i).We;
			case 4:
				subject = this->_subjectChildWords.at(i).YouP;
			case 5:
				subject = this->_subjectChildWords.at(i).They;
			}
		}
	}
	
	return subject;
}
std::string CollConceptSubjectChild::getSubjectForMemory(std::string subject)
{
	//suppose the return I, you, etc
	for (int i = 0; i < this->_subjectChildWords.size(); i++)
	{
		//Si le sujet est compris dans la structure
		if (this->_subjectChildWords.at(i).I == subject)
		{
			i = this->_subjectChildWords.size();
			return "YOU";
		}
		else if (this->_subjectChildWords.at(i).You == subject)
		{
			i = this->_subjectChildWords.size();
			return "I";
		}
		else if (this->_subjectChildWords.at(i).He.at(0) == subject)
		{
			i = this->_subjectChildWords.size();
			return "HE";
		}
		else if (this->_subjectChildWords.at(i).We == subject)
		{
			i = this->_subjectChildWords.size();
			return "WE";
		}
		else if (this->_subjectChildWords.at(i).YouP == subject)
		{
			i = this->_subjectChildWords.size();
			return "YOUP";
		}
		else if (this->_subjectChildWords.at(i).They == subject)
		{
			i = this->_subjectChildWords.size();
			return "THEY";
		}
	
	}
}
void CollConceptSubjectChild::addSubject(std::string parent, std::string name, std::string i, std::string you, std::vector<std::string> he, std::string  we, std::string youp, std::string they)
{

	CONCEPT_SUBJECT_CHILD subjectChild = { parent, name, i, you, he, we, youp, they };
	this->_subjectChildWords.push_back(subjectChild);
}