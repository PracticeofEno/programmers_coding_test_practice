"""프로그래머스 - 야근지수"""

# 각 works의 제곱을 더한 값이 최소가 되도록 만들어야 함
# n만큼 works에서 수치를 뺼 수 있음. 즉 큰 수부터 n만큼 빼주면 됨
# 정렬된 자료구조를 가지며, 가장 큰 수부터 가져와서 1씩 빼주는걸 반복하면 됨
# 여기서 효율적으로 만들고자 할수 있겠지만 가장 간단한 알고리즘으로써 list를 만들고 빼주고 정렬하고 형태로 선택
def solution(n, works: list):
    works.sort(reverse=True)
    for i in range(n):
        if works[0] == 0:
            continue
        works[0] -= 1
        works.sort(reverse=True)
    overtime_index = sum([i**2 for i in works])
    print(overtime_index)
    return overtime_index

n = 4
works= [4, 3, 3]
result = solution(n, works) # 12
print(result)