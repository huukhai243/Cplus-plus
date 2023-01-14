#include<iostream>
using namespace std;

const int MAX = 100;
int nhap[MAX][MAX];

int C(int k,int n){
	if(k==n||k==0)
	return 1;
	else return C(k-1,n-1)+C(k,n-1);
	
}
 int C2(int k,int n){
 	if(k == n || k == 0) return 1;
 	
 	if(nhap[k][n] == -1)
 	  nhap[k][n] = C2(k-1,n-1) +C2(k,n-1);
 	  
 	  return nhap[k][n];
 	  
 }
  int main(){
  	for (int i=0; i<MAX;i++)
  	   for (int j=0; j< MAX; j++)
  	   nhap[i][j] =-1;
  	   cout << C2(20,32);
  	   
  }
