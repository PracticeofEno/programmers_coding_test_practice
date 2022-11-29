#include <bits/stdc++.h>

using namespace std;

bool cmp(vector<int> &a, vector<int> &b)
{
    if (a[1] == b[1])
        return a[0] < b[0];
    return a[1] > b[1];
}

vector<int> solution(int e, vector<int> starts)
{
    vector<int> answer;

    vector<vector<int>> arr2;
    map<int, int> available;
    int answer_index = -1;
    int max = -1;

    for (int i = 0; i <= e; i++)
    {
        vector<int> tmp;
        tmp.push_back(i);
        tmp.push_back(0);
        arr2.push_back(tmp);
    }
    for (int i = 2; i <= e; i++)
    {
        int count = 0;
        for(int j = 1 ; j <= sqrt(i) ; j++){
             if(i % j == 0) {
                count++;
                if(i / j != j) 
                    count++;
            }
        }   
        arr2[i][1] = count;
    }
    sort(arr2.begin(), arr2.begin() + e + 1, cmp);

    for (int i = 0; i < starts.size(); i++)
    {
        for(int j = 0; j <= e; j++) {
            if (arr2[j][0] >= starts[i])
            {
                int k = arr2[j][0];
                answer.push_back(k);
                break;
            }
        }
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
