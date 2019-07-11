#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);
int generator(unordered_map<int,int> &arrayMap,int x,int change){
    int bel=arrayMap.count(x-1)?arrayMap[x-1]:0;
    int curr=arrayMap.count(x)?arrayMap[x]:0;
    int up=arrayMap.count(x+1)?arrayMap[x+1]:0;
    //cout<<"["<<bel<<","<<curr<<","<<up<<"]";
    int beautyBeforeChange=0;
    int beautyAfterChange=0;

    beautyBeforeChange+=max(0,curr-bel);
    beautyBeforeChange+=max(0,up-curr);
    curr+=change;
    beautyAfterChange+=max(0,curr-bel);
    beautyAfterChange+=max(0,up-curr);
    arrayMap[x]=curr;
    return beautyAfterChange-beautyBeforeChange;
}
// Complete the arrayAndQueries function below.
int arrayAndQueries(vector<int> A, vector<vector<int>> queries) {
    unordered_map<int,int> arrayMap;
    int beautyCount=0;
    for(int x:A){
        beautyCount+=generator(arrayMap,x,1);
      //  cout<<beautyCount<<" b";
    }
    int sum=0;
    for(int i=0;i<queries.size();i++){
        int index=queries[i][0]-1;
        int newVal=queries[i][1];
        int oldVal=A[index];
        beautyCount+=generator(arrayMap,oldVal,-1);
        A[index]=newVal;
        beautyCount+=generator(arrayMap,newVal,1);
        //cout<<beautyCount<<"  ";
        sum+=beautyCount*(i+1);
    }
//cout<<sum;
return sum;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string A_temp_temp;
    getline(cin, A_temp_temp);

    vector<string> A_temp = split_string(A_temp_temp);

    vector<int> A(n);

    for (int i = 0; i < n; i++) {
        int A_item = stoi(A_temp[i]);

        A[i] = A_item;
    }

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> queries(q);
    for (int i = 0; i < q; i++) {
        queries[i].resize(2);

        for (int j = 0; j < 2; j++) {
            cin >> queries[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = arrayAndQueries(A, queries);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}

