#include <iostream>
#include <vector>
#include <time.h>
#include <cstdlib>
#include <string.h>

using namespace std;

const int PlayerIndex = 1;
const int BotNum = 2;


bool checkTicked(vector<int> ticked, int a)
{
    for(int x : ticked)
    {
        if(x==a)
        {
            return false;
        }
    }
    return true;
}
void tick(int (&tt)[3][3] ,int location, int playerIndex )
{
    switch(location)
    {
        case 1:
        tt[0][0] = playerIndex; break;
        case 2:
        tt[0][1] = playerIndex; break;
        case 3:
        tt[0][2] = playerIndex; break;
        case 4:
        tt[1][0] = playerIndex; break;
        case 5:
        tt[1][1] = playerIndex; break;
        case 6:
        tt[1][2] = playerIndex; break;
        case 7:
        tt[2][0] = playerIndex; break;
        case 8:
        tt[2][1] = playerIndex; break;
        case 9:
        tt[2][2] = playerIndex; break;
    }
}
bool checkTriNum(int a,int b,int c,int num)
{
    if(a==b&&b==c&&a!=num)
    {
        return true;
    }
    return false;
}

void display(int tt[3][3])
{
    int indexNum[9] = {1,2,3,4,5,6,7,8,9};
    int index = 0;
    for(int i =0;i<3;i++)
    {
        cout<<"+---+---+---+"<<endl;
        for(int j=0;j<3;j++)
        {
            if(j==0)
            {
                cout<<"|";
            }
            if(tt[i][j] == 0)
            {
                cout<<" "<<indexNum[index]<<" " ;
                cout<<"|";
                ++index;
            }else if(tt[i][j] == PlayerIndex)
            {
                cout<<" X ";
                cout<<"|";
                ++index;
                
            }else if(tt[i][j] == BotNum)
            {
                cout<<" O ";
                cout<<"|";
                ++index;
            }
        }
        if(i==2){
            cout<<endl<<"+---+---+---+";
        }
        cout<<endl;
    }
}
int checkWin( int tt[3][3], int index1, int index2)
{
    for(int i =0;i<3;i++)
    {
        if(checkTriNum(tt[i][0],tt[i][2],tt[i][1],0))
        {
            return (tt[i][1] == index1)? (index1) : (index2);
        }
    }
    for(int i = 0;i<3;i++)
    {
        if(checkTriNum(tt[0][i],tt[2][i],tt[1][i],0))
        {
            return (tt[1][i] == index1)? (index1) : (index2);
        }
    }
    if(checkTriNum(tt[0][0],tt[1][1],tt[2][2],0))
    {
        return (tt[1][1] == index1)? (index1) : (index2);
    }
    if(checkTriNum(tt[0][2],tt[1][1],tt[2][0],0))
    {
        return (tt[1][1] == index1)? (index1) : (index2);
    }
    return 0;
}

void playerTick(int (&tt)[3][3], vector<int>& ticked)
{
    int input;
    do{

        cout<<"Nhap tu 1 den 9 de chon o :"; cin>>input;

    }while(checkTicked(ticked,input) == false||input>9||input<1);

    ticked.push_back(input);

    tick(tt,input,PlayerIndex);
}

void botPlay(int (&tt)[3][3],vector<int>& ticked)
{
    srand(time(NULL));
    int botInput;
    do{
    botInput = rand() % 9 + 1;
    }while(!checkTicked(ticked,botInput));

    ticked.push_back(botInput);

    tick(tt, botInput, BotNum);
    cout<<"Bot danh tai o so "<<botInput<<"."<<endl;
}

int main()
{
    vector<int> ticked ;
    int TurnCount = 0;
    int ticTable[3][3] = 
    {{0,0,0},
     {0,0,0},
     {0,0,0}};

    display(ticTable);
    do{
        if(TurnCount % 2 ==0 )
        {
            playerTick(ticTable,ticked);
            system("cls");
            TurnCount++;
            //display(ticTable);
        }else 
        {
            botPlay(ticTable,ticked);
            TurnCount++;
            display(ticTable);
        }
        if(checkWin(ticTable,PlayerIndex,BotNum) == PlayerIndex)
        {
            cout<<"Chuc mung ban thang con bot !!"<<endl;
        } 
        else if(checkWin(ticTable,PlayerIndex,BotNum) == BotNum)
        {
            cout<<"Ban ga hon con bot!!"<<endl;
        }
        if(TurnCount == 9&&checkWin(ticTable,PlayerIndex,BotNum) == 0)
        {
            cout<<"Hoa!"<<endl;
            break;
        }
    }while(!checkWin(ticTable,PlayerIndex,BotNum));

    
    
    return 0;
}