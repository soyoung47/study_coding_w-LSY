//https://programmers.co.kr/learn/courses/30/lessons/17685

#include <string>
#include <vector>
#include <cstring>
using namespace std;

//트라이 구조
struct Trie
{
    Trie* child[26];
    bool check; //끝나는 지점인지 아닌지
    int count = 0;   //현재의 학습 된 문자 개수

    Trie()
    {
        check = false;
        memset(child, 0, sizeof(child));
    }

    ~Trie()
    {
        for (int i = 0; i < 26; i++)
            delete child[i];
    }

    void input(const char* str)
    {
        //문자열이 끝나는 지점일 경우
        if (*str == '\0')
        {
            check = true;   
            return;
        }

        //소문자를 인덱스로 변환
        int ind = *str - 'a'; //TO_NUMBER(*str);

        //탐색이 처음인 경우 동적할당
        if (child[ind] == NULL)
            child[ind] = new Trie();

        //문자 개수 증가 + 다음 문자 인덱스 트리 생성
        child[ind]->count++;
        child[ind]->input(str + 1);
    }

    int find(const char* str, const int cnt)
    {
        int ind = *str - 'a';

        if (*str == 0 || child[ind] == NULL)   return cnt - 1;

        //문자에 해당하는 트라이가 생성되어 있지 않은 경우(문자 없음: false 반환)
        if (child[ind]->count == 1)  return cnt;

        return child[ind]->find(str + 1, cnt + 1);   //다음 문자 탐색
    }
};

int solution(vector<string> words) {
    int answer = 0;
    Trie* dict = new Trie();

    //단어 (트라이 구조)사전에 등록
    for (int i = 0; i < words.size(); i++)
        dict->input(words[i].c_str());

    for (int i = 0; i < words.size(); i++)
        answer += dict->find(words[i].c_str(), 1);

    delete dict;

    return answer;
}

//Ref:::https://dev-dream-world.tistory.com/77