#include<iostream>
using namespace std;

const int MAX =100;

int n,a[MAX],dem=0;
bool b[MAX],c[MAX],d[MAX];

void inketqua(){
	cout<<"Cach dat hau thu "<<++dem<<endl;
	for(int i=1;i<=n;i++,cout<<endl)
	    for(int j=1;j<=n;j++)
	    if(j==a[i])
	    cout<<"x";
	    else cout <<" .";
	    
}

void dat(int k){
	if(k>n){
		inketqua();return;
	}
	for(int i=1;i<=n;i++)
	if(b[i] && c[n+k-i] && d[k+i]){
		a[k]=i;
		dat(k+1);
	}
}

int main(){
	cout<<"N= ";
	cin>>n;
	for(int i=0;i<MAX;i++)
	b[i]=c[i]=d[i]=true;
	dat(1);
	
}
