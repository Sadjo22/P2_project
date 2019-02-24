#ifndef ENGINEERING_H
#define ENGINEERING_H

#include<iostream>
#include<string>
using namespace std;


class Engineering
{
private:
    string Student_name;
    string student_num;
    string FacultyName;
    string responsible_name;
    string Location;
    int concorso;

public:
    Engineering(const string&, const string &,const string&, const string &, const string&, int);
    virtual ~Engineering()=default;
    virtual bool access()const=0;
    virtual string Academic_Employment_Opportunities()const=0;
    virtual string Professional_Employment_Opportunities()const=0;
    virtual string Educational_Pathway()const;
    virtual string getResponsibleName()const;
    virtual string getLocation()const;
    virtual string getStudentNumber()const;
    virtual string getStudentName()const;
    virtual int has_Concorso()const;
    virtual string getType()const;
    virtual string getFacultyName()const;


};

#endif // ENGINEERING_H
