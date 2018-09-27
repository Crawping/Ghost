// ExecStatic.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "GhostMan.h"
#include "ExecStatic.h"


// CExecStatic

IMPLEMENT_DYNAMIC(CExecStatic, CStatic)

CExecStatic::CExecStatic()
{

}

CExecStatic::~CExecStatic()
{
}


BEGIN_MESSAGE_MAP(CExecStatic, CStatic)
	ON_WM_MOUSEMOVE()
	ON_WM_MOUSELEAVE()
	ON_WM_MOUSEHOVER()
	ON_WM_SETCURSOR()
END_MESSAGE_MAP()



// CExecStatic ��Ϣ�������



void CExecStatic::OnMouseMove(UINT nFlags, CPoint point)
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


void CExecStatic::OnMouseLeave()
{


	HINSTANCE hIns = AfxFindResourceHandle(MAKEINTRESOURCE(IDB_BITMAP_EXEC_NORMAL), RT_GROUP_ICON);
	HBITMAP   hBmp = ::LoadBitmap(hIns, MAKEINTRESOURCE(IDB_BITMAP_EXEC_NORMAL));
	SetBitmap(hBmp);

	CStatic::OnMouseLeave();
}

void CExecStatic::OnMouseHover(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	HINSTANCE hIns = AfxFindResourceHandle(MAKEINTRESOURCE(IDB_BITMAP_EXEC_HOVER), RT_GROUP_ICON);
	HBITMAP   hBmp = ::LoadBitmap(hIns, MAKEINTRESOURCE(IDB_BITMAP_EXEC_HOVER));
	SetBitmap(hBmp);

	CStatic::OnMouseHover(nFlags, point);
}

BOOL CExecStatic::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	// ʹ���Լ��������ƺ�����
	::SetCursor(::LoadCursorW(NULL, IDC_HAND));
	return TRUE;
}
