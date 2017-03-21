#include "worker.h"

char stateport = 0;
char stateport2 = 0;
QSerialPort* portCom;
QSerialPort* portCom2;

worker::worker(QObject *parent) : QObject(parent)
{
    portCom = new QSerialPort(this);
    portCom2 = new QSerialPort(this);
}

worker::~worker()
{
    delete portCom;
    //portCom=NULL;
}
void worker::initPort(QString nameport)
{
    if(stateport==0)
    {

      portCom->setPortName(nameport); // se le asigna le nombre del puerto

      portCom->open(QIODevice::ReadWrite); // abre la comunicación en modo lectura y escritura

      if( portCom->isOpen()==false)
      {
        portCom->clearError();


        portCom->close();
        stateport = 1;

        emit initPortNotOK();
        emit mensajeError("Error en el puerto", "Imposible abrir puerto"+nameport);

      }
      else
      {

        portCom->setBaudRate(QSerialPort::Baud115200);
        portCom->setStopBits(QSerialPort::OneStop);
        portCom->setParity(QSerialPort::NoParity);
        portCom->setDataBits(QSerialPort::Data8);
        portCom->setFlowControl(QSerialPort::NoFlowControl);
        stateport = 2;
        emit initPortOK();
        emit mensajeOK("Puerto Abierto", "Se abrió el puerto!: "+nameport);
        connect(portCom,SIGNAL(readyRead()),this,SLOT(availableData()));
        connect(this,SIGNAL(hayDatos()),this,SLOT(readEduciaa()));
      }
    }
    else if( stateport==1 )
    { stateport = 0;  }
    else if( stateport==2 )//para cerrar el puerto al volver a hacer click en el botón
    {
      portCom->close();
      portCom->destroyed();
      stateport = 0;
      emit finish();
    }


}

void worker::initPort_2(QString nameport)
{
    if(stateport2==0)
    {

      portCom2->setPortName(nameport); // se le asigna le nombre del puerto

      portCom2->open(QIODevice::ReadWrite); // abre la comunicación en modo lectura y escritura

      if( portCom2->isOpen()==false)
      {
        portCom2->clearError();


        portCom2->close();
        stateport2 = 1;

        emit initPort2NotOK();
        emit mensajeError("Error en el puerto", "Imposible abrir puerto"+nameport);

      }
      else
      {

        portCom2->setBaudRate(QSerialPort::Baud115200);
        portCom2->setStopBits(QSerialPort::OneStop);
        portCom2->setParity(QSerialPort::NoParity);
        portCom2->setDataBits(QSerialPort::Data8);
        portCom2->setFlowControl(QSerialPort::NoFlowControl);
        stateport2 = 2;

        emit mensajeOK("Puerto Abierto", "Se abrió el puerto!: "+nameport);

      }
    }
    else if( stateport2==1 )
    { stateport2 = 0;  }
    else if( stateport2==2 )//para cerrar el puerto al volver a hacer click en el botón
    {
      portCom2->close();
      portCom2->destroyed();
      stateport2 = 0;
      emit finish();
    }

    connect(portCom2,SIGNAL(readyRead()),this,SLOT(recibir_comVirtual()));
}


void worker::readEduciaa()
{
    connect(portCom, SIGNAL(error(QSerialPort::SerialPortError)), SLOT(handleError(QSerialPort::SerialPortError)));
    QStringList buffer_split;
    QString serialBuffer="";
    QByteArray serialDat="";
    QByteArray serialData="";
    int bytes;
    int n=0;
    int items=0;

    bytes=portCom->bytesAvailable();

    if(bytes>0)
    {
      serialDat = portCom->readLine();

      n =serialDat.size();
      qDebug()<<n<<'\n';


       serialData=serialDat.trimmed();
       serialBuffer += QString::fromStdString(serialData.toStdString());
       qDebug()<< serialBuffer<<'\n';

       buffer_split = serialBuffer.split(',');


       qDebug() << buffer_split;
       items=buffer_split.size();
    if(items ==9)
        {
            emit datosCargados(buffer_split);
        }

    }

    serialDat.clear();
    serialData.clear();
    portCom->clear(QSerialPort::Input);

    if(items!=9)
    {
        envia_char('z');
    }

}


void worker::handleError(QSerialPort::SerialPortError error)
{

    qDebug()<<"Error:"<<error;//I added this line
    if(error==QSerialPort::ResourceError)
    {
    qDebug()<<portCom->errorString();

    }
}

void worker::availableData()
{
    qDebug()<<"Hay Datos en el puerto"<<'\n';
    emit hayDatos();
}

void worker::recibir_comVirtual()
{
    int num_datos;

    char dato;
    num_datos =  portCom2->bytesAvailable();
    if (num_datos > 0) {    // hay algo, saco un solo byte
        portCom2->getChar(&dato);

        if (dato == 'e') {
            char letra;
            letra = 'e';
            portCom->putChar(letra);}
    }
}

void worker::envia_char(char letra)
{
    portCom->putChar(letra);
}

void worker::envia_byte(QByteArray outbyte)
{
    portCom->write(outbyte);
}

void worker::wait_for_write()
{
    portCom->waitForBytesWritten(10);
}
