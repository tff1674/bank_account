#ifndef __LK_LIST_H__
#define __LK_LIST_H__
#include <iostream>
#include <fstream>
#include<string>
#include "Node.h"

template <class ElemType>
class LinkList
{
protected:
	Node<ElemType> *head;
	int length;

public:
    LinkList();
	LinkList(ElemType v[], int n);
	virtual ~LinkList();
	void Clear();						// 将单链表清空
	void Traverse(void (*Visit)(const ElemType &)) const;// 遍历单链表
	int LocateElem(const ElemType &e) const;	         // 元素定位
	void Saving();           //存款
	void Drawing();           //取款
	Status GetElem(int position, ElemType &e) const;	 // 求指定位置的元素
	void SetElem();	 // 设置指定位置的元素值
	void DeleteElem();		 // 删除元素
	Status InsertElem(int position, const ElemType &e);	 // 在制定位置插入元素
	void InsertElem();	                              //开户
	Status InsertElem(const ElemType &e);                // 在表尾插入元素
	void change1();
	double change2();
	void change3(double a);
	void showlink();
	void open();
	void showall();
	double interest();
	void arrange();
	void Save(char *filename);
	void Load(char *filename);
	void calculate();
};

template<class ElemType>
void LinkList<ElemType>::calculate()//利息
{
    long delta,end_year;
    double interest;
    int years;
    cout<<"请输入需要查询的利息账号：";
	string search1;
	cin>>search1;
	Node<ElemType> *p=head;
    for(int i=1;i<=length ;i++)
    {
		p=p->next;
		if(p->data.number==search1)//找账户
		{
           cout<<"请输入存款到期时间：";
    	   cin>>end_year;
           delta=end_year-p->data.date;
           if(delta<0)
		   {
             cout<<"时间错误"<<endl;
           }
           else if(delta==0)
		   {
             cout<<"利息为0"<<endl;
           }
           else if(delta%10000==0)
	       {
             years = delta/10000;
             if(p->data.state=="活期")
		     {
               interest=years*p->data.money*0.0035;
             }
             if(p->data.state=="定期")
		     {
               if(years==1)
			   {
                interest=p->data.money*years*0.0275;
               }
               else if(years>1&&years<=2)
		       {
                interest=p->data.money*0.0275+(p->data.money+p->data.money*0.0275)*(years-1)*0.0335;
               }
               else if(years>2)
		       {
                interest=p->data.money*0.0275+(p->data.money+p->data.money*0.0275)*0.0335
				+(p->data.money*0.0275+(p->data.money+p->data.money*0.0275)*0.0335
				+p->data.money)*0.04*(years-2);
               }
             }
              cout<<"利息为："<<interest<<endl;
           }
           else if(delta%10000!=0)
		   {
             years = int(delta/10000)+0.5;
             if(p->data.state=="活期")
		     {
               interest=years*p->data.money*0.0035;
             }
             if(p->data.state=="定期")
		     {
               if(years==1)
			   {
                interest=p->data.money*years*0.0275;
               }
               else if(years>1&&years<=2)
		       {
                interest=p->data.money*0.0275+(p->data.money+p->data.money*0.0275)*(years-1)*0.0335;
               }
               else if(years>2)
		       {
                interest=p->data.money*0.0275+(p->data.money+p->data.money*0.0275)*0.0335
				+(p->data.money*0.0275+(p->data.money+p->data.money*0.0275)*0.0335
				+p->data.money)*0.04*(years-2);
               }
             }
             cout<<"利息为："<<interest<<endl;
           }
	    }
}
}


template<class ElemType>
void LinkList<ElemType>::change1()
{
    string search1;
    double Money;
    int flag = 0;
    cout<< "请输入需要操作的账号："<<endl;
    cin >> search1;
    string search2;
    Node<ElemType> *p=head;
    for(int i=1;i<=length ;i++)
    {
		p=p->next;
		if(p->data.number==search1)//找账户
		{
		   cout<<"输入密码："<<endl;
		   cin>>search2;
		   if(search2==p->data.password)//找密码
		   {
		       cout<<"输入转账金额："<<endl;
		       cin>>Money;
			   if(Money>p->data.money)
               {
                   cout<<"转账金额大于当前余额,转账失败。"<<endl;
               }
               else
          flag=1;         p->data.money=p->data.money - Money;
                   p->data.show();
               }
               else
		   {
            cout<<"密码错误"<<endl;
		   }
		   flag=1;
		   }
    }
    if(flag==0)
    cout<<"未找到该账户"<<endl;
}

template<class ElemType>
double LinkList<ElemType>::change2()
{
    string search1;
    double Money;
    int flag = 0;
    cout << "请输入需要操作的账号："<<endl;
    cin >> search1;
    string search2;
    Node<ElemType> *p=head;
    for(int i=1;i<=length ;i++)
    {
		p=p->next;
		if(p->data.number==search1)//找账户
		{
		   cout<<"输入密码："<<endl;
		   cin>>search2;
		   if(search2==p->data.password)//找密码
		   {
		       cout<<"输入转账金额："<<endl;
		       cin>>Money;
		       return Money;
		       double x;
		       x=0.01*Money;
		       if(x>=50)
               {
                   x=50;
               }
               Money = Money + x;
			   if(Money>p->data.money)
               {
                   cout<<"转账金额大于当前余额,转账失败。"<<endl;
               }
               else
               {
                   p->data.money=p->data.money - Money;
                   p->data.show();
                   cout<<"转账成功"<<endl; 
               }
		   }

		   else
		   {
            cout<<"密码错误"<<endl;

		   }
		   flag=1;
		}
    }

    if(flag==0) cout<<"未找到该账户"<<endl;
}

template<class ElemType>
void LinkList<ElemType>::change3(double a)
{
    string search1;
    double Money;
    cout << "请输入被转账的账号："<<endl;
    cin >> search1;
    Node<ElemType> *p=head;
    for(int i=1;i<=length ;i++)
    {
		p=p->next;
		if(p->data.number==search1)
		{
			p->data.money=p->data.money+a;
		}
	}
}


template<class ElemType>
void LinkList<ElemType>::showall()//显示
{
	Node<ElemType> *p=head;
	while(p->next!=NULL)
	{
		p=p->next;
		p->data.show();
	}
}
//保存文件
template <class ElemType>
void LinkList<ElemType>::Save(char *filename)
{
	ofstream outfile(filename);
	Node<Bank> *p=head;
	for ( p;p->next!= NULL;)
	{
	    p=p->next;
	 outfile << p->data.name<< "\t"
				<< p->data.number<< "\t"
	     		<< p->data.date<< "\t"
				<< p->data.sex<< "\t"
				<< p->data.password<< "\t"
				<< p->data.money<< "\t"
				<< p->data.state << endl;
		p->data.show();
	}
	outfile.close();
}

//读取文件
template <class ElemType>
void LinkList<ElemType>::Load(char *filename1)
{
	//cout<<"打开文件：";
	//cout<<filename<<endl;
	ifstream infile(filename1);
	//string check;
	length=0;
    Node<ElemType> *q,*p;
    q=new Node <ElemType>();
	while(infile>>q->data.name)
	{
        length++;
		infile 	>> q->data.number
				>> q->data.date
				>> q->data.sex
				>> q->data.password
				>> q->data.money
				>> q->data.state ;
	   for(p=head;p->next!=NULL;p=p->next);
        p->next=q;
        q=new Node <ElemType>();
	}
	infile.close();
}

template <class ElemType>
void LinkList<ElemType>::arrange()
{
	string type;
	Bank temp;
	cout<<"选择排序类型：（账号/金额/开户日期）";
	cin>>type;
	cout<<type<<endl;
	Node<ElemType> *p=head,*q;
	if(type=="账号")
	{
	    for(int i=1;i<length;i++)
	    {
			p=p->next;
			q=p;
			for(int j=i+1;j<=length;j++)
	    	{
				q=q->next;
	    		if(p->data.number>q->data.number)
	    		{
	    			temp=p->data;
					p->data=q->data;
					q->data=temp;
	    		}
	        }

	    }
	}
	if(type=="金额")
	{
	    for(int i=1;i<length;i++)
	    {
			p=p->next;
			q=p;
			for(int j=i+1;j<=length;j++)
	    	{
				q=q->next;
	    		if(p->data.money>q->data.money)
	    		{
	    			temp=p->data;
					p->data=q->data;
					q->data=temp;
	    		}
	        }

	    }
	}
	if(type=="开户日期")
	{
	    for(int i=1;i<length;i++)
	    {
			p=p->next;
			q=p;
			for(int j=i+1;j<=length;j++)
	    	{
				q=q->next;
	    		if(p->data.date>q->data.date)
	    		{
	    			temp=p->data;
					p->data=q->data;
					q->data=temp;
	    		}
	        }

	    }
	}
}

template <class ElemType>
void LinkList<ElemType>::Saving()
{
	string search1;
	string search2;
	double Money;
	cout<<"输入账号：";
	cin>>search1;
	Node<ElemType> *p=head;
	int flag=0;
	for(int i=1;i<=length ;i++)
    {
		p=p->next;
		if(p->data.number==search1)//找账户
		{
		   cout<<"输入密码：";
		   cin>>search2;
		   if(search2==p->data.password)//找密码
		   {
		       cout<<"输入存款金额：";
		       cin>>Money;
			   p->data.money=p->data.money+Money;
		   }
		   else
		   cout<<"密码错误"<<endl;
		   flag=1;
		}
	}
	if(flag==0) cout<<"未找到该账户"<<endl;
}

template <class ElemType>
void LinkList<ElemType>::Drawing()
{
	string search1;
	string search2;
	double Money;
	cout<<"输入账号：";
	cin>>search1;
	Node<ElemType> *p = head;
	int flag=0;
	for(int i=1;i<=length ;i++)
    {
		p=p->next;
		if(p->data.number==search1)//找账户
		{
		   cout<<"输入密码：";
		   cin>>search2;
		   if(search2==p->data.password)//找密码
		   {
		       cout<<"输入取款金额：";
		       cin>>Money;
		       if(p->data.money<Money)
		       cout<<"余额不足";
		       else
			   {
			      p->data.money=p->data.money-Money;
			      cout<<"取款成功";
				  p->data.show();
			   }
		   }
		   else
		   cout<<"密码错误";
		   flag=1;
		}
	}
	if(flag==0) cout<<"未找到该账户"<<endl;
}


template <class ElemType>
LinkList<ElemType>::LinkList()
// 操作结果：构造一个空链表
{
	head = new Node<ElemType>;
	assert(head);
	length = 0;
}

template <class ElemType>
LinkList<ElemType>::LinkList(ElemType v[], int n)
{
    Node<ElemType> *p;
	p = head = new Node<ElemType>;
	assert(head != 0);
	for (int i = 0; i < n; i++) {
	    p->next = new Node<ElemType>(v[i],NULL);
	    assert(p->next);
	    p = p->next;
    }
	length = n;
}

template <class ElemType>
LinkList<ElemType>::~LinkList()
{
	Clear();
	delete head;
}
template <class ElemType>
void LinkList<ElemType>::Clear()
// 操作结果：清空单链表,删除单链表中所有元素结点
{
    Node<ElemType> *p = head->next;
	while (p != NULL) {
		head->next = p->next;
        delete p;
		p = head->next;
	}
	length = 0;
}

template <class ElemType>
void LinkList<ElemType>::Traverse(void (*Visit)(const ElemType &)) const
// 操作结果：依次对单链表的每个元素调用函数(*visit)访问
{
    Node<ElemType> *p = head->next;
	while (p != NULL) {
		(*Visit)(p->data);	// 对单链表中每个元素调用函数(*visit)访问
		p = p->next;
	}
}

template <class ElemType>
void LinkList<ElemType>::showlink()
//查询账户信息
{
	Node<ElemType> *p=head;
	cout<<"请选择输入账号、开户人姓名或开户日期：";
	string search1;
	cin>>search1;
	long search2=0;
	string search="";
	if(search1=="账号"||search1=="开户人姓名")
	{
	cout<<"请输入账号或开户人姓名";
	cin>>search;
	}
	else if(search1=="开户日期")
	{
	cout<<"请输入开户日期：";
	cin>>search2;
	}
	int flag=1;
    for(int i=1;i<=length ;i++)
    {
		p=p->next;
		if(p->data.name==search||p->data.number==search||p->data.date==search2)
		{
		   p->data.show();
		   flag=0;
		}
	}
	if(flag==1)
    {
	     cout<<"未找到该账户"<<endl;
    }
 }

template <class ElemType>
int LinkList<ElemType>::LocateElem(const ElemType &e) const
 //元素定位
{
    Node<ElemType> *p = head->next;
    int count = 1;
	while (p != NULL && (p->data.name!=e.name||p->data.number!=e.number||p->data.sex!=e.sex||
	       p->data.classroom!=e.classroom||p->data.telenum!=e.telenum))
	{
	    count++;
		p = p->next;
	}
    return  (p != NULL) ? count : 0;
}

template <class ElemType>
Status LinkList<ElemType>::GetElem(int i, ElemType &e) const
// 操作结果：当单链表存在第i个元素时，用e返回其值，函数返回ENTRY_FOUND,
//	否则函数返回NOT_PRESENT
{
	if (i < 1 || i > length)
		return RANGE_ERROR;
 	else	{
		Node<ElemType> *p = head->next;
		int count;
		for (count = 1; count < i; count++)
		  p = p->next;	            // p指向第i个结点
		e = p->data;				// 用e返回第i个元素的值
		return ENTRY_FOUND;
	}
}

template <class ElemType>
void LinkList<ElemType>::SetElem()
//修改账户密码
{
	string search1;
	string search2;
	string newpassword;
	cout<<"输入待修改密码账号：";
	cin>>search1;
	Node<ElemType> *p=head;
	int flag=0;
	for(int i=1;i<=length ;i++)
    {
		p=p->next;
		if(p->data.number==search1)//找账户
		{
		   cout<<endl<<"输入密码：";
		   cin>>search2;
		   if(search2==p->data.password)//找密码
		   {
		       cout<<endl<<"输入新密码：";
		       cin>>newpassword;
			   p->data.password=newpassword;
		   }
		   else
		   cout<<"密码错误";
		   flag=1;
		}
	}
	if(flag==0) cout<<"未找到该账户"<<endl;
}

template <class ElemType>
void LinkList<ElemType>::InsertElem()
// 开户
{
	Node<ElemType> *p=head, *q;
	string search;
	int flag=0;
	cout<<"输入账号编号：";
	cin>>search;
	for(int i=1;i<=length ;i++)
    {
		p=p->next;
		if(p->data.number==search)
		{
		   cout<<"账号已存在"<<endl;
		   flag=1;
		}
	}
	if(flag==0)
	{
	q = new Node<ElemType>;             // 生成新结点q
    assert(q);                          // 申请结点失败，终止程序运行
	for (p = head; p->next != NULL; p = p->next) ;	// p指向表尾结点
    p->next = q;                        // 在单链表的表尾位置插入新结点
    getbank(q->data);
	length++;							// 插入成功后，单链表长度加1
    }
}
template<class ElemType>
void LinkList<ElemType>::open()
{
    Node<ElemType> *p=head, *q;
    q = new Node<ElemType>;             // 生成新结点q
    assert(q);                          // 申请结点失败，终止程序运行
	for (p = head; p->next != NULL; p = p->next) ;	// p指向表尾结点
    p->next = q;                        // 在单链表的表尾位置插入新结点
    getbank(q->data);
	length++;
}
template <class ElemType>
void LinkList<ElemType>::DeleteElem()
//销户
{
	string search1;
	string search2;
	Node<ElemType> *p=head,*q;
	int flag=0;
	cout<<"输入待销户账号：";
	cin>>search1;
	if(head->next->data.number==search1)
	{
		   cout<<"输入密码：";
		   cin>>search2;
		   if(search2==head->next->data.password)//找密码
		   {
		        q=head->next;
				head->next=q->next;	      // q指向第i个结点
		        length--;			  // 删除成功后元素个数减1
		        delete q;			  // 删除
		   }
		   else
		   cout<<"密码错误";
		   flag=1;
	}
	for(int i=1;i<length ;i++)
    {
		p=p->next;
		if(p->next->data.number==search1)//找账户
		{
		   cout<<"输入密码：";
		   cin>>search2;
		   if(search2==p->next->data.password)//找密码
		   {
		        q = p->next;	      // q指向第i个结点
		        p->next = q->next;	  // 删除结点
		        length--;			  // 删除成功后元素个数减1
		        delete q;			  // 删除
		   }
		   else
		   cout<<"密码错误";
		   flag=1;
		}
	}
	if(flag==0) cout<<"未找到该账户"<<endl;
}

template <class ElemType>
Status LinkList<ElemType>::InsertElem(int i, const ElemType &e)
// 操作结果：在单链表的第i个位置前插入元素e
//	i的取值范围为1≤i≤length+1
//	i合法时返回SUCCESS, 否则函数返回RANGE_ERROR
{
	if (i < 1 || i > length+1)
		return RANGE_ERROR;
 	else	{
		Node<ElemType> *p = head, *q;
		int count;
		for (count = 1; count < i; count++)
		  p = p->next;	                    // p指向第i-1个结点
		q = new Node<ElemType>(e, p->next); // 生成新结点q
        assert(q);                          // 申请结点失败，终止程序运行
		p->next = q;				        // 将q插入到链表中
		length++;							// 插入成功后，单链表长度加1
		return SUCCESS;
	}
}

template <class ElemType>
Status LinkList<ElemType>::InsertElem(const ElemType &e)
// 产生新账户
{
	Node<ElemType> *p, *q;
	q = new Node<ElemType>(e, NULL);    // 生成新结点q
    assert(q);                          // 申请结点失败，终止程序运行
	for (p = head; p->next != NULL; p = p->next) ;	// p指向表尾结点
    p->next = q;                        // 在单链表的表尾位置插入新结点
	length++;							// 插入成功后，单链表长度加1
	return SUCCESS;
}



#endif


