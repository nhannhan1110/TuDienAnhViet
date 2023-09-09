// TuDienAnhViet.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
//#include<bits/stdc++.h>
using namespace std;
struct NODE {
	string data;
	NODE* left;
	NODE* right;
}; typedef NODE* BTree;
void them(BTree& T, string x);
void khoitao(BTree& T);
void DuyetLNR(BTree T);
bool timkiem(BTree T, string x);
void timNODEthe(BTree& p, BTree& q);
void xoa(BTree& T, string x);
string DT[100];
int m;
int main()
{
	BTree T;
	khoitao(T);
	while (true)
	{
		system("cls");
		cout << "===========MENU==========" << endl;
		cout << "1.Nhap du lieu" << endl;
		cout << "2.Xuat du lieu cay theo LNR" << endl;
		cout << "3.Gia tri cua node thu n duyet theo LNR" << endl;
		cout << "4.Xoa mot node khi biet key" << endl;
		cout << "0. Ket thuc" << endl;
		cout << "=========================" << endl;
		int luachon;
		cout << "Nhap lua chon: ";
		cin >> luachon;

		if (luachon < 0 || luachon>4)
		{
			cout << "Lua chon khong hop le" << endl;
			system("pause");
		}
		else if (luachon == 1)
		{
			string x;
			cout << "Nhap du lieu cua node: ";
			cin >> x;
			them(T, x);
			cout << endl;
		}
		else if (luachon == 2)
		{
			cout << endl;
			DuyetLNR(T);
			for (int j = 0; j < m; j++)
				cout << DT[j] << " ";
			cout << endl;
			system("pause");
		}
		else if (luachon == 3)
		{
			int n;
			cout << "Nhap thu tu node can biet gia tri:";
			cin >> n;
			cout << "Gia tri thu " << n << " la: " << DT[n - 1];
			cout << endl;
		}
		else if (luachon == 4)
		{
			string x;
			cout << "Nhap key cua node can xoa ";
			cin >> x;
			xoa(T, x);
		}
		else if (luachon == 0)
		{
			break;
		}

	}
	return 0;
}
// Duyet theo thu tu truoc/giua/sau
void DuyetLNR(BTree T)
{
	if (T == NULL)
		return;
	else
	{
		DuyetLNR(T->left);
		DT[m++] = T->data;
		cout << T->data;
		DuyetLNR(T->right);

	}
}
void them(BTree& T, string x)
{
	NODE* p = new NODE;
	p->data = x;
	if (T == NULL)
	{
		p->left = NULL;
		p->right = NULL;
		T = p;
	}
	else
	{
		if (T->data > x)
			them(T->left, x);
		if (T->data < x)
			them(T->right, x);
	}
}
void timNODEthe(BTree& p, BTree& q)
{
	if (q->left != NULL)
		timNODEthe(p, q->left);
	else
	{
		p->data = q->data;
		p = q;
		q = q->right;
	}
}
void xoa(BTree& T, string x)
{
	if (T == NULL)
		return;
	if (T->data == x)
	{
		NODE* p = T;
		if (T->left != NULL && T->right != NULL)
			timNODEthe(p, T->right);// tìm Node trái nh?t bên ph?i
		else if (T->left != NULL)
			T = T->left;
		else if (T->right != NULL)
			T = T->right;
		else
			T = NULL;
		delete p;
	}
	else if (T->data < x)
		xoa(T->right, x);
	else
		xoa(T->left, x);
}
bool timkiem(BTree T, string x)
{
	while (T != NULL)
	{
		if (T->data == x)
			return true;
		if (T->data < x)
			T = T->right;
		if (T->data > x)
			T = T->left;
	}
	return false;
}
void khoitao(BTree& T)
{
	T = NULL;
}


