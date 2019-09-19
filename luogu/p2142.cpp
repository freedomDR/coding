#include<bits/stdc++.h>
using namespace std;
int main()
{
    string a, b;
    cin >> a >> b;
    if(a == b)
    {
        cout << "0" << endl;
        return 0;
    }
    int a_symbol = (a[0] == '-'?-1:1);
    int b_symbol = (b[0] == '-'?-1:1);
    b_symbol *= -1;
    if(a[0] == '-') a = a.substr(1);
    if(b[0] == '-') b = b.substr(1);
    std::reverse(a.begin(), a.end());
    std::reverse(b.begin(), b.end());
    vector<int> a_arr(a.size()), b_arr(b.size());
    for(int i = 0; i < (int)a.size(); i++)
    {
        a_arr[i] = a[i]-'0'; 
    }
    for(int i = 0; i < (int)b.size(); i++)
    {
        b_arr[i] = b[i]-'0'; 
    }
    vector<int> c_arr(10500);
    int ai = 0, bi = 0, ci = 0;
    while(ai < (int)a_arr.size() && bi < (int)b_arr.size())
    {
        c_arr[ci] += a_arr[ai]*a_symbol + b_arr[bi]*b_symbol;
        if(c_arr[ci] > 9)
        {
            c_arr[ci+1] += 1;
            c_arr[ci] -= 9;
        }
        else if(c_arr[ci] < 0)
        {
            c_arr[ci+1] -= 1;
            c_arr[ci] += 10; 
        }
        ai++;bi++;ci++;
    }
    while(ai < (int)a_arr.size())
    {
        c_arr[ci] += a_arr[ai]*a_symbol;
        if(c_arr[ci] > 9)
        {
            c_arr[ci+1] += 1;
            c_arr[ci] -= 9;
        }
        else if(c_arr[ci] < 0)
        {
            c_arr[ci+1] -= 1;
            c_arr[ci] += 10; 
        }
        ai++;ci++;
    }
    while(bi < (int)b_arr.size())
    {
        c_arr[ci] += b_arr[bi]*b_symbol;
        if(c_arr[ci] > 9)
        {
            c_arr[ci+1] += 1;
            c_arr[ci] -= 9;
        }
        else if(c_arr[ci] < 0)
        {
            c_arr[ci+1] -= 1;
            c_arr[ci] += 10; 
        }
        bi++;ci++;
    }
    int c_symbol = 1, c_len = 0;
    if(c_arr[ci] == 0) 
    {
        c_len = (ci-1)+1;   
    }
    else if(c_arr[ci] == -1) 
    {
        c_arr[ci] = 1;
        c_len = (ci-1)+1;
        c_symbol = -1;
        ci--;
        while(ci >= 0)
        {
            if(c_arr[ci] != 0)
            {
                c_arr[ci] = 10 - c_arr[ci];
                int pos = ci+1;
                c_arr[pos]--;
                while(c_arr[pos] < 0)
                {
                    c_arr[pos] = 10 + c_arr[pos];
                    pos++;
                    c_arr[pos]--;
                }
            }
            ci--;
        }
    }
    else
    {
        c_len = ci+1;
    }
    cout << (c_symbol == 1?"":"-");
    for(int i = c_len-1, can = 0; i >= 0; i--)
        if(can)
            cout << c_arr[i];
        else
        {
            if(c_arr[i] != 0)
            {
                can = 1;
                cout << c_arr[i];
            }
        }
    cout << endl;
    return 0;
}
