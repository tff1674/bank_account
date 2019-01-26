#include "Assistance.h"		// 辅助软件包
#include "LinkList.h"		// 单链表类
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
		cout << endl << "1. 读取文件.";
        cout << endl << "2. 查询账户信息.";
        cout << endl << "3. 开户.";
        cout << endl << "4. 修改账户密码.";
        cout << endl << "5. 销户.";
        cout << endl << "6. 存款.";
		cout << endl << "7. 取款";
		cout << endl << "8. 排序";
		cout << endl << "9. 保存文件";
        cout << endl << "a. 转账";
        cout << endl << "b. 利息";
        cout << endl << "c. 保存文件数据";
  		cout << endl << "0. 退出";
		cout << endl << "选择功能:"<<endl;
		cout <<"--------------------------"<<endl;
		cin >> c;
		switch (c)
		{
			case '1':
				char filename[10];
				cout << "输入操作银行:"<<endl;
				scanf("%s",filename);
				la.Load(filename);
				la.showall();
				break;
			case '2'://查询账户信息
			    la.showlink();
			
				break;
			case '3'://开户
			    la.InsertElem();
			    la.Save(filename);
			    break;
			case '4'://修改账户密码
			    la.SetElem();
			    la.Save(filename);
			    break;
			case '5'://销户
			    la.DeleteElem();
			    la.Save(filename);
			    break;
			case '6'://存款
			    la.Saving();
			    la.Save(filename);
			    break;
			case '7'://取款
			    la.Drawing();
			    la.Save(filename);
			    break;
			case '8'://账户排序
			    la.arrange();
			    la.Save(filename);
			    break;
			case '9'://保存文件 ;
				char filename1[10];
				scanf("%s", filename1);
			    la.Save(filename1);
				break;
            case 'a'://转账
                char filename3[10];
                char filename2[10];
                cout << "请输入转账方银行:"<<endl;
                scanf("%s",filename3);
                cout << "请输入被转账方银行:"<<endl;
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
                    la2.Load(filename2);//被转账方
                    la2.change3(a);//被转账金额变化
                }
                la1.Save(filename3);
                la2.Save(filename2);
                break; 
			case 'b'://利息 
        	    double interest;
                la.calculate();
				break;
            case 'c'://保存文件数据 
                LinkList<Bank> la3;
                la3.open();
                cout<<"请输入需要操作的文件名："<<endl;
                char filename4[10];
                scanf("%s",filename4);
                la3.Save(filename4);

		}
	}
	system("PAUSE");        // 调用库函数system()
	return 0;               // 返回值0, 返回操作系统
}
