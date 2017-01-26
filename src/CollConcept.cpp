#include "CollConcept.h"
#include <algorithm>

CollConcept::CollConcept()
{

}
CollConcept::~CollConcept()
{

}
std::string CollConcept::getCurrentConceptWord()
{
	return this->_currentConceptWord;
}

std::string CollConcept::putToUpperCase(std::string s)
{
	std::transform(s.begin(), s.end(), s.begin(), ::toupper);

	return s;
}
std::string CollConcept::putToLowerCase(std::string s)
{
	std::transform(s.begin(), s.end(), s.begin(), ::tolower);

	return s;
}