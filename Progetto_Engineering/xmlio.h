#ifndef XMLIO_H
#define XMLIO_H

#include <QString>
#include <QList>

template<class T>class Container;
class Engineering;


class XMLIO
{
private:
    QString filename;

public:
    XMLIO(QString);
    Container<Engineering*> read() const;
    void write(const Container<Engineering*>&) const;
};
#endif // XMLIO_H
