#include"Header.h"
#include"log_in.h"
#include"show_inf_and_account.h"
#pragma warning(disable : 4996)
/*void menu()
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
}*/
void log_in()
{
	system("cls");
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
	//if (n == 3)
		//function(luachon);
	//sdfsfsd
}
