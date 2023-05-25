def solution(arr):
    answer = []
    stack = []
    
    stack.append(arr[0])
    for i in range(1, len(arr)):
        if arr[i] != stack[0]:
            answer.append(stack[0])
            stack.pop()
            stack.append(arr[i])
    answer.append(stack[0])
    
    return answer