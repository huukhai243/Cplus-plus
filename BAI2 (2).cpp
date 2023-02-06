#include <bits/stdc++.h>
using namespace std;
multiset<int> arr;
int n, temp;
string query;
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        arr.insert(temp);
    }
    while (true)
    {
        cin >> query;
        if (query == "*")
            break;
        if (query == "insert") // them phần tử vào multiset
        {
            cin >> temp;
            arr.insert(temp);
        }
        else if (query == "delete-max") // xóa phần tử cuối cùng - phần tử lớn nhất
        {
            cout << *--arr.end() << endl;
            arr.erase(--arr.end());
        }
        else
            break;
    }
}