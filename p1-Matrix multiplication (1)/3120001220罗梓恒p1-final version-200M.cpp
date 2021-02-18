#include<iostream>
#include<chrono>
#include<thread>
#define LEFT 200000000 // ������Ԫ�ظ��������Բ����� 
#define RIGHT 200000000 // �Ҿ����Ԫ�����������Բ����� 
#define RESULT 40000 // ��������Ԫ�ظ��������Բ����� 
using namespace std;
using namespace std::chrono;
struct Mat //����ṹ�� 
{
	int row;//���� 
	int col;//���� 
	float* ele;//�����Ԫ������ 
};
void compute(Mat* p_a, Mat* p_b, Mat* p_c)
{
	p_c->row = p_a->row;//ȷ�������������������� 
	p_c->col = p_b->col;
	//p_c->ele = new float[RESULT]();//������ʱ��̬�ڴ沢��ʼ��
	if (p_a->col != p_b->row)//�����ж� 
	{
		cout << endl << " WRONG! " << endl;
	}
	else//���㷽�� 
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
	Mat* p_left = &left;//�ṹ��ָ���ʼ�� 
	Mat* p_right = &right;
	Mat* p_result = &result;
	p_left->row = 100;//�趨���Բ���
	p_left->col = 2000000;
	p_right->row = 2000000;
	p_right->col = 100;
	p_left->ele = new float[LEFT]();//���붯̬�ڴ沢��ʼ�� 
	p_right->ele = new float[RIGHT]();
	p_result->ele = new float[RESULT]();
	p_left->ele[0] = 5;//�趨���Բ��� 
	p_right->ele[0] = 5;
	time_point<system_clock>start=system_clock::now();//��ʼ�����ʱ�� 
	compute(p_left, p_right,p_result);//���� 
	time_point<system_clock>finish=system_clock::now();//���������ʱ�� 
	chrono::duration<double>passing=finish-start;
	cout <<"time: " <<passing.count()<<" s" <<endl; //��ʱ���	
	for (int i = 0; i < p_result->row; i++) //������ 
	{
		for (int j = 0; j < p_result->col; j++)
		{
			cout << p_result->ele[i * p_result->col + j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	delete[]p_left->ele;//�ͷŶ�̬�ڴ� 
	delete[]p_right->ele;
	delete[]p_result->ele;
	return 0;
}
