//Тут нужно подключать только заголовочный файл модуля
#include "com_module.h"

/*=================================

Отдельный конструктор класса становится ненужен, т.к. используется наследованный конструктор

//Конструктор класса
COM_Module::COM_Module()
{

}

==================================*/

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

    //Задаем настройки COM-порта
    this->setPortName(Chosen_Port);
    this->setBaudRate(9600);
    this->setDataBits(QSerialPort::Data8);
    this->setParity(QSerialPort::NoParity);
    this->setStopBits(QSerialPort::OneStop);
    this->setFlowControl(QSerialPort::SoftwareControl);

    //Пробуем открыть порт
    if (this->open(QIODevice::ReadWrite))
    {
        return "Opened successefully";
    }
    else
    {
        return this->errorString();
    }

}

/*=================================

Т.к. мы наследуем объект, то отдельная функция чтения порта становится ненужной

//Функция чтения данных, тип - QByteArray
QByteArray COM_Module::Read_Port()
{

    //Временная переменная для записи данных из буфера COM-порта
    QByteArray Temp_Array = NULL;

    //В течение секунды проверяем, есть ли что в порту для чтения
    //if (COM_Port.waitForReadyRead(0))
    {
        //Если есть - так и пишем
        Temp_Array.append(COM_Port.readAll());
    }

    //Выводим результат в качестве значения функции
    return Temp_Array;
}

==================================*/
