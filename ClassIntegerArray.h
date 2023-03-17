#pragma once

template <class T> 
class Array
{
    int _size{};
    int _data{0};
    T *arr{};
public:
    Array()= default;
    Array(int size);
    Array(const Array& other);
    Array& operator=(const Array& oper);
    T& operator[](int index);

    int getSize();
    int getData();                              //получить кол-во элементов

    void addByIndex(int index, T el);         //добавить по индексу
    void addInBegin(T el);                    //добавить в начало
    void addInEnd(T el);                      //добавить в конец
    void resize(int newSize);                   //изменить размер
    void search(T el);                        //поиск элемента
    void remove(int index);                     //удаление элемента
    void sorting();                             //сортировка
    void printEl();                             //вывод всех элементов
    
    ~Array();
};
