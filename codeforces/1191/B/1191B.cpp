#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<vector<int>> a(3, vector<int>(10, 0));
    for(int i = 0; i < 3; i++) {
        string s;
        cin >> s;
        if(s[1] == 'm') a[0][s[0]-'0']++;
        else if (s[1] == 'p') a[1][s[0]-'0']++;
        else a[2][s[0]-'0']++;
    }
    for(int i = 0; i < 3; i++) {
        for(int j = 1; j < 10; j++) {
            if(a[i][j] == 3) {
                cout << "0" << endl;
                return 0;
            }
            if(a[i][j] == 2) {
                cout << "1" <<endl;
                return 0;
            }
        }
        for(int j = 1; j < 10-2; j++) {
            if(a[i][j] && a[i][j+1] && a[i][j+2]) {
                cout << "0" <<endl;
                return 0;
            }
        }
        for(int j = 1; j < 10-1; j++) {
            if(a[i][j] && a[i][j+1]) {
                cout << "1" <<endl;
                return 0;
            }
        }
        for(int j = 1; j < 10-2; j++) {
            if(a[i][j] && a[i][j+2]) {
                cout << "1" <<endl;
                return 0;
            }
        }
    }
    cout << "2" << endl;
    return 0;
}
