"""프로그래머스 - 야근지수"""

# 각 works의 제곱을 더한 값이 최소가 되도록 만들어야 함
# n만큼 works에서 수치를 뺼 수 있음. 즉 큰 수부터 n만큼 빼주면 됨

def solution(n, works: list):
    index_list = {}
    max = 0
    for i in range(50000):
        index_list[i] = 0
    for work in works:
        index_list[work] += 1
        if max < work:
            max = work
    for _ in range(n):
        if max < 0:
            break
        if index_list[max] > 0:
            index_list[max] -= 1
            if max > 0:
                index_list[max-1] += 1
            if index_list[max] == 0:
                max -= 1
    indexs = [i for i in range(50000) if index_list[i] > 0]
    overtime_indexs = sum([(i ** 2) * index_list[i] for i in indexs])
    print(overtime_indexs)
    return overtime_indexs

n = 9
works= [1,1,1]
result = solution(n, works) # 12
print(result)