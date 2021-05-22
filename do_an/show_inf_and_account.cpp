#include"show_inf_and_account.h"
#include"log_in.h"
#pragma warning(disable : 4996)
void show_inf(int luachon, char* ten)
{
	system("cls");
	cout << "THONG TIN CA NHAN" << endl;
	if (luachon == 1)
	{
		FILE* f = fopen("thong_tin_sv.csv", "rt");
		char stt[3], id[20], f_name[20], l_name[10], g_tinh[10], ngaysinh[40], cm[10];
		if (f != NULL)
		{
			while (1)
			{
				int a = fscanf(f, "%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\n]\n", &stt, &id, &f_name, &l_name, &g_tinh, &ngaysinh, &cm);
				if (strcmp(id, ten) == 0)
				{
					cout << "Ma so sinh vien:" << id << endl;
					cout << "Ho va ten:" << f_name << " " << l_name << endl;
					cout << "Gioi tinh:" << g_tinh << endl;
					cout << "Ngay sinh:" << ngaysinh << endl;
					cout << "So CMNND:" << cm << endl;
					break;
				}
			}
			fclose(f);
		}
	}
	else
	{
		FILE* f = fopen("thong_tin_nv.csv", "rt");
		char stt[3], id[20], f_name[20], l_name[10], g_tinh[10], ngaysinh[40], cm[10];
		if (f != NULL)
		{
			while (1)
			{
				fscanf(f, "%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\n]\n", &stt, &id, &f_name, &l_name, &g_tinh, &ngaysinh, &cm);
				if (strcmp(id, ten) == 0)
				{
					cout << "Ma so nhan vien:" << id << endl;
					cout << "Ho va ten:" << f_name << " " << l_name << endl;
					cout << "Gioi tinh:" << g_tinh << endl;
					cout << "Ngay sinh:" << ngaysinh << endl;
					cout << "So CMNND:" << cm << endl;
					break;
				}
			}
			fclose(f);
		}
	}
	cout << setw(25) << left << "-" << endl;
	cout << "Nhan Enter de quay ve" << endl;
	cin.ignore(100, '\n');
	cin.get();
	log_in_success(luachon, ten);
}
void account(int luachon, char* ten)
{
	system("cls");
	cout << "TAI KHOAN" << endl;
	cout << "1.Thay doi mat khau" << endl;
	cout << "2.Dang xuat" << endl;
	cout << "3.Tro ve" << endl;
	cout << "Nhap lua chon:";
	int n = 0;
	while (n < 1 || n>4)
	{
		cin >> n;
		if (n < 1 || n>4)
			cout << "Gia tri nhap khong thoa. Moi nhap lai" << endl;
	}
	
	if (n == 1)
	{
		char pas[50];
		cout << "Nhap mat khau cu:";
		cin >> pas;
		char* pas_o = new char[strlen(pas) + 1];
		strcpy(pas_o, pas);
		cout << "Nhap mat khau moi:";
		cin.ignore(100, '\n');
		cin.getline(pas, 50);
		//Dieu kien cua pass
	KT:
		int length = strlen(pas);
		for (int i = 0; i < length; i++)
		{
			if (pas[i] == ' ')
			{
				cout << "Mat khau khong hop le." << endl;
				cout << "Moi nhap lai:";
				cin.getline(pas, 50);
				goto KT;
			}
		}
		char* pas_n = new char[strlen(pas) + 1];
		strcpy(pas_n, pas);
		change_Pass(luachon, ten, pas_o, pas_n);
	}
	else if (n == 2)
	{
		log_in();
	}
	else
		log_in_success(luachon, ten);
}
void change_Pass(int luachon, char* ten, char* pas_o, char* pas_n)
{

	if (luachon == 1)
	{
		fstream f("sinh_vien.txt", ios_base::in);
		char u[50], m[50];
		List l;
		CreateList(l);
		while (!f.eof())
		{
			f >> u >> m;
			Node* node = CreateNode(u, m);
			addLast(l, node);
		}
		f.close();
		change_Pass_1(luachon, l, ten, pas_o, pas_n);
		fstream f1("sinh_vien.txt", ios_base::out);
		if (l.pHead != NULL)
		{
			Node* node = l.pHead;
			while (node != NULL)
			{
				f1 << node->inf.id << ' ' << node->inf.pass << endl;
				node = node->pNext;
			}
		}
		f1.close();
	}
	else
	{
		fstream f("nhan_vien.txt", ios_base::in);
		char u[50], m[50];
		List l;
		CreateList(l);
		while (!f.eof())
		{
			f >> u >> m;
			Node* node = CreateNode(u, m);
			addLast(l, node);
		}
		f.close();
		change_Pass_1(luachon, l, ten, pas_o, pas_n);
		fstream f1("nhan_vien.txt", ios_base::out);
		if (l.pHead != NULL)
		{
			Node* node = l.pHead;
			while (node != NULL)
			{
				f1 << node->inf.id << ' ' << node->inf.pass << endl;
				node = node->pNext;
			}
		}
		f1.close();
	}
	cout << setw(50) << left << "-" << endl;
	cout << "Doi mat khau thanh cong. Nhan Enter de quay ve" << endl;
	//cin.ignore(100, '\n');
	cin.get();
	account(luachon, ten);
}
void change_Pass_1(int luachon, List& l, char* ten, char* pas_o, char* pas_n)
{
	if (l.pHead != NULL)
	{
		Node* node = l.pHead;
		while (node != NULL)
		{
			if (strcmp(node->inf.id, ten) == 0)
			{
				if (strcmp(node->inf.pass, pas_o) == 0)
					strcpy(node->inf.pass, pas_n);
				else
				{
					cout << "Mat khau cu khong dung" << endl;
					cout << "Press Enter to back" << endl;
					cin.get();
					account(luachon, ten);
				}
			}
			node = node->pNext;
		}
	}
}
void CreateList(List& l)
{
	l.pHead = NULL;
	l.pTail = NULL;
}
Node* CreateNode(char u[], char m[])
{
	Node* node = new Node;
	node->inf.id = new char[strlen(u) + 1];
	node->inf.pass = new char[strlen(m) + 1];
	strcpy(node->inf.id, u);
	strcpy(node->inf.pass, m);
	node->pNext = NULL;
	return node;
}
void addLast(List& l, Node* node)
{
	if (l.pHead == NULL)
	{
		l.pHead = node;
		l.pTail = node;
	}
	else
	{
		l.pTail->pNext = node;
		l.pTail = node;
	}
}
