#include <iostream>

using namespace std;

int n, st[100], s = 0, termeni = 0, ultValid;

void tipar(int k)
{
	if (k > 1)
	{
		for (int i = 1; i <= k; i++)
		{
			cout << st[i] << " ";
		}
		cout << endl;
	}
}

int valid(int k)
{
	if (k == 1)
	{
		s = 0;
		termeni = 0;
	}
	else
	{
		if ((st[k] - 1) != st[k - 1])
		{
			return 0;
		}
	}
	if (s + st[k] > n)
	{
		return 0;
	}
	termeni++;
	s += st[k];
	return 1;
}

void back(int k)
{
	if (s == n)
	{
		tipar(termeni);
		termeni--;
		s -= st[k];
	}
	else
	{
		for (int i = 1; i <= n; i++)
		{
			st[k] = i;
			if (valid(k))
			{
				back(k + 1);
			}
		}
	}
}


int main()
{
	cin >> n;
	back(1);
}
