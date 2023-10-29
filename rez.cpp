#include <fstream>
#define LGMAX 1001
using namespace std;
ifstream fin("rez.in");
ofstream fout("rez.out");
// variabile globale
char s[LGMAX];
int lg, poz;
// functii ajutatoare
bool cifra(char);
int evalCircuitSerie();
int evalCircuitParalel();
// functia principala
int main()
{
	fin >> s;
	fin.close();
	for (lg = 0; s[lg]; lg++);
	fout << evalCircuitSerie();
	fout.close();
	return 0;
}
int evalCircuitParalel()
{
	int suma=0, produs=1, nr;
	while (s[poz] != ')')
	{
		poz++;
		nr = evalCircuitSerie();
		suma += nr;
		produs *= nr;
	}
	poz++;
	return produs/suma;
}
bool cifra(char c)
{
	return c >= '0' && c <= '9';
}
int evalCircuitSerie()
{
	int nr, suma=0;
	if (poz >= lg || s[poz] == ',' || s[poz] == ')') return 0;
	while (poz < lg && s[poz] != ',' && s[poz] != ')')
	{
		if (s[poz] == 'R')
		{
			poz++;
			nr = s[poz]-'0';
			poz++;
			if (cifra(s[poz]))
			{
				nr = nr*10 + s[poz]-'0';
				poz++;
			}
			suma += nr;
		}
		else
		{
			suma += evalCircuitParalel();
		}
	}
	return suma;
}
