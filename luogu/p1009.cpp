#include <bits/stdc++.h>

using namespace std;

void countV(int v, vector<int>& vi)
{
    while(v != 0)
    {
        vi[v%10]++;v/=10;
    }
}

int main()
{
    vector<int> visit(10, 0);
    for(int i = 1; i <= 9; i++)
    {
        for(int j = 1; j <= 9; j++)
        {
            for(int k = 1; k <= 9; k++)
            {
                int v = i*100+j*10+k;
                countV(v, visit);
                countV(v*2, visit);
                countV(v*3, visit);
                if(all_of(visit.begin()+1, visit.end(), [](int c){return c == 1;}))
                   cout<<v<<" "<<(v*2)<<" "<<(v*3)<<endl;
                for(int i = 0; i < 10; i++) visit[i] = 0;
            }
        }
    }
    return 0;
}
