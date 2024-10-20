#include <iostream>
#include <conio.h>
#include <windows.h>
#define WIDTH 20
#define HEIGHT 20
using namespace std;

int tailx[50],taily[50];
int tail;

enum Directions {STOP,UP,DOWN,LEFT,RIGHT};
Directions dir;

bool gameover{};
int x,y,Fruitx,Fruity,score{};

void Draw();
void Input();
void logic();

void setup()
{
    gameover = false;
    dir = STOP;
    x = WIDTH/2;
    y = HEIGHT/2;
    Fruitx = rand()%WIDTH;
    Fruity = rand()%HEIGHT;
}



int main()
{
    setup();
    while(!gameover)
    {
        Draw();
        Input();
        logic();
        Sleep(200);
    }


    return 0;
}



void Draw()
{
    for(int i{};i<WIDTH;i++)
        std::cout<<"#";
    std::cout<<std::endl;

    for(int i{};i<HEIGHT;i++)
    {
        for(int j{};j<WIDTH;j++)
        {
            if((j==0)||(j==WIDTH - 1))
                std::cout<<"#";
            else if ((i==y)&&(j==x))
                std::cout<<"O";
            else if ((i==Fruity)&&(j==Fruitx))
                std::cout<<"F";
            else
            {
                bool print_space = false;
                for(int k{};k<tail;k++)
                {
                    if((i == taily[k]) && (j == tailx[k]))
                    {
                        std::cout<<"o";
                        print_space = true;
                    }
                }
                if(!print_space)
                {
                    std::cout<<" ";
                }
            }
        }
        std::cout<<std::endl;
    }
    for(int i{};i<WIDTH;i++)
        std::cout<<"#";
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<"Score: "<<score<<endl;
}
void Input()
{
    if(_kbhit())
    {
        switch(_getch())
        {
        case 'w':
            dir = UP;
            break;
        case 'a':
            dir = LEFT;
            break;
        case 's':
            dir = DOWN;
            break;
        case 'd':
            dir = RIGHT;
            break;
        }
    }
}

void logic()
{
    int prevx = tailx[0];
    int prevy = taily[0];
    tailx[0] = x;
    taily[0] = y;
    int prev_x,prev_y;
    for(int i{1};i<=tail;i++)
    {
        prev_x = tailx[i];
        prev_y = taily[i];

        tailx[i] = prevx;
        taily[i] = prevy;

        prevx = prev_x;
        prevy = prev_y;
    }

    switch(dir)
    {
        case UP:
            y--;
            break;
        case DOWN:
            y++;
            break;
        case RIGHT:
            x++;
            break;
        case LEFT:
            x--;
            break;
    }
    if((x<0)||(x>WIDTH)||(y<0)||(y>HEIGHT))
    {
        gameover = true;
    }

    for(int i{};i<tail;i++)
    {
        if((x==tailx[i])&&(y==taily[i]))
        {
            gameover=true;
        }
    }

    if((x == Fruitx)&&(y == Fruity))
    {
        score+=10;
        Fruitx = rand()%WIDTH;
        Fruity = rand()%HEIGHT;
        tail++;
    }
}
