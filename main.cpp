#include <QCoreApplication>

//Добавим свеженаписанный модуль для тестов
#include <com_module.h>

//Пара файлов для работы с командной строкой
#include <QTextStream>

//Главная процедура
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //Собственно, модуль для тестов
    COM_Module TestObj;

    //Входные-выходные потоки
    QTextStream qtin(stdin);
    QTextStream qtout(stdout);

    qtout << TestObj.Ports_Count();

    //Не забываем показать изменения в самой командной строке
    qtout.flush();

    return a.exec();
}
