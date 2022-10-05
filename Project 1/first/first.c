#include <stdlib.h>
#include <stdio.h>

int check(int a) {
	if(a <= 1) {
		return 0;
	}
	else {
		for(int b = 2; b < a; b++) {
			if(a%b == 0){ 
				return 0; 
			} 
		}
	}
	return 1;
}

int main(int argc, char* argv[argc+1]){
/* Opens the file*/
	FILE* f = fopen (argv[1], "r"); 
	if (f == 0) {
		printf("Failed\n");
		return EXIT_SUCCESS;
	}
	int i;
	while(fscanf(f, "%d\n", &i) != EOF) { 
		int a = i+2;
		int b = i-2;
		if(check(i) == 1) {
			if(check(a) == 1 && check(b) == 1){
				printf("yes\n"); 
			}
			else if(check(a) == 1 || check(b) ==1){
				printf("yes\n");
			}
			else{
				printf("no\n");
			}
		}
		else{
			printf("no\n");
		}
	}
	fclose(f);
	return EXIT_SUCCESS; 
}

/* 
yes 
yes
yes
no
yes
no
no
no
no
yes
*/

