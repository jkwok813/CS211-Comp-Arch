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
    int expo;
    int size;
    int frac; 
    unsigned long int val;
    int length;
    while(fscanf(f, "%d %d %d %lx %d", &size, &expo, &frac, &val, &length) != EOF){
        //printf("Size is %d expo is %d frac is %d val is %ld length is %d\n", size, expo, frac, val, length);
        //hex to binary
        int a[10000] = {0};  
        for(int i = 0; i < size; i++){
            if(val == 0){       
                break;
            }   
            a[i] = val%2; 
            val = val/2;   
        }

        //reverse the binary
        int f = 0;
        int score = size-1;
        int bin[100] = {0};
        while(f < size){
            bin[f] = a[score];
            f++;
            score--;
        }

        //reads the binary out
        int i = 0;
        while(i < size){
            //printf("%d", bin[i]);
            i++;
        }
        //printf("\n");
        //split the binary into parts

        //first check negative number
        int e = 0;
        if(bin[0] == 1){
            e = 1;
        }
        if(e == 1){
            //printf("Negative number\n");
        }

        //solve for exponent
        int b = 1;
        int c = 0;
        int exp[100] = {0}; 
        while(b < expo+1){
            exp[c] = bin[b];
            c++;
            b++;
        }
        int counter = 0;
        //printf("Exponent binary is:\n");
        while(counter < expo){
            //printf("%d", exp[counter]);
            counter++;
        }
        //printf("\n");
        int exp2[1000] = {0};
        int k = 0;
        int score2 = expo-1;
        while(k < expo){
            exp2[k] = exp[score2];
            score2--, k++;
        }
        /*int asdfg = 0;
        while(asdfg < expo){
            printf("%d", exp2[asdfg]);
            asdfg++;
        }*/
        int ex = 0;
        int z = 0;
        while(z < expo){
            if(exp2[z] == 1){
                ex += pow(2, z);
                //printf("2^%d\n", z);
            }
            z++;
        }
        /*int asdf = 0;
        while(asdf < expo){
            printf("exp[%d] = %d\n", asdf, exp[asdf]);
            asdf++;
        }*/
        //printf("Exponent value is %d\n", ex);
        int h = 0;
        h = pow(2, expo-1);
        h = h-1;
        //printf("bias is %d\n", h);
        double finalexponent = ex-h;
        //printf("Finalexponent is %f\n", finalexponent);
        //solve for mantissa
        int man[100] = {0};
        int d = 0;
        while(b < size){
            man[d] = bin[b];
            d++, b++;
        }

        //print mantissa binary
        /*printf("mantissa binary is:\n");
        int count = 0;
        while(count < frac){
            printf("%d", man[count]);
            count++;
        }
        printf("\n");*/

        //solve for fraction integer
        int man2[1000] = {0};
        int l = 0;
        int score3 = frac-1;
        while(l < frac){
            man2[l] = man[score3];
            score3--, l++;
        }

        //print reversed mantisa binary
        /*int asdfg = 0;
        while(asdfg < frac){
            printf("%d", man2[asdfg]);
            asdfg++;
        }*/
        int g = 0;
        double mantissa = 0;
        while(g < frac){
            if(man2[g] == 1){
                mantissa = mantissa+1;
            }
        g++;
        mantissa = mantissa/2;
        //printf("Mantissa = %f\n", mantissa);
        }
        mantissa = mantissa+1;
        //printf("%f\n", mantissa);
        double final = 0;
        double finale = 0;
        if(ex == 0){
            int sign = pow(-1, e);
            //printf("uh oh stinky\n");
            mantissa = mantissa-1;
            //printf("Mantissa = %f\n", mantissa);
            finale = pow(2, 1-h);
            //printf("Finale = %f\n", finale);
            final = sign*mantissa*finale;
        }
        else{
            int sign = pow(-1, e);
            //printf("%f\n", finalexponent);
            finale = pow(2, finalexponent);
            //printf("finale is %f\n", finale); 
            final = sign*mantissa*finale;
        }   
        printf("%.*f\n", length, final);
    }
    return EXIT_SUCCESS;
}
