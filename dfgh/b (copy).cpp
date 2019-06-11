#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'productName' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING_ARRAY names as parameter.
 */
string productName(vector<string> names) {
    //cout<<"e";
   // int a[25]={0};
    for(int q=0;q<5;q++){
    int a[26]={0};
    for (vector<string>::iterator i=names.begin() ;i!=names.end();++i){
      // cout<<"-"<<(*i)[q]-97;
       a[(*i)[q]-97]++;
    }
    int o=25;
    while(a[o]!= 0)
    {  // cout<<o<<" "<<a[o]<<"} ";
        o--;
    }
  //  cout<<"\n";
    names[0][q]=o+97;
    }
    int p=0;
    string al;
    while(p<=4){
      //  cout<<names[0][p];
        al.push_back(names[0][p]);
        p++;
    }
    //names[0].reverse();
    cout<<names[0];
    return al;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<string> names(n);

    for (int i = 0; i < n; i++) {
        string names_item;
        getline(cin, names_item);

        names[i] = names_item;
    }

    string result = productName(names);

    fout << result << "\n";

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

