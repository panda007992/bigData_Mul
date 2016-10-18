//�������
//���������޷���һ�����α����洢������Ȼ���뵽���ַ�������ʾһ�����֡�
//Ȼ���ճ˷������������һ��������ÿһλ������һ��������
//Ȼ�������м�������ȷλ����ӵõ����ս����
//���Է����ó��������ΪA��B��A��λ��Ϊm��B��λ��Ϊn����˻����Ϊm+n-1λ�����λ�޽�λ����m+nλ�����λ�н�λ����
//��˿��Է���һ��m+n�ĸ������洢���ս����Ϊ�˽�Լ�ռ䣬���е��м���ֱ����m+n�ĸ����Ͻ����ۼӡ�
//���Ϊ�˸��������ǵĳ˷������߼������Խ���������洢���������ֵĵ�λ��������ĵ��±�λ�ã������ۼ�ʱȷ���±�λ�ý�����Щ��
#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <stdlib.h>
using namespace std;
//�����������������ֵĵ�λ��������ĵ��±�λ�ã������ۼ�ʱȷ���±�λ�ý�����Щ
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
//��ɴ������
char* multiLargeNum(char* A, char* B)
{
    int m = strlen(A);
    int n = strlen(B);
    char* result = new char[m+n+1];
    memset(result, '0', m+n);
    result[m+n] = '\0';
    reverseOrder(A, 0, m-1);
    reverseOrder(B, 0, n-1);

    int multiFlag; // �˻���λ
    int addFlag;   // �ӷ���λ
    for(int i=0; i <= n-1; i++) // B��ÿһλ
    {
        multiFlag = 0;
        addFlag = 0;
        for(int j=0; j <= m-1; j++) // A��ÿһλ
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
    reverseOrder(result, 0, m+n-1); // �������

    return result;
}

//���Գ���
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
