#include <iostream>
using namespace std;

void ReplaceBlank(char string[], int length){
    if (string == NULL || length <= 0)
        return;
    int numOfBlank = 0;
    int index = 0;
    int originalLength = 0;
    while (string[index] != '\0') {
        if (string[index] == ' ')
            ++numOfBlank;
        ++originalLength;
        ++index;
    }
    int newLength = originalLength + numOfBlank * 2;
    int i = newLength;
    int j = originalLength;
    while (i >=0 && i > j)
    {
        if (string[j] == ' '){
            string[i--] = '0';
            string[i--] = '2';
            string[i--] = '%';
        }
        else
            string[i--] = string[j];
        --j;
    }
}

int main(){
    char test[30] = "I love SYC, yes!";
    ReplaceBlank(test, 30);
    cout<<test<<endl;
    return 0;
}