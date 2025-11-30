#include <stdio.h>

#define MToKm 0.001

void convertMeters(float meters) {
		
	printf("Enter meters: ");
	scanf("%f", &meters);
    static int callCount = 0;
    callCount++;
    printf("%.2f meters = %.3f kilometers\n", meters, meters * MToKm);
    printf("Function called %d times.\n\n", callCount);
}

int main() {
	
	float meters;

    convertMeters(meters);
    convertMeters(meters);
    convertMeters(meters);
    return 0;
}

