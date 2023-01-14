#include<iostream>
using namespace std;

int n,r;
int f(int n){

 if(n<3)return n;
 int k =n/3;
 if(n%3 == 0)
 return r = f(2*k);
 if(n%3 == 1)
 return f(2*k) +f(2*k+1);

 if(n%3==2)
 return f(2*k)+f(2*k+1)+f(2*k+2);

 return r;
}

int main(){
	cout << "Nhap n =" ;cin >>n;
	cout << "f("<< n <<")=" <<f(n);
}
