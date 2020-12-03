#include "login.h"
#include "ui_login.h"
#include <QMessageBox>
#include <QPixmap>

//making some changes to login
Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}


//Sign in button clicked , username and password check
void Login::on_pushButton_clicked()
{
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();

    QString uppercaseUsername;
    uppercaseUsername = username.toUpper();

    if(uppercaseUsername == "A" && password == "A")
    {
        QMessageBox::information(this, "Login", "Username and password is correct");
        hide();
        MainWindow* mainwindow = new MainWindow(this);
        mainwindow->show();//since valid usernam and password we can show the main window
        mainwindow->hide();
    }
    else
    {
        QMessageBox::warning(this,"Login", "Username and password is not correct");
    }
}
