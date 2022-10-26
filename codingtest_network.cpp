#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool isVisit(vector<int>& visited, int node) {
	for(size_t i = 0; i < visited.size(); i++) {
		if (visited[i] == node) {
			return true;
		}
	}
	return false;
}

int getIndex(vector<vector<int>> visit, int computers_number) {
    for(size_t i = 0; i < visit[computers_number].size(); i++) {
        if (visit[computers_number][i] == 1) {
            return i;
        }
    }
    return -1;
}

void getNetwork(vector<vector<int>>& visit, int index, vector<int>& networks) {

	networks.push_back(index);
	int get_index = getIndex(visit, index);
	while (true) {
		int get_index = getIndex(visit, index);
		if (get_index == -1) {
			break;
		}
		else {
			visit[index][get_index] = 0;
			visit[get_index][index] = 0;
			getNetwork(visit, get_index, networks);
		}
	}
}

void addVisited(vector<int>& visited, vector<int> nodes) {
	for(size_t i = 0; i < nodes.size(); i++) {
		visited.push_back(nodes[i]);
	}
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    size_t i,j;
    vector<vector<int>> visit;
	vector<int> visited;
	vector<int> networks;
    visit = computers;
    for(size_t i = 0; i < visit.size(); i++) {
        visit[i][i] = 0;
    }

	for(size_t i = 0; i < visit.size(); i++) {
		if (!isVisit(visited, i)) {
			getNetwork(visit,i,networks);
			addVisited(visited, networks);
			networks.clear();
			answer++;
		}
	}
    return answer;
}

int main () {

}
