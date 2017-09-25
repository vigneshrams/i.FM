#pragma once


// CFireManagerDlg dialog

class CFireManagerDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CFireManagerDlg)

public:
	CFireManagerDlg(CString strUser, CWnd* pParent = NULL);   // standard constructor
	virtual ~CFireManagerDlg();

// Dialog Data
	enum { IDD = IDD_Main };

	CString m_strUser;
	CButton m_ctlStock;
	CButton m_ctlBilling;
	CButton m_ctlReport;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedStock();
	afx_msg void OnBnClickedBilling();
	afx_msg void OnBnClickedReport();
};
