#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);
bool myfunct(vector<int> a,vector<int> b){
    return a[0]<b[0];
}
bool myfunct2(vector<int> a,vector<int> b){
    return a[1]<b[1];
}
// Complete the solve function below.
string solve(vector<vector<int>> grid) {
//sort(grid.begin(),grid.end(),myfunct);
int k=grid.size();
int batch=k/5;
int w=0;
while(batch!=0){
    vector <vector<int>> temp(grid.begin()+w*5,grid.begin()+w*5+5);
    vector <vector<int>> temp2(grid.begin()+w*5,grid.begin()+w*5+5);
        sort(temp.begin(),temp.end(),myfunct);
        sort(temp2.begin(),temp2.end(),myfunct2);
    cout<<"\n";
    //
    if(temp[1][0]==temp[2][0] && temp[2][0]==temp[3][0] && temp[3][0]+1==temp[4][0] && temp[0][0]+1==temp[1][0]){
        if((temp2[0][1]==temp2[1][1] && temp2[1][1]==temp2[2][1]) || (temp2[2][1]==temp2[3][1] && temp2[3][1]==temp2[4][1]))
         // cout<<"yes";//
         return "YES";
    }
    if(temp2[1][1]==temp2[2][1] && temp2[2][1]==temp2[3][1] && temp2[0][1]+1==temp2[1][1] && temp2[3][1]+1==temp2[4][1]){
        if((temp[0][0]==temp[1][0] && temp[1][0]==temp[2][0]) || (temp[2][0]==temp[3][0] && temp[3][0]==temp[4][0]))
         // cout<<"yes";//
         return "YES";
    }
    for(int i=0;i<temp.size();i++){
    cout<<temp2[i][1]<<" ";
}
//cout<<batch;
    batch--;
    w++;
}


}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        vector<vector<int>> points(5);

        for (int i = 0; i < 5; i++) {
            points[i].resize(2);

            string points_row_temp_temp;
            getline(cin, points_row_temp_temp);

            vector<string> points_row_temp = split(rtrim(points_row_temp_temp));

            for (int j = 0; j < 2; j++) {
                int points_row_item = stoi(points_row_temp[j]);

                points[i][j] = points_row_item;
            }
        }

        string result = solve(points);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
