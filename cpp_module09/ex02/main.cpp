#include "PmergeMe.hpp"

int jacobstal_num[100] = {0, 1, 1};

void make_jacobs_num();
int binary_search(std::vector<int> main_chain, int target, int search_idx);

int main(int argc, char *argv[])
{
	std::vector<std::pair<int, int>> vec;

	if (argc == 1) {
		std::cout << "Error" << std::endl;
		return 1;
	}

	int *arr = new int[argc];

	for (int i = 1; i < argc; i++)
	{
		arr[i] = std::atoi(argv[i]);
	}

	make_jacobs_num();
}

std::vector<int> ford_johnson(std::vector<std::pair<int, int>> arr, std::vector<std::pair<int, int>> mov_info)
{
	int last_num;
	std::vector<int> main_chain;

	for (int i = 0; i < arr.size(); i++)
	{
		main_chain.push_back(arr[i].first);
	}

	// return 조건
	if (main_chain.size() == 1) {
		return main_chain;
	}

	if (main_chain.size() % 2 != 0) {
		last_num = main_chain.back();
		main_chain.pop_back();
	}

	std::vector<std::pair<int, int>> new_arr;

	for (int i = 0; i < arr.size() - 1; i += 2)
	{
		std::pair<int, int> elem = {std::max(main_chain[i], main_chain[i + 1]), \
									std::min(main_chain[i], main_chain[i + 1])};
		new_arr.push_back(elem);
	}
	
	// 재귀 들어가기 전 index 정보 담기
	for (int i = 0; i < new_arr.size(); i++)
	{
		mov_info.push_back(std::make_pair(new_arr[i].first, i));
	}

	// recursion!
	main_chain = ford_johnson(new_arr, mov_info);

	// sub_chain 복원
	for (int i = 0; i < mov_info.size(); i++)
	{
		std::swap(new_arr[mov_info[i].first], new_arr[mov_info[i].second]);
	}

	// insertion
	int next;
	int prev_jacob = 0;
	int jacob_idx = 2;
	int search_idx;
	int size = new_arr.size();
	int j = 0;

	while (j <= size)
	{
		next = jacobstal_num[jacob_idx];
		int target = new_arr[next].second;

		while (next > prev_jacob)
		{
			for (int i = 0; i < main_chain.size(); i++) {
				if (main_chain[i] == new_arr[next].first) {
					search_idx = i - 1;
					break;
				}
			}

			int des_idx = binary_search(main_chain, target, search_idx);
			main_chain.insert(main_chain.begin() + des_idx, 1, target);

			next--;
			j++;
		}
		
		prev_jacob = jacobstal_num[jacob_idx];
		jacob_idx++;
	}

	// 리턴 전에 바뀐 인덱스 정보 담기
}

void make_jacobs_num()
{
	for (int i = 3; i < 100; i++)
	{
		jacobstal_num[i] = jacobstal_num[i - 1] + (2 * jacobstal_num[i - 2]);
	}
}

int binary_search(std::vector<int> main_chain, int target, int search_idx)
{
	int left = 0;
	int right =  search_idx;
	int mid;

	while (left <= right)
	{
		mid = (left + right) / 2;
		
		if (main_chain[mid] < target) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}

	return mid;
}