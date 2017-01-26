#include "bot1.h"
#include <iostream>

//#include "voce.h"
Bot1::Bot1()
{

}

Bot1::~Bot1()
{

}
/*
StartBehavior get the user msg, extract each word and create a list of conceptsName
*/
void Bot1::startBehavior(std::string userSentence)
{
    this->sentenceToSay = "";
	userSentence = this->putToUpperCase(userSentence);

	std::vector<std::string> conceptInSentence;
	//Spliting the user sentence into a vector
	conceptInSentence = this->split(userSentence);


	std::string wh;
	std::string be;
	std::string subject;
	std::string complement;


   
    /* Si ça commence par un WH*/
	if (this->checkIfQuestionWHBeSC(wh, be, subject, complement, conceptInSentence))
	{
		std::string conceptSubject;
		this->getSubjectFromVectors(conceptSubject, conceptInSentence, subject);
		
		std::string conceptComplement;
		this->getComplementFromVectors(conceptComplement, conceptInSentence, complement);

		std::string whValueInMemory;		
		wh = this->putToUpperCase(wh);
		whValueInMemory = this->_souvenirs.getWHValue(conceptSubject, "CONCEPT_BE", conceptComplement, wh);

		std::string subjectAnswer;
		subjectAnswer = this->getRealSubject(subject);
		std::string verbAnswer;
		verbAnswer = this->getRealBe(be);

		std::vector<std::string> sentenceToBuild;
		sentenceToBuild.push_back(subjectAnswer);
		sentenceToBuild.push_back(this->putToLowerCase(complement));
		sentenceToBuild.push_back(verbAnswer);
		sentenceToBuild.push_back(whValueInMemory);

		this->buildAnswerWH(whValueInMemory, sentenceToBuild);
	}
	/*Si c'est Who are you / how are you (WH BE Subject)*/
	else if (this->checkIfQuestionWHBeS(wh, be, subject, conceptInSentence))
	{
		std::string conceptSubject;
		this->getSubjectFromVectors(conceptSubject, conceptInSentence, subject);	

		std::string whValueInMemory;
		wh = this->putToUpperCase(wh);
		whValueInMemory = this->_souvenirs.getWHValue(conceptSubject, "CONCEPT_BE", "", wh);

		std::string subjectAnswer;
		subjectAnswer = this->getRealSubject(subject);
		std::string verbAnswer;
		verbAnswer = this->getRealBe(be);
		std::vector<std::string> sentenceToBuild;
		sentenceToBuild.push_back(subjectAnswer);
		sentenceToBuild.push_back(verbAnswer);
		sentenceToBuild.push_back(whValueInMemory);

		this->buildAnswerWH(whValueInMemory, sentenceToBuild);
	
	}
	/* WH S C : what is love ?*/
	else if (this->checkIfQuestionWHBeC(wh, be, complement, conceptInSentence))
	{
		std::string conceptComplement;
		this->getComplementFromVectors(conceptComplement, conceptInSentence, complement);	

		std::string whValueInMemory;
		conceptComplement = this->putToUpperCase(conceptComplement);
		wh = this->putToUpperCase(wh);
		whValueInMemory = this->_souvenirs.getWHValue("", "CONCEPT_BE", conceptComplement, wh);

		std::string verbAnswer;
		verbAnswer = this->getRealBe(be);

		std::vector<std::string> sentenceToBuild;
		sentenceToBuild.push_back(complement);
		sentenceToBuild.push_back(verbAnswer);
		sentenceToBuild.push_back(whValueInMemory);

		this->buildAnswerWH(whValueInMemory, sentenceToBuild);
	

	}
	/* Si c'est une expression */
	else if (this->_Expression.checkIfExist(userSentence))
	{
		this->sentenceToSay = this->_Expression.getAnswer(userSentence);
	}

	
	this->saySomething();
}

std::string Bot1::getRealSubject(std::string subject)

{
    std::string subjectAnswer = subject;
    if (subject == "I")
    {
        subjectAnswer = "You";
    }
    else if (subject == "YOU")
    {
        subjectAnswer = "I";
    }
    if (subject == "YOUR")
    {
        subjectAnswer = "My";
    }
    else if (subject == "MY")
    {
        subjectAnswer = "Your";
    }
    return subjectAnswer;

}
std::string Bot1::getRealBe(std::string be)
{
    std::string verbAnswer = be;
    if (be == "ARE")
    {
        verbAnswer = "am";
    }
    else if (be == "AM")
    {
        verbAnswer = "are";
    }
    else {
        verbAnswer = be;
    }
    return verbAnswer;

}
