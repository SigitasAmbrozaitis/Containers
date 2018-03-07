#include <iostream>
#include <string>
#include "MyException.h"
int main()
{
    std::string er("a");
	std::cout << er << std::endl;
	try
	{
		throw MyException("Pisk nx");
	}
	catch (MyException ex)
	{
		std::cout << ex.what() << std::endl;
	}

}
