#ifndef COM_MODULE_H
#define COM_MODULE_H

//Подключаем все, что будет использоваться в модуле
#include <QSerialPort>
#include <QSerialPortInfo>

//Класс для работы с COM-портами для настройки свитчей. Для работы необходима библиотека QtSerialPort
//В файле проекта нужно добавить строку "QT += serialport"


class COM_Module
{
    //Объявления публичных процедур (забыл, как это правильно называется...)
public:
    //Конструктор модуля
    COM_Module();

    //Функция осмотра доступных портов
    QList<QString> Available_Ports();

    int Ports_Count();


};

#endif // COM_MODULE_H
