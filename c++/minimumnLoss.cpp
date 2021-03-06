#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);
bool compare(pair <long long,long long>&a,pair<long long,long long>&b ){
    return (a.first<b.first);
    
        
}
// Complete the minimumLoss function below.
int minimumLoss(vector<long> price) {
    vector<pair <long long int,long long int>> q;
    for (int i=0;i<price.size();i++){
      q.push_back(make_pair(price[i],i));
  }
  sort(q.begin(),q.end(),compare);
    long long minsum=9876543211111;
    for(int i=0;i<q.size()-1;i++){
        if(q[i+1].second<q[i].second && q[i+1].first-q[i].first>=0 && q[i+1].first-q[i].first<minsum)
            minsum=q[i+1].first-q[i].first;
       // cout<<"|"<<q[i].second;
    }
    return minsum;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string price_temp_temp;
    getline(cin, price_temp_temp);

    vector<string> price_temp = split_string(price_temp_temp);

    vector<long> price(n);

    for (int i = 0; i < n; i++) {
        long price_item = stol(price_temp[i]);

        price[i] = price_item;
    }

    int result = minimumLoss(price);

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
