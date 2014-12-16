#include <cstdio>
#include <cstring>
struct node
{
    char ch;
    node *lchild;
    node *rchild;
    node()
    {
        lchild = NULL;
        rchild = NULL;
    }
};
char str[1001];
int l;
node *create(node *b)
{
    b->ch = str[l--];
    if(l < 0 || b->ch > 'Z')
        return b;

    b->rchild = new node();
    b->rchild = create(b->rchild);

    if(l < 0)
        return b;

    b->lchild = new node();
    b->lchild = create(b->lchild);

    return b;
}
void printn(node *b)
{
    if(b)
    {
        printn(b->lchild);
        printf("%c", b->ch);
        printn(b->rchild);
    }
}
int main()
{
    int t;
    scanf("%d", &t);
    node *bt;
    while(t--)
    {
        scanf("%s", str);
        l = strlen(str);

        l--;
        bt = new node();
        bt = create(bt);

        printn(bt);
        printf("\n");
       }
}
