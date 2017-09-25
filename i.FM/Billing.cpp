// Billing.cpp : implementation file
//

#include "stdafx.h"
#include "i.FM.h"
#include "Billing.h"
#include "afxdialogex.h"
#include <string>


// CBilling dialog

IMPLEMENT_DYNAMIC(CBilling, CDialogEx)

CBilling::CBilling(CWnd* pParent /*=NULL*/)
	: CDialogEx(CBilling::IDD, pParent)
{
	m_callingCount = 0;
}

CBilling::~CBilling()
{
}

void CBilling::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BILLING_LISTCTRL, m_ListCtrl);
	DDX_Control(pDX, IDC_PRICE_EDITCTRL, m_wndEdit);
	DDX_Control(pDX, IDC_DISCOUNT_EDITCTRL, m_DiscountEdtCtrl);
	DDX_Control(pDX, IDC_ADD_DISCOUNT_EDTCTRL, m_AddDiscountEdtCtrl);
	DDX_Control(pDX, IDC_EDIT3, m_TotalValue);
	DDX_Control(pDX, IDC_DELETE_BTN, m_DeleteBtn);
	DDX_Control(pDX, IDC_PRINT_BTN, m_PrintBtn);
	DDX_Control(pDX, IDC_STATIC_CURRENTDATE, m_CurrentDate);
	DDX_Control(pDX, IDC_BILLNO_EDTCTRL, m_BillNoEdtCtrl);
}


BEGIN_MESSAGE_MAP(CBilling, CDialogEx)
END_MESSAGE_MAP()


// CBilling message handlers
BOOL CBilling::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
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
	//m_ListCtrl.SetImageList(&m_imgList, LVSIL_SMALL);
	//FillListBox();
	m_ListCtrl.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES | LVS_EX_AUTOSIZECOLUMNS);
	AddColumns();
	FillListBox();

	CTime t = CTime::GetCurrentTime();
    CString s = t.Format("%d/%m/%Y");
	m_CurrentDate.SetWindowTextW(s);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CBilling::AddColumns()
{
	m_ListCtrl.InsertColumn(0, L"S.No", LVCFMT_CENTER, 50);
	m_ListCtrl.InsertColumn(1, L"Item Name", LVCFMT_CENTER, 400);
	m_ListCtrl.InsertColumn(2, L"Rate/Piece", LVCFMT_CENTER, 70);
	m_ListCtrl.InsertColumn(3, L"Quantity", LVCFMT_CENTER, 70);
	m_ListCtrl.InsertColumn(4, L"Price", LVCFMT_CENTER, 160);	
}

void CBilling::FillListBox()
{
	int count = vecDetails.size();
	for(int i = 0; i < count; i++)
	{
		m_ListCtrl.InsertItem(i, ConvertIntToWstr(i+1).c_str());
		m_ListCtrl.SetItemText(i, 1, vecDetails[i].wstrProName);
		m_ListCtrl.SetItemText(i, 2, ConvertIntToWstr(vecDetails[i].iQuantity).c_str());
		m_ListCtrl.SetItemText(i, 3, ConvertIntToWstr(vecDetails[i].iQuantity).c_str());
		m_ListCtrl.SetItemText(i, 4, ConvertIntToWstr(vecDetails[i].dPrice).c_str());
		m_ListCtrl.SetCellEditor(i, 3, &m_wndEdit);
	}
}

BOOL CBilling::InsertScanedProduct(productDetails pInsertDetails)
{
	vecDetails.push_back(pInsertDetails);
	if(m_callingCount != 0)
		FillListBox();
	m_callingCount++;
	return TRUE;
}

std::wstring CBilling::ConvertIntToWstr(int value)
{
	wchar_t buffer [33];
	_itow (value, buffer, 10);
	std::wstring wstrValue (buffer);
	return wstrValue;
}
