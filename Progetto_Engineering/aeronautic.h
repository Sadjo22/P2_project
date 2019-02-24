#ifndef AERONAUTIC_H
#define AERONAUTIC_H


#include"mechanical_engineering.h"


class Aeronautic: public Mechanical_Engineering
{
private:
    string Laurea_Triennale;
    int LaureaScore;
    int concorsoScore;

public:
    Aeronautic(const string&, const string&, const string&, const string&, const string&, int, const string&, int, int, const string&, int, int);
    ~Aeronautic();
    virtual bool access()const override;
    virtual string Academic_Employment_Opportunities()const override;
    virtual string Professional_Employment_Opportunities()const override;
    virtual string Educational_Pathway()const;
    virtual string getStudentNumber()const;
    virtual string getStudentName()const;
    virtual string getFacultyName()const;
    string getLaureaTriennale()const;
    int getLaureaScore()const;
    int getConcorsoScore()const;
    virtual string getType()const override;
};

#endif // AERONAUTIC_H
