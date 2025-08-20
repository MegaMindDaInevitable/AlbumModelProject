
#include "mainwindow.h"

#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QLineEdit>
#include <QDate>
#include <QDateEdit>
#include <QComboBox>
#include <QPushButton>
#include <QTableView>
#include <QHeaderView>
#include <QStandardItemModel>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QMetaProperty>
#include <QMetaEnum>
#include <QVariant>
#include <QLabel>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QGroupBox>
#include <QTextEdit>
#include <QFileDialog>
#include <QProgressBar>
#include <QStyle>
#include <QMenu>
#include <QMenuBar>
#include <QTabWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("Album Model");
    setMinimumSize(1000,700);

    //create a tab widget for different sections
    QTabWidget *staffTab = new QWidget(tabWidget);
    setupStaffUI();
    QVBoxLayout  *staffLayout = new QVBoxLayout(staffTab);
    staffLayout->addWidget(new QLabel("Staff Management"));


    QFormLayour *formLayout = new QFormLayout();
    formLayout->addRow("Name: ",nameEdit);
    formLayout->addRow("Birth Date: ",birthdateEdit);
    formLayout->addRow("Type: ",typeCombo);

    staffLayout->addLayout(formLayout);
    staffLayout->addWidget(addButton);
    staffLayout->addWidget(saveButton);
    staffLayout->addWidget(new QLabel("Staff List"));
    staffLayout->addWidget(staffDisplay);


    tabWidget->addTab(staffTab, "Staff Management");

    //album Management tab

    QWidget *albumTab = new QWidget(tabWidget);
    setupAlbumUI();

    QVBoxLayout *albumLayout = new QVBoxLayout(albumTab);
    albumLayout->addWidget(new QLabel("Album Management"));

    QFormLayout *albumFormLayout = new QFormLayout();
    albumFormLayout->addRow("Composer", composerEdit);
    albumFormLayout->addRow("Album: ",albumEdit);
    albumFormLayout->addRow("Cost", costSpin);
    albumFormLayout->addRow("Rating: ", ratingSpin);
    albumLayout->addLayout(albumFormLayout);

}

MainWindow::~MainWindow()
{
}


