/*
    Time Complexity: O(N + M)
    Result:::https://app.codility.com/demo/results/trainingDQP2ZH-8KW/
*/
vector<int> solution(string& S, vector<int>& P, vector<int>& Q) {

    vector<int> ans;
    vector<vector<int>> v;    
    
    vector<int> data(4);
    int len = S.length();
    for (int k = 0; k < len; k++)
    {
        if (S[k] == 'A') data[0]++;
        else if (S[k] == 'C') data[1]++;
        else if (S[k] == 'G') data[2]++;
        else if (S[k] == 'T') data[3]++;

        v.push_back(data);
    }

    int M = P.size();
    for (int i = 0; i < M; i++)
    {
        vector<int> prefix(4);
        if (P[i] == 0) prefix = v[Q[i]];
        else
        {
            for (int j = 0; j < 4; j++)
            {
                prefix[j] = v[Q[i]][j] - v[P[i] - 1][j];
            }            
        }

        //find the minimal impact factor
        for (int z = 0; z < 4; z++)
        {
            if (prefix[z] > 0)
            {
                ans.push_back(z + 1);
                break;
            }
        }
    }

    return ans;
}