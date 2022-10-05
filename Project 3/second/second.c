#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[argc+1]){
/* Opens the file*/
	FILE* f = fopen (argv[1], "r"); 
	if (f == 0) {
		printf("Failed\n");
		return EXIT_SUCCESS;
	} 
    long int val;
    int size;
    while(fscanf(f, "%ld\n" "%d\n",  &val, &size) != EOF) { 
    //printf("Val is %ld\n", val);
    //printf("Size is %d\n", size);
    long int min;
    long int max;
    int h = 0;
    long int count = 2;
    while(h < size-2){
        count = count*2;
        h++;
    }
    min = count*-1;
    max = count-1;
    //printf("This is min %ld\n", min);
    //printf("This is max %ld\n", max); 
    if(val > max){
        //printf("Value %ld is greater than max %ld\n", val, max);
        val = max;
        //printf("New val is %ld\n", max);
    }
    else if(val < min){
        //printf("Value %ld is less than min %ld\n", val, min);
        val = min;
        //printf("New val is %ld\n", min);
    }
    int l = val;
    if(val < 0){
        val = val*-1;
        //printf("Val is negative, here is new val %ld\n", val);
    }
    int a[100000] = {0};  
            //printf("Val is %ld and size is %d\n", val, size);   
            if(l > 0 || l == 0){
                for(int i = 0; i < size; i++){
                    //printf("Val is %ld\n", val);
                    if(val == 0){
                        //printf("a[%d] is now %ld\n", i, val%2);           
                        break;
                    }   
                    //printf("Array value is: %d\n", i);
                    //printf("a[%d] is now %ld\n", i, val%2);
                    a[i] = val%2; 
                    val = val/2;   
                }
            }
            else{ 
                //printf("%ld val is negative\n", val);
                for(int i = 0; i < size; i++){
                    //printf("Val is %ld\n", val);
                    if(val == 0){
                   
                        //printf("a[%d] is now %ld\n", i, val%2);           
                        break;
                    }   
                    //printf("Array value is: %d\n", i);
                    //printf("a[%d] is now %ld\n", i, val%2);
                    a[i] = val%2; 
                    val = val/2;   
                }
                /*int score = size-1;
                int i = 0;*/
                /*while(i < size){
                    printf("This is a[%d]\n", score);
                    printf("%d\n", a[score]);
                    score--;
                    i++;
                }*/               
                int k = 0;
                while(k < size){//finds 1's compliment
                    if(a[k] == 0){
                        a[k] = 1;
                        k++;
                    }
                    else{
                        a[k] = 0;
                        k++;
                    }  
                }
                /*while(i < size){
                    printf("This is a[%d]\n", score);
                    printf("%d\n", a[score]);
                    score--;
                    i++;
                }*/
                if(a[0] == 0){
                    a[0] = 1;
                }
                else {
                    int d = 0;
                    while(a[d] == 1){
                        a[d] = 0;
                        d++;
                    }
                    a[d] = 1;
                    a[d-1] = 0;
                }
            }
            int score = size-1;
            //printf("Score is now %d\n", score);
            int i = 0;
                while(i < size){
                    //printf("This is a[%d]", score);
                    printf("%d", a[score]);
                    score--;
                    i++;
                }
            //}
            printf("\n");
       }
    return EXIT_SUCCESS;
}
