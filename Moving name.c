#include<stdio.h>
#include<windows.h>
void gotoxy(int x,int y){ ///gotoxy is not a pre defined function
 COORD c; ///COORD is a data type which is declared after using console function header file
 c.X=x; ///Assign x
 c.Y=y;///Assign y
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c); ///c variable is cord type
///To work this function in gotoxy
}
 int main()
{
    int x=30,y=10;
    char ch;
    gotoxy(x,y); ///To set cursor position
    printf("AkikSalim");
    while(1){  ///Here 1 means infinite loop
        ch=getch(); ///switching ch variable
        switch(ch){
        case 'a':
            x--; ///left moving
            break;
        case 's':
            x++; ///right moving
            break;
        case 'w':
            y--; ///UP and decrement
            break;
        case 'z':
            y++; ///DOWN and increment
            break;
        case 27:
            exit(0);
        }
        system("cls"); ///screen clear korbe kuno return lekha ashbe na
        gotoxy(x,y);
        printf("AkikSalim");
    }
    return 0;
}
