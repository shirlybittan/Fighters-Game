#pragma once


// Player_Won dialog

class Player_Won : public CDialogEx
{
	DECLARE_DYNAMIC(Player_Won)

public:
	Player_Won(CWnd* pParent = nullptr);   // standard constructor
	virtual ~Player_Won();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = Player_Won_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
