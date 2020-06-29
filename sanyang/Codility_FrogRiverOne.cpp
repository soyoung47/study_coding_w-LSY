//Codility_L4_CountingElements_FrogRiverOne[Painless]
//https://app.codility.com/programmers/lessons/4-counting_elements/frog_river_one/

int solution(int X, int Y, int D)
{
	int cnt = (Y - X) / D;
	if (((Y - X) % D) != 0) cnt++;
	return cnt;
}

//result: 
