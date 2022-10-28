#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer(2);
    
    vector<string> types = gems;
    sort(types.begin(), types.end());
    types.erase(unique(types.begin(), types.end()), types.end());
    
    queue<string> q;
    set<string> s;
    map<string, int> count;
    int left = 0;
    int right = 0;
    int len = 1e9;
    
    while(right < gems.size()) {
        q.push(gems[right]);
        s.insert(gems[right]);
        count[gems[right]]++;

        while (s.size() == types.size()) {
            if (right - left < len) {
                len = right - left;
                answer[0] = left + 1;
                answer[1] = right + 1;
            }
            count[q.front()]--;
            if (count[q.front()] == 0) {
                s.erase(q.front());
            }
            q.pop();
            left++;
        }
        right++;
    }
    return answer;
}

int main()
{
    vector<string> gems2 = {"DIA", "RUBY", "RUBY", "DIA", "EMERALD", "SAPPHIRE", "DIA"};
    solution(gems2);
    // vector<string> gems = {"AA", "AB", "AC", "AA", "AC"};
    // solution(gems);
}
