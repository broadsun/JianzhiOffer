#include <iostream>
#include <vector>
using namespace std;
bool Find(vector<vector<int> > &matrix, int rows, int columns, int number){
    if (matrix.empty()|| rows <= 0 || columns <= 0)
        return false;
    int i = 0;
    int j = columns - 1;
    while (i < rows && j >=0)
    {
        if (matrix[i][j] == number)
            return true;
        else if (matrix[i][j] > number)
            --j;
        else
            ++i;
    }
    return false;
}

int main(){
    vector<vector<int> > matrix(4, vector<int>(4,0));
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            if (0 == i)
            {
                matrix[i][j] = j+1;
            }
            else
                matrix[i][j] = matrix[i-1][j]+1;
        }
    }
    bool res = Find(matrix, 4,4,7);
    if (res)
    {
        cout<<"Find!!"<<endl;
    }
    else
        cout<<"No"<<endl;
    
    return 0;
}