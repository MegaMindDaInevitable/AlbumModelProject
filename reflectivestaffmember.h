
#ifndef REFLECTIVESTAFFMEMBER_H
#define REFLECTIVESTAFFMEMBER_H


#include <QObject>
#include <QDate>
#include <QString>
#include <QWidget>


class ReflectiveStaffMember : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName)
    Q_PROPERTY(QDate birthdate READ birthdate WRITE setBirthdate)
public:
    ReflectiveStaffMember();
};

#endif // REFLECTIVESTAFFMEMBER_H
