#include <iostream>
#include <map>
using namespace std;
 
int n,k;
map<int, long long> positive_side, negative_side;

long long run() {
    long long res = 0;
    map<int, long long>::iterator it = negative_side.begin();
    map<int, long long>::reverse_iterator rit = positive_side.rbegin();
 
    int mod = 0;
    while (it != negative_side.end()) {
        long long weight = it->second;
        if (mod < weight) {
            weight -= mod;
            if (weight%k != 0) {
                mod = k - weight%k;
            }
            else mod = 0;
            int num_of_move = weight/k + (mod ? 1 : 0);
            res += (long long) (num_of_move << 1)*(-it->first);
        }
        else {
            mod -= weight;
        }
        it++;
    }
 
    mod = 0;
    while (rit != positive_side.rend()) {
        int weight = rit->second;
        if (mod < weight) {
            weight -= mod;
            if (weight%k != 0) {
                mod = k - weight%k;
            }
            else mod = 0;
            int num_of_move = weight/k + (mod ? 1 : 0);
            res += (long long) (num_of_move << 1)*(rit->first);
        }
        else {
            mod -= weight;
        }
        rit++;
    }
 
    return res;
}
 
int main() {
	cin >> n >> k;
 
    int x, m;
    for (int i = 0; i < n; i++) {
        cin >> x >> m;
        if (x > 0) {
            positive_side[x] += m;
        }
        else {
            negative_side[x] += m;
        }
    }
    long long res = run();
    cout << res;
}
