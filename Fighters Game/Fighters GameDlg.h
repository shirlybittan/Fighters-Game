
// Fighters GameDlg.h : header file
//
#pragma once


// CFightersGameDlg dialog
class CFightersGameDlg : public CDialogEx
{
// Construction
public:
	CFightersGameDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FIGHTERSGAME_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
	int Character_Chosen = 0;  // 1 - Knight , 2 - Horse Man , 3 - White Wizard , 4 - Black Wizard
	int flagBeginFight = 0; // 0 - has never started a fight , 1 - otherwise
	Player* computer;
	Player* myPlayer;
	int Steal_money_counter = 0;
	int computer_Char_Num = 1;
	public:
	afx_msg void OnBnClickedRadio();
	
	
	afx_msg void OnBnClickedManRadio();
	afx_msg void OnBnClickedWizardRadio();
	afx_msg void OnBnClickedBlackWizardRadio();
	CProgressCtrl Player_HP_bar;
	CProgressCtrl Computer_HP_bar;
	afx_msg void OnBnClickedtheGameButton();
	CString Computer_Character_String;
	CString Player_Character_String;
protected:
	CString Player_Weapon_String;
public:
	afx_msg void OnBnClickedButton();
protected:
	CString Status_Edit;
public:
	afx_msg void OnBnClickedRestartButton();
	void ComputerAttack();
	CString Money_Edit;
	afx_msg void OnBnClickedmoneyButton();
	afx_msg void OnBnClickedstoreButton();
	CString Status2_Edit;
	
	Player* getPlayer() const;
	
	CStatic Player_Knight_STATIC;

	CStatic Black_Wizard_STATIC;
	CStatic HorseMan_STATIC;
	CStatic White_Wizard_IMG_STATIC;
	CStatic Computer_Knight_IMG;
	CStatic Black_Wizard_Computer_STATIC;
	CStatic Player_Computer_STATIC;
};

