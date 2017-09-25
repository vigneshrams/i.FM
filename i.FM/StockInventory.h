#pragma once


// CStockInventory dialog

class CStockInventory : public CDialogEx
{
	DECLARE_DYNAMIC(CStockInventory)

public:
	CStockInventory(CWnd* pParent = NULL);   // standard constructor
	virtual ~CStockInventory();

// Dialog Data
	enum { IDD = IDD_STOCK };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
