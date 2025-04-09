#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis_x(1, 5000);
    uniform_int_distribution<> dis_k(1, 3);

    while(t--) {
        int x, k;
        // cin >> x >> k;
        x = dis_x(gen);
        k = dis_k(gen);
        auto isPrime = [](int x) {
            if (x < 2) return false;
            for (int i = 2; i*i <= x; i++) {
                if (x % i == 0) return false;
            }
            return true;
        };
        auto isPrime2 = [](long long x, int k) {
            int ori_x = x;
            int xx = 1;
            while(x) {
                xx *= 10;
                x = x/10;
            }
            x = ori_x;
            for(int i = 0; i < k-1; i++) {
                x = x*xx + ori_x;
            }

            if (x < 2) return false;
            for (long long i = 2; i*i <= x; i++) {
                if (x % i == 0) return false;
            }
            return true;
        };
        string result1 = ((k==1&&isPrime(x))?"YES":"NO");
        string result2 = (isPrime2(x, k)?"YES":"NO");
        if (result1 != result2) {
            cout << "x: " << x << ", k: " << k << endl;
            cout << "isPrime: " << result1 << ", isPrime2: " << result2 << endl;
        }
    }
    return 0;
}