#include "PmergeMe.hpp"

static t_vec_chain split_vector(std::vector<t_valAndIdx> &arr);
static void make_main_chain(std::vector<t_valAndIdx>& main_chain, const t_vec_chain &chain);
static void restore_sub_chain(std::vector<t_valAndIdx>& main_chain, t_vec_chain& new_chain, const t_vec_chain &chain);

static t_deque_chain split_deque(std::deque<t_valAndIdx> &arr);
static void make_main_chain(std::deque<t_valAndIdx>& main_chain, const t_deque_chain &chain);
static void restore_sub_chain(std::deque<t_valAndIdx>& main_chain, t_deque_chain& new_chain, const t_deque_chain &chain);


PmergeMe::PmergeMe()
{
	this->jacobstal_num[0] = 0;
	this->jacobstal_num[1] = 1;
	this->jacobstal_num[2] = 1;

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

#pragma region vector_sort
void PmergeMe::sort(std::vector<t_valAndIdx> &arr)
{
	t_vec_chain chain = split_vector(arr);
	t_valAndIdx last_num = { -1, -1 };

	if (arr.size() % 2 != 0) {
		last_num = arr.back();
		arr.pop_back();
	}

	arr = ford_johnson(chain);

	insertion_odd_num(arr, last_num);
}

std::vector<t_valAndIdx> PmergeMe::ford_johnson(const t_vec_chain &chain)
{
	t_valAndIdx last_num = {-1, -1};
	std::vector<t_valAndIdx> main_chain;
	
	make_main_chain(main_chain, chain);

	// base case
	if (main_chain.size() == 1) {
		main_chain[0] = chain[0].second;
		main_chain.push_back(chain[0].first);
		return main_chain;
	}

	if (main_chain.size() % 2 != 0) {
		last_num = main_chain.back();
		main_chain.pop_back();
	}

	t_vec_chain new_chain = split_vector(main_chain);

	// recursion!
	main_chain = ford_johnson(new_chain);

	// odd comeback
	insertion_odd_num(main_chain, last_num);

	// sub_chain restore
	restore_sub_chain(main_chain, new_chain, chain);

	// insertion
	this->insertion(main_chain, new_chain);

	// 정렬된 main_chain 리턴
	return main_chain;
}

int PmergeMe::binary_search(const std::vector<t_valAndIdx> &main_chain, int target, int search_idx)
{
	int left = 0;
	int right = search_idx;
	int mid;

	while (left <= right)
	{
		mid = (left + right) / 2;
		
		if (main_chain[mid].value < target) {
			left = mid + 1;
		}
		else if (main_chain[mid].value > target) {
			right = mid - 1;
		}
		else
			return mid;
	}

	return left;
}

void PmergeMe::insertion(std::vector<t_valAndIdx>& main_chain, t_vec_chain& arr)
{
	// insertion
	int next;
	int prev_jacob = -1;
	int jacob_idx = 2;
	int search_range;
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
			t_valAndIdx target = arr[next].second;

			search_range = next + j;

			if (search_range == 0) {
				main_chain.insert(main_chain.begin(), 1, target);
			}
			
			else {
				int des_idx = binary_search(main_chain, target.value, search_range);
			
				main_chain.insert(main_chain.begin() + des_idx, 1, target);
			}

			next--;
			j++;
		}
		
		prev_jacob = jacobstal_num[jacob_idx] - 1;
		jacob_idx++;
	}
}

void PmergeMe::insertion_odd_num(std::vector<t_valAndIdx> &arr, const t_valAndIdx& last_num)
{
	if (last_num.value != -1)
	{
		int last_idx = this->binary_search(arr, last_num.value, arr.size() - 1);
		arr.insert(arr.begin() + last_idx, 1, last_num);
	}
}
#pragma endregion vector_sort

#pragma region deque_sort
void PmergeMe::sort(std::deque<t_valAndIdx> &arr)
{
	t_deque_chain chain = split_deque(arr);
	t_valAndIdx last_num = { -1, -1 };

	if (arr.size() % 2 != 0) {
		last_num = arr.back();
		arr.pop_back();
	}

	arr = ford_johnson(chain);

	insertion_odd_num(arr, last_num);
}

std::deque<t_valAndIdx> PmergeMe::ford_johnson(const t_deque_chain &chain)
{
	t_valAndIdx last_num = {-1, -1};
	std::deque<t_valAndIdx> main_chain;
	
	make_main_chain(main_chain, chain);

	// base case
	if (main_chain.size() == 1) {
		main_chain[0] = chain[0].second;
		main_chain.push_back(chain[0].first);
		return main_chain;
	}

	if (main_chain.size() % 2 != 0) {
		last_num = main_chain.back();
		main_chain.pop_back();
	}

	t_deque_chain new_chain = split_deque(main_chain);

	// recursion!
	main_chain = ford_johnson(new_chain);

	// odd comeback
	insertion_odd_num(main_chain, last_num);

	// sub_chain restore
	restore_sub_chain(main_chain, new_chain, chain);

	// insertion
	this->insertion(main_chain, new_chain);

	// 정렬된 main_chain 리턴
	return main_chain;
}

int PmergeMe::binary_search(const std::deque<t_valAndIdx> &main_chain, int target, int search_idx)
{
	int left = 0;
	int right = search_idx;
	int mid;

	while (left <= right)
	{
		mid = (left + right) / 2;
		
		if (main_chain[mid].value < target) {
			left = mid + 1;
		}
		else if (main_chain[mid].value > target) {
			right = mid - 1;
		}
		else
			return mid;
	}

	return left;
}

void PmergeMe::insertion(std::deque<t_valAndIdx>& main_chain, t_deque_chain& arr)
{
	// insertion
	int next;
	int prev_jacob = -1;
	int jacob_idx = 2;
	int search_range;
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
			t_valAndIdx target = arr[next].second;

			search_range = next + j;

			if (search_range == 0) {
				main_chain.insert(main_chain.begin(), 1, target);
			}
			
			else {
				int des_idx = binary_search(main_chain, target.value, search_range);
			
				main_chain.insert(main_chain.begin() + des_idx, 1, target);
			}

			next--;
			j++;
		}
		
		prev_jacob = jacobstal_num[jacob_idx] - 1;
		jacob_idx++;
	}
}

void PmergeMe::insertion_odd_num(std::deque<t_valAndIdx> &arr, const t_valAndIdx& last_num)
{
	if (last_num.value != -1)
	{
		int last_idx = this->binary_search(arr, last_num.value, arr.size() - 1);
		arr.insert(arr.begin() + last_idx, 1, last_num);
	}
}
#pragma endregion deque_sort

#pragma region vector_utils
static t_vec_chain split_vector(std::vector<t_valAndIdx> &arr) 
{
	t_vec_chain chain;

	for (size_t i = 0; i < arr.size() - 1; i += 2)
	{
		std::pair<t_valAndIdx, t_valAndIdx> elem;

		if (arr[i].value > arr[i + 1].value) {
			elem.first = arr[i];
			elem.second = arr[i + 1];
		}
		else {
			elem.first = arr[i + 1];
			elem.second = arr[i];
		}
		chain.push_back(elem);
	}

	return (chain);
}

static void make_main_chain(std::vector<t_valAndIdx>& main_chain, const t_vec_chain &chain)
{
	main_chain.reserve(chain.size());

	for (size_t i = 0; i < chain.size(); i++)
	{
		t_valAndIdx elem = { chain[i].first.value, i };
		main_chain.push_back(elem);
	}
}

static void restore_sub_chain(std::vector<t_valAndIdx>& main_chain, t_vec_chain& new_chain, const t_vec_chain &chain)
{
	new_chain = chain;
	for (size_t i = 0; i < main_chain.size(); i++)
	{
		new_chain[i] = chain[main_chain[i].idx];
		main_chain[i] = new_chain[i].first;
	}
}
#pragma endregion vector_utils

#pragma region deque_utils
static t_deque_chain split_deque(std::deque<t_valAndIdx> &arr) 
{
	t_deque_chain chain;

	for (size_t i = 0; i < arr.size() - 1; i += 2)
	{
		std::pair<t_valAndIdx, t_valAndIdx> elem;

		if (arr[i].value > arr[i + 1].value) {
			elem.first = arr[i];
			elem.second = arr[i + 1];
		}
		else {
			elem.first = arr[i + 1];
			elem.second = arr[i];
		}
		chain.push_back(elem);
	}

	return (chain);
}

static void make_main_chain(std::deque<t_valAndIdx>& main_chain, const t_deque_chain &chain)
{
	for (size_t i = 0; i < chain.size(); i++)
	{
		t_valAndIdx elem = { chain[i].first.value, i };
		main_chain.push_back(elem);
	}
}

static void restore_sub_chain(std::deque<t_valAndIdx>& main_chain, t_deque_chain& new_chain, const t_deque_chain &chain)
{
	new_chain = chain;
	for (size_t i = 0; i < main_chain.size(); i++)
	{
		new_chain[i] = chain[main_chain[i].idx];
		main_chain[i] = new_chain[i].first;
	}
}

#pragma endregion deque_utils