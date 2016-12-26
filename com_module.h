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

    //Функция выбора порта (пока не защищена от ввода неверного имени порта)
    void Choose_Port(QString Port_Name);

    //Функция подключения к выбранному COM-порту (настройки подключения взяты стандартынми для DES-3526)
    QString Connect_to_Chosen_Port();

    //Функция чтения данных
    QByteArray Read_Port();


    //Объявления внутренних процедур/переменных
private:
    //Строка, в которой сохранено имя выбранного порта
    QString Chosen_Port;

    //Объект-порт, с которым будем взаимодействовать
    QSerialPort COM_Port;


};

#endif // COM_MODULE_H
