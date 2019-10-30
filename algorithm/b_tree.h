#include<memory>
using namespace std;
class Tree;
typedef shared_ptr<Tree> ptr;
class Tree
{
    public:
        Tree(int val = 0):val(val){}
        ~Tree(){};
        bool addLeft(ptr node);
        bool addRight(ptr node);

    public:
        int val;
        ptr left;
        ptr right;
};
