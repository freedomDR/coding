#include<bits/stdc++.h>

using namespace std;

int s,v;
int main()
{
    cin >> s >> v;
    int need = (s-1)/v + 1;
    need += 10;
    int hour = 8-(need/60)-1;
    int minutes = 60 - need%60;
    if(hour < 0) hour = 24-abs(hour);
    if(hour < 10) cout << "0" << hour << ":";
    else cout << hour << ":";
    if(minutes < 10) cout << "0" << minutes;
    else cout << minutes;
    return 0;
}
