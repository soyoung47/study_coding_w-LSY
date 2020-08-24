//Codility_L13-2_FibonacciNumbers_Ladder[Respectable]
//https://app.codility.com/programmers/lessons/13-fibonacci_numbers/ladder/

#include <algorithm>
#include <math.h>

vector<int> solution(vector<int>& A, vector<int>& B)
{
	vector<unsigned long long> fib(*max_element(A.begin(), A.end()) + 1, 0);
	fib[1] = 1;
	fib[2] = 2;

	for (int i = 3; i < fib.size(); i++) fib[i] = fib[i - 1] + fib[i - 2];

	vector<int> res;
	for (int i = 0; i < A.size(); i++) res.push_back(fib[A[i]] % static_cast<unsigned long long>(pow(2, B[i])));
	
	return res;
}

//result O(L): https://app.codility.com/demo/results/training4D8XWJ-ZJV/
//ref: http://dal4segno.github.io/algorithm/codility-13-fibonacci-numbers/
