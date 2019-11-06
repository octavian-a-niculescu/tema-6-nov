#include <iostream>

using namespace std;

int n, ok = 0, s;
char st[100], cuv[25], variante[25];

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
		if (strchr("aeiou", st[k]) && strchr("aeiou", st[k - 1]))
		{
			return 0;
		}
		if (strchr("bcdfghjklmnpqrstvwxyz", st[k]) && strchr("bcdfghjklmnpqrstvwxyz", st[k - 1]))
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
			st[k] = cuv[i];
			if (valid(k))
			{
				back(k + 1);
			}
		}
	}
}


int main()
{
	cin.get(cuv, 25);
	n = strlen(cuv);
	back(1);
}
