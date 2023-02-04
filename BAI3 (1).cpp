#include <bits/stdc++.h>
using namespace std;
int arr[100007];
int n;
int findmaxsum()
{
    int ans[n];
    if (n >= 1)
        ans[0] = arr[0];
    if (n >= 2)
        ans[1] = arr[0] + arr[1];
    if (n > 2)
        ans[2] = max(ans[1], max(arr[1] + arr[2], arr[0] + arr[2]));
    for (int i = 3; i < n; i++)
        ans[i] = max(max(ans[i - 1], ans[i - 2] + arr[i]), arr[i] + arr[i - 1] + ans[i - 3]);
    return ans[n - 1];
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << findmaxsum();
    return 0;
}