#pragma once
#include "lock.h"

template<class T>
class Speedlist {
private:
	LSECT _lock;
	int _size = 0;
public:
	T* _data = nullptr;

	Speedlist<T>()
	{
		_lock = lock_new();
	}

	void lock() {
		lock_lock(_lock);
	}

	void unlock() {
		lock_unlock(_lock);
	}

	void clear() {
		free(_data);
		_data = nullptr;
		_size = 0;
	}

	void push(T element)
	{
		lock();
		if (_size == 0)
			_data = (T*)malloc(sizeof(T));
		else
			_data = (T*)realloc(_data, (_size + 1) * sizeof(T));
		_data[_size] = element;
		_size++;
		unlock();
	}

	void pop(T element)
	{
		lock();
		T *newArray = (T*)malloc((_size - 1) * sizeof(T));
		int newI = 0;
		for (int i = 0; i < _size; i++)
			if (_data[i] != element) {
				newArray[newI] = _data[i];
				newI++;
			}
		free(_data);
		_data = newArray;
		_size--;
		unlock();
	}

	T& operator [] (int i)
	{
		return _data[i];
	}
	
	int size() {
		return _size;
	}
};