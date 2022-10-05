#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[argc+1]){
/* Opens the file*/
	FILE* f = fopen (argv[1], "r"); 
	if (f == 0) {
		printf("Failed\n");
		return EXIT_SUCCESS;
	} 
    double val; //Number converting
    int size; //number of decimal places
    while(fscanf(f, "%le\n" "%d\n",  &val, &size) != EOF) {
    int a[1000] = {0};  
    int div = 0;
    int c = 0;
    //int b = 0;
    //printf("This is Val %f and this is size %d\n", val, size);
    if(val < 1){
        while(val < 1){
            val = val*2;
            div--;
        }
    }
    while(val > 2){
        //printf("Above 2\n");
        val = val/2;
        div++;
    }
    if(val > 1){
        val = val-1;
        //printf("%f\n", val);
    }
    //if(b == 0){
        while(val != 0 && val != 1){
            //printf("%f\n", val);
            val = val*2;
            if(val >= 1){
                a[c] = 1;
                val = val-1;
            }
            else{
                a[c] = 0;
            }
            c++;
        }
    //}
    int i = 0;
    printf("1.");
    while(i < size){
        printf("%d", a[i]);
        i++;
    }
    printf(" %d", div);
    printf("\n");
    }//end of while loop
}
         
         
