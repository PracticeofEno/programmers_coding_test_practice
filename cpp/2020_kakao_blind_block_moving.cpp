#include <bits/stdc++.h>

using namespace std;

int getState(const vector<vector<int>> &current)
{
    if (current[0][0] == current[1][0])
        return 0;
    return 1;
}

void addQueue(const vector<vector<int>> &current, map<vector<vector<int>>, int> &visited, queue<vector<vector<int>>> &q, int count)
{
    map<vector<vector<int>>, int>::iterator it = visited.find(current);
    if (it == visited.end())
    {
        visited.insert(std::pair<vector<vector<int>>, int>(current, count));
        q.push(current);
    }
    else
    {
        if (it->second > count)
        {
            it->second = count;
            q.push(current);
        }
    }
}

void checkMoveRight(const vector<vector<int>> &board, const vector<vector<int>> &current, queue<vector<vector<int>>> &q, map<vector<vector<int>>, int> &visited, int count)
{
    int size = board.size();
    int state = getState(current);
    // 가로 0 세로 1          0,0, 0, 1      0, 5
    if (state == 0)
    {
        if (current[1][1] + 1 < board.size() && board[current[1][0]][current[1][1] + 1] != 1)
        {
            vector<vector<int>> tmp = current;
            tmp[0][1] = current[0][1] + 1;
            tmp[1][1] = current[1][1] + 1;
            addQueue(tmp, visited, q, count);
        }
    }
    else if (state == 1)
    {
        if (current[1][1] + 1 < board.size())
        {
            if (board[current[0][0]][current[0][1] + 1] != 1 && board[current[1][0]][current[1][1] + 1] != 1)
            {
                vector<vector<int>> tmp = current;
                tmp[0][1] = current[0][1] + 1;
                tmp[1][1] = current[1][1] + 1;
                addQueue(tmp, visited, q, count);
            }
        }
    }
}

void checkMoveDown(const vector<vector<int>> &board, const vector<vector<int>> &current, queue<vector<vector<int>>> &q, map<vector<vector<int>>, int> &visited, int count)
{
    int size = board.size();
    int state = getState(current);
    // 가로 0 세로 1          0,0, 0, 1      0, 5
    if (state == 0)
    {
        if (current[0][0] + 1 < size)
        {
            if (board[current[0][0] + 1][current[0][1]] != 1 && board[current[1][0] + 1][current[1][1]] != 1)
            {
                vector<vector<int>> tmp = current;
                tmp[0][0] = current[0][0] + 1;
                tmp[1][0] = current[1][0] + 1;
                addQueue(tmp, visited, q, count);
            }
        }
    }
    else if (state == 1)
    {
        if (current[1][0] + 1 < size)
        {
            if (board[current[1][0] + 1][current[1][1]] != 1)
            {
                vector<vector<int>> tmp = current;
                tmp[0][0] = current[0][0] + 1;
                tmp[1][0] = current[1][0] + 1;
                addQueue(tmp, visited, q, count);
            }
        }
    }
}

void checkMoveLeft(const vector<vector<int>> &board, const vector<vector<int>> &current, queue<vector<vector<int>>> &q, map<vector<vector<int>>, int> &visited, int count)
{
    int size = board.size();
    int state = getState(current);
    // 가로 0 세로 1          0,0, 0, 1      0, 5
    if (state == 0)
    {
        if (current[0][1] - 1 >= 0)
        {
            if (board[current[0][0]][current[0][1] - 1] != 1)
            {
                vector<vector<int>> tmp = current;
                tmp[0][1] = current[0][1] - 1;
                tmp[1][1] = current[1][1] - 1;
                addQueue(tmp, visited, q, count);
            }
        }
    }
    else if (state == 1)
    {
        if (current[0][1] - 1 >= 0)
        {
            if (board[current[0][0]][current[0][1] - 1] != 1 && board[current[1][0]][current[1][1] - 1] != 1)
            {
                vector<vector<int>> tmp = current;
                tmp[0][1] = current[0][1] - 1;
                tmp[1][1] = current[1][1] - 1;
                addQueue(tmp, visited, q, count);
            }
        }
    }
}

void checkMoveUp(const vector<vector<int>> &board, const vector<vector<int>> &current, queue<vector<vector<int>>> &q, map<vector<vector<int>>, int> &visited, int count)
{
    int size = board.size();
    int state = getState(current);
    // 가로 0 세로 1          0,0, 0, 1      0, 5
    if (state == 0)
    {
        if (current[0][0] - 1 >= 0)
        {
            if (board[current[0][0] - 1][current[0][1]] != 1 && board[current[1][0] - 1][current[1][1]] != 1)
            {
                vector<vector<int>> tmp = current;
                tmp[0][0] = current[0][0] - 1;
                tmp[1][0] = current[1][0] - 1;
                addQueue(tmp, visited, q, count);
            }
        }
    }
    else if (state == 1)
    {
        if (current[0][0] - 1 >= 0)
        {
            if (board[current[0][0] - 1][current[0][1]] != 1)
            {
                vector<vector<int>> tmp = current;
                tmp[0][0] = current[0][0] - 1;
                tmp[1][0] = current[1][0] - 1;
                addQueue(tmp, visited, q, count);
            }
        }
    }
}

void checkRotateVertical(const vector<vector<int>> &board, const vector<vector<int>> &current, int direction, queue<vector<vector<int>>> &q, map<vector<vector<int>>, int> &visited, int count)
{
    // direction은  0은 좌측 기준
    if (direction == 0)
    {
        // 좌측 기준으로 위로 회전할수 있는가? ㅣ 모양
        if (current[0][0] - 1 >= 0)
        {
            if (board[current[0][0] - 1][current[0][1]] != 1 && board[current[1][0] - 1][current[1][1]] != 1)
            {
                vector<vector<int>> tmp = current;
                tmp[0][0] = current[0][0] - 1;
                tmp[1][1] = current[0][1];
                addQueue(tmp, visited, q, count);
            }
        }
        // 좌측 기준으로 밑으로 회전할 수 있는가?
        if (current[0][0] + 1 < board.size())
        {
            if (board[current[0][0] + 1][current[0][1]] != 1 && board[current[1][0] + 1][current[1][1]] != 1)
            {
                vector<vector<int>> tmp = current;
                tmp[1][0] = current[0][0] + 1;
                tmp[1][1] = current[0][1];
                addQueue(tmp, visited, q, count);
            }
        }
    }
    // 1은 우측 기준
    else if (direction == 1)
    {
        // 우측 기준으로 위로 회전할수 있는가? ㅣ 모양
        if (current[1][0] - 1 >= 0)
        {
            if (board[current[1][0] - 1][current[1][1]] != 1 && board[current[0][0] - 1][current[0][1]] != 1)
            {
                vector<vector<int>> tmp = current;
                tmp[0][0] = current[1][0] - 1;
                tmp[0][1] = current[1][1];
                addQueue(tmp, visited, q, count);
            }
        }
        // 우측 기준으로 밑으로 회전할 수 있는가?
        if (current[1][0] + 1 < board.size())
        {
            if (board[current[1][0] + 1][current[1][1]] != 1 && board[current[0][0] + 1][current[0][1]] != 1)
            {
                vector<vector<int>> tmp = current;
                tmp[0][1] = current[1][1];
                tmp[1][0] = current[1][0] + 1;
                addQueue(tmp, visited, q, count);
            }
        }
    }
}

// 0 x 1 y 2 x 3 y
void checkRotateHorizental(const vector<vector<int>> &board, const vector<vector<int>> &current, int direction, queue<vector<vector<int>>> &q, map<vector<vector<int>>, int> &visited, int count)
{
    // direction은  0은 윗측 기준
    if (direction == 0)
    {
        // 윗측 기준으로 우회전할수 있는가? ㅡ 모양
        if (current[0][1] + 1 < board.size())
        {
            if (board[current[0][0]][current[0][1] + 1] != 1 && board[current[1][0]][current[1][1] + 1] != 1)
            {
                vector<vector<int>> tmp = current;
                tmp[1][0] = current[0][0];
                tmp[1][1] = current[0][1] + 1;
                addQueue(tmp, visited, q, count);
            }
        }
        // 윗측 기준으로 좌회전할 수 있는가?
        if (current[0][1] - 1 >= 0)
        {
            if (board[current[0][0]][current[0][1] - 1] != 1 && board[current[1][0]][current[1][1] - 1] != 1)
            {
                vector<vector<int>> tmp = current;
                tmp[0][1] = current[0][1] - 1;
                tmp[1][0] = current[1][0] - 1;
                addQueue(tmp, visited, q, count);
            }
        }
    }
    // 1은 밑측 기준
    else if (direction == 1)
    {
        // 밑측 기준으로 우회전할수 있는가? ㅡ 모양
        if (current[1][1] + 1 < board.size())
        {
            if (board[current[0][0]][current[0][1] + 1] != 1 && board[current[1][0]][current[1][1] + 1] != 1)
            {
                vector<vector<int>> tmp = current;
                tmp[0][0] = current[0][0] + 1;
                tmp[1][1] = current[1][1] + 1;
                addQueue(tmp, visited, q, count);
            }
        }
        // 밑측 기준으로 좌회전할 수 있는가? <--여기부터
        if (current[1][1] - 1 >= 0)
        {
            if (board[current[0][0]][current[0][1] - 1] != 1 && board[current[1][0]][current[1][1] - 1] != 1)
            {
                vector<vector<int>> tmp = current;
                tmp[0][0] = current[0][0] + 1;
                tmp[0][1] = current[1][1] - 1;
                addQueue(tmp, visited, q, count);
            }
        }
    }
}

void BFS(const vector<vector<int>> &board, const vector<vector<int>> &current, queue<vector<vector<int>>> &q, map<vector<vector<int>>, int> &visited, int count)
{
    checkMoveUp(board, current, q, visited, count);
    checkMoveDown(board, current, q, visited, count);
    checkMoveLeft(board, current, q, visited, count);
    checkMoveRight(board, current, q, visited, count);
    int state = getState(current);
    if (state == 0)
    {
        checkRotateVertical(board, current, 0, q, visited, count);
        checkRotateVertical(board, current, 1, q, visited, count);
    }
    else if (state == 1)
    {
        checkRotateHorizental(board, current, 0, q, visited, count);
        checkRotateHorizental(board, current, 1, q, visited, count);
    }
}

int solution(vector<vector<int>> board)
{
    vector<int> answer;
    map<vector<vector<int>>, int> visited;
    queue<vector<vector<int>>> q;
    vector<int> x = {0, 0};
    vector<int> y = {0, 1};
    vector<vector<int>> current;
    current.push_back(x);
    current.push_back(y);
    visited.insert(std::pair<vector<vector<int>>, int>(current, 0));
    int state = 0;

    q.push(current);
    while (q.size() != 0)
    {
        vector<vector<int>> tmp = q.front();
        if ((tmp[0][0] == board.size() - 1 && tmp[0][1] == board.size() - 1) || (tmp[1][0] == board.size() -1 && tmp[1][1] == board.size() - 1)) {
            answer.push_back(visited.find(tmp)->second);
        }
        int count = 0;
        if (visited.find(tmp) != visited.end())
        {
            count = visited.find(tmp)->second;
            count++;
        }
        else
            count = 0;
        
        BFS(board, tmp, q, visited, count);
        q.pop();
    }
    int k = 5;
    return *min_element(answer.begin(), answer.end());
}

int main()
{
    vector<vector<int>> board = {
        {0, 0, 0, 1, 1},
        {0, 0, 0, 1, 0},
        {0, 1, 0, 1, 1},
        {1, 1, 0, 0, 1},
        {0, 0, 0, 0, 0}};
    cout << solution(board) << endl;
}