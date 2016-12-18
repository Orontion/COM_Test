#include "com_module.h"
#include <QSerialPort>
#include <QSerialPortInfo>

//Конструктор класса
COM_Module::COM_Module()
{

}


//Процедура подсчета количества COM-портов в системе
int COM_Module::Ports_Count()
{
    return QSerialPortInfo::availablePorts().count();
}
