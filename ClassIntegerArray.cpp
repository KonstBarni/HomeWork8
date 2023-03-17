#include <iostream>
#include <string>
#include "ClassIntegerArray.h"
#include "ExceptionsArray.h"
using namespace std;

template <class T>
Array<T>::Array(int size):_size(size)
{
    if (_size <= 0)
        throw Exceptions("Размер контейнера  <= 0!");
    else if(_size > 10)                  //ограничение размера контейнера
        throw Exceptions("Превышен макс. размер контейнера!");
    arr = new T[_size]{};
    _data = 0;
}

template <class T>
Array<T>::Array(const Array& other)
{
    _size = other._size;
    _data = other._data;
    arr = new T[other._size];
    for (int i = 0; i < _size; i++)
        arr[i] = other.arr[i];
}

template <class T>
Array<T>& Array<T>::operator=(const Array& oper)         // перегрузка оператора присваивания
{
    if(this == &oper)
        return *this;
    delete[] arr;
    _size = oper._size;
    _data = oper._data;
    arr = new T[oper._size];
    for(int i =0; i<oper._size; i++)
        arr[i] = oper.arr[i];
    return *this;
} 

template <class T>
T& Array<T>::operator[](int index)
    {
        if(index < 0 || index > _size)
            throw Exceptions("Operator[] Неверный индекс");
        return arr[index];
    }

template <class T>
int Array<T>::getSize()
{
    return _size;
}

template <class T>
int Array<T>::getData()                             //возвращает размер
{
    return _data;
}

template <class T>
void Array<T>::addByIndex(int index, T el)        // добавление по индексу
{
    if(index < 0 || index > _size)
            throw Exceptions("addByIndex: Неверный индекс");
    if(_data >= _size)
        throw Exceptions("addByIndex: Контейнер заполнен");

    T* tempB = new T[_size];            //создаем копию 
    for(int i = 0; i <_size; i++)
    {
        tempB[i] = arr[i];
    }

    arr[index] = el;                        //добавить по индексу 

    for(int x{index}; x < _size; x++)       //заполнить из копии со сдвигом
        if(x+1 < _size)
            arr[x+1] = tempB[x];
        else if(_data >= _size)
            throw Exceptions("addByIndex: Контейнер заполнен");

    _data++; 
    delete[] tempB;
}

template <class T>
void Array<T>::addInBegin(T el)                   //добавить в начало
{
    if(_data >= _size)
        throw Exceptions("addInBegin: Контейнер заполнен");
    T* tempB = new T[_size];             //создаем копию 
    for(int i = 0; i <_size; i++)
        tempB[i] = arr[i];

    arr[0] = el;                            //добавляем в начало

    for(int x{0}; x <_size; x++)            //заполняем из копии со сдвигом
        if(x+1 < _size)
            arr[x+1] = tempB[x];
        else if(_data >= _size)
            throw Exceptions("addInBegin: Контейнер заполнен");
    _data++;
    delete[] tempB;
}

template <class T>
void Array<T>::addInEnd(T el)                     //добавить в конец
{
    if(_data >= _size)                
        throw Exceptions("addInEnd: Контейнер заполнен");
    
    for(int i{0}; i < _size; i++)
    {
        if(arr[i] == 0)
        {                
            arr[i] = el;
            break;
        }
    }
    _data++;
}

template <class T>
void Array<T>::resize(int newSize)
{
    if(newSize <=0 || newSize > 10)
        throw Exceptions("resize: неверный размер");

    if (newSize == _size)
            return;
    
    if (newSize > 0)
        {
            T* temp = new T[newSize];
            for (int i{0}; i < newSize; i++)
                temp[i] = arr[i];
        
            if(_data > newSize)
                _data = newSize;

            delete[] arr;
            _size = newSize;
            arr = temp;
        }   
}

template <class T>
void Array<T>::search(T el)           //поиск элемента
{
    for(int i{0}; i < _size; i++)
    {
        if(arr[i] == el)
        {
            cout << "Элемент " << el << " находится в ячейке: " << i << endl;
            break;
        }    
        else if(i == _size - 1 && arr[i] != el)
            cout << "Элемент " << el << " не найден!" << endl;
    }
}

template <class T>
void Array<T>::remove(int index)        //удаление элемента
{
    if(_size < 0 || index >= _size)
        throw Exceptions("Удаление невозможно: неверный индекс");

    arr[index] = 0;

    for(int i{index}; i < _size; i++)
        swap(arr[i], arr[i+1]);

    --_size;
    --_data;
}

template <class T>
void Array<T>::sorting()                    //сортировка пузырьком
{
    int cnt = _data-1;

    while(cnt--)
    {
        bool swapped = false;

        for (int i{0}; i < _data-1; i++)
            {
                if(arr[i] > arr[i +1])
                {
                    swap(arr[i], arr[i+1]);
                    swapped = true;
                }
            }
        if (swapped = false)
            break;
    }
}

template <class T>
void Array<T>::printEl()                    //print all elements
{
    for(int i = 0; i < _size; i++)
        cout << arr[i] << " ";
    cout << endl;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  
}

template <class T>
Array<T>::~Array()
{
    delete[] arr;
}

template class Array<int>;
template class Array<double>;
template class Array<char>;