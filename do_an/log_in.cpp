#include"Header.h"
#include"log_in.h"
#pragma warning(disable : 4996)
void menu()
{
	cout << "1.Dang nhap" << endl;
	cout << "2.Thoat" << endl;
	cout << "Nhap lua chon:";
	int luachon;
	do
	{
		cin >> luachon;
		if (luachon < 1 || luachon>2)
			cout << "Gia tri nhap khong thoa. Moi nhap lai:";
	} while (luachon > 2 || luachon < 1);
	if (luachon == 1)
		log_in();
	else
		return;
}
void log_in()
{
	cout << "DANG NHAP" << endl;
	cout << "Ban la:" << endl;
	cout << "1.Sinh vien" << endl;
	cout << "2.Nhan vien hoc vu" << endl;
	cout << "Nhap lua chon:";
	int luachon;
	do
	{
		cin >> luachon;
		if (luachon < 1 || luachon>2)
			cout << "Gia tri nhap khong thoa. Moi nhap lai:";
	} while (luachon > 2 || luachon < 1);
	char t[50];
	cout << "Ten dang nhap:";
	cin.ignore(100, '\n');
	cin.getline(t, 50);
	char* ten = new char[strlen(t) + 1];
	strcpy(ten, t);
	cout << "Mat khau:";
	cin.getline(t, 50);
	char* matkhau = new char[strlen(t) + 1];
	strcpy(matkhau, t);
	if (luachon == 1)
	{
		fstream f("sinh_vien.txt", ios_base::in);
		char u[50], m[50];
		int co = 0;
		while (!f.eof())
		{
			f >> u >> m;
			if (strcmp(u, ten) == 0 && strcmp(m, matkhau) == 0)
			{
				co = 1;
				break;
			}
			else if (strcmp(u, ten) == 0)
			{
				co = 2;
				break;
			}
		}
		f.close();
		if (co == 1)
		{
			cout << "Dang nhap thanh cong" << endl;
			cout << "Nhan Enter de tiep tuc" << endl;
			cin.get();
			log_in_success(luachon,ten);
		}
		else if (co == 2)
		{
			cout << "Sai mat khau" << endl;
			cout << "Nhan Enter de quay lai" << endl;
			cin.get();
			main();
		}
		else
		{
			cout << "Khong tim thay tai khoan cua ban" << endl;
			cout << "Nhan Enter de quay lai" << endl;
			cin.get();
			main();
		}
	}
	else
	{
		fstream f("nhan_vien.txt", ios_base::in);
		char u[50], m[50];
		int co = 0;
		while (!f.eof())
		{
			f >> u >> m;
			if (strcmp(u, ten) == 0 && strcmp(m, matkhau) == 0)
			{
				co = 1;
				break;
			}
			else if (strcmp(u, ten) == 0)
			{
				co = 2;
				break;
			}
		}
		f.close();
		if (co == 1)
		{
			cout << "Dang nhap thanh cong";
			cout << "Nhan Enter de tiep tuc" << endl;
			cin.get();
			log_in_success(luachon,ten);
		}
		else if (co == 2)
		{
			cout << "Sai mat khau" << endl;
			cout << "Nhan Enter de quay lai" << endl;
			cin.get();
			main();
		}
		else
		{
			cout << "Khong tim thay tai khoan cua ban" << endl;
			cout << "Nhan Enter de quay lai" << endl;
			cin.get();
			main();
		}
	}
	
}
void log_in_success(int luachon,char* ten)
{
	system("cls");
	cout << "MENU CHINH" << endl;
	cout << "1.Xem thong tin" << endl;
	cout << "2.Tai khoan" << endl;
	cout << "3.Chuc nang" << endl;
	cout << "Nhap lua chon:";
	int n=0;
	while (n < 1 || n>3)
	{
		cin >> n;
		if (n < 1 || n>3)
			cout << "Gia tri nhap khong thoa. Moi nhap lai" << endl;
	}
	if (n == 1)
		show_inf(luachon,ten);
	if (n == 2)
		account(luachon,ten);
	//if (luachon == 3)
		//function(luachon);
}
void show_inf(int luachon,char* ten)
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
				fscanf(f, "%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\n]\n", &stt, &id, &f_name, &l_name, &g_tinh, &ngaysinh, &cm);
				if (strcmp(id, ten) == 0)
				{
					cout << "Ma so sinh vien:" << id << endl;
					cout << "Ho va ten:" << f_name << " " << l_name << endl;
					cout << "Gioi tinh:" << g_tinh << endl;
					cout << "Ngay sinh:" << ngaysinh << endl;
					cout << "So CMNND:" << cm << endl;
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
				}
			}
			fclose(f);
		}
	}
}
void account(int luachon,char* ten)
{
	system("cls");
	cout << "TAI KHOAN" << endl;
	cout << "1.Thay doi mat khau" << endl;
	cout << "2.Dang xuat" << endl;
	cout << "Nhap lua chon:";
	int n = 0;
	while (n < 1 || n>3)
	{
		cin >> n;
		if (n < 1 || n>3)
			cout << "Gia tri nhap khong thoa. Moi nhap lai" << endl;
	}
	char pas[50];
	cout << "Nhap mat khau cu:";
	cin >> pas;
	char* pas_o = new char[strlen(pas) + 1];
	strcpy(pas_o, pas);
	cout << "Nhap mat khau moi:";
	cin >> pas;
	char* pas_n = new char[strlen(pas) + 1];
	strcpy(pas_n, pas);
	//Dieu kien cua pas  

	
	if (n == 1)
	{
		change_Pass(luachon, ten, pas_o, pas_n);
	}
}
void change_Pass(int luachon,char* ten, char* pas_o,char* pas_n)
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
		cout << l.pHead->inf.pass;
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
}
void change_Pass_1(int luachon,List& l, char* ten, char* pas_o, char* pas_n)
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
