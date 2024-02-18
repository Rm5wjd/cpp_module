# ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <algorithm>
#include <iterator>
#include <list>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack()
			: std::stack<T>()
		{}
		MutantStack(const MutantStack& origin)
		{
			*this = origin;
		}
		MutantStack& operator= (const MutantStack& origin)
		{
			this->c = origin.c;

			return *this;
		}
		~MutantStack()
		{}

	public:
		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator begin() { return this->c.begin(); }
		iterator end() { return this->c.end(); }
		typename std::stack<T>::container_type::reference top()
		{
			if (this->c.size() == 0)
				throw std::runtime_error("stack is empty");

			return this->c.back();
		}

		void pop()
		{
			if (this->c.size() == 0)
				throw std::runtime_error("stack is empty");

			this->c.pop_back();
		}
};

# endif