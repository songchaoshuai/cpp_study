// macro.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
/*
__FUNTION__  ��ȡ��ǰ������
__LINE__ ��ȡ��ǰ�����к�
__FILE__ ��ȡ��ǰ�ļ���
__DATE__ ��ȡ��ǰ����
__TIME__ ��ȡ��ǰʱ��
__STDC_VERSION__
*/

using namespace std;
#define Pi 3.14156
//������ʽ
#define sum(a,b)  (a+b)
//�ַ�ת��
#define PSQR(x) printf("the square of "#x" is %d.\n",((x)*(x)))
#define PSQR2(x) printf("the square of %s is %d.\n",#x,((x)*(x)))
//## ������
#define  Sum_Number(b) 12##b
//a++
#define S(a) (a)*(a)
//�������
#define WARN_IF(EXPR)\
do {\
    if (EXPR)\
        fprintf(stderr, "Warning: "#EXPR" \n");\
} while(0)

#define PR(...) printf(__VA_ARGS__)

//��ĳ�����;
#define MacroLog(...)\
{\
FILE* file; \
fopen_s(&file, "./a.txt", "a"); \
if (file != nullptr)\
{\
fprintf(file, "%s: Line %d:\t", __FILE__, __LINE__); \
fprintf(file, __VA_ARGS__); \
fprintf(file, "\n"); \
}\
fclose(file); \
}

void FuncLog(const char *filename, int line, const char * str)
{
	FILE* file;
	fopen_s(&file, "./a.txt", "a");
	if (file != nullptr)
	{
		fprintf(file, "%s: Line %d:\t", filename, line);
		fprintf(file, str);
		fprintf(file, "\n");
	}
	fclose(file);
}

int main()
{
	cout << Pi << endl;
	cout << sum(2*3,3) << endl;
	PSQR(2 * 3);
	cout << Sum_Number(1423) << endl;
	int a = 1;
	cout << S(a++) <<a<< endl;
	//////////////
	int R = 5;
	WARN_IF(R>0);
	/////////////
	PR("Howdy");
	PR("weight=%d,shipping=$%.2f.\n", 12, 20.1);
	/////////////////////
	MacroLog("%s,%s", "hello", "log");
	FuncLog(__FILE__, __LINE__, "hello");
	return 0;
}


