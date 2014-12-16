#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int n=9;
const int len=3;

const int maxrow=n*n*n; //row, col, value
const int maxcol=3*n*n; //row, col, block, cell

struct Node
{
    int row,col,num;
    Node *left, *right, *up, *down;
};

Node head,row[maxrow+10],col[maxcol+10],node[maxrow*maxcol+2000];
int nodenum;
int count[maxcol+10];
  int result[maxrow+10];
  char temp[2000];

  void linkinit()
  {
      memset(count,0,sizeof(count));
      nodenum=0;
      head.col=head.row=0;
    head.right=head.left=head.up=head.down=&head;
    for (int i=0;i<maxcol;i++) {
        col[i].left=head.left;
          head.left=&col[i];
         col[i].right=&head;
          col[i].num=0;
         col[i].col=i;
         col[i].up=col[i].down=&col[i];
          col[i].left->right=&col[i];col[i].right->left=&col[i];
      }
      for (int i=0;i<maxrow;i++) {
          row[i].up=head.up;
        head.up=&row[i];
          row[i].row=i;
          row[i].down=&head;
          row[i].left=row[i].right=&row[i];
          row[i].up->down=&row[i];row[i].down->up=&row[i];
      }
  }

  void link(int r,int c,int num,int coln)
  {
      int rown=r*n*n+c*n+num;
      count[coln]++;
      node[nodenum].row=rown;node[nodenum].col=coln;
      node[nodenum].up=&col[coln];
      node[nodenum].down=col[coln].down;
      col[coln].down->up=&node[nodenum];
      col[coln].down=&node[nodenum];
      node[nodenum].left=&row[rown];
      node[nodenum].right=row[rown].right;
      row[rown].right->left=&node[nodenum];
      row[rown].right=&node[nodenum];
      nodenum++;
  }

  void removerowhead()
  {
      for (int i=0;i<maxrow;i++) {
          row[i].left->right=row[i].right;
          row[i].right->left=row[i].left;
      }
  }

  void remove(int coln)
  {
      col[coln].left->right=col[coln].right;
      col[coln].right->left=col[coln].left;
      for (Node * curr=col[coln].down;curr!=&col[coln];curr=curr->down)
      {
          for (Node * tmp=curr->right;tmp!=curr;tmp=tmp->right)
          {
              count[tmp->col]--;
              tmp->up->down=tmp->down;
              tmp->down->up=tmp->up;
          }
          curr->left->right=curr->right;
          curr->right->left=curr->left;
      }
  }

  void resume(int coln)
  {
      for (Node * curr=col[coln].down;curr!=&col[coln];curr=curr->down)
      {
          curr->right->left=curr;
          curr->left->right=curr;
          for (Node * tmp=curr->left;tmp!=curr;tmp=tmp->left)
          {
             tmp->up->down=tmp;
             tmp->down->up=tmp;
             count[tmp->col]++;
         }
     }
     col[coln].left->right=&col[coln];
     col[coln].right->left=&col[coln];
 }

 bool solve(int k)
 {
     if (head.right==&head) return true;
     int min=2*n,rec;
     for (Node * curr=head.right;curr!=&head;curr=curr->right) {
         if (min>count[curr->col]) {
             min=count[curr->col];
             rec=curr->col;
             if (min<=1) break;
         }
     }
     if (min==0) return false;
     remove(rec);
     for (Node * curr=col[rec].down;curr!=&col[rec];curr=curr->down) {
         result[k]=curr->row;
         curr->left->right=curr;
         for (Node * tmp=curr->right;tmp!=curr;tmp=tmp->right) {
             remove(tmp->col);
         }
         curr->left->right=curr->right;
         if (solve(k+1)) return true;
        curr->right->left=curr;
         for (Node * tmp=curr->left;tmp!=curr;tmp=tmp->left)
         {
             resume(tmp->col);
         }
         curr->right->left=curr->left;
    }
     resume(rec);
     return false;
 }

 void probinit()
 {
     int r,c,b;
     for (int i=0;i<n*n;i++) {
         r=i/n;c=i%n;b=(r/len)*len+(c/len);
         if (temp[i]=='?') {
             for (int j=0;j<n;j++) {
                 link(r,c,j,r*n+j);//row
                 link(r,c,j,n*n+c*n+j);//column
                 link(r,c,j,n*n*2+b*n+j);//block
                 link(r,c,j,n*n*3+i);//cell
             }
         }
         else {
             int j=temp[i]-'0';
             link(r,c,j,r*n+j);//row
             link(r,c,j,n*n+c*n+j);//column
             link(r,c,j,n*n*2+b*n+j);//block
             link(r,c,j,n*n*3+i);//cell
         }
     }
 }

 void printres()
 {
     int r,c,num;
     int numb[n*n+10]={0};
     for (int i=0;i<n*n;i++)
     {
         r=result[i]/(n*n);
         c=(result[i]-r*n*n)/n;
         num=result[i]%n;
         numb[r*n+c]=num+1;
     }
     for (int i=0;i<n*n;i++) {
         printf("%c",numb[i]+'A'-1);
         if ((i+1)%n==0) printf("\n");
     }
     printf("\n");
 }

 int main()
 {
     char tmpp[100];
     int x;
     cin>>x;
     //while(scanf("%s",tmpp)!=EOF)
     while(x--)
     {
         memset(temp,0,sizeof(temp));
         //strcat(temp,tmpp);
         for (int i=0;i<n;i++) {
             cin>>tmpp;
             strcat(temp,tmpp);
         }
         linkinit();
         probinit();
         removerowhead();
         if(solve(0))
            printf("YES\n");
        else
            printf("NO\n");
         //printres();
     }
     return 0;
 }
