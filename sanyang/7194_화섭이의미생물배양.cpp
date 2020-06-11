//#7194. 화섭이의 미생물 
#include <iostream>
#include <cstring>
#define endl "\n"
using namespace std;
int s, t, a, b; //t = n*b(s + m*a)

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++)
	{
		s = 0, t = 0, a = 0, b = 0;
		cin >> s >> t >> a >> b;
		cout << "#" << tc << ' ';
		int Ans = 0;
		if (b == 1) // *1
		{
			int tmp = t - s;
			if ((tmp % a) == 0) //t=s+a*((t-s)/a)
				cout << tmp / a << endl;
			else cout << "-1" << endl;
			continue;
		}

		while (s != t)
		{
			if ((t % b) == 0)
			{
				if ((t / b) < s)
				{
					Ans++;
					t -= a;
				}
				else
				{
					Ans++;
					t /= b;
				}
			}
			else
			{
				Ans++;
				t -= a;
			}
			if (s > t) //impossible case
			{
				Ans = -1;
				break;
			}
		}

	cout << Ans << endl;
	}

	return 0;
}
*/

/*
void Solve()
{
	Ans = INT_MAX;
	numCal = 0;
	for (int i = 0; i <= (t/a); i++) // n
	{
		for (int j = 0; j <= (t/a); j++) // m
		{
			int Cmp = (i * b) * ((j * a) + s);
			if (Cmp > t) continue;
			if (t == Cmp)
			{
				numCal = i + j;
				if (numCal < Ans) Ans = numCal;
			}
		}
	} 
	if (numCal == 0) Ans = -1;
	cout << Ans << endl;
}
