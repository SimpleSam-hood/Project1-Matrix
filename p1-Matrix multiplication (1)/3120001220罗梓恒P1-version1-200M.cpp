#include<iostream>
#include<chrono>
#include<thread>
#define LEFT 200000000 // 左矩阵的元素个数（测试参数） 
#define RIGHT 200000000 // 右矩阵的元数个数（测试参数） 
#define RESULT 40000 // 结果矩阵的元素个数（测试参数） 
using namespace std;
using namespace std::chrono;
struct Mat //矩阵结构体 
{
	int row;//行数 
	int col;//列数 
	float* ele;//具体的元素数据 
};
Mat compute( Mat a, Mat b) 
{
	Mat c;
	c.row = a.row;//确定结果矩阵的行数和列数 
	c.col = b.col;
	c.ele = new float [RESULT]();//申请内存并初始化 
	if(a.col != b.row)//错误判断 
 	{
 		cout <<endl <<" WRONG! " <<endl;
 		return c;
	 }
	 else//计算方法 
	 {
	 	for(int k=0; k < a.row; k++)
	 	{
	 		for(int j=0; j < b.col; j++)
	 		{
	 			for(int i=0; i < a.col; i++)
	 			{
	 				c.ele[j + a.row* k] += (a.ele[i + a.col* k] ) * (b.ele[j + b.col* i]);
				 } 
			 }
		 } 
		 return c;
     }
     delete []c.ele;
}
int main()
{
	Mat left;
	Mat right;
	Mat result;
	left.row = 100;//设定测试参数
	left.col = 2000000;
	right.row = 2000000;
	right.col = 100; 
	left.ele = new float [LEFT]();//申请内存并初始化 
	right.ele = new float [RIGHT]();
	result.ele = new float [RESULT]();
	left.ele[0] = 5;//设定测试参数 
    right.ele[0] = 5;
	time_point<system_clock>start=system_clock::now();//开始运算的时间 
	result = compute( left, right);//运算 
	time_point<system_clock>finish=system_clock::now();//结束运算的时间 
	chrono::duration<double>passing=finish-start;
	cout <<"time: " <<passing.count()<<" s" <<endl; //用时输出	
	for (int i = 0; i < result.row; i++) //结果输出 
	{
        for (int j = 0; j < result.col; j++) 
		{
            cout << result.ele[i *result.col + j] << " ";
        }
        cout <<endl;
    }
    cout <<endl; 
	delete []left.ele;//释放内存 
	delete []right.ele;
	delete []result.ele;
	return 0;	
}
