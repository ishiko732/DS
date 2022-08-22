List Create(ElementType e)
{
    List L = (List)malloc(sizeof(struct Node));
    L->Data = e;
    L->Next = NULL;
    return L;
}
List Read()
{
    int n;
    ElementType e;
    List L = Create(-1);
    List p = L;
    List cell = NULL;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &e);
        cell = Create(e);
        p->Next = cell;
        p = cell;
    }
    return L;
}
void Print(List L)
{
    List p = L->Next;
    if (p == NULL)
    {
        printf("NULL\n");
        return;
    }
    while (p->Next != NULL)
    {
        printf("%d ", p->Data);
        p = p->Next;
    }
    printf("%d\n", p->Data);
}

List Read_NoHead()
{
    int n;
    ElementType e;
    List L,p,cell;
    scanf("%d", &n);
    scanf("%d", &e);
    L = Create(e);
    p =L;
    for (int i = 1; i < n; i++)
    {
        scanf("%d", &e);
        cell = Create(e);
        p->Next = cell;
        p = cell;
    }
    return L;
}

void Print_NotHead( List L ){
    List p = L;
    while (p->Next)
    {
        printf("%d ", p->Data);
        p = p->Next;
    }
    printf("%d\n", p->Data);
}