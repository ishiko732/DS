#include <stdio.h>
#include <stdlib.h>

#define MaxVertexNum 100
#define INFINITY 65535
typedef int Vertex;
typedef int WeightType;
typedef char DataType;

typedef struct GNode* PtrToGNode;
struct GNode{
    int Nv;
    int Ne;
    WeightType** G;
    DataType Data[MaxVertexNum];
};
typedef PtrToGNode MGraph;

typedef struct ENode* PtrToENode;
struct ENode{
    Vertex V1,V2;
    WeightType Weight;
};
typedef PtrToENode Edge;

MGraph CreateGraph(int VertexNum){
    Vertex V,W;
    MGraph Graph;
    Graph=(MGraph)malloc(sizeof(struct GNode));
    Graph->Nv=VertexNum;
    Graph->G=(WeightType**)malloc(sizeof(WeightType)*VertexNum);
    Graph->Ne=0;
    for(V=0;V<Graph->Nv;V++){
        Graph->G[V]=(WeightType*)malloc(sizeof(WeightType)*VertexNum);
        for(W=0;W<Graph->Nv;W++){
            Graph->G[V][W]=INFINITY;
        }
    }
    return Graph;
}

void InsertEdge(MGraph Graph,Edge E){
    Graph->G[E->V1][E->V2]=E->Weight;
    // 无向图
    Graph->G[E->V2][E->V1]=E->Weight;
}

MGraph BuildGraph(){
    MGraph Graph;
    Edge E;
    Vertex V;
    int Nv,i;

    scanf("%d",&Nv);
    Graph=CreateGraph(Nv);

    scanf("%d",&(Graph->Ne));
    if(Graph->Ne!=0){
        E=(Edge)malloc(sizeof(struct ENode));
        for(i=0;i<Graph->Ne;i++){
            scanf("%d %d %d",&E->V1,&E->V1,&E->V2);
            InsertEdge(Graph,E);
        }
    }
    for(V=0;V<Graph->Nv;V++){
        scanf("%c",&(Graph->Data[V]));
    }
    return Graph;
}

typedef enum {false,true} bool;
static bool Visited[MaxVertexNum]={0,};
#include "Queue_op.c"
bool IsEdge(MGraph Graph,Vertex V,Vertex W){
    return Graph->G[V][W]<INFINITY?true:false;
}

void Visit(Vertex V){
    printf("正在访问顶点%d\n",V);
}

void DFS(MGraph Graph,Vertex V,void(*Visit)(Vertex)){
    Visit(V);
    Visited[V]=true;
    for(int W=0;W<Graph->Nv;W++){
        if(!Visited[Graph->G[V][W]]&&IsEdge(Graph,V,W)){
            DFS(Graph,W,Visit); // 利用系统栈
        }
    }
}

void BFS(MGraph Graph,Vertex S,void(*Visit)(Vertex)){
    Queue Q;
    Vertex V,W;
    Q=CreateQueue(MAXSIZE);

    Visit(S);
    Visited[S]=true;
    AddQ(Q,S);
    while(!isEmpty(Q)){
        V=DeleteQ(Q);
        for(W=0;W<Graph->Nv;W++){
            if(!Visited[W]&&IsEdge(Graph,V,W)){
                Visit(W);
                Visited[W]=true;
                AddQ(Q,W);
            }
        }
    }
}