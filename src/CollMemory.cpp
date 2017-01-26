#include "CollMemory.h"
#include <algorithm>
#include <iostream>

/* Constructor */
CollMemory::CollMemory()

{

}
/* Destructor */
CollMemory::~CollMemory()
{
	this->_souvenirs.clear();
}
void CollMemory::Init()
{
    //Create the basic souvenirs
	/*
	Add a row with the real name to answer question who are you ? -> it will answer "WHO", so who are you = i am i :p
	*/
	 this->addSouvenir("CONCEPT_BE", "", "I", "", "SOMEWHERE IN THE UNIVERSE", "", "A MACHINE", "Fine", true, true);
	 this->addSouvenir("CONCEPT_BE", "", "YOU", "", "In front of your screen bich", "", "A human I guess", "", true, true);


	 this->addSouvenir("CONCEPT_BE", "CONCEPT_NAME", "I", "", "", "", "Gandalf", "", true, true);
	 this->addSouvenir("CONCEPT_BE", "CONCEPT_NAME", "YOU", "", "", "", "", "", true, true);

	 this->addSouvenir("CONCEPT_BE", "CONCEPT_CAR", "I", "", "", "", "MERCEDES", "RED", true, true);
	 this->addSouvenir("CONCEPT_BE", "CONCEPT_CAR", "YOU", "", "", "", "GARBAGE", "SHIT COLOR", true, true);


	 this->addSouvenir("CONCEPT_BE", "CONCEPT_LOVE", "I", "", "", "", "", "", true, true);
	 this->addSouvenir("CONCEPT_BE", "CONCEPT_LOVE", "", "", "", "", "very human", "something i\'ll never know, sorry", true, true);
}

void CollMemory::deleteAll()
{
    this->_souvenirs.clear();
}


/* Check if the souvenir exist by checking the verb and the name */
bool CollMemory::checkIfExist(std::string concept_verb,
                              std::string concept_name)
{
	bool found = false;
	for (int i = 0; i < this->_souvenirs.size(); i++)
	{
		if (this->_souvenirs.at(i).CONCEPT_NAME == concept_name && this->_souvenirs.at(i).CONCEPT_VERB == concept_verb)
		{
			found = true;
		}
	}
	return found;
}
bool CollMemory::checkIfWhExists(std::string concept_verb,
                                 std::string concept_name,
                                 int whPlace)
{
	bool found = false;
	for (int i = 0; i < this->_souvenirs.size(); i++)
	{
		if (this->_souvenirs.at(i).CONCEPT_NAME == concept_name 
			&& this->_souvenirs.at(i).CONCEPT_VERB == concept_verb)
		{
			switch (whPlace)
			{
			case 0:
				if (this->_souvenirs.at(i).WHO != "")
				{
					found = true;
				}
				break;
			case 1:
				if (this->_souvenirs.at(i).WHY != "")
				{
					found = true;
				}
				break;
			case 2:
				if (this->_souvenirs.at(i).WHERE != "")
				{
					found = true;
				}
				break;
			case 3:
				if (this->_souvenirs.at(i).WHEN != "")
				{
					found = true;
				}
				break;
			case 4:
				if (this->_souvenirs.at(i).WHAT != "")
				{
					found = true;
				}
				break;
			case 5:
				if (this->_souvenirs.at(i).HOW != "")
				{
					found = true;
				}
				break;
			}
		}
	}
	return found;
}


/* Return the value contained in the WH structure
For example, if my name is Tariq, the getWHValue(CONCEPT_BE, CONCEPT_NAME, WHAT) will return Tariq.

 */
std::string CollMemory::getWHValueByPos(std::string subject, std::string concept_verb,
                                   std::string concept_name,
                                   int whPlace)
{
	
	std::string theWHValue;
	for (int i = 0; i < this->_souvenirs.size(); i++)
	{
		if (this->_souvenirs.at(i).CONCEPT_NAME == concept_name
			&& this->_souvenirs.at(i).CONCEPT_VERB == concept_verb
			&& this->_souvenirs.at(i).WHO == subject)
		{
			switch (whPlace)
			{
			case 0:
				if (this->_souvenirs.at(i).WHO != "")
				{
					theWHValue = this->_souvenirs.at(i).WHO;
					
				}
				break;
			case 1:
				if (this->_souvenirs.at(i).WHY != "")
				{
					theWHValue = this->_souvenirs.at(i).WHY;
				}
				break;
			case 2:
				if (this->_souvenirs.at(i).WHERE != "")
				{
					theWHValue = this->_souvenirs.at(i).WHERE;
				}
				break;
			case 3:
				if (this->_souvenirs.at(i).WHEN != "")
				{
					theWHValue = this->_souvenirs.at(i).WHEN;
				}
				break;
			case 4:
				if (this->_souvenirs.at(i).WHAT != "")
				{
					theWHValue = this->_souvenirs.at(i).WHAT;
				}
				break;
			case 5:
				if (this->_souvenirs.at(i).HOW != "")
				{
					theWHValue = this->_souvenirs.at(i).HOW;
				}
				break;
			}
		}
	}
	return theWHValue;
}
std::string CollMemory::getWHValue(std::string subject, std::string concept_verb,
	std::string concept_name,
	std::string wh_value)
{
	wh_value = this->putToUpperCase(wh_value);
	int wh_place = 0;
	std::string theWHValue;

	if (wh_value == "WHO")
	{
		wh_place = 0;
	}
	else if (wh_value == "WHY")
	{
		wh_place = 1;
	}
	else if (wh_value == "WHERE")
	{
		wh_place = 2;
	}
	else if (wh_value == "WHEN")
	{
		wh_place = 3;
	}
	else if (wh_value == "WHAT")
	{
		wh_place = 4;
	}
	else if (wh_value == "HOW")
	{
		wh_place = 5;
	}
	theWHValue = this->getWHValueByPos(subject, concept_verb, concept_name, wh_place);
	
	return theWHValue;
}
void CollMemory::setWHValue(std::string concept_verb,
                            std::string concept_name,
                            int whPlace,
                            std::string valueToPutIn)
{
	for (int i = 0; i < this->_souvenirs.size(); i++)
	{
		if (this->_souvenirs.at(i).CONCEPT_NAME == concept_name
			&& this->_souvenirs.at(i).CONCEPT_VERB == concept_verb)
		{
			switch (whPlace)
			{
			case 0:			
				this->_souvenirs.at(i).WHY = valueToPutIn;	
				break;
			case 1:
				this->_souvenirs.at(i).WHY = valueToPutIn;
				break;
			case 2:			
				this->_souvenirs.at(i).WHERE = valueToPutIn;
				break;
			case 3:
				this->_souvenirs.at(i).WHEN = valueToPutIn;
				break;
			case 4:				
				this->_souvenirs.at(i).WHAT = valueToPutIn;
				break;
			case 5:
				this->_souvenirs.at(i).HOW = valueToPutIn;
				break;
				
			}
		}
	}
}

/*
Create a souvenir
std::string WHO;
std::string WHY;
std::string WHERE;
std::string WHEN;
std::string WHAT;
std::string HOW;
*/
void CollMemory::addSouvenir(std::string concept_name)
{
	Souvenir souvenir = { "", "", "", "", "", "", "", concept_name, false, false};
	this->_souvenirs.push_back(souvenir);
}
void CollMemory::addSouvenir(std::string concept_verb, std::string concept_name)
{
	Souvenir souvenir = { "", "", "", "", "", "", concept_verb, concept_name , false, false };
	this->_souvenirs.push_back(souvenir);
}
void CollMemory::addSouvenir(std::string concept_verb, std::string concept_name, std::string who, std::string why, std::string where, std::string when, std::string what, std::string how, bool is, bool have)
{
	Souvenir souvenir = { who, why, where, when, what, how, concept_verb, concept_name , is, have };
	this->_souvenirs.push_back(souvenir);
}

bool CollMemory::checkIs(std::string concept_name)
{
	bool is;
	for (int i = 0; i < this->_souvenirs.size(); i++)
	{
		if (this->_souvenirs.at(i).CONCEPT_NAME == concept_name)
		{
			is = this->_souvenirs.at(i).is;
		}
	}
	return is;
}
bool CollMemory::checkHave(std::string concept_name)
{
	bool have;
	for (int i = 0; i < this->_souvenirs.size(); i++)
	{
		if (this->_souvenirs.at(i).CONCEPT_NAME == concept_name)
		{
			have = this->_souvenirs.at(i).have;
		}
	}
	return have;
}


std::string CollMemory::putToUpperCase(std::string s)
{
	std::transform(s.begin(), s.end(), s.begin(), ::toupper);

	return s;
}