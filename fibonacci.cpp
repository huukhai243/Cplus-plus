#include<stdio.h>
#include<math.h>
 int main(){
 	long long int a=1,b=2,n;
 	printf("%lld\n%lld\n",a,b);
 	for(n=1;n<=100000000;n++){
 		n=a+b;
 		b=a;
 		a=n;
 		printf("%lld",n);
 		printf("\n");
	 }
      
 		
 		
	 }
 
