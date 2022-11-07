#include <bits/stdc++.h>

using namespace std;

int getMinNode(vector<vector<int>>& fares, int startNode) {
    int weight = 1e9;
    int node = -1;
    for (int i = 0; i <= fares.size(); i++) {
        if (fares[i][0] == startNode && fares[i][2] < weight) {
            weight = fares[i][2];
            node = fares[i][1];
        }
        else if (fares[i][1] == startNode && fares[i][2] < weight) {
            weight = fares[i][2];
            node = fares[i][1];
        }
    }
    return node;
}

void calculationNode(vector<vector<int>> fares, int node, map<int,bool>& visited, map<int,vector<int>>& each_route, map<int, int>& min_dist) {

}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 0;
    map<int, int> min_dist;
    map<int, vector<int>> each_route;
    map<int, bool> viisted;

    for(int i = 0; i < n; i++) {
        vector<int> tmp;
        min_dist.insert(pair<int, int>(i, 1e9));
        each_route.insert(pair<int, vector<int>>(i, tmp));
    }

    return answer;
}

int main()
{
    int n = 6;
    int s = 4;
    int a = 6;
    int b = 2;
    vector<vector<int>> fares = {
        {4, 1, 10}, 
        {3, 5, 24}, 
        {5, 6, 2}, 
        {3, 1, 41}, 
        {5, 1, 24}, 
        {4, 6, 50}, 
        {2, 4, 66}, 
        {2, 3, 22}, 
        {1, 6, 25}
    };
    cout << solution(n,s,a,b,fares) << endl;
}