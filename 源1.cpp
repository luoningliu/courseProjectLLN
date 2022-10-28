#include<istream>
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<strstream>
#include<array>
#include<typeinfo>

/*
以下是大概要实现的功能
1. 在本地新建log文件(f
2. 在本地新建goods.txt文件（f
3. 在本地新建users.txt文件（f
4. 节点以"#"为大节点尾，扫描到” * “为小节点尾，一个文件的开头是“~”（f
5. 在内存中出现一个新节点之后就要实时的进行保存，以防止内容的丢失
6.输入序号，从文件中查找并按照二维数组的形式输出
7.对文件之中的给定元素进行替换

1. 写函数，对文本尾部进行增加节点
2. 读函数，主要是对账号和商品名称进行快速读取，扫描到账号传出账号，再与密码比对，返回值随意
*/


//文件 注意类别
using namespace std;


void usersIDwrite_file()//写入用户的ID
{
	ofstream file;
	file.open("users.txt", ios::app);
	if (file.is_open())
	{
		int a;
		cin >> a;
		file << a << endl;


	}
	file.close();

}

void usersPasswordWrite_file()//写入用户的密码
{
	ofstream file;
	file.open("password.txt", ios::app);
	if (file.is_open())
	{
		string pw;
		cin >> pw;
		file << pw << endl;


	}
	file.close();

}

void usersRead_file()//按行读取用户的消息（从users.txt里）

{
	ifstream file("users.txt");//创建一个叫file的流对象
	string line;

	if (file.is_open()) // 有好好打开
	{
		while (getline(file, line)) // line中不包括每行的换行符
		{
			cout << line << endl;
		}
	}
	else // 没有该文件
	{
		cout << "该文件不存在或无法打开" << endl;
	}
}

void usersPasswordRead_file()//从password.txt里读出用户的密码(main能跑起来
{
	ifstream file;//创建流对象
	string pw;
	file.open("password.txt");//打开密码存放的文件
	if (file.is_open())//检查一下有没有好好打开
	{
		while (getline(file, pw))
		{
			cout << pw<<"\n" << endl;//输出
			
		}
	}
}

void arrayRead() {
	/* 一直读文件，直到满足下面的条件之一：
	 1.已经读取100个字符（可以根据文件里的具体长度来改变数组长度
	 2.遇到字符“*”
	最后把之前所读取的东西全部输出
	*/
	ifstream File("users.txt");
	static char arr[100];//建立一个用来存放所读取出的东西的数组


	File.getline(arr, 100, '宁');

	cout << arr << endl; //输出
	File.close();
}


void goodRead_file()//从good.txt里读出商品
{
	ifstream file2;
	string _str;
	file2.open("good.txt");
	if (file2.is_open())
	{
		while (getline(file2, _str))
		{
			if (_str == "~")
				cout << "_str" << endl;
		}
	}
}

void write_file()
{
	char buf[128];
	ofstream ofile("good2.0.txt");
	for (int i = 0; i < 5; i++) {
		memset(buf, 0, 128);//输入五次数据 程序把这五次数据写入文件中
		cin >> buf;
		ofile << buf;


	}

	ofile.close();//关闭
	ifstream ifile("good2.0.txt");//然后再用ifstream打开
	while (!ifile.eof()) {

		char ch;
		ifile.get(ch);
		if (!ifile.eof())
			cout << ch;
	}
	cout << endl;
	ifile.close();

}



class users
{
private:
	int ID;
	string password;
};

class admin
{

};

class gamble
{
	int a[1000];
};

class good
{
private:
	int ID;
	string name;
	double price;
	int num;
};



int main()
{
	string a[2][6] = { 0 };
	ifstream file;
	file.open("user.txt");
	for (int i = 1; i < 3; i++)
	{
		for (int j = 1; j < 6; j++)
		{
			file >> a[i][j];
		}
	}
	file.close();
	for (int i = 1; i < 3; i++)
	{
		for (int j = 1; j < 6; j++)
		{
			cout<< a[i][j];
		}
	}
	return 0;
}


/*把数组里的东西写进文件
int arr[] = {1,2,3,4,5};
ofstream file;
file.open("good2.0.txt", ios::out);
if (!file)
{
	cerr << "啊这" << endl;
	exit(1);
}
for (int i = 0; i < sizeof(arr) / sizeof(int); ++i)
{
	file << arr[i] << "";
}
file.close();*/