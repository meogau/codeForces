#include <iostream>
#include <queue>
#include <algorithm>



#define M 11
#define N 31

using namespace std;

typedef pair<int, int> pi;

int m, n, res;
int pl[M], lot[M]; // preference_list, load of teacher
int cc[N]; // conflict courses, num of teachers in a course
int cwc = 0; // num of courses was choosed

void setData() {
    int k, x, y, temp;

    scanf("%d %d", &m, &n);
    for (int i = 1; i <= m; i++) {
        scanf("%d", &k);
        x = 0;
        for (int j = 0; j < k; j++) {
            scanf("%d", &temp);
            x |= (1<<temp);
        }
        pl[i] = x;
    }

    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        scanf("%d %d", &x, &y);
        cc[x] |= (1<<y);
        cc[y] |= (1<<x);
    }
}

int load_max() {
    return *max_element(lot + 1, lot + m + 1);
}

void run_recur(int i) {
    int k = 1<<i;
    for (int t = 1; t <= m; t++) {

        if (pl[t] & k) {
            if (lot[t] + 1 > res) continue;
            int temp = (cc[i]) & (pl[t]);

            ++lot[t];
            pl[t] ^= temp;

            if (i == n) {
                res = min(load_max(), res);
            }
            else {
                run_recur(i+1);
            }

            --lot[t];
            pl[t] |= temp;
        }
    }
}


int main()
{

    res = N + 1;

    setData();

//    auto start = steady_clock::now();

    run_recur(1);

    cout << (res > N ? -1 : res);
//    auto finish = steady_clock::now();
//
//    duration<double, std::milli> f = finish - start;
//    cout << endl << "Time: " << f.count();


    return 0;
}
