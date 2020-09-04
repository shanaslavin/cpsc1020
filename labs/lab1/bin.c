// Shana Slavin
// CPSC1020 Sec 04
// Lab 1
// Converting base 10 numbers to binary

#include <stdio.h>

	void int_to_bin(int basenum, int binary[8]);
	void print_bin(int basenum, int binary[8]);
	
	int main(void){
		int basenum = 0;
		int binary[8];
		
		
		printf("Enter a base 10 number to be converted to binary: ");
		scanf("%i", &basenum);
		
		int_to_bin(basenum, binary);
		print_bin(basenum, binary);

		return 0;
}

void int_to_bin(int basenum, int binary[8]){
	int i;
	
	for(i = 0; i <= 7; i++){
		binary[i] = basenum % 2;
		basenum = basenum / 2;
		
	}

}

void print_bin(int basenum, int binary[8]){
	int i;

	printf("You're binary number is: ");

	for(i = 7; i >= 0; i--){
		printf("%d", binary[i]);

	
	}
		
	printf("\n");

}
