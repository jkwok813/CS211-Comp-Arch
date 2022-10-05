#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[argc+1]){
/* Opens the file*/
	FILE* f = fopen (argv[1], "r"); 
	if (f == 0) {
		printf("Failed\n");
		return EXIT_SUCCESS;
	}
    unsigned long int val;
    int size;
    while(fscanf(f, "%ld\n" "%d\n",  &val, &size) != EOF) { 
    int a[10000] = {0};  
        //printf("Val is %d and size is %d\n", val, size);   
        for(int i = 0; i < size; i++){
            //printf("Val is %d\n", val);
            if(val == 0){
                //printf("a[%d] is now %d\n", i, val%2);           
                break;
            }   
            //printf("Array value is: %d\n", i);
            //printf("a[%d] is now %d\n", i, val%2);
            a[i] = val%2; 
            val = val/2;   
        }
        int score = size-1;
        int i = 0;
        while(i < size){
            //printf("This is a[%d]", score);
            printf("%d", a[score]);
            score--;
            i++;
        }
        printf("\n");
    }
    return EXIT_SUCCESS;
}
