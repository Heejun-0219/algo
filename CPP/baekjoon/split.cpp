#include <bits/stdc++.h>

using namespace std;

vector<string> split(string query, string demlimeter){
    vector<string> answer;
    long long pos = 0;
    string token = "";
    while ((pos = query.find(demlimeter)) != string::npos)
    {
        token = query.substr(0, pos);
        answer.push_back(token);
        query.erase(0, pos + demlimeter.length());
    }
    answer.push_back(query);
    return answer;    
}

int input_value(string &query, string &demlimeter){
    try
    {
        cout << "input query : ";
        getline(cin, query);

        if (query.empty()) {
            return 1;
        }

        cout << "input demlimeter : ";
        getline(cin, demlimeter);

        return 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return 1;
    }
}

int controller(){
    try
    {
        string query = "";
        string demlimeter = "";

        while (true) {
            if (input_value(query, demlimeter) == 1) {
                return 0;
            }

            vector<string> answer = split(query, demlimeter);
            for (string word : answer) {
                cout << word << '\n';
            }

            query.clear();
            demlimeter.clear();
        }

        return 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return 1;
    }   
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    return controller();
}