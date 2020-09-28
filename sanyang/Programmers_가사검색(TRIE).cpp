//[programmers.co.kr] - 코딩테스트 연습 - 2020 KAKAO BLIND RECRUITMENT - 가사 검색
//https://programmers.co.kr/learn/courses/30/lessons/60060

#include <string>
#include <vector>
#include <map> //검색 키워드 중복되는경우 고려
using namespace std;

struct TRIE {
	//알파벳 26자
	TRIE* Node[26];
	//가지고있는 child 수 (길이 고려하여 탐색시간 줄이기 위함)
	int Child_Cnt;
	bool Finish;

	void Insert(const char* Str);
	int Find(const char* Str);
};

int idx = 0;
//키워드 길이 1-10,000, 뒤집은 문자열도 함께 고려(???x)
//n번 인덱스는 모두 길이 n인 문자열
TRIE *Trie[10010], *R_Trie[10010];
//전체 검색 키워드 길이 합 2-1,000,000
TRIE Nodepool[1000010 * 2];

//노드 기본 세팅
TRIE* Nodeset() {
	TRIE* NewNode = &Nodepool[idx++];
	NewNode->Child_Cnt = 0;
	NewNode->Finish = false;
	for (int i = 0; i < 26; i++) NewNode->Node[i] = NULL;
	return NewNode;
}

//트라이에 새로운 문자열 추가
void TRIE::Insert(const char* Str) {
	//가능한 문자열 수 증가
	Child_Cnt++;
	if (*Str == NULL) {
		Finish = true;
		return;
	}

	int Cur = *Str - 'a';
	if (Node[Cur] == NULL) Node[Cur] = Nodeset();
	Node[Cur]->Insert(Str + 1);
}

//문자열 검색
int TRIE::Find(const char* Str) {
	if (*Str == '?') return Child_Cnt;
	int Cur = *Str - 'a';
	if (Node[Cur] == NULL) return 0;
	return Node[Cur]->Find(Str + 1);
}

//?가 처음 또는 끝에 있는지 확인
int Check_State(string S) {
	if (S[0] == '?') return 0;
	if (S[S.length() - 1] == '?') return 1;
}

//문자열 역순으로 뒤집기
string Reverse(string S) {
	string tmp = "";
	for (int i = S.length() - 1; i >= 0; i--) tmp += S[i];
	return tmp;
}

vector<int> solution(vector<string> words, vector<string> queries) {
	vector<int> answer;
	//words를 TRIE에 추가, 초기화
	for (int i = 0; i < words.size(); i++) {
		string S = words[i];
		int Len = S.length();
		if (Trie[Len] == NULL) Trie[Len] = Nodeset();
		Trie[Len]->Insert(S.c_str());

		//역순 고려
		string Reverse_S = Reverse(S);
		if (R_Trie[Len] == NULL) R_Trie[Len] = Nodeset();
		R_Trie[Len]->Insert(Reverse_S.c_str());
	}

	map<string, int> MAP;
	for (int i = 0; i < queries.size(); i++) {
		string S = queries[i];
		//S가 map에 없으면 0, 있으면 1 (중복 키워드 처리)
		if (MAP.count(S) == 0) {
			MAP[S] = i;
			int Len = S.length();
			int State = Check_State(S);

			//xx?
			if (State == 1) {
				if (Trie[Len] == NULL) answer.push_back(0);
				else answer.push_back(Trie[Len]->Find(S.c_str()));
			}
			//?xx
			else {
				string Reverse_S = Reverse(S);
				if (R_Trie[Len] == NULL) answer.push_back(0);
				else answer.push_back(R_Trie[Len]->Find(Reverse_S.c_str()));
			}
		}
		//이전에 찾았던 경우 매치 단어 수 동일
		else answer.push_back(answer[MAP[S]]);
	}
	return answer;
}

//ref: https://yabmoons.tistory.com/474
