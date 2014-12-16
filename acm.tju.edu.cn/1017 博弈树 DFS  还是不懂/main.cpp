/*

http://acm.pku.edu.cn/JudgeOnline/problem?id=1143

博弈论(DFS + 状态记忆表 + 位运算), 假定一个走的人是A，第二个走的人是B
 A在当前状态下一定能够取胜的条件是:当前状态下存在一个数字,对于当A取走
 这个数字后的状态,B不管怎么取都得输(即B不能够绝对取胜)

 有了上面的分析就很容易看出这是一道博弈题，最终会形成一棵博弈树.假定最上面一层
 是A开始取,编号是1,那么所有A来取的都是奇数层,所有B来取的都是偶数层,奇数层对A来
 说, 各种取法之间是或的关系,即只要存在一种可以取胜的情况那么A就从当前层胜出,而
 偶数层对A来说是与的关系,即只有当所有取法对B来说都是输的时候A才获胜.(其实偶数层
 对B来说也是或的关系,只要有一种取法导致A输掉,B就获胜,所以相对A来说就是与关系了)
 */

#include <iostream>
#include <cstdio>
#include <cstring>
#define MAX_N 20             //最大N
#define MAX_STATE 1048576    //2 ^ 20, 最大的状态数
using namespace std;

int exp[MAX_N + 1];          //记录2 ^ i
bool res[MAX_N + 1];         //记录结果,res[i] = true表示对A来说取数字 i + 1 是winning move
int record[MAX_STATE];       //记忆表, 其取值表示当前状态是winning move 还是 losing move
                             //1: winning move, 2: losing move, 0: not sure yet.
                             //比如: record[18] = 1表示对当前取者来说18是winning move;
                             //record[6] = 2,表示对对当前取者来说, 6不是winning move
int num, state, maxD;

bool dfs(int curState, int curLevel)
{
    //如果无数字可取, 则是losing move
    if(curState == 0)
        return false;
    int i, j, k, newState;
    bool can = true;
    bool finalCan = false;

    //遍历所有可取的数字
    for(i = 0; i <= maxD - 1; i++)
    {
        if(curState & exp[i])
        {
            //取这个数字, 将对应bit置为0
            newState = curState ^ exp[i];
            //取完后,要做一个判断,对于比所取数字大的其他数字,进行加法分解,
            //如果存在一个分解,分解得到的两个数字都已经被取过了,那么这个数不应该继续存在也需要被置0
            //比如:对于状态2 3 4 5,如果取了2,那么4肯定就也不能继续存在了
            for(j = i + 1 + 1; j <= maxD; j++)
            {
                if((newState & exp[j - 1]) == 0)
                    continue;
                for(k = 2; k <= j / 2; k++)
                {
                    if((newState & exp[k - 1]) == 0 && (newState & exp[j - k - 1]) == 0)
                    {
                        newState = newState ^ exp[j - 1];
                        break;
                    }
                }
            }
            int  t;

            //查看记忆表,看这个状态是否已经计算过了
            t = record[newState];

            bool type;
            if(t == 1)
                type = true;
            else if(t == 2)
                type = false;
            else //没有计算过的话需要进一步DFS
                type = dfs(newState, curLevel + 1);
            //对于第一层需要额外记忆,以便最终输出
            if(curLevel == 1)
            {
                if(!type)
                {
                    res[i] = true;
                    finalCan = true;
                    //写入记忆表
                    if(!record[curState]) record[curState] = 1;
                }
            }
            //如果对方下一步不可取,那么当前就是winning move
            else if(!type)
            {
                //记忆并返回
                if(!record[curState]) record[curState] = 1;
                return true;
            }

        }
    }
    if(curLevel == 1)
    {
        if(finalCan)
        {
            if(!record[curState]) record[curState] = 1;
            return true;
        }
        else
        {
            if(!record[curState]) record[curState] = 2;
            return false;
        }
    }
    //能走到这儿说明对于自己的所有走法,对方都能够取得winning move,所以自己是losing move
    else
    {
        if(!record[curState]) record[curState] = 2;
            return false;
    }
}
int main()
{
    int i, digit, caseNum = 0;
    exp[0] = 1;
    for(i = 1; i < MAX_N; i++)
        exp[i] = exp[i - 1]<<1;
    while(cin>>num && num != 0)
    {
        caseNum++;
        state = 0;
        maxD = INT_MIN;
        memset(res, 0, sizeof(res));
        //memset(record, 0, sizeof(record)); 不要清0,因为记忆表还可以留给下一个case用
        for(i = 1; i <= num; i++)
        {
            cin>>digit;
            if(digit > maxD)
                maxD = digit;
            state = state | exp[digit - 1];
        }
        bool can = dfs(state, 1);
        cout<<"Scenario #"<<caseNum<<endl;
        if(!can)
            cout<<"There's no winning move."<<endl;
        else
        {
            cout<<"The winning moves are:";
            for(i = 0; i < maxD; i++)
            {
                if(res[i])
                    cout<<" "<<i + 1;
            }
            cout<<endl;
        }
        cout<<endl;
    }
    return 0;

}
