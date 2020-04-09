#pragma once


// Computer_Won dialog

class Computer_Won : public CDialogEx
{
	DECLARE_DYNAMIC(Computer_Won)

public:
	Computer_Won(CWnd* pParent = nullptr);   // standard constructor
	virtual ~Computer_Won();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = Compuet_Won_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
