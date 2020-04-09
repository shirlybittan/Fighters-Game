#pragma once
#include "Fighters Game.h"

#include "Fighters GameDlg.h"

// Store dialog

class Store : public CDialogEx 
{
	DECLARE_DYNAMIC(Store)

public:
	Store(CWnd* pParent = nullptr);   // standard constructor
	virtual ~Store();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = Store_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()

public:
	CString Money_Edit;
	Player* myPlayer;
	afx_msg void OnBnClickedButton();
	afx_msg void OnBnClickedBallButton();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedPotionButton();
};
