#include <stdio.h>

int sum(int n);

int main(){
	
	int n;
	printf("Enter a number: ");
	scanf("%d",&n);
	
	printf("The sum of the digits you entered are: %d", sum(n));
	
	return 0;
}

int sum(int n){
	
	if (n==0){
		return 0;
	}

	return n%10 +sum(n/10);
}
