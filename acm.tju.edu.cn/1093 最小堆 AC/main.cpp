#include <iostream>
#include <string>
using namespace std;
typedef struct rf
{
    int ID;
    int time;
    int interval;
}refer;
int SearhMinTime(refer *r, int count)
{
    int minTime = r[0].time;
    int IDCur = r[0].ID;
    int iPlace = 0;

    for(int i = 1;i < count; i++)
    {
        if(minTime == r[i].time && IDCur > r[i].ID)
        {
            iPlace = i;
            IDCur = r[i].ID;
        }
        else if(minTime > r[i].time)
        {
            iPlace = i;
            minTime = r[i].time;
            IDCur = r[i].ID;
        }
    }
    return iPlace;
}
int main()
{
    refer r[1000];
    string sTemp;
    int i = 0;

    while(1)
    {
        cin >> sTemp;
        if(sTemp == "#")
        break;
        cin >> r[i].ID >> r[i].interval;
        r[i].time = r[i].interval;
        i++;
    }
    int count = i;
    int K;
    cin >> K;
    int iPlace;

    for(i = 0; i < K; i++)
    {
        iPlace=SearhMinTime(r, count);
        r[iPlace].time += r[iPlace].interval;
        cout << r[iPlace].ID << endl;
    }
}
