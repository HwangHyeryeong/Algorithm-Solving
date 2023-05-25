def solution(arr, divisor):
    answer = []
    
    answer = [i for i in arr if i % divisor == 0] or [-1]
    answer.sort()
    
    return answer