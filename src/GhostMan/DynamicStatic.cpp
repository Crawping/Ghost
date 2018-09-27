// DynamicStatic.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "GhostMan.h"
#include "DynamicStatic.h"


// CDynamicStatic

IMPLEMENT_DYNAMIC(CDynamicStatic, CStatic)

CDynamicStatic::CDynamicStatic()
{

}

CDynamicStatic::~CDynamicStatic()
{
}


BEGIN_MESSAGE_MAP(CDynamicStatic, CStatic)
	ON_WM_MOUSEMOVE()
	ON_WM_MOUSELEAVE()
	ON_WM_MOUSEHOVER()
	ON_WM_SETCURSOR()
END_MESSAGE_MAP()



// CDynamicStatic ��Ϣ�������

void CDynamicStatic::OnMouseMove(UINT nFlags, CPoint point)
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


void CDynamicStatic::OnMouseLeave()
{


	HINSTANCE hIns = AfxFindResourceHandle(MAKEINTRESOURCE(IDB_BITMAP_DYNAMIC_NORMAL), RT_GROUP_ICON);
	HBITMAP   hBmp = ::LoadBitmap(hIns, MAKEINTRESOURCE(IDB_BITMAP_DYNAMIC_NORMAL));
	SetBitmap(hBmp);

	CStatic::OnMouseLeave();
}

void CDynamicStatic::OnMouseHover(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	HINSTANCE hIns = AfxFindResourceHandle(MAKEINTRESOURCE(IDB_BITMAP_DYNAMIC_HOVER), RT_GROUP_ICON);
	HBITMAP   hBmp = ::LoadBitmap(hIns, MAKEINTRESOURCE(IDB_BITMAP_DYNAMIC_HOVER));
	SetBitmap(hBmp);

	CStatic::OnMouseHover(nFlags, point);
}

BOOL CDynamicStatic::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	// ʹ���Լ��������ƺ�����
	::SetCursor(::LoadCursorW(NULL, IDC_HAND));
	return TRUE;
}

