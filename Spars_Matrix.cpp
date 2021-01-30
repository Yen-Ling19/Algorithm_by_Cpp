#include <iostream>
using namespace std;

class SpMatrix
{
    public:
        SpMatrix(int x);
        void input();
        void transpose();
        void output();
    private:
        int size;
        int *row;
        int *col;
        int *value;
        int col_max_num;
        int *smArray;
        int *row_final;
        int *col_final;
        int *value_final;
};

int main()
{
    int total_num; //一共有幾個值
    cin >> total_num;
    SpMatrix A(total_num);
    A.input();
    A.transpose();
    A.output();
}

SpMatrix::SpMatrix(int x)
{
    size = x;
    row = new int[x];
    col = new int[x];
    value = new int[x];
    row_final = new int[x];
    col_final = new int[x];
    value_final = new int[x];
    for (int i = 0; i < size; i++){
        row[i] = 0;
        col[i] = 0;
        value[i] = 0;
        row_final[i] = 0;
        col_final[i] = 0;
        value_final[i] = 0;
    }
}

void SpMatrix::input()
{
    for (int i = 0; i < size; i++){
        cin >> row[i] >> col[i] >> value[i];
    }
    int max = 0; //找出最大的col數
    for (int i = 0; i < size; i++){
        if(col[i]>max)
            max = col[i];
    }
    col_max_num = max;
    smArray = new int[(col_max_num + 1) * 2]; //宣告最大col數的兩倍空間，前半段放RowSize，後半段放RowStart
    for (int i = 0; i < (col_max_num + 1) * 2; i++){
        smArray[i] = 0;
    }
}

void SpMatrix::transpose()
{
    int col_num = 0;
    for (int i = 0; i < size; i++) //算RowSize
    {
        col_num = col[i];
        smArray[col_num]++;
    }
    for (int i = col_max_num + 2; i < (col_max_num + 1) * 2; i++){ //算RowStart
        smArray[i] = smArray[i - 1] + smArray[i - col_max_num - 2];
    }
    int start = 0;
    for (int i = 0; i < col_max_num + 1; i++)
    {
        for (int j = 0; j < size; j++){
            if(col[j]==i){
                start = smArray[col_max_num + 1 + i];
                row_final[start] = col[j];
                col_final[start] = row[j];
                value_final[start] = value[j];
                col[j] = i;
                row[j] = i;
                value[j] = i;
                smArray[col_max_num + 1 + i] = smArray[col_max_num + 1 + i] + 1;
            }
        }
    }
}

void SpMatrix::output()
{
    for (int i = 0; i < size; i++){
        cout << row_final[i] << " " <<  col_final[i] << " " << value_final[i] << endl;
    }
}