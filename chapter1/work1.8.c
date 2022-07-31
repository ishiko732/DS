#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 20
#define NotFound -1
typedef int ElementType;
typedef int Position;
typedef struct LNode *List;
struct LNode{
    ElementType Data[MAXSIZE];
    Position Last;
};

Position BinarySearch(List L,ElementType X);
int main(){
    List l=(List)malloc(sizeof(struct LNode));
    int n,x;
    scanf("%d",&n);
    l->Data[0]=NotFound;
    l->Last=n;
    for (int i=1;i<(MAXSIZE)&&i<=n;i++){
        scanf("%d",&(l->Data[i]));
    }
    scanf("%d",&x);
    printf("%d\n",BinarySearch(l,x));
    return 0;
}

Position BS(List L,ElementType X,Position left,Position right){
    if(left>right){
        return NotFound;
    }
    Position mid = (left+right)/2;
    if(L->Data[mid]>X){
        return BS(L,X,left,mid-1);
    }else if(L->Data[mid]<X){
        return BS(L,X,mid+1,right);
    }else if (L->Data[mid]==X){
        return mid;
    }
}
Position BinarySearch(List L,ElementType X){
    // return BS(L,X,1,L->Last);
    Position left,right,mid;
    left=1;
    right=L->Last;
    while(left<=right){
        mid= (left+right)/2;
        if(L->Data[mid]>X){
            right = mid-1;
        }else if (L->Data[mid]<X){
            left =mid +1;
        }else if(L->Data[mid]==X){
            return mid;
        }
    }
    return NotFound;
}


/*
5
12 31 55 89 101
31
*/

/*
3
26 78 233
31
*/

/*
5
11 15 18 22 23
18
*/

/*
6
2 3 5 8 12 25
5
*/