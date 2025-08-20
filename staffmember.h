
#ifndef STAFFMEMBER_H
#define STAFFMEMBER_H


#include <QObject>
#include <QWidget>
#include <QString>
#include <QDate>


class StaffMember
{
public:
    enum AppointmentType{Permanent, PartTime, Contract};

    StaffMember();
    StaffMember(QString name, QDate birthDate,AppointmentType type);

    //Getters
    QString getName() const;
    QDate getBirthdate() const;
    AppointmentType getAppointmentType() const;
    QString getAppointmentTypeString() const;

    //Setters
    void setName(QString name);
    void setBirthdate(QDate birthdate);
    void setAppointmentType(AppointmentType type);

private:

    QString m_name;
    QDate m_birthDate;
    AppointmentType m_type;
};

#endif // STAFFMEMBER_H
