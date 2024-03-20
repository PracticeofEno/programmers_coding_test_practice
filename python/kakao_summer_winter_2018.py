def search(lst : list, start: int, target):
    end = len(lst) - 1
    while start <= end:
        if lst[start] > target:
            return start
        start += 1
    return -1

def solution(A: list, B: list):
    A.sort()
    B.sort()
    print(A, B)
    start = 0
    count = 0
    for a in A:
        index = search(B, start, a)
        if index == -1:
            break
        start = index + 1
        count += 1
    print(count)
    return count

A = [5,1,3,7]
B = [2,2,6,8]

result = solution(A,B)
print(result)