#include <iostream>
#include <string>
using namespace std;
struct SinhVien
{
    int maSV;
    string tenSV;
    string lop;
    float tongKet;
    string hanhKiem;
};

struct Node
{
    SinhVien data;
    Node *left;
    Node *right;
};

typedef Node* Tree;
void khoiTaoCay(Tree &T)
{
    T = NULL;
}
Node* taoNode(SinhVien sv)
{
    Node *p = new Node;

    p->data = sv;
    p->left = NULL;
    p->right = NULL;

    return p;
}
void chenNode(Tree &T, SinhVien sv)
{
    if (T == NULL)
    {
        T = taoNode(sv);
    }
    else
    {
        if (sv.maSV < T->data.maSV)
        {
            chenNode(T->left, sv);
        }
        else if (sv.maSV > T->data.maSV)
        {
            chenNode(T->right, sv);
        }
    }
}
Node* timKiem(Tree T, int maSV)
{
    if (T == NULL)
    {
        return NULL;
    }

    if (maSV == T->data.maSV)
    {
        return T;
    }
    else if (maSV < T->data.maSV)
    {
        return timKiem(T->left, maSV);
    }
    else
    {
        return timKiem(T->right, maSV);
    }
}
void duyetCay(Tree T)
{
    if (T != NULL)
    {
        duyetCay(T->left);

        cout << "\nMa sinh vien: " << T->data.maSV;
        cout << "\nTen sinh vien: " << T->data.tenSV;
        cout << "\nLop: " << T->data.lop;
        cout << "\nTong ket: " << T->data.tongKet;
        cout << "\nHanh kiem: " << T->data.hanhKiem;

        cout << "\n-----------------------------";

        duyetCay(T->right);
    }
}
SinhVien nhapSinhVien()
{
    SinhVien sv;

    cout << "\nMa sinh vien: ";
    cin >> sv.maSV;

    cin.ignore();

    cout << "Ten sinh vien: ";
    getline(cin, sv.tenSV);

    cout << "Lop: ";
    getline(cin, sv.lop);

    cout << "Tong ket: ";
    cin >> sv.tongKet;

    cin.ignore();

    cout << "Hanh kiem (Tot/Kha/Trung binh/Yeu): ";
    getline(cin, sv.hanhKiem);

    return sv;
}
int main()
{
    Tree T;
    int n;
    khoiTaoCay(T);
    cout << "Nhap so luong sinh vien n = ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "\n===== NHAP SINH VIEN THU " << i + 1 << " =====";

        SinhVien sv = nhapSinhVien();

        chenNode(T, sv);
    }
    cout << "\n\n===== DANH SACH SINH VIEN TRONG CAY =====";
    duyetCay(T);
    int maCanTim;

    cout << "\n\nNhap ma sinh vien can tim: ";
    cin >> maCanTim;

    Node *p = timKiem(T, maCanTim);

    if (p == NULL)
    {
        cout << "\nKhong co sinh vien co ma " << maCanTim
             << " trong cay.";
    }
    else
    {
        cout << "\n===== THONG TIN SINH VIEN CAN TIM =====";
        cout << "\nMa sinh vien: " << p->data.maSV;
        cout << "\nTen sinh vien: " << p->data.tenSV;
        cout << "\nLop: " << p->data.lop;
        cout << "\nTong ket: " << p->data.tongKet;
        cout << "\nHanh kiem: " << p->data.hanhKiem;
    }

    return 0;
} 
