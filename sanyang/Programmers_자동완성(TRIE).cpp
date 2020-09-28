//[programmers.co.kr] - 코딩테스트 연습 - 2018 KAKAO BLIND RECRUITMENT - 자동완성
//https://programmers.co.kr/learn/courses/30/lessons/17685

#include <string>
#include <vector>
using namespace std;

struct TRIE {
	//알파벳 26자
	TRIE* Node[26];
	//뒤에 문자열이 더 있는지
	int Child;
	//마지막 문자인지
	bool Finish;

	void Insert(const char* Str);
	int Find(const char* Str, int Cnt);
};

int Trie_idx;
//단어 길이 총합 2-1,000,000
TRIE Nodepool[1000010];

TRIE* Nodeset() {
	TRIE* NewNode = &Nodepool[Trie_idx++];
	for (int i = 0; i < 26; i++) NewNode->Node[i] = NULL;
	NewNode->Child = 0;
	return NewNode;
}

void TRIE::Insert(const char* Str) {
	Child++;
	if (*Str == NULL) {
		Finish = true;
		return;
	}

	int Cur = *Str - 'a';
	if (Node[Cur] == NULL) Node[Cur] = Nodeset();
	Node[Cur]->Insert(Str + 1);
}

int TRIE::Find(const char* Str, int Cnt) {
	//유일 문자열인지 확인(chd==1), 마지막인지 확인->입력수(Cnt) 반환
	if (Child == 1 || *Str == NULL) return Cnt;
	int Cur = *Str - 'a';
	return Node[Cur]->Find(Str + 1, Cnt + 1);
}

int solution(vector<string> words) {
	Trie_idx = 0;
	int answer = 0;
	int N = words.size();
	TRIE* Root = Nodeset();
	for (int i = 0; i < N; i++) Root->Insert(words[i].c_str());
	for (int i = 0; i < N; i++) answer += Root->Find(words[i].c_str(), 0);
	return answer;
}

//ref: //https://yabmoons.tistory.com/490
