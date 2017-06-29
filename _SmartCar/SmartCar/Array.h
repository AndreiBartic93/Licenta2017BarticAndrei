#ifndef ARRAY_H
#define ARRAY_H

#include <Arduino.h>

template <typename T>
class Array
{
	T* m_array;
	byte m_size;
	byte m_maxCapacity;

public:
	Array(byte maxSize);
	~Array();

	void add(T obj);
	void remove(T obj);
	byte size();
	byte find(T obj);
	void clear();
	T* get(byte poz);
	byte getSize();
	void reset();
};



template <typename T>
Array<T>::Array(byte maxSize)
	: m_array(NULL),
	m_maxCapacity(maxSize),
	m_size(0)
{
	m_array = new T[m_maxCapacity];
}

template <typename T>
Array<T>::~Array()
{
	m_size = 0;
	delete[] m_array;
}

template <typename T>
void Array<T>::remove(T obj)
{
	byte index = find(obj);

	while (index != m_maxCapacity)
	{
		for (byte i = index; i < m_size - 1; i++)
		{
			m_array[i] = m_array[i + 1];
		}

		m_size--;

		index = find(obj);
	}
}


template <typename T>
void Array<T>::add(T obj)
{
	if (m_size < m_maxCapacity)
	{
		m_array[m_size] = obj;
		m_size++;
	}
}



template <typename T>
byte Array<T>::find(T obj)
{
	byte index = m_maxCapacity;

	if (m_array != NULL)
	{
		for (byte i = 0; i < m_size; i++)
		{
			if (m_array[i] == obj)
			{
				index = i;
				break;
			}
		}
	}

	return index;
}


template <typename T>
byte Array<T>::size()
{
	return m_size;
}


template <typename T>
void Array<T>::clear()
{
	m_size = 0;
}

template <typename T>
T* Array<T>::get(byte poz)
{
	T* retEl = NULL;

	if (poz < m_maxCapacity && poz >= 0)
	{
		retEl = &m_array[poz];
	}
	return retEl;
}

template <typename T>
byte Array<T>::getSize()
{
	return m_size;
}

template <typename T>
void Array<T>::reset()
{
	for (int i = 0; i, m_size; i++){
		m_array[i] = 0;
	}
}

#endif