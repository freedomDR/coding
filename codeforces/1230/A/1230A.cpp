#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a1, a2, a3, a4;
    cin >> a1 >> a2 >> a3 >> a4;
    int as = 0, bs = 0;
    bool ans = false;
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 2; j++)
            for(int k = 0; k < 2; k++)
                for(int l = 0; l < 2; l++)
                {
                    if(i == 0) as += a1;
                    else bs += a1;
                    if(j == 0) as += a2;
                    else bs += a2;
                    if(k == 0) as += a3;
                    else bs += a3;
                    if(l == 0) as += a4;
                    else bs += a4;
                    if(as == bs) ans = true;
                    as = 0; bs = 0;
                }
    cout << (ans?"YES":"NO") << endl;
    return 0;
}

