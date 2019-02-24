#include "mechanical_engineering.h"

Mechanical_Engineering::Mechanical_Engineering(const string& sname, const string& snum,const string& fn,const string& rname, const string& loc, int con , const string& dip, int math, int logic):
    Engineering(sname,snum,fn,rname, loc, con),Diploma(dip),Math_Score(math),Logic_score(logic){}


Mechanical_Engineering::~Mechanical_Engineering(){}

int Mechanical_Engineering::maths=12;
int Mechanical_Engineering::logic=12;


bool Mechanical_Engineering::access()const{

    if(Math_Score < maths || Logic_score <logic){
        return false;
    }
    return (Diploma == "Certificate of secondary school" || Diploma=="Baccalaureat");

}


string Mechanical_Engineering::Academic_Employment_Opportunities()const{

    return "Academic Employment Opportunities: Continuation of studies in the second cycle of master's degree aeronautic,electronic and so one.";
}


string Mechanical_Engineering::Professional_Employment_Opportunities()const{

    return "Professional Employment Opportunities:  work in Automobile companies, industies.";

}


string Mechanical_Engineering::Educational_Pathway()const{

     return "Educational Pathway: The Formation in Mechanical Engineering has a duration of 3 years subdivided into 6 semesters. "
           "The First session start in settember and end in february with exams of the session."
           "The second session start in settember and end in june with final exams.";
}


string Mechanical_Engineering::getDiploma()const{

    return Diploma;
}


int Mechanical_Engineering::getMathScore()const{

    return Math_Score;
}


int Mechanical_Engineering::getLogicScore()const{

    return Logic_score;
}


string Mechanical_Engineering::getType()const{

    return "Mechanics";
}






