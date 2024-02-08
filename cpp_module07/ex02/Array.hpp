# ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <stdexcept>

template <typename T>
class Array
{
	private:
		T* arr;
		int length;

	public:
		Array() : arr(new T[0]), length(0)
		{}

		Array(unsigned int n)
		{
			arr = new T[n];
			length = n;

			for (int i = 0; i < length; i++)
				arr[i] = 0;
		}

		Array(const Array& origin)
		{
			length = origin.length;
			arr = new T[length];
			for (int i = 0; i < length; i++)
				arr[i] = origin.arr[i];
		}
		
		Array& operator= (const Array& origin)
		{
			if (arr)
				delete[] arr;

			length = origin.length;
			arr = new T[length];
			for (int i = 0; i < length; i++)
				arr[i] = origin.arr[i];
		}

		T& operator[] (int idx) {
			if (idx < 0 || length <= idx)
				throw std::out_of_range("idx out of range");
			return arr[idx];
		}

		T operator[] (int idx) const {
			if (idx < 0 || length <= idx)
				throw std::out_of_range("idx out of range");
			return arr[idx];
		}

		int size() const {
			return length;
		}

		~Array()
		{
			delete[] arr;
		}
};


# endif