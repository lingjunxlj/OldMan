#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAX = 20001;
int n1, n2;
bool prime[MAX];
int value[MAX];
int q[MAX];
int c[4]=
{
    1,
    10,
    100,
    1000
};
bool BFS()
{
    int front = 0;
    int rear = 0;
    q[rear++] = n1;
    value[n1] = 0;
    int i, j;
    while (front < rear)
    {

        int temp;
        temp = q[front++];
        if (temp == n2)
        return 1;
        for (i = 0; i < 4; i++)
        {
            int digit = (temp / c[i]) % 10;
            for (j = 0; j < 10; j++)
            {
                int change = temp - digit*c[i] + j*c[i];
                if (change >= 1000 && j != digit && prime[change] && value[change] == -1)
                {
                    q[rear++] = change;
					value[change] = value[temp] + 1;
                }
            }
        }
    }
    return 0;
}
int main()
{
    int n;
    for(int i = 1; i <= 9999; ++i)
		prime[i] = true;
    for(int i = 2; i < 5000; ++i)
    {
        if(prime[i])
		{
			for(int j = 2*i; j <= 9999; j += i)
				prime[j] = false;
		}
    }
    cin>>n;
    while (n--)
    {
        cin>>n1>>n2;
        memset(value, -1, sizeof (value));
        if (prime[n1] && prime[n2])
        {
            if (BFS())
                printf("%d\n", value[n2]);

			else
				printf("Impossible\n");

        }
        else
        printf("Impossible\n");
    }
}
