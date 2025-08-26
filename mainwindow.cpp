
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


    //Also add to reflective list
    ReflectiveStaffMember::AppointmentType refType;
    switch(type)
    {
    case StaffMember::Permanent: refType = ReflectiveStaffMemeber::Permanent; break;
    case StaffMember::PartTime: refType = RefelectiveStaffMemeber::PartTime; break;
    case StaffMammber::Contract: refType = ReflectivestaffMember::Contract; break;
    }

    reflectiveStaffList.append(new ReflectiveStaffMember(name, birthdate, refType, this));

    //Update display
    staffDisplay->append(QString("%1: %2, %3, %4")
        .arg(staffList.size())
        .arg(name)
        .arg(birthdate.toString("yyyy-MM-dd"))
                             .arg(typeCombo->currentText()));


    //clear input fields
    nameEdit->clear();
    birthdateedit->setDate(QDate::currentDate());
    typeCombo->setCurrentIndex(0);

    nameEdit->setFocus();
    updateUI();


}

void MainWindow::saveStaffToFile(){
    if(staffList.isEmpty()){
        QMessageBox::information(this, "save", "No staff members to save");
        return;
    }

    QString fileName = QFileDialog::getSaeFileName(this, "Save Staff Data", " ", "Text Files( *.txt)");

    if(fileName.isEmpty()) return;


    QFile file(fileName);
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text)){
        QMessageBox::warning(this, "Save Error", "Cannot open file for writing. ");
        return;

    }

    QTextStream out(&file);
    for(const StaffMember &staff : staffList)
    {
        out <<"name: "<<staff.getName() << "; ";
        out <<"date:  "<<staff.getBirthdate().toString("yyyy-MM-dd")<<"; ";
        out <<"type:"staff.getAppointmentTypestring()<<";\n";
    }

    file.close();
    QMessageBox::information(this, "Save", "Staff data saved successfully.");


}

void MainWindow::addAlbum()
{

    QString composer = composerEdit-text().trimmed();
    QString album = albumEdit->text().trimmed();

    if(composer.isEmpty()||album.isEmpty())
    {
        QMessageBox::warning(this, "Input Error", "Please enter both composer and album name");
        return;
    }

    double cost = costSpin->Value();
    int rating = ratingSpin->Value();

    albumModel->addAlbum(composer, album, cost, rating);


    //clear input fields

    composerEdit->clear();
    albumEdit->clear();
    costSpin->setValue(0.0);
    ratingSpin->setValue(0);

    composerEdit->setFocus();
    updateUI();
}

void MainWindow::deleteAlbum(){
    QModelIndexList selected = albumTable->selectionMode()->selectedRows();
    if(selected.isEmpty()){
        QMessageBox::information(this, "Delete", "Please select an Album to delete.");
        return;
    }

    for(const QModelIndex &index : selected){
        albumModel->removeAlbum(index.row());
    }

    updateUI();
}























