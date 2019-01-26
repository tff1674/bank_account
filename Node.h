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
		cout<<"姓名："<<setw(6)<<name<<"   "<<"账号："<<setw(6)<<number<<"   "<<"性别："<<setw(8)<<sex<<"       "<<"日期："<<setw(6)<<date<<endl;
		cout<<"密码："<<setw(6)<<password<<"   "<<"金额："<<setw(6)<<money<<"   "<<"账户状态："<<setw(6)<<state<<endl;
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
		cout<<"输入姓名：";cin>>Name;ba1.name=Name;
		cout<<"输入账号：";cin>>Number;ba1.number=Number;
		cout<<"输入性别：";cin>>Sex;ba1.sex=Sex;
		cout<<"输入开户日期：";cin>>Date;ba1.date=Date;
		cout<<"输入密码：";cin>>Password;ba1.password=Password;
		cout<<"输入金额：";cin>>Money;ba1.money=Money;
		cout<<"输入账户状态：";cin>>State;ba1.state=State;
    }
// 结点类
template <class ElemType>
struct Node
{
// 数据成员:
	ElemType data;				// 数据域
	Node<ElemType> *next;		// 指针域

// 构造函数:
	Node();						// 无参数的构造函数
	Node(ElemType e, Node<ElemType> *link = NULL);	// 已知数数据元素值和指针建立结构
};

// 结点类的实现部分
template<class ElemType>
Node<ElemType>::Node()
// 操作结果：构造指针域为空的结点
{
   next = NULL;
}

template<class ElemType>
Node<ElemType>::Node(ElemType e, Node<ElemType> *link)
// 操作结果：构造一个数据域为e和指针域为link的结点
{
   data = e;
   next = link;
}

#endif

