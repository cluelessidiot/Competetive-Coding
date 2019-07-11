#include <bits/stdc++.h>
#define lli long long int
using namespace std;

lli n, tmp;
int idx[50];
int main(){
    lli ans = 0; cin >> n;
    for(int i=1; i<=n; ++i){
        cin >> tmp;
        for(int j=0; j<=3; ++j){
            lli pw = 1l << j;
            if(tmp & pw){
                ans += pw * i;
                idx[j] = i;
                 cout<<" "<<"E "<<ans<<" ";
            } else if(idx[j]){
                ans += pw * idx[j];
                cout<<" "<<"NE "<<ans<<" ";
            }
            
        }
        cout<<"\n";
    }
    cout << ans << endl;

    return 0;
}
