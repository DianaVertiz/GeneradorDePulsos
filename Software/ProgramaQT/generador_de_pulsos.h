#ifndef GENERADOR_DE_PULSOS_H
#define GENERADOR_DE_PULSOS_H

#include <QMainWindow>
#include <QThread>
#include<QMessageBox>
#include<QtGui>
#include<string>
#include<iostream>
#include "worker.h"

namespace Ui {
class Generador_de_pulsos;
}

class Generador_de_pulsos : public QMainWindow
{
    Q_OBJECT
    QThread cThread;

public:
    explicit Generador_de_pulsos(QWidget *parent = 0);
    ~Generador_de_pulsos();


private:



    Ui::Generador_de_pulsos *ui;

    int flagVoI=1; //1 en modo corriente
    int flagPoN=1; //1 pulsos positivos
    //flags de recepción de datos desde edu-ciaa
    //si flag=1 recibo desde educiaa
    int flag1=0; //VoI
    int flag2=0; //PoN
    int flagN=0;
    int flagV=0;
    int flagT=0;
    int flagP=0;

private slots:


    void ConfInicio();

    void on_NPulsos();

    void on_Tup();

    void on_Periodo();

    void on_ValueUp();

    void ConfPulsos();

    void ConfTup();

    void ConfPeriodo();

    void ConfValUp();

    void ConfValUp_tension();

    void on_MandarPulsos_clicked();

    void on_ValoresDefault_clicked();

    void on_Stop_clicked();

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



    void on_SalidaVoI_highlighted(const QString &arg1);

    void on_SalidaPoN_highlighted(const QString &arg1);

    void configurarVoI();

    void configurarPoN();

    void on_ValueN_valueChanged(int arg1);

    void on_doubleSpinBox_valueChanged(double arg1);

    void on_ValueT_valueChanged(int arg1);

    void on_ValueP_valueChanged(int arg1);

    //void on_radioButton_2_clicked();

    //void recibir_comVirtual();

    void ModificarDatos(QStringList);

    void messageWarning(QString title,QString mensaje);

    void namePort();
    void namePort_2();

    void messageInfo(QString title, QString mensaje);

    void animate_click();
    void animate_click_2();

signals:

    void openPort();
    void nomPort(QString nameport);
    void nomPort_2(QString nameport);
    void send_char(char c);
    void send_byte(QByteArray outbyte);
    void wait_written();
};

#endif // GENERADOR_DE_PULSOS_H
