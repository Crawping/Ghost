// MyStatic.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "GhostMan.h"
#include "MyStatic.h"


// CMyStatic

IMPLEMENT_DYNAMIC(CMyStatic, CStatic)

CMyStatic::CMyStatic()
{

}

CMyStatic::~CMyStatic()
{
}


BEGIN_MESSAGE_MAP(CMyStatic, CStatic)
	ON_WM_PAINT()
END_MESSAGE_MAP()



// CMyStatic ��Ϣ�������




void CMyStatic::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO:  �ڴ˴������Ϣ����������
	// ��Ϊ��ͼ��Ϣ���� CStatic::OnPaint()

//	UpdateWindow();
}
