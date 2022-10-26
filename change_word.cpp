#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool isVisited(vector<string>& visited, string word) {
    for(size_t i = 0; i < visited.size(); i++) {
        if (visited[i] == word) {
            return true;
        }
    }
    return false;
}

bool isChangable(string target, string word, vector<string>& visited) {
    int count = 0;
    if (isVisited(visited, word)) {
        return false;
    }
    for (size_t i = 0; i < target.length(); i++) {
        if (target.at(i) == word.at(i)) {
            count++;
        }
    }
    if (count == (target.length() - 1))
        return true;
    return false;
}

bool dfs(string begin, string target, vector<string> words, vector<int>& dest, int count, vector<string> visited) {
    string tmp;
    if (begin == target) {
        dest.push_back(count);
        return true;
    }
    for(size_t i = 0; i < words.size(); i++) {
        if (isChangable(begin, words[i], visited)) {
            visited.push_back(words[i]);
            cout << begin << " -> " << words[i] << endl;
            tmp = begin;
            begin = words[i];
            count++;
            
            cout << count << endl << endl;
            if (dfs(begin, target, words, dest, count, visited) == false) {
                begin = tmp;
                count--;
            }
        }
    }
    return false;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    vector<int> dest;
    vector<string> visited;
    dfs(begin, target, words, dest, 0, visited);
    if (dest.size() == 0 )
        return 0;
    else {
        cout << *min_element(dest.begin(), dest.end()) << endl;
    }
    return *min_element(dest.begin(), dest.end());
}

int main () {
    string begin = "hit";
    string target = "cog";
    vector<string> words = { "hot", "dot", "dog", "lot", "log", "cog"};
    cout << solution(begin, target, words) << endl;
}
