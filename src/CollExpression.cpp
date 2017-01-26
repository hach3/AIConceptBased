#include "CollExpression.h"

CollConceptExpression::CollConceptExpression()
	: CollConcept()
{
 
}
CollConceptExpression::~CollConceptExpression()
{
    this->_expressions.clear();

}
void CollConceptExpression::Init()
{
    //Create the basics expressions
    this->addExpression("HELLO", "HELLO");
    this->addExpression("HI", "HI");
    this->addExpression("OK", ":)");
    this->addExpression("OKAY", ":)");
    this->addExpression("THANK YOU", "YOU\'RE WELCOME");
    this->addExpression("TY", "NP BRA");
}

void CollConceptExpression::deleteAll()
{
    this->_expressions.clear();
}

/*
Check if the expression value exists
*/
bool CollConceptExpression::checkIfExist(std::string value)
{
    bool found = false;
    for(unsigned int i = 0; i < this->_expressions.size(); i++)
    {
        if(this->getValueByInt(i) == value)
        {
            found = true;
        }
    }
    return found;
}
void CollConceptExpression::addExpression(std::string value, std::string answer)
{
    CONCEPT_EXPRESSION concept = { value, answer };
    this->_expressions.push_back(concept);
}
bool CollConceptExpression::deleteExpression(std::string value)
{
    bool found = false;
    for(unsigned int i = 0; i < this->_expressions.size(); i++)
    {
        if(this->getValueByInt(i) == value)
        {
            found = true;
            this->_expressions.erase(this->_expressions.begin() + i);
            continue;
        }
    }
    return found;
}

std::string CollConceptExpression::getAnswer(std::string value)
{
    bool found = false;
    std::string answer;
    for(unsigned int i = 0; i < this->_expressions.size(); i++)
    {
        if(this->getValueByInt(i) == value)
        {
            found = true;
            answer = this->getAnswerByInt(i);
        }
    }
    return answer;
}
std::string CollConceptExpression::getAnswerByInt(int i)
{
    return this->_expressions.at(i).answer;
}
std::string CollConceptExpression::getValue(std::string answer)
{
    bool found = false;
    std::string value;
    for(unsigned int i = 0; i < this->_expressions.size(); i++)
    {
        if(this->getAnswerByInt(i) == answer)
        {
            found = true;
            value = this->getValueByInt(i);
        }
    }
    return value;
}

std::string CollConceptExpression::getValueByInt(int i)
{
    return this->_expressions.at(i).value;
}
