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

    //QList для тестов
    QList<QString> Test_List;

    //Входные-выходные потоки
    QTextStream qtin(stdin);
    QTextStream qtout(stdout);

    qtout << TestObj.Ports_Count() << "\n";

    //Берем в переменную инфу о доступных портах
    Test_List = TestObj.Available_Ports();


    //Если портов нет - так и говорим, иначе - выводим инфу в консольку
    if (Test_List.count() == 0)
    {
        qtout << "No available ports";
    }
    else
    {
        //Перебираем все элементы Test_List и выводим их в консоль
        for (const QString Temp_String : Test_List)
        {
            qtout << Temp_String + "\n\n";
        }

        //Выбираем первый порт
        TestObj.Choose_Port(Test_List[0]);

        //Подключаемся к первому порту и сразу выводим результат
        qtout << TestObj.Connect_to_Chosen_Port();

    }

    //Не забываем показать изменения в самой командной строке
    qtout.flush();

    return a.exec();
}
