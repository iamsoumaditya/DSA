#include<stdio.h>
void TOH(int n,char src, char aux,char dest){
    if(n==1){
        printf("Move disk %d from %c to %c\n",n,src,dest);
        return;
    }
    TOH(n - 1, src, dest, aux);
    printf("Move disk %d from %c to %c\n", n, src, dest);
    TOH(n - 1, aux,src, dest);
}
int main(){
    int n;
    printf("Enter the disk number: ");
    scanf("%d",&n);
    TOH(n,'s','a','d');
    return 0;
}