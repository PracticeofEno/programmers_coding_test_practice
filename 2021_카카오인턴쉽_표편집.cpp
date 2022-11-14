#include <bits/stdc++.h>

using namespace std;

vector<string> split(string str, char Delimiter)
{
    istringstream iss(str); // istringstream에 str을 담는다.
    string buffer;          // 구분자를 기준으로 절삭된 문자열이 담겨지는 버퍼

    vector<string> result;

    // istringstream은 istream을 상속받으므로 getline을 사용할 수 있다.
    while (getline(iss, buffer, Delimiter))
    {
        result.push_back(buffer); // 절삭된 문자열을 vector에 저장
    }
    return result;
}

string solution(int n, int k, vector<string> cmd)
{
    stack<int> st; // 삭제된 행
    vector<int> prev;
    vector<int> next;

    for (int i = 0; i < n + 2; i++)
    {
        prev.push_back(i - 1);
        next.push_back(i + 1);
    }
    k++;

    for (int i = 0; i < cmd.size(); i++)
    {
        string command;
        int number;
        if (cmd[i].find("D") != string::npos || cmd[i].find("U") != string::npos)
        {
            vector<string> tmp = split(cmd[i], ' ');
            command = tmp[0];
            number = stoi(tmp[1]);
        }
        else if (cmd[i].find("C") != string::npos || cmd[i].find("Z") != string::npos)
        {
            command = cmd[i];
            number = 0;
        }

        if (command == "U")
        {
            for (int j = 0; j < number; j++)
            {
                k = prev[k];
            }
        }
        else if (command == "D")
        {
            for (int j = 0; j < number; j++)
            {
                k = next[k];
            }
        }
        else if (command == "C")
        {
            st.push(k);
            next[prev[k]] = next[k];
            prev[next[k]] = prev[k];

            if (next[k] == n + 1)
                k = prev[k];
            else
                k = next[k];
        }
        else if (cmd[i][0] == 'Z')
        {
            int r = st.top();
            next[prev[r]] = r;
            prev[next[r]] = r;
            st.pop();
        }
    }

    string answer;
    answer.append(n, 'O');

    while (!st.empty())
    {
        answer[st.top() - 1] = 'X';
        st.pop();
    }

    return answer;
}

int main()
{
    int n = 8;
    int k = 2;
    vector<string> cmd = {"D 2","C","U 3","C","D 4","C","U 2","Z","Z"};
    cout << solution(n, k, cmd) << endl;
}
