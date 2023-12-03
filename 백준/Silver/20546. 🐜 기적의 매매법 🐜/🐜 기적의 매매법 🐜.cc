#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(){
    int cash; cin >> cash;
    vector<int> stock(14, 0);

    int jhStock = 0, smStock = 0, jhMoney = cash, smMoney = cash;
    int decline = 0, rise = 0;
    for(int i = 0; i < 14; i++){
        cin >> stock[i];
        
        if(i > 0){
            if(stock[i] > stock[i-1]){
                decline = 0;
                rise++;
            }
            else if(stock[i] < stock[i - 1]){
                rise = 0;
                decline++;
            }
            else{
                decline = 0;
                rise = 0;
            }
        }
        
        if(jhMoney >= stock[i]){
            int cnt = jhMoney / stock[i];
            jhStock += cnt;
            jhMoney -= cnt * stock[i];
        }
        
        if(decline == 3){
            if(smMoney >= stock[i]){
                int cnt = smMoney / stock[i];
                smStock += cnt;
                smMoney -= cnt * stock[i];
            }
        }
        else if(rise == 3){
            smMoney += smStock * stock[i];
            smStock = 0;
        }
    }
    
    jhMoney += jhStock * stock[13];
    smMoney += smStock * stock[13];
    
    if(jhMoney > smMoney) cout << "BNP";
    else if(jhMoney < smMoney) cout << "TIMING";
    else cout <<"SAMESAME";
    
    return 0;
}