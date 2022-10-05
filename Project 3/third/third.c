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
    long int kek;
    int size;
    char type;
    char fr;
    while(fscanf(f, "%ld %d %c %c", &kek, &size, &type, &fr) != EOF){
        //printf("%ld\n", kek);
        if(type == 's'){
            long int val = kek;
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
            if(val > max){
                val = max;
            }
            else if(val < min){
                val = min;
            }
            int l = val;
            if(val < 0){
                val = val*-1;
            }
            int a[100000] = {0};  
            if(l > 0 || l == 0){
                for(int i = 0; i < size; i++){
                    if(val == 0){      
                        break;
                    }   
                    a[i] = val%2; 
                    val = val/2;   
                }
            }
            else{ 
                for(int i = 0; i < size; i++){
                   if(val == 0){       
                       break;
                   }   
                a[i] = val%2; 
                val = val/2;   
                }      
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
                int dec = 0;
                int z = 0;
                while(z < 65){
                    if(a[z] == 1){
                        dec += pow(2, z);
                    }
                    z++;
                }
                printf("%d\n", dec);
            } 
//
        else{
            long int val = kek;
            int a[10000] = {0};   
            for(int i = 0; i < size; i++){
                if(val == 0){       
                    break;
                }   
                a[i] = val%2; 
                val = val/2;   
            }
            int b[100000] = {0};
            int score = size-1;
            int i = 0;
            int u = 0;
            while(i < size){
                b[u] = a[score];
                score--;
                i++;
                u++;
            }
            int boolean = 0;
            if(b[0] == 1){
               boolean = 1;
            }
            int z = 0;
            int y = 1;
            int c[100000] = {0};
            while(z < size-1){
                c[z] = b[y];
                z++, y++;
            }
            int v = 0;
            int mango = 0;
            while(mango < size-1){
                //printf("%d", c[mango]);
                mango++;
            }
            //printf("\n");
            while(v < size-1){
                if(c[v] == 1){
                    c[v] = 0;
                }
                else{
                    c[v] = 1;
                }
                v++;
            }
            int apple = 0;
            while(apple < size-1){
                //printf("%d", c[apple]);
                apple++;
            }
            v--;
            //printf("\n");
            //printf("c[%d] is %d\n", v, c[v]);
            /*if(c[v] == 0){
                c[v] = 1;
            }
            else{
                while(v > 0 && c[v] == 1){
                    c[v] = 0;
                    v--;
                }
                c[v] = 1;
            }*/
            //printf("c[%d] is %d\n", v, c[v]);
            int j = 0;
            long int k = 0;
            for(j = 0; j < size-1; j++){
                 k = 10*k+c[j];
            }   
            //printf("%d\n", k);
            int dec = 0, f = 0, rem;
            while(k != 0){
                rem = k%10;
                k /= 10;
                dec += rem * pow(2, f);
                ++f;
            }
            dec = dec+1;
            if(boolean == 1){
                dec = dec*-1;
            }
            if(dec < 1){
                printf("%d\n", dec); 
            }   
            else{
                printf("%ld\n", kek);
            }  
            //return EXIT_SUCCESS;
        }
    }
    return EXIT_SUCCESS;
}
