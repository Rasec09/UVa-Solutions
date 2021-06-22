/*
* First, you must sort the dolls by their heights to reduce the searching area then use backtracking to try all possible placement.
*/
#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

struct doll {
	int h, d, w;
};

// return true if a fits inside b
bool fit(doll &a, doll &b) {
	if (a.h <= b.h - 2 * b.w and a.d <= b.d - 2 * b.w)
		return true;
	return false;
}

int n;
bool found;
vector<doll> munecas;

void backtracking(int idx, vector<doll> &setA, vector<doll> &setB) {
	if (setA.size() > n or setB.size() > n) return;
	if (idx == 2 * n) {
		if (setA.size() == n and setB.size() == n) {
			for (int i = int(setA.size()) - 1; i >= 0; i--)
				cout << setA[i].h << " " << setA[i].d << " " << setA[i].w << "\n";
			cout << "-\n";
			for (int i = int(setB.size()) - 1; i >= 0; i--)
				cout << setB[i].h << " " << setB[i].d << " " << setB[i].w << "\n";
			cout << "\n";
			found = true;
		}
		return;
	}
	else {
		if (!found) {			
			bool fitA = (setA.empty() or fit(setA.back(), munecas[idx]));
			bool fitB = (setB.empty() or fit(setB.back(), munecas[idx]));

			if (!fitA and !fitB) return;

			if (fitA)	{
				setA.push_back(munecas[idx]);
				backtracking(idx + 1, setA, setB);
				setA.pop_back();				
			}

			if (fitB) {
				setB.push_back(munecas[idx]);
				backtracking(idx + 1, setA, setB);
				setB.pop_back();		
			}
		
		}
	}
}

int main() {
	optimizar_io
	while (cin >> n, n) {
		munecas.assign(2 * n, {0,0,0});
		for (int i = 0; i < 2 * n; i++)
			cin >> munecas[i].h >> munecas[i].d >> munecas[i].w;
		sort(munecas.begin(), munecas.end(),
			[](const doll &a, const doll &b) -> bool {
				return a.h < b.h;
			});
		found = false;
		vector<doll> setA, setB;
		backtracking(0, setA, setB);
	}
	return 0;
}
/*
3
100 100 3
97 97 3
94 94 3
91 91 3
88 88 3
85 85 3
5
100 100 1
97 97 3
98 98 1
96 96 1
94 94 1
92 92 1
90 90 1
88 88 1
86 86 1
84 84 1
0
*/
