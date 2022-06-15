#include "lab12_pnr.h"
#include "ui_lab12_pnr.h"

const int STR_LEN = 10;

Lab12_PNR::Lab12_PNR(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Lab12_PNR)
{
    ui->setupUi(this);
    file = new QFile("D:\\Work\\University\\C1S2\\OOP\\Lab\\Lab12\\Lab12_PNR\\1.log");
}

Lab12_PNR::~Lab12_PNR()
{
    if(file != nullptr)
    {
        delete file;
    }
    delete ui;
}

void Lab12_PNR::writeException(Exception_PNR ex)
{
    file->open(QIODevice::WriteOnly | QIODevice::Append);
    QTextStream log(file);
    log << "[" << QDateTime::currentDateTime().toString("dd-MM-yyyy hh:mm:ss") << "]" << ex.getMessage() << "\n";
    file->flush();
    file->close();
}

void Lab12_PNR::getNumbers()
{
    int numer1, numer2, denom1, denom2;
    long long lnumer1, lnumer2, ldenom1, ldenom2;
    std::string strnumer1, strnumer2, strdenom1, strdenom2;
    QString qnumer1, qnumer2, qdenom1, qdenom2;

    strnumer1 = ui->lineEditNum1_PNR->text().toStdString();
    strnumer2 = ui->lineEditNum2_PNR->text().toStdString();
    strdenom1 = ui->lineEditDenom1_PNR->text().toStdString();
    strdenom2 = ui->lineEditDenom2_PNR->text().toStdString();

    qnumer1 = ui->lineEditNum1_PNR->text();
    qnumer2 = ui->lineEditNum2_PNR->text();
    qdenom1 = ui->lineEditDenom1_PNR->text();
    qdenom2 = ui->lineEditDenom2_PNR->text();


    bool isSym{false};
    for(size_t i{}; i < strnumer1.length(); i++)
    {
        if(isalpha(strnumer1[i]))
        {
            isSym = true;
        }
    }
    for(size_t i{}; i < strnumer2.length(); i++)
    {
        if(isalpha(strnumer2[i]))
        {
            isSym = true;
        }
    }
    for(size_t i{}; i < strdenom1.length(); i++)
    {
        if(isalpha(strdenom1[i]))
        {
            isSym = true;
        }
    }
    for(size_t i{}; i < strdenom2.length(); i++)
    {
        if(isalpha(strdenom2[i]))
        {
            isSym = true;
        }
    }

    if(isSym)
    {
        throw Exception_PNR("You entered letters instead of numbers");
    }

    if(strnumer1.length() > STR_LEN || strnumer2.length() > STR_LEN || strdenom1.length() > STR_LEN || strdenom2.length() > STR_LEN)
    {
        throw Exception_PNR("Too many numbers");
    }

    if(qnumer1.isEmpty() || qnumer2.isEmpty() || qdenom1.isEmpty() || qdenom2.isEmpty())
    {
        throw Exception_PNR("You haven't entered all data");
    }

    numer1 = ui->lineEditNum1_PNR->text().toInt();
    numer2 = ui->lineEditNum2_PNR->text().toInt();
    denom1 = ui->lineEditDenom1_PNR->text().toInt();
    denom2 = ui->lineEditDenom2_PNR->text().toInt();

    lnumer1 = ui->lineEditNum1_PNR->text().toLongLong();
    lnumer2 = ui->lineEditNum2_PNR->text().toLongLong();
    ldenom1 = ui->lineEditDenom1_PNR->text().toLongLong();
    ldenom2 = ui->lineEditDenom2_PNR->text().toLongLong();

    if(numer1 != lnumer1 || numer2 != lnumer2 || denom1 != ldenom1 || denom2 != ldenom2)
    {
        throw Exception_PNR("Number overflow");
    }

    num1.setNumerator(numer1);
    num1.setDenominator(denom1);
    num2.setNumerator(numer2);
    num2.setDenominator(denom2);
}

void Lab12_PNR::getNum1()
{
    int numer1, denom1;
    long long lnumer1, ldenom1;

    std::string strnumer1, strdenom1;
    QString qnumer1, qdenom1;

    strnumer1 = ui->lineEditNum1_PNR->text().toStdString();
    strdenom1 = ui->lineEditDenom1_PNR->text().toStdString();

    qnumer1 = ui->lineEditNum1_PNR->text();
    qdenom1 = ui->lineEditDenom1_PNR->text();


    bool isSym{false};
    for(size_t i{}; i < strnumer1.length(); i++)
    {
        if(isalpha(strnumer1[i]))
        {
            isSym = true;
        }
    }
    for(size_t i{}; i < strdenom1.length(); i++)
    {
        if(isalpha(strdenom1[i]))
        {
            isSym = true;
        }
    }

    if(isSym)
    {
        throw Exception_PNR("You entered letters instead of numbers");
    }

    if(strnumer1.length() > STR_LEN || strdenom1.length() > STR_LEN)
    {
        throw Exception_PNR("Too many numbers");
    }

    if(qnumer1.isEmpty() || qdenom1.isEmpty())
    {
        throw Exception_PNR("You haven't entered all data");
    }

    numer1 = ui->lineEditNum1_PNR->text().toInt();
    denom1 = ui->lineEditDenom1_PNR->text().toInt();

    lnumer1 = ui->lineEditNum1_PNR->text().toLongLong();
    ldenom1 = ui->lineEditDenom1_PNR->text().toLongLong();

    if(numer1 != lnumer1 || denom1 != ldenom1)
    {
        throw Exception_PNR("Number overflow");
    }

    num1.setNumerator(numer1);
    num1.setDenominator(denom1);
}

void Lab12_PNR::getNum2()
{
    int numer2, denom2;
    long long lnumer2, ldenom2;

    std::string strnumer2, strdenom2;
    QString qnumer2, qdenom2;

    strnumer2 = ui->lineEditNum2_PNR->text().toStdString();
    strdenom2 = ui->lineEditDenom2_PNR->text().toStdString();

    qnumer2 = ui->lineEditNum2_PNR->text();
    qdenom2 = ui->lineEditDenom2_PNR->text();


    bool isSym{false};
    for(size_t i{}; i < strnumer2.length(); i++)
    {
        if(isalpha(strnumer2[i]))
        {
            isSym = true;
        }
    }
    for(size_t i{}; i < strdenom2.length(); i++)
    {
        if(isalpha(strdenom2[i]))
        {
            isSym = true;
        }
    }

    if(isSym)
    {
        throw Exception_PNR("You entered letters instead of numbers");
    }

    if(strnumer2.length() > STR_LEN || strdenom2.length() > STR_LEN)
    {
        throw Exception_PNR("Too many numbers");
    }

    if(qnumer2.isEmpty() || qdenom2.isEmpty())
    {
        throw Exception_PNR("You haven't entered all data");
    }

    numer2 = ui->lineEditNum2_PNR->text().toInt();
    denom2 = ui->lineEditDenom2_PNR->text().toInt();

    lnumer2 = ui->lineEditNum2_PNR->text().toLongLong();
    ldenom2 = ui->lineEditDenom2_PNR->text().toLongLong();

    if(numer2 != lnumer2 || denom2 != ldenom2)
    {
        throw Exception_PNR("Number overflow");
    }

    num2.setNumerator(numer2);
    num2.setDenominator(denom2);
}

void Lab12_PNR::on_btnAdd_PNR_clicked()
{
    try
    {
    getNumbers();

    ui->textEdit1_PNR->setText((num1 + num2).print());
    }
    catch(Exception_PNR err)
    {
        writeException(err);
        QMessageBox messageBox;
        messageBox.critical(0,"Error", err.getMessage());
        messageBox.setFixedSize(500,200);
    }
}


void Lab12_PNR::on_btnSub_PNR_clicked()
{
    try
    {
    getNumbers();

    ui->textEdit1_PNR->setText((num1 - num2).print());
    }
    catch(Exception_PNR err)
    {
        writeException(err);
        QMessageBox messageBox;
        messageBox.critical(0,"Error", err.getMessage());
        messageBox.setFixedSize(500,200);
    }
}


void Lab12_PNR::on_btnMult_PNR_clicked()
{
    try
    {
    getNumbers();

    ui->textEdit1_PNR->setText((num1 * num2).print());
    }
    catch(Exception_PNR err)
    {
        writeException(err);
        QMessageBox messageBox;
        messageBox.critical(0,"Error", err.getMessage());
        messageBox.setFixedSize(500,200);
    }
}


void Lab12_PNR::on_btnDiv_PNR_clicked()
{
    try
    {
    getNumbers();

    ui->textEdit1_PNR->setText((num1 / num2).print());
    }
    catch(Exception_PNR err)
    {
        writeException(err);
        QMessageBox messageBox;
        messageBox.critical(0,"Error", err.getMessage());
        messageBox.setFixedSize(500,200);
    }
}

void Lab12_PNR::on_btnInverse_PNR_clicked()
{
    try
    {
        if(ui->radBtnNum1_PNR->isChecked())
        {
            getNum1();
            ui->textEdit1_PNR->setText((num1.inverse()).print());
        } else if(ui->radBtnNum2_PNR->isChecked())
        {
            getNum2();
            ui->textEdit1_PNR->setText((num2.inverse()).print());
        }
    }
    catch(Exception_PNR err)
    {
        writeException(err);
        QMessageBox messageBox;
        messageBox.critical(0,"Error", err.getMessage());
        messageBox.setFixedSize(500,200);
    }
}

