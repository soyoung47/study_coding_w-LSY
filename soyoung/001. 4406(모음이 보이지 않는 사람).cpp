#include<iostream>
  
using namespace std;
  
int main(int argc, char** argv)
{
    int test_case;
    int T;
  
    cin>>T;
      
    for(test_case = 1; test_case <= T; ++test_case)
    {
        char word[50]={"\0"};
        cin>>word;
          
        char answer[50] = {"\0"};
        int count =0;
        for(int i=0; word[i] != 0; i++)
        {
            switch(word[i])
            {
                case 'a':
                case 'e':
                case 'i':
                case 'o':
                case 'u':
                    break;
                default:
                    answer[count] = word[i];
                    count++;
            }
        }
          
        cout<<"#"<<test_case<<" "<<answer<<"\n";
    }
    return 0;
}
