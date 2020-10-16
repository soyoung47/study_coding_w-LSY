#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    
    map<string,int> person; 
    string answer = "";
    
    int n =participant.size();
    
    for(int i=0; i<n; i++)
        person[participant[i]]++;
    for(int j=0; j<n-1; j++)
        person[completion[j]]--;
    
    for(auto iter=person.begin(); iter!=person.end(); iter++)
    {
        if(iter->second != 0)
            answer = iter->first;
    }
    
    return answer;
}
