#pragma once
#include <exception>
#include <string>
#include <stdio.h>

char * messages[3] = { "Failed To Allocate Memory", "Index Out of Bounds", "Container is Empty" };

class MyException : public std::exception
{
public:
	MyException();
	MyException(int index);
	MyException(char * error);
	virtual const char * what() const override;
protected:
private:
	char * error;
};
MyException::MyException()
{
	error = nullptr;
}
MyException::MyException(int index)
{
	if (index >= 0 && index< 3) { error = messages[index]; }
	else { error = nullptr; }
	
}
MyException::MyException(char * error) : exception()
{
	this->error = error;
}

const char * MyException::what() const throw()
{
	return (error == nullptr ? "Unknown Exception" : error);
}

