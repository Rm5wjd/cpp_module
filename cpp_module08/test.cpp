#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

int main()
{
	std::srand(unsigned(std::time(0)));
	std::vector<int> v;
	v.push_back(0);
	std::fill(v.begin(), v.begin() + 5, 0);
	std::generate(v.begin(), v.begin() + 5, std::rand);
	std::cout << v.size() << std::endl;
	std::cout << *(v.begin() + 2) << std::endl;
	std::cout << *(v.end() - 1) << std::endl << std::endl;
	for (int i = 0; i < 7; i++)
		std::cout << v[i] << std::endl;
}