#pragma once

class IntArray
{
private:
    int m_length;
    int* m_data;

public:
    IntArray();

    IntArray(int length);
    ~IntArray();

    void erase();

    int& operator[](const int& index);

    void reallocate(int newLength);

   void resize(int newLength);

    void insertBefore(int value, int index);
  
    void insertAtBegin(int value);

    void insertAtEnd(int value);

    int getLength() const;

    void ShowArray();
};

