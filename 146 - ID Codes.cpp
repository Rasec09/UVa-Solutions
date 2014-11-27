#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int main()
{
	char code[52];
	string s; 

	while(1)
	{
		cin >> s;
		if(s == "#") break;
		strcpy(code, s.c_str());
		if(next_permutation(code, code+(int)strlen(code)))
			cout << code << "\n";
		else
			cout << "No Successor\n";
	}
	return 0;
}
