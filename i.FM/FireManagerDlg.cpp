// CFireManagerDlg.cpp : implementation file
//

#include "stdafx.h"
#include "i.FM.h"
#include "FireManagerDlg.h"
#include "afxdialogex.h"
#include "Billing.h"

// CFireManagerDlg dialog

IMPLEMENT_DYNAMIC(CFireManagerDlg, CDialogEx)

CFireManagerDlg::CFireManagerDlg(CString strUser, CWnd* pParent /*=NULL*/)
	: CDialogEx(CFireManagerDlg::IDD, pParent)
	,m_strUser(strUser)
{

}

CFireManagerDlg::~CFireManagerDlg()
{
}

void CFireManagerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, ID_Stock, m_ctlStock);
	DDX_Control(pDX, ID_Billing, m_ctlBilling);
	DDX_Control(pDX, ID_Report, m_ctlReport);
}


BEGIN_MESSAGE_MAP(CFireManagerDlg, CDialogEx)
	ON_BN_CLICKED(ID_Stock, &CFireManagerDlg::OnBnClickedStock)
	ON_BN_CLICKED(ID_Billing, &CFireManagerDlg::OnBnClickedBilling)
	ON_BN_CLICKED(ID_Report, &CFireManagerDlg::OnBnClickedReport)
END_MESSAGE_MAP()


// CFireManagerDlg message handlers
BOOL CFireManagerDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	if(m_strUser.CompareNoCase(_T("User"))==0 )
	{
		m_ctlStock.ShowWindow(false);
		m_ctlReport.ShowWindow(false);
	}
	return TRUE;
}

void CFireManagerDlg::OnBnClickedStock()
{
	// TODO: Add your control notification handler code here
}


void CFireManagerDlg::OnBnClickedBilling()
{
	CBilling billingDlg;
	billingDlg.detailsStruct.wstrProName = L"Standard Crackers";
	billingDlg.detailsStruct.iQuantity = 100;
	billingDlg.detailsStruct.dPrice = 1000;
	billingDlg.InsertScanedProduct(billingDlg.detailsStruct);
	billingDlg.DoModal();
}


void CFireManagerDlg::OnBnClickedReport()
{
	// TODO: Add your control notification handler code here
}
