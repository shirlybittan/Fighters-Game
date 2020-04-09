
// Fighters GameDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "Fighters Game.h"
#include "Fighters GameDlg.h"
#include "afxdialogex.h"

//includes for sound added
#include <windows.h>
#include <iostream>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CFightersGameDlg dialog



CFightersGameDlg::CFightersGameDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_FIGHTERSGAME_DIALOG, pParent)
	, Computer_Character_String(_T(""))
	, Player_Character_String(_T(""))
	, Player_Weapon_String(_T(""))
	, Status_Edit(_T("Press 'Start The Game!' to start."))
	, Money_Edit(_T("0"))
	, Status2_Edit(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFightersGameDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PROGRESS1, Player_HP_bar);
	DDX_Control(pDX, IDC_PROGRESS2, Computer_HP_bar);
	DDX_Text(pDX, Computer_Character_EDIT, Computer_Character_String);
	DDX_Text(pDX, Player_Character_EDIT, Player_Character_String);
	DDX_Text(pDX, Player_Weapon_EDIT, Player_Weapon_String);
	DDX_Text(pDX, Status_EDIT, Status_Edit);
	DDX_Text(pDX, Money_Amount_EDIT, Money_Edit);
	DDX_Text(pDX, Status2_EDIT, Status2_Edit);

	DDX_Control(pDX, Player_Knight_IMG_IDC_STATIC, Player_Knight_STATIC);
	DDX_Control(pDX, Black_Wizard_IMG_STATIC, Black_Wizard_STATIC);
	DDX_Control(pDX, HorseMan_IMG_STATIC, HorseMan_STATIC);
	DDX_Control(pDX, White_Wizard_STATIC, White_Wizard_IMG_STATIC);
	DDX_Control(pDX, computer_knight_IMG_STATIC, Computer_Knight_IMG);
	DDX_Control(pDX, Black_Wizard_Computer_IMG_STATIC, Black_Wizard_Computer_STATIC);
	DDX_Control(pDX, Player_Computer_IMG_STATIC, Player_Computer_STATIC);
}

BEGIN_MESSAGE_MAP(CFightersGameDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(Knight_RADIO, &CFightersGameDlg::OnBnClickedRadio)
	ON_BN_CLICKED(Horse_Man_RADIO, &CFightersGameDlg::OnBnClickedManRadio)
	ON_BN_CLICKED(White_Wizard_RADIO, &CFightersGameDlg::OnBnClickedWizardRadio)
	ON_BN_CLICKED(Black_Wizard_RADIO, &CFightersGameDlg::OnBnClickedBlackWizardRadio)
	ON_BN_CLICKED(Start_the_Game_BUTTON, &CFightersGameDlg::OnBnClickedtheGameButton)
	ON_BN_CLICKED(Attack_BUTTON, &CFightersGameDlg::OnBnClickedButton)
	ON_BN_CLICKED(Restart_BUTTON, &CFightersGameDlg::OnBnClickedRestartButton)
	ON_BN_CLICKED(Steal_money_BUTTON, &CFightersGameDlg::OnBnClickedmoneyButton)
	ON_BN_CLICKED(Visit_store_BUTTON, &CFightersGameDlg::OnBnClickedstoreButton)
END_MESSAGE_MAP()


// CFightersGameDlg message handlers

BOOL CFightersGameDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CFightersGameDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CFightersGameDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CFightersGameDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CFightersGameDlg::OnBnClickedRadio() // Knight Chosen
{
	Character_Chosen = 1;
	UpdateData(FALSE);

}


void CFightersGameDlg::OnBnClickedManRadio() // Horse Man Chosen
{
	Character_Chosen = 2;
	UpdateData(FALSE);
}


void CFightersGameDlg::OnBnClickedWizardRadio() // White Wizard Chosen
{
	Character_Chosen = 3;
	UpdateData(FALSE);
}

 
void CFightersGameDlg::OnBnClickedBlackWizardRadio() //Black Wizard Chosen
{
	Character_Chosen = 4;
	UpdateData(FALSE);
}


void CFightersGameDlg::OnBnClickedtheGameButton()
{
	//add sound to the game
	PlaySound(TEXT("C:/Users/shirl/Music/pirates.wav"), NULL, SND_FILENAME | SND_ASYNC);



	
	if (Character_Chosen > 0 && Character_Chosen < 5 && flagBeginFight == 0) {
		flagBeginFight = 1;
		Player_HP_bar.SetPos(100);
		Computer_HP_bar.SetPos(100);
		Status_Edit = (_T(""));

		computer = new Player();
		Computer_Character_String = (_T("Simple Player"));
		Player_Computer_STATIC.ShowWindow(SW_SHOW);

		if (Character_Chosen == 1) {
			myPlayer = new Knight("Knight Sword", 15);
			Player_Character_String = (_T("Knight"));
			Player_Knight_STATIC.ShowWindow(SW_SHOW);
		}
		else if (Character_Chosen == 2) {
			myPlayer = new Horseman("Spear", 15);
			Player_Character_String = (_T("Horse Man"));
			HorseMan_STATIC.ShowWindow(SW_SHOW);
	}
		else if (Character_Chosen == 3) {
			myPlayer = new WhiteWizard("Energy Push", 15);
			Player_Character_String = (_T("White Wizard"));
			White_Wizard_IMG_STATIC.ShowWindow(SW_SHOW);
	}
		else {
			myPlayer = new BlackWizard("Darkness", 15);
			Player_Character_String = (_T("Black Wizard"));
			Black_Wizard_STATIC.ShowWindow(SW_SHOW);
	}
		
		std::string stdstr((myPlayer->getWeapon()).m_name);
		CString cstr(stdstr.c_str());
		Player_Weapon_String = cstr;

		UpdateData(FALSE);

	}
	else {
		Status_Edit = (_T("You must choose a character first"));
		UpdateData(FALSE);
	}
}


void CFightersGameDlg::OnBnClickedButton()
{
	if (flagBeginFight == 0) // match hasnt started
		return;
	Status_Edit = (_T(" "));
	UpdateData(FALSE);
	Sleep(500);// delay for letting Status_Edit to be refreshed
	myPlayer->attack(*computer);
	Computer_HP_bar.SetPos(computer->getHp());
	UpdateData(FALSE);

	if (computer->getHp() <= 1){// in case computer died
		if (computer_Char_Num == 1)
		{
			Player_Computer_STATIC.ShowWindow(SW_HIDE);
			Computer_Knight_IMG.ShowWindow(SW_SHOW);
			computer = new Knight("Knight Sword", 20);
			Status_Edit = (_T("You killed the simple player.\n Prepare for round 2!"));
			Computer_Character_String = (_T("Knight"));
			Computer_HP_bar.SetPos(computer->getHp());
			Status2_Edit = (_T(" "));
		}
		if (computer_Char_Num == 2) {
			Computer_Knight_IMG.ShowWindow(SW_HIDE);
			Black_Wizard_Computer_STATIC.ShowWindow(SW_SHOW);
			computer = new BlackWizard("Dark Magic", 40);
			Status_Edit = (_T("You killed the Knight. Prepare for round 3!"));
			Computer_Character_String = (_T("Black Wizard"));
			Computer_HP_bar.SetPos(computer->getHp());
			Status2_Edit = (_T("Final Battle!"));
		}
		if (computer_Char_Num == 3)
		{
			Player_Won player_Dial;
			player_Dial.DoModal();
		}
		computer_Char_Num++;
	}
	else {// computer is not dead so he will attack
		ComputerAttack();
	}
	UpdateData(FALSE);
	

}


void CFightersGameDlg::OnBnClickedRestartButton()
{
	PlaySound(TEXT("C:/Users/shirl/Music/pirates.wav"), NULL, SND_FILENAME | SND_ASYNC);

	flagBeginFight = 0;
	myPlayer = new Player();
	computer = new Player();

	computer_Char_Num = 1;

	//Hide Characters
	Player_Computer_STATIC.ShowWindow(SW_HIDE);
	Player_Knight_STATIC.ShowWindow(SW_HIDE);
	HorseMan_STATIC.ShowWindow(SW_HIDE);
	White_Wizard_IMG_STATIC.ShowWindow(SW_HIDE);
	Black_Wizard_STATIC.ShowWindow(SW_HIDE);
	Computer_Knight_IMG.ShowWindow(SW_HIDE);
	Black_Wizard_Computer_STATIC.ShowWindow(SW_HIDE);
	///////

	string st = to_string(myPlayer->getmoney());
	std::string stdstr(st);
	CString cstr(stdstr.c_str());
	Money_Edit = cstr;
	UpdateData(FALSE);
	CFightersGameDlg::OnBnClickedtheGameButton();
	UpdateData(FALSE);

}



void CFightersGameDlg::OnBnClickedmoneyButton()
{
	if (flagBeginFight == 0) // match hasnt started
		return;

	// Player gain exp when stealing

	if (Steal_money_counter == 0) {
		myPlayer->AddMoney(10);
		Status_Edit = (_T("You successfully stole 10 coins!"));
		UpdateData(FALSE);
		
	}
	if (Steal_money_counter == 1) {
		myPlayer->AddMoney(15);
		Status_Edit = (_T("You successfully stole 15 coins!"));
		UpdateData(FALSE);
	}
	if (Steal_money_counter > 1) {
		myPlayer->AddMoney(20);
		Status_Edit = (_T("You successfully stole 20 coins!"));
		UpdateData(FALSE);
	}
	Steal_money_counter++;
	string st = to_string(myPlayer->getmoney());
	std::string stdstr(st);
	CString cstr(stdstr.c_str());
	Money_Edit = cstr;
	UpdateData(FALSE);
	ComputerAttack();

}

void CFightersGameDlg::ComputerAttack()
{
	Sleep(500); // wait before computer attack back
	computer->attack(*myPlayer);
	Player_HP_bar.SetPos(myPlayer->getHp());
	Sleep(500);
	Status2_Edit = (_T("The computer attacked you back!"));
	UpdateData(FALSE);

	if (myPlayer->getHp() <= 0) { // in case the player died
		Computer_Won computer_Dial;
		computer_Dial.DoModal();

		CFightersGameDlg::OnBnClickedRestartButton();
	}
}

void CFightersGameDlg::OnBnClickedstoreButton()
{

	Store Store_Dial;
	(Store_Dial.myPlayer) = myPlayer;
	string st = to_string(myPlayer->getmoney());
	std::string stdstr(st);
	CString cstr(stdstr.c_str());
	Store_Dial.Money_Edit = cstr;
	UpdateData(FALSE);
	Store_Dial.DoModal();


	// update money dialog 
	stdstr = to_string(myPlayer->getmoney());
	cstr=stdstr.c_str();
	Money_Edit = cstr;

	// update weapon dialog
	stdstr = ((myPlayer->getWeapon()).m_name);
	 cstr = stdstr.c_str();
	Player_Weapon_String = cstr;

	//update life bar
	Player_HP_bar.SetPos(myPlayer->getHp());
		
	UpdateData(FALSE);

}



Player* CFightersGameDlg::getPlayer() const{
	return myPlayer;
}

