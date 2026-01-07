#include<stdio.h>
int main() {
    int n,j,binary[32],i=0;
    printf("Enter a number:");
    scanf("%d",&n);
    while(n>0) {
        binary[i] = n%2;
        n=n/2;
        i++;
    }
    printf("binary representation:");
    for(j=i-1; j>=0; j--) {
        printf("%d",binary[j]);
    }
    return 0;
}