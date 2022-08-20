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