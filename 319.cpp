#include <iostream>
#include <cstring>

using namespace std;

int n, st[10], termeni, h, suma, ultValid;

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
	if (k == 1)
	{
		termeni = 0;
		suma = 0;
	}
	if (st[k] == 4)
	{
		return 0;
	}
	if (suma + st[k] > n)
	{
		return 0;
	}
	termeni++;
	ultValid = st[k];
	suma += st[k];
	return 1;
}

void back(int k)
{
	if (suma == n)
	{
		tipar(termeni);
		suma -= ultValid;
		cout << "scazut" << endl;
		termeni--;
	}
	else {
		for (int i = 3; i <= 5; ++i)
		{
			st[k] = i;
			if (valid(k))
			{
				cout << "VALID" << k << " " << st[k] <<" " << suma << endl;
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
