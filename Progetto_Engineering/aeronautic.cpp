#include "aeronautic.h"

Aeronautic::Aeronautic(const string& sname,const string& snum,const string& fn, const string& rname, const string& loc, int con , const string& dip, int math, int logic,const string& lt,int lts,int medC):
    Mechanical_Engineering(sname,snum,fn,rname,loc,con,dip,math,logic),Laurea_Triennale(lt),LaureaScore(lts),concorsoScore(medC){}


Aeronautic::~Aeronautic(){}


bool Aeronautic::access()const{

    if(Laurea_Triennale!="Maths" ||Laurea_Triennale!="physics" || Laurea_Triennale!="informatics" ||
            Laurea_Triennale!="Mechanical_Engineeering" )

        return false;

    return (LaureaScore>=24 && LaureaScore<=120 && concorsoScore >=12 && concorsoScore <=20);
}


string Aeronautic::Academic_Employment_Opportunities()const{

        return "Academic Employment Opportunities: Fullfil your study in Doctorate degree as researcher in aerospace o aeronautical.";
}


string Aeronautic::Professional_Employment_Opportunities()const{

    return "Professional Employment Opportunities: Work in aerospace as engineer or the aviation field.";
}


string Aeronautic::Educational_Pathway()const{

    return "Educational Pathway: The formation has a duration of 36 months.And the access is only for those students having a Degrre in mechanical Engineering.";

}


string Aeronautic::getLaureaTriennale()const{

    return Laurea_Triennale;
}


int Aeronautic::getLaureaScore()const{

    return LaureaScore;
}


int Aeronautic::getConcorsoScore()const{

    return concorsoScore;
}


string Aeronautic::getType()const{

    return "Aeronautic";
}

string Aeronautic::getStudentName()const{

    return Engineering::getStudentName();
}

string Aeronautic::getStudentNumber()const{

    return Engineering::getStudentNumber();
}

string Aeronautic::getFacultyName()const{

    return Engineering::getFacultyName();
}
