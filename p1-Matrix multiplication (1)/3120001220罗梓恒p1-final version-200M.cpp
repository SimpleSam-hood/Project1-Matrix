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
void compute(Mat* p_a, Mat* p_b, Mat* p_c)
{
	p_c->row = p_a->row;//确定结果矩阵的行数和列数 
	p_c->col = p_b->col;
	//p_c->ele = new float[RESULT]();//申请临时动态内存并初始化
	if (p_a->col != p_b->row)//错误判断 
	{
		cout << endl << " WRONG! " << endl;
	}
	else//计算方法 
	{
		for (int k = 0; k < p_a->row; k++)
		{
			for (int j = 0; j < p_b->col; j++)
			{
				for (int i = 0; i < p_a->col; i+=10)
				{
					p_c->ele[j + p_a->row * k] += p_a->ele[i + p_a->col * k] * p_b->ele[j + p_b->col * i];
					p_c->ele[j + p_a->row * k] += p_a->ele[1+i + p_a->col * k] * p_b->ele[j + p_b->col * (i+1)];
					p_c->ele[j + p_a->row * k] += p_a->ele[2+i + p_a->col * k] * p_b->ele[j + p_b->col * (i+2)];
					p_c->ele[j + p_a->row * k] += p_a->ele[3+i + p_a->col * k] * p_b->ele[j + p_b->col * (i+3)];
					p_c->ele[j + p_a->row * k] += p_a->ele[4+i + p_a->col * k] * p_b->ele[j + p_b->col * (i+4)];
					p_c->ele[j + p_a->row * k] += p_a->ele[5+i + p_a->col * k] * p_b->ele[j + p_b->col * (i+5)];
					p_c->ele[j + p_a->row * k] += p_a->ele[6+i + p_a->col * k] * p_b->ele[j + p_b->col * (i+6)];
					p_c->ele[j + p_a->row * k] += p_a->ele[7+i + p_a->col * k] * p_b->ele[j + p_b->col * (i+7)];
					p_c->ele[j + p_a->row * k] += p_a->ele[8+i + p_a->col * k] * p_b->ele[j + p_b->col * (i+8)];
					p_c->ele[j + p_a->row * k] += p_a->ele[9+i + p_a->col * k] * p_b->ele[j + p_b->col * (i+9)];	
				}
			}
		}
	} 
}
int main()
{
	Mat left;
	Mat right;
	Mat result;
	Mat* p_left = &left;//结构体指针初始化 
	Mat* p_right = &right;
	Mat* p_result = &result;
	p_left->row = 100;//设定测试参数
	p_left->col = 2000000;
	p_right->row = 2000000;
	p_right->col = 100;
	p_left->ele = new float[LEFT]();//申请动态内存并初始化 
	p_right->ele = new float[RIGHT]();
	p_result->ele = new float[RESULT]();
	p_left->ele[0] = 5;//设定测试参数 
	p_right->ele[0] = 5;
	time_point<system_clock>start=system_clock::now();//开始运算的时间 
	compute(p_left, p_right,p_result);//运算 
	time_point<system_clock>finish=system_clock::now();//结束运算的时间 
	chrono::duration<double>passing=finish-start;
	cout <<"time: " <<passing.count()<<" s" <<endl; //用时输出	
	for (int i = 0; i < p_result->row; i++) //结果输出 
	{
		for (int j = 0; j < p_result->col; j++)
		{
			cout << p_result->ele[i * p_result->col + j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	delete[]p_left->ele;//释放动态内存 
	delete[]p_right->ele;
	delete[]p_result->ele;
	return 0;
}
