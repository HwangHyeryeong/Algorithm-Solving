#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct FileName{
    int idx;
    string head;
    int number;
};

vector<FileName> names;

bool cmp(const FileName& f1, const FileName& f2){
    if(f1.head == f2.head){
        if(f1.number == f2.number)
            return f1.idx < f2.idx;
        else
            return f1.number < f2.number;         
    }
    else
        return f1.head < f2.head;
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    
    //파일명 파싱
    for(int i = 0; i < files.size(); i++){
        vector<int> index;
        for(int j = 0 ; j < files[i].size(); j++){
            if(files[i][j] >= '0' && files[i][j] <= '9'){
                index.push_back(j);
            }
        }
        string head = "";
        for(int j = 0; j < index[0]; j++){
            head += tolower(files[i][j]); //문자 모두 소문자로 변환
        }
        string num = files[i].substr(index[0], index.size());
        
        FileName file;
        file.idx = i;
        file.head = head;
        file.number = stoi(num);
        names.push_back(file);
    }
    
    sort(names.begin(), names.end(), cmp);
    for(FileName f : names){
        answer.push_back(files[f.idx]);
    }
    
    return answer;
}