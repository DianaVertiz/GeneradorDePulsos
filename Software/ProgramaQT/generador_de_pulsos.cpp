#include "generador_de_pulsos.h"
#include "ui_generador_de_pulsos.h"
#include<QtSerialPort/QSerialPort>
#include<QtSerialPort/QSerialPortInfo>
#include<QtMath>

QSerialPort * Serial;
QSerialPort * Serial_virtual;

char stateport = 0;
char stateport2 = 0;


Generador_de_pulsos::Generador_de_pulsos(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Generador_de_pulsos)
{
    ui->setupUi(this);
    Serial = new QSerialPort(this);
    foreach (QSerialPortInfo port, QSerialPortInfo::availablePorts()) {
        ui->ListaPuertos->addItem(port.portName());
        ui->ListaPuertos_2->addItem(port.portName());
    }

}

void Generador_de_pulsos::ConfInicio()
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

}

/*void Generador_de_pulsos::readEduciaa()
{

}*/


void Generador_de_pulsos::on_radioButton_clicked()
{
    QString nameport;

    nameport=ui->ListaPuertos->currentText();
    if(stateport==0)
    {
      Serial = new QSerialPort(this); // se crea un objeto de tipo puerto serial en esta ventana
      Serial->setPortName(nameport); // se le asigna le nombre del puerto

      Serial->open(QIODevice::ReadWrite); // abre la comunicación en modo lectura y escritura

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
        ConfInicio();
        //connect(Serial,SIGNAL(readyRead()),this,SLOT(readEduciaa()));
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

void Generador_de_pulsos::on_radioButton_2_clicked()
{
    QString nameport2;

    nameport2=ui->ListaPuertos_2->currentText();

    if(stateport2==0)
    {
      Serial_virtual = new QSerialPort(this); // se crea un objeto de tipo puerto serial en esta ventana
      Serial_virtual->setPortName(nameport2); // se le asigna le nombre del puerto

      Serial_virtual->open(QIODevice::ReadOnly); // abre la comunicación en modo lectura y escritura

      if( Serial_virtual->isOpen()==false)
      {
        Serial_virtual->clearError();
        //Qmessagebox emite un mensaje en una caja aparte a la ventana actual en modo de alerta.
        QMessageBox::warning(this,"Error en el puerto", "Imposible abrir puerto"+nameport2);

        Serial_virtual->close();
        stateport2 = 1;
        ui->radioButton_2->animateClick(200);

      }
      else
      {
        //Qmessagebox emite un mensaje en una caja aparte a la ventana actual en modo de notificacion.
        QMessageBox::information(this, "Puerto Abierto", "Se abrió el puerto!: "+nameport2);
        // Configuraciones para la comunicacion serie segun sea el caso.
        Serial_virtual->setBaudRate(QSerialPort::Baud115200);
        Serial_virtual->setStopBits(QSerialPort::OneStop);
        Serial_virtual->setParity(QSerialPort::NoParity);
        Serial_virtual->setDataBits(QSerialPort::Data8);
        Serial_virtual->setFlowControl(QSerialPort::NoFlowControl);
        stateport2 = 2;
      }
    }
    else if( stateport2==1 )
    { stateport2 = 0;  }
    else if( stateport2==2 )
    {
      Serial_virtual->close();
      Serial_virtual->destroyed();
      stateport2 = 0;
    }

     connect(Serial_virtual,SIGNAL(readyRead()),this,SLOT(recibir_comVirtual()));

}

void Generador_de_pulsos::recibir_comVirtual()
{
    int num_datos;

    char dato;
    num_datos =  Serial_virtual->bytesAvailable();
    if (num_datos > 0) {    // hay algo, saco un solo byte
        Serial_virtual->getChar(&dato);

        if (dato == 'e') {
            char letra;
            letra = 'e';
            Serial->putChar(letra);}
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

void Generador_de_pulsos::on_Stop_clicked()
{

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

    if(ui->ValueT->value()==ui->ValueP->value())
     {
        ui->ValueP->setValue(ui->ValueP->value() +1 );
     }

}

void Generador_de_pulsos::on_toolButton_4_clicked()
{
     ui->ValueT->setValue(ui->ValueT->value()-100);
     if(ui->ValueT->value()==ui->ValueP->value())
      {
         ui->ValueP->setValue(ui->ValueP->value() +1 );
      }
}

void Generador_de_pulsos::on_toolButton_5_clicked()
{
    ui->ValueT->setValue(ui->ValueT->value()+10);
    if(ui->ValueT->value()==ui->ValueP->value())
     {
        ui->ValueP->setValue(ui->ValueP->value() +1 );
     }
}

void Generador_de_pulsos::on_toolButton_6_clicked()
{
    ui->ValueT->setValue(ui->ValueT->value()-10);
    if(ui->ValueT->value()==ui->ValueP->value())
     {
        ui->ValueP->setValue(ui->ValueP->value() +1 );
     }
}

void Generador_de_pulsos::on_toolButton_21_clicked()
{
    ui->ValueT->setValue(ui->ValueT->value()+1);
    if(ui->ValueT->value()==ui->ValueP->value())
     {
        ui->ValueP->setValue(ui->ValueP->value() +1 );
     }
}

void Generador_de_pulsos::on_toolButton_22_clicked()
{
    ui->ValueT->setValue(ui->ValueT->value()-1);
    if(ui->ValueT->value()==ui->ValueP->value())
     {
        ui->ValueP->setValue(ui->ValueP->value() +1 );
     }
}


//----------------------------------------------------

void Generador_de_pulsos::on_toolButton_7_clicked()
{
    ui->ValueP->setValue(ui->ValueP->value()+100);
    if(ui->ValueT->value()==ui->ValueP->value())
     {
        ui->ValueP->setValue(ui->ValueP->value() +1 );
     }
}

void Generador_de_pulsos::on_toolButton_9_clicked()
{
    ui->ValueP->setValue(ui->ValueP->value()-100);
    if(ui->ValueT->value()==ui->ValueP->value())
     {
        ui->ValueP->setValue(ui->ValueP->value() +1 );
     }
}


void Generador_de_pulsos::on_toolButton_8_clicked()
{
    ui->ValueP->setValue(ui->ValueP->value()+10);
    if(ui->ValueT->value()==ui->ValueP->value())
     {
        ui->ValueP->setValue(ui->ValueP->value() +1 );
     }
}



void Generador_de_pulsos::on_toolButton_10_clicked()
{
    ui->ValueP->setValue(ui->ValueP->value()-10);
    if(ui->ValueT->value()==ui->ValueP->value())
     {
        ui->ValueP->setValue(ui->ValueP->value() +1 );
     }
}

void Generador_de_pulsos::on_toolButton_19_clicked()
{
    ui->ValueP->setValue(ui->ValueP->value()+1);
    if(ui->ValueT->value()==ui->ValueP->value())
     {
        ui->ValueP->setValue(ui->ValueP->value() +1 );
     }
}

void Generador_de_pulsos::on_toolButton_20_clicked()
{
    ui->ValueP->setValue(ui->ValueP->value()-1);
    if(ui->ValueT->value()==ui->ValueP->value())
     {
        ui->ValueP->setValue(ui->ValueP->value() +1 );
     }
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

//---------------------------------------------------------
void Generador_de_pulsos::on_ValueN_valueChanged(int arg1)
{
    on_NPulsos();
    ConfPulsos();
}

void Generador_de_pulsos::on_doubleSpinBox_valueChanged(double arg1)
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

void Generador_de_pulsos::on_ValueT_valueChanged(int arg1)
{
    on_Tup();
    ConfTup();

}

void Generador_de_pulsos::on_ValueP_valueChanged(int arg1)
{
    on_Periodo();
    ConfPeriodo();
}

