
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

    //create a central widget and layout
    QWidget *centralWidget = new QWidget(this);
    QHBoxLayout *mainLayout = new QHBoxLayout(centralWidget);

    //create a tab widget for different sections
    QTabWidget *tabWidget = new QTabWidget(centralWidget);

    //staff management tab
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

    QHBoxLayout *albumButtonLayout = new QHBoxLyout();
    albumButtonLayout->addWidget(addAlbumButton);
    albumButtonLayout->addWidget(deleteAlbumButton);
    albumLayout->addLayout(albumButtonLayout);
    albumLayout->addWidget(albumTable);

    tabWidget->addTab(albumTab, "Album Management");


    //Refletive programming tab

    QWidget *reflectiveTab = new QWidget(tabWidget);
    setupReflectiveUI();
    QVBoxLayout *reflectiveLayout = new QVBoxLayout(reflectiveTab);
    reflectiveLayout->addWidget(new QLabel("Reflective Programming"));
    reflectiveLayout->addWidget(reflectiveButton);
    reflectiveLayout->addWidget(reflectiveDisplay);

    tabWidget->addTab(reflectiveTab, "Reflective Programming");

    mainLayout->addWidget(tabWidget);
    setCentralWidget(centralWidget);

    createMenu();
    updateUI();

}

MainWindow::~MainWindow()
{
    qDeleteAll(reflectiveStaffList);
    delete albumModel;

}

void MainWindow::setupStaffUI()
{
    nameEdit = new QLineEdit(this);
    birthdateEdit = new QDateEdit(QDate::currentDate(),this);
    birthdateEdit->setCalendar(true);

    typeCombo = new QComboBox(this);
    typeCombo->addItem("Permanent", StaffMember::Permanent);
    typeCombo->addItem("Part-time", StaffMember::PartTime);
    typeCombo->addItem("Contract",  StaffMember::Contract);


    addButton = new QPushButton("Add Staff Member", this);
    saveButton = new QPushButton("Save to File", this);



    staffDisplay = new QTextEdit(this);
    staffDisplay->setReadOnly(true);

    connect(addButton, &QPushButton::clicked,this,&MainWindow::addStaffMember);
    connect(saveButton, &QPushButton::clicked,this, &MainWindow::saveStaffToFile);


}

void MainWindow::voidsetupAlbumUI()
{
    composerEdit = new QLineEdit(this);
    albumEdit = new QLineEdit(this);

    costSpin = QDoubleSpinBox(this);
    costSpin->setRange(0.0, 1000.0);
    costSpin->setDecimals(2);
    costSpin->setPrefix("R");

    ratingSpin = QSpinBox(this);
    ratingSpin->setRange(0, 100);


    addAlbumButton = new QPushButton("Add Album", this);
    deleteAlbumButton = new QPushButton("Delete Selected Album",this);

    albumTable = new QTableView(this);
    albumModel = new AlbumModel(this);
    albumTable->setModel(albumModel);

    albumTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);


    connect(addAlbumButton, &QPushButton::clisked,this, &MainWindow::addAlbum );
    connect(deleteAlbumButton, &QPushButton::clicked,this, &MainWindow::deleteAlbum);

}

void MainWindow::setupReflectiveUI()
{
    reflectiveButton = new QPushButton("Show Reflective Info", this);
    reflectiveDisplay= new QTextEdit(this);
    reflectiveDisplay->setReadOnly(true);

    connect(reflectiveButton, &QPushButton::clicked, this, &MainWindow::showReflectiveInfo);


}

void MainWindow::createMenu()
{
    QMenu *fileMenu = menuBar()->addMenu("File");
    QAction *exitAction = fileMenu->addAction("Exit");
    connect(exitAction, &QAction::triggered, this, &QMainWindow::close);


    QMenu *helpMenu = menuBar()->addMenu("Help");
    QAction *aboutAction = helpMenu->addAction("About");
    connect(aboutAction,&QAction::triggered,[](){QMessageBox::about(nullptr,"About","Album Model Application");});
}

void MainWindow::addStaffMember()()
{
    QString name = nameEdit->text().trimmed();
    if(name.isEmpty())
    {
        QMessageBox::warning(this,"Input Error", "Please Enter a name. ");
        nameEdit->setFocus();
        return;
    }

    QDate birthdate = birthdateEdit->date();
    staffMember::AppointmentType type = static_cast<StaffMemeber::AppointmentType>(
        typeCombo->currentData().toInt());

    staffList.append(staffMemeber(name, birthdate, type));
}
























