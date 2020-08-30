#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(string a, string b)
{
    if (a.size() == b.size())   return a < b;
    else   return a.size() < b.size();
}

vector<int> solution(vector<string> words, vector<string> queries) {
    
    vector<int> answer;

    //�ܾ� ����� ����
    vector<string> rwords = words;
    for (int i = 0; i < rwords.size(); i++)
    {
        reverse(rwords[i].begin(), rwords[i].end());
    }

    //����, ������ �������� ����
    sort(words.begin(), words.end(), comp);
    sort(rwords.begin(), rwords.end(), comp);

    //�˻� Ű���忡 �ش��ϴ� ���� �ܾ� ���� ã��
    for (int i = 0; i < queries.size(); i++)
    {
        string str = queries[i];
        int size = str.size();

        int lower, upper, ind, len;

        //?�� ���λ翡 ������,
        if (str[0] == '?')
        {           
            reverse(str.begin(), str.end());//Ű���� ������
            ind = str.find_first_of('?');   //?�� ������ index
            len = size - ind;

            str.replace(ind, len, len, 'a');   //?�� 'a'�� ġȯ
            lower = lower_bound(rwords.begin(), rwords.end(), str, comp) - rwords.begin();

            str.replace(ind, len, len, 'z');   //?�� 'z'�� ġȯ
            upper = upper_bound(rwords.begin(), rwords.end(), str, comp) - rwords.begin();
        }
        //?�� ���̻翡 ������,
        else
        {
            ind = str.find_first_of('?');   //?�� ������ index
            len = size - ind;

            str.replace(ind, len, len, 'a');   //?�� 'a'�� ġȯ
            lower = lower_bound(words.begin(), words.end(), str, comp) - words.begin();

            str.replace(ind, len, len, 'z');   //?�� 'z'�� ġȯ
            upper = upper_bound(words.begin(), words.end(), str, comp) - words.begin();
        }

        answer.push_back(upper - lower);
    }

    return answer;
}

//Ref:::https://regularmember.tistory.com/201 (�̺�Ž��)