#include <stdio.h>
#include <time.h>
clock_t start,stop;
double duration;

int main(int args, char** argv){

    return 0;
}

int MaxSubseqSum1(int list[],int n){
    int thissum,maxsum=0;
    for (int i=0;i<n;i++){
        for (int j=i;j<n;i++){
            thissum=0;
            for (int k=j;k<n;k++){
                thissum+=list[k];
            }
            if(thissum>maxsum){
                maxsum=thissum;
            }
        }
    }
    return maxsum;
}

int MaxSubseqSum2(int list[],int n){
    int thissum,maxsum=0;
    for (int i=0;i<n;i++){
        for (int j=i;j<n;i++){
            thissum+=list[j];
            if(thissum>maxsum){
                maxsum=thissum;
            }
        }
    }
    return maxsum;
}


int max3(int a,int b,int c){
    return a>b?a>c?a:c:b>c?b:c;
}

int DivideAndConquer(int list[],int left,int right){
    int maxleftsum,maxrightsum;
    int maxleftbordersum,maxrightbordersum;

    int leftbordersum,rightbordersum;
    int center,i;
    if(left==right){
        if(list[left]>0){
            return list[left];
        }else{
            return 0;
        }
    }
    center=(left+right)/2;
    maxleftsum=DivideAndConquer(list,left,center);
    maxrightsum=DivideAndConquer(list,center+1,right);

    maxleftbordersum=leftbordersum=0;
    for(i=center;i>=left;i--){
        leftbordersum+=list[i];
        if(leftbordersum>maxleftbordersum){
            maxleftbordersum=leftbordersum;
        }
    }

    maxrightbordersum=rightbordersum=0;
    for(i=center+1;i<=right;i++){
        rightbordersum+=list[i];
        if(rightbordersum>maxrightbordersum){
            maxrightbordersum=rightbordersum;
        }
    }
    return max3(maxleftsum,maxrightsum,maxleftbordersum+maxrightbordersum);
}

int MaxSubseqSum3(int list[],int n){
    return DivideAndConquer(list,0,n-1);
}

int MaxSubseqSum4(int list[],int n){
    int thissum=0,maxsum=0;
    for(int i=0;i<n;i++){
        thissum+=list[i];
        if(thissum>maxsum){
            maxsum=thissum;
        }else if(thissum<0){
            thissum=0;
        }
    }
    return maxsum;
}