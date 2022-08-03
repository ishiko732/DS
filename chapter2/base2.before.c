#include <stdio.h>
#include <stdlib.h>
int main(){
    int n,m;//n<=100,m>=0
    scanf("%d",&n);
    scanf("%d",&m);
    m%=n;
    int *p=(int*)calloc(n+m,sizeof(int));
    int *q=p;
    for(int i=0;i<n;i++){
        scanf("%d",p+i);
    }
    for(int i=0;i<m;i++){
        *(p+n+i)=*(p+i);
    }
    p=p+m;
    printf("%d",*p++);

    for(int i=0;i<n-1;i++){
        printf(" %d",*(p+i));
    }
    free(q);
    return 0;
}