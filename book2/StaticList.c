#include <stdio.h>
#include <stdlib.h>
#define MaxSize 100
#define ERROR -1
typedef int Element;
struct LNode{
    Element data;
    int next;
};
typedef struct SList* SList;
struct SList{
    struct LNode dates[MaxSize];//与书本统一
    int head;
    int avail;
    int maxsize;
};

SList initSList(){
    SList s=(SList)malloc(sizeof(struct SList));
    s->head=0;
    s->dates[s->head].next=-1;
    s->avail=1;
    for(int i=1;i<s->maxsize-1;i++){
        s->dates[i].next=i+1;
    }
    s->dates[s->maxsize-1].next=-1;
    return s;
}

void Insert(SList slist,int i,Element x){
    int p=slist->head;
    int s;
    int cnt=0;
    while(slist->dates[p].next!=-1&&cnt<i-1){
        p=slist->dates[p].next;
        cnt++;
    }
    if(slist->dates[p].next==-1){
        printf("插入位置异常\n");
    }else{
        // update avail
        s = slist->avail;
        slist->dates[s].data=x;
        slist->avail=slist->dates[s].next;
        // update p
        slist->dates[s].next=slist->dates[p].next;
        slist->dates[p].next=s;
    }
}

Element Remove(SList slist,int i){
    int p=slist->head,cnt=0;
    int q;
    Element data=ERROR;
    while(p!=-1&&cnt<i-1){
        p=slist->dates[p].next;
        cnt++;
    }
    if(p==-1||slist->dates[p].next==-1){
        printf("删除错误!\n");
    }else{
        q=slist->dates[p].next;
        data=slist->dates[q].data;
        slist->dates[p].next=slist->dates[q].next;
        slist->dates[q].next=slist->avail;
        slist->avail=q;
    }
    return data;
}

Element find(SList s,int i){
    int p=s->head;
    int cnt=0;
    while(p!=-1&&cnt<i){
        p=s->dates[p].next;
        cnt++;
    }
    if(p!=-1){
        return s->dates[p].data;
    }else{
        printf("出错!\n");
    }
    return ERROR;
}