#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "calc.c"

int main(char* argc, char** argv){
	if(strlen(argv[1]) == 32){
		char* full_String = argv[1];
		char* type = argv[2];
		char sign = full_String[0];
		int i;
		for(i = 0; i < strlen(full_String); i++){
			if(full_String[i] != '0' && full_String[i] != '1'){
				printf("The inputed value is not formatted as a Binary!");
				return 0;
			}
		}
		if(strcmp(type, "int") == 0){
			
		}else if(strcmp(type, "float") == 0){
			char* mantissa = full_String;
		}else{
			printf("%s is an invalid type. Type must be 'int' or 'float'\n");
		}
	}else{
		printf("The input must be a 32 bit Binary number!\n");
	}

	return 0;
}
