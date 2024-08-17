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
		cout << "请输入需要存入数据库的内容（输入退出以退出系统，输入打印以打印当前数据库内的内容）" << endl;
		cin >> input;
		if (input == "退出")
		{
			break;
		}
		else if (input == "打印")
		{
			uh.print_table();
		}
		else
		{
			cout << "请输入需要存入的数量" << endl;
			cin >> num;
			while (cin.good() != 1)
			{
				cin >> num;
				cout << "输入的数量不符合规范，请重新输入:";
				cin.clear();
				while (cin.get() != '\n')
					continue;
			}
			uh.new_key(input, num);
		}
	}





}
