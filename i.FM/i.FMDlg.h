
// i.FMDlg.h : header file
//

#pragma once


// CiFMDlg dialog
class CiFMDlg : public CDialogEx
{
// Construction
public:
	CiFMDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_IFM_DIALOG };
	CEdit m_ctlUser;
	CEdit m_ctlPassword;
	CString	m_strUser;
	CString	m_strPassword;

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
	afx_msg void OnBnClickedOk();
	afx_msg void OnEnChangetxtpassword();
	afx_msg void OnBnClickedCancel();
};
