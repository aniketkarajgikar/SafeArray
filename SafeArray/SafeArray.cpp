// SafeArray.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include"SafeArray.h"

std::ostream& operator<<(std::ostream& os, const SafeArray& s)
{
	os << "[";
	for (int i = 0; i < s.get_msize(); i++)
	{
		os << s[i] << " ";
	}
	os << "]";
	return os;
}

int main()
{
	try
	{
		std::cout << "Hello World!\n" << std::endl;
		SafeArray s1{};
		std::cout << s1.get_msize() << std::endl;
		SafeArray s2{ 4 };
		std::cout << s2.get_msize() << std::endl;
		for (int i = 0; i < s2.get_msize(); i++)
		{
			s2[i] = i * 10;
		}
		for (int i = 0; i < s2.get_msize(); i++)
		{
			std::cout << s2[i] << " ";
		}
		std::cout << "\ns2: " << s2;
		std::cout << "\ncalling Copy constructor\n";
		SafeArray s3 = s2;
		s3[1] = 1500;
		std::cout << "\n" << "s2: " << s2;
		std::cout << "\n" << "s3: " << s3<<std::endl;
		int index{};
		std::cout << "\nPlease enter an array index: ";
		std::cin >> index;
		std::cout << "The element at index " << index << " is " << s2[index] << std::endl;
	}
	catch (const IndexOutOfBoundsException & e)
	{
		std::cout << "Invalid array index" << std::endl;
	}

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
