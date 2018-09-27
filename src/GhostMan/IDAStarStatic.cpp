// IDAStarStatic.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "GhostMan.h"
#include "IDAStarStatic.h"


// CIDAStarStatic

IMPLEMENT_DYNAMIC(CIDAStarStatic, CStatic)

CIDAStarStatic::CIDAStarStatic()
{
	m_nClicked = 0;
}

CIDAStarStatic::~CIDAStarStatic()
{
}


BEGIN_MESSAGE_MAP(CIDAStarStatic, CStatic)
	ON_WM_MOUSEMOVE()
	ON_WM_MOUSELEAVE()
	ON_WM_MOUSEHOVER()
	ON_WM_SETCURSOR()
END_MESSAGE_MAP()



// CIDAStarStatic ��Ϣ�������


void CIDAStarStatic::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	TRACKMOUSEEVENT csTME;
	csTME.cbSize = sizeof(csTME);
	csTME.dwFlags = TME_LEAVE | TME_HOVER;
	csTME.hwndTrack = m_hWnd;		// ָ��Ҫ ׷�� �Ĵ��� 
	csTME.dwHoverTime = 10;			// ����ڰ�ť��ͣ������ 10ms ������Ϊ״̬Ϊ HOVER
	::_TrackMouseEvent(&csTME);	// ���� Windows �� WM_MOUSELEAVE �� WM_MOUSEHOVER �¼�֧��
	//	CStatic::OnMouseMove(nFlags, point);
}


void CIDAStarStatic::OnMouseLeave()
{

	if (m_nClicked)
	{
		HINSTANCE hIns = AfxFindResourceHandle(MAKEINTRESOURCE(IDB_BITMAP_IDASTAR_CLICK), RT_GROUP_ICON);
		HBITMAP   hBmp = ::LoadBitmap(hIns, MAKEINTRESOURCE(IDB_BITMAP_IDASTAR_CLICK));
		SetBitmap(hBmp);
	}
	else
	{
		HINSTANCE hIns = AfxFindResourceHandle(MAKEINTRESOURCE(IDB_BITMAP_IDASTAR_NORMAL), RT_GROUP_ICON);
		HBITMAP   hBmp = ::LoadBitmap(hIns, MAKEINTRESOURCE(IDB_BITMAP_IDASTAR_NORMAL));
		SetBitmap(hBmp);
	}


	CStatic::OnMouseLeave();
}

void CIDAStarStatic::OnMouseHover(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	HINSTANCE hIns = AfxFindResourceHandle(MAKEINTRESOURCE(IDB_BITMAP_IDASTAR_CLICK), RT_GROUP_ICON);
	HBITMAP   hBmp = ::LoadBitmap(hIns, MAKEINTRESOURCE(IDB_BITMAP_IDASTAR_CLICK));
	SetBitmap(hBmp);

	CStatic::OnMouseHover(nFlags, point);
}

BOOL CIDAStarStatic::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	// ʹ���Լ��������ƺ�����
	::SetCursor(::LoadCursorW(NULL, IDC_HAND));
	return TRUE;
}
