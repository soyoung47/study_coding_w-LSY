//Codility_L1-1_Iterations_BinaryGap[Painless]
//https://app.codility.com/programmers/lessons/1-iterations/binary_gap/
int arrTmp[32] = {0};

int solution(int N) {
    int tmp = N;
    int ind = 0;
    while (tmp >= 1)
    {
        arrTmp[ind] = tmp % 2;
        tmp = tmp / 2;
        ind++;
    }
    int arr[ind];
    for (int i=0; i<ind; i++)
    {
        arr[i] = arrTmp[ind-1-i];
    }
    int max = 0, cnt = 0;
    int CntOne = 0;
    for (int i=0; i<ind; i++)
    {
        if (arr[i] == 1)
        {
            CntOne++;
            if (CntOne > 1)
            {
                if (cnt > max) max = cnt;
            }
            cnt = 0;
        }
        else if((arr[i] == 0)&&(CntOne != 0)) //arr[i] == 0
        {
            cnt++;
        }
    }
    return max;
}

//result: https://app.codility.com/demo/results/trainingZX4T84-734/
