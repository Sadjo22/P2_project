#include "xmlio.h"
#include "engineering.h"
#include "computer_engineering.h"
#include "mechanical_engineering.h"
#include "aeronautic.h"
#include "container.h"

#include <QFile>
#include <QSaveFile>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>
#include <QDebug>


XMLIO::XMLIO(QString name):filename(name){}


Container<Engineering*> XMLIO::read() const {

    // Crea una lista
    Container<Engineering*> lista;

    // Apre un file (QFile)
    QFile file(filename);

    if(!file.open(QIODevice::ReadOnly)) {
        qWarning() << "Non è stato possibile aprire il file" << file.errorString();
        return  lista;
    }

   // bool trovato=false;
    // READING FROM  XML FILE.
    QXmlStreamReader reader(&file);
    if(reader.readNextStartElement()) {
        if(reader.name() == "root"){
            while(reader.readNextStartElement()){
                if(reader.name() == "Engineering"){

                        const QXmlStreamAttributes attributes = reader.attributes();
                                            const QString type = attributes.hasAttribute("type") ? attributes.value("type").toString() : "";

                        reader.readNextStartElement();

                        const QString sname=reader.readElementText();
                        reader.readNextStartElement();

                        const QString snum=reader.readElementText();
                        reader.readNextStartElement();

                        const QString fname=reader.readElementText();
                        reader.readNextStartElement();

                        const QString rname=reader.readElementText();
                        reader.readNextStartElement();

                        const QString loc=reader.readElementText();
                        reader.readNextStartElement();

                        const QString entry=reader.readElementText();
                        reader.readNextStartElement();

                        const QString degree=reader.readElementText();
                        reader.readNextStartElement();

                        const QString math=reader.readElementText();
                        reader.readNextStartElement();

                        const QString logic=reader.readElementText();
                        reader.readNextStartElement();

                        if(type == "Informatic"){
                            lista.append(new Mechanical_Engineering(sname.toStdString(),snum.toStdString(),fname.toStdString(),rname.toStdString(),
                                                                  loc.toStdString(),entry.toInt(),degree.toStdString(),math.toInt(),logic.toInt()));
                             qDebug()<<"Letto" + sname+ rname+snum+loc+degree+logic+math+loc;
                        }

                        if(type == "Mechanics"){
                                lista.append(new Computer_Engineering(sname.toStdString(),snum.toStdString(),fname.toStdString(),rname.toStdString(),
                                                                      loc.toStdString(),entry.toInt(),degree.toStdString(),math.toInt(),logic.toInt()));
                                 qDebug()<<"Letto" + sname+ rname+snum+loc+degree+logic+math;
                        }

                        if(type == "Aeronautic"){

                            const QString laurea=reader.readElementText();
                            reader.readNextStartElement();

                            const QString laureasco=reader.readElementText();
                            reader.readNextStartElement();

                            const QString esamsco=reader.readElementText();
                            reader.readNextStartElement();


                                lista.append(new Aeronautic(sname.toStdString(),snum.toStdString(),fname.toStdString(),rname.toStdString(),
                                                                      loc.toStdString(),entry.toInt(),degree.toStdString()
                                                            ,math.toInt(),logic.toInt(),laurea.toStdString(),
                                                            laureasco.toInt(),esamsco.toInt()));

                                 qDebug()<<"Letto" + sname+fname+ rname+snum+loc+degree+logic+math+laurea+laureasco+esamsco;
                        }


                }
                else
                  reader.skipCurrentElement();

           }


       }

   }

 file.close();
 return lista;
}








void XMLIO::write(const Container<Engineering*>& list) const {
    // QSaveFile rispetto a QFile è più adatto per effettuare scritture su disco. Gestisce meglio
      // i casi di errore, garantendo che non vengano persi i dati del file in caso di errori in scrittura
    QSaveFile file(filename);

    // Apre un file. Se non si apre lancia una eccezione.
    if(!file.open(QIODevice::WriteOnly)) {
        throw std::exception();
        // NB: la cosa giusta. da fare sarebbe creare un tipo eccezione. std::exception è troppo generica.
    }

    QXmlStreamWriter writer(&file);

    writer.setAutoFormatting(true); // Per leggibilità del file XML
    writer.writeStartDocument();    // Scrive le intestazioni XML
    writer.writeComment("File di salvataggio dell'applicazione. Non modificare a mano.");

    writer.writeStartElement("root");    // <root>


   for ( auto it=list.begin();it != list.end();it++){

            writer.writeStartElement("Engineering");
             const Engineering* ptr=*it;
            string type=ptr ->getType();
            string sname =ptr->getStudentName();
            string snum = ptr->getStudentNumber();
            string fname=ptr->getFacultyName();
            string rname = ptr->getResponsibleName();
            string location = ptr->getLocation();
            string entry = to_string(ptr->has_Concorso());
            string dip,mats,log,laurea,laurea_score,esam;

           if(type == "Informatic"){
            Computer_Engineering*pt= static_cast<Computer_Engineering*>(*it);
              dip=pt->getDiploma();
              log=to_string(pt->getLogicScore());
              mats=to_string(pt->getMathScore());

           }

           if(type == "Mechanics"){
            Mechanical_Engineering *pt= static_cast<Mechanical_Engineering*>(*it);
              dip=pt->getDiploma();
              log=to_string(pt->getLogicScore());
              mats=to_string(pt->getMathScore());

           }
           if(type == "Aeronautic"){
            Aeronautic*pt= static_cast<Aeronautic*>(*it);
              dip=pt->getDiploma();
              log=to_string(pt->getLogicScore());
              mats=to_string(pt->getMathScore());
              laurea= pt->getLaureaTriennale();
              laurea_score=to_string(pt->getLaureaScore());
              esam =to_string(pt->getConcorsoScore());
           }

            writer.writeAttribute("type", QString::fromStdString(type));

            writer.writeStartElement("s_name");
            writer.writeCharacters(QString::fromStdString(sname));
            writer.writeEndElement();

            writer.writeStartElement("student_number");
            writer.writeCharacters(QString::fromStdString(snum));
            writer.writeEndElement();

            writer.writeStartElement("fac_name");
            writer.writeCharacters(QString::fromStdString(fname));
            writer.writeEndElement();


            writer.writeStartElement("head_name");
            writer.writeCharacters(QString::fromStdString(rname));
            writer.writeEndElement();

            writer.writeStartElement("location");
            writer.writeCharacters(QString::fromStdString(location));
            writer.writeEndElement();

            writer.writeStartElement("degree");
            writer.writeCharacters(QString::fromStdString(dip));
            writer.writeEndElement();

            writer.writeStartElement("entry_exam");
            writer.writeCharacters(QString::fromStdString(entry));
            writer.writeEndElement();

            writer.writeStartElement("math_score");
            writer.writeCharacters(QString::fromStdString(mats));
            writer.writeEndElement();

            writer.writeStartElement("logic_score");
            writer.writeCharacters(QString::fromStdString(log));
            writer.writeEndElement();
           if(type == "Aeronautic"){

               writer.writeStartElement("bachelor_degree");
               writer.writeCharacters(QString::fromStdString(laurea));
               writer.writeEndElement();

               writer.writeStartElement("degree_score");
               writer.writeCharacters(QString::fromStdString(laurea_score));
               writer.writeEndElement();

               writer.writeStartElement("entry_exam_score");
               writer.writeCharacters(QString::fromStdString(esam));
               writer.writeEndElement();

           }

           writer.writeEndElement();
           if(writer.hasError())
               throw std::exception();
 }

    writer.writeEndElement();
    writer.writeEndDocument();  // chiude eventuali tag lasciati aperti e aggiunge una riga vuota alla fine

    file.commit(); // Scrive il file temporaneo su disco
}

