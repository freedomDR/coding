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
            return res;
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
    FenWick t(10);
    for(int i = 1; i < 10; i++)
    {
        t.add(i, i);
        std::cout << t.get(i) << std::endl;
    }
    return 0;
}