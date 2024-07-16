#include "PmergeMe.hpp"
#include <algorithm> // delete 삭제 임시 tmp temp
#include <ctime>

int main(int argc, char *argv[])
{
	PmergeMe pmergeme;
	int num;

	if (argc == 1) {
		std::cout << "Error" << std::endl;
		return 1;
	}

	std::vector<t_valAndIdx> arr_vec;
	std::deque<t_valAndIdx> arr_deque;
	std::vector<int> to_compare;

	for (int i = 0; i < argc; i++)
	{
		if (i + 1 == argc)
			break;
		
		num = std::atoi(argv[i + 1]);
		if (num < 0) {
			std::cout << "Error" << std::endl;
			return 1;
		}
		t_valAndIdx elem = {num, i};
		arr_vec.push_back(elem);
		arr_deque.push_back(elem);
		to_compare.push_back(num);
	}

	std::cout << "Before: ";
	for (size_t i = 0; i < arr_vec.size(); i++)
	{
		std::cout << arr_vec[i].value << " ";
	}
	std::cout << std::endl;

	clock_t vec_start = std::clock();
	pmergeme.sort(arr_vec);
	clock_t vec_end = std::clock();

	clock_t deque_start = std::clock();
	pmergeme.sort(arr_deque);
	clock_t deque_end = std::clock();

	std::sort(to_compare.begin(), to_compare.end());
	
	std::cout << "After:  ";
	for (size_t i = 0; i < arr_vec.size(); i++)
		std::cout << arr_vec[i].value << " ";
	std::cout << std::endl;

	clock_t vec_exec_time = vec_end - vec_start;
	double vec_time = ((double)vec_exec_time / CLOCKS_PER_SEC);
	std::cout << "Time to process a range of " << argc - 1 << " elements with std::vector : " << vec_time << " us" << std::endl;

	clock_t deque_exec_time = deque_end - deque_start;
	double deque_time = ((double)deque_exec_time / CLOCKS_PER_SEC);
	std::cout << "Time to process a range of " << argc - 1 << " elements with std::deque : " << deque_time << " us" << std::endl;

	for (size_t i = 0; i < arr_vec.size(); i++) {
		if (arr_vec[i].value != to_compare[i] || arr_deque[i].value != to_compare[i]) {
			printf("ERROR\n");
			printf("vec_index: %lu\n", i);
			printf("value: %d %d\n", arr_vec[i].value, to_compare[i]);
			return 1;
		}
	}
}
