#include <bits/stdc++.h>

using namespace std;

bool decreaseStone(vector<int> stones, int min, int k)
{
    int count = 0;
    for (int i = 0; i < stones.size(); i++)
    {
        stones[i] = stones[i] - min;
        if (stones[i] <= 0)
        {
            count++;
        }
        else
        {
            count = 0;
        }
        if (count == k)
            return false;
    }
    return true;
}

int solution(vector<int> stones, int k)
{
    int answer = 0;
    bool loop = true;
    bool checkAvailableStone = 0;
    vector<int> tmp = stones;
    sort(tmp.begin(), tmp.end());
    int left = 0;
    int right = stones.size();
    while (left != right)
    {
        int index = ((left + right) / 2);
        checkAvailableStone = decreaseStone(stones, tmp[index], k);
        if (checkAvailableStone == false)
        {
            if (right == index) 
                right--;
            else 
                right = index;
        }
        else
        {
            if (left == index) 
                left++;
            else 
                left = index;
        }
    }
    return tmp[left];
}

int main()
{
    vector<int> stones = {2, 4, 5, 3, 2, 1, 4, 2, 5, 1};
    cout << solution(stones, 3) << endl;
}
