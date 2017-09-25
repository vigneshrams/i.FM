// StockInventory.cpp : implementation file
//

#include "stdafx.h"
#include "i.FM.h"
#include "StockInventory.h"
#include "afxdialogex.h"


// CStockInventory dialog

IMPLEMENT_DYNAMIC(CStockInventory, CDialogEx)

CStockInventory::CStockInventory(CWnd* pParent /*=NULL*/)
	: CDialogEx(CStockInventory::IDD, pParent)
{

}

CStockInventory::~CStockInventory()
{
}

void CStockInventory::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CStockInventory, CDialogEx)
END_MESSAGE_MAP()


// CStockInventory message handlers
