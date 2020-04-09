// macro.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
/*
__FUNTION__  获取当前函数名
__LINE__ 获取当前代码行号
__FILE__ 获取当前文件名
__DATE__ 获取当前日期
__TIME__ 获取当前时间
__STDC_VERSION__
*/

using namespace std;
#define Pi 3.14156
//参数形式
#define sum(a,b)  (a+b)
//字符转换
#define PSQR(x) printf("the square of "#x" is %d.\n",((x)*(x)))
#define PSQR2(x) printf("the square of %s is %d.\n",#x,((x)*(x)))
//## 连接器
#define  Sum_Number(b) 12##b
//a++
#define S(a) (a)*(a)
//输出警告
#define WARN_IF(EXPR)\
do {\
    if (EXPR)\
        fprintf(stderr, "Warning: "#EXPR" \n");\
} while(0)

#define PR(...) printf(__VA_ARGS__)

//宏的长用用途
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


