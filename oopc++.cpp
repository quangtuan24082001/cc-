#include<iostream>
#include<string>
#include <fstream>
#include<iomanip>
using namespace std;


//class thong tin chung
class ThongTin {
protected:
	string HoTen;
	string GioiTinh;
	string NgaySinh;
	string DiaChi;
	string SDT;

public:
	void Nhap();
	void Xuat();
	string GetName() {
		return HoTen;
	}

	ThongTin();
	~ThongTin();
};

//Ham nhap
void ThongTin::Nhap() {
	while (getchar() != '\n');
	cout << "\n\tNhap ho ten: ";
	getline(cin, HoTen);
	cout << "\n\tNhap ngay sinh: ";
	getline(cin, NgaySinh);
	cout << "\n\tNhap gioi tinh: ";
	getline(cin, GioiTinh);
	cout << "\n\tNhap dia chi: ";
	getline(cin, DiaChi);
	cout << "\n\tNhap sdt: ";
	getline(cin, SDT);

}

// Ham xuat
void ThongTin::Xuat() {
	
	cout << "\t" << HoTen << "\t" << GioiTinh << "\t\t" << NgaySinh << "\t\t" << DiaChi << "\t" <<SDT ;
}
ThongTin::ThongTin() {}
ThongTin::~ThongTin() {}

//------------------------------------------------
//class Bac si
class BacSi :public ThongTin
{
private:
	float LuongThucTe;
	float HeSoLuong;
	float  LuongCoBan;


public:
	void Nhap();
	void Xuat();
	void TimKiemBS();
	void XoaBacSi(BacSi* ds_BS[], int& n);
	void SapXepBS(BacSi* ds_BS[], int n);
	void GhiFileBS(BacSi* ds_BS[], int  n);
	void CapNhatBS(BacSi* ds_BS[], int n);
	float TinhLuong();

	BacSi();
	~BacSi();
};
BacSi::BacSi() {}
BacSi::~BacSi() {}

//Ham nhap bac si
void BacSi::Nhap() {
	ThongTin::Nhap();
	cout << "\n\tNhap luong co ban: ";
	cin >> LuongCoBan;
	cout << "\n\tNhap he so luong: ";
	cin >> HeSoLuong;
}
// Ham tinh luong bac si
float BacSi::TinhLuong() {
	return LuongCoBan + HeSoLuong * LuongCoBan;

}

//Ham xuat thong tin bac si
void BacSi::Xuat() {
	LuongThucTe = BacSi::TinhLuong();
	ThongTin::Xuat();
	cout <<"\t"<< (size_t)LuongThucTe << endl;
}


//---------------------------------------------

//class benh nhan
class BenhNhan :public ThongTin
{
private:
	long SoThe;
	string TinhTrang;
	string NgayHenKham, NgayTaiKham;
	string NgheNghiep;
	string TienSuBenh;
	string GhiChu;
	float ChiPhi;

public:
	float GetChiPhi() {
		return ChiPhi;
	}
	int GetSoThe() {
		return SoThe;
	}
	void Nhap();
	void Xuat();
	void GhiFileBN(BenhNhan* ds_BN[], int m);
	void TimKiemBN(BenhNhan* ds_BN[], int m);
	void XoaBenhNhan(BenhNhan* ds_BN[], int& m);
	void SapXepBN(BenhNhan* ds_BN[], int m);
	void CapNhatBN(BenhNhan* ds_BN[], int m);
	void TimKiemBNTheoMS(BenhNhan* ds_BN[], int m);
	friend void ChinhSua(BenhNhan* ds_BN[], int m);

	BenhNhan();
	~BenhNhan();
};

// Ham nhap benh nhan
void BenhNhan::Nhap() {
	while (getchar() != '\n');
	cout << "\n\tSo the: ";
	cin >> SoThe;
	ThongTin::Nhap();
	cout << "\n\tTinh trang benh: ";
	getline(cin, TinhTrang);
	cout << "\n\tTien su benh: ";
	getline(cin, TienSuBenh);
	cout << "\n\tLich hen kham: ";
	getline(cin, NgayHenKham);
	cout << "\n\tLich tai kham: ";
	getline(cin, NgayTaiKham);
	while (getchar() != '\n');
	cout << "\n\tChi phi vien: ";
	cin >> ChiPhi;
	while (getchar() != '\n');
	cout << "\n\tGhi chu: ";
	getline(cin, GhiChu);
}

//Ham xuat benh nhan
void BenhNhan::Xuat() {
	cout << "\n";
	ThongTin::Xuat();
	cout << "\t" << SoThe << "\t" << TinhTrang << "\t\t" << TienSuBenh << "\t\t" << NgayHenKham << "\t\t" << NgayTaiKham << "\t\t" << ChiPhi << "\t" << GhiChu<<endl;
}

BenhNhan::BenhNhan() {
}
BenhNhan::~BenhNhan() {
}
/*void ChinhSua(BenhNhan* ds_BN[], int m, BenhNhan) {
	BenhNhan a;
	string name;
	while (getchar() != '\n');
	cout << "Nhap ten benh nhan  can tim : ";
	getline(cin, name);
	bool check = false;
	for (int i = 0; i < m; i++) {
		if (ds_BN[i]->GetName() == name) {
			cout << "nhap ten can chinh sua";
			 ds_BN[i]->Xuat();
			check = true;
		}
	}
	if (!check)
		cout << "\nKhong tim thay benh nhan co ten la " << name << endl;
	cout << "\n\n";
	system("pause");

}
*/
//-------------------------------------
// Ham doi cho cho Bac si
void SwapBS(BacSi*& x, BacSi*& y) {
	BacSi* tam;
	tam = x;
	x = y;
	y = tam;

}

//Ham doi cho benh nhan
void SwapBN(BenhNhan*& x, BenhNhan*& y) {
	BenhNhan* tam;
	tam = x;
	x = y;
	y = tam;

}

//Ham sap xep bac si theo luong co ban
void BacSi::SapXepBS(BacSi* ds_BS[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i; j < n; j++) {
			if (ds_BS[i]->TinhLuong() < ds_BS[j]->TinhLuong()) {
				SwapBS(ds_BS[i], ds_BS[j]);
			}
		}
	}
	system("cls");
	cout << "\n\t\t======= DANH SACH BAC SI DUOC SAP XEP THEO LUONG CO BAN =======";
	cout << "\n\tHoTen\tGioiTinh\tNgaySinh\tDiaChi\tSDT\tLuong thuc te" << endl;
	for (int i = 0; i < n; i++) {
		ds_BS[i]->Xuat();
	}
	cout << "\n\n";
	system("pause");

}

//Ham sap xep benh nhan theo chi phi
void BenhNhan::SapXepBN(BenhNhan* ds_BN[], int m) {
	for (int i = 0; i < m - 1; i++) {
		for (int j = i; j < m; j++) {
			if (ds_BN[i]->GetChiPhi() < ds_BN[j]->GetChiPhi()) {
				SwapBN(ds_BN[i], ds_BN[j]);
			}
		}
	}
	system("cls");
	cout << "\n\t\t======= DANH SACH BENH NHAN DUOC SAP XEP THEO CHI PHI =======";
	for (int i = 0; i < m; i++) {
		cout << "\n\tHoTen\tGioiTinh\tNgaySinh\tDiaChi\tSDT\tSoThe\tTinhTrangBenh\tTienSuBenh\tLichHenKham\tLichTaiKham\tChiPhi\tGhiChu" << endl;
		ds_BN[i]->Xuat();
	}
	cout << "\n\n";
	system("pause");

}


//----------------------------------
	// Ham tim kiem bac si
void TimKiemBS(BacSi* ds_BS[], int n) {
	string name;
	while (getchar() != '\n');
	cout << "Nhap ten bac si  can tim : ";
	getline(cin, name);
	bool check = false;
	for (int i = 0; i < n; i++) {
		if (ds_BS[i]->GetName() == name) {
			cout << "\n\tHoTen\tGioiTinh\tNgaySinh\tDiaChi\tSDT\tLuong thuc te" << endl;
			ds_BS[i]->Xuat();
			check = true;
		}
	}
	if (!check)
		cout << "\nKhong tim thay bac si co ten la " << name << endl;
	cout << "\n\n";
	system("pause");

}

// Ham tim kiem benh nhan
void BenhNhan::TimKiemBN(BenhNhan* ds_BN[], int m) {
	string name;
	while (getchar() != '\n');
	cout << "Nhap ten benh nhan  can tim : ";
	getline(cin, name);
	bool check = false;
	for (int i = 0; i < m; i++) {
		if (ds_BN[i]->GetName() == name) {
			cout << "\n\tHoTen\tGioiTinh\tNgaySinh\tDiaChi\tSDT\tSoThe\tTinhTrangBenh\tTienSuBenh\tLichHenKham\tLichTaiKham\tChiPhi\tGhiChu" << endl;
			ds_BN[i]->Xuat();
			check = true;
		}
	}
	if (!check)
		cout << "\nKhong tim thay benh nhan co ten la " << name << endl;
	cout << "\n\n";
	system("pause");

}
void BenhNhan::TimKiemBNTheoMS(BenhNhan* ds_BN[], int m) {
	int timma;
	while (getchar() != '\n');
	cout << "Nhap ma so can tim: ";
	cin >> timma;
	bool check = false;
	for (int i = 0; i < m; i++) {
		if (ds_BN[i]->GetSoThe() == timma) {
			ds_BN[i]->Xuat();
			check = true;
		}
	}
	if (!check)
		cout << "\nKhong tim thay benh nhan co ma so la " << timma << endl;
	cout << "\n\n";
	system("pause");
}


//------------------------------------------
  // Ham xoa bac si
void BacSi::XoaBacSi(BacSi* ds_BS[], int& n) {
	string name;
	while (getchar() != '\n');
	cout << "\n\tNhap ten bac si can xoa : ";
	getline(cin, name);
	bool check = false;
	for (int i = 0; i < n; i++) {
		if (ds_BS[i]->GetName() == name) {
			for (int j = i; j < n; j++) {
				ds_BS[j] = ds_BS[j + 1];
			}
			cout << "\n\tBac si co ten " << name << " da duoc xoa";
			n--;
			check = true;
			break;
		}
	}
	if (!check)
		cout << "\nKhong tim thay bac si co ten la " << name << endl;
	cout << "\n\n";
	system("pause");
}


// Ham xoa benh nhan
void BenhNhan::XoaBenhNhan(BenhNhan* ds_BN[], int& m) {
	string name;
	while (getchar() != '\n');
	cout << "\n\tNhap ten benh nhan can xoa : ";
	getline(cin, name);
	bool check = false;
	for (int i = 0; i < m; i++) {
		if (ds_BN[i]->GetName() == name) {
			for (int j = i; j < m; j++) {
				ds_BN[j] = ds_BN[j + 1];
			}
			cout << "\n\tBenh nhan co ten " << name << " da duoc xoa";
			m--;
			check = true;
			break;
		}
	}
	if (!check)
		cout << "\nKhong tim thay benh nhan co ten la " << name << endl;
	cout << "\n\n";
	system("pause");
}
//-------------------------------------------
	//Ham cap nhat bac si
void ThongTinCapNhatBS(BacSi*& x) {
	cout << "\n\tMoi nhap thong tin moi cua bac si";
	x->Nhap();

}
void BacSi::CapNhatBS(BacSi* ds_BS[], int n) {
	string name;
	while (getchar() != '\n');
	cout << "\n\tNhap ten bac si can cap nhat : ";
	getline(cin, name);
	bool check = false;
	for (int i = 0; i < n; i++) {
		if (ds_BS[i]->GetName() == name) {
			ThongTinCapNhatBS(ds_BS[i]);
			cout << "\n\tBac si co ten " << name << " da duoc cap nhat";
			check = true;
		}
	}
	if (!check)
		cout << "\nKhong tim thay bac si co ten la " << name << endl;
	cout << "\n\n";
	system("pause");

}


//Ham cap nhat benh nhan
void ThongTinCapNhatBN(BenhNhan*& x) {
	cout << "\n\tMoi nhap thong tin moi cua benh nhan";
	x->Nhap();

}
void BenhNhan::CapNhatBN(BenhNhan* ds_BN[], int m) {
	string name;
	while (getchar() != '\n');
	cout << "\n\tNhap ten benh nhan can cap nhat : ";
	getline(cin, name);
	bool check = false;
	for (int i = 0; i < m; i++) {
		if (ds_BN[i]->GetName() == name) {
			ThongTinCapNhatBN(ds_BN[i]);
			cout << "\n\tBenh nhan co ten " << name << " da duoc cap nhat";
			check = true;
		}
	}
	if (!check)
		cout << "\nKhong tim thay benh nhan co ten la " << name << endl;
	cout << "\n\n";
	system("pause");

}

//-----------------------------------
	// Ham ghi file bac si
void BacSi::GhiFileBS(BacSi* ds_BS[], int n) {

	//Mở file bằng ofstream 
	ofstream ofs("C:/Users/ADMIN/Desktop/BacSi.txt");

	//Kiểm tra file đã mở thành công hay chưa
	if (!ofs) {
		cerr << "Error: File not opened." << endl;

	}

	//Ghi file
	long sum = 0;
	for (int i = 0; i < n; i++) {
		ofs << "\n\n\t\tThong tin bac si thu " << i + 1;
		ofs << "\n\tHo ten : " << ds_BS[i]->HoTen;
		ofs << "\n\tNgay Sinh : " << ds_BS[i]->NgaySinh;
		ofs << "\n\tGioi tinh : " << ds_BS[i]->GioiTinh;
		ofs << "\n\tDia chi : " << ds_BS[i]->DiaChi;
		ofs << "\n\tSdt : " << ds_BS[i]->SDT;
		ofs << "\n\tLuong co ban: " << (size_t)ds_BS[i]->LuongCoBan;
		ofs << "\n\tHe so luong: " << ds_BS[i]->HeSoLuong;
		//LuongThucTe = BacSi::TinhLuong();
		sum += ds_BS[i]->TinhLuong();
		ofs << "\n\tLuong thuc te: " << (size_t)ds_BS[i]->LuongThucTe;

	}ofs << "\n\n\tTong luong cua cac bac si: " << (size_t)sum;


	//Đóng file
	ofs.close();

}

// Ham ghi file benh nhan
void BenhNhan::GhiFileBN(BenhNhan* ds_BN[], int m) {

	//Mở file bằng ofstream 
	ofstream ofs("E:/");

	//Kiểm tra file đã mở thành công hay chưa
	if (!ofs) {
		cerr << "Error: File not opened." << endl;

	}

	//Ghi file
	long sum = 0;
	for (int i = 0; i < m; i++) {
		ofs << "\n\n\t\tThong tin benh nhan thu " << i + 1;
		ofs << "\n\tSo the" << ds_BN[i]->SoThe;
		ofs << "\n\tHo ten : " << ds_BN[i]->HoTen;
		ofs << "\n\tNgay Sinh : " << ds_BN[i]->NgaySinh;
		ofs << "\n\tGioi tinh : " << ds_BN[i]->GioiTinh;
		ofs << "\n\tDia chi : " << ds_BN[i]->DiaChi;
		ofs << "\n\tSdt : " << ds_BN[i]->SDT;
		ofs << "\n\tTinh trang benh: " << ds_BN[i]->TinhTrang;
		ofs << "\n\tTien su benh: " << ds_BN[i]->TienSuBenh;
		ofs << "\n\tLich hen kham vao ngay: " << ds_BN[i]->NgayHenKham;
		ofs << "\n\tlich tai kham sau:  " << ds_BN[i]->NgayTaiKham << " ngay";
		ofs << "\n\tChi phi: " << (size_t)ds_BN[i]->ChiPhi;
		ofs << "\n\tGhi chu: " << ds_BN[i]->GhiChu;

		sum += ds_BN[i]->ChiPhi;

	}ofs << "\n\n\tTong chi phi cua cac benh nhan: " << (size_t)sum;


	//Đóng file
	ofs.close();

}
//-----------------------------------
// Mwnu 1 - Bac si
void Menu1(BacSi* ds_BS[], int n) {
	int LuaChon;
	do {
		system("cls");
		cout << "\n\n\t\t===== BAC SI =====";
		cout << "\n\t1.Them thong tin bac si vao danh sach";
		cout << "\n\t2.Xuat danh sach thong tin bac si";
		cout << "\n\t3.Sap xep danh sach thong tin bac si";
		cout << "\n\t4.Tim kiem bac si";
		cout << "\n\t5.Cap nhat thong tin bac si";
		cout << "\n\t6.Xoa bac si";
		cout << "\n\t7.Ghi thong tin bac si vao file";
		cout << "\n\t0.Thoat";
		cout << "\n\n\tLua chon cua ban:  ";
		cin >> LuaChon;

		BacSi* x = new BacSi;
		//Kiem tra dk nhap
		if (LuaChon < 0 || LuaChon > 7) {
			cout << "\n\tBan da nhap lua chon khong hop le. Vui long nhap lai!\n";
			system("pause");
		}

		//Nhap thong tin bac si
		else if (LuaChon == 1) {

			system("cls");
			cout << "\n\n\t\t===== THEM THONG TIN  BAC SI =====";
			x->Nhap();
			ds_BS[n] = x;
			n++;
			cout << "\n\tThong tin bac si da duoc them vao danh sach\n\n";
			system("pause");

		}

		//xuat thong tin bac si
		else if (LuaChon == 2) {
			long sum = 0;
			system("cls");
			cout << "\n\n\t\t===== DANH SACH BAC SI =====";
			if (n == 0)
				cout << "\n\tDanh sach trong!!!";
			cout << "\n\tHoTen\tGioiTinh\tNgaySinh\tDiaChi\tSDT\tLuong thuc te" << endl;
			for (int i = 0; i < n; i++) {
				sum += ds_BS[i]->TinhLuong();
				ds_BS[i]->Xuat();
			}
			cout << "\n\n\tTong luong cua cac bac si: " << (size_t)sum;
			cout << "\n\n";
			system("pause");

		}

		//Sap xep bac si
		else if (LuaChon == 3) {
			if (n == 0)
				cout << "\n\n\t\Danh sach rong!!!";

			x->SapXepBS(ds_BS, n);

		}

		//Tim kiem bac si
		else if (LuaChon == 4) {
			TimKiemBS(ds_BS, n);
		}

		//Cap nhat thong tin bac si
		else if (LuaChon == 5) {

			system("cls");
			cout << "\n\n\t\t===== CAP NHAT THONG TIN  BAC SI =====";
			if (n == 0) {
				cout << "\n\tDanh sach rong !!\n";
				system("pause");

			}
			else
				x->CapNhatBS(ds_BS, n);
		}

		// Xoa bac si
		else if (LuaChon == 6) {

			system("cls");
			cout << "\n\n\t\t===== DANH SACH BAC SI =====";
			if (n == 0)
				cout << "\n\tDanh sach trong!!!";
			cout << "\n\tHoTen\tGioiTinh\tNgaySinh\tDiaChi\tSDT\tLuong thuc te" << endl;
			for (int i = 0; i < n; i++) {
				ds_BS[i]->Xuat();
			}
			cout << "\n\n\t\t===== XOA THONG TIN  BAC SI =====";
			if (n == 0) {
				cout << "\n\tDanh sach rong !!\n";
				system("pause");

			}
			else x->XoaBacSi(ds_BS, n);
		}

		//Ghi bac si
		else if (LuaChon == 7) {

			x->GhiFileBS(ds_BS, n);
			cout << "\n\tFile da duoc luu theo dong dan: C:/Users/ADMIN/Desktop/BcSi.txt\n\n";
			system("pause");
		}


	} while (LuaChon != 0);

}


// Menu 2 - Benh nhan
void Menu2(BenhNhan* ds_BN[], int m) {
	int LuaChon;
	do {
		system("cls");
		cout << "\n\n\t\t===== BENH NHAN =====";
		cout << "\n\t1.Them thong tin benh nhan vao danh sach";
		cout << "\n\t2.Xuat danh sach thong tin benh nhan";
		cout << "\n\t3.Sap xep danh sach thong tin benh nhan";
		cout << "\n\t4.Tim kiem benh nhan";
		cout << "\n\t5.Cap nhat thong tin benh nhan";
		cout << "\n\t6.Xoa benh nhan";
		cout << "\n\t7.Ghi thong tin benh nhan vao file";
		cout << "\n\t0.Thoat";
		cout << "\n\n\tLua chon cua ban:  ";
		cin >> LuaChon;

		BenhNhan* x = new BenhNhan;
		//Kiem tra dk nhap
		if (LuaChon < 0 || LuaChon > 7) {
			cout << "\n\tBan da nhap lua chon khong hop le. Vui long nhap lai!\n";
			system("pause");
		}

		//Nhap thong tin benh nhan
		else if (LuaChon == 1) {

			system("cls");
			cout << "\n\n\t\t===== THEM THONG TIN BENH NHAN =====";
			x->Nhap();
			ds_BN[m] = x;
			m++;
			cout << "\n\tThong tin benh nhan da duoc them vao danh sach\n\n";
			system("pause");

		}

		//Xuat thong tin benh nhan
		else if (LuaChon == 2) {
			long sum = 0;
			system("cls");
			cout << "\n\n\t\t===== DANH SACH BENH NHAN =====";
			cout << "\n\tHoTen\tGioiTinh\tNgaySinh\tDiaChi\tSDT\tSoThe\tTinhTrangBenh\tTienSuBenh\tLichHenKham\tLichTaiKham\tChiPhi\tGhiChu" << endl;
			if (m == 0)
				cout << "\n\tDanh sach trong!!!";
			for (int i = 0; i < m; i++) {
				sum += ds_BN[i]->GetChiPhi();
				ds_BN[i]->Xuat();
			}
			cout << "\n\n\tTong chi phi cua cac benh nhan: " << (size_t)sum;
			cout << "\n\n";
			system("pause");

		}

		//Sap xep benh nhan
		else if (LuaChon == 3) {
			x->SapXepBN(ds_BN, m);
		}

		//Tim kiem benh nhan
		else if (LuaChon == 4) {
			int LuaChon;
			do {
				system("cls");
				cout << "\n\n\t\t====TIM KIEM====";
				cout << "\n\t1.Tim kiem theo ten";
				cout << "\n\t2.Tim kiem theo ma so";
				cout << "\n\t0.Thoat";
				cout << "Lua chon cua ban:  ";
				cin >> LuaChon;
				BenhNhan* x = new BenhNhan;
				if (LuaChon < 0 || LuaChon > 2) {
					cout << "\n\tBan da nhap lua chon khong hop le. Vui long nhap lai!\n";
					system("pause");
				}
				else if (LuaChon == 1) {
					x->TimKiemBN(ds_BN, m);

				}
				else if (LuaChon == 2) {
					x->TimKiemBNTheoMS(ds_BN, m);
				}
			} while (LuaChon != 0);
		}

		//Ham cap nhat benh nhan
		else if (LuaChon == 5) {
			system("cls");
			cout << "\n\n\t\t===== CAP NHAT THONG TIN BENH NHAN =====";
			if (m == 0) {
				cout << "\n\tDanh sach rong !!\n";
				system("pause");

			}
			else
				x->CapNhatBN(ds_BN, m);
		}

		// Xoa benh nhan
		else if (LuaChon == 6) {
			system("cls");
			cout << "\n\n\t\t===== XOA THONG TIN BENH NHAN =====";
			cout << "\n\tHoTen\tGioiTinh\tNgaySinh\tDiaChi\tSDT\tSoThe\tTinhTrangBenh\tTienSuBenh\tLichHenKham\tLichTaiKham\tChiPhi\tGhiChu" << endl;
			if (m == 0)
				cout << "\n\tDanh sach trong!!!";
			for (int i = 0; i < m; i++) {

				ds_BN[i]->Xuat();
			}
			if (m == 0) {
				cout << "\n\tDanh sach rong !!\n";
				system("pause");

			}
			else x->XoaBenhNhan(ds_BN, m);
		}

		//Ghi benh nhan
		else if (LuaChon == 7) {

			x->GhiFileBN(ds_BN, m);
			cout << "\n\tFile da duoc luu theo dong dan: C:/Users/ADMIN/Desktop/BenhNhan.txt\n\n";
			system("pause");
		}

	} while (LuaChon != 0);

}

//Menu
void Menu(BacSi* ds_BS[], BenhNhan* ds_BN[], int n, int m) {
	int LuaChon;
	while (true) {
		system("cls");
		cout << "\n\n\t\t===== PHAN MEM QUAN LY NHA KHOA =====";
		cout << "\n\t1.Bac si";
		cout << "\n\t2.Benh nhan ";
		cout << "\n\t0.Thoat";
		cout << "\n\n\tLua chon cua ban:  ";
		cin >> LuaChon;

		//Kiem tra dk nhap
		if (LuaChon < 0 || LuaChon > 6) {
			cout << "\n\tBan da nhap lua chon sai. Vui long nhap lai\n";
			system("pause");
		}

		//Menu bac si
		else if (LuaChon == 1) {
			Menu1(ds_BS, n);

		}

		//Menu benh nhan
		else if (LuaChon == 2) {
			Menu2(ds_BN, m);
		}

		//Thoat
		else if (LuaChon == 0) break;
	}

	//Xoa bo nho cap phat
	for (int i = 0; i < n; i++)
		delete ds_BS[i];
	for (int i = 0; i < m; i++)
		delete ds_BN[i];
}






int main() {
	BacSi* ds_BS[100];
	BenhNhan* ds_BN[100];
	int n = 0;
	int m = 0;
	Menu(ds_BS, ds_BN, n, m);

	return 0;
}
