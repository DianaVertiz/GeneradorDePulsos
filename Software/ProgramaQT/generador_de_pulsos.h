#ifndef GENERADOR_DE_PULSOS_H
#define GENERADOR_DE_PULSOS_H

#include <QMainWindow>
#include<QMessageBox>
#include<QtGui>
#include<string>
#include<iostream>

namespace Ui {
class Generador_de_pulsos;
}

class Generador_de_pulsos : public QMainWindow
{
    Q_OBJECT

public:
    explicit Generador_de_pulsos(QWidget *parent = 0);
    ~Generador_de_pulsos();

private slots:
    void on_NPulsos();

    void on_Tup();

    void on_Periodo();

    void on_ValueUp();

    void ConfPulsos();

    void ConfTup();

    void ConfPeriodo();

    void ConfValUp();

    void on_MandarPulsos_clicked();

    void on_ValoresDefault_clicked();

    void on_Configurar_clicked();

    void on_toolButton_clicked();

    void on_toolButton_2_clicked();

    void on_toolButton_23_clicked();

    void on_toolButton_24_clicked();

    void on_toolButton_3_clicked();

    void on_toolButton_4_clicked();

    void on_toolButton_5_clicked();

    void on_toolButton_6_clicked();

    void on_toolButton_21_clicked();

    void on_toolButton_22_clicked();

    void on_toolButton_7_clicked();

    void on_toolButton_9_clicked();

    void on_toolButton_8_clicked();

    void on_toolButton_10_clicked();

    void on_toolButton_19_clicked();

    void on_toolButton_20_clicked();

    void on_toolButton_12_clicked();

    void on_toolButton_14_clicked();

    void on_toolButton_17_clicked();

    void on_toolButton_18_clicked();


    void on_radioButton_clicked();

private:
    Ui::Generador_de_pulsos *ui;
};

#endif // GENERADOR_DE_PULSOS_H
