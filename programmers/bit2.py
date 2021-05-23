def sol(num):
    tmp = num
    while True:
        tmp = tmp + 1
        if bin(num ^ tmp).count("1") <= 2:
            break ;
    return tmp

def solution(numbers):
    answer = []
    for num in numbers:
        answer.append(sol(num))
    return answer
