#include <iostream>
 
using namespace std;
 
int N;
 
int x[1000];
 
void in(int x[]){
    for (int i = 1; i <= N; i++)
        cout << x[i];
    cout << endl;
}
 
void deQuy(int i){
    for (int j = 0; j <= 1; j++){
        x[i] = j;
        if (i == N)
            in(x);
        else
            deQuy(i + 1);
        
    }
}
 
int main(){
    cin >> N;
    deQuy(1);
}
