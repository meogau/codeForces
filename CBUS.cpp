#include<bits/stdc++.h>
using namespace std;

const long long MAX_COST = 100000000; 
const int MAX_SIZE = 23;

int n, k, points, load;
long long cmin, min_cost, curr_cost;
long long a[MAX_SIZE][MAX_SIZE];
vector<bool> visited;

void init() {
    cin >> n >> k;
    points = n*2;

    load = 0;
    curr_cost = 0;
    cmin = MAX_COST;
    min_cost = MAX_COST;
    visited.assign(points+1, false);
    visited[0] = true;

    for (int i = 0; i <= points; i++) {
        for (int j = 0; j <= points; j++) {
            cin >> a[i][j];
            if (i != j) cmin = min(a[i][j], cmin);
        }
    }
}

int check_move(int pos, int load) {
    if (visited[pos]) return 0;
    if (pos > n) {
        if (!visited[pos-n]) return 0;
    } else {
        if (load == k) return 0;
    }

    return 1;
}

void Try(int i, int before_city) {
    for (int j = 1; j <= points; j++) {
        if (check_move(j, load)) {

            visited[j] = true;
            curr_cost += a[before_city][j];
            (j <= n) ? load++ : load--;

            if (curr_cost < min_cost) {
                if (i == points) {
                    if (curr_cost + a[j][0] < min_cost) {
                        min_cost = curr_cost + a[j][0];
                    }
                }
                else {
                    if (curr_cost + (points-i+1)*cmin < min_cost) Try(i+1, j);
                }

            }

            visited[j] = false;
            curr_cost -= a[before_city][j];
            (j <= n) ? load-- : load++;
        }
    }
}

int main() {
	init();

    Try(1, 0);
    if (min_cost != MAX_COST) cout << min_cost;

	return 0;
}
