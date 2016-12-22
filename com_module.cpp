//Тут нужно подключать только заголовочный файл модуля
#include "com_module.h"


//Конструктор класса
COM_Module::COM_Module()
{

}

//Функция осмотра доступных портов
QList <QString> COM_Module::Available_Ports()
{
    QList<QString> PortInfos_List;

    //Константа (тип которой автоматически устанавливается таким же, как и у присваиваемой переменной, С++11, сучки!),
    //в которую сохраняется текущее положение дел с портами в системе
    const auto PortInfos = QSerialPortInfo::availablePorts();

    //Цикл перебора всех имеющихся портов (фактически, for each, еще одна фишка С++11)
    for (const QSerialPortInfo &info : PortInfos)
    {
        QString Temp_S = info.portName();
                         //+ info.systemLocation() + "\n"
                         //+ info.description() + "\n";

        PortInfos_List << Temp_S;
    }

    return PortInfos_List;
}


//Процедура подсчета количества COM-портов в системе
int COM_Module::Ports_Count()
{
    return QSerialPortInfo::availablePorts().count();
}

//Функция выбора порта (пока не защищена от ввода неверного имени порта)
void COM_Module::Choose_Port(QString Port_Name)
{
    Chosen_Port = Port_Name;
}

//Функция подключения к выбранному COM-порту (настройки подключения взяты стандартынми для DES-3526)
QString COM_Module::Connect_to_Chosen_Port()
{
    //Создаем новый объект
    //COM_Port = new QSerialPort(this);

    //Задаем настройки COM-порта
    COM_Port.setPortName(Chosen_Port);
    COM_Port.setBaudRate(9600);
    COM_Port.setDataBits(QSerialPort::Data8);
    COM_Port.setParity(QSerialPort::NoParity);
    COM_Port.setStopBits(QSerialPort::OneStop);
    COM_Port.setFlowControl(QSerialPort::SoftwareControl);

    //Пробуем открыть порт
    if (COM_Port.open(QIODevice::ReadWrite))
    {
        return "Opened successefully";
    }
    else
    {
        return COM_Port.errorString();
    }

}

//Функция чтения данных
QByteArray COM_Module::Read_Port()
{
    QByteArray Temp_Array;
    Temp_Array.append(COM_Port.readAll());
    return Temp_Array;
}
