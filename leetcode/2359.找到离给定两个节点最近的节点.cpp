/*
 * @lc app=leetcode.cn id=2359 lang=cpp
 *
 * [2359] 找到离给定两个节点最近的节点
 */

// @lc code=start
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int cnt1 = 0, cnt2 = 0;
        int n = edges.size();
        // ring
        int p1 = node1;
        vector<int> path1, path2;
        while (cnt1 < 2*n && p1 != -1) {
            path1.push_back(p1);
            if (p1==node2) break;
            p1 = edges[p1];
            cnt1++;
        }
        cout << "path1: ";
        for (auto v:path1) cout << v << " ";
        cout << endl; 
        // if(cnt==2*n) return -1;
        int p2 = node2;
        while (cnt2 < 2*n && p2 != -1) {
            path2.push_back(p2);
            if (p2==node1) break;
            p2 = edges[p2];
            cnt2++;
        }
        cout << "path2: ";
        for (auto v:path2) cout << v << " ";
        cout << endl; 
        // if(cnt==2*n) return -1;
        if (path1.back()==node2&&path2.back()==node1) {
            if (cnt1==cnt2) return min(node2, node1);
            return cnt1<cnt2?node2:node1;
        }
        if (path1.back()==node2) return node2;
        if (path2.back()==node1) return node1;
        if (path1.back()!=path2.back()) return -1;
        ranges::reverse(path1);
        ranges::reverse(path2);
        for (int i = 0; i < path1.size() && i < path2.size(); i++) {
            if (path1[i]!=path2[i]) return path1[i-1];
        }
        return path1[min(path1.size(), path2.size())-1];
    }
};

int main()
{
    vector<int> arr = {4,4,8,-1,9,8,4,4,1,1};
    Solution s;
    cout << s.closestMeetingNode(arr, 5, 6) << endl;
    return 0;
}
// @lc code=end

