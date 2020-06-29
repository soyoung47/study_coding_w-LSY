//Codility_L2_Arrays_OddOccurrencesInArray[Painless]
//https://app.codility.com/programmers/lessons/2-arrays/odd_occurrences_in_array/

int solution(vector<int>& A)
{
    int Ans = 0;
    for (int i = 0; i < A.size(); i++)
    {
        int Num = A[i];
        Ans ^= Num;
    }
    return Ans;
}

//result: https://app.codility.com/demo/results/trainingSV2FFU-EUG/
