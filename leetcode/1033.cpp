#include <bits/stdc++.h>

using namespace std;

vector<int> numMovesStones(int a, int b, int c) {
    int aa = a, bb = b, cc = c;
    c = max(aa, max(bb, cc));
    a = min(aa, min(bb, cc));
    b = (aa+bb+cc)-a-c;
    cout<<a<<b<<c<<endl;
    int mmax = max(0, c-a-1-1), mmin = 0;
    int l = b-a-1, r = c-b-1;
    if(l >= 2 && r >= 2) mmin = 2;
    else mmin = min(1, mmax);
    return vector<int>{mmin, mmax};
}

int main()
{
    return 0;
}
