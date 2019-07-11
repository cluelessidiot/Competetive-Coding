#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int romans=0;
int persian=0;
int col_traverser(int ar[1000][1000] ,int r,int c,int n){
   if(ar[r][c]!=1 || c<0)
      return 0;
   if(r==n-1){
      romans= 1;
      return 1;}
    return col_traverser(ar,r+1,c,n) && col_traverser(ar,r+1,c-1,n) &&col_traverser(ar,r+1,c+1,n) ;


}
int row_traverser(int ar[1000][1000] ,int r,int c,int n){
   if(ar[r][c]!=2 || r<0)
      return 0;
   if(r==n-1){
        persian= 1;
      return 1;}
    return col_traverser(ar,r+1,c+1,n) && col_traverser(ar,r-1,c+1,n) &&col_traverser(ar,r,c+1,n) ;  


}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int m,n;
    cin>>n>>m;
    int ar[1000][1000];
    for (int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        if(i%2==0)
            ar[a][b]=1;
        else
            ar[a][b]=2;
    }
    for(int i=0;i<n;i++){
        int q=col_traverser(ar,0,i,n);
    }
    for(int i=0;i<n;i++){
        int q=row_traverser(ar,i,0,n);
    }
    if(romans==1)
       cout<<"ROMANS";
    else if(persian==1)
       cout<<"PERSIANS";
    else
    {
         cout<<"NIETHER";
    }
          
    return 0;
}

