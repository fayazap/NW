#include<stdio.h>
#include<stdlib.h>
int main(){
    int n,bsize,in,out,bucket=0;
    printf("Enter the number of inputs: \n");
    scanf("%d",&n);
    printf("Enter the bucket size: \n");
    scanf("%d",&bsize);
    printf("Enter the outgoing rate: \n");
    scanf("%d",&out);
    while(n!=0){
        printf("Enter the incoming packet size: \n");
        scanf("%d",&in);
        if(in<=(bsize-bucket)){
            bucket+=in;
            printf("Bucket status: %d out of %d\n",bucket,bsize);
        }
        else{
            printf("dropped packets: %d\n",in-(bsize-bucket));
            printf("Bucket status: %d out of %d\n",bucket,bsize);
            bucket=bsize;
        }
        bucket-=out;
        printf("After outgoing Bucket status: %d out of %d\n",bucket,bsize);
        n--;
    }
}