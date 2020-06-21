#include <bits/stdc++.h>
 

 
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;

 
int main() {
	int T, L, C;
	int temp;
 
	scanf("%d", &T);
	for (int t = 0; t < T; ++t) {
		vector<pii> bef;
		vector<pii> aft;
 
 
		scanf("%d %d", &L, &C);
		for (int i = 0; i < L; ++i) {
			for (int j = 0; j < C; ++j) {
				scanf("%d", &temp);
				if (temp) bef.push_back({i, j});
			}
		}
		for (int i = 0; i < L; ++i) {
			for (int j = 0; j < C; ++j) {
				scanf("%d", &temp);
				if (temp) aft.push_back({i, j});
			}
		}
 
		vvi dis(2000);
		int max = 0;
		for (int i = 0; i < 2000; i++) {
			dis[i].resize(2000);
		}
		for (pii e1: bef) {
			for (pii e2: aft) {
				temp = ++(dis[(e2.first - e1.first + 1000)][e2.second - e1.second + 1000]);
				if (temp > max) max = temp;
			}
		}
		printf("%d\n", max);
	}
 

 
	return 0;
}
