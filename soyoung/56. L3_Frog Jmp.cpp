int solution(int X, int Y, int D) {

    int cnt = 0;

    int len = Y - X;

    if (len % D != 0)
    {
        cnt++;
    }

    cnt += len / D;
}