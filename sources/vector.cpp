#include <algorithm>
#include <cassert>

#include "vector.hpp"

vector_t::vector_t()
{
elements_ = nullptr;
size_ = 0;
capacity_ = 0;
}

vector_t::vector_t(vector_t const & other)
{
elements_ = new int [other.capacity()];
for (int i = 0; i < other.size(); ++i)
	{
	elements_[i] = other.elements_[i];
	}
size_ = other.size();
capacity_ = other.capacity();
}

vector_t & vector_t::operator = (vector_t const & other)
{ 
if (&other != this)
	{
	delete[] elements_;
	size_ = other.size_;
	capacity_ = other.capacity_;
	elements_ = new int [capacity_];
	for (unsigned int i = 0; i < size_; i++)
	elements_[i] = other.elements_[i];
	}
return *this;
}

bool vector_t::operator == (vector_t const & other) const
{	
if (size_ != other.size() || capacity_ != other.capacity())
	{
	return false;
	}
for (int i = 0; i < capacity_; i++)
	{
	if(elements_[i] != other.elements_[i]) return false;
	}
return true;
}

vector_t::~vector_t()
{
delete[] elements_;
}

std::size_t vector_t::size() const
{
return size_;
}

std::size_t vector_t::capacity() const
{
return capacity_;
}

void vector_t::push_back(int value)
{
if (!elements_)
	{
	size_ = 1;
	capacity_ = 1;
	elements_ = new int[capacity_];
	elements_[0] = value;
	}
else
	{
	int *v = new int[capacity_];
	for (int i = 0; i < size_; ++i)
		{
		v[i] = elements_[i];
		}
	delete[] elements_;
	if (size_ == capacity_)
		{
		capacity_ *= 2;
		}
	size_++;

	elements_ = new int[capacity_];
	for (int i = 0; i < size_; ++i)
		{
		if( i != size_-1) elements_[i] = v[i];
		else elements_[i] = value;
		}
	}
}

void vector_t::pop_back()
{
if (size_ == 0)
	{
	return;
	}
size_--;
if (size_ <= (capacity_ / 4))
	{
	capacity_ = capacity_ / 2;
	int *elements = new int[capacity_];
	for (int i; i<size_; i++)
		{
		elements[i] = elements_[i];
		}

	if (elements_ != nullptr)
		{
		delete[] elements_;
		}
	elements_ = elements;
	}
}

int & vector_t::operator [](std::size_t index)
{
return elements_[index];
}

int vector_t::operator [](std::size_t index) const
{
return elements_[index];
}

bool operator != (vector_t const & lhs, vector_t const & rhs)
{
if (rhs.size() != lhs.size())
	{
	return true;
	}
for (int i = 0; i < rhs.size(); i++)
	{
	if (lhs.elements_[i] != rhs.elements_[i])
		{
		return true;
		}
	}
return false;
}
