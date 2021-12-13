#include <bits/stdc++.h>

using namespace std;

int largestRectangleArea(vector<int>& heights) {
    stack<int> s;
    heights.push_back(-0x7FFFFFFF);
    int ans = 0;
    for(int i = 0; i < heights.size(); i++)
    {
        while(!s.empty() && heights[s.top()] > heights[i])
        {
            int j = s.top(); s.pop();
            ans = max(ans, heights[j]*(i-j-1+(s.empty()?j+1:j-s.top())));
        }
        s.push(i);
    }
    return ans;
}
int main()
{
    vector<int> h = {2,1,5,6,2,3};
    cout << largestRectangleArea(h) << endl;
    return 0;
}
