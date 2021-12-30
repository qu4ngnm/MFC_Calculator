
// CalculatorDlg.h : header file
//

#pragma once


// CCalculatorDlg dialog
class CCalculatorDlg : public CDialogEx
{
// Construction
public:
	CCalculatorDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CALCULATOR_DIALOG };
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
public:
	CString edit_result;
	double num1, num2, result;
	CString str1, str2, cal_str;
	bool user_Flag;
	int Flag;
	afx_msg void OnBnClickedButtonNum0();
	afx_msg void OnBnClickedButtonNum1();
	afx_msg void OnBnClickedButtonNum2();
	afx_msg void OnBnClickedButtonNum3();
	afx_msg void OnBnClickedButtonNum4();
	afx_msg void OnBnClickedButtonNum5();
	afx_msg void OnBnClickedButtonNum6();
	afx_msg void OnBnClickedButtonNum7();
	afx_msg void OnBnClickedButtonNum8();
	afx_msg void OnBnClickedButtonNum9();
	afx_msg void OnBnClickedButtonSin();
	afx_msg void OnBnClickedButtonCos();
	afx_msg void OnBnClickedButtonTan();
	afx_msg void OnBnClickedButtonPlus();
	afx_msg void OnBnClickedButtonSub();
	afx_msg void OnBnClickedButtonMulti();
	afx_msg void OnBnClickedButtonDiv();
	afx_msg void OnBnClickedButtonEqual();
	afx_msg void OnBnClickedButtonPoint();
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnBnClickedButtonClear();
	afx_msg void OnBnClickedButtonNegative();
};
