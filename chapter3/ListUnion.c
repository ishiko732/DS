#include <stdio.h>
#include <stdlib.h>
#define max 100
#define _CRT_SECURE_NO_DEPRECATE
struct LNode
{
    int Data[max];
    int Length;
};
typedef struct LNode *PtrToNode;
typedef PtrToNode List;

List CreateList()
{
    int n;
    List l;
    // printf("Data number of:");
    scanf("%d", &n);
    if (n < 0)
    {
        return NULL;
    }
    l = (List)malloc(sizeof(struct LNode));
    // printf("Data message:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", l->Data + i);
    }
    l->Length = n;
    return l;
}

List CreateListEmpty()
{
    List l;
    l = (List)malloc(sizeof(struct LNode));
    l->Length = 0;
    return l;
}

List IntersectionList(List La, List Lb)
{
    List Lc = CreateListEmpty();
    int p, q;
    p = q = 0;
    while (La->Length > p && Lb->Length > q)
    {
        if (La->Data[p] > Lb->Data[q])
        {
            q++;
        }
        else if (La->Data[p] < Lb->Data[q])
        {
            p++;
        }
        else if (La->Data[p] == Lb->Data[q])
        {
            Lc->Data[Lc->Length++] = La->Data[p];
            p++;
            q++;
        }
    }
    return Lc;
}

int main()
{
    List La, Lb, Lc;
    // printf("交集\n");

    // printf("请输入集合A的信息:\n");
    La = CreateList();
    // printf("请输入集合B的信息:\n");
    Lb = CreateList();
    /**
     * A value 4 1 3 5 7
     * B value 5 1 2 4 5 7
     * C value 3 1 5 7
     */
    Lc = IntersectionList(La, Lb);
    printf("C=(");
    for (int i = 0; i < Lc->Length; i++)
    {
        if (i == Lc->Length - 1)
            printf("%d)\n", Lc->Data[i]);
        else
            printf("%d,", Lc->Data[i]);
    }
    return 0;
}