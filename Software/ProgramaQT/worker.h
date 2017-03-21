#ifndef WORKER_H
#define WORKER_H

#include <QObject>
#include <QThread>
#include <QtDebug>
#include <QtSerialPort/QSerialPort>


class worker : public QObject
{
    Q_OBJECT
public:
    explicit worker(QObject *parent = 0);
    ~worker();
signals:
    void initPortOK();
    void initPortNotOK();
    void initPort2NotOK();
    void mensajeError(QString title, QString info);
    void mensajeOK(QString title, QString info);
    void finish();
    void hayDatos();
    void datosCargados(QStringList buffer);


public slots:
    //void doSetup(QThread &cThread);
    void initPort(QString nameport);
    void initPort_2(QString nameport);
    void readEduciaa();
    void handleError(QSerialPort::SerialPortError error);
    void availableData();
    void recibir_comVirtual();
    void envia_char(char letra);
    void envia_byte(QByteArray outbyte);
    void wait_for_write();
};

#endif // WORKER_H
