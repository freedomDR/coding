#include <bits/stdc++.h>
#include <algorithm>
#include <ranges>
#include <vector>

using namespace std;

void testGenerateVector() 
{
    auto arr_view = (views::iota(1, 10));
    auto arr_vector = vector(arr_view.begin(), arr_view.end());
    for_each(arr_view.begin(), arr_view.end(), [](int a) {cout << "vector: " << a << endl;});
    auto arr_set = set(arr_view.begin(), arr_view.end());
    ranges::for_each(arr_view, [](int i) {cout << "view: " << i << endl;});
    ranges::for_each(arr_set, [](int i) {cout << "set: " << i << endl;});
}

int main()
{
    testGenerateVector();
    return 0;
}