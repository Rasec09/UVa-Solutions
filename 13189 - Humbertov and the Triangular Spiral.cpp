/*
* Solution: read all queries and sort then jump over y-axis until find correct subtriangle
* and finally find if the point is in the base or the sides.
* Beware with the same querie asked multiple times
*/
#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;

int main() {
    optimizar_io
    int t;
 	ll N, curr = 1, diff = 2, next = 3;
 	vector<ll> queries, original;
 	map<ll,pair<int,int>> ans;

 	cin >> t;
 	original.assign(t, 0);
 	queries.assign(t, 0);
 	for (int i = 0; i < t; i++) {
 		cin >> N;
 		original[i] = N;
 		queries[i] = N;
 	}
 	sort(queries.begin(), queries.end());
 	ll x = 0, y = 0, pos = 0, base = 1;
 	while (pos < t) {
 		while (queries[pos] >= next) {
 			curr = next;
 			diff += 2;
 			next = curr + diff;
 			if (base) {
 				y *= -1;
 				y++;
 			}
 			else {
 				y *= -1;
 			}
 			base = 1 - base;
 		}
 		ll k = curr;
 		if (pos < t and k == queries[pos]) {
			ans[queries[pos]] = make_pair(x, y);
		 	pos++;
		}
 		if (base) {
 			while (pos < t and queries[pos] <= k + (diff >> 1LL)) {
 				ll _x = x - (queries[pos] - k);
 				ans[queries[pos]] = make_pair(_x, y);
 				pos++;
 			}
 			k += (diff >> 1LL);
 			x -= (diff >> 1LL);
 			
 			while (pos < t and queries[pos] <= k + (diff >> 1LL)) {
 				ll _x = x + (queries[pos] - k);
 				ll _y = y + (queries[pos] - k);
 				ans[queries[pos]] = make_pair(_x, _y);
		 		pos++;
 			}
 			k += (diff >> 1LL);
 			x += (diff >> 1LL);
 			y += (diff >> 1LL);
 		}
 		else {
 			while (pos < t and queries[pos] <= k + (diff >> 1LL)) {
 				ll _x = x + (queries[pos] - k);
 				ll _y = y - (queries[pos] - k);
 				ans[queries[pos]] = make_pair(_x, _y);
 				pos++;
 			}
 			k += (diff >> 1);
 			x += (diff >> 1);
 			y -= (diff >> 1);

 			while (pos < t and queries[pos] <= k + (diff >> 1LL)) {
				ll _x = x - (queries[pos] - k);
				ans[queries[pos]] = make_pair(_x, y);
 				pos++;
			}
 			k += (diff >> 1LL);
 			x -= (diff >> 1LL);
 		}
 		base = 1 - base;
 		curr = next;
 		diff += 2;
 		next = curr + diff;
 	}
 	for (int i = 0; i < original.size(); i++) {
 		cout << ans[original[i]].first << " " << ans[original[i]].second << "\n";
 	}
    return 0;
}
