# ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <sstream>
#include <vector>
#include <deque>

class PmergeMe
{
	private:
		int jacobstal_num[20];
		
		void insertion(std::vector<int>& main_chain, std::vector< std::pair<int, int> >& arr);
		void insertion(std::deque<int>& main_chain, std::deque< std::pair<int, int> >& arr);

		std::vector<int> ford_johnson(std::vector< std::pair<int, int> > &arr);
		std::deque<int> ford_johnson(std::deque< std::pair<int, int> > &arr);

		int binary_search(std::vector<int> main_chain, int target, int search_idx);
		int binary_search(std::deque<int> main_chain, int target, int search_idx);
		
	public:
		PmergeMe();
		PmergeMe(const PmergeMe& origin);
		PmergeMe& operator= (const PmergeMe& origin);
		~PmergeMe();

		void sort(std::vector<int> &arr);
		void sort(std::deque<int> &arr);
};

# endif