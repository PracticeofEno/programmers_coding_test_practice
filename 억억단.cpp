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

    vector<vector<int>> arr2 (e + 1, vector<int> (2, 0));
    map<int, int> available;
    int answer_index = -1;
    int max = -1;

    for (int i = 1; i <= e; i++) {
        arr2[i][0] = i;
        arr2[i][1] = arr2[i][1] + 1;
    }
	
    //2부터 e까지의 숫자에 대한 약수 정보 삽입
    for (int i = 2; i <= e; i++) {
        for (int k = 1; k <= e / i; k++) {
            arr2[i * k][1] = arr2[i*k][1] + 1;
        }
    }
    // for (int i = 0; i <= e; i++)
    // {
    //     arr2[i][0] = i;
    //     if (i >= 2) {
    //         int count = 0;
    //         for(int j = 1 ; j <= sqrt(i) ; j++){
    //             if(i % j == 0) {
    //                 count++;
    //                 if(i / j != j) 
    //                     count++;
    //             }
    //         }   
    //         arr2[i][1] = count;
    //     }
    // }
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
