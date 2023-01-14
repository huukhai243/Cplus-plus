#include<iostream>
using namespace std;

const int MAX =100;

int a[MAX],m,n;

void inday(){
	for(int i=1;i<=n;i++)
	cout <<" "<< a[i];
	cout<< endl;
	
}
 void sinh(int k)
{
	if(k>n)
	{
		inday();return;
		
	}
	for(int i=a[k-1]+1; i<=m+n;i++){
		a[k]=i; sinh(k+1);
	}
	
}
int main(){
	cout << "M=" ;cin >> m;
	cout << "N=" ;cin >> n;
	a[0]=0;
	sinh(1);
}
