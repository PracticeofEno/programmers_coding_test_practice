#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void printVector(vector<string> tmp)
{
    for (int i = 0; i < tmp.size(); i++)
    {
        cout << tmp[i] << " ";
    }
    cout << endl;
}

bool dfs(vector<string> gems, vector<string>& gems_name, vector<string> selected_list, int start) {
    if (gems_name.size() == selected_list.size()) 
        return true;
    
    return false;
}

vector<int> solution(vector<string> gems)
{
    vector<int> answer;
    vector<string> gems_name = gems;
    vector<string> selected_list;
    vector<int>
    sort(gems_name.begin(), gems_name.end());
    gems_name.erase(unique(gems_name.begin(), gems_name.end()), gems_name.end());
    for (int i = 0; i < gems.size() - gems_name.size(); i++) {
        dfs(gems, gems_name, selected_list, i);
        gems.erase(gems.begin());
        i--;
    } 
}

int main()
{
    vector<string> gems = {"DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA"};
    solution(gems);
}
