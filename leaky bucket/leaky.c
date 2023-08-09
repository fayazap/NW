#include<stdio.h>
#include<stdlib.h>

void main(){
    int bucket_size,occupied=0,n,output_rate, int remaining=0;
    printf("Enter the bucket size: \n");
    scanf("%d",&bucket_size);
    remaining = bucket_size();
    printf("Enter the number of inputs: \n");
    scanf("%d",&n);
    printf("Enter the output rate: \n");
    scanf("%d",&output_rate);
    while(n!=0){
        printf("Enter the input size: \n");
        int in;
        scanf("%d",&in);
        remaining = bucket_size-occupied;
        if(in<=(remaining)){
            occupied+=in;
            printf("Status: %d out of %d\n",occupied,bucket_size);
        }
        else {
            printf("Discarded: %d\n",in-(remaining));
            occupied=bucket_size;
            printf("Status: %d out of %d\n",occupied,bucket_size);
        }
        occupied-=output_rate;
        remaining += output_rate;
        n--;
        printf("Status after removal: %d out of %d\n",occupied,bucket_size);
    }
}
