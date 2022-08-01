#include <stdio.h>
#include <stdlib.h>

int main() //方法二
{
    int n;
    scanf("%d",&n);
    int *s1=(int*)calloc(n,sizeof(int));
    int *s2=(int*)calloc(n,sizeof(int));
    for(int i=0;i<n;i++){
        scanf("%d",s1+i);
    }
    for(int i=0;i<n;i++){
        scanf("%d",s2+i);
    }
    // // op2
    // int *p=s1,*q=s2;
    // int *ret=NULL;
    // for(int i=0;p!=NULL&&q!=NULL&&i<n;i++){
    //     if(*p>*q){
    //         ret = q++;
    //     }else{
    //         ret = p++;
    //     }
    // }
    // printf("%d\n",*ret);

    // op3
    int mid=(n-1)/2;
    int s1_m=*(s1+mid);
    int s2_m=*(s2+mid);
    int *ret=NULL;
    if(s1_m==s2_m){
        ret=&s1_m;
    }else{
        if(s1_m>s2_m){
            int *t=s1;
            s1=s2;
            s2=t;
        }
        int *p=&s1[mid-1];
        int *q=s2;
        for(int i=0;p!=NULL&&q!=s2+n-mid&&i<n-mid+1;i++){
            if(*p>*q){
                ret = q++;
            }else{
                ret = p++;
            }
        }
    }
    printf("%d\n",*ret); 
    return 0;
}
/*
3
1 2 3
4 5 6
*/
/*
3
4 5 6
1 2 3
*/
