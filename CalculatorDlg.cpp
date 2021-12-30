
// CalculatorDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "Calculator.h"
#include "CalculatorDlg.h"
#include "afxdialogex.h"
#include "afxwin.h"
#include "math.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include <iostream>
using namespace std;


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


// CCalculatorDlg dialog



CCalculatorDlg::CCalculatorDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CALCULATOR_DIALOG, pParent)
{
	num1 = num2 = result = 0;
	Flag = 0;
	str1 = _T("");
	str2 = _T("");
	cal_str = _T("");
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, edit_result);
}

BEGIN_MESSAGE_MAP(CCalculatorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_Num0, &CCalculatorDlg::OnBnClickedButtonNum0)
	ON_BN_CLICKED(IDC_BUTTON_Num1, &CCalculatorDlg::OnBnClickedButtonNum1)
	ON_BN_CLICKED(IDC_BUTTON_Num2, &CCalculatorDlg::OnBnClickedButtonNum2)
	ON_BN_CLICKED(IDC_BUTTON_Num3, &CCalculatorDlg::OnBnClickedButtonNum3)
	ON_BN_CLICKED(IDC_BUTTON_Num4, &CCalculatorDlg::OnBnClickedButtonNum4)
	ON_BN_CLICKED(IDC_BUTTON_Num5, &CCalculatorDlg::OnBnClickedButtonNum5)
	ON_BN_CLICKED(IDC_BUTTON_Num6, &CCalculatorDlg::OnBnClickedButtonNum6)
	ON_BN_CLICKED(IDC_BUTTON_Num7, &CCalculatorDlg::OnBnClickedButtonNum7)
	ON_BN_CLICKED(IDC_BUTTON_Num8, &CCalculatorDlg::OnBnClickedButtonNum8)
	ON_BN_CLICKED(IDC_BUTTON_Num9, &CCalculatorDlg::OnBnClickedButtonNum9)
	ON_BN_CLICKED(IDC_BUTTON_Sin, &CCalculatorDlg::OnBnClickedButtonSin)
	ON_BN_CLICKED(IDC_BUTTON_Cos, &CCalculatorDlg::OnBnClickedButtonCos)
	ON_BN_CLICKED(IDC_BUTTON_Tan, &CCalculatorDlg::OnBnClickedButtonTan)
	ON_BN_CLICKED(IDC_BUTTON_Plus, &CCalculatorDlg::OnBnClickedButtonPlus)
	ON_BN_CLICKED(IDC_BUTTON_Sub, &CCalculatorDlg::OnBnClickedButtonSub)
	ON_BN_CLICKED(IDC_BUTTON_Multi, &CCalculatorDlg::OnBnClickedButtonMulti)
	ON_BN_CLICKED(IDC_BUTTON_Div, &CCalculatorDlg::OnBnClickedButtonDiv)
	ON_BN_CLICKED(IDC_BUTTON_Equal, &CCalculatorDlg::OnBnClickedButtonEqual)
	ON_BN_CLICKED(IDC_BUTTON_Point, &CCalculatorDlg::OnBnClickedButtonPoint)
	ON_BN_CLICKED(IDC_BUTTON_Clear, &CCalculatorDlg::OnBnClickedButtonClear)

END_MESSAGE_MAP()


// CCalculatorDlg message handlers

BOOL CCalculatorDlg::OnInitDialog()
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

void CCalculatorDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CCalculatorDlg::OnPaint()
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
HCURSOR CCalculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CCalculatorDlg::OnBnClickedButtonNum0()
{
	// TODO: Add your control notification handler code here
	if (user_Flag == true) {
		str1 += _T("0");
		edit_result = str1;
		
	}
	else
	{
		str2 += _T("0");
		edit_result = str2;
	}
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedButtonNum1()
{
	// TODO: Add your control notification handler code here
	if (user_Flag == true) {
		str1 += _T("1");
		edit_result = str1;
		
	}
	else
	{
		str2 += _T("1");
		edit_result = str2;
	}
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedButtonNum2()
{
	// TODO: Add your control notification handler code here
	if (user_Flag == true) {
		str1 += _T("2");
		edit_result = str1;

	}
	else
	{
		str2 += _T("2");
		edit_result = str2;
	}
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedButtonNum3()
{
	// TODO: Add your control notification handler code here
	if (user_Flag == true) {
		str1 += _T("3");
		edit_result = str1;

	}
	else
	{
		str2 += _T("3");
		edit_result = str2;
	}
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedButtonNum4()
{
	// TODO: Add your control notification handler code here
	if (user_Flag == true) {
		str1 += _T("4");
		edit_result = str1;

	}
	else
	{
		str2 += _T("4");
		edit_result = str2;
	}
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedButtonNum5()
{
	// TODO: Add your control notification handler code here
	if (user_Flag == true) {
		str1 += _T("5");
		edit_result = str1;

	}
	else
	{
		str2 += _T("5");
		edit_result = str2;
	}
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedButtonNum6()
{
	// TODO: Add your control notification handler code here
	if (user_Flag == true) {
		str1 += _T("6");
		edit_result = str1;

	}
	else
	{
		str2 += _T("6");
		edit_result = str2;
	}
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedButtonNum7()
{
	// TODO: Add your control notification handler code here
	if (user_Flag == true) {
		str1 += _T("7");
		edit_result = str1;

	}
	else
	{
		str2 += _T("7");
		edit_result = str2;
	}
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedButtonNum8()
{
	// TODO: Add your control notification handler code here
	if (user_Flag == true) {
		str1 += _T("8");
		edit_result = str1;

	}
	else
	{
		str2 += _T("8");
		edit_result = str2;
	}
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedButtonNum9()
{
	// TODO: Add your control notification handler code here
	if (user_Flag == true) {
		str1 += _T("9");
		edit_result = str1;

	}
	else
	{
		str2 += _T("9");
		edit_result = str2;
	}
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedButtonSin()
{
	// TODO: Add your control notification handler code here
	/*if (edit_result != _T("")) {
		num1 = _ttof(edit_result);
		user_Flag = !user_Flag;
		edit_result = _T("");
		Flag = 5;
	}*/
	MessageBox(_T("This function is under maintenance"), _T("Sorry !!"), MB_OK | MB_ICONINFORMATION);

}


void CCalculatorDlg::OnBnClickedButtonCos()
{
	// TODO: Add your control notification handler code here
	MessageBox(_T("This function is under maintenance"), _T("Sorry !!"), MB_OK | MB_ICONINFORMATION);
	/*if (edit_result != _T("")) {
		num1 = _ttof(edit_result);
		user_Flag = !user_Flag;
		edit_result = _T("");
		Flag = 6;
	}
	*/
}


void CCalculatorDlg::OnBnClickedButtonTan()
{
	// TODO: Add your control notification handler code here
	/*if (edit_result != _T("")) {
		num1 = _ttof(edit_result);
		user_Flag = !user_Flag;
		edit_result = _T("");
		Flag = 7;
	}*/
	MessageBox(_T("This function is under maintenance"), _T("Sorry !!"), MB_OK | MB_ICONINFORMATION);

}

void CCalculatorDlg::OnBnClickedButtonPlus()
{
	// TODO: Add your control notification handler code here
	if (edit_result != _T("")) {
		num1 = _ttof(edit_result);
		user_Flag = !user_Flag;
		edit_result = _T("");
		Flag = 1;
	}
}


void CCalculatorDlg::OnBnClickedButtonSub()
{
	// TODO: Add your control notification handler code here
	if (edit_result != _T("")) {
		num1 = _ttof(edit_result);
		user_Flag = !user_Flag;
		edit_result = _T("");
		Flag = 2;
	}
}


void CCalculatorDlg::OnBnClickedButtonMulti()
{
	// TODO: Add your control notification handler code here
	if (edit_result != _T("")) {
		num1 = _ttof(edit_result);
		user_Flag = !user_Flag;
		edit_result = _T("");
		Flag = 3;
	}
}


void CCalculatorDlg::OnBnClickedButtonDiv()
{
	// TODO: Add your control notification handler code here
	
	if (edit_result != _T("") && user_Flag == true) {
		cal_str += "/";
		num1 = _ttof(edit_result);
		user_Flag = !user_Flag;
		edit_result = _T("");
		Flag = 4;
	}
}


void CCalculatorDlg::OnBnClickedButtonEqual()
{
	// TODO: Add your control notification handler code here
	if (edit_result != _T("")) {
		num2 = _ttof(edit_result);
		user_Flag = !user_Flag;
		edit_result = _T("");
	}
	if (Flag == 1) {
		result = num1 + num2;
	}
	if (Flag == 2) {
		result = num1 - num2;
	}
	if (Flag == 3) {
		result = num1 * num2 ;
	}
	if (Flag == 4) {
		result = num1 / num2; 
	}
	if (Flag == 5) {
		
	}
	edit_result.Format(_T("%.3lf"), result);
	UpdateData(FALSE);
	str1 = _T("");
	str2 = _T("");
}


void CCalculatorDlg::OnBnClickedButtonPoint()
{
	// TODO: Add your control notification handler code here
	if (user_Flag == true) {
		str1 += _T(".");
		edit_result = str1;

	}
	else
	{
		str2 += _T(".");
		edit_result = str2;
	}
	UpdateData(FALSE);

}


void CCalculatorDlg::OnEnChangeEdit1()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void CCalculatorDlg::OnBnClickedButtonClear()
{
	if (edit_result != _T("")) {
		edit_result = str1 = str2 = _T("");
		num1 = num2 = result = 0;
	}
	UpdateData(FALSE);
}

