# ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <sstream>
#include <vector>
#include <list>

class PmergeMe
{
	private:
		
	public:
	
	/*
		1. 인자로 배열을 받는다.
		2. 메인체인, 서브체인 배열을 만든다.
		3. 메인체인은 재귀로 다시 포드존슨 인자로 넣어준다.
		4. 서브체인의 삽입을 시작한다.
			재귀 종료조건 : 메인체인의 원소가 하나일 때?
		
		point: 아마 재귀로 내려가는 도중 바뀌는 mainchain의 순서를 벡터로 실시간 스왑해야되는듯 (재귀 스택마다 같은 벡터를 컨트롤)
	*/
};

# endif