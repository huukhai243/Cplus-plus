#include<iostream>
using namespace std;

int dem =0, dem2 =0;
int fibo(int n){
	if(n<2)
	return n;
	dem++;
	return fibo(n-1)+fibo(n-2);
}
const int MAX =100;
int f[MAX];

int fibo2(int n){
	if(n <2) return n;
	dem2++;
	
	if (f[n] == -1) f[n] =fibo2(n-1) +fibo2(n-2);
	
	return f[n];
}

int main(){
	for(int i=0;i<MAX;i++) f[i] =-1;
    cout<< fibo2(45)<<endl;
	cout<< "So lan goi ham: "<< dem2 << endl;
	
	cout<< fibo(45) << endl;
	cout<< "So lan goi ham: " << dem << endl;
	}
