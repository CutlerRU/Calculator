#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//adds, subtracts, multiplies numbers of Marie Callahandifference bases

void reverse(char** c){
	for(int i = 0; i < (strlen(*c))/2; i++){
		char temp = (*c)[i];
		(*c)[i] = (*c)[strlen(*c) - i - 1];
		(*c)[strlen(*c) - i - 1] = temp;
	}
}

char leftover(char* c){
	if(c[strlen(c)-1] == '1')
		return '1';
	if(c[strlen(c)-1] == '3')
		return '1';
	if(c[strlen(c)-1] == '5')
		return '1';
	if(c[strlen(c)-1] == '7')
		return '1';
	if(c[strlen(c)-1] == '9')
		return '1';

	return '0';
}

char* multByTwo(char* num){
	//int digit, carry, i;
	//char* x = malloc(strlen(num)+2);
	return 0;
}

char* divByTwo(char* num){
	int digit, add, i;
	add = 0;
	char* x = malloc(strlen(num)+1);

	for(i = 0; i < strlen(num); i++){
		digit = num[i] - '0';
		x[i] = digit/2 + add + '0';
		if(digit % 2 == 1){
			add = 5;
		}else{
			add = 0;
		}
	}

	if(strlen(x) != 0 && x[0] == '0'){
		x[i] = '\0';
		x++;
	}else{
		x[i] = '\0';
	}

	if(strlen(x) == 0){
		free(x);
		return 0;
	}
	return x;
}

char* add(char* num1, char* num2){
	int i, j, max, a, b, carry = 0;
	i = strlen(num1);
	j = strlen(num2);
	if(strlen(num1) >= strlen(num2)){
		max = strlen(num1);
	}else{
		max = strlen(num2);
	}

	char* sum = malloc(max+2);
	sum[max+1] = '\0';
	for(i = strlen(num1)-1, j = strlen(num2)-1; max > 0; i--, j--, max--){
		if(i < 0){
			b = num2[j] - '0';
			sum[max] = (b^carry) + '0';
			carry = b&carry;
		}else if(j < 0){
			a = num1[i] - '0';
			sum[max] = (a^carry) + '0';
			carry = a&carry;
		}else{
			a = num1[i] - '0';
			b = num2[j] - '0';
			sum[max] = ((a^b)^carry) + '0';
			carry = a&b || a&carry || b&carry;
		}
	}
	if(carry == 1){
		sum[0] = '1';
	}else{
		sum++;
	}

	return sum;
}

char* decToBin(char* a){
	char* b = malloc(strlen(a)*4);
	int i;
	for(i = 0; a != 0; i++){
		b[i] = leftover(a);
		a = divByTwo(a);
	}
	b[i] = '\0';
	reverse(&b);
	return b;
}

char* binToDec(char* a){
	char* b = malloc(strlen(a));
	int i;
	for(i = 0; a != 0; i++){
		if(a[i] == '1'){

		}
	}
	b[i] = '\0';
	return b;
}

char * multiply(char* a, char* b){
	char* product = malloc((strlen(a) + strlen(b))*2);
	
}


int main(int argc, char** argv){
	char* op = argv[1];
	char* a = argv[2];
	char* b = argv[3];
	char* base = argv[4];

	printf("%s", op);

	if(strncmp("+", op, strlen(op)) == 0){
		if(a[0] == '-' && b[0] == '-'){
			a++;
			b++;
			a = decToBin(a);
			b = decToBin(b);
			printf("\n-%s + -%s = -%s\n", a, b, add(a,b));
		}
		else{
			a = decToBin(a);
			b = decToBin(b);
			printf("\n%s + %s = %s\n", a, b, add(a,b));
		}
	}else if(strncmp("-", op, strlen(op)) == 0){

	}else if(strncmp("*", op, strlen(op)) == 0){

	}else{
		printf("%s is not a valid operation!", op);
	}

	return 0;
}
