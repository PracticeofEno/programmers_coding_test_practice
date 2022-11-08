#include <bits/stdc++.h>

using namespace std;

bool checkCondition(vector<vector<int>> &board, vector<int> data, map<vector<int>, vector<int>> &min_fares, queue<vector<int>> &q, int state)
{
    if (data[0] == 0 && data[1] == 0)
        return false;
    // x,y인덱스가 안벗어나면서
    if ((data[0] >= 0 && data[0] < board.size()) && (data[1] >= 0 && data[1] < board.size()))
    {
        // 다음에 연결해야될 좌표가 연결가능하다면
        if (board[data[1]][data[0]] == 0)
        {
            if (state != data[2])
                data[3] = data[3] + 600;
            else
                data[3] = data[3] + 100;

            vector<int> tmp = {data[0], data[1]};
            vector<int> tmp2 = min_fares.find(tmp)->second;
            if (data[3] <= tmp2[state])
            {
                min_fares.find(tmp)->second[state] = data[3];
                data[2] = state;
                q.push(data);
                return true;
            }
        }
        return true;
    }
    return false;
}

int solution(vector<vector<int>> board)
{
    vector<int> answer;
    queue<vector<int>> q;
    map<vector<int>, vector<int>> min_fares;
    map<vector<int>, int> min_state;

    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board.size(); j++)
        {
            vector<int> tmp;
            tmp.push_back(j);
            tmp.push_back(i);
            vector<int> tmp2;
            tmp2.push_back(1e9);
            tmp2.push_back(1e9);
            min_fares[tmp] = tmp2;
        }
    }
    vector<int> start = {0, 0, 0, 0};
    vector<int> start2 = {0, 0, 1, 0};
    q.push(start);
    q.push(start2);
    vector<int> aa;
    aa.push_back(0);
    aa.push_back(0);
    min_fares[aa] = aa;

    while (q.size() != 0)
    {
        vector<int> tmp = q.front();
        int tmp_x = tmp[0];
        int tmp_y = tmp[1];
        int state = tmp[2];
        int fare = tmp[3];
        tmp.clear();

        if (tmp_x == board.size() - 1 && tmp_y == board.size() - 1)
        {
            q.pop();
            continue;
        }

        tmp.push_back(tmp_x + 1);
        tmp.push_back(tmp_y);
        tmp.push_back(state);
        tmp.push_back(fare);
        checkCondition(board, tmp, min_fares, q, 0);
        tmp.clear();

        tmp.push_back(tmp_x - 1);
        tmp.push_back(tmp_y);
        tmp.push_back(state);
        tmp.push_back(fare);
        checkCondition(board, tmp, min_fares, q, 0);
        tmp.clear();

        tmp.push_back(tmp_x);
        tmp.push_back(tmp_y + 1);
        tmp.push_back(state);
        tmp.push_back(fare);
        checkCondition(board, tmp, min_fares, q, 1);
        tmp.clear();

        tmp.push_back(tmp_x);
        tmp.push_back(tmp_y - 1);
        tmp.push_back(state);
        tmp.push_back(fare);
        checkCondition(board, tmp, min_fares, q, 1);
        tmp.clear();

        q.pop();
    }

    vector<int> haha;
    haha.push_back(board.size() - 1);
    haha.push_back(board.size() - 1);
    vector<int> haha2 = min_fares.find(haha)->second;
    if (haha2[0] < haha2[1])
        return haha2[0];
    else
        return haha2[1];
}

int main()
{
    vector<vector<int>> board2 = {
        {0, 0, 0, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 1, 0, 0},
        {1, 0, 0, 0, 1},
        {0, 1, 1, 0, 0}};
    cout << solution(board2) << endl;
}
