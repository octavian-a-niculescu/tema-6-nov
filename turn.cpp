#include <iostream>
#include <cstring>

using namespace std;

int n, st[10], termeni, h, suma;

struct cub {
	int inaltime, culoare;
} cuburi[15];

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
	else {
		if (cuburi[st[k]].inaltime > cuburi[st[k-1]].inaltime)
		{
			return 0;
		}
		if (cuburi[st[k]].culoare == cuburi[st[k-1]].culoare)
		{
			return 0;
		}
	}
	if (suma + st[k] > h)
	{
		return 0;
	}
	termeni++;
	suma += cuburi[st[k]].inaltime;
	return 1;
}

void back(int k)
{
	if (suma == h)
	{
		tipar(k);
		suma -= st[k];
		termeni--;
	}
	else {
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
	cin >> n >> h;
	for (int i = 1; i <= n; i++)
	{
		cin >> cuburi[i].inaltime >> cuburi[i].culoare;
	}
	back(1);
}
