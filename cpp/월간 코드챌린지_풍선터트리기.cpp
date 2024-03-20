#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> a)
{
    int answer = 2;
    queue<int> left_min_q;
    vector<int> right_min_q;

    int min[a.size()][2];

    int left_min_value = a[0];
    int right_min_value = a[a.size()-1];

    for(int i = 1; i < a.size(); i++) {
        if (a[i] < left_min_value) {
            left_min_value = a[i];
        }
        min[i][0] = left_min_value;
    }
    for(int i = a.size() - 2; i > 0; i--) {
        if (a[i] < right_min_value) {
            right_min_value = a[i];
        }
        min[i][1] = right_min_value;
    }

    for (int i = 1; i < a.size() - 1; i++)
    {
        if (a[i] <= min[i][0] || a[i] <= min[i][1]) {
            answer++;
        }

    }
    return answer;
}

int main()
{
    vector<int> a = {-16, 27, 65, -2, 58, -92, -71, -68, -61, -33};
    cout << solution(a) << endl;
}
