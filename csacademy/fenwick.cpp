#include <bits/stdc++.h>

using namespace std;
#define LSB(i) ((i)&-(i))
const int SIZE = 5;

int A[SIZE];

int sum(int i)
{
        int sum = 0;
        while(i > 0){
                sum += A[i], i -= LSB(i);
        }
        return sum;
}

void add(int i, int p)
{
        while(i < SIZE){
                A[i] += p, i += LSB(i);
        }
}

int main()
{
        for(int i = 1; i < SIZE; i++)
                add(i, i);
        for(int i = 1; i < SIZE; i++)
                cout<<sum(i)<<endl;
        return 0;
}
