#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	char nombre[75];
	string pais;	
	map <string, set <string> > conq;

	scanf("%d", &n);
	while(n--)
	{
		cin >> pais;
		fgets(nombre, 75 - pais.size(), stdin);
		conq[pais].insert(nombre);
	}
	for(map <string, set <string> >::iterator it = conq.begin(); it != conq.end(); it++)
		cout << it->first << " " << conq[it->first].size() << '\n';
	
	return 0;
}
