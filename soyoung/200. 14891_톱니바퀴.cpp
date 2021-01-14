//https://www.acmicpc.net/problem/14891
//2212KB, 0ms

#include <iostream>
#include <vector>
#include <deque>
using namespace std;

deque<int>	d[5];	//��Ϲ���
vector<int> rt(5, 5);	//��Ϲ����� ȸ�� ���� (�ð� 1, �ݽð� -1, ���� 0, �������� ����(�ʱ�ȭ) 5)
//�� ��Ϲ����� ���� �� ���ϱ�
int cal_score()
{
	int score = 0;

	for (int i = 1; i <= 4; i++)
		score += d[i].front() * (int)pow(2, i - 1);

	return score;
}

//��Ϲ��� ȸ��
void rotation(int no)
{
	//������ ��Ϲ����� �� + ȸ������ ���ϱ�
	int ind = no;
	while(ind > 1)
	{
		//���� �ٸ� ���� ��� �ٸ� �������� ȸ��, ���� ���̸� ȸ������ ����
		if (d[ind - 1].at(2) != d[ind].at(6) && rt[ind] != 0)
			rt[ind - 1] = rt[ind] * -1;
		else
			rt[ind - 1] = 0;

		ind--;
	}

	//������ ��Ϲ����� �� + ȸ������ ���ϱ�
	ind = no;
	while (ind < 4)
	{
		//���� �ٸ� ���� ��� �ٸ� �������� ȸ��, ���� ���̸� ȸ������ ����
		if (d[ind].at(2) != d[ind + 1].at(6) && rt[ind] != 0)
			rt[ind + 1] = rt[ind] * -1;
		else
			rt[ind + 1] = 0;

		ind++;
	}

	//��Ϲ��� ���� ������Ʈ
	for (int i = 1; i <= 4; i++)
	{
		if (rt[i] == 1)	//�ð� ����
		{
			d[i].emplace_front(d[i].back());
			d[i].pop_back();
		}
		else if(rt[i] == -1)	//�ݽð� ����
		{
			d[i].emplace_back(d[i].front());
			d[i].pop_front();
		}

		rt[i] = 5;
	}
}

int main()
{
	//��Ϲ����� ���� ���� �޾ƿ���
	for (int i = 1; i <= 4; i++)
	{	
		d[i].assign(8, 0);
		for (int j = 0; j < 8; j++)
			scanf("%1d", &d[i].at(j));
	}

	int k, no, r_state;	//ȸ�� Ƚ��, ��Ϲ��� ��ȣ, ȸ�� ����(�ð� 1, �ݽð� -1)
	cin >> k;

	//��Ϲ��� ȸ��
	for (int i = 0; i < k; i++)
	{
		cin >> no >> r_state;

		//��Ϲ��� ȸ��
		rt[no] = r_state;	//���� ������Ʈ
		rotation(no);
	}

	cout << cal_score();

	return 0;
}