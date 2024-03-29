#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//adds, subtracts, multiplies numbers of and difference bases

void reverse(char** c){
	int i;
	for(i = 0; i < (strlen(*c))/2; i++){
		char temp = (*c)[i];
		(*c)[i] = (*c)[strlen(*c) - i - 1];
		(*c)[strlen(*c) - i - 1] = temp;
	}
}

void prepend(char* s, const char* t)
{
    size_t len = strlen(t);
    size_t i;

    memmove(s + len, s, strlen(s) + 1);

    for (i = 0; i < len; ++i)
    {
        s[i] = t[i];
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
	int digit, i;
	int j = 0;
	int carry = 0;
	char* x = malloc(strlen(num)+2);
	for(i = 0; i < strlen(num); j++, i++){
		digit = num[i] - '0';
		//printf("The value of digit is: %d\n", digit);
		digit = digit*2;
		//printf("The value of digitx2 is: %d\n", digit);
		if(digit >= 10){
			//printf("The value is > 10");
			x[j] = digit%10 + '0';
			x[j] = x[j] + carry;
			carry = 1;
		}else{
			//printf("The value is < 10");
			x[j] = digit + '0';
			x[j] = x[j] + carry;
			carry = 0;
		}
	}
	//printf("The value of j is %d and carry is %d\n", j, carry);
	if(carry == 1){
		//printf("IT GOT HERE!!!");
		x[j] = carry + '0';
		x[j+1] = '\0';
	}else{
		x[j] = '\0';
	}

	//printf("\n\n%s\n\n", x);
	return x;
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

	if(strlen(num1) == 0 || strlen(num2) == 0){
		sum[0] = '\0';
		return sum;
	}

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

char* subtract(char* a, char* b){
	int i, digit, sub, j;
	//printf("%s - %s\n", a, b);
	char* c = malloc(strlen(a)+strlen(b));

	if(strcmp(a,b) == 0){
		free(c);
		return "0";
	}else{
		for(i = 0; strlen(b) > 0; i++){
			digit = a[strlen(a)-1] - '0';
			sub = b[strlen(b)-1] - '0';
			if(digit == 0 && sub == 1){
				digit = 2;
				for(j = strlen(a) - 2; a[j] != '1'; j--){
					a[j] = '1';
				}
				a[j] = '0';
			}
			
			c[i] = digit - sub + '0';
			a[strlen(a) - 1] = '\0';
			b[strlen(b) - 1] = '\0';
		}
	}
	//printf("%s\n", c);
	reverse(&a);
	strcat(c, a);
	reverse(&c);
	while(c[0] != '1'){
		c++;
	}
	return c;
}

char* hexToBin(char* a){
	char* b = malloc(strlen(a)*4);
	int i;

	if(strlen(a) == 0){
		b[0] = '\0';
		return b;
	}

	for(i = 0; i < strlen(a); i++){
		switch(a[i]){
			case '0':
				strncat(b, "0000",4);
				break;

			case '1':
				strncat(b, "0001",4);
				break;

			case '2':
				strncat(b, "0010",4);
				break;

			case '3':
				strncat(b, "0011",4);
				break;

			case '4':
				strncat(b, "0100",4);
				break;

			case '5':
				strncat(b, "0101",4);
				break;

			case '6':
				strncat(b, "0110",4);
				break;

			case '7':
				strncat(b, "0111",4);
				break;

			case '8':
				strncat(b, "1000",4);
				break;

			case '9':
				strncat(b, "1001",4);
				break;

			case 'a':
			case 'A':
				strncat(b, "1010",4);
				break;

			case 'b':
			case 'B':
				strncat(b, "1011",4);
				break;

			case 'c':
			case 'C':
				strncat(b, "1100",4);
				break;

			case 'd':
			case 'D':
				strncat(b, "1101",4);
				break;

			case 'e':
			case 'E':
				strncat(b, "1110",4);
				break;

			case 'f':
			case 'F':
				strncat(b, "1111",4);
				break;

		}
	}
	while(b[0] == '0' && strlen(b) > 1){
		b++;
	}
	//printf("\n%s\n", b);
	return b;
}

char* binToHex(char* s){
	char* a = malloc(strlen(s)+4);
	//printf("%s is %d digits\n", s, strlen(s));
	if(strlen(s) == 0){
		a[0] = '\0';
		return a;
	}

	strcpy(a, s);
	while(strlen(a) % 4 != 0){
		prepend(a, "0");
	}

	char* b = malloc(strlen(a)/4);
	for(int i = 0; strlen(a) > 0; i++){
		char test[4];
		strncpy(test, a, 4);
			if(strncmp(test, "0000", 4) == 0){
				b[i] = '0';
			}else if(strncmp(test, "0001", 4) == 0){
				b[i] = '1';
			}else if(strncmp(test, "0010", 4) == 0){
				b[i] = '2';
			}else if(strncmp(test, "0011", 4) == 0){
				b[i] = '3';
			}else if(strncmp(test, "0100", 4) == 0){
				b[i] = '4';
			}else if(strncmp(test, "0101", 4) == 0){
				b[i] = '5';
			}else if(strncmp(test, "0110", 4) == 0){
				b[i] = '6';
			}else if(strncmp(test, "0111", 4) == 0){
				b[i] = '7';
			}else if(strncmp(test, "1000", 4) == 0){
				b[i] = '8';
			}else if(strncmp(test, "1001", 4) == 0){
				b[i] = '9';
			}else if(strncmp(test, "1010", 4) == 0){
				b[i] = 'a';
			}else if(strncmp(test, "1011", 4) == 0){
				b[i] = 'b';
			}else if(strncmp(test, "1100", 4) == 0){
				b[i] = 'c';
			}else if(strncmp(test, "1101", 4) == 0){
				b[i] = 'd';
			}else if(strncmp(test, "1110", 4) == 0){
				b[i] = 'e';
			}else if(strncmp(test, "1111", 4) == 0){
				b[i] = 'f';
			}
			a+= 4;
		}
	//free(a);
	while(b[0] == '0' && strlen(b) > 1){
		b++;
	}
	//printf("\n%s\n", b);
	return b;
}

char* octToBin(char* a){
	char* b = malloc(strlen(a)*3);
	int i;

	if(strlen(a) == 0){
		b[0] = '\0';
		return b;
	}

	for(i = 0; i < strlen(a); i++){
		switch(a[i]){
			case '0':
				strncat(b, "000",3);
				break;

			case '1':
				strncat(b, "001",3);
				break;

			case '2':
				strncat(b, "010",3);
				break;

			case '3':
				strncat(b, "011",3);
				break;

			case '4':
				strncat(b, "100",3);
				break;

			case '5':
				strncat(b, "101",3);
				break;

			case '6':
				strncat(b, "110",3);
				break;

			case '7':
				strncat(b, "111",3);
				break;
			}
		}
	while(b[0] == '0'){
		b++;
	}
	return b;
}

char* binToOct(char* s){
	char* a = malloc(strlen(s)+3);

	if(strlen(s) == 0){
		a[0] = '\0';
		return a;
	}

	strcpy(a, s);
	while(strlen(a) % 3 != 0){
		prepend(a, "0");
	}

	char* b = malloc(strlen(a)/3);
	for(int i = 0; strlen(a) > 0; i++){
		char test[3];
		strncpy(test, a, 3);
		if(strncmp(test, "000", 3) == 0){
			b[i] = '0';
		}else if(strncmp(test, "001", 3) == 0){
			b[i] = '1';
		}else if(strncmp(test, "010", 3) == 0){
			b[i] = '2';
		}else if(strncmp(test, "011", 3) == 0){
			b[i] = '3';
		}else if(strncmp(test, "100", 3) == 0){
			b[i] = '4';
		}else if(strncmp(test, "101", 3) == 0){
			b[i] = '5';
		}else if(strncmp(test, "110", 3) == 0){
			b[i] = '6';
		}else if(strncmp(test, "111", 3) == 0){
			b[i] = '7';
		}
		a+= 3;
	}
	//free(a);
	while(b[0] == '0'){
		b++;
	}
	return b;
}

char* decToBin(char* a){
	char* b = malloc(strlen(a)*4);
	int i;

	if(strlen(a) == 0){
		b[0] = '\0';
		return b;
	}

	for(i = 0; a != 0; i++){
		b[i] = leftover(a);
		a = divByTwo(a);
	}
	b[i] = '\0';
	reverse(&b);
	//printf("%s\n", b);
	return b;
}

char* binToDec(char* a){
	char* b = malloc(strlen(a));
	int i, j;

	if(strlen(a) == 0){
		b[0] = '\0';
		return b;
	}

	for(i = 0; strlen(a) > 0; i++, a++){
		//printf("The value is: %s\n", b);
		b = multByTwo(b);
		if(a[0] == '1'){
			for(j = 0; j < strlen(b); j++){
				if(b[j] != '9'){
					b[j] = b[j] + 1;
					j = strlen(b)+2;
				}else{
					b[j] = '0';
				}
			}
			if(j == strlen(b)){
				b[j] = '1';
			}
		}
		//printf("The new value is: %s\n", b);
	}
	//printf("i is value %d\n", i);
	b[j+2] = '\0';
	reverse(&b);
	return b;
}

char * multiply(char* a, char* b){
	char* product = malloc((strlen(a) + strlen(b))*2);
	product = "0";

	if(strlen(a) == 0 || strlen(b) == 0){
		product[0] = '\0';
		return product;
	}

		while(strlen(a) > 0){
			//printf("a[%d] = %c", strlen(a)-1, a[strlen(a)-1]);
			if(a[strlen(a)-1] == '1'){
				//printf("Add %s to %s\n", b, product);
				product = add(product, b);
			}
			strncat(b, "0", 1);
			a[strlen(a) - 1] = '\0';
		}

	return product;
}

void printbase(char* value, char*base){
	if(strlen(value) == 0){
		printf("Formatting Error! Check above!\n");
		return;
	}

	if(strcmp(value, "0") == 0){
		printf("0\n");
	}else if(strcmp(base, "b") == 0){
		printf("b%s\n", value);
	}else if(strcmp(base, "o") == 0){
		printf("o%s\n", binToOct(value));
	}else if(strcmp(base, "d") == 0){
		printf("d%s\n", binToDec(value));
	}else if(strcmp(base, "h") == 0){
		printf("h%s\n", binToHex(value));
	}else{
		printf("%s is an invalid base!\n", base);
	}
}

void toBase(char** a, char** b){
	int i;
	if(*a[0] == 'b'){
		(*a)++;
		for(i = 0; i < strlen(*a); i++){
			//printf("%c\n", (*a)[i]);
			if((*a)[i] != '0' && (*a)[i] != '1'){
				printf("First parameter is an invalid binary!\n");
				(*a)[0] = '\0';
			}
		}
	}else if(*a[0] == 'd'){
		(*a)++;
		for(i = 0; i < strlen(*a); i++){
			//printf("%c\n", (*a)[i]);
			if((*a)[i] < '0' || (*a)[i] > '9'){
				printf("First parameter is an invalid decimal!\n");
				(*a)[0] = '\0';
			}
		}
		*a = decToBin(*a);
	}else if(*a[0] == 'o'){
		(*a)++;
		for(i = 0; i < strlen(*a); i++){
			//printf("%c\n", (*a)[i]);
			if((*a)[i] < '0' || (*a)[i] > '7'){
				printf("First parameter is an invalid octal!\n");
				(*a)[0] = '\0';
			}
		}
		*a = octToBin(*a);
	}else if(*a[0] == 'h'){
		(*a)++;
		for(i = 0; i < strlen(*a); i++){
			//printf("%c\n", (*a)[i]);
			if(!isxdigit((*a)[i])){
				printf("First parameter is an invalid hexidecimal!\n");
				(*a)[0] = '\0';
			}
		}
		*a = hexToBin(*a);
	}else{
		(*a)[0] = '\0';
		printf("Improper format!");
	}

	if(*b[0] == 'b'){
		(*b)++;
		for(i = 0; i < strlen(*b); i++){
			//printf("%c\n", (*a)[i]);
			if((*b)[i] != '0' && (*b)[i] != '1'){
				printf("Second parameter is an invalid binary!\n");
				(*b)[0] = '\0';
			}
		}
	}else if(*b[0] == 'd'){
		(*b)++;
		for(i = 0; i < strlen(*b); i++){
			//printf("%c\n", (*a)[i]);
			if((*b)[i] < '0' || (*b)[i] > '9'){
				printf("Second parameter is an invalid decimal!\n");
				(*b)[0] = '\0';
			}
		}
		*b = decToBin(*b);
	}else if(*b[0] == 'o'){
		(*b)++;
		for(i = 0; i < strlen(*b); i++){
			//printf("%c\n", (*a)[i]);
			if((*b)[i] < '0' || (*b)[i] > '7'){
				printf("Second parameter is an invalid octal!\n");
				(*b)[0] = '\0';
			}
		}
		*b = octToBin(*b);
	}else if(*b[0] == 'h'){
		(*b)++;
		for(i = 0; i < strlen(*b); i++){

			//printf("%c\n", (*a)[i]);
			if(!isxdigit((*b)[i])){
				printf("Second parameter is an invalid hexidecimal!\n");
				(*b)[0] = '\0';
			}
		}
		*b = hexToBin(*b);
	}else{
		printf("Improper format!");
		(*b)[0] = '\0';
	}
}

char* expo(char* b, char* e){
	if(strcmp(e, "0") == 0){
		return "1";
	}else{
		return multiply(b, expo(b, subtract(e, "1")));
	}
}


int main(int argc, char** argv){
	int negative = 0;
	if(argv[1] != NULL && argv[2] != NULL && argv[3] != NULL && argv[4]!= NULL){
	char* op = argv[1];
	char* a = argv[2];
	char* b = argv[3];
	char* base = malloc(strlen(argv[4])+1);
	strcpy(base, argv[4]);
	char* value = malloc(10000);

	//value = expo(decToBin(a),decToBin(b));
	//printbase(value, base);

		if(strncmp("+", op, strlen(op)) == 0){

			if(a[0] == '-' && b[0] == '-'){
				a++;
				b++;
				negative = 1;
				toBase(&a, &b);
				value = add(a,b);
			}
			else if(a[0] == '-'){
				a++;
				toBase(&a, &b);
				if(strcmp(a, b) > 0 || strlen(a) > strlen(b)){
					negative = 1;
					value = subtract(a, b);
				}else{
					value = subtract(b,a);
				}
			}else if(b[0] == '-'){
				b++;
				toBase(&a, &b);
				if(strcmp(a, b) > 0 || strlen(a) > strlen(b)){
					value = subtract(a, b);
				}else{
					negative = 1;
					value = subtract(b,a);
				}
			}else{
				toBase(&a, &b);
				value = add(a,b);
				//printf("\n%s\n", value);
			}
			if(negative == 1 && strcmp("0", value) != 0){
				printf("-");
			}
			//printf("%s and %s", a, b);
			//printf("\n%s", value);
			printbase(value, base);
		}else if(strncmp("-", op, strlen(op)) == 0){

			if(a[0] == '-' && b[0] == '-'){
				a++;
				b++;
				toBase(&a, &b);
				if(strcmp(a, b) > 0 || strlen(a) > strlen(b)){
					negative = 1;
					value = subtract(a, b);
				}else{
					value = subtract(b,a);
				}
			}
			else if(a[0] == '-'){
				a++;
				negative = 1;
				toBase(&a, &b);
				value = add(a,b);
			}else if(b[0] == '-'){
				b++;
				toBase(&a, &b);
				value = add(a,b);
			}else{
				toBase(&a, &b);
				if(strcmp(a, b) > 0 || strlen(a) > strlen(b)){
					value = subtract(a, b);
				}else{
					negative = 1;
					value = subtract(b,a);
				}
			}

			if(negative == 1 && strcmp("0", value) != 0){
				printf("-");
			}
			printbase(value, base);

		}else if(strncmp("*", op, strlen(op)) == 0){
			if(a[0] == '-' && b[0] == '-'){
				a++;
				b++;
				toBase(&a, &b);
				value = multiply(a,b);
			}else if(a[0] == '-'){
				a++;
				toBase(&a, &b);
				negative = 1;
				value = multiply(a,b);
			}else if(b[0] == '-'){
				b++;
				toBase(&a, &b);
				negative = 1;
				value = multiply(a,b);
			}else{
				toBase(&a, &b);
				value = multiply(a,b);
			}

			if(negative == 1 && strcmp("0", value) != 0){
				printf("-");
			}
			printbase(value, base);
		}else{
			printf("%s is not a valid operation!", op);
		}
	}else{
		printf("Must be in format of <op> <num1> <num2> <base>\n");
	}
	return 0;
}
