#include<istream>
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<strstream>
#include<array>
#include<typeinfo>

/*
�����Ǵ��Ҫʵ�ֵĹ���
1. �ڱ����½�log�ļ�(f
2. �ڱ����½�goods.txt�ļ���f
3. �ڱ����½�users.txt�ļ���f
4. �ڵ���"#"Ϊ��ڵ�β��ɨ�赽�� * ��ΪС�ڵ�β��һ���ļ��Ŀ�ͷ�ǡ�~����f
5. ���ڴ��г���һ���½ڵ�֮���Ҫʵʱ�Ľ��б��棬�Է�ֹ���ݵĶ�ʧ
6.������ţ����ļ��в��Ҳ����ն�ά�������ʽ���
7.���ļ�֮�еĸ���Ԫ�ؽ����滻

1. д���������ı�β���������ӽڵ�
2. ����������Ҫ�Ƕ��˺ź���Ʒ���ƽ��п��ٶ�ȡ��ɨ�赽�˺Ŵ����˺ţ���������ȶԣ�����ֵ����
*/


//�ļ� ע�����
using namespace std;


void usersIDwrite_file()//д���û���ID
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

void usersPasswordWrite_file()//д���û�������
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

void usersRead_file()//���ж�ȡ�û�����Ϣ����users.txt�

{
	ifstream file("users.txt");//����һ����file��������
	string line;

	if (file.is_open()) // �кúô�
	{
		while (getline(file, line)) // line�в�����ÿ�еĻ��з�
		{
			cout << line << endl;
		}
	}
	else // û�и��ļ�
	{
		cout << "���ļ������ڻ��޷���" << endl;
	}
}

void usersPasswordRead_file()//��password.txt������û�������(main��������
{
	ifstream file;//����������
	string pw;
	file.open("password.txt");//�������ŵ��ļ�
	if (file.is_open())//���һ����û�кúô�
	{
		while (getline(file, pw))
		{
			cout << pw<<"\n" << endl;//���
			
		}
	}
}

void arrayRead() {
	/* һֱ���ļ���ֱ���������������֮һ��
	 1.�Ѿ���ȡ100���ַ������Ը����ļ���ľ��峤�����ı����鳤��
	 2.�����ַ���*��
	����֮ǰ����ȡ�Ķ���ȫ�����
	*/
	ifstream File("users.txt");
	static char arr[100];//����һ�������������ȡ���Ķ���������


	File.getline(arr, 100, '��');

	cout << arr << endl; //���
	File.close();
}


void goodRead_file()//��good.txt�������Ʒ
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
		memset(buf, 0, 128);//����������� ��������������д���ļ���
		cin >> buf;
		ofile << buf;


	}

	ofile.close();//�ر�
	ifstream ifile("good2.0.txt");//Ȼ������ifstream��
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


/*��������Ķ���д���ļ�
int arr[] = {1,2,3,4,5};
ofstream file;
file.open("good2.0.txt", ios::out);
if (!file)
{
	cerr << "����" << endl;
	exit(1);
}
for (int i = 0; i < sizeof(arr) / sizeof(int); ++i)
{
	file << arr[i] << "";
}
file.close();*/