def solution(arr):
    answer = []
    
    for cur in arr:
        if len(answer) == 0 or answer[-1] != cur:
            answer.append(cur)
    
    return answer