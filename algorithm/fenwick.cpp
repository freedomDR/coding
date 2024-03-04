#include <bits/stdc++.h>
#include <vector>

using namespace std;

class FenWick
{
    public:
        FenWick(int sz_): tree(sz_) {}

        void add(int pos, int add_val)
        {
            while(pos < tree.size())
            {
                tree[pos] += add_val;
                pos += lowbit(pos);
            }
        }

        int get(int pos)
        {
            int res = 0;
            while(pos > 0)
            {
                res += tree[pos];
                pos -= lowbit(pos);
            }
        }

    private:
        std::vector<int> tree;
        inline int lowbit(int x)
        {
            return x & -x;
        }
};

int main()
{
    return 0;
}