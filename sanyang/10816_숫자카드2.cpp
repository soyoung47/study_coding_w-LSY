/*
 https:www.acmicpc.net/problem/10816
 첫째 줄에 상근이가 가지고 있는 숫자 카드의 개수 N(1 ≤ N ≤ 500,000)이 주어진다. 둘째 줄에는 숫자 카드에 적혀있는 정수가 주어진다. 숫자 카드에 적혀있는 수는 -10,000,000보다 크거나 같고, 10,000,000보다 작거나 같다.

 셋째 줄에는 M(1 ≤ M ≤ 500,000)이 주어진다. 넷째 줄에는 상근이가 몇 개 가지고 있는 숫자 카드인지 구해야 할 M개의 정수가 주어지며, 이 수는 공백으로 구분되어져 있다. 이 수도 -10,000,000보다 크거나 같고, 10,000,000보다 작거나 같다.
 */

#include <cstdio>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main(){
    int N, M, tmpN;
    unordered_map<int, int> map;
    scanf("%d", &N);
    for (int i=0; i<N; i++){
        scanf("%d", &tmpN);
        map[tmpN]++;
    }
    scanf("%d", &M);
    for (int i=0; i<M; i++){
        scanf("%d", &tmpN);
        printf("%d ", map[tmpN]);
    }
}

//ref: https://minocode.tistory.com/6

//아래 코드는 이진 탐색으로 풀어보았으나 시간초과

//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//int main(){
//    ios::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);
//    int N, M;
//    vector<int> cards, targets;
//    int tmpN, min, max, avg;
//    //#N
//    cin >> N;
//    //A[1], A[2], ..., A[N]
//    for (int i=0; i<N; i++){
//        cin >> tmpN;
//        cards.emplace_back(tmpN);
//    }
//    //#M
//    cin >> M;
//    //targets
//    for (int i=0; i<M; i++){
//        cin >> tmpN;
//        targets.emplace_back(tmpN);
//    }
//
//    //데이터 정렬
//    sort(cards.begin(), cards.end());
//    //binary search
//
//    for (auto t: targets){
//        int cnt=0, found=0;
//        min = 0;
//        max = N-1;
//        while(min<=max){
//            avg = (min+max+1)/2;
//            if (t==cards[avg]){
//                found=1;
//                cnt++;
//                break;
//            }
//            else if (t<cards[avg])   max = avg-1;
//            else if (t>cards[avg])   min = avg+1;
//        }
//        int dist = 1;
//        bool chkL=0, chkR=0;
//        while (found==1){
//            if (cards[avg-dist]==t) cnt++;
//            else chkL = 1;
//            if (cards[avg+dist]==t) cnt++;
//            else chkR = 1;
//            if (chkL == 1 && chkR == 1) found = 0;
//            else dist++;
//        }
//        cout << cnt << ' ';
//    }
//}
//
//binary search: time error
