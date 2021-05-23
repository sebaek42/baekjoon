def sol(x):
    i = 0
    while (i < len(x)):
        key = x.find("110")
        while key < i:
            st = x[key+2:]
            key = st.find("110")
        tmp = x.find("111")
        if tmp != -1 and tmp < key and tmp >= i:  # i = tmp + 1
            temp = list(x)
            temp[tmp+2] = '0'
            temp[key+2] = '1'
            x = ''.join(temp)
            i = tmp
        else:
            break ;
    print(x)
    return x


def solution(s):
    answer = []
    for x in s:
        answer.append(sol(x))
    return answer
