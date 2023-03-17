#include <iostream>
#include <string>
#include "ClassIntegerArray.h"
#include "ExceptionsArray.h"

using namespace std;


int main()
{
    int size;
    while(true)
    {
        cout << "Для выхода нажмите любую букву" << endl;
        cout << "Введите размер контейнера: ";
        cin >> size;

        if(cin.fail())          // выход из программмы
            return 0;

        try 
        {
            Array<char> conteiner(size);

            conteiner.addInBegin('c');       //добавить в начало
            conteiner.addInBegin('q');
            conteiner.addInBegin('y');
            //conteiner.printEl();

            conteiner.addInEnd('H');         //добавить в конец
            conteiner.addInEnd('G');
            conteiner.addInEnd('D');
            //conteiner.printEl();

            conteiner.addByIndex(2, 'Z');   //добавить по индексу
            conteiner.addByIndex(6, 'P');
            //conteiner.addByIndex(18, 135);    //неверный индекс
            conteiner.printEl();
            cout << "Элементов в контейнере: " << conteiner.getData() << endl;
            cout << endl;

            conteiner.search(12.5);           //поиск
            //conteiner.search(35);
            conteiner.sorting();            //сортировка
            cout << "Сортировка: "; 
            conteiner.printEl();
            cout <<endl;

            cout << "Удаление: ";
            conteiner.remove(6);            //удаление элемента
            conteiner.printEl();
            cout << "Элементов в контейнере: " << conteiner.getData() << endl;
            cout << endl;

            cout << "Изменение размера: ";
            conteiner.resize(6);            //изменение размера
            conteiner.printEl();
            cout << "Элементов в контейнере: " << conteiner.getData() << endl;
        
        } 

        catch(Exceptions& ex)
        {
            cout << ex.what() << endl;
        }
    
    }
    return 0;
}
