#include "MutantStack.hpp"

int main()
{
	MutantStack<int> mstack;
	//std::list<int> mstack;
	//mstack.top();
	//mstack.pop();
	mstack.push(5);
	mstack.push(17);

	std::cout << "mstack top: " << mstack.top() << std::endl;

	mstack.pop(); // delete 17

	std::cout << "mstack size: " << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	
	++it;
	--it;
	while (it != ite)
	{
		std::cout << "value: " << *it << std::endl;
		++it;
	}

	std::stack<int> sss(mstack);

	MutantStack<int> s(mstack);

	MutantStack<int>::iterator copy_it = s.begin();
	MutantStack<int>::iterator copy_ite = s.end();
	
	++copy_it;
	--copy_it;
	while (copy_it != copy_ite)
	{
		std::cout << "copy value: " << *copy_it << std::endl;
		++copy_it;
	}

	return 0;
}

// --------------------------------------------------------------------------------------------------------------------------------------------------


//int main()
//{
//	//MutantStack<int> mstack;
//	std::list<int> mstack;

//	mstack.push_back(5);
//	mstack.push_back(17);

//	std::cout << "mstack top: " << mstack.back() << std::endl;

//	mstack.pop_back(); // delete 17

//	std::cout << "mstack size: " << mstack.size() << std::endl;

//	mstack.push_back(3);
//	mstack.push_back(5);
//	mstack.push_back(737);
//	//[...]
//	mstack.push_back(0);

//	std::list<int>::iterator it = mstack.begin();
//	std::list<int>::iterator ite = mstack.end();
	
//	++it;
//	--it;
//	while (it != ite)
//	{
//		std::cout << "value: " << *it << std::endl;
//		++it;
//	}

//	//std::stack<int> s(mstack);

//	//std::list<int>::iterator copy_it = mstack.begin();
//	//std::list<int>::iterator copy_ite = mstack.end();
	
//	//++copy_it;
//	//--copy_it;
//	//while (copy_it != copy_ite)
//	//{
//	//	std::cout << "copy value: " << *copy_it << std::endl;
//	//	++copy_it;
//	//}

//	return 0;
//}