#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n, bsize, bucket = 0, in, out;
    printf("Enter the no of inputs: \n");
    scanf("%d", &n);
    printf("Enter the output rate: \n");
    scanf("%d", &out);
    printf("Enter the bucket size: \n");
    scanf("%d", &bsize);
    while (n != 0)
    {
        printf("Enter the incoming packet size: \n");
        scanf("%d", &in);
        if (in <= (bsize - bucket))
        {
            bucket += in;
            printf("status: %d out of %d\n", bucket, bsize);
        }
        else
        {
            printf("Dropped packets: %d", in - (bsize - bucket));
            printf("status: %d out of %d\n", bucket, bsize);
            bucket = bsize;
        }

        printf("status after removal: %d out of %d\n", bucket, bsize);
        bucket -= out;
        n--;
    }
}