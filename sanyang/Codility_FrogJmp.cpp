//Codility_L3_FrorJmp[Painless]
//https://app.codility.com/programmers/lessons/3-time_complexity/frog_jmp/

int solution(int X, int Y, int D)
{
	int cnt = (Y - X) / D;
	if (((Y - X) % D) != 0) cnt++;
	return cnt;
}

//result: https://app.codility.com/demo/results/trainingG9PPXV-7AZ/
