//[programmers.co.kr] - 코딩테스트 연습 - 2018 KAKAO BLIND RECRUITMENT - n진수게임
//https://programmers.co.kr/learn/courses/30/lessons/17687

string solution(int n, int t, int m, int p) {
    string answer = "", tmp, val = "0";
    bool exit = 0;
    vector<string> nums = {"0", "1", "2" , "3" , "4" , "5" , "6" , "7" , "8" , "9" ,
        "A", "B", "C", "D", "E", "F"};
    int i = 1, cnt = 1;

    //1.구해야 하는 숫자만큼
    while (cnt < (t*m)) {
        exit = 1;
        tmp = "";
        int num = i;
        //2.진법 변환
        while (exit) {
            if (num / n == 0) exit = 0;
            //0번째 위치에 나머지값 넣기
            tmp.insert(0, nums[num % n]);
            num /= n;
        }
        cnt += tmp.size(); //자릿수만큼 추가
        val += tmp;
        i++;    
    }
    for (int i = 0, j = 0; i < cnt && j < t; i++) {
        if (i % m == p - 1) { //순서에 맞게 입력
            answer += val[i];
            j++;
        }
    }

    return answer;
}

//ref: https://chaibin0.tistory.com/entry/N%EC%A7%84%EC%88%98-%EA%B2%8C%EC%9E%84
