#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

//위:0 아래:1 앞:2 뒤:3 왼쪽:4 오른쪽:5
char cube[6][3][3];
char start_colors[6] = {'w','y','r','o','g','b'};

//side_turn[i] 는 i index의 면이 가지는 4방향 측면을 오른쪽 아래 왼쪽 위 인덱스로 가지는 배열
int side_turn[6][4] = {{5,2,4,3},{4,2,5,3},{5,1,4,0},{4,1,5,0},{2,1,3,0},{3,1,2,0}};
int t,n;

void turn( int index , char dir)
{
    char tmp[3][3];
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(dir=='+')
            {
                tmp[j][2-i]=cube[index][i][j];
            }
            else
            {
                tmp[2-j][i] = cube[index][i][j];
            }
        }
    }
    memcpy(cube[index],tmp,sizeof(tmp));
}

void turn_four_side(int index, char dir)
{
    char tmp[3];
    //시계방향, 윗면
    if(dir=='+'&&index==0)
    {
        //오른쪽면 값 저장
        for(int i=0;i<3;i++) tmp[i]=cube[5][0][i];
        for(int i=0;i<3;i++) cube[5][0][i]=cube[3][0][i];
        for(int i=0;i<3;i++) cube[3][0][i]=cube[4][0][i];
        for(int i=0;i<3;i++) cube[4][0][i]=cube[2][0][i];
        for(int i=0;i<3;i++) cube[2][0][i]=tmp[i];
    }
    else if(dir=='+'&&index==1)
    {
       //오른쪽면 값 저장
        for(int i=0;i<3;i++) tmp[i]=cube[5][2][i];
        for(int i=0;i<3;i++) cube[5][2][i]=cube[3][2][i];
        for(int i=0;i<3;i++) cube[3][2][i]=cube[4][2][i];
        for(int i=0;i<3;i++) cube[4][2][i]=cube[2][2][i];
        for(int i=0;i<3;i++) cube[2][2][i]=tmp[i];
    }
    else if(dir=='+'&&index==2)
    {
       //오른쪽면 값 저장
        for(int i=0;i<3;i++) tmp[i]=cube[5][i][0];
        for(int i=0;i<3;i++) cube[5][i][0]=cube[0][2][i];
        for(int i=0;i<3;i++) cube[0][2][i]=cube[4][][2];
        for(int i=0;i<3;i++) cube[4][3][i]=cube[2][3][i];
        for(int i=0;i<3;i++) cube[2][3][i]=tmp[i];
    }
    else if(dir=='+'&&index==3)
    {
       //오른쪽면 값 저장
        for(int i=0;i<3;i++) tmp[i]=cube[5][3][i];
        for(int i=0;i<3;i++) cube[5][3][i]=cube[3][3][i];
        for(int i=0;i<3;i++) cube[3][3][i]=cube[4][3][i];
        for(int i=0;i<3;i++) cube[4][3][i]=cube[2][3][i];
        for(int i=0;i<3;i++) cube[2][3][i]=tmp[i];
    }
    else if(dir=='+'&&index==4)
    {
       //오른쪽면 값 저장
        for(int i=0;i<3;i++) tmp[i]=cube[5][3][i];
        for(int i=0;i<3;i++) cube[5][3][i]=cube[3][3][i];
        for(int i=0;i<3;i++) cube[3][3][i]=cube[4][3][i];
        for(int i=0;i<3;i++) cube[4][3][i]=cube[2][3][i];
        for(int i=0;i<3;i++) cube[2][3][i]=tmp[i];
    }
    else if(dir=='+'&&index==5)
    {
       //오른쪽면 값 저장
        for(int i=0;i<3;i++) tmp[i]=cube[5][3][i];
        for(int i=0;i<3;i++) cube[5][3][i]=cube[3][3][i];
        for(int i=0;i<3;i++) cube[3][3][i]=cube[4][3][i];
        for(int i=0;i<3;i++) cube[4][3][i]=cube[2][3][i];
        for(int i=0;i<3;i++) cube[2][3][i]=tmp[i];
    }
}

void set_cube()
{
    for(int i=0;i<6;i++)
    {
        for(int j=0;j<3;j++)
        {
            for(int k=0;k<3;k++) cube[i][j][k]=start_colors[i];
        }
    }
}

int find_index(char side)
{
    if(side == 'U') return 0;
    else if (side=='D') return 1;
    else if (side=='F') return 2;
    else if (side=='B') return 3;
    else if (side=='L') return 4;
    else return 5;
}

int main()
{
    scanf("%d",&t);
    while (t--)
    {
        set_cube();
        scanf("%d",&n);
        while (n--)
        {
            char side,dir;
            scanf("%1c%1c",&side,&dir);
            int idx=find_index(side);
            turn(idx,dir);
            turn_four_side(idx,dir);
        }
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++) printf("%c",cube[0][i][j]);
            printf("\n");
        }
    }
    return 0;
}