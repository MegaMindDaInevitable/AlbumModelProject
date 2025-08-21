
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>
#include "staffmember.h"

//forward declarations

class QLineEdit;
class QDateEdit;
class QComboBox;
class QPushButton;
class QTextEdit;
class QTableView;
class QLabel;
class QDoubleSpinBox;
class QSpinBox;
class QTabWidget;


class MainWindow : public QMainWindow

{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void addStaffMember();
    void saveStaffToFile();
    void addAlbum();
    void deleteAlbum();
    void showReflectiveInfo();
    void updateUI();

private:
    //Staff management UI
    QLineEdit *nameEdit;
    QDateEdit *birthdateEdit;
    QComboBox *typeCombo;
    QPushButton *addButton;
    QPushButton *saveButton;
    QTextEdit *staffDisplay;

    //Album management UI

    QLineEdit *composerEdit;
    QLineEdit *albumEdit;
    QDoubleSpinBox *costSpin;
    QSpinBox *ratingSpin;
    QPushButton *addAlbumButton;
    QPushButton *deleteAlbumButton;
    QTableView *albumTable;


    //refelective programming UI
    QPushButton *reflectiveButton;
    QTextEdit *reflectiveDisplay;


    //Data Storage

    QList<StaffMember> staffList;
    AlbumModel *albumModel;
    QList<ReflectiveStaffMember*> reflectiveStaffList;

    void setupStaffUI();
    voidsetupAlbumUI();
    void setupReflectiveUI();
    void createMenu();





};

#endif // MAINWINDOW_H
