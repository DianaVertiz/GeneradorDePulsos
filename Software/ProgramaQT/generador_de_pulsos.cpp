#include "generador_de_pulsos.h"
#include "ui_generador_de_pulsos.h"
#include "worker.h"
#include<QtSerialPort/QSerialPort>
#include<QtSerialPort/QSerialPortInfo>
#include<QtMath>
#include <QThread>


Generador_de_pulsos::Generador_de_pulsos(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Generador_de_pulsos)
{
    ui->setupUi(this);
    worker *mworker=new worker;
    foreach (QSerialPortInfo port, QSerialPortInfo::availablePorts())
    {
    ui->ListaPuertos->addItem(port.portName());
    ui->ListaPuertos_2->addItem(port.portName());
    }

    mworker->moveToThread(&cThread);

    connect(ui->radioButton,SIGNAL(clicked()),this, SLOT(namePort()));
    connect(ui->radioButton_2,SIGNAL(clicked()),this,SLOT(namePort_2()));
    connect(this,SIGNAL(nomPort(QString)), mworker, SLOT(initPort(QString)));
    connect(this,SIGNAL(nomPort_2(QString)), mworker, SLOT(initPort_2(QString)));
    connect(mworker,SIGNAL(mensajeError(QString,QString)),this,SLOT(messageWarning(QString,QString)));
    connect(mworker,SIGNAL(mensajeOK(QString, QString)),this,SLOT(messageInfo(QString,QString)));
    connect(mworker, SIGNAL(initPortOK()), this, SLOT(ConfInicio()));
    connect(mworker, SIGNAL(initPortNotOK()), this, SLOT(animate_click()));
    connect(mworker, SIGNAL(initPort2NotOK()), this, SLOT(animate_click_2()));
    connect(this,SIGNAL(send_char(char)), mworker, SLOT(envia_char(char)));
    connect(this,SIGNAL(send_byte(QByteArray)), mworker, SLOT(envia_byte(QByteArray)));
    connect(this,SIGNAL(wait_written()), mworker, SLOT(wait_for_write()));
    connect(mworker, SIGNAL(datosCargados(QStringList)), this, SLOT(ModificarDatos(QStringList)));

    cThread.start();

}

Generador_de_pulsos::~Generador_de_pulsos()
{
    cThread.quit();
    cThread.wait();
    delete ui;
}

void Generador_de_pulsos::messageWarning(QString title, QString mensaje)
{
     QMessageBox::warning(this,title, mensaje);
}

void Generador_de_pulsos::namePort()
{
    QString nameport;
    nameport=ui->ListaPuertos->currentText();
    emit nomPort(nameport);
}

void Generador_de_pulsos::namePort_2()
{
    QString nameport;
    nameport=ui->ListaPuertos_2->currentText();
    emit nomPort_2(nameport);
}

void Generador_de_pulsos::messageInfo(QString title, QString mensaje)
{
    QMessageBox::information(this,title, mensaje);
}

void Generador_de_pulsos::animate_click()
{
    ui->radioButton->animateClick(200);

}

void Generador_de_pulsos::animate_click_2()
{
    ui->radioButton_2->animateClick(200);
}


void Generador_de_pulsos::ConfInicio()
{
   char letra;
   letra = 'x';
   emit send_char(letra);

       configurarVoI();
       configurarPoN();
       on_NPulsos();
       ConfPulsos();
       on_ValueUp();

      if(flagVoI==1)
      {
           ConfValUp();
      }
      if(flagVoI==0)
      {
           ConfValUp_tension();
      }

      on_Tup();
      ConfTup();
      on_Periodo();
      ConfPeriodo();


}


void Generador_de_pulsos::ModificarDatos(QStringList buffer)
{
    qreal a=0;
    int b=0;

    //Número de pulsos
    if(ui->ValueN->value()!= (buffer[0]).toInt())
    {
        flagN=1;
        ui->ValueN->setValue((buffer[0]).toInt());

    }

    //Amplitud de pulsos

    a= 100*((buffer[1]).toInt()) + ((buffer[2]).toInt());

    if(flagVoI != (buffer[7]).toInt())
    {  //cambió el valor del flagVoI

        flag1=1;

        if((buffer[7]).toInt() == 1)
        {
            flagVoI=1;
            ui->SalidaVoI->setCurrentIndex(0);
            ui->doubleSpinBox->setSuffix(" mA");
             b= qFloor((31*a)/1000);
        }
        if((buffer[7]).toInt() == 0)
        {
            flagVoI=0;
            ui->SalidaVoI->setCurrentIndex(1);
            ui->doubleSpinBox->setSuffix(" V");
            b= qFloor((62*a)/1000);
        }

    }
    else
    {
        if((buffer[7]).toInt() == 1)
        {
            flagVoI=1;
            ui->SalidaVoI->setCurrentIndex(0);
            ui->doubleSpinBox->setSuffix(" mA");
             b= qFloor((31*a)/1000);
        }
        if((buffer[7]).toInt() == 0)
        {
            flagVoI=0;
            ui->SalidaVoI->setCurrentIndex(1);
            ui->doubleSpinBox->setSuffix(" V");
            b= qFloor((62*a)/1000);
        }
    }

    if(ui->doubleSpinBox->value() != b)
    {
        flagV=1;
        ui->doubleSpinBox->setValue(b);
    }


    if(flagPoN != (buffer[8]).toInt())
    {   //cambió el valor del flagPoN

        flag2=1;

        if((buffer[8]).toInt() == 1)
        {
            flagPoN=1;
            ui->SalidaPoN->setCurrentIndex(0);
            ui->doubleSpinBox->setPrefix("");
        }
        if((buffer[8]).toInt() == 0)
        {
            flagPoN=0;
            ui->SalidaPoN->setCurrentIndex(1);
            ui->doubleSpinBox->setPrefix("-");
        }

    }
    else
    {
        if((buffer[8]).toInt() == 1)
        {
            flagPoN=1;
            ui->SalidaPoN->setCurrentIndex(0);
            ui->doubleSpinBox->setPrefix("");
        }
        if((buffer[8]).toInt() == 0)
        {
            flagPoN=0;
            ui->SalidaPoN->setCurrentIndex(1);
            ui->doubleSpinBox->setPrefix("-");
        }

    }



    int c,d;
    c = 100*((buffer[3]).toInt()) + ((buffer[4]).toInt());

    if(ui->ValueT->value() != c)
    {
    flagT=1;
    ui->ValueT->setValue(c);
    }


    d= 100*((buffer[5]).toInt()) + ((buffer[6]).toInt());

    if(ui->ValueP->value() != d)
    {
     flagP=1;
     ui->ValueP->setValue(d);
    }

}



void Generador_de_pulsos::on_NPulsos()
{
    char letra;
    letra = 'n';
    emit send_char(letra);
}

void Generador_de_pulsos::on_Tup()
{
    char letra;
    letra = 't';
    emit send_char(letra);
}

void Generador_de_pulsos::on_Periodo()
{
    char letra;
    letra = 'p';
    emit send_char(letra);
}

void Generador_de_pulsos::on_ValueUp()
{
    char letra;
    letra = 'v';
    emit send_char(letra);
}

void Generador_de_pulsos::ConfPulsos()
{
    int value;
    value = ui->ValueN->value();
    QByteArray outbyte;
    char x = (char)value;
    outbyte.append(x); //agrega el caracter al arreglo outbyte

    qDebug()<<"r: "<<QString::fromStdString(outbyte.toStdString());
    //envía el valor configurado
    //Serial->write(outbyte);
    emit send_byte(outbyte);
    //Serial->waitForBytesWritten(10);
    emit wait_written();
}

void Generador_de_pulsos::ConfTup()
{
    int value;
    int a,b;
    char x,y;
    QByteArray outbyte1,outbyte2;
    value = ui->ValueT->value();
    a=int(value/100);
    b=int(value%100);
    x = (char)a;
    y = (char)b;
    outbyte1.append(x); //agrega el caracter al arreglo outbyte
    outbyte2.append(y);
    qDebug()<<"r: "<<QString::fromStdString(outbyte1.toStdString());
    qDebug()<<"r: "<<QString::fromStdString(outbyte2.toStdString());
    emit send_byte(outbyte1);
    emit wait_written();
    emit send_byte(outbyte2);
    emit wait_written();

}

void Generador_de_pulsos::ConfPeriodo()
{
    int value;
    int a,b;
    char x,y;
    QByteArray outbyte1,outbyte2;
    value = ui->ValueP->value();
    a=int(value/100);
    b=int(value%100);
    x = (char)a;
    y = (char)b;
    outbyte1.append(x); //agrega el caracter al arreglo outbyte
    outbyte2.append(y);
    qDebug()<<"r: "<<QString::fromStdString(outbyte1.toStdString());
    qDebug()<<"r: "<<QString::fromStdString(outbyte2.toStdString());

    emit send_byte(outbyte1);

    emit wait_written();

    emit send_byte(outbyte2);

    emit wait_written();
}

void Generador_de_pulsos::ConfValUp()
{
    qreal valor=0;
    int a=0;
    int b=0;
    int aux=0;
    if(flagPoN==1)
    {
        valor=ui->doubleSpinBox->value();
        aux=qCeil(valor*1000/(10*3.1));
        a=int(aux/100);
        b=aux%100;
    }

    if(flagPoN==0)
    {
        valor=ui->doubleSpinBox->value();
        aux=qCeil(valor*1000/(10*3.1));
        a=int(aux/100);
        b=aux%100;
    }



    QByteArray outbyte1,outbyte2;
    char x = (char)a;
    char y = (char)b;
    outbyte1.append(x); //agrega el caracter al arreglo outbyte
    outbyte2.append(y);
    qDebug()<<"r: "<<QString::fromStdString(outbyte1.toStdString());
    qDebug()<<"r: "<<QString::fromStdString(outbyte2.toStdString());

    emit send_byte(outbyte1);

    emit wait_written();

    emit send_byte(outbyte2);

    emit wait_written();

}

void Generador_de_pulsos::ConfValUp_tension()
{
    qreal valor;
    int a,b;
    int aux;

    if(flagPoN==1)
    {
        valor=ui->doubleSpinBox->value();
        aux=qCeil(valor*1000/(20*3.1));
        a=int(aux/100);
        b=aux%100;
    }

    if(flagPoN==0)
    {
        valor=ui->doubleSpinBox->value();
        aux=qCeil(valor*1000/(20*3.1));
        a=int(aux/100);
        b=aux%100;
    }


    QByteArray outbyte1,outbyte2;
    char x = (char)a;
    char y = (char)b;
    outbyte1.append(x); //agrega el caracter al arreglo outbyte
    outbyte2.append(y);
    qDebug()<<"r: "<<QString::fromStdString(outbyte1.toStdString());
    qDebug()<<"r: "<<QString::fromStdString(outbyte2.toStdString());

    emit send_byte(outbyte1);

    emit wait_written();

    emit send_byte(outbyte2);

    emit wait_written();

}

void Generador_de_pulsos::on_MandarPulsos_clicked()
{
    char letra;
    letra = 'e';
    emit send_char(letra);
}

void Generador_de_pulsos::on_ValoresDefault_clicked()
{
    char letra;
    letra = 'q';
    emit send_char(letra);
    ui->ValueN->setValue(5);
    ui->ValueT->setValue(1);
    ui->ValueP->setValue(5);
    ui->doubleSpinBox->setValue(1);

}

void Generador_de_pulsos::on_Stop_clicked()
{

    char letra;
    letra = 'r';
    emit send_char(letra);
}

//------------------------------------------

void Generador_de_pulsos::on_toolButton_clicked()
{
    ui->ValueN->setValue(ui->ValueN->value()+10);
}

void Generador_de_pulsos::on_toolButton_2_clicked()
{
     ui->ValueN->setValue(ui->ValueN->value()-10);
}

void Generador_de_pulsos::on_toolButton_23_clicked()
{
     ui->ValueN->setValue(ui->ValueN->value()+1);
}


void Generador_de_pulsos::on_toolButton_24_clicked()
{
     ui->ValueN->setValue(ui->ValueN->value()-1);
}


//------------------------------------------------

void Generador_de_pulsos::on_toolButton_3_clicked()
{
    ui->ValueT->setValue(ui->ValueT->value()+100);

    if(ui->ValueT->value()>=ui->ValueP->value())
     {
        ui->ValueP->setValue(ui->ValueT->value() +1 );
     }

}

void Generador_de_pulsos::on_toolButton_4_clicked()
{
     ui->ValueT->setValue(ui->ValueT->value()-100);
     if(ui->ValueT->value()>=ui->ValueP->value())
      {
         ui->ValueP->setValue(ui->ValueT->value() +1 );
      }
}

void Generador_de_pulsos::on_toolButton_5_clicked()
{
    ui->ValueT->setValue(ui->ValueT->value()+10);
    if(ui->ValueT->value()>=ui->ValueP->value())
     {
        ui->ValueP->setValue(ui->ValueT->value() +1 );
     }
}

void Generador_de_pulsos::on_toolButton_6_clicked()
{
    ui->ValueT->setValue(ui->ValueT->value()-10);
    if(ui->ValueT->value()>=ui->ValueP->value())
     {
        ui->ValueP->setValue(ui->ValueT->value() +1 );
     }
}

void Generador_de_pulsos::on_toolButton_21_clicked()
{
    ui->ValueT->setValue(ui->ValueT->value()+1);
    if(ui->ValueT->value()>=ui->ValueP->value())
     {
        ui->ValueP->setValue(ui->ValueT->value() +1 );
     }
}

void Generador_de_pulsos::on_toolButton_22_clicked()
{
    ui->ValueT->setValue(ui->ValueT->value()-1);
    if(ui->ValueT->value()>=ui->ValueP->value())
     {
        ui->ValueP->setValue(ui->ValueT->value() +1 );
     }
}


//----------------------------------------------------

void Generador_de_pulsos::on_toolButton_7_clicked()
{
    ui->ValueP->setValue(ui->ValueP->value()+100);
    if(ui->ValueP->value()<=ui->ValueT->value())
     {
        ui->ValueT->setValue(ui->ValueP->value() -1 );
     }
}

void Generador_de_pulsos::on_toolButton_9_clicked()
{
    ui->ValueP->setValue(ui->ValueP->value()-100);
    if(ui->ValueP->value()<=ui->ValueT->value())
     {
        ui->ValueT->setValue(ui->ValueP->value() -1 );
     }
}


void Generador_de_pulsos::on_toolButton_8_clicked()
{
    ui->ValueP->setValue(ui->ValueP->value()+10);
    if(ui->ValueP->value()<=ui->ValueT->value())
     {
        ui->ValueT->setValue(ui->ValueP->value() -1 );
     }
}



void Generador_de_pulsos::on_toolButton_10_clicked()
{
    ui->ValueP->setValue(ui->ValueP->value()-10);
    if(ui->ValueP->value()<=ui->ValueT->value())
     {
        ui->ValueT->setValue(ui->ValueP->value() -1 );
     }
}

void Generador_de_pulsos::on_toolButton_19_clicked()
{
    ui->ValueP->setValue(ui->ValueP->value()+1);
    if(ui->ValueP->value()<=ui->ValueT->value())
     {
        ui->ValueT->setValue(ui->ValueP->value() -1 );
     }
}

void Generador_de_pulsos::on_toolButton_20_clicked()
{
    ui->ValueP->setValue(ui->ValueP->value()-1);
    if(ui->ValueP->value()<=ui->ValueT->value())
     {
        ui->ValueT->setValue(ui->ValueP->value() -1 );
     }
}

//--------------------------------------------------


void Generador_de_pulsos::on_toolButton_12_clicked()
{

    ui->doubleSpinBox->setValue(ui->doubleSpinBox->value()+10);


}

void Generador_de_pulsos::on_toolButton_14_clicked()
{

   ui->doubleSpinBox->setValue(ui->doubleSpinBox->value()-10);

}

void Generador_de_pulsos::on_toolButton_17_clicked()
{
    ui->doubleSpinBox->setValue(ui->doubleSpinBox->value()+1);

}

void Generador_de_pulsos::on_toolButton_18_clicked()
{
    ui->doubleSpinBox->setValue(ui->doubleSpinBox->value()-1);

}


void Generador_de_pulsos::on_SalidaVoI_highlighted(const QString &arg1)
{
    if(flag1==0)
    {

        if(arg1=="Salida en corriente")
        {
        ui->doubleSpinBox->setRange(1,85);
        ui->doubleSpinBox->setSuffix(" mA");
        flagVoI=1;

        on_ValueUp();
        ConfValUp();

        char letra;
        letra = 'u';
       emit send_char(letra);
        }

        if(arg1=="Salida en tensión")
        {
        ui->doubleSpinBox->setRange(1,170);
        ui->doubleSpinBox->setSuffix(" V");
        flagVoI=0;

        on_ValueUp();
        ConfValUp_tension();

        char letra;
        letra = 'w';
       emit send_char(letra);
        }

    }
    else {flag1=0;}
}

void Generador_de_pulsos::on_SalidaPoN_highlighted(const QString &arg1)
{
    if(flag2==0)
    {

        if(arg1=="Pulsos positivos")
        {
        flagPoN=1;
        ui->doubleSpinBox->setPrefix("");
        char letra;
        letra = 'o';
        emit send_char(letra);
        }
        if(arg1=="Pulsos negativos")
        {
        flagPoN=0;
        ui->doubleSpinBox->setPrefix("-");
        char letra;
        letra = 's';
        emit send_char(letra);
        }

    }
    else{flag2=0;}
}

void Generador_de_pulsos::configurarVoI()
{
    if(flagVoI==1)
    {
        char letra;
        letra = 'u';
        emit send_char(letra);

    }

    if(flagVoI==0)
    {
        char letra;
        letra = 'w';
        emit send_char(letra);

    }

}

void Generador_de_pulsos::configurarPoN()
{
    if(flagPoN==1)
    {
        char letra;
        letra = 'o';
       emit send_char(letra);
    }

    if(flagPoN==0)
    {
        char letra;
        letra = 's';
        emit send_char(letra);
    }
}

//---------------------------------------------------------
void Generador_de_pulsos::on_ValueN_valueChanged(int arg1)
{
    if(flagN==0)
    {
    on_NPulsos();
    ConfPulsos();
    }
    else{flagN=0;}

}

void Generador_de_pulsos::on_doubleSpinBox_valueChanged(double arg1)
{
    if(flagV==0)
    {
        on_ValueUp();

        if(flagVoI==1)
        {
            ConfValUp();
        }
        if(flagVoI==0)
        {
            ConfValUp_tension();
        }
    }
    else{flagV=0;}
}

void Generador_de_pulsos::on_ValueT_valueChanged(int arg1)
{
    if(flagT==0)
    {
        on_Tup();
        ConfTup();
    }
    else{flagT=0;}

}

void Generador_de_pulsos::on_ValueP_valueChanged(int arg1)
{
    if(flagP==0)
    {
        on_Periodo();
        ConfPeriodo();
    }
    else{flagP=0;}
}



