#include <iostream>

#include "uhash.h"


using namespace std;






int main()
{
	string input;
	const char* char_ptr;
	uhash uh;
	int num;
	while (1)
	{
		cout << "��������Ҫ�������ݿ�����ݣ������˳����˳�ϵͳ�������ӡ�Դ�ӡ��ǰ���ݿ��ڵ����ݣ�" << endl;
		cin >> input;
		if (input == "�˳�")
		{
			break;
		}
		else if (input == "��ӡ")
		{
			uh.print_table();
		}
		else
		{
			cout << "��������Ҫ���������" << endl;
			cin >> num;
			while (cin.good() != 1)
			{
				cin >> num;
				cout << "��������������Ϲ淶������������:";
				cin.clear();
				while (cin.get() != '\n')
					continue;
			}
			uh.new_key(input, num);
		}
	}





}
