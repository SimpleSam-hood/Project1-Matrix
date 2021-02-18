#include<iostream>
#include<chrono>
#include<thread>
using namespace std;
using namespace std::chrono;
struct Matrix
{
	int n_row;
	int n_col;
	float* ele;
 };
 Matrix compute(Matrix a,Matrix b)//���㺯�� 
 {
 	Matrix c={0,0};
 	c.n_row=a.n_row;
 	c.n_col=b.n_col;
 	c.ele=new float[c.n_row*c.n_col]();
 	if(a.n_col!=b.n_row)
 	{
 		cout<<"wrong!"<<endl;
 		return c;
	 }
	 else
	 {
	 	for(int k=0;k<a.n_row;k++)
	 	{
	 		for(int j=0;j<b.n_col;j++)
	 		{
	 			for(int i=0;i<a.n_col;i++)
	 			{
	 				c.ele[j + a.n_row* k] += a.ele[i+a.n_col* k] * b.ele[j + b.n_col* i];
				 } 
			 }
		 } 
		 return c;
	 }
 }
 int main()
 {
 	Matrix left_mat;
 	Matrix right_mat;
 	Matrix result_mat;
 	cout<<"enter the number of rows of left matrix: "<<endl;
 	cin>>left_mat.n_row;
 	cout<<"enter the number of columns of left matrix: "<<endl;
 	cin>>left_mat.n_col;
 	left_mat.ele=new float [left_mat.n_row*left_mat.n_col]();//��������������� 
 	cout<<"enter the number of rows of right matrix: "<<endl;
 	cin>>right_mat.n_row;
 	cout<<"enter the number of columns of right matrix: "<<endl;
 	cin>>right_mat.n_col;
 	right_mat.ele=new float [right_mat.n_row*right_mat.n_col]();//�����Ҿ��������� 
 	for(int i=0;i<left_mat.n_row*left_mat.n_col;i++)
 	{
 		cout<<"enter the element(left matrix)"<<"NO."<<i+1<<":"<<endl;
 		cin>>left_mat.ele[i];
	 }//����������Ԫ�� 
	 for(int i=0;i<right_mat.n_row*right_mat.n_col;i++)
	 {
	 	cout<<"enter the element(right matrix)"<<"NO."<<i+1<<":"<<endl;
	 	cin>>right_mat.ele[i];
	 }//�����Ҿ����Ԫ�� 
	 time_point<system_clock>start=system_clock::now();//��ʼ�����ʱ�� 
	 result_mat=compute(left_mat,right_mat);//���� 
	 time_point<system_clock>finish=system_clock::now();//���������ʱ�� 
	 chrono::duration<double>passing=finish-start;
	 cout <<"time: " <<passing.count()<<" s" <<endl; //��ʱ���
	 for (int i = 0; i < result_mat.n_row; i++) //������ 
	{
        for (int j = 0; j < result_mat.n_col; j++) 
		{
            cout << result_mat.ele[i *result_mat.n_col + j] << " ";
        }
        cout <<endl;
    }
	 delete []left_mat.ele;//�ͷ��ڴ� 
	 delete []right_mat.ele;
	 delete []result_mat.ele;
	 return 0; 	
 }
