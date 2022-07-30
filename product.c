# include <stdio.h>
int main(int args,char ** argv){
    int n;
    double product;
    scanf("%d",&n);
    product = 1;
    for (int i=1;i<=n;i++){
        product*=i;
    }
    printf("product=%.0f \n",product);
    return 0;
}