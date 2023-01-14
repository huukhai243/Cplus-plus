#include<iostream>
using namespace std;

const int MAX =100;
int a[MAX],n;

void print (int n){
	for(int i=1;i<=n;i++)
	cout << a[i];
	cout << endl;
}

void gen(int k){
	if(k>n){
		printf();
		return;
	}
	a[k]=0;gen(k+1);
	a[k]=1;gen(k+1);
}

int main(){
	n=5;
	gen(1);
}

