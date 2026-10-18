#include<bits/stdc++.h>
using namespace std;

#define ROCK 1
#define PAPER 2
#define SCISSORS 3

int main(void)
{
    srand((unsigned int)time(NULL));

    int player=0;
    int robot=0;

    bool draw=false;

    do{

            cout<<"Enter you choice:"<<endl;
            cout<<"1)Rock "<<endl;
            cout<<"2)Paper "<<endl;
            cout<<"3)Scissors "<<endl;
            cout<<"Selection:";
            cin>>player;

            cout<<endl;
            ///rand()->0.....999999  0-2 +1-> 1-3
            ///remainder
            ///10%3=1
            ///11%3=2
            ///12%3=0
            ///13%3=1

            robot=(rand()%3)+1;

            if(robot==ROCK){
                cout<<"AI Choose ROCK"<<endl;
            }
            else if(robot==PAPER){
                cout<<"AI choose PAPER"<<endl;
            }
            else if(robot==SCISSORS){
                cout<<"AI choose SCISSORS"<<endl;
            }

            cout<<endl;
            ///draw=false; To play finitely
            if(player==robot){
                draw=true;
                cout<<"Draw! Play again!!"<<endl;
            }
            else if(player==ROCK&&robot==SCISSORS){
                cout<<"ROCK beats SCISSORS!You win!"<<endl;
            }
            else if(player==ROCK&&robot==PAPER){
                cout<<"PAPER beats ROCK!You Lose!"<<endl;
            }
            else if(player==PAPER && robot==ROCK){
                cout<<"PAPER beats ROCK!You Win!"<<endl;
            }
            else if(player==PAPER&&robot==SCISSORS){
                cout<<"SCISSORS beats PAPER!You Lose!"<<endl;
            }
            else if(player==SCISSORS&&robot==PAPER){
                 cout<<"SCISSORS beats PAPER!You Win!"<<endl;
            }
            else if(player==SCISSORS&&robot==ROCK){
                cout<<"ROCK beats SCISSORS!You Lose!"<<endl;
            }

    }while(draw);
    ///rock beats scissors
    ///scissors beats paper
    ///paper beats rock
}
