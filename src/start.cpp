#include "start.h"
#include <string>
#include "bot1.h"
#include <iostream>

Start::Start()
{
	this->mainloop();
}
Start::~Start()
{

}

void Start::mainloop()
{
	std::string userSentence;
	Bot1 bot1;
	bool keepLooping = true;
	std::cout << "AI is waiting for a talk..." << std::endl;
	while (keepLooping)
	{

		userSentence = "";

		std::getline(std::cin, userSentence);

		/*
		the user sentence is in userSentence variable
		We now have to call for the ai with this sentence and that'll start its behavior
		*/
		bot1.startBehavior(userSentence);

		userSentence = "";
	}
}
