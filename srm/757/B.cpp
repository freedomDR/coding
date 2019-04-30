#include <bits/stdc++.h>

using namespace std;

class FillInTheMaze{
public:
    vector<string> filled(int R, int C, int X){
        vector<string> g(2*R+1, string(2*C+1, '#'));
        for(int i = 1; i < 2*R; i += 2) {
            for(int j = 1; j < 2*C; ++j) {
                g[i][j] = '.';
            }
        }
        for(int i = 2; i < 2*R; i++) {
            g[i][1] = '.';
        }
        for(int i = 1; i < 2*R && X > 0; i += 2) {
            if(X > 0) {g[i][0] = '.'; X--;}
            if(X > 0) {g[i][2*C] = '.'; X--;}
        }
        for(int i = 1; i < 2*C+1 && X > 0; i += 2) {
            if(X > 0) {g[0][i] = '.'; X--;}
            if(X > 0) {g[2*R][i] = '.'; X--;}
        }
        return g;
    }
};

int main()
{
    FillInTheMaze* app = new FillInTheMaze();
    int R, C, X; cin>>R>>C>>X;
    vector<string> s = app->filled(R, C, X);
    for(string v:s) cout<<v<<endl;
    return 0;
}
