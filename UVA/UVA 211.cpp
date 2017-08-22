#include<bits/stdc++.h>
using namespace std;
int arr[10][10], T, soln;
int vis[10][10] ;
int t[10][10];
void go(int cnt)
{
    if(cnt == 28)
    {
        soln++;
        for(int i = 1 ; i <= 7 ; i++ )
        {
            for(int j = 1 ; j <= 8 ; j++)
            {
                cout << setw(4) << t[i][j] ;
            }
            cout << "\n";
        }
        cout << "\n\n";
        return ;
    }
    int sx = -1, sy = -1 ;
    for(int i = 1 ; i <= 7 && sx+sy < 0 ; i++)
    {
        for(int j = 1 ; j <= 8 && sx+sy < 0; j++)
        {
            if(arr[i][j] != -1)
            {
                sx = i, sy = j;
            }
        }
    }
    int x, y, mx, my;
    x = arr[sx][sy], y = arr[sx+1][sy];
    mx = min(x,y);
    my = max(x,y);
    if(mx != -1 && vis[mx][my] > 0)
    {
        int idx = vis[mx][my];
        vis[mx][my] *=-1;
        arr[sx][sy] = -1;
        arr[sx+1][sy] = -1;
        t[sx][sy] = t[sx+1][sy] = idx;
        go(cnt+1);
        t[sx][sy] = t[sx+1][sy] = 0;
        vis[mx][my] *=-1;
        arr[sx][sy] = x;
        arr[sx+1][sy] = y;
    }
    x = arr[sx][sy], y = arr[sx][sy+1];
    mx = min(x,y);
    my = max(x,y);
    if(mx != -1 && vis[mx][my] > 0)
    {
        int idx = vis[mx][my];
        vis[mx][my] *=-1;
        arr[sx][sy] = -1;
        arr[sx][sy+1] = -1;
        t[sx][sy] = t[sx][sy+1] = idx;
        go(cnt+1);
        t[sx][sy] = t[sx][sy+1] = 0;
        vis[mx][my] *=-1;
        arr[sx][sy] = x;
        arr[sx][sy+1] = y;
    }
}
int main()
{
    int f = 1;
    for(int i = 0 ; i <= 6 ; i++)
        for(int j = i ; j <= 6 ; j++) vis[i][j] = f++;
    for(int i = 0 ; i < 10 ; i++)
        for(int j = 0 ; j <10 ; j++) arr[i][j] = -1;
    while(cin >> arr[1][1])
    {
        if(T) cout << "\n\n\n\n\n" ;
        soln = 0;
        T++;
        for(int j = 2 ; j <= 8 ; j++) cin >> arr[1][j];
        for(int i = 2 ; i <= 7 ; i++)
            for(int j = 1 ; j <= 8 ; j++) cin >> arr[i][j];
        cout << "Layout #" << T << ":\n\n\n";
        for(int i = 1 ; i <= 7 ; i++ )
        {
            for(int j = 1 ; j <= 8 ; j++)
            {
                cout << setw(4) << arr[i][j] ;
            }
            cout << "\n";
        }
        cout << "\n";
        cout << "Maps resulting from layout #" << T<< " are:\n\n\n";
        go(0);
        cout << "There are " << soln << " solution(s) for layout #" << T << ".\n";
        for(int i = 0 ; i < 10 ; i++)
            for(int j = 0 ; j <10 ; j++) arr[i][j] = -1;
    }
}
