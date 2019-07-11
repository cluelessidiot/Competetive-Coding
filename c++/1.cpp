	#include <bits/stdc++.h>
using namespace std;


int subarr(vector<long int> vect,long int S,long int N ){
  if(accumulate(vect.begin(),vect.end(),0)<S){
    //cout<<accumulate(vect.begin(),vect.end(),0);
    cout<<-1;
    return 0;
     
  }
 
  for(int j=0;j<N;j++){
    long int sum=0;
    for(int i=j;i<N;i++)
      {
        sum+=vect[i];
        //cout<<sum<<" ";
        if(sum==S){
          cout<<j+1<<" "<<i+1;
          return 0;
        }
        if(sum>S)
          break;
       

      }
     
  }
  cout<<"3-1";
  return 0;
}

int main() {
    //code
    long int  N;
    long int T,S;
   
    cin>>T;
  for(int i=0;i<T;i++){
    cin>>N>>S;
      long int A[N];
      for(int i=0;i<N;i++)
        cin>>A[i];
 
      vector<long int> vect(A,A+N);

  
    //sort(vect.begin(),vect.end());
    subarr(vect,S,N);
    if(i!=T-1)
      cout<<endl;
  }
    return 0;
}
