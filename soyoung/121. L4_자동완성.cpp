//https://programmers.co.kr/learn/courses/30/lessons/17685

#include <string>
#include <vector>
#include <cstring>
using namespace std;

//Ʈ���� ����
struct Trie
{
    Trie* child[26];
    bool check; //������ �������� �ƴ���
    int count = 0;   //������ �н� �� ���� ����

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
        //���ڿ��� ������ ������ ���
        if (*str == '\0')
        {
            check = true;   
            return;
        }

        //�ҹ��ڸ� �ε����� ��ȯ
        int ind = *str - 'a'; //TO_NUMBER(*str);

        //Ž���� ó���� ��� �����Ҵ�
        if (child[ind] == NULL)
            child[ind] = new Trie();

        //���� ���� ���� + ���� ���� �ε��� Ʈ�� ����
        child[ind]->count++;
        child[ind]->input(str + 1);
    }

    int find(const char* str, const int cnt)
    {
        int ind = *str - 'a';

        if (*str == 0 || child[ind] == NULL)   return cnt - 1;

        //���ڿ� �ش��ϴ� Ʈ���̰� �����Ǿ� ���� ���� ���(���� ����: false ��ȯ)
        if (child[ind]->count == 1)  return cnt;

        return child[ind]->find(str + 1, cnt + 1);   //���� ���� Ž��
    }
};

int solution(vector<string> words) {
    int answer = 0;
    Trie* dict = new Trie();

    //�ܾ� (Ʈ���� ����)������ ���
    for (int i = 0; i < words.size(); i++)
        dict->input(words[i].c_str());

    for (int i = 0; i < words.size(); i++)
        answer += dict->find(words[i].c_str(), 1);

    delete dict;

    return answer;
}

//Ref:::https://dev-dream-world.tistory.com/77