// MyText.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "GhostMan.h"
#include "MyText.h"


// CMyText

IMPLEMENT_DYNAMIC(CMyText, CStatic)

CMyText::CMyText()
{

}

CMyText::~CMyText()
{
}


BEGIN_MESSAGE_MAP(CMyText, CStatic)
	ON_WM_CTLCOLOR_REFLECT()
END_MESSAGE_MAP()



// CMyText ��Ϣ�������

HBRUSH CMyText::CtlColor(CDC* pDC, UINT /*nCtlColor*/)
{
	// TODO:  �ڴ˸��� DC ���κ�����

	// TODO:  �����Ӧ���ø����Ĵ�������򷵻ط� null ����
	pDC->SetBkMode(TRANSPARENT);
	pDC->SetTextColor(RGB(75, 75, 75));

	return (HBRUSH) ::GetStockObject(NULL_BRUSH);
	
}

LRESULT CMyText::DefWindowProc(UINT message, WPARAM wParam, LPARAM lParam)
{
	// TODO: �ڴ����ר�ô����/����û���

/*	if (message == WM_SETTEXT)
	{
		CRect rect;
		GetWindowRect(&rect);
		CWnd* pParent = GetParent();

		if (pParent)
		{
			pParent->ScreenToClient(&rect);
			pParent->InvalidateRect(&rect);
		}
	}*/

	return CStatic::DefWindowProc(message, wParam, lParam);
}
