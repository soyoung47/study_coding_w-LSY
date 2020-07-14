//Codility_L6-2_Sorting_MaxProductOfThree[Painless]
//https://app.codility.com/programmers/lessons/6-sorting/max_product_of_three/

#include <algorithm>

int solution(vector<int>& A)
{
	sort(A.begin(), A.end());
	int a = A[A.size()-1] * A[A.size()-2] * A[A.size()-3];
	int b = A[0] * A[1] * A[A.size() - 1];
	return (a > b) ? a : b;
}

//result(100% O(N * log(N))
//https://app.codility.com/demo/results/trainingCWFQ9R-XVF/

//ref:
//https://killong.blogspot.com/2019/03/codility-lesson6-maxproductofthree.html
//https://moonscode.tistory.com/128
