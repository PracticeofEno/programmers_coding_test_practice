def solution(n, s):
    if (s < n):
        return [-1]
    mok = s // n
    mod = s % n
    
    answer = []
    for i in range(n):
        if mod > 0:
            answer.append(mok + 1)
            mod -= 1
        else:
            answer.append(mok)
    answer.sort()
    return answer

n = 2
s = 9
result = solution(n, s)
print(result)