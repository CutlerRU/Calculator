#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//adds, subtracts, multiplies numbers of difference bases

char * convert(char* num, char* inbase, char* outbase){
	if(strcmp(inbase, outbase) == 0){
		return num;
	}
	char* base;

	if(strcmp(inbase, "b") == 0){
		base = "10";
	}else if(strcmp(inbase, "o") == 0){
		base = "1000";
	}else if(strcmp(inbase, "d") == 0){
		base = "1010";
	}else if(strcmp(inbase, "x") == 0){
		base = "10000";
	}else{
		base = 0;
		printf("ERROR!");
	}
	return base;
}

char bigate(char a, char b, int * carry){
	if(a == '0'){
		if(b == '0'){
			if(*carry == 0){
				return 0;
			}
			*carry = 0;
			return '1';
		}//b == '1'
		if(*carry == 0){
			return '1';
		}
		return '0';
	}//a == '1'

	if(b == '0'){
		if(*carry == 0){
			return '1';
		}
		return '0';
	}
	if(*carry == 0){
		*carry = 1;
		return '0';
	}
	return '1';
}

char * add(char* num1, char* num2){
	int max, i, j, k, len1, len2;
	int carry = 0;

	if(strlen(num1) >= strlen(num2)){
		max = strlen(num1);
		len1 = strlen(num1);
		len2 = strlen(num2);
	}else{
		max = strlen(num2);
		len1 = strlen(num1);
		len2 = strlen(num2);
	}


	char* sum = malloc(max + 2); //the largest possible size for the sum of two numbers
	sum[max+1] = '\0';

	for(i = len1-1, j = len2-1, k = max; i >= 0 || j >= 0; i--, j--, k--){
		if(i < 0){
			//printf("%c is digit num2", num2[i-1]);
			sum[k] = bigate('0', num2[j], &carry);
			//printf("%c", sum[i]);
		}else if(j < 0){
			//printf("%c is digit num1", num1[i-1]);
			sum[k] = bigate('0', num1[i], &carry);
			//printf("%c", sum[i]);
		}else{
			//printf("%c is digit num1 and %c is digit num2", num1[i], num2[j]);
			sum[k] = bigate(num1[i], num2[j], &carry);
			//printf("%c", sum[i]);
		}
	}

	if(carry == 1){
		sum[0] = '1';
	}else{
		sum[0] = ' ';
	}

	return sum;
}


int main(int argc, char** argv){
	char*a = "111111111111111111111111111111111111111111";
	char*b = "1";
	printf("%s + %s = %s\n", a, b, add(a, b));
	return 0;
}
