#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
typedef struct Head_
{
    int ID;
    int Time;
    int Interval;
}Head;
int Min_Heap(Head *root, int Count)
{
    int MinTime = root[0].Time;
    int IdCur = root[0].ID;
    int Iplace = 0;
    int i;

    for (i = 0; i < Count; i++)
    {
        if ( MinTime == root[i].Time && IdCur > root[i].ID )
        {
            Iplace = i;
            IdCur = root[i].ID;
        }
        else if (MinTime > root[i].Time)
        {
            Iplace = i;
            MinTime = root[i].Time;
            IdCur = root[i].ID;
        }
    }
    return Iplace;
}
int main()
{
    Head root[1001];
    string str;
    int k = 0, i;
    while (cin >> str)
    {
        if (str == "#")
        break;

        cin >> root[k].ID >> root[k].Interval;
        root[k].Time = root[k].Interval;
        k++;
    }

    int Count = k;
    int temp;
    cin >> temp;
    int Iplace;

    for (i = 0; i < temp ; i++)
    {
        Iplace = Min_Heap(root, Count);
        root[Iplace].Time += root[Iplace].Interval;
        cout << root[Iplace].ID << endl;
    }
}
