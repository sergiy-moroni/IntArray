#include <iostream>
#include "IntArray.h"
#include <exception>

using namespace std;

class bad_range : public exception
{
public:
    virtual const char* what() const noexcept override
    {
        return "ERROR: Выход за пределы массива!";
    }
};

class bad_length : public exception
{
public:
    virtual const char* what() const noexcept override
    {
        return "ERROR: Предоставили неверную длинну массива!";
    }
};


IntArray::IntArray() = default;

IntArray::IntArray(int length) : m_length(length)
{
    if (length < 0) {
        throw bad_length();
    }
    m_data = new int[length] {};
        cout << "array constructed" << endl;
}

IntArray::~IntArray()
    {
        delete[] m_data;
        cout << "array distructed" << endl;
    }

    void IntArray:: erase() // очистка обьекта
    {
        delete[] m_data;
        m_data = nullptr;
        m_length = 0;
        cout << "Массив очищен" << endl;
    }

    int& IntArray:: operator[](const int& index)
    {
        if (index <= 0 && index > m_length) {
            throw bad_range();
        }
        return m_data[index];
    }

    void IntArray::resize(int newLength)
    {
        if (newLength == m_length)
            return;

        if (newLength <= 0)
        {
            erase();
            return;
        }

        int* data{ new int[newLength] };

        if (m_length > 0)
        {
            int elementsToCopy{ (newLength > m_length) ? m_length : newLength };

            for (int index = 0; index < elementsToCopy; ++index)
                data[index] = m_data[index];
        }

        delete[] m_data;
        m_data = data;
        m_length = newLength;
        cout << "Размер массива изменен на: " << newLength << endl;
    }

    void IntArray::insertBefore(int value, int index)
    {
        if (index < 0 || index > m_length) {
            throw bad_range();
        }

        int* data{ new int[m_length + 1] };

        // Копируем все элементы до индекса
        for (int i = 0; i < index; ++i)
            data[i] = m_data[i];
            data[index] = value;

        for (int i = index; i < m_length; ++i)
            data[i + 1] = m_data[i];

        delete[] m_data;
        m_data = data;
        ++m_length;
    }

    void IntArray::insertAtBegin(int value) {
        insertBefore(value, 0);
    }
    void IntArray::insertAtEnd(int value) { 
        insertBefore(value, m_length);
    }

    int IntArray::getLength() const { return m_length; }

    void IntArray::ShowArray() {

        cout << "Элементы массива: ";

        for (int i = 0; i < m_length; ++i) {
            if (i != m_length - 1) {
                cout << m_data[i] << " ";
            }
            else { cout << m_data[i]; }
        }
        cout <<  "." << endl;
    }
