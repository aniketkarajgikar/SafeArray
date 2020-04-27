#pragma once
class IndexOutOfBoundsException {};

class SafeArray
{
private:
	int* m_ptr{ nullptr };
	int m_size{ 0 };
public:
	SafeArray() = default;

	explicit SafeArray(int size)
	{
		if (size > 0)
		{
			std::cout << "Calling explicit constructor" << std::endl;
			m_ptr = new int[size] {};
			m_size = size;
		}
	}

	SafeArray(const SafeArray& src)	//Copy Constructor
	{
		if (src.get_msize() > 0)
		{
			m_size = src.get_msize();
			m_ptr = new int[m_size] {};

			for (int i = 0; i < m_size; i++)
			{
				m_ptr[i] = src[i];
			}
		}
	}

	int get_msize() const
	{
		return m_size;
	}

	bool IsValidIndex(int index) const
	{
		return (index >= 0) && (index < m_size);
	}

	int& operator[](int index)
	{
		//std::cout << "With ref got called";
		if (!IsValidIndex(index))
		{
			throw IndexOutOfBoundsException{};
		}
		return m_ptr[index];
	}

	int operator[](int index) const //there is a role, if we send class object with const reference, then it will use this method.
	{
		//std::cout << "Without ref got called";
		if (!IsValidIndex(index))
		{
			throw IndexOutOfBoundsException{};
		}
		return m_ptr[index];
	}

	~SafeArray()
	{
		delete[] m_ptr;
	}
};
