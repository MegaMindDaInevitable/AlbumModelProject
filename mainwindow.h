
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
    QDateEdit *nirthdateEdit;
    QComboBox *typeCombo;
    QPushButton *addButton;
    QPushButton saveButton;
    QTextEdit *staffDisplay;

    //Album management UI

    QLineEdit *composerEdit;
    QLineEdit *albumEdit;
    QDoubleSpinBox *costSpin;
    QSpinBox *ratingSpin;
    QPushButton *addAlbumButton;
    QPushButton *deleteAlbumButton;


    //refelective programming UI






};

#endif // MAINWINDOW_H
