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
	int max, i;
	int carry = 0;

	if(strlen(num1) >= strlen(num2)){
		max = strlen(num1);
	}else{
		max = strlen(num2);
	}


	char* sum = malloc(max + 2); //the largest possible size for the sum of two numbers

	for(i = 0; i < max; i++){
		if(i >= strlen(num1)){
			sum[i] = bigate('0', num2[i], &carry);
			//printf("%c", sum[i]);
		}else if(i >= strlen(num2)){
			sum[i] = bigate('0', num1[i], &carry);
			//printf("%c", sum[i]);
		}else{
			sum[i] = bigate(num1[i], num2[i], &carry);
			//printf("%c", sum[i]);
		}
	}

	if(carry == 1){
		sum[i] = '1';
		sum[i + 1] = '\0';
	}else{
		sum[i] = '\0';
	}

	return sum;
}


int main(int argc, char** argv){
	char*a = "10";
	char*b = "1";
	printf("%s + %s = %s", a, b, add(a, b));
	return 0;
}
