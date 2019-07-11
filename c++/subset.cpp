  #include<bits/stdc++.h>
  using namespace std;

    void subsets(int S[], int n) {
         int nSub = 1<<n;
         cout<<(1<<0); 
         for(int i=1; i<nSub; i++){
         	  cout<<"{ ";
              for(int k=0; k<n; k++){
                   //if the k-th bit is set
                   if( (1<<k) & i){
                        cout<<S[k]<<" ";
                   } 
              }
              cout<<"}\n";
         }
    }
    int main(){
        int s[5]={1,2,3,4,5};
        subsets(s,5);
        return 0;
    }