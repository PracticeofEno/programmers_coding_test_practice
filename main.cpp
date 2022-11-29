#include <bits/stdc++.h>

using namespace std;

int getAnswer(int e, int start, vector<int> &arr)
{
    int index = -1;
    int max = -1;
    for (int i = start; i <= e; i++)
    {
        if (max < arr[i])
        {
            index = i;
            max = arr[i];
        }
    }
    return index;
}

vector<int> solution(int e, vector<int> starts)
{
    vector<int> answer;

    vector<int> arr2(100000001, 0);
    map<int, int> available;
    int answer_index = -1;
    int max = -1;

    for (int i = 1; i <= 100000000; i++)
    {
        if (i > e)
        {
            break;
        }
        available.insert(pair<int, int>(i, i));
    }
    while (available.size() > 0)
    {
        map<int, int>::iterator it;
        for (it = available.begin(); it != available.end(); it++)
        {
            arr2[it->second] = arr2[it->second] + 1;
            it->second = it->second + it->first;
            if (it->second > 5000000)
            {
                if (available.size() > 1)
                {
                    map<int, int>::iterator tmp = (--it);
                    it++;
                    available.erase(it);
                    it = tmp;
                }
                else
                {
                    available.erase(it);
                    break;
                }
            }
        }
    }

    for (int i = 0; i < starts.size(); i++)
    {
        int k = getAnswer(e, starts[i], arr2);
        answer.push_back(k);
    }
    return answer;
}

int main()
{
    int e = 8;
    vector<int> starts = {1, 3, 7};
    solution(e, starts);
    return 0;
}
