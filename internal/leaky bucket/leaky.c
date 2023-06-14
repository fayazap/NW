#include<stdio.h>
#include<stdlib.h>
int main(){
    int bucket_size,occupied=0,n,out_rate,in;
    printf("Enter the number of packets: \n");
    scanf("%d",&n);
    printf("Enter the bucket size: \n");
    scanf("%d",&bucket_size);
    printf("Enter the output rate: \n");
    scanf("%d",&out_rate);
    while(n!=0){
        printf("Enter the size of input: \n");
        scanf("%d",&in);
        if(in<=(bucket_size-occupied)){
            occupied+=in;
            printf("Status: %d out of %d\n",occupied,bucket_size);
        }else{
            printf("Dropping %d\n",in-(bucket_size-occupied));
            occupied=bucket_size;
            printf("Status: %d out of %d\n",occupied,bucket_size);
        }
        printf("Status: %d out of %d\n",occupied,bucket_size);
        n--;
        occupied-=out_rate;
    }
}