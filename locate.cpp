#include <bits/stdc++.h>
#define pii pair<int, int> 

using namespace std;
int numOfTest;

typedef vector<int> vecint;
typedef vector<vecint> vecintint;
int main() {
  
  int L, C;

	cin>>numOfTest;
	for (int t = 0; t < numOfTest; ++t){
	int res = 0;
	vector <pii> p1, p2;
	cin >> L;
	cin >> C;
     int n;
     int tm;
    for  (int i = 0; i < L; i++) {
        for (int j = 0;j< C; j++) {
            scanf("%d", &n);
            if (n) {
                p1.push_back({i, j});
            }
        }
    }
     for  (int i = 0; i < L; i++) {
        for (int j = 0;j< C; j++) {
            scanf("%d", &n);
            if (n) {
                p2.push_back({i, j});
            }
        }
    }
    vecintint v(2000);
    for (int i = 0; i < 2000; i++) {
			v[i].resize(2000);
		}
    for (pii e1: p1){
        for (pii e2: p2) {
                int x = e2.first - e1.first +1000;
                int y = e2.second - e1.second +1000;
                tm = ++v[x][y];
               if(tm>res) res = tm;
        }
    }


	

    cout << res<<endl;	
	}
    
    return 0;
}
