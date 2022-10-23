#include <iostream>
#include "IntArray.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "");

	int length = 10;
	
	try
	{
		IntArray s_array(length);

		for (int i = 0; i < length; ++i) {
			s_array[i] = i;
		}
		s_array.resize(7);
		s_array.insertBefore(20, 5);
		s_array.insertAtEnd(30);
		s_array.insertAtBegin(40);
		s_array.ShowArray();
			cout << "Размер массива: " << s_array.getLength() << endl;
	}
	
	catch (exception& e) {
		cout << e.what();
	}

	return 0;
}
