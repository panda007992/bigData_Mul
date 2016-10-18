//大数相乘
//由于数字无法用一个整形变量存储，很自然的想到用字符串来表示一串数字。
//然后按照乘法的运算规则，用一个乘数的每一位乘以另一个乘数，
//然后将所有中间结果按正确位置相加得到最终结果。
//可以分析得出如果乘数为A和B，A的位数为m，B的位数为n，则乘积结果为m+n-1位（最高位无进位）或m+n位（最高位有进位）。
//因此可以分配一个m+n的辅存来存储最终结果。为了节约空间，所有的中间结果直接在m+n的辅存上进行累加。
//最后为了更符合我们的乘法运算逻辑，可以讲数字逆序存储，这样数字的低位就在数组的低下标位置，进行累加时确定下标位置较容易些。
#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <stdlib.h>
using namespace std;
//将数组逆序，这样数字的低位就在数组的低下标位置，进行累加时确定下标位置较容易些
void reverseOrder(char* str, int p, int q)
{
    char temp;
    while(p < q)
    {
        temp = str[p];
        str[p] = str[q];
        str[q] = temp;
        p ++;
        q --;
    }
}
//完成大数相乘
char* multiLargeNum(char* A, char* B)
{
    int m = strlen(A);
    int n = strlen(B);
    char* result = new char[m+n+1];
    memset(result, '0', m+n);
    result[m+n] = '\0';
    reverseOrder(A, 0, m-1);
    reverseOrder(B, 0, n-1);

    int multiFlag; // 乘积进位
    int addFlag;   // 加法进位
    for(int i=0; i <= n-1; i++) // B的每一位
    {
        multiFlag = 0;
        addFlag = 0;
        for(int j=0; j <= m-1; j++) // A的每一位
        {
            // '0' - 48 = 0
            int temp1 = (A[j] - 48) * (B[i] - 48) + multiFlag;
            multiFlag = temp1 / 10;
            temp1 = temp1 % 10;
            int temp2 = (result[i+j] - 48) + temp1 + addFlag;
            addFlag = temp2 / 10;
            result[i+j] = temp2 % 10 + 48;
        }
        result[i + m] += multiFlag + addFlag;
    }
    reverseOrder(result, 0, m+n-1); // 逆序回来

    return result;
}

//测试程序
int main()
{
    char A[] = "962346239843253528686293234124";
    char B[] = "93459382645998213649236498";
    char *res = multiLargeNum(A, B);
    if(res[0] != 48)
        printf("%c", res[0]);
    printf("%s", res+1);
    delete [] res;
    return 0;
}
