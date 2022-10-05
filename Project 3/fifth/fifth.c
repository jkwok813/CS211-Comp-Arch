#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(int argc, char* argv[argc+1]){
/* Opens the file*/
	FILE* f = fopen (argv[1], "r"); 
	if (f == 0) {
		printf("Failed\n");
		return EXIT_SUCCESS;
	} 
    double val; //Number converting
    int size; //number of decimal places total
    int frac; //number of fraction binary
    int expo; //number of exponent binary
    while(fscanf(f, "%le\n" "%d\n" "%d\n" "%d\n",  &val, &size, &expo, &frac) != EOF) {
    int a[1000] = {0};  
    double div = 0;
    //int c = 1;
    //printf("This is Val %f size %d frac %d expo %d\n", val, size, expo, frac);
    if(val < 0){
        //printf("Number is negative\n");
        val = val*-1;
        a[0] = 1;
    }
    if(val < 1){
        while(val < 1){
            val = val*2;
            div--;
        }
    }
    while(val > 2){
        val = val/2;
        //printf("Divided by 2; New Value is %f\n", val);
        div++;
    }
    if(val > 1){
        val = val-1;
        //printf("%f\n", val);
    }
    //double val2 = val;
    int count = 0;
    int t = expo+1;
    while(val != 0 && val != 1){ //writes mantissa binary
        //printf("%f\n", val);
        val = val*2;
        count++;
        if(val >= 1){
            a[t] = 1;
            val = val-1;
        }
        else{
            a[t] = 0;
        }
        //printf("a[%d] is %d\n", t, a[t]);
        t++;
    }
    int v = size-1;
    int hold = size;
    int boolean = 0;
    int cheese = 0;
    for(int w = size+1; w < 200; w++){
        if(a[w] == 1){
            boolean = 1;
        }
    }
    //printf("mantissa = %f a[%d] is %d and a[%d] is %d\n", val2, v, a[v], v+1, a[v+1]);
    //printf("a[%d] is %d\n", v-1, a[v-1]); 
    if(a[v] == 1 && a[v+1] == 1){//Round up condition 1
        //printf("ROUNDING CONDITION MET\n");
        while(a[v-1] == 1){
        //printf("ROUNDING CONDITION MET 2\n");
            v--;
        }
        //printf("v is now %d\n", v);
        while(hold > v-1){
            a[hold] = 0;
            //printf("a[%d] edited\n", hold);
            hold--;
        }
        //printf("a[%d] is now edited\n", hold);
        a[hold] = 1;
        if(hold == expo){
            cheese = 1;
        }
    }
    else if(a[v+1] == 1 && boolean == 1){
       //printf("ROUNDING CONDITION MET BUT THE SECOND ONE\n");
         while(a[v] == 1){
            v--;
        }
        while(hold > v){
            a[hold] = 0;
            hold--;
        }     
        a[hold] = 1;
        if(hold == expo){
            cheese = 1;
        }    
    }  
    //printf("div = %f\n", div);
    double exp = expo;
    //printf("count = %d\n", count);
    double bias = pow(2.0, exp-1);
    bias = bias-1+div;
    //printf("bias = %f\n", bias);
    int new = bias;
    //int b[10000] = {0};
    int k = 0;
    for(int i = expo; i > 0; i--){
       // printf("new = %d\n", new);
        if(new == 0){   
            //printf("New is 0, break\n");    
            break;
        }   
        a[i] = new%2; 
        new = new/2;
        //printf("a[%d] is %d\n", i, a[i]); 
        k++;  
    }
    int q = 0;
    if(cheese == 1){
        a[expo] = 1;
    }
    while(q < size){
        printf("%d", a[q]);
        q++;
    }
    printf("\n");
    }//end of while loop
}
         
         
