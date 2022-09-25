#include <stdio.h>
#include <stdlib.h>

#define MaxVertexNum 20 //顶点最大个数
#define INFINITY 65535
typedef int Vertex;
typedef int WeightType;
typedef char DataType;

#ifndef MGraph
typedef struct GNode* PtrToGNode;
struct GNode{
    int Nv;
    int Ne;
    WeightType G[MaxVertexNum][MaxVertexNum];
    DataType Data[MaxVertexNum];
};
typedef PtrToGNode MGraph;

typedef struct ENode* PtrToENode;
struct ENode{
    Vertex V1,V2;
    WeightType Weight;
};
typedef PtrToENode Edge;
#endif

#ifndef LGraph
typedef struct AdjVNode* PtroToAdjVNode;
struct AdjVNode
{
    Vertex AdjV;
    WeightType Weight;
    PtroToAdjVNode Next;
};

typedef struct VNode{
    PtroToAdjVNode FirstEdge;
    DataType Data;
} *AdjList;

typedef struct LGNode* PtrToLGNode;
struct LGNode
{
    int Nv;
    int Ne;
    AdjList G;
};
typedef PtrToLGNode LGraph;
#endif

#ifndef bool
typedef enum{false,true} bool;
#endif

static bool Visited[MaxVertexNum]={0,};

MGraph CreateMGraph(int VertexNum){ //CreateMartix
    Vertex V,W;
    MGraph Graph;
    Graph=(MGraph)malloc(sizeof(struct GNode));
    Graph->Nv=VertexNum;
    Graph->Ne=0;
    for(V=0;V<Graph->Nv;V++){
        for(W=0;W<Graph->Nv;W++){
            Graph->G[V][W]=0;
        }
    }
    return Graph;
}
void InsertMGraphEdge(MGraph Graph,Edge E){
    Graph->G[E->V1][E->V2]=E->Weight;
    // 无向图
    Graph->G[E->V2][E->V1]=E->Weight;
}

MGraph BuildMGraph(char *fileName){ // CreateMartix
    MGraph Graph;
    Edge E;
    Vertex V;
    int Nv,i;

    FILE *fp=fopen(fileName,"r");
    fscanf(fp,"%d",&Nv); // read Vertex
    Graph=CreateMGraph(Nv);

    fscanf(fp,"%d",&(Graph->Ne)); // read Edge
    if(Graph->Ne!=0){
        E=(Edge)malloc(sizeof(struct ENode));
        for(i=0;i<Graph->Ne;i++){
            fscanf(fp,"%d %d %d",&E->V1,&E->V2,&E->Weight);
            InsertMGraphEdge(Graph,E);
        }
    }
    fclose(fp);
    return Graph;
}

LGraph CreateLGraph(int VertexNum){
    Vertex V;
    LGraph Graph;

    Graph=(LGraph)malloc(sizeof(struct LGNode));
    Graph->Nv=VertexNum;
    Graph->Ne=0;
    Graph->G=(AdjList)malloc(sizeof(struct VNode)*VertexNum);
    for(V=0;V<Graph->Nv;V++){
        Graph->G[V].FirstEdge=NULL;
    }
    return Graph;
}

void InsertLGraphEdge(LGraph Graph,Edge E){
    PtroToAdjVNode NewNode;
    NewNode=(PtroToAdjVNode)malloc(sizeof(struct AdjVNode));
    NewNode->AdjV=E->V2;
    NewNode->Weight=E->Weight;

    NewNode->Next=Graph->G[E->V1].FirstEdge;
    Graph->G[E->V1].FirstEdge=NewNode;
}

LGraph BuildLGraph(char *fileName){
    LGraph Graph;
    Edge E;
    Vertex V;
    int Nv,i;
    FILE *fp=fopen(fileName,"r");
    fscanf(fp,"%d",&Nv);
    Graph=CreateLGraph(Nv);

    fscanf(fp,"%d",&(Graph->Ne));
    if(Graph->Ne!=0){
        E=(Edge)malloc(sizeof(struct ENode));
        for(i=0;i<Graph->Ne;i++){
            fscanf(fp,"%d %d %d",&E->V1,&E->V2,&E->Weight);
            InsertLGraphEdge(Graph,E);
        }
    }
    return Graph;
}

void printMGraph(MGraph Graph){
    for(int V=0;V<Graph->Nv;V++){
        for(int W=0;W<Graph->Nv;W++){
            printf("%d ",Graph->G[V][W]);
        }
        printf("\n");
    }
    printf("\n");
}

void printLGraph(LGraph Graph){
    PtroToAdjVNode WNode;
    WeightType G[MaxVertexNum][MaxVertexNum]={0,};
    for(int V=0;V<Graph->Nv;V++){
        for(WNode=Graph->G[V].FirstEdge;WNode;WNode=WNode->Next){
            G[V][WNode->AdjV]=WNode->Weight;
        }
    }
    
    for(int V=0;V<Graph->Nv;V++){
        for(int W=0;W<Graph->Nv;W++){
            printf("%d ",G[V][W]);
        }
        printf("\n");
    }
    printf("\n");
}

void Visit(Vertex V){
    printf("%d ",V);
}
void ResetVisted(){
    for(int V=0;V<MaxVertexNum;V++){
        Visited[V]=false;
    }
}
void DFS(LGraph Graph,Vertex V,void(*Visit)(Vertex)){
    PtroToAdjVNode W;
    // Visit(V);
    // Visited[V]=true;
    Vertex Stack[MaxVertexNum];
    int p=0;
    Stack[p++]=V;
    while (p!=0){
        V=Stack[--p];
        if(!Visited[V]){
            Visit(V);
            Visited[V]=true;
        }
        for(W=Graph->G[V].FirstEdge;W;W=W->Next){
            if(!Visited[W->AdjV]){
                Stack[p++]=W->AdjV;
                // DFS(Graph,W->AdjV,Visit);
            }
        }
    }
}

void BFS(LGraph Graph,Vertex S,void(*Visit)(Vertex)){
    Vertex V,W;
    PtroToAdjVNode WNode;
    Vertex Q[MaxVertexNum];
    int Q1=0,Q2=0;
    Visit(S);
    Visited[S]=true;
    // Q2=(Q2+1)%MaxVertexNum;
    Q[Q2++]=S;
    while(Q2!=Q1){
        // Q1=(Q1+1)%MaxVertexNum;
        V=Q[Q1++];
        for(WNode=Graph->G[V].FirstEdge;WNode;WNode=WNode->Next){
            W=WNode->AdjV;
            if(!Visited[W]){
                Visit(W);
                Visited[W]=true;
                // Q2=(Q2+1)%MaxVertexNum;
                Q[Q2++]=W;
            }
        }
    }
}

void Menu(){
    int choose;
    Vertex V;
    MGraph G1;
    LGraph G2;
	while (1) {
        printf( "***********************************************\n");
        printf( "*********         0--退出程序        **********\n");
        printf( "*********    1--打印邻接矩阵无向图   **********\n");
        printf( "*********    2--创建有向图的邻接表   **********\n");
        printf( "*********    3--打印有向图的邻接表   **********\n");
        printf( "*********    4--邻接表深度优先遍历   **********\n");
        printf( "*********    5--邻接表广度优先遍历   **********\n");
        printf( "***********************************************\n");
        scanf("%d",&choose);
        if(choose==0){
            break;
        }
		switch (choose) {
		case 1: {
			G1=BuildMGraph("/Users/liuyuanfeng/Desktop/081203/DS/chapter6/input1.in");
            printMGraph(G1);
			break;
		}
		case 2:
        case 3:
         {
            G2=BuildLGraph("/Users/liuyuanfeng/Desktop/081203/DS/chapter6/input2.in");
			printLGraph(G2);
			break;
		}
		case 4: {
			printf( "输入从哪个顶点开始遍历(序号从0开始):");
			scanf("%d",&V);
            ResetVisted();
			DFS(G2,V,Visit);
            printf("\n");
			break;
		}
		case 5: {
			printf( "输入从哪个顶点开始遍历(序号从0开始):");
			scanf("%d",&V);
            ResetVisted();
			BFS(G2,V,Visit);
            printf("\n");
			break;
		}
		default:
            printf( "输入错误，请重新选择！");
            break;
		}
	}
}
int main(){
    Menu();
    return 0;

}
// int main(){
//     // // func1
//     // MGraph G1=BuildMGraph("/Users/liuyuanfeng/Desktop/081203/DS/chapter6/input1.in");
//     // printMGraph(G1);

//     // //func2
//     // LGraph G2=BuildLGraph("/Users/liuyuanfeng/Desktop/081203/DS/chapter6/input2.in");
//     // //func3
//     // printLGraph(G2);

//     // //func4
//     // printf("DFS:");
//     // DFS(G2,0,Visit);
//     // printf("\n");

//     // //func5
//     // printf("BFS:");
//     // ResetVisted();
//     // BFS(G2,1,Visit);
//     // printf("\n");
// }