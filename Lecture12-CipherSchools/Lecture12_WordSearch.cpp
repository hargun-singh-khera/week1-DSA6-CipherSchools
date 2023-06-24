#include<bits/stdc++.h>
using namespace std;

bool exist(vector<vector<char>>& b, string w) 
{
    int m=b.size(),n=b[0].size();
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            if(b[i][j]==w[0])       
                if(find(b,w,i,j,0)) return true;
    return false;    
}
bool find(vector<vector<char>> &b, string w, int i, int j, int x)
{
    if(x==w.size())        return true;
    if(i<0 || i>=b.size() || j<0 || j>=b[0].size())   return false;
    if(b[i][j]!=w[x] || b[i][j]=='-1')      return false;
    else{
        b[i][j]='-1';
        if(find(b,w,i+1,j,x+1) || find(b,w,i,j+1,x+1) || find(b,w,i-1,j,x+1) || find(b,w,i,j-1,x+1))            
            return true;;
        b[i][j]=w[x];
        return false;
    }
}