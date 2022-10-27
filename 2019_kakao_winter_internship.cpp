#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool isMatch(string user_id, string banned_id)
{
    if (user_id.length() != banned_id.length())
        return false;

    for (size_t i = 0; i < banned_id.length(); i++)
    {
        if (banned_id.at(i) == '*')
        {
            continue;
        }
        else if (banned_id.at(i) != user_id.at(i))
        {
            return false;
        }
    }
    return true;
}

void addMatchList(vector<vector<string>> &match_list, vector<string> match)
{
    bool tf = true;
    int count = 0;
    for (int i = 0; i < match_list.size(); i++)
    {
        vector<string> tmp = match_list[i];
        for (int j = 0; j < tmp.size(); j++)
        {
            if (tmp.at(j) == match.at(j))
            {
                count++;
            }
        }
        if (count == match.size())
        {
            tf = false;
        }
        count = 0;
    }
    if (tf)
    {
        match_list.push_back(match);
    }
}

bool dfs(vector<string> user_id, vector<string> banned_id, vector<vector<string>> &match_list, vector<string> match)
{
    if (banned_id.size() == 0)
    {
        sort(match.begin(), match.end());
        addMatchList(match_list, match);
        return false;
    }
    vector<string> tmp = user_id;
    vector<string> tmp2 = banned_id;

    for (int i = 0; i < user_id.size(); i++)
    {
        if (isMatch(user_id.at(i), banned_id.at(0)))
        {
            match.push_back(user_id.at(i));
            user_id.erase(user_id.begin() + i);
            banned_id.erase(banned_id.begin());
            dfs(user_id, banned_id, match_list, match);
            user_id = tmp;
            banned_id = tmp2;
            match.pop_back();
        }
    }

    return false;
}

int solution(vector<string> user_id, vector<string> banned_id)
{
    int answer = 0;
    vector<vector<string>> match_list;
    vector<string> match;
    dfs(user_id, banned_id, match_list, match);

    return match_list.size();
}