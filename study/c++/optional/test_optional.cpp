#include <bits/stdc++.h>

using namespace std;

template<typename T>
std::optional<T> create(T t)
{
    return {};
}

int main()
{
    // create
    auto string_val = create("1");
    auto int_val = create(1);
    cout << "string_val: " << *string_val << "\n";
    cout << "int_val: " << *int_val << "\n";
    if(string_val)
        cout << "not null" << "\n";
    else
        cout << string_val.value() << "\n"; // abort

    return 0;
}