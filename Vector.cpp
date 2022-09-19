

// To include this header file in some other .cpp file use #include "vector.h"

template <typename T> // We have generalize the datatype of our vector

class Vector
{

	int cs;
	int ms;
	T *arr;

public:
	Vector()
	{
		cs = 0;
		ms = 1;
		arr = new T[ms];
	}

	void push_back(T d)
	{
		if (cs == ms)
		{
			// Old Array is full
			T *oldArr = arr;
			arr = new T[2 * ms];
			ms = 2 * ms;
			for (int i = 0; i < cs; i++)
			{
				arr[i] = oldArr[i];
			}
			// Delete the old array
			delete[] oldArr;
		}
		arr[cs] = d;
		cs++;
	}

	void pop_back()
	{
		cs--;
	}

	T front()
	{
		return arr[0];
	}

	T back()
	{
		return arr[cs - 1];
	}

	T capacity()
	{
		return ms;
	}

	T size()
	{
		return cs;
	}
	bool empty()
	{
		return cs == 0;
	}

	T operator[](int i)
	{
		return arr[i];
	}
};
