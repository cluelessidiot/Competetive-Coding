#include<bits/stdc++.h>
using namespace std;
void subsetGener(vector <int> a,vector<int> q,int index,int s){
//cout<<index<<":"<<"P"<<s;
  if(s==0 ){
      cout<<"{";
      for(int j=0;j<q.size();j++){
                cout<<q[j]<<" ";
      }
      cout<<"}\n";
      return ;
  }
  for(int i=index;i<a.size();i++){
      q.push_back(a[i]);
  //    cout<<a[i]<<a.size();
      subsetGener(a,q,i+1,s-1);
      q.pop_back();
  }
  return;
}
int main(){
    vector<int> a={1,2};
  vector<int> q;
    subsetGener(a,q,0,1);
}