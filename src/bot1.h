#ifndef BOT1_H
#define BOT1_H

#include <string>
#include <vector>
#include "ai.h"

class Bot1 : public AI {

public:
	Bot1();
	~Bot1();
	/*
	StartBehavior get the user msg, extract each word and create a list of conceptsName
	*/
	void startBehavior(std::string);
    std::string getRealSubject(std::string subject);
    std::string getRealBe(std::string be);

protected:
private:

};
#endif
