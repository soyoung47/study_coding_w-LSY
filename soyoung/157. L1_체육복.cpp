//https://programmers.co.kr/learn/courses/30/lessons/42862

#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> student(n,1);
    
    //소지한 체육복 개수
    for(int i=0; i<lost.size(); i++)
        student[lost[i]-1]--;
    
    for(int j=0; j<reserve.size(); j++)
        student[reserve[j]-1]++;
    
    for(int k=0; k<n; k++)
    {
        //여분 O && 왼쪽 사람 체육복 X (맨 앞사람 제외)
        if(k!=0 && student[k]>1 && student[k-1]==0)
        {
            student[k]--;
            student[k-1]++;
        }
        //여분 O && 오른쪽 사람 체육복 X (맨 끝사람 제외)
        if(k!=n-1 && student[k]>1 && student[k+1]==0)
        {
            student[k]--;
            student[k+1]++;
        }
    }
    
    for(int z=0; z<n; z++)
    {
        if(student[z] > 0)
            answer++;
    }
    
    return answer;
}
