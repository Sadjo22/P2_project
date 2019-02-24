#ifndef MODEL_H
#define MODEL_H
#include "container.h"
#include<iostream>
using namespace std;
#include <QList>

class Engineering;
template<class T> class Container;
class Model
{
private:
    Container<Engineering*>list;

public:
    Model();
    ~Model();
    void saveToFile()const;
    void loadFromFile();
    void AddFaculty(Engineering*);
    void RemoveFaculty(int);
    int CountFaculties()const;
    const Engineering* getFaculty(int)const; // return the faculty of the specify index
    void settext(const string&, const string&,const string&, const string&, const string&, int, const string&, int, int,
                 const string&, int, int);
    Engineering* searchFaculty(const string&)const;
    Container<string> Mec_StudentName()const;
    Container<string> Aero_StudentName()const;
    Container<string> Comp_StudentName()const;
    bool match(const string&)const;


};

#endif // MODEL_H
