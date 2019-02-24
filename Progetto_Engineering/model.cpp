#include "model.h"
#include "xmlio.h"
#include "aeronautic.h"
#include "engineering.h"
#include "computer_engineering.h"
#include "mechanical_engineering.h"
#include <QMessageBox>
#include <regex>



#include<QtAlgorithms>

Model::Model(){}


Model::~Model(){
    qDeleteAll(list);
}

void Model::saveToFile()const {
    XMLIO xmlio("../Progetto_Engineering/images/data.xml");
    xmlio.write(list);
}

void Model::loadFromFile() {
    XMLIO xmlio("../Progetto_Engineering/images/data.xml");
    list = xmlio.read();
}


void Model::AddFaculty(Engineering* eng){

     list.append(eng);
}


void Model::RemoveFaculty(int index){

 list.removeAt(index);
}

int Model::CountFaculties()const{

    return list.getSize();
}

const Engineering* Model::getFaculty(int indice)const{

     return list.At(indice);
}

bool Model::match(const string& snum)const{
    for(auto it=list.begin(); it!= list.end();it++){
         Computer_Engineering* ptr= dynamic_cast<Computer_Engineering*>(*it);
         if(ptr){
            return ptr->getStudentNumber()== snum;
         }
         Mechanical_Engineering* pt= dynamic_cast<Mechanical_Engineering*>(*it);
         if(pt){
             return pt->getStudentNumber()== snum;
         }
         Aeronautic* aer= dynamic_cast<Aeronautic*>(*it);
         if(pt){
             return aer->getStudentNumber()== snum;
         }
    }
    return false;

}


void Model::settext(const string& sname,const string& snum,const string& fn,const string& rname, const string& loc,
                    int con , const string& dip, int math, int logic,const string& lt,int lts,int medC){

    regex b("(ENG)[0-9]{1,4}"); // REGULAR EXPRESSION TO USE (IT matches all the expression starting with ENG FOLLOW by 1 or 4 numbers between(0and 9))
    if(sname =="" || snum =="" || rname =="" || loc =="" || dip ==""){
             QMessageBox box(QMessageBox::Warning,"Filled all the fields", "*Fill out the empty field(s)", QMessageBox::Ok);
             box.exec();
   }
   else{
        if(!regex_match(snum,b)){
            QMessageBox box(QMessageBox::Warning,"Standard", "*The student Number doesn't match the standard."
                                                  "The Student Number should starts with ENG follow by one or four numbers.", QMessageBox::Ok);
            box.exec();
        }
        else{
            if(match(snum)){
                QMessageBox box(QMessageBox::Warning,"Match", "*Can't duplicate the Student Number.", QMessageBox::Ok);
                box.exec();
            }
            else{
                if(lt == "None"){
                    if( math >=14 && logic >=14){
                        if(fn=="Computer Engineering"){
                             list.append(new Computer_Engineering(sname,snum,fn,rname,loc,con,dip,math,logic));
                        }
                        else{
                            if(fn=="Mechanical Engineering")
                                list.append(new Mechanical_Engineering(sname,snum,fn,rname,loc,con,dip,math,logic));
                            else{
                                QMessageBox box(QMessageBox::Warning,"Bachelor degree", "*Can't access to this faculty without Engineering degree.", QMessageBox::Ok);
                                box.exec();
                            }
                        }

                    }
                    else{
                        if(math >=12 && logic >=12 && ( fn=="Mechanical Engineering")){
                             list.append(new Mechanical_Engineering(sname,snum,fn,rname,loc,con,dip,math,logic));
                        }
                        else{
                            QMessageBox box(QMessageBox::Warning," Mechanical and Computer Enrolment",
                               "-To enrol in Mechanical Engineering, you should have at least"
                                                                  " 12 in math exam and logic exam.\n"
                               "-To enrol in Computer Engineering, you should have at least 14 in math exam and logic exam."
                                                                  , QMessageBox::Ok);
                            box.exec();
                        }
                   }
               }
               else{
                     if(medC >= 12 && lts >= 24 && fn=="Aeronautic"){
                          list.append(new Aeronautic(sname,snum,fn,rname,loc,con,dip,math,logic,lt,lts,medC));
                     }
                     else{
                             QMessageBox box(QMessageBox::Warning,"Aeronautic Enrolment", "To enrol in Aeronautic you should have a licence with at least 24 and at least 12 at the entry exam.", QMessageBox::Ok);
                             box.exec();

                     }


              }
            }


    }


}


}

Container<string> Model::Mec_StudentName()const{

    Container<string>student;

    for(auto it=list.begin(); it!= list.end();it++){

        Mechanical_Engineering* ptr= dynamic_cast<Mechanical_Engineering*>(*it);
        if(ptr){
            student.append(ptr->getStudentName());
        }

    }

    return student;
}


Container<string> Model::Aero_StudentName()const{

    Container<string>student;

    for(auto it=list.begin(); it!= list.end();it++){

        Aeronautic* ptr= dynamic_cast<Aeronautic*>(*it);
        if(ptr){
            student.append(ptr->getStudentName());
        }

    }

    return student;
}


Container<string> Model::Comp_StudentName()const{

    Container<string>student;

    for(auto it=list.begin(); it!= list.end();it++){

        Computer_Engineering* ptr= dynamic_cast<Computer_Engineering*>(*it);
        if(ptr){
            student.append(ptr->getStudentName());
        }

    }

    return student;
}

