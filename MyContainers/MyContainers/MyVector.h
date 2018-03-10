#pragma once
#include <exception>
#include <iostream>
//enumerator for allocation direction
enum  AllocationDirection{ shrink = -1, expand = 1 };

template<class T>
class MyVector
{
public:
	//MyArray();
	MyVector(int buffer = 100);	//constructor with default buffer size
	~MyVector();				//destructor


	void Insert(T value, int place = 0);	//insertion
	void Delete(int place = 0);				//deletion

	T Get(int place = 0);					//get value at index location
	bool Find(T value);						//return true if value is found
	int FindIndex(T value);					//return index if value is found
	void TestPrint();						//prints all data

private:

	int buffer;			//buffer size for allocation
	int maxSize;		//currently allocated space
	int currentSize;	//currently used space
	T * data;			//data

	void CopyData(T * to, T * from, int size);			//copies data from one array to the other
	void AllocateMemory(AllocationDirection direction);	//allocates new space for expanding array

};

template<class T>
inline MyVector<T>::MyVector(int buffer)
{
	this->buffer = buffer;
	maxSize = buffer;
	data = new T[buffer];
	currentSize = 0;
}

template<class T>
inline MyVector<T>::~MyVector()
{
	delete[] data;
}
//adds value by index
template<class T>
inline void MyVector<T>::Insert(T value, int place)
{
	if (place < 0 || place > currentSize) { throw MyException(1); }
	
	try 
	{
		++currentSize;
		if (currentSize == maxSize) { AllocateMemory(AllocationDirection::expand); }

		for (int i = currentSize; i >= place + 1; --i)
		{
			data[i] = data[i - 1];
		}
		data[place] = value;	
	}
	catch (std::bad_alloc &ex) { --currentSize; throw; }
	catch (std::exception &ex) { throw; }
}
//deletes value by index
template<class T>
inline void MyVector<T>::Delete(int place)
{
	if (place < 0 || place >= currentSize) { throw MyException(1); return; }
	if (currentSize == 0) { throw MyException(2); return; }

		try 
		{
			for (int i = place; i<currentSize; ++i)
			{
				data[i] = data[i + 1];
			}
			--currentSize;
			if (maxSize-currentSize >= buffer) 
			{ 
				AllocateMemory(AllocationDirection::shrink);
			}
		}
		catch (std::exception &ex) { throw; }

}
//returns value by index
template<class T>
inline T MyVector<T>::Get(int place)
{
	if (place < 0 || place > currentSize) { throw MyException(1); }
	return data[place];
}

//checks if element exist in array,if it is returns true 
template<class T>
inline bool MyVector<T>::Find(T value)
{
	for (int i = 0; i < currentSize; ++i)
	{
		if (data[i] == value)
		{
			return true;
		}
	}
	return false;
}

//finds index by value
template<class T>
inline int MyVector<T>::FindIndex(T value)
{
	for (int i = 0; i < currentSize; ++i)
	{
		if (data[i] == value)
		{
			return i;
		}
	}
	return -1;
}

//test function that prints all contents
template<class T>
inline void MyVector<T>::TestPrint()
{
	for (int i = 0; i < currentSize; ++i)
	{
		std::cout << data[i] << " ";
	}
	std::cout<<std::endl;
}


//copies information from 2 different arrays
template<class T>
inline void MyVector<T>::CopyData(T * to, T * from, int size)
{
	for (int i = 0; i < size; ++i)
	{
		to[i] = from[i];
	}
}

//memory allocation and data transfer
//note: information from temporaryData needs to be transfered to Data, 
//repointing couses crashes, or does not allow to free before allocated memory for Data
template<class T>
inline void MyVector<T>::AllocateMemory(AllocationDirection direction)
{
	//std::cout << "allocator being called, direection:" << direction << std::endl;
	try 
	{
		int min = ((maxSize >= maxSize + (direction*buffer)) ? (maxSize + (direction*buffer)) : (maxSize));
		T * temporaryData;

		temporaryData = new T[maxSize + (direction*buffer)];
		CopyData(temporaryData, data, min);
		delete[] data;

		
		try
		{
			data = new T[maxSize + (direction*buffer)];
			CopyData(data, temporaryData, maxSize + (direction*buffer));
			delete[]temporaryData;
		}
		catch (std::exception &ex) { data = temporaryData;  throw; }

		maxSize += (direction*buffer);
	}
	catch (std::exception &ex) { throw; }

}