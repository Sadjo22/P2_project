#include "computer_engineering.h"

Computer_Engineering::Computer_Engineering(const string& sname, const string& snum, const string& fn, const string& rname, const string& loc, int con, const string& deg, int ms, int is):
    Engineering(sname,snum,fn,rname,loc,con),Degree(deg),mathScore(ms),logicScore(is){}



Computer_Engineering::~Computer_Engineering(){}

int Computer_Engineering::mathematics=14;
int Computer_Engineering::logics=14;


bool Computer_Engineering::access()const{

    if(Degree != "Baccalaureat" || Degree != "Certificate of secondary school")
        return false;
    return (mathScore >=mathematics  &&  logicScore >= logics);
}


string Computer_Engineering::Academic_Employment_Opportunities()const{

    return "Academic Employment Opportunities: At the end of the formation,the student has the opportunity to fullfil his study in master degree .";

}


string Computer_Engineering::Professional_Employment_Opportunities()const{

    return "Professional Employment Opportunities: At the end of the formation,the student will be able to work in any informatic sector.";

}


string Computer_Engineering::Educational_Pathway()const{


    return "Educational Pathway: The Formation in Computer Engineering has a duration of 3 years subdivided into 6 semesters. "
          "The First session start in settember and end in february with exams of the session."
          "The second session start in settember and end in june with final exams.";
}


string Computer_Engineering:: getDiploma()const{

    return Degree;
}


int Computer_Engineering::getMathScore()const{

    return mathScore;
}


int Computer_Engineering::getLogicScore()const{

    return logicScore;
}


string Computer_Engineering::getType()const{

    return "Informatic";
}
