#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

struct webPage {
    int ind;
    double basic;
    double score;
};

bool comp(webPage& a, webPage& b)
{
    if (a.score == b.score)
        return a.ind < b.ind;
    return a.score > b.score;
}

int solution(string word, vector<string> pages) {

    int answer = 0;

    int size = word.size();
    int psize = pages.size();
    vector<webPage> list;   //웹페이지 리스트
    map<string, int> url;   //웹페이지의 url, index
    vector<vector<string>> link(psize);    //각 웹페이지의 외부 링크의 url
    transform(word.begin(), word.end(), word.begin(), ::tolower);

    for (int i = 0; i < psize; i++)
    {
        string s = pages[i];
        transform(s.begin(), s.end(), s.begin(), ::tolower);

        int pA, pB;
        //각 web page의 url 저장
        pA = s.find("<meta property=");
        pA = s.find("https://", pA);
        pB = s.find("\"/>", pA);
        url[s.substr(pA, pB - pA)] = i;

        //기본 점수 구하기
        pA = s.find("<body>", pB);
        double b = 0.0;
        while (1)
        {
            pA = s.find(word, pA + 1);
            if (pA == -1)  break;
            if (!isalpha(s[pA - 1]) && !isalpha(s[pA + size]))
            {
                b += 1.0;
                pA += size;
            }
        }

        //외부 링크 url 저장
        pA = pB = 0;
        while (1)
        {
            pA = s.find("<a href", pA);
            if (pA == -1)  break;
            pA = s.find("https://", pA);
            pB = s.find("\">", pA);
            link[i].push_back(s.substr(pA, pB - pA));
        }

        list.push_back({ i, b, b });
    }

    //매칭 점수 구하기
    for (int i = 0; i < psize; i++)
    {
        if (list[i].basic == 0)  continue;
        for (int j = 0; j < link[i].size(); j++)
        {
            string outULR = link[i][j];
            if (url.count(outULR) == 0)  continue;

            int link_url = url[outULR];
            list[link_url].score += list[i].basic / link[i].size();
        }
    }

    sort(list.begin(), list.end(), comp);

    return list[0].ind;
}

//Ref:::https://blog.naver.com/csezsw/221552563358, https://9967han.tistory.com/10