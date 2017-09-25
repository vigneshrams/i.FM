#pragma once

#include "ListCtrlEx.h"
#include "afxcmn.h"
#include <vector>
#include "afxwin.h"
// CBilling dialog

class CBilling : public CDialogEx
{
	DECLARE_DYNAMIC(CBilling)

public:
	CBilling(CWnd* pParent = NULL);   // standard constructor
	virtual ~CBilling();

	BOOL OnInitDialog();

// Dialog Data
	enum { IDD = IDD_DLG_BILLING };

private:
	int  m_callingCount;
	void AddColumns();
	void FillListBox();
	std::wstring ConvertIntToWstr(int value);

protected:
	HICON m_hIcon;

	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CListCtrlEx m_ListCtrl;
	CEdit m_wndEdit;

	struct productDetails
	{
		CString wstrProName;
		int		iQuantity;
		double	dPrice;
	};

	productDetails detailsStruct;
	std::vector <productDetails> vecDetails;

	BOOL InsertScanedProduct(productDetails pInsertDetails);
	CEdit m_DiscountEdtCtrl;
	CEdit m_AddDiscountEdtCtrl;
	CEdit m_TotalValue;
	CButton m_DeleteBtn;
	CButton m_PrintBtn;
	CStatic m_CurrentDate;
	CEdit m_BillNoEdtCtrl;
};
