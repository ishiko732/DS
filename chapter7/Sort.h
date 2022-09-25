#ifndef __SORT_H__
#define __SORT_H__

#include <stdio.h>
#include <stdlib.h>
#ifndef ElementType
typedef int ElementType;
#endif

#ifndef bool
typedef enum{false,true} bool;
#endif

#ifdef Swap
void Swap(ElementType* a,ElementType* b){
    ElementType t=*a;
    *a=*b;
    *b=t;
}
#endif
#endif