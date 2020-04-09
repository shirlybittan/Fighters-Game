// Store.cpp : implementation file
//

#include "pch.h"
#include "Store.h"
#include "afxdialogex.h"


// Store dialog

IMPLEMENT_DYNAMIC(Store, CDialogEx)

Store::Store(CWnd* pParent /*=nullptr*/)
	: CDialogEx(Store_DIALOG1, pParent)
	, Money_Edit(_T(""))
{

}

Store::~Store()
{
}

void Store::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, Money_EDIT, Money_Edit);
}


BEGIN_MESSAGE_MAP(Store, CDialogEx)
	ON_BN_CLICKED(Excalibur_Button, &Store::OnBnClickedButton)
	ON_BN_CLICKED(Fire_Ball_BUTTON, &Store::OnBnClickedBallButton)
	ON_BN_CLICKED(IDC_BUTTON3, &Store::OnBnClickedButton3)
	ON_BN_CLICKED(Life_Potion_BUTTON, &Store::OnBnClickedPotionButton)
END_MESSAGE_MAP()





void Store::OnBnClickedButton()
{
	if (myPlayer->getmoney() >= 25) { // have enough money
		myPlayer->switchWeapon("Excalibur", 20);
		myPlayer->AddMoney(-25);

		string st = to_string(myPlayer->getmoney());
		std::string stdstr(st);
		CString cstr(stdstr.c_str());
		Money_Edit = cstr;
	}

		UpdateData(FALSE);

}


void Store::OnBnClickedBallButton()
{
	if (myPlayer->getmoney() >= 50) { // have enough money
		myPlayer->switchWeapon("Fire Ball", 30);
		myPlayer->AddMoney(-50);

		string st = to_string(myPlayer->getmoney());
		std::string stdstr(st);
		CString cstr(stdstr.c_str());
		Money_Edit = cstr;
	}

	UpdateData(FALSE);
}


void Store::OnBnClickedButton3()
{
	if (myPlayer->getmoney() >= 100) { // have enough money
		myPlayer->switchWeapon("Nuclear Bomb", 50);
		myPlayer->AddMoney(-100);

		string st = to_string(myPlayer->getmoney());
		std::string stdstr(st);
		CString cstr(stdstr.c_str());
		Money_Edit = cstr;
	}

	UpdateData(FALSE);
}


void Store::OnBnClickedPotionButton()
{
	if (myPlayer->getmoney() >= 25) { // have enough money
		myPlayer->drinkLifePotion(40);
		myPlayer->AddMoney(-25);

		string st = to_string(myPlayer->getmoney());
		std::string stdstr(st);
		CString cstr(stdstr.c_str());
		Money_Edit = cstr;
	}

	UpdateData(FALSE);
}
