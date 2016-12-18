#ifndef COM_MODULE_H
#define COM_MODULE_H

//Класс для работы с COM-портами для настройки свитчей. Для работы необходима библиотека QtSerialPort
//В файле проекта нужно добавить строку "QT += serialport"


class COM_Module
{
    //Объявления публичных процедур (забыл, как это правильно называется...)
public:
    //Конструктор модуля
    COM_Module();

    int Ports_Count();


};

#endif // COM_MODULE_H
