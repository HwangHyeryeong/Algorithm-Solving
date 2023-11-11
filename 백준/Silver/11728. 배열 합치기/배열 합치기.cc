#include <iostream>
#include <vector>
using namespace std;

int main(){
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
    
    int sizeA, sizeB; cin >> sizeA >> sizeB;
    vector<int> A(sizeA, 0), B(sizeB, 0);
    
    //A배열 입력
    for(int i = 0; i < sizeA; i++)
        cin >> A[i];
    //B배열 입력
    for(int i = 0; i < sizeB; i++)
        cin >> B[i];
    
    vector<int> result;
    int indexA = 0, indexB = 0;
    while(indexA < sizeA && indexB < sizeB){
        if(A[indexA] <= B[indexB])
            cout << A[indexA++] << " ";
        else
            cout << B[indexB++] << " ";
    }
    
    //남은 배열 출력
    if(indexA < sizeA)
        for(; indexA < sizeA; indexA++)
            cout << A[indexA] << " ";
    else
        for(; indexB < sizeB; indexB++)
            cout << B[indexB] << " ";
    
    return 0;
}