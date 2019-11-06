#include <iostream>

using namespace std;

int n, st[100], ok = 0, x, y;

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

	for (int i = 1; i < k; i++)
	{
		if (st[i] == st[k])
		{
			return 0;
		}
	}
	if (st[k] == y)
	{
		for (int i = 1; i < k; i++)
		{
			if (st[i] == x)
			{
				return 0;
			}
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
	cin >> n >> x >> y;
	back(1);
}
