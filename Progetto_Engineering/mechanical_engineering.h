#ifndef MECHANICAL_ENGINEERING_H
#define MECHANICAL_ENGINEERING_H

#include "engineering.h"


class Mechanical_Engineering: public Engineering
{
private:
    string Diploma;  // certificate  of secondary school
    int Math_Score; // media in mathematica nel diploma di scuolasuperiore
    int Logic_score; // media in logica nel diploma di scuola superiore

public:
    Mechanical_Engineering(const string&, const string&, const string&, const string&, const string&, int, const string&, int, int);
    ~Mechanical_Engineering();
    static int maths;
    static int logic;
    virtual bool access()const override;
    virtual string Academic_Employment_Opportunities()const override;
    virtual string Professional_Employment_Opportunities()const override;
    virtual string Educational_Pathway()const;
    string getDiploma()const;
    int getMathScore()const;
    int getLogicScore()const;
    virtual string getType()const override;
};

#endif // MECHANICAL_ENGINEERING_H
