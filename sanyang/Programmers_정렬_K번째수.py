#Programmers_정렬_K번째수

def solution(array, commands):
    size = len(commands)
    answer = [0] * len(commands)
    for i in range(len(commands)):
        tmpArr = array[commands[i][0]-1:commands[i][1]]
        tmpArr.sort()
        answer[i] = tmpArr[commands[i][2]-1]
    return answer
