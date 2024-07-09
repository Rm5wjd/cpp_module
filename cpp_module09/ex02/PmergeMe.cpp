#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
	this->jacobstal_num[0] = 0;
	this->jacobstal_num[1] = 1;
	this->jacobstal_num[2] = 2;

	for (int i = 3; i < 20; i++)
	{
		jacobstal_num[i] = jacobstal_num[i - 1] + (2 * jacobstal_num[i - 2]);
	}
}

PmergeMe::PmergeMe(const PmergeMe& origin)
{
	*this = origin;
}

PmergeMe& PmergeMe::operator= (const PmergeMe& origin)
{
	for (int i = 0; i < 20; i++) {
		this->jacobstal_num[i] = origin.jacobstal_num[i];
	}

	return *this;
}

PmergeMe::~PmergeMe()
{

}

void PmergeMe::sort(std::vector<int> &arr)
{
	std::vector< std::pair<int, int> > chain;
	int last_num = -1;

	if (arr.size() % 2 != 0) {
		last_num = arr.back();
		arr.pop_back();
	}

	for (size_t i = 0; i < arr.size() - 1; i += 2)
	{
		std::pair<int, int> elem = std::make_pair(std::max(arr[i], arr[i + 1]), \
									std::min(arr[i], arr[i + 1]));
		chain.push_back(elem);
	}

	arr = ford_johnson(chain);

	if (last_num != -1) {
		int last_idx = this->binary_search(arr, last_num, arr.size() - 1);
		arr.insert(arr.begin() + last_idx, 1, last_num);
	}
}

void PmergeMe::sort(std::deque<int> &arr)
{
	std::deque< std::pair<int, int> > chain;
	int last_num = -1;

	if (arr.size() % 2 != 0) {
		last_num = arr.back();
		arr.pop_back();
	}

	for (size_t i = 0; i < arr.size() - 1; i += 2)
	{
		std::pair<int, int> elem = std::make_pair(std::max(arr[i], arr[i + 1]), \
									std::min(arr[i], arr[i + 1]));
		chain.push_back(elem);
	}

	arr = ford_johnson(chain);

	if (last_num != -1) {
		int last_idx = this->binary_search(arr, last_num, arr.size() - 1);
		arr.insert(arr.begin() + last_idx, 1, last_num);
	}
}

std::vector<int> PmergeMe::ford_johnson(std::vector< std::pair<int, int> > &arr)
{
	int last_num = -1;
	std::vector<int> main_chain;

	for (size_t i = 0; i < arr.size(); i++)
	{
		main_chain.push_back(arr[i].first);
	}

	// return 조건
	if (main_chain.size() == 1) {
		main_chain.insert(main_chain.begin(), 1, arr[0].second);
		return main_chain;
	}

	if (main_chain.size() % 2 != 0) {
		last_num = main_chain.back();
		main_chain.pop_back();
	}

	std::vector< std::pair<int, int> > new_arr;

	for (size_t i = 0; i < arr.size() - 1; i += 2)
	{
		std::pair<int, int> elem = std::make_pair(std::max(main_chain[i], main_chain[i + 1]), \
									std::min(main_chain[i], main_chain[i + 1]));
		new_arr.push_back(elem);
	}

	// recursion!
	main_chain = ford_johnson(new_arr);

	// sub_chain 복원
	if (last_num != -1)
	{
		int last_idx = this->binary_search(main_chain, last_num, main_chain.size() - 1);
		main_chain.insert(main_chain.begin() + last_idx, 1, last_num);
	}
	for (size_t i = 0; i < main_chain.size(); i++)
	{
		for (size_t j = i; j < arr.size(); j++)
		{
			if (main_chain[i] == arr[j].first) {
				if (i != j)
					std::swap(arr[i], arr[j]);
				else
					break;
			}
		}
	}

	// insertion
	this->insertion(main_chain, arr);

	// 정렬된 main_chain 리턴
	return main_chain;
}

std::deque<int> PmergeMe::ford_johnson(std::deque< std::pair<int, int> > &arr)
{
	int last_num = -1;
	std::deque<int> main_chain;

	for (size_t i = 0; i < arr.size(); i++)
	{
		main_chain.push_back(arr[i].first);
	}

	// return 조건
	if (main_chain.size() == 1) {
		main_chain.insert(main_chain.begin(), 1, arr[0].second);
		return main_chain;
	}

	if (main_chain.size() % 2 != 0) {
		last_num = main_chain.back();
		main_chain.pop_back();
	}

	std::deque< std::pair<int, int> > new_arr;

	for (size_t i = 0; i < arr.size() - 1; i += 2)
	{
		std::pair<int, int> elem = std::make_pair(std::max(main_chain[i], main_chain[i + 1]), \
									std::min(main_chain[i], main_chain[i + 1]));
		new_arr.push_back(elem);
	}

	// recursion!
	main_chain = ford_johnson(new_arr);

	// sub_chain 복원
	if (last_num != -1)
	{
		int last_idx = this->binary_search(main_chain, last_num, main_chain.size() - 1);
		main_chain.insert(main_chain.begin() + last_idx, 1, last_num);
	}
	for (size_t i = 0; i < main_chain.size(); i++)
	{
		for (size_t j = i; j < arr.size(); j++)
		{
			if (main_chain[i] == arr[j].first) {
				if (i != j)
					std::swap(arr[i], arr[j]);
				else
					break;
			}
		}
	}

	// insertion
	this->insertion(main_chain, arr);

	// 정렬된 main_chain 리턴
	return main_chain;
}

int PmergeMe::binary_search(std::vector<int> main_chain, int target, int search_idx)
{
	int left = 0;
	int right =  search_idx;
	int mid;
	
	bool lt_flag;
	bool gt_flag;

	while (left <= right)
	{
		mid = (left + right) / 2;
		
		if (main_chain[mid] < target) {
			left = mid + 1;
			gt_flag = true;
			lt_flag = false;
		}
		else {
			right = mid - 1;
			lt_flag = true;
			gt_flag = false;
		}
	}

	if (gt_flag){
		mid++;
	}
	//else {
	//	if (mid > 0)
	//		mid--;
	//}

	return mid;
}

int PmergeMe::binary_search(std::deque<int> main_chain, int target, int search_idx)
{
	int left = 0;
	int right =  search_idx;
	int mid;
	
	bool lt_flag;
	bool gt_flag;

	while (left <= right)
	{
		mid = (left + right) / 2;
		
		if (main_chain[mid] < target) {
			left = mid + 1;
			gt_flag = true;
			lt_flag = false;
		}
		else {
			right = mid - 1;
			lt_flag = true;
			gt_flag = false;
		}
	}

	if (gt_flag){
		mid++;
	}
	//else {
	//	if (mid > 0)
	//		mid--;
	//}

	return mid;
}

void PmergeMe::insertion(std::vector<int>& main_chain, std::vector< std::pair<int, int> >& arr)
{
	// insertion
	int next;
	int prev_jacob = -1;
	int jacob_idx = 2;
	int search_idx;
	int size = arr.size();
	int j = 0;

	while (j < size)
	{
		next = jacobstal_num[jacob_idx] - 1;
		if (next >= size) {
			next = size - 1;
		}

		while (next > prev_jacob)
		{
			int target = arr[next].second;

			for (size_t i = 0; i < main_chain.size(); i++) {
				if (main_chain[i] == arr[next].first) {
					search_idx = i - 1;
					break;
				}
			}
			
			//std::cout << "target: " << target << ", search_idx: " << search_idx << ", next: " << next << std::endl;
			if (search_idx == -1) {
				main_chain.insert(main_chain.begin(), 1, target);
			}
			
			else {
				int des_idx = binary_search(main_chain, target, search_idx);
			
				//std::cout << "des_idx: " << des_idx << std::endl;
				main_chain.insert(main_chain.begin() + des_idx, 1, target);
			}

			next--;
			j++;
			//std::cout << "[ ";
			//for (int i = 0; i < main_chain.size(); i++) {
			//	std::cout << main_chain[i] << ", ";
			//}
			//std::cout << " ]" << std::endl;
		}
		
		prev_jacob = jacobstal_num[jacob_idx] - 1;
		jacob_idx++;
	}
}

void PmergeMe::insertion(std::deque<int>& main_chain, std::deque< std::pair<int, int> >& arr)
{
	// insertion
	int next;
	int prev_jacob = -1;
	int jacob_idx = 2;
	int search_idx;
	int size = arr.size();
	int j = 0;

	while (j < size)
	{
		next = jacobstal_num[jacob_idx] - 1;
		if (next >= size) {
			next = size - 1;
		}

		while (next > prev_jacob)
		{
			int target = arr[next].second;

			for (size_t i = 0; i < main_chain.size(); i++) {
				if (main_chain[i] == arr[next].first) {
					search_idx = i - 1;
					break;
				}
			}
			
			//std::cout << "target: " << target << ", search_idx: " << search_idx << ", next: " << next << std::endl;
			if (search_idx == -1) {
				main_chain.insert(main_chain.begin(), 1, target);
			}
			
			else {
				int des_idx = binary_search(main_chain, target, search_idx);
			
				//std::cout << "des_idx: " << des_idx << std::endl;
				main_chain.insert(main_chain.begin() + des_idx, 1, target);
			}

			next--;
			j++;
			//std::cout << "[ ";
			//for (int i = 0; i < main_chain.size(); i++) {
			//	std::cout << main_chain[i] << ", ";
			//}
			//std::cout << " ]" << std::endl;
		}
		
		prev_jacob = jacobstal_num[jacob_idx] - 1;
		jacob_idx++;
	}
}