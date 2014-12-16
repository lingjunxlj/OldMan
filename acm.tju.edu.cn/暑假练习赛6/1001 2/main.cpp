 //------------------------------------- AdjtwGraph.h文件--------------------------------------------------
 #ifndef AdjTWGraph_H
 #define AdjTWGraph_H
 #include <vector>
 #include <iostream>
 using namespace std;
 const int MaxV=100;
 struct Edge
  {
     int dest;
     int weight;
     Edge * next;
      Edge(){}
      Edge(int d,int w):dest(d),weight(w),next(NULL){}
 };
 struct item
  {    int data;
     Edge * adj;
 };
 class AdjTWGraph
  {
 private:
     item vertices[MaxV];
     int numV,numE;
 public :
     AdjTWGraph();
     ~AdjTWGraph();
      int NumV(){return numV;}
      int NumE(){return numE;}
     int GetValue(const int i);
     int GetWeight(const int v1,const int v2);
     void InsertV(const int & vertex);
     void InsertE(const int v1,const int v2,int weight);
     friend ostream& operator<<(ostream& os,  AdjTWGraph & m)
      {     for (int i = 0; i < m.numV ; i++)     {
             for (int j = 0; j < m.numV; j++)
                 os << right << m.GetWeight(i,j) << " ";
             os << endl;
         }
         return os;
     }
     friend istream& operator>>(istream& is, AdjTWGraph & m)
      {    int t;
         for (int i = 0; i < m.NumV(); i++)
             for (int j = 0; j < m.NumV(); j++)
              {
                 is >> t;     m.InsertE(i,j,t);
             }
         return is;
     }
 };
 AdjTWGraph::AdjTWGraph()
  {
     for(int i=0;i<MaxV;i++)     vertices[i].adj=NULL;
     numV=0;numE=0;
 }
 AdjTWGraph::~AdjTWGraph()
  {
     for(int i=0;i<numV;i++)
      {
         Edge * p=vertices[i].adj,*q;
         while(p!=NULL)
          {
             q=p->next;delete p;p=q;
         }
     }
 }
  int AdjTWGraph::GetValue(const int i){    return vertices[i].data;  }
 int AdjTWGraph::GetWeight(const int v1,const int v2)
  {
     Edge *p=vertices[v1].adj;
     while(p!=NULL && p->dest<v2) p=p->next;
      if(v2!=p->dest)    {    return 0;    }
     return p->weight;
 }
  void AdjTWGraph::InsertV(const int & v) { vertices[numV].data=v; numV++;  }
 void AdjTWGraph::InsertE(const int v1,const int v2,int weight)
  {
     Edge * q=new Edge(v2,weight);
     if(vertices[v1].adj==NULL) vertices[v1].adj=q;
     else
      {
         Edge *curr=vertices[v1].adj,*pre=NULL;
          while(curr!=NULL && curr->dest<v2)    {    pre=curr;curr=curr->next;    }
          if(pre==NULL){    q->next=vertices[v1].adj;vertices[v1].adj=q;        }
          else    {    q->next=pre->next;pre->next=q;    }
     }
     numE++;
 }
 #endif

 //------------------------------------- tsp.cpp文件--------------------------------------------------
 #include "AdjtwGraph.h"
 #include <fstream>
 #include <vector>
 #include <algorithm>
 #include <ctime>
 #include <queue>
 using namespace std;
 ofstream fout("out.txt");
 int N;
 AdjTWGraph g;
 struct Node
  {   int currentIndex;
     int level;
     Node * previous;
      Node(int L = 0, int V = 0, Node *p = NULL):level(L),currentIndex(V), previous(p) {}
 };
 class TspBase
  {
 protected:
     vector<int> currentPath;
     vector<int> bestPath;
     int cv;
     int bestV;
     Node * root;

     int SumV();
     void EnumImplicit(int k);
     void BackTrackImplicit(int k);

     void EnumExplicit(Node * r);
     void BackTrackExplicit(Node * r);
     void FIFOBB();

     bool Valid(Node *p,int v)  //
          {    bool flag = true;
             for(Node *r = p; r->level > 0 && V; r = r->previous)  flag = r->currentIndex !=v;
             return flag;
         }
     void StoreX(Node * p) //
          {for(Node *r = p; r->level >0 ; r = r->previous )
  {    currentPath[r->level-1] = r->currentIndex;    }
         }
     void Print();
 public:
      TspBase(){currentPath.resize(N);    bestPath.resize(N);    }
  ~TspBase(){currentPath.resize(0);bestPath.resize(0);}

     void TspEnumImplicit();
     void TspBackTrackImplicit();

     void TspEnumExplicit();
     void TspBackTrackExplicit();

     void TspBB();

     void TspGreedy();

     void DataClear(bool flag)
      {   currentPath.resize(N);        bestPath.resize(N);
          if(flag)        { Node * p=root,*q;
                       while(p!=NULL) {q=p->previous; delete p; p=q;}
         }
     }
 };
 void TspBase::TspEnumImplicit()  //         枚举隐式
  {    fout<<"TspEnumImplicit ..."<<endl;
 cv=0; bestV=10000;
     for(int i=0;i<N;i++)    currentPath[i]=i;
     EnumImplicit(1);
     Print();
 }
 void TspBase::EnumImplicit(int k)
  {    if(k == N)
      {    if((cv + g.GetWeight(currentPath[N-1],0)) < bestV)
          {
             bestV = cv + g.GetWeight(currentPath[N-1],0);
             for(int i = 0; i < N; i++)
               bestPath[i] = currentPath[i];
         }
     }
     else
         for(int j = k; j < N; j++)
          {    swap(currentPath[k],currentPath[j]);
             cv += g.GetWeight(currentPath[k-1],currentPath[k]);
             EnumImplicit(k+1);
             cv -= g.GetWeight(currentPath[k-1],currentPath[k]);
             swap(currentPath[k],currentPath[j]);
         }
 }
 void TspBase::TspEnumExplicit()    //  枚举显式
  {   fout<<"TspEnumExplicit  ..."<<endl;
 cv=0;     bestV=10000;
      for(int i=0;i<N;i++)     currentPath[i]=i;
      root=new Node(0,-1,NULL);
      EnumExplicit(root);
      Print();
 }

 void TspBase::EnumExplicit(Node * r)
  {    if(r->level == N)
      {    StoreX(r);    cv = SumV();
         if(cv  < bestV)
          {    bestV = cv  ;
             for(int i = 0; i < N; i++)
               bestPath[i] = currentPath[i];
         }
     }
     else
         for(int i = 0; i < N; i ++)
          { if(Valid(r,i))
              {  Node *q = new Node(r->level+1,i,r);    EnumExplicit(q);    }
         }
 }
 void TspBase::TspBackTrackImplicit()     //回溯隐式
  {    fout<<"TspBackTrackImplicit ..."<<endl;
 cv=0;  bestV=10000;
     for(int i=0;i<N;i++)    currentPath[i]=i;
     BackTrackImplicit(1);
     Print();
 }
 void TspBase::BackTrackImplicit(int k)
  {    if(k == N)
      {    if((cv + g.GetWeight(currentPath[N-1],0)) < bestV)
          {
             bestV = cv + g.GetWeight(currentPath[N-1],0);
             for(int i = 0; i < N; i++)
               bestPath[i] = currentPath[i];
         }
     }
     else
         for(int j = k; j < N; j++)
          { if((cv + g.GetWeight(currentPath[k-1],currentPath[j])) < bestV)
            {    swap(currentPath[k],currentPath[j]);
                cv += g.GetWeight(currentPath[k-1],currentPath[k]);
             BackTrackImplicit(k+1);
             cv -= g.GetWeight(currentPath[k-1],currentPath[k]);
             swap(currentPath[k],currentPath[j]);
           }
         }
 }
 void TspBase::TspBackTrackExplicit()      // 回溯显式
  {    fout<<"TspBackTrackExplicit  ..."<<endl;
 cv=0;     bestV=10000;
      for(int i=0;i<N;i++)     currentPath[i]=i;
      root=new Node(0,-1,NULL);
      BackTrackExplicit(root);
      Print();
 }
 void TspBase::BackTrackExplicit(Node * r)
  {    int w=0;  //初值
     if(r->level == N)
      {    StoreX(r);
         cv = SumV();
         if(cv  < bestV)
          {   bestV = cv  ;
             for(int i = 0; i < N; i++)        bestPath[i] = currentPath[i];
         }
     }
     else
         for(int i = 0; i < N; i ++)
          {  if(Valid(r,i))
              {    Node *q = new Node(r->level+1,i,r);
                 w += g.GetWeight(q->currentIndex,i);
                 if(w < bestV)       BackTrackExplicit(q);
                 w -= g.GetWeight(q->currentIndex,i);
             }
         }
 }


 void TspBase::Print() //
  {       fout<<"the shortest path is  ";
        for(unsigned i = 0; i < N; i++)
              fout<<bestPath[i] + 1<<"--";
        fout<<"1"<<endl;
        fout<<"minimum distance is  "<<bestV<<endl;
 }

 void TspBase::TspBB()       // 分支限界法
  {        fout<<"TspBB(FIFOBB)  ........"<<endl;
 cv = 0;        bestV = 100000;
         for(unsigned i = 0; i < N; i++)    currentPath[i] = i;
         root=new Node(0,-1,NULL);
         FIFOBB();
         Print();
 }
 void TspBase::FIFOBB()
  { queue<Node*> q;   Node *r;
   q.push(root);
   int w=0;  //初值
   while(!q.empty())
    {      r = q.front();      q.pop();
       if(r->level == N)
        { StoreX(r);
         cv = SumV();
         if(cv  < bestV)
          {   bestV = cv  ;
             for(int i = 0; i < N; i++)     bestPath[i] = currentPath[i];
         }
       }
       else
         for(int i = 0; i < N; i ++)
          {    if(Valid(r,i))
              {   Node *s = new Node(r->level+1,i,r);
                 w += g.GetWeight(s->currentIndex,i);
                 if(w < bestV)       q.push(s);
                 w -=  g.GetWeight(s->currentIndex,i);
             }
         }
   }
 }
 int TspBase::SumV()           //用于FIFOBB
  {    int s = 0;
     for(int i = 0; i < N; i++)
         s += g.GetWeight(currentPath[i],currentPath[(i + 1)%N]);
     return s;
 }
 void TspBase::TspGreedy()  //TSP贪心算法
  {     fout<<"TspGreedy ........"<<endl;
 bestV = 0;
     vector<int> NEAR(N); //
     NEAR[0] = -1;
     for (int i = 1; i < N; i++)
        NEAR[i] = 0;
     bestPath[0] = 1;
     int t;
     for (int s = 1; s < N; s++)
      {
       int j = 1;
       while (j < N && NEAR[j] < 0) /
           j++;
       int K = j;
       for (int k = j + 1; k < N; k++)
          if (NEAR[k] >= 0 &&  g.GetWeight(k,NEAR[k]) < g.GetWeight(j,NEAR[j]))
                j = k;
       bestPath[s] = j + 1;
       bestV +=g.GetWeight(j,NEAR[j]);
       NEAR[j] = -1;
       for (k = K; k < N; k++) //调整NEAR值
          if (NEAR[k] >= 0)
              NEAR[k] = j;
       t = j;
     }
     bestV += g.GetWeight(t,0);
     fout<<"the shortest path is  ";
     for(unsigned w = 0; w < N; w++)
        fout<<bestPath[w] <<"--";
     fout<<"1"<<endl;
     fout<<"minimum distance is  "<<bestV<<endl;
 }

 int main(int argc, char* argv[])
  {   int m,n;
     ifstream fin("data.txt");
     if(fin.bad()) return 1;
     fin >> m >> n;
     N = n;
     for(int i=0;i<N;i++)  g.InsertV(i);
     fin >> g;
     TspBase it;
     it.TspEnumImplicit();    it.DataClear(false);

     it.TspBackTrackImplicit();    it.DataClear(false);

     it.TspEnumExplicit();    it.DataClear(true);

     it.TspBackTrackExplicit();    it.DataClear(true);

     it.TspBB();    it.DataClear(true);

     it.TspGreedy();    it.DataClear(false);
     return 0;
 }
