# ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <sstream>
#include <vector>
#include <deque>

typedef struct s_valAndIdx
{
	int value;
	int idx;
}	t_valAndIdx;

typedef std::vector< std::pair <t_valAndIdx, t_valAndIdx> > t_vec_chain;
typedef std::deque< std::pair <t_valAndIdx, t_valAndIdx> > t_deque_chain;

class PmergeMe
{
	private:
		int jacobstal_num[20];

		std::vector<t_valAndIdx> ford_johnson(const t_vec_chain &chain);
		std::deque<t_valAndIdx> ford_johnson(const t_deque_chain &chain);

		int binary_search(const std::vector<t_valAndIdx> &main_chain, int target, int search_idx);
		int binary_search(const std::deque<t_valAndIdx> &main_chain, int target, int search_idx);

		void insertion(std::vector<t_valAndIdx>& main_chain, t_vec_chain& arr);
		void insertion(std::deque<t_valAndIdx>& main_chain, t_deque_chain& arr);

		void insertion_odd_num(std::vector<t_valAndIdx> &arr, const t_valAndIdx& last_num);
		void insertion_odd_num(std::deque<t_valAndIdx> &arr, const t_valAndIdx& last_num);

	public:
		PmergeMe();
		PmergeMe(const PmergeMe& origin);
		PmergeMe& operator= (const PmergeMe& origin);
		~PmergeMe();

		void sort(std::vector<t_valAndIdx> &arr);
		void sort(std::deque<t_valAndIdx> &arr);
};

# endif