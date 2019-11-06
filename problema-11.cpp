#include <iostream>

using namespace std;

int n, ok = 0, st[100], termeni, p;
char nume[30][30];

void tipar(int k)
{
	for (int i = 1; i <= k; i++)
	{
		cout << nume[st[i]] << "-";
	}
	cout << endl;
}

int valid(int k)
{
	if (k == 1)
	{
		termeni = 0;
	}
	for (int i = 1; i < k; i++)
	{
		if (st[i] == st[k])
		{
			return 0;
		}
	}
	termeni++;
	return 1;
}

void back(int k)
{
	if (termeni == p)
	{
		tipar(termeni);
		termeni--;
	}
	else
	{
		for (int i = 0; i < n; i++)
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
	cin >> n >> p;
	for (int i = 0; i < n; i++)
	{
		cin.get();
		cin.get(nume[i], 30);
	}
	back(1);
}
