//https://programmers.co.kr/learn/courses/30/lessons/17683

#include <string>
#include <vector>
#include <sstream>
using namespace std;

vector<string> split(string str, char delimiter)
{
    vector<string> arr;
    stringstream ss(str);
    string tmp;

    while (getline(ss, tmp, delimiter))
        arr.push_back(tmp);

    return arr;
}

//����� �Ǻ� ���
string write_play_music(int time, string music)
{
    string play = "";
    int n = music.size();
    int t = 0;
    while (t < time)
    {
        play += music[t % n];
        t++;
    }

    return play;
}

string rewrite_music(string music)
{
    if (music.find_first_of('#') == -1)  return music;

    string n_music = "";
    int n = music.size();

    for (int i = 0; i < n; i++)
    {
        if (i - 1 < n && music[i + 1] == '#')
        {
            n_music += tolower(music[i]);
            i++;
        }
        else
            n_music += music[i];
    }

    return n_music;
}

string solution(string m, vector<string> musicinfos) {
    string answer = "(None)";
    int size = musicinfos.size();
    vector<vector<string>> play_music;  //{����, ����� �Ǻ�}
    vector<int> t_play; //����� �ð�

    for (string line : musicinfos)
    {
        vector<string> tmp = split(line, ',');
        
        //����� �ð�: ������ ȯ��
        int t_start = stoi(tmp[0].substr(0, 2)) * 60 + stoi(tmp[0].substr(3, 2));
        int t_end = stoi(tmp[1].substr(0, 2)) * 60 + stoi(tmp[1].substr(3, 2));
        t_play.push_back(t_end - t_start);

        //����� �Ǻ�: ����� �ð���ŭ ���
        string name = tmp[2], music = tmp[3];
        play_music.push_back({ name, write_play_music(t_play.back(), rewrite_music(music)) });
    }

    int max_time = 0;
    m = rewrite_music(m);
    for (int i = 0; i < size; i++)
    {
        //��ε� �ִ� ���
        int pos = play_music[i][1].find(m);
        if (pos != -1)
        {
            if (pos + m.size() > play_music[i][1].size())    continue;
            
            if (max_time < t_play[i])
            {
                answer = play_music[i][0];
                max_time = t_play[i];
            }            
        }
    }

    return answer;
}