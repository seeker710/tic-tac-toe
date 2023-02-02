#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void h_r(int d[9], int e[9], char f[10]);
void shift(int g[9], int h[9], char j[10]);
void display(int k[9], int l[9], char m[10]);
void judge(int n[9], int o[9], char p[10]);
void m_r(int q[9], int r[9], char s[10]);

int main()
{
    int a[9]={0, 0, 0, 0, 0, 0, 0, 0, 0};
    printf("\nGame Board:");
    int b[10]={1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    char c[10]={};
    printf("Tic-Tac-Toe by Sagar Mandal");
    printf("\n1 | 2 | 3");
    printf("\n---------");
    printf("\n4 | 5 | 6");
    printf("\n---------");
    printf("\n7 | 8 | 9");
    printf("\nHumans are greater than machines so...");
    h_r(a, b, c);
    return 0;
}
void h_r(int d[9], int e[9], char f[10])
{
    int n, flag=0, j=0;
    static int i=0;
    printf("\n\nEnter your turn: ");
    scanf("%d", &n);
    if(n<1 || n>9)
    {
        printf("\nYou fool you crashed the game...");
        exit(0);
    }
    while(d[j]!=0)
    {
        if(d[j]==n)
        flag=1;
        j++;
    }
    if(flag==1)
    {
        printf("\nInvalid move.");
        h_r(d, e, f);
    }
    else
    d[i]=n;
    f[n]='X';
    i+=2;
    shift(d, e, f);
}
void shift(int g[9], int h[9], char j[10])
{
    int i=0, pos;
    static int i1=0;
    while(h[i]!=0)
    {
        if(h[i]==g[i1])
        pos=i;
        i++;
    }
    i1+=1;
    while(h[pos]!=0)
    {
        h[pos]=h[pos+1];
        pos++;
    }
    display(g, h, j);
}
void display(int k[9], int l[9], char m[10])
{
    printf("\n%c | %c | %c", m[1], m[2], m[3]);
    printf("\n---------");
    printf("\n%c | %c | %c", m[4], m[5], m[6]);
    printf("\n---------");
    printf("\n%c | %c | %c", m[7], m[8], m[9]);
    judge(k, l, m);
}
void judge(int n[9], int o[9], char p[10])
{
    static int i=0;
    if((p[1]=='X' && p[2]=='X' && p[3]=='X') || (p[4]=='X' && p[5]=='X' && p[6]=='X') || (p[7]=='X' && p[8]=='X' && p[9]=='X') || (p[1]=='X' && p[4]=='X' && p[7]=='X') || (p[2]=='X' && p[5]=='X' && p[8]=='X') || (p[3]=='X' && p[6]=='X' && p[9]=='X') || (p[1]=='X' && p[5]=='X' && p[9]=='X') || (p[3]=='X' && p[5]=='X' && p[7]=='X'))
    {
        printf("\nYou won.");
        exit(0);
    }    
    else if((p[1]=='O' && p[2]=='O' && p[3]=='O') || (p[4]=='O' && p[5]=='O' && p[6]=='O') || (p[7]=='O' && p[8]=='O' && p[9]=='O') || (p[1]=='O' && p[4]=='O' && p[7]=='O') || (p[2]=='O' && p[5]=='O' && p[8]=='O') || (p[3]=='O' && p[6]=='O' && p[9]=='O') || (p[1]=='O' && p[5]=='O' && p[9]=='O') || (p[3]=='O' && p[5]=='O' && p[7]=='O'))
    {
        printf("\nMachine won.");
        exit(0);
    }
    else if(i==8)
    {
        printf("\nDraw.");
        exit(0);
    }
    if(i%2==1)
    {
        i++;
        h_r(n, o, p); 
    }
    else if(i%2==0)
    {
        i++;
        m_r(n, o, p);
    }
}
void m_r(int q[9], int r[9], char s[10])
{
    int n, flag=0, i=0;
    srand(time(NULL));
    n=rand()%9+1;
    while(q[i]!=0)
    {
       if(q[i]==n)
       flag=1;
       i++;
    }
    if(flag==1)
    {
        q[i]=r[0];
        n=r[0];
    }
    else if(flag==0)
    q[i]=n;
    printf("\n\nMachine turn: %d", n);
    s[n]='O';
    shift(q, r, s);
}

