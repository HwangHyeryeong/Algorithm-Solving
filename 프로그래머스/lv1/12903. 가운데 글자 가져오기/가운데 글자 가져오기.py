def solution(s):
    answer = ''
    centerIndex = len(s)//2
    
    if len(s) % 2 == 0:
        answer = s[centerIndex-1:centerIndex+1]
    else:
        answer = s[centerIndex]
        
    return answer