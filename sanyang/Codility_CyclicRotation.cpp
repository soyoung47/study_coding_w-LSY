//Codility_L2_Arrays_CyclicRotation[Painless]
//https://app.codility.com/programmers/lessons/2-arrays/cyclic_rotation/

vector<int> solution(vector<int> &A, int K) {
    int tmpV = 0, ind = 0;
    vector<int> tmpA = A;
    for (int i=0; i<A.size(); i++)
    {
        tmpV = A.at(i);
        ind = (i+K)%A.size();
        tmpA.at(ind) = tmpV;
    }
    A.swap(tmpA);
    return A;
}
