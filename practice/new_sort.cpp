#include <bits/stdc++.h>
using namespace std;

void printVector(vector<int> & arr) {
    cout << "arr: ";
    for (auto & v:arr)
        cout << v << " ";
    cout << endl;
}

void quickSort(vector<int> & arr, int l, int r) {
    if (l >= r) return;
    int f = arr[l];
    int ll = l, rr = r;
    while (ll < rr) {
        while (ll < rr && arr[rr] > f) rr--;
        arr[ll] = arr[rr];
        while (ll < rr && arr[ll] <= f) ll++;
        arr[rr] = arr[ll];
    }
    arr[ll] = f;
    quickSort(arr, l, ll-1);
    quickSort(arr, ll+1, r);
}

void mergeSort(vector<int> & arr, int l, int r) {
    if (l >= r) return;
    int mid = l + (r-l)/2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid+1, r);
    vector<int> tmp;
    int i = l, j = mid+1;
    while (i <= mid && j <= r) {
        if (arr[i] < arr[j]) {
            tmp.push_back(arr[i++]);
        } else {
            tmp.push_back(arr[j++]);
        }
    }
    while (i <= mid) tmp.push_back(arr[i++]);
    while (j <= mid) tmp.push_back(arr[j++]);
    for (int i = 0; i < tmp.size(); i++) {
        arr[l+i] = tmp[i];
    }
}

void updateHeap(vector<int> & arr, int pos, int limit) {
    int dad = pos, son = 2*pos+1;
    while (son < limit) {
        if (son+1 < limit && arr[son] < arr[son+1]) son++;
        if (arr[dad] >= arr[son]) break;
        swap(arr[dad], arr[son]);
        dad = son; son = dad*2+1;
    }
}

void heapSort(vector<int> & arr) {
    int n = arr.size();
    for (int i = n/2-1; i >=0; i--) {
        updateHeap(arr, i, n);
    }
    for (int i = n-1; i > 0; i--) {
        swap(arr[0], arr[i]);
        updateHeap(arr, 0, i);
    }
}

int main()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 100);
    vector<int> arr;
    for (int i = 0; i < 20; i++) {
        arr.push_back(dis(gen));
    }
    printVector(arr);
    // quickSort(arr, 0, arr.size()-1);
    // mergeSort(arr, 0, arr.size()-1);
    heapSort(arr);
    printVector(arr);
    return 0;
}