def diff(bit, tmp):
    cnt = 0
    i = len(bit) - 1
    j = len(tmp) - 1
    while i >= 0:
        if bit[i] != tmp[j]:
            cnt += 1
        i = i - 1
        j = j - 1
    return cnt

def twototen(num):
    i = len(num) - 1
    j = 0
    result = 0
    while i > 0:
        if num[i] == 1:
            result = result + pow(2, j)
        j = j + 1
        i = i - 1
    return result

def tentotwo(num):
    result = []
    while True:
        result.append(num % 2)
        num = num // 2
        if num == 0 or num == 1:
            result.append(num)
            break ;
    result.append(0)
    result.reverse()
    return result

def sol(num):
    result = 0
    # 1더하고 diff보면될듯
    bit = tentotwo(num)
    while True:
        num = num + 1
        tmp = tentotwo(num)
        if diff(bit, tmp) <= 2:
            break ;
    result = twototen(tmp)
    return result

def solution(numbers):
    answer = []
    for num in numbers:
        answer.append(sol(num))
    return answer
