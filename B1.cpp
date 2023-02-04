#include<iostream>
using namespace std;

int check[10] = {0};
int Q = 0;
int Tinh(int* a){
    return a[0]*100 + a[1]*10 + a[2] - (a[3]*100 + 62) + a[4]*1000 + a[5]*100 + a[6]*10 + a[2];
}
void Dem(int x, int *a, int n){
    if(x == 7){
        if(Tinh(a) == n){
            Q++;
            
        }
        return;
    }
    for(int i=1; i<=9; i++)
        if(check[i] == 0){
            a[x] = i;
            check[i] = 1;
            Dem(x + 1, a, n);
            check[i] = 0;
        }
}
int main(){
    int n;
    cin >> n;
    int a[8];
    Dem(0, a, n);
    cout << Q;
}
