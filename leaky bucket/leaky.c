#include<stdio.h>
#include<stdlib.h>

void main(){
    int bucket_size,occupied=0,n,output_rate;
    printf("Enter the bucket size: \n");
    scanf("%d",&bucket_size);
    printf("Enter the number of inputs: \n");
    scanf("%d",&n);
    printf("Enter the output rate: \n");
    scanf("%d",&output_rate);
    while(n!=0){
        printf("Enter the input size: \n");
        int in;
        scanf("%d",&in);
        if(in<=(bucket_size-occupied)){
            occupied+=in;
            printf("Status: %d out of %d\n",occupied,bucket_size);
        }
        else {
            printf("Discarded: %d\n",in-(bucket_size-occupied));
            occupied=bucket_size;
            printf("Status: %d out of %d\n",occupied,bucket_size);
        }
        occupied-=output_rate;
        n--;
        printf("Status after removal: %d out of %d\n",occupied,bucket_size);
    }
}