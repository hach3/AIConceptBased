#ifndef COLLMEMORY_H
#define COLLMEMORY_H

#include <string>
#include <vector>
#include "memory.h"


class CollMemory {
public:
    /* Constructor */
    CollMemory();

    /* Destructor */
    ~CollMemory();

    void Init();

    /* Check if the souvenir exists by checking the verb and the name */
    bool checkIfExist(std::string concept_verb, std::string concept_name);
    bool checkIfWhExists(std::string concept_verb, std::string concept_name, int whPlace);

    void deleteAll();
    /* Return the value contained in the WH structure
    For example, if my name is Tariq, the getWHValue(CONCEPT_BE, CONCEPT_NAME, WHAT) will return Tariq.

     */
	std::string getWHValue(std::string subject, std::string concept_verb, std::string concept_name, std::string wh_value);
    std::string getWHValueByPos(std::string subject, std::string concept_verb, std::string concept_name, int whPlace);
    void setWHValue(std::string concept_verb, std::string concept_name, int whPlace, std::string valueToPutIn);

    /*
    Create a souvenir
    std::string WHO;
    std::string WHY;
    std::string WHERE;
    std::string WHEN;
    std::string WHAT;
    std::string HOW;
    */
    void addSouvenir(std::string concept_name);
    void addSouvenir(std::string concept_verb, std::string concept_name);
    void addSouvenir(std::string concept_verb, std::string concept_name, std::string who, std::string why, std::string where, std::string when, std::string what, std::string how, bool is, bool have);


    bool checkIs(std::string concept_name);
    bool checkHave(std::string concept_name);

	std::string putToUpperCase(std::string s);
protected:
private:
    /* will save every souvenirs in this vector */
    std::vector<Souvenir> _souvenirs;
};
#endif // COLLMEMORY_H
