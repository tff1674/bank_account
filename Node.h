#ifndef __NODE_H__
#define __NODE_H__
#include <iostream>
#include <fstream>


struct Bank
{
	string name;
	string number;
	long date;
	string sex;
	string password;
	double money;
	string state;
	void show()
	{
		cout<<"������"<<setw(6)<<name<<"   "<<"�˺ţ�"<<setw(6)<<number<<"   "<<"�Ա�"<<setw(8)<<sex<<"       "<<"���ڣ�"<<setw(6)<<date<<endl;
		cout<<"���룺"<<setw(6)<<password<<"   "<<"��"<<setw(6)<<money<<"   "<<"�˻�״̬��"<<setw(6)<<state<<endl;
	}
	Bank()
	{
		name="Name";
		number="Number";
		sex="Sex";
		date=0;
		password="Password";
		money=0;
		state="State";
	}
	Bank(string Name,string Number,string Sex,long Date,string Password,double Money,string State)
	{
		name=Name;
		number=Number;
		sex=Sex;
		date=Date;
		password=Password;
		money=Money;
		state=State;
	}

};
    void getbank(Bank &ba1)
    {
		string Name;string Number;string Sex;long Date;string Password;double Money;string State;
		cout<<"����������";cin>>Name;ba1.name=Name;
		cout<<"�����˺ţ�";cin>>Number;ba1.number=Number;
		cout<<"�����Ա�";cin>>Sex;ba1.sex=Sex;
		cout<<"���뿪�����ڣ�";cin>>Date;ba1.date=Date;
		cout<<"�������룺";cin>>Password;ba1.password=Password;
		cout<<"�����";cin>>Money;ba1.money=Money;
		cout<<"�����˻�״̬��";cin>>State;ba1.state=State;
    }
// �����
template <class ElemType>
struct Node
{
// ���ݳ�Ա:
	ElemType data;				// ������
	Node<ElemType> *next;		// ָ����

// ���캯��:
	Node();						// �޲����Ĺ��캯��
	Node(ElemType e, Node<ElemType> *link = NULL);	// ��֪������Ԫ��ֵ��ָ�뽨���ṹ
};

// ������ʵ�ֲ���
template<class ElemType>
Node<ElemType>::Node()
// �������������ָ����Ϊ�յĽ��
{
   next = NULL;
}

template<class ElemType>
Node<ElemType>::Node(ElemType e, Node<ElemType> *link)
// �������������һ��������Ϊe��ָ����Ϊlink�Ľ��
{
   data = e;
   next = link;
}

#endif

