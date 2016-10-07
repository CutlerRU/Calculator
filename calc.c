#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//adds, subtracts, multiplies numbers of difference bases

void reverse(char** c){
	for(int i = 0; i < (strlen(*c))/2; i++){
		char temp = (*c)[i];
		//printf("Temp = %c", temp);
		//printf("Swtich = %c", (*c)[strlen(*c) - i - 1]);
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

char* divByTwo(char* num){
	int digit, add, i;
	add = 0;
	char* x = malloc(strlen(num)+1);

	for(i = 0; i < strlen(num); i++){
		digit = num[i] - '0';
		//printf("The number is %d\n", digit);
		x[i] = digit/2 + add + '0';
		if(digit % 2 == 1){
			//printf("It made it here\n");
			add = 5;
		}else{
			add = 0;
		}
		//printf("The value of x[%d] is: %c", i, x[i]);
	}

	if(strlen(x) != 0 && x[0] == '0'){
		//printf("SWAGGG\n");
		x[i] = '\0';
		x++;
	}else{
		x[i] = '\0';
	}

	if(strlen(x) == 0){
		free(x);
		//printf("X was freed");
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


int main(int argc, char** argv){
	char* c = argv[2];
	char* d = malloc(strlen(c)*4);
	//printf("c = %s\n", c);
	char* a = argv[1];
	char* b = malloc(strlen(a)*4);
	int i = 0;
	//printf("HELLO");
	//printf("\n%s", divByTwo(a));
	for(i = 0; a != 0; i++){
		//printf("b[%d]= %c \n", i, leftover(a));
		b[i] = leftover(a);
		//printf("\n%s", a);
		a = divByTwo(a);
		//printf("Step %d: %s\n", i, a);
		//printf("Strlen[%d] = %c" , strlen(a) ,a[strlen(a) -1]);
	}
	b[i] = '\0';
	//printf("The value is = %s", b);
	reverse(&b);
	//printf("HELLO");
	for(i = 0; c != 0; i++){
		//printf("b[%d]= %c \n", i, leftover(a));
		d[i] = leftover(c);
		//printf("\n%s", a);
		c = divByTwo(c);
		//printf("Step %d: %s\n", i, a);
		//printf("Strlen[%d] = %c" , strlen(a) ,a[strlen(a) -1]);
	}
	d[i] = '\0';
	//printf("The value is = %s", d);
	reverse(&d);

	printf("\n%s + %s = %s\n", b, d, add(b,d));

	return 0;
}
