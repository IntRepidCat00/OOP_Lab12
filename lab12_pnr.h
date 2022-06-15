#ifndef LAB12_PNR_H
#define LAB12_PNR_H

#include <QMainWindow>
#include "drib_pnr.h"
#include <QMessageBox>
#include <QRegularExpression>
#include <QFile>
#include <QDateTime>

QT_BEGIN_NAMESPACE
namespace Ui { class Lab12_PNR; }
QT_END_NAMESPACE

class Lab12_PNR : public QMainWindow
{
    Q_OBJECT

public:
    Lab12_PNR(QWidget *parent = nullptr);
    ~Lab12_PNR();

private slots:
    void on_btnAdd_PNR_clicked();

    void on_btnSub_PNR_clicked();

    void on_btnMult_PNR_clicked();

    void on_btnDiv_PNR_clicked();

    void on_btnInverse_PNR_clicked();

private:
    Ui::Lab12_PNR *ui;

    void getNumbers();
    void getNum1();
    void getNum2();
    void writeException(Exception_PNR ex);
    Drib_PNR num1;
    Drib_PNR num2;
    QFile* file;
};
#endif // LAB12_PNR_H
