#include<bits/stdc++.h>
using namespace std;
int main()
{
    int N; cin >> N;
    vector<int> student(N);
    for(int i = 0; i < N; i++) cin >> student[i];
    int ans = N;
    vector<int> f(N, 1), e(N, 1);
    for(int i = 0; i < N; i++)
        for(int j = 0; j < i; j++)
            if(student[i] > student[j]) f[i] = max(f[i], f[j]+1);
    for(int i = N-1; i >= 0; i--)
        for(int j = N-1; j > i; j--)
            if(student[i] > student[j]) e[i] = max(e[i], e[j]+1);
    for(int i = 0; i < N; i++)
        ans = min(ans, N-(f[i]+e[i]-1));
    cout << ans << endl;
    return 0;
}
