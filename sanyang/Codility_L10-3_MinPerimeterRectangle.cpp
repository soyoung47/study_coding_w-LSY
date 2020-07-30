//Codility_L10-3_PrimeAndCompositeNumbers_MinPerimeterRectangle
//https://app.codility.com/programmers/lessons/10-prime_and_composite_numbers/min_perimeter_rectangle/

int solution(int N)
{
	int cnt = 0, i = 1, tmpP = 0, minP = numeric_limits<int>::max();
	if (N == 1) return 2 * 2 * 1;
	while (i * i <= (unsigned int)N)
	{
		if (N % i == 0)
		{
			tmpP = 2 * (i + (N / i));
			if (tmpP < minP && tmpP > 0) minP = tmpP;
		}
		i++;
	}
	return (int)minP;
}

//result O(sqrt(N)): https://app.codility.com/demo/results/trainingAMRGKC-Y6A/
