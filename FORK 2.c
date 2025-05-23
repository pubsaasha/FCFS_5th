#include<stdio.h>
#include<math.h>

int main(){
    int n,i;

    printf("Enter the number: ");
    scanf("%d",&n);

    for(i=0;i<pow(2,n);i++){
        printf("%d. Hello Sir!\n",i+1);
    }
    return 0;
}
