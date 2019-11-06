#include <iostream>

using namespace std;

int n, ok = 0, st[100], m, y;

void tipar(int k)
{
		for (int i = 1; i <= k ; i++)
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
	if (k == n)
	{
		for (int i = m; i < n; i++)
		{
			if (st[i] == y || st[k] == y)
			{
				return 0;
			}
		}
	}
	return 1;
}

void back(int k)
{
	if (k == n+1)
	{
		tipar(m);
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
	cin >> n >> m >> y;
	back(1);
}
