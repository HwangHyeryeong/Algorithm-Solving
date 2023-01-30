#include <iostream>
#include <string>
using namespace std;

#define NUM 26

int findMax(int arr[]) {
    int max = 0, index = -1, numOfDuplication = 0;
    for (int i = 0; i < NUM; i++) {
        if (arr[i] > max) {
            max = arr[i];
            index = i;
        }
        else if ((arr[i] == max)) {
            index = -1;
            numOfDuplication++;
            if(i == 25)
                break;
        }
    }

    return index;
}

int main() {
    int alphabet[NUM] = { 0 };
    string input;
    cin >> input;

    for (int i = 0; i < input.length(); i++) {
        if (input[i] >= (int)('a'))
            alphabet[(int)(input[i] - 'a')]++;
        else
            alphabet[(int)(input[i] - 'A')]++;
    }

    int maxIndex = findMax(alphabet);

    if (maxIndex == -1)
        cout << "?" << endl;
    else
        cout << (char)(maxIndex + 'A') << endl;

    return 0;
}