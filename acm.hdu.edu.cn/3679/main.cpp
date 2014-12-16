#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAX = 1000;
int box[3][MAX];
int sai[3][MAX];
int N,i,j;
int main()
{
    int count = 0;
    int degree = 0;
    while (cin>>N, N)
    {
        count++;
        for (i = 0; i < 3; i++)
            for (j = 0; j < N; j++)
                cin>>box[i][j];


        for (j = 0; j < N; j++)
        {
            int col = box[0][j] - 1;
            int rank = j + 1;
            sai[0][col] = rank;
            col = box[1][j] - 1;
            rank = j + 1;
            sai[1][col] = rank;
            sai[2][j] = box[2][j];
        }
        for (int b = 0; b < N; b++)
        {
            if (sai[0][b] <= sai[2][b])
                degree += 3;
            else if (sai[0][b] < sai[1][b])
                degree += 2;

            else
                degree += 1;
        }
        cout<<"Case "<<count<<": "<<degree<<endl;
        degree = 0;
    }
    return 0;
}
