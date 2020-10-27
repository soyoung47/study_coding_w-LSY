//https://programmers.co.kr/learn/courses/30/lessons/42579

#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

bool compare(pair<int,int> a,pair<int,int> b){
    return a.first > b.first;
}
bool compare_map_value(pair<string,int> a,pair<string,int> b){
    return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    //장르,재생수,고유번호
    unordered_map<string,vector<pair<int,int>>> genre_playlist;
    //장르,총재생수
    unordered_map<string,int> genre_play_cnt;
    //정렬위해 벡터 생성
    vector<pair<string,int>> genre_play_cnt_v;

    //맵에 데이터 삽입
    for(int i=0; i < genres.size(); i++){
        genre_playlist[genres[i]].push_back(make_pair(plays[i],i));
        genre_play_cnt[genres[i]]+=plays[i];
    }

    //장르별 재생빈도수 내림차순 정렬
    for(auto &k : genre_playlist){
        sort(k.second.begin(),k.second.end(),compare);
    }
    genre_play_cnt_v.assign(genre_play_cnt.begin(),genre_play_cnt.end());
    sort(genre_play_cnt_v.begin(),genre_play_cnt_v.end(),compare_map_value);


    for(int i=0; i < genre_play_cnt_v.size(); i++){
        string genre_name = genre_play_cnt_v[i].first;
        //탑1,2 저장
        for(int j=0; (j < genre_playlist[genre_name].size() ) && (j < 2) ; j++){
            answer.push_back(genre_playlist[genre_name][j].second);
        }
    }
    return answer;
}

//https://velog.io/@gowoonsori/%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%A8%B8%EC%8A%A4cpp%EB%B2%A0%EC%8A%A4%ED%8A%B8%EC%95%A8%EB%B2%94

