#include <iostream>

using namespace std;

int n, st[100], ok=0;

void tipar(int k)
{
		for (int i = 1; i <= k; i++)
		{
			cout << (char) (st[i]+64) << " ";
		}
		cout << endl;
}

int valid(int k)
{	

	for (int i = 1; i < k; i++)
	{
		if (st[i] == st[k])
		{
			return 0;
		}
	}
	if (st[k] == 4)
	{
		for (int i = 1; i < k; i++)
		{
			if (st[i] == 1)
			{
				return 0;
			}
		}
	}
	if (k == 3)
	{
		if (st[1] != 5 && st[2] != 5 && st[3] != 5)
		{
			return 0;
		}
	}
	return 1;
}

void back(int k)
{
	if (k == n+1)
	{
		tipar(n);
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
