#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    vector <int> ar={100, 180, 260, 310, 40, 535, 695};//{20,30,40,5,20,80};
    //vector<int,int> maxMin;
    int i=0;
    for( i=0;i<ar.size();i++){
        int local_min=0;
        int local_max=0;
        int flag=0;
       // cout<<"Gf";
        while(i!=ar.size()){
            if(ar[i]<ar[i+1]){
                cout<<"{"<<i<<"}";
                local_min=ar[i];
                i++;
                break;}
                i++;

            }
        while(i<ar.size()){
            if(i==ar.size()-1){
                local_max=ar[i];
                break;
            }
            if(ar[i]>ar[i+1]){
                cout<<"["<<i<<"]";
                local_max=ar[i];
                break;}
                i++;
        
            }

        cout<<local_min<<"D"<<local_max<<"\n";


        }
    }