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
Mat compute( Mat a, Mat b) 
{
	Mat c;
	c.row = a.row;//ȷ�������������������� 
	c.col = b.col;
	c.ele = new float [RESULT]();//�����ڴ沢��ʼ�� 
	if(a.col != b.row)//�����ж� 
 	{
 		cout <<endl <<" WRONG! " <<endl;
 		return c;
	 }
	 else//���㷽�� 
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
	left.row = 100;//�趨���Բ���
	left.col = 2000000;
	right.row = 2000000;
	right.col = 100; 
	left.ele = new float [LEFT]();//�����ڴ沢��ʼ�� 
	right.ele = new float [RIGHT]();
	result.ele = new float [RESULT]();
	left.ele[0] = 5;//�趨���Բ��� 
    right.ele[0] = 5;
	time_point<system_clock>start=system_clock::now();//��ʼ�����ʱ�� 
	result = compute( left, right);//���� 
	time_point<system_clock>finish=system_clock::now();//���������ʱ�� 
	chrono::duration<double>passing=finish-start;
	cout <<"time: " <<passing.count()<<" s" <<endl; //��ʱ���	
	for (int i = 0; i < result.row; i++) //������ 
	{
        for (int j = 0; j < result.col; j++) 
		{
            cout << result.ele[i *result.col + j] << " ";
        }
        cout <<endl;
    }
    cout <<endl; 
	delete []left.ele;//�ͷ��ڴ� 
	delete []right.ele;
	delete []result.ele;
	return 0;	
}
