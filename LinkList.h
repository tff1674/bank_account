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
	void Clear();						// �����������
	void Traverse(void (*Visit)(const ElemType &)) const;// ����������
	int LocateElem(const ElemType &e) const;	         // Ԫ�ض�λ
	void Saving();           //���
	void Drawing();           //ȡ��
	Status GetElem(int position, ElemType &e) const;	 // ��ָ��λ�õ�Ԫ��
	void SetElem();	 // ����ָ��λ�õ�Ԫ��ֵ
	void DeleteElem();		 // ɾ��Ԫ��
	Status InsertElem(int position, const ElemType &e);	 // ���ƶ�λ�ò���Ԫ��
	void InsertElem();	                              //����
	Status InsertElem(const ElemType &e);                // �ڱ�β����Ԫ��
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
void LinkList<ElemType>::calculate()//��Ϣ
{
    long delta,end_year;
    double interest;
    int years;
    cout<<"��������Ҫ��ѯ����Ϣ�˺ţ�";
	string search1;
	cin>>search1;
	Node<ElemType> *p=head;
    for(int i=1;i<=length ;i++)
    {
		p=p->next;
		if(p->data.number==search1)//���˻�
		{
           cout<<"���������ʱ�䣺";
    	   cin>>end_year;
           delta=end_year-p->data.date;
           if(delta<0)
		   {
             cout<<"ʱ�����"<<endl;
           }
           else if(delta==0)
		   {
             cout<<"��ϢΪ0"<<endl;
           }
           else if(delta%10000==0)
	       {
             years = delta/10000;
             if(p->data.state=="����")
		     {
               interest=years*p->data.money*0.0035;
             }
             if(p->data.state=="����")
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
              cout<<"��ϢΪ��"<<interest<<endl;
           }
           else if(delta%10000!=0)
		   {
             years = int(delta/10000)+0.5;
             if(p->data.state=="����")
		     {
               interest=years*p->data.money*0.0035;
             }
             if(p->data.state=="����")
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
             cout<<"��ϢΪ��"<<interest<<endl;
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
    cout<< "��������Ҫ�������˺ţ�"<<endl;
    cin >> search1;
    string search2;
    Node<ElemType> *p=head;
    for(int i=1;i<=length ;i++)
    {
		p=p->next;
		if(p->data.number==search1)//���˻�
		{
		   cout<<"�������룺"<<endl;
		   cin>>search2;
		   if(search2==p->data.password)//������
		   {
		       cout<<"����ת�˽�"<<endl;
		       cin>>Money;
			   if(Money>p->data.money)
               {
                   cout<<"ת�˽����ڵ�ǰ���,ת��ʧ�ܡ�"<<endl;
               }
               else
          flag=1;         p->data.money=p->data.money - Money;
                   p->data.show();
               }
               else
		   {
            cout<<"�������"<<endl;
		   }
		   flag=1;
		   }
    }
    if(flag==0)
    cout<<"δ�ҵ����˻�"<<endl;
}

template<class ElemType>
double LinkList<ElemType>::change2()
{
    string search1;
    double Money;
    int flag = 0;
    cout << "��������Ҫ�������˺ţ�"<<endl;
    cin >> search1;
    string search2;
    Node<ElemType> *p=head;
    for(int i=1;i<=length ;i++)
    {
		p=p->next;
		if(p->data.number==search1)//���˻�
		{
		   cout<<"�������룺"<<endl;
		   cin>>search2;
		   if(search2==p->data.password)//������
		   {
		       cout<<"����ת�˽�"<<endl;
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
                   cout<<"ת�˽����ڵ�ǰ���,ת��ʧ�ܡ�"<<endl;
               }
               else
               {
                   p->data.money=p->data.money - Money;
                   p->data.show();
                   cout<<"ת�˳ɹ�"<<endl; 
               }
		   }

		   else
		   {
            cout<<"�������"<<endl;

		   }
		   flag=1;
		}
    }

    if(flag==0) cout<<"δ�ҵ����˻�"<<endl;
}

template<class ElemType>
void LinkList<ElemType>::change3(double a)
{
    string search1;
    double Money;
    cout << "�����뱻ת�˵��˺ţ�"<<endl;
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
void LinkList<ElemType>::showall()//��ʾ
{
	Node<ElemType> *p=head;
	while(p->next!=NULL)
	{
		p=p->next;
		p->data.show();
	}
}
//�����ļ�
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

//��ȡ�ļ�
template <class ElemType>
void LinkList<ElemType>::Load(char *filename1)
{
	//cout<<"���ļ���";
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
	cout<<"ѡ���������ͣ����˺�/���/�������ڣ�";
	cin>>type;
	cout<<type<<endl;
	Node<ElemType> *p=head,*q;
	if(type=="�˺�")
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
	if(type=="���")
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
	if(type=="��������")
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
	cout<<"�����˺ţ�";
	cin>>search1;
	Node<ElemType> *p=head;
	int flag=0;
	for(int i=1;i<=length ;i++)
    {
		p=p->next;
		if(p->data.number==search1)//���˻�
		{
		   cout<<"�������룺";
		   cin>>search2;
		   if(search2==p->data.password)//������
		   {
		       cout<<"�������";
		       cin>>Money;
			   p->data.money=p->data.money+Money;
		   }
		   else
		   cout<<"�������"<<endl;
		   flag=1;
		}
	}
	if(flag==0) cout<<"δ�ҵ����˻�"<<endl;
}

template <class ElemType>
void LinkList<ElemType>::Drawing()
{
	string search1;
	string search2;
	double Money;
	cout<<"�����˺ţ�";
	cin>>search1;
	Node<ElemType> *p = head;
	int flag=0;
	for(int i=1;i<=length ;i++)
    {
		p=p->next;
		if(p->data.number==search1)//���˻�
		{
		   cout<<"�������룺";
		   cin>>search2;
		   if(search2==p->data.password)//������
		   {
		       cout<<"����ȡ���";
		       cin>>Money;
		       if(p->data.money<Money)
		       cout<<"����";
		       else
			   {
			      p->data.money=p->data.money-Money;
			      cout<<"ȡ��ɹ�";
				  p->data.show();
			   }
		   }
		   else
		   cout<<"�������";
		   flag=1;
		}
	}
	if(flag==0) cout<<"δ�ҵ����˻�"<<endl;
}


template <class ElemType>
LinkList<ElemType>::LinkList()
// �������������һ��������
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
// �����������յ�����,ɾ��������������Ԫ�ؽ��
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
// ������������ζԵ������ÿ��Ԫ�ص��ú���(*visit)����
{
    Node<ElemType> *p = head->next;
	while (p != NULL) {
		(*Visit)(p->data);	// �Ե�������ÿ��Ԫ�ص��ú���(*visit)����
		p = p->next;
	}
}

template <class ElemType>
void LinkList<ElemType>::showlink()
//��ѯ�˻���Ϣ
{
	Node<ElemType> *p=head;
	cout<<"��ѡ�������˺š������������򿪻����ڣ�";
	string search1;
	cin>>search1;
	long search2=0;
	string search="";
	if(search1=="�˺�"||search1=="����������")
	{
	cout<<"�������˺Ż򿪻�������";
	cin>>search;
	}
	else if(search1=="��������")
	{
	cout<<"�����뿪�����ڣ�";
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
	     cout<<"δ�ҵ����˻�"<<endl;
    }
 }

template <class ElemType>
int LinkList<ElemType>::LocateElem(const ElemType &e) const
 //Ԫ�ض�λ
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
// �������������������ڵ�i��Ԫ��ʱ����e������ֵ����������ENTRY_FOUND,
//	����������NOT_PRESENT
{
	if (i < 1 || i > length)
		return RANGE_ERROR;
 	else	{
		Node<ElemType> *p = head->next;
		int count;
		for (count = 1; count < i; count++)
		  p = p->next;	            // pָ���i�����
		e = p->data;				// ��e���ص�i��Ԫ�ص�ֵ
		return ENTRY_FOUND;
	}
}

template <class ElemType>
void LinkList<ElemType>::SetElem()
//�޸��˻�����
{
	string search1;
	string search2;
	string newpassword;
	cout<<"������޸������˺ţ�";
	cin>>search1;
	Node<ElemType> *p=head;
	int flag=0;
	for(int i=1;i<=length ;i++)
    {
		p=p->next;
		if(p->data.number==search1)//���˻�
		{
		   cout<<endl<<"�������룺";
		   cin>>search2;
		   if(search2==p->data.password)//������
		   {
		       cout<<endl<<"���������룺";
		       cin>>newpassword;
			   p->data.password=newpassword;
		   }
		   else
		   cout<<"�������";
		   flag=1;
		}
	}
	if(flag==0) cout<<"δ�ҵ����˻�"<<endl;
}

template <class ElemType>
void LinkList<ElemType>::InsertElem()
// ����
{
	Node<ElemType> *p=head, *q;
	string search;
	int flag=0;
	cout<<"�����˺ű�ţ�";
	cin>>search;
	for(int i=1;i<=length ;i++)
    {
		p=p->next;
		if(p->data.number==search)
		{
		   cout<<"�˺��Ѵ���"<<endl;
		   flag=1;
		}
	}
	if(flag==0)
	{
	q = new Node<ElemType>;             // �����½��q
    assert(q);                          // ������ʧ�ܣ���ֹ��������
	for (p = head; p->next != NULL; p = p->next) ;	// pָ���β���
    p->next = q;                        // �ڵ�����ı�βλ�ò����½��
    getbank(q->data);
	length++;							// ����ɹ��󣬵������ȼ�1
    }
}
template<class ElemType>
void LinkList<ElemType>::open()
{
    Node<ElemType> *p=head, *q;
    q = new Node<ElemType>;             // �����½��q
    assert(q);                          // ������ʧ�ܣ���ֹ��������
	for (p = head; p->next != NULL; p = p->next) ;	// pָ���β���
    p->next = q;                        // �ڵ�����ı�βλ�ò����½��
    getbank(q->data);
	length++;
}
template <class ElemType>
void LinkList<ElemType>::DeleteElem()
//����
{
	string search1;
	string search2;
	Node<ElemType> *p=head,*q;
	int flag=0;
	cout<<"����������˺ţ�";
	cin>>search1;
	if(head->next->data.number==search1)
	{
		   cout<<"�������룺";
		   cin>>search2;
		   if(search2==head->next->data.password)//������
		   {
		        q=head->next;
				head->next=q->next;	      // qָ���i�����
		        length--;			  // ɾ���ɹ���Ԫ�ظ�����1
		        delete q;			  // ɾ��
		   }
		   else
		   cout<<"�������";
		   flag=1;
	}
	for(int i=1;i<length ;i++)
    {
		p=p->next;
		if(p->next->data.number==search1)//���˻�
		{
		   cout<<"�������룺";
		   cin>>search2;
		   if(search2==p->next->data.password)//������
		   {
		        q = p->next;	      // qָ���i�����
		        p->next = q->next;	  // ɾ�����
		        length--;			  // ɾ���ɹ���Ԫ�ظ�����1
		        delete q;			  // ɾ��
		   }
		   else
		   cout<<"�������";
		   flag=1;
		}
	}
	if(flag==0) cout<<"δ�ҵ����˻�"<<endl;
}

template <class ElemType>
Status LinkList<ElemType>::InsertElem(int i, const ElemType &e)
// ����������ڵ�����ĵ�i��λ��ǰ����Ԫ��e
//	i��ȡֵ��ΧΪ1��i��length+1
//	i�Ϸ�ʱ����SUCCESS, ����������RANGE_ERROR
{
	if (i < 1 || i > length+1)
		return RANGE_ERROR;
 	else	{
		Node<ElemType> *p = head, *q;
		int count;
		for (count = 1; count < i; count++)
		  p = p->next;	                    // pָ���i-1�����
		q = new Node<ElemType>(e, p->next); // �����½��q
        assert(q);                          // ������ʧ�ܣ���ֹ��������
		p->next = q;				        // ��q���뵽������
		length++;							// ����ɹ��󣬵������ȼ�1
		return SUCCESS;
	}
}

template <class ElemType>
Status LinkList<ElemType>::InsertElem(const ElemType &e)
// �������˻�
{
	Node<ElemType> *p, *q;
	q = new Node<ElemType>(e, NULL);    // �����½��q
    assert(q);                          // ������ʧ�ܣ���ֹ��������
	for (p = head; p->next != NULL; p = p->next) ;	// pָ���β���
    p->next = q;                        // �ڵ�����ı�βλ�ò����½��
	length++;							// ����ɹ��󣬵������ȼ�1
	return SUCCESS;
}



#endif


