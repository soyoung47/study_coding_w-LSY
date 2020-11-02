#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    int cnt[3] = {0};
    int n = answers.size();
    
    int arr1[5] = {1,2,3,4,5};
    int arr2[8] = {2,1,2,3,2,4,2,5};
    int arr3[10] = {3,3,1,1,2,2,4,4,5,5};
    
    for(int i=0; i<n; i++)
    {
        int ans = answers[i];
        //math 1
        if(ans==arr1[i%5])
            cnt[0]++;
        
        //math 2
        if(ans==arr2[i%8])
            cnt[1]++;
        
        //math 3
        if(ans==arr3[i%10])
            cnt[2]++;
    }
    
    int max = 0;
    for(int j=0; j<3; j++)
    {
        if(max < cnt[j])
            max = cnt[j];
    }
    
    for(int z=0; z<3; z++)
    {
        if(max == cnt[z])
            answer.push_back(z+1);
    }
    
    return answer;
}
