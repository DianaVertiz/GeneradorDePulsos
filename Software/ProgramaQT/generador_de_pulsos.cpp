#include "generador_de_pulsos.h"
#include "ui_generador_de_pulsos.h"
#include<QtSerialPort/QSerialPort>
#include<QtSerialPort/QSerialPortInfo>
#include<QtMath>

QSerialPort * Serial;

char stateport = 0;
//QString nameport = "COM7";

Generador_de_pulsos::Generador_de_pulsos(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Generador_de_pulsos)
{
    ui->setupUi(this);
    Serial = new QSerialPort(this);
    foreach (QSerialPortInfo port, QSerialPortInfo::availablePorts()) {
        ui->ListaPuertos->addItem(port.portName());
    }
}

void Generador_de_pulsos::on_radioButton_clicked()
{
    QString nameport;

    nameport=ui->ListaPuertos->currentText();
    if(stateport==0)
    {
      Serial = new QSerialPort(this); // se crea un objeto de tipo puerto serial en est� ventana
      Serial->setPortName(nameport); // se le asigna le nombre del puerto
      Serial->open(QIODevice::ReadWrite); // abre la comunicaci�n en modo lectura y escritura

      if( Serial->isOpen()==false)
      {
        Serial->clearError();
        //Qmessagebox emite un mensaje en una caja aparte a la ventana actual en modo de alerta.
        QMessageBox::warning(this,"Error en el puerto", "Imposible abrir puerto"+nameport);

        Serial->close();
        stateport = 1;
        ui->radioButton->animateClick(200);

      }
      else
      {
        //Qmessagebox emite un mensaje en una caja aparte a la ventana actual en modo de notificacion.
        QMessageBox::information(this, "Puerto Abierto", "Se abrió el puerto!: "+nameport);
        // Configuraciones para la comunicacion serie segun sea el caso.
        Serial->setBaudRate(QSerialPort::Baud115200);
        Serial->setStopBits(QSerialPort::OneStop);
        Serial->setParity(QSerialPort::NoParity);
        Serial->setDataBits(QSerialPort::Data8);
        Serial->setFlowControl(QSerialPort::NoFlowControl);
        stateport = 2;
      }
    }
    else if( stateport==1 )
    { stateport = 0;  }
    else if( stateport==2 )
    {
      Serial->close();
      Serial->destroyed();
      stateport = 0;
    }

}


Generador_de_pulsos::~Generador_de_pulsos()
{
    Serial->close();
    delete ui;
}

void Generador_de_pulsos::on_NPulsos()
{
    char letra;
    letra = 'n';
    Serial->putChar(letra);
}

void Generador_de_pulsos::on_Tup()
{
    char letra;
    letra = 't';
    Serial->putChar(letra);
}

void Generador_de_pulsos::on_Periodo()
{
    char letra;
    letra = 'p';
    Serial->putChar(letra);
}

void Generador_de_pulsos::on_ValueUp()
{
    char letra;
    letra = 'v';
    Serial->putChar(letra);
}

void Generador_de_pulsos::ConfPulsos()
{
    int value;
    value = ui->ValueN->value();
    QByteArray outbyte;
    char x = (char)value;
    outbyte.append(x); //agrega el caracter al arreglo outbyte
    qDebug()<<"r: "<<outbyte.data();
    //envía el valor configurado
    Serial->write(outbyte);
    Serial->waitForBytesWritten(10);
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
    qDebug()<<"r: "<<outbyte1.data();
    qDebug()<<"r: "<<outbyte2.data();
    //envía el valor configurado
    Serial->write(outbyte1);
    // Serial->waitForBytesWritten(10);
    Serial->write(outbyte2);
    //Serial->waitForBytesWritten(10);

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
    qDebug()<<"r: "<<'0' + outbyte1.data();
    qDebug()<<"r: "<<outbyte2.data();
    //envía el valor configurado
    Serial->write(outbyte1);
    // Serial->waitForBytesWritten(10);
    Serial->write(outbyte2);
    //Serial->waitForBytesWritten(10);


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
    qDebug()<<"r: "<<outbyte1.data();
    qDebug()<<"r: "<<outbyte2.data();
    //envía el valor configurado
    Serial->write(outbyte1);
   // Serial->waitForBytesWritten(10);
    Serial->write(outbyte2);
    //Serial->waitForBytesWritten(10);;

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
    qDebug()<<"r: "<<outbyte1.data();
    qDebug()<<"r: "<<outbyte2.data();
    //envía el valor configurado
    Serial->write(outbyte1);
    // Serial->waitForBytesWritten(10);
    Serial->write(outbyte2);
    //Serial->waitForBytesWritten(10);;

}

void Generador_de_pulsos::on_MandarPulsos_clicked()
{
    char letra;
    letra = 'e';
    Serial->putChar(letra);
}

void Generador_de_pulsos::on_ValoresDefault_clicked()
{
    char letra;
    letra = 'q';
    Serial->putChar(letra);
    //ui->ValueN->setValue(5);
    ui->ValueT->setValue(1);
    ui->ValueP->setValue(5);
    //ui->doubleSpinBox->setValue(1);
    char letra2;
    letra2 = 'r';
    Serial->putChar(letra2);
}

void Generador_de_pulsos::on_Configurar_clicked()
{
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
   char letra;
   letra = 'r';
   Serial->putChar(letra);
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
}

void Generador_de_pulsos::on_toolButton_4_clicked()
{
     ui->ValueT->setValue(ui->ValueT->value()-100);
}

void Generador_de_pulsos::on_toolButton_5_clicked()
{
    ui->ValueT->setValue(ui->ValueT->value()+10);
}

void Generador_de_pulsos::on_toolButton_6_clicked()
{
    ui->ValueT->setValue(ui->ValueT->value()-10);
}

void Generador_de_pulsos::on_toolButton_21_clicked()
{
    ui->ValueT->setValue(ui->ValueT->value()+1);
}

void Generador_de_pulsos::on_toolButton_22_clicked()
{
    ui->ValueT->setValue(ui->ValueT->value()-1);
}


//----------------------------------------------------

void Generador_de_pulsos::on_toolButton_7_clicked()
{
    ui->ValueP->setValue(ui->ValueP->value()+100);
}

void Generador_de_pulsos::on_toolButton_9_clicked()
{
    ui->ValueP->setValue(ui->ValueP->value()-100);
}


void Generador_de_pulsos::on_toolButton_8_clicked()
{
    ui->ValueP->setValue(ui->ValueP->value()+10);
}



void Generador_de_pulsos::on_toolButton_10_clicked()
{
    ui->ValueP->setValue(ui->ValueP->value()-10);
}

void Generador_de_pulsos::on_toolButton_19_clicked()
{
    ui->ValueP->setValue(ui->ValueP->value()+1);
}

void Generador_de_pulsos::on_toolButton_20_clicked()
{
    ui->ValueP->setValue(ui->ValueP->value()-1);
}

//--------------------------------------------------


void Generador_de_pulsos::on_toolButton_12_clicked()
{
    if(flagVoI==1)
    {
        if(ui->doubleSpinBox->value()==100)
        {
            ui->doubleSpinBox->setValue(1);
        }
        else
        {
            ui->doubleSpinBox->setValue(ui->doubleSpinBox->value()+10);

        }

    }

    if(flagVoI==0)
    {
        if(ui->doubleSpinBox->value()==200)
        {
            ui->doubleSpinBox->setValue(1);
        }
        else
        {
            ui->doubleSpinBox->setValue(ui->doubleSpinBox->value()+10);

        }
    }
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
    if(arg1=="Salida en corriente")
    {
    ui->doubleSpinBox->setRange(1,100);
    ui->doubleSpinBox->setSuffix(" mA");
    flagVoI=1;

    on_ValueUp();
    ConfValUp();

    char letra;
    letra = 'u';
    Serial->putChar(letra);
    }

    if(arg1=="Salida en tensión")
    {
    ui->doubleSpinBox->setRange(1,200);
    ui->doubleSpinBox->setSuffix(" V");
    flagVoI=0;

    on_ValueUp();
    ConfValUp_tension();

    char letra;
    letra = 'w';
    Serial->putChar(letra);
    }
}

void Generador_de_pulsos::on_SalidaPoN_highlighted(const QString &arg1)
{
    if(arg1=="Pulsos positivos")
    {
    flagPoN=1;
    ui->doubleSpinBox->setPrefix("");
    char letra;
    letra = 'o';
    Serial->putChar(letra);
    }
    if(arg1=="Pulsos negativos")
    {
    flagPoN=0;
    ui->doubleSpinBox->setPrefix("-");
    char letra;
    letra = 's';
    Serial->putChar(letra);

    }
}

void Generador_de_pulsos::configurarVoI()
{
    if(flagVoI==1)
    {
        char letra;
        letra = 'u';
        Serial->putChar(letra);

    }

    if(flagVoI==0)
    {
        char letra;
        letra = 'w';
        Serial->putChar(letra);

    }

}

void Generador_de_pulsos::configurarPoN()
{
    if(flagPoN==1)
    {
        char letra;
        letra = 'o';
        Serial->putChar(letra);
    }

    if(flagPoN==0)
    {
        char letra;
        letra = 's';
        Serial->putChar(letra);
    }
}
