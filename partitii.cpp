#include <iostream>
#include <cstring>

using namespace std;

int n, st[10], termeni, s;

void tipar(int k)
{
	/*for (int i = 1; i <= k; i++)
	{
		cout << st[i] << " ";
	}
	cout << endl;*/
}

int valid(int k)
{
	if (k == 1)
	{
		termeni = 0;
		s = 0;
	}
	else {
		if (st[k] - st[k - 1] < 2)
		{
			return 0;
		}
	}
	for (int i = 1; i < k; i++)
	{
		if (st[k] == st[i])
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
	else {
		for (int i = 1; i <= n; i++)
		{
			st[k] = i;
			cout << k << " " << st[k] << " " << s << endl;
			if (valid(k))
			{
				cout << "VALID " << k << " " << st[k] << " " << s << endl;
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
