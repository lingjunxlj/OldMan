#include <iostream>
#include <cstdio>
using namespace std;
int Sum, M, N, Best_Value, Now_Value, Sum_Value, Station_Num[11];
struct Node
{
    int First;
    int End;
    int Num;
    int Earn;
}Order[31];
bool cmp (Node x, Node y)
{
    return x.Earn > y.Earn;
}
void DFS(int Passenger_Ca)
{
    int i;
    if (Passenger_Ca > N)
    {
        if (Best_Value < Now_Value)
        Best_Value = Now_Value;
        return;
    }
    bool Flag = 0;
    for (i = Order[Passenger_Ca].First; i < Order[Passenger_Ca].End; i++)
    {
        if (Station_Num[i] + Order[Passenger_Ca].Num > Sum)
        {
            Flag = 1;
            break;
        }
    }
    if (!Flag)
    {
        for (i = Order[Passenger_Ca].First; i < Order[Passenger_Ca].End; i++)
        Station_Num[i] +=  Order[Passenger_Ca].Num;

        Now_Value += Order[Passenger_Ca].Earn;
        Sum_Value -= Order[Passenger_Ca].Earn;

        DFS(Passenger_Ca + 1);

        for (i = Order[Passenger_Ca].First; i < Order[Passenger_Ca].End; i++)
        Station_Num[i] -=  Order[Passenger_Ca].Num;

        Now_Value -= Order[Passenger_Ca].Earn;
        Sum_Value += Order[Passenger_Ca].Earn;
    }
    if (Sum_Value + Now_Value > Best_Value)
    DFS(Passenger_Ca + 1);
}
int main()
{
    int i;
    while(scanf("%d %d %d", &Sum, &M, &N) != EOF)
    {
        if(Sum == 0 && M == 0 && N == 0)
            break;
        for(i = 1; i <= N; i ++)
        {
            scanf("%d %d %d", &Order[i].First, &Order[i].End, &Order[i].Num);
            Order[i].Earn = Order[i].Num * (Order[i].End - Order[i].First);
            Sum_Value += Order[i].Earn;
        }
        memset(Station_Num, 0, sizeof(Station_Num));
        sort(Order + 1, Order + N + 1, cmp);
        Best_Value = 0;
        Now_Value = 0;
        DFS(1);
        printf("%d\n", Best_Value);
    }
}
