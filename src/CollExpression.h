#ifndef COLLCONCEPTEXPRESSION_H
#define COLLCONCEPTEXPRESSION_H

#include "CollConcept.h"

class CollConceptExpression : public CollConcept {
public:
    CollConceptExpression();
    ~CollConceptExpression();
    void Init();
    /* Check if the wh exists by checking the name in the whwords vector */
    bool checkIfExist(std::string value);

    void addExpression(std::string value, std::string answer);
    bool deleteExpression(std::string value);

    std::string getAnswer(std::string value);

    std::string getValue(std::string answer);
    std::string getValueByInt(int i);
    std::string getAnswerByInt(int i);

    void deleteAll();
protected:
private:
    std::vector<CONCEPT_EXPRESSION> _expressions;

};


#endif // COLLCONCEPTEXPRESSION_H
