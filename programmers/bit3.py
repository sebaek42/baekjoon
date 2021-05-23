def sol(num):
    bn = bin(num)
    bn = bn[2:]
    i = len(bn) - 1
    if bn[i] == '0':
        return num + 1
    while i >= 0:
        if bn[i] == '0':
            return num + pow(2, len(bn) - 1 - i) - pow(2, len(bn) - 2 - i)
        i = i - 1
    return num - pow(2, len(bn) - 1) + pow(2, len(bn))


# 첫번째 0 나오는 곳을 뒤랑 바꾸면돼겠다. 0이 첨에 발견돼면 걍 + 1해주고
# 1011
# 1101

def solution(numbers):
    answer = []
    for num in numbers:
        answer.append(sol(num))
    return answer
