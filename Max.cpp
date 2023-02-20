#include <bits/stdc++.h>
using namespace std;
 
int vt1, vt2, vt;
int maxleft (int a[], int i, int j)
{
    int maxsum = 0;
    int sum = 0;
    for (int k = j; k >= i; k--){
        sum = sum + a[k];
        if(sum > maxsum) {
            maxsum = sum;
            vt1 = k;
        }
    }
    return maxsum;
}
int maxright (int a[], int i, int j){
    int maxsum = 0;
    int sum = 0;
    for (int k = i; k <= j; k++){
        sum = sum + a[k];
        if(sum > maxsum) {
            maxsum = sum;
            vt2 = k;
        }
    }
    return maxsum;
}
int maxsub(int a[], int i, int j){
    if (i == j) return a[i];
    int m = (i + j)/2;
    int wL = maxsub (a, i, m);
    int wR = maxsub (a, m+1, j);
    int wM = maxleft(a, i, m) + maxright(a, m+1, j);
    if(wL > wR) vt = vt1;
    else vt = vt2;
    return max (max(wL, wR), wM);
}
int main ()
{
    int N;
   cin >> N;
     int a[N];
   for(int i = 0; i < N; i++) cin >> a[i];
     
     
    int a[]={-5,0,-4,1,5,-2,5};
    int N = sizeof(a)/4;
     
     
    int sum = maxsub (a, 0, N-1);
    cout << sum << endl;
    for(int i = vt; i >= 0; i--) {
        if(sum > 0) {
            cout << a[i] << " ";
            sum -= a[i];
        }
    }
    return 0;
}
