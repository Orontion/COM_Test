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
        QString Temp_S = info.portName() + "\n"
                         + info.description() + "\n";

        PortInfos_List << Temp_S;
    }

    return PortInfos_List;
}



//Процедура подсчета количества COM-портов в системе
int COM_Module::Ports_Count()
{
    return QSerialPortInfo::availablePorts().count();
}
