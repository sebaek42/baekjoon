def solution(dartResult):
    answer = 0
    cnt = 0
    CHANCE = 3
    score = []
    dartResult = list(dartResult)
    while cnt < CHANCE:
        token = dartResult.pop(0)
        if token == '1' and dartResult[0] == '0':
            token = token + dartResult.pop(0)
        score.append(int(token))
        token = dartResult.pop(0)
        if token == 'D':
            score[cnt] = score[cnt]**2
        elif token == 'T':
            score[cnt] = score[cnt]**3
        if dartResult:
            if dartResult[0] == '*' or dartResult[0] == '#':
                token = dartResult.pop(0)
                if token == '*':
                    score[cnt] = score[cnt] * 2
                    if cnt != 0:
                        score[cnt - 1] = score[cnt - 1] * 2
                if token == '#':
                    score[cnt] = score[cnt] * -1
        cnt = cnt + 1
    answer = sum(score)
    return answer

dart = "1S2D*3T*"
print(solution(dart))
