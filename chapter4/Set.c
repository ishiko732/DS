#include <stdio.h>
#include <stdlib.h>
#ifndef MAXN
#define MAXN 1000
#endif
#ifndef ElementType
typedef int ElementType;
#endif
typedef int SetName;
typedef ElementType SetType[MAXN];

SetName Find(SetType S,ElementType X){ // 压缩路径
    // for(;S[X]>=0;X=S[X]);
    // return X;
    if(S[X]<0){
        return X;
    }else{
        return S[X]=Find(S,S[X]);
    }
}

void Union1(SetType S,SetName Root1,SetName Root2){ // 简单的并操作
    S[Root2]=Root1;
}

void Union(SetType S,SetName Root1,SetName Root2){
    if(S[Root2]<S[Root1]){ // 若Root2大于Root1 (这里Root1,Root2带有负号)
        S[Root2]+=S[Root1]; // 合并小树root1
        S[Root1]=Root2; //Root1 指向 Root2(小树指向大树)
    }else{
        S[Root1]+=S[Root2];
        S[Root2]=Root1;
    }
}