#include "Assistance.h"		// ���������
#include "LinkList.h"		// ��������
#include <iostream>
#include <fstream>
#include <string>
#include<string.h>
#include"Node.h"
#include<cstdio>
using namespace std;


int main(void)
{
	char c;
    LinkList<Bank> la,la2,la1;
    Bank ba,check;
    string e;

    while (c != '0')
	{
        cout <<"--------------------------";
		cout << endl << "1. ��ȡ�ļ�.";
        cout << endl << "2. ��ѯ�˻���Ϣ.";
        cout << endl << "3. ����.";
        cout << endl << "4. �޸��˻�����.";
        cout << endl << "5. ����.";
        cout << endl << "6. ���.";
		cout << endl << "7. ȡ��";
		cout << endl << "8. ����";
		cout << endl << "9. �����ļ�";
        cout << endl << "a. ת��";
        cout << endl << "b. ��Ϣ";
        cout << endl << "c. �����ļ�����";
  		cout << endl << "0. �˳�";
		cout << endl << "ѡ����:"<<endl;
		cout <<"--------------------------"<<endl;
		cin >> c;
		switch (c)
		{
			case '1':
				char filename[10];
				cout << "�����������:"<<endl;
				scanf("%s",filename);
				la.Load(filename);
				la.showall();
				break;
			case '2'://��ѯ�˻���Ϣ
			    la.showlink();
			
				break;
			case '3'://����
			    la.InsertElem();
			    la.Save(filename);
			    break;
			case '4'://�޸��˻�����
			    la.SetElem();
			    la.Save(filename);
			    break;
			case '5'://����
			    la.DeleteElem();
			    la.Save(filename);
			    break;
			case '6'://���
			    la.Saving();
			    la.Save(filename);
			    break;
			case '7'://ȡ��
			    la.Drawing();
			    la.Save(filename);
			    break;
			case '8'://�˻�����
			    la.arrange();
			    la.Save(filename);
			    break;
			case '9'://�����ļ� ;
				char filename1[10];
				scanf("%s", filename1);
			    la.Save(filename1);
				break;
            case 'a'://ת��
                char filename3[10];
                char filename2[10];
                cout << "������ת�˷�����:"<<endl;
                scanf("%s",filename3);
                cout << "�����뱻ת�˷�����:"<<endl;
                scanf("%s",filename2);
                if(strcmp(filename3,filename2)==0)
                {
                    la1.Load(filename3);
                    la1.change1();
                }
                else
                {
                    double a;
					la1.Load(filename3);
                    a=la1.change2();
                    la2.Load(filename2);//��ת�˷�
                    la2.change3(a);//��ת�˽��仯
                }
                la1.Save(filename3);
                la2.Save(filename2);
                break; 
			case 'b'://��Ϣ 
        	    double interest;
                la.calculate();
				break;
            case 'c'://�����ļ����� 
                LinkList<Bank> la3;
                la3.open();
                cout<<"��������Ҫ�������ļ�����"<<endl;
                char filename4[10];
                scanf("%s",filename4);
                la3.Save(filename4);

		}
	}
	system("PAUSE");        // ���ÿ⺯��system()
	return 0;               // ����ֵ0, ���ز���ϵͳ
}
