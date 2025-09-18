
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
    Q_PROPERTY(AppointmentType appointmentType READ appointmentType WRITE setAppointmentType)
public:
    ReflectiveStaffMember();
    enum AppointmentType {Permanent, partTime, Contract};
};

#endif // REFLECTIVESTAFFMEMBER_H
