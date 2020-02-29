#include<bits/stdc++.h>

using namespace std;

int main()
{
    int q;
    cin >> q;
    vector<int> arr;
    while(q--)
    {
        int opt, x;
        cin >> opt >> x;
        if(opt == 1)
        {
            auto pos = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
            cout << pos+1 << endl;
        }else if(opt == 2)
        {
            cout << arr[x-1] << endl;
        }else if(opt == 3)
        {
            auto pos = lower_bound(arr.begin(), arr.end(), x);
            cout << *(pos-1) << endl;
        }else if(opt == 4)
        {
            auto pos = upper_bound(arr.begin(), arr.end(), x);
            if(pos != arr.end())
                cout << *pos << endl;
            else 
                cout << "2147483647" << endl;
        }else
        {
            bool f = false;
            for(int i = 0; i < arr.size(); i++)
            {
                if(arr[i]>x)
                {
                    f = true;
                    arr.insert(arr.begin()+i, x);
                    break;
                }
            }
            if(!f) arr.push_back(x);
        }
    }
    return 0;
}

