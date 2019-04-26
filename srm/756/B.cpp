#include <bits/stdc++.h>

using namespace std;

class PAndPuns {
public:
    string check(string text)
    {
        bool ok = false;
        for(int i = 0; i < text.size()-1 && !ok; i++)
        {
            for(int j = i+2; j < text.size()-1 && !ok; j++)
            {
                if(text[i] == text[j] && text[i+1] == text[j+1]) ok = true;
            }
        }
        if(ok) return "pun";
        else return "not a pun";
    }

    string check1(string text)
    {
        bool ok = false;
        set<int> s;
        for(int i = 0; i < text.size()-2 && !ok; i++)
        {
            if(s.count((text[i+1]-'a')*26+text[i+2]-'a'))
            {
                ok = true;
            }
            s.insert((text[i]-'a')*26+text[i+1]-'a');
        }
        if(ok) return "pun";
        else return "not a pun";
    }
};


int main()
{
    PAndPuns* app = new PAndPuns();
    string text;
    cin>>text;
    cout<<"check of result is "<<(app->check(text))<<endl;
    cout<<"check1 of result is "<<(app->check1(text))<<endl;
    return 0;
}
