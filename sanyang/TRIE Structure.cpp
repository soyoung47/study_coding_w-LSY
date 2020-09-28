#include <iostream>
using namespace std;

//TRIE structure
struct TRIE {
	//문자열이 끝나면 fin = true
	bool Finish;
	//알파벳 수 26
	TRIE* Node[26];
	//생성자 (노드 할당)
	TRIE() {
		Finish = false;
		for (int i = 0; i < 26; i++) Node[i] = NULL;
	}
};

void Insert(char* Str) {
	//더이상 문자열에 남은 문자가 없으면 종료후 단어끝 표시
	if (*Str == NULL) {
		Finish = true;
		return;
	}

	//문자열에서 현재 가리키는 문자 가져옴
	//노드에 이미 존재하는지 확인 위해 정수로 가져옴
	int Cur = *Str - 'A';
	//연결 노드 없음 -> 노드 생성 후 다음 문자열 탐색
	if (Node[Cur] == NULL) Node[Cur] = new TRIE();
	//다음 문자열 확인
	Node[Cur]->Insert(Str + 1);
}

bool Find(char* Str) {
	//마지막까지 탐색
	if (*Str == NULL) {
		if (Finish == true) return true;
		else return false;
	}
	int Cur = *Str - 'A';
	//노드가 생성되지 않은 경우(TRIE에 없는 문자열) false 반환
	if (Node[Cur] == NULL) return false;
	else Node[Cur]->Find(Str + 1);
}

//TRIE 구조는 문자열 탐색에 유용
//ref: https://yabmoons.tistory.com/379
//ref: https://bit.ly/36h4tYT
