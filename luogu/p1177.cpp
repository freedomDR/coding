#include <bits/stdc++.h>

using namespace std;
const int N = 100100;
int a[N], n;

void quick_sort(int l, int r)
{
    if(l >= r) return;
    swap(a[l], a[(l+r)/2]);
    int flag = a[l], ll = l, rr = r;
    while(l < r)
    {
        while(l<r&&a[r]>=flag) r--;
        a[l] = a[r];
        while(l<r&&a[l]<=flag) l++;
        a[r] = a[l];
    }
    a[l] = flag;
    if(l-1>ll)quick_sort(ll, l-1);
    if(rr>l+1)quick_sort(l+1, rr);
}
void quick_sort1(int left,int right)
{
    int i=left,j=right;
    int mid,temp;   
    mid=a[(i+j)/2];   
    while(i<j)
    {
        while(a[i]<mid)	i++;
        while(a[j]>mid)	j--;
        
        if(i<=j)
        {
            temp=a[i];a[i]=a[j];a[j]=temp;
            i++;j--;            
        }
    }
    if(left<j)	quick_sort(left,j);
    if(right>i)	quick_sort(i,right);
}
int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    sort(a, a+n);
    /* quick_sort(0, n-1); */
    /* quick_sort1(0, n-1); */
    for(int i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");
    return 0;
}
