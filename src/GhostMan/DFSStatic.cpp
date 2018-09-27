// DFSStatic.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "GhostMan.h"
#include "DFSStatic.h"


// CDFSStatic

IMPLEMENT_DYNAMIC(CDFSStatic, CStatic)

CDFSStatic::CDFSStatic()
{
	m_nClicked = 0;
}

CDFSStatic::~CDFSStatic()
{
}


BEGIN_MESSAGE_MAP(CDFSStatic, CStatic)
	ON_WM_MOUSEMOVE()
	ON_WM_MOUSELEAVE()
	ON_WM_MOUSEHOVER()
	ON_WM_SETCURSOR()
END_MESSAGE_MAP()



// CDFSStatic ��Ϣ�������


void CDFSStatic::OnMouseMove(UINT nFlags, CPoint point)
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


void CDFSStatic::OnMouseLeave()
{

	if (m_nClicked)
	{
		HINSTANCE hIns = AfxFindResourceHandle(MAKEINTRESOURCE(IDB_BITMAP_DFS_CLICK), RT_GROUP_ICON);
		HBITMAP   hBmp = ::LoadBitmap(hIns, MAKEINTRESOURCE(IDB_BITMAP_DFS_CLICK));
		SetBitmap(hBmp);
	}
	else
	{
		HINSTANCE hIns = AfxFindResourceHandle(MAKEINTRESOURCE(IDB_BITMAP_DFS_NORMAL), RT_GROUP_ICON);
		HBITMAP   hBmp = ::LoadBitmap(hIns, MAKEINTRESOURCE(IDB_BITMAP_DFS_NORMAL));
		SetBitmap(hBmp);
	}


	CStatic::OnMouseLeave();
}

void CDFSStatic::OnMouseHover(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	HINSTANCE hIns = AfxFindResourceHandle(MAKEINTRESOURCE(IDB_BITMAP_DFS_CLICK), RT_GROUP_ICON);
	HBITMAP   hBmp = ::LoadBitmap(hIns, MAKEINTRESOURCE(IDB_BITMAP_DFS_CLICK));
	SetBitmap(hBmp);

	CStatic::OnMouseHover(nFlags, point);
}

BOOL CDFSStatic::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	// ʹ���Լ��������ƺ�����
	::SetCursor(::LoadCursorW(NULL, IDC_HAND));
	return TRUE;
}
