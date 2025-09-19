
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
    Q_ENUM(Appointment)
    ReflectiveStaffMember(Qbjecct *parent = nullptr);
    ReflectiveStaffMember(QString name, QDate birthdate, AppointmentType type, QObject *parent = nullptr);

private:
    //private getters and setters
    QString name() const;
    void seName(const QString &name);
    QDate birthdate() const;
    void setBirthdate(const QDate &birthdate);
    void AppointmentType(appointmentType type);

    QString m_name;
    QDate m_birthdate;
    AppointmentType m_type;

};


#endif // REFLECTIVESTAFFMEMBER_H
