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
struct gv {
	char id;
	char ten;
	char ho;
	char gioitinh;
};
struct sv {
	int no;
	char mssv;
	char ten;
	char ho;
	char gioitinh;
	sv* next;

};
struct monhoc {
	sv* head;
	gv giaovien;
	char ten[50];
	char thoigian;
	char ngay;
	monhoc* next;
};
struct hocki {
	monhoc* head;

};
struct namhoc {
	hocki* hk;
};
void log_in_success(int luachon,char* ten)
{
	system("cls");
	cout << "MENU CHINH" << endl;
	cout << "1.Xem thong tin" << endl;
	cout << "2.Tai khoan" << endl;
	cout << "3.tao nam hoc" << endl;
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
	if (n == 3)
	{

		chucNangNv(luachon);
	}
}

void chucNangNv(int luachon)
{
	cout << "1.Tao nam hoc moi" << endl;
	cout << "2.Tao hoc ky va cac mon hoc" << endl;
	cout << "Nhap lua chon:";
	int choos;
	cin >> choos;
	if(choos==1)
		taoNamHoc();
	if (choos == 2)
		taoHocKi();

}
void taoNamHoc()
{
	int thang, nam;
	timeNow(thang, nam);
	if (thang != 8)
		cout << "Khong phai thoi gian de tao nam hoc moi" << endl;
	else {
		FILE* f1 = fopen("danhsachnamhoc.txt", "w+");
		int co = 1;
		if (f1 != NULL)
		{
			int namhocTruoc;
			while (!feof(f1))
			{
				fscanf(f1, "%d\n", &namhocTruoc);
				if (namhocTruoc == nam)
				{
					co = 0;
					break;
				}
				if (feof(f1))
					break;
			}
			fprintf(f1, "%d\n", nam);
			fclose(f1);
		}
		
		if (co == 0)
		{
			cout << "NAM HOC MOI DA DUOC TAO TRUOC DAY" << endl;
			return;

			//xu ly quay lai

		}
		char* namhoc = new char[30];
		itoa(nam, namhoc,10);
		_mkdir(namhoc);
		char* tenThumuc = new char[60];
		
		strcpy(tenThumuc, namhoc);
		strcat(namhoc, "/DSLop.txt");

		FILE* f = fopen(namhoc, "w");
		if (f != NULL)
		{
			cout << "Nhap so luong lop cua sinh vien nam 1:" << endl;
			int num;
			cin >> num;

			cout << "Nhap ten cac lop:" << endl;
			char* nameClass = new char[100];
			for (int i = 0; i < num; i++)
			{
				char* temp = new char[100];
				strcpy(temp, tenThumuc);
				cout << i+1 <<".";
				cin.ignore();
				cin.getline(nameClass, 100);
				char* source = new char[100];
				cout << "Duong dan den file CSV chua thong tin cua lop:";
				cin.getline(source, 100);

				strcat(temp, "/");
				strcat(temp, nameClass);
				strcat(temp, ".csv");
				//doiDuongDan(source);
				copyFile(source,temp);
				delete[] temp;

				fprintf(f, "%s\t", nameClass);
			}

			FILE* f3 = fopen("danhsachnamhoc.txt", "r");
			if (f3 != NULL)
			{
				char* tenNamHoc = new char[4];
				while (!feof(f3))
				{
					fscanf(f3, "%s\n", &tenNamHoc);
					strcat(tenNamHoc, ".txt");
					FILE* f4 = fopen(tenNamHoc, "r");
					if (f4 != NULL)
					{
						char* tenLop = new char[10];
						while (!feof(f4))
						{
							fscanf(f4, "%s\t", &tenLop);
							fprintf(f, "%s\t", tenLop);
						}
						fclose(f4);
					}

				}
				fclose(f3);
			}
		}
	}
 }
void timeNow(int& thang,int& nam)
{
	time_t now = time(0);
	tm* ltm = localtime(&now);
	nam= 1900 + ltm->tm_year ;
	thang= 1 + ltm->tm_mon ;
}

void taoHocKi()
{
	FILE* f = fopen("danhsachnamhoc.txt", "r");
	fseek(f, -8, SEEK_END);
	int nam;
	fscanf(f, "%d\n", &nam);
	fclose(f);
	char* namstr = new char[4];
	itoa(nam, namstr, 10);
	char hocKy[100] = "danhsachhockynam";
	strcat(hocKy, namstr);
	strcat(hocKy, ".txt");
	FILE* f1 = fopen(hocKy, "r");
	int num;
	if (f1 == NULL)
	{
		FILE* f2 = fopen(hocKy, "a");
		fprintf(f2, "%d", 1);
		fclose(f2);
		cout << "Tao hoc ky 1 cho nam hoc " << nam << " thanh cong" << endl;
		taoMonHoc();
	}
	else
	{
		fseek(f1, -4, SEEK_END);
		int cur;
		fscanf(f1, "%d", &cur);
		fclose(f1);
		if (cur == 3)
		{
			cout << "Tao hoc ky khong thanh cong!" << endl;
			cout << "Nam hoc " << nam << " da du 3 ky" << endl;


			//Quay tro lai...........


		}
		else
		{
			cur++;
			FILE* f2 = fopen(hocKy, "a");
			fprintf(f2, "\t%d", cur);
			fclose(f2);
			cout << "Tao hoc ky " << cur << " cho nam hoc " << nam << " thanh cong" << endl;
			fclose(f1);
			taoMonHoc();



		}


	}
}

struct monHoc
{
	char* id = new char[10];
	char* name = new char[30];
	int tinchi;
	int slSV;
	int thu[2];
	char* gio = new char[5];
};
void taoMonHoc()
{
	cout << "Nhap so luong mon hoc can tao:" << endl;
	int soluong;
	cin >> soluong;
}

int copyFile( char* file_src,  char* file_dis)
{
	char* buffer;
	FILE* fn = fopen(file_src, "rb");
	if (!fn)
		return 0;
	fseek(fn, 0, SEEK_END);
	int size = ftell(fn);
	buffer = new char[size];
	fseek(fn, 0, SEEK_SET);
	

	FILE* f1 = fopen(file_dis, "wb");
	while (!feof(fn))
	{
		fread(&buffer, sizeof(buffer), 1, fn);
		if (feof(fn))
			break;
		fwrite(&buffer, sizeof(buffer), 1, f1);
	}
	fclose(fn);
	fclose(f1);
	return 1;
}
void doiDuongDan(char* source)
{
	int len = strlen(source);
	for (int i = 0; i < len; i++)
	{
		if (strcmp((const char*)source[i], "\\") == 0)
			source[i] = '/';
	}
}