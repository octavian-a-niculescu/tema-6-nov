#include <iostream>

using namespace std;

int n, ok = 0, st[100], A[5] = { 2, 5, 6, 7, 8 };

void tipar(int k)
{
	for (int i = 1; i <= k; i++)
	{
		cout << st[i] << " ";
	}
	cout << endl;
}

int valid(int k)
{
	for (int i = 0; i < k; i++)
	{
		if (st[i] == st[k])
		{
			return 0;
		}
	}
	if (k > 1)
	{
		if (st[k] % 2 == 0 && st[k - 1] % 2 == 0)
		{
			return 0;
		}
		if (st[k] % 2 == 1 && st[k - 1] % 2 == 1)
		{
			return 0;
		}
	}
	return 1;
}

void back(int k)
{
	if (k == n + 1)
	{
		tipar(n);
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			st[k] = A[i];
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
