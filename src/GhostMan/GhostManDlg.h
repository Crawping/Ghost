
// GhostManDlg.h : ͷ�ļ�
//

#pragma once
#include "SetStartStatic.h"
#include "SetEndStatic.h"
#include "MyText.h"
#include "MinStatic.h"
#include "CloseStatic.h"
#include "AStarStatic.h"
#include "BFSStatic.h"
#include "DFSStatic.h"
#include "IDAStarStatic.h"
#include "ACOStatic.h"
#include "InitStatic.h"
#include "ExecStatic.h"
#include "StepStatic.h"
#include "DynamicStatic.h"
#include "STStatic.h"
#include "MyStatic.h"
#include "afxwin.h"
#include <algorithm>

#define MAXX 	20			//��ͼ���߶� 
#define MAXY	40			//��ͼ����� 
#define wall 	-1			//ǽ�� 
#define grass   4			//�ݵ�
#define swamp	3			//����  
#define water 	2			//ˮ 
#define road  	1			//½��
#define visited 5			//����·���ʹ���

#define IDT_DELAY_DRAWGRID		0x1001
#define IDT_DELAY_CLOSEGRID		0x1002
#define IDT_DELAY_DRAWIDAPANDA	0x1003
#define IDT_DELAY_DRAWIDAGRID   0x1004
#define IDT_DELAY_REPAINT		0x1005
#define IDT_DELAY_FLICKER		0x1006


#define WM_REPAINT_GRID			WM_USER+1
#define WM_PAINT_PANDA          WM_USER+2

#define clr( a, b ) memset( a, b, sizeof(a) )

#define NUM						20

struct Point{
	int x, y;
	unsigned long long time;
	int pre_x, pre_y;
	int deep;
	int h, g, f;
	Point(){ };
	Point(int _x, int _y, long long _time, int _deep){
		x = _x;
		y = _y;
		time = _time;
		deep = _deep;
	}
	bool operator < (const Point b) const {
		if (f == b.f){
			return deep > b.deep;
		}
		else{
			return f > b.f;
		}
		//return f > b.f;
	}
};

struct SAPoint{
	double x, y, v;
	SAPoint() {};
	SAPoint(double _x, double _y) : x(_x), y(_y) { };
};

//��Ҫ���������ͼ��Ϣ 
struct IDA_S{
	int maze[3][3];
	int x, y;
	int step, pre;
	int h;
};

// CGhostManDlg �Ի���
class CGhostManDlg : public CDialogEx
{
// ����
public:
	CGhostManDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_GHOSTMAN_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnMenuExit();

	int m_nWidth;			//һ������Ŀ��
	int m_nHeight;			//һ������ĸ߶�

	int m_nStartX;			//��������Ŀؼ�X�������
	int m_nStartY;			//��������Ŀؼ�Y�������

	BOOL m_bSetStart;		//�Ƿ���Ҫ�������
	BOOL m_bSetEnd;			//�Ƿ���Ҫ�����յ�

	BOOL m_bHaveAStart;		//�Ƿ��Ѿ���һ�����
	BOOL m_bHaveAEnd;		//�Ƿ��Ѿ���һ���յ�

	BOOL m_bInternalShow;	//�Ƿ�ִ̬��

	BOOL m_bFirstStep;		//�Ƿ��һ�ν��뵥��
	BOOL m_bByStep;			//�����ָ�����ִ�е��Զ�ִ��
	BOOL m_bClickStep;		//�Ƿ����˵���ִ�а�ť

	BOOL m_bHaveARoad;		//�Ƿ��Ѿ��ҵ���һ��·��

	BOOL m_bleftButtonDown;
	BOOL m_bInitGhostMan;
	BOOL m_bNeedRepaint;

	BOOL m_bInitSquared;

	CPoint m_mousePoint;

	int m_nAvailableStartX;	//���X����
	int m_nAvailableStartY;	//���Y����

	int m_nAvailableEndX;	//�յ�X����
	int m_nAvailableEndY;   //�յ�Y����

	int m_nAlgorithmIndex;
	int m_nExeCount;

	int m_nCurPandaIndex;

	int m_nFlickerIndex;
	int m_nFlickerTimer;
	BOOL m_bHaveAResult;

	CSetStartStatic m_btnSetStart;
	CSetEndStatic m_btnSetEnd;

	CMinStatic m_btnMin;
	CCloseStatic m_btnClose;
	CAStarStatic m_btnAStar;
	CBFSStatic m_btnBFS;
	CDFSStatic m_btnDFS;
	CIDAStarStatic m_btnIDAStar;
	CACOStatic m_btnSA;
	CInitStatic m_btnInit;
	CExecStatic m_btnExec;
	CStepStatic m_btnStep;
	CDynamicStatic m_btnDynamic;
	CSTStatic m_btnST;

	CBitmap m_BitMap;
	CDC		m_Dc;
	CDC		m_GridDc;

	int m_nOriGridBottom;
	int m_nOriGridTop;
	int m_nOriGridLeft;
	int m_nOriGridRight;

	int m_nCurGridLeft;
	int m_nCurGridBottom;
	int m_nCurGridTop;
	int m_nCurGridRight;

	int m_nIDAGridStartX;
	int m_nIDAGridStartY;

	int m_nIDACurGridX;
	int m_nIDACurGridY;

	int m_nHidedPandaIndex;


	CRect m_rcPanda[9];
	void CGhostManDlg::DrawGrid();
	void CGhostManDlg::DrawAColor(int nx, int ny, COLORREF color);
	void CGhostManDlg::DrawCurMazeColor();
	void CGhostManDlg::DrawInitMazeColor();
	void CGhostManDlg::DrawInitDerrick();
	void CGhostManDlg::DrawCurDerrick();
	void CGhostManDlg::DrawInitSAMaze();
	void CGhostManDlg::DrawNewSAMaze();
	bool CGhostManDlg::BFS();
	bool CGhostManDlg::DFS();
	bool CGhostManDlg::ExDFS();
	bool CGhostManDlg::ExBFS();
	bool CGhostManDlg::Check(int x, int y);
	bool CGhostManDlg::IDA_check(IDA_S s);
	void CGhostManDlg::Get_Path();
	int  CGhostManDlg::h(Point p);
	int CGhostManDlg::IDA_h(IDA_S s);
	bool CGhostManDlg::Astar();
	bool CGhostManDlg::ExAstar();
	bool CGhostManDlg::IDA_star(IDA_S s);
	int CGhostManDlg::IDA_dfs(IDA_S s);

	void CGhostManDlg::rota_A();
	void CGhostManDlg::rota_F();
	void CGhostManDlg::rota_B();
	void CGhostManDlg::rota_E();
	void CGhostManDlg::rota_C();
	void CGhostManDlg::rota_H();
	void CGhostManDlg::rota_D();
	void CGhostManDlg::rota_G();
	void CGhostManDlg::Derrick_IDAstar();
	int CGhostManDlg::Derrick_h();
	bool CGhostManDlg::Derrick_check();
	bool CGhostManDlg::Derrick_dfs(int d);
	void CGhostManDlg::InitDerrick();

	double CGhostManDlg::SA_Rand();
	SAPoint CGhostManDlg::SA_gen_p(SAPoint a, SAPoint b);
	void CGhostManDlg::SA(double T);
	double CGhostManDlg::SA_dis(SAPoint a, SAPoint b);
	double CGhostManDlg::SA_check(SAPoint t);

	void CGhostManDlg::InitDC();
	void CGhostManDlg::DrawDC();
	void CGhostManDlg::Final_BFS();
	void CGhostManDlg::Final_DFS();
	void CGhostManDlg::Final_ASTAR();
	void CGhostManDlg::Final_IDAStar();
	void CGhostManDlg::Final_SA();

	void CGhostManDlg::RandIDAGrid();					//���ܱȽϺ�ʱ
	bool CGhostManDlg::CheckNum(int nNum, int nIndex);
	

	CPoint CGhostManDlg::GetMazeCenter(int x, int y);	//��õ�ͼһ�����������

	void CGhostManDlg::MovePandaToZero();
	void CGhostManDlg::MovePandaToInit();

	void CGhostManDlg::InitStatus();					//��ʼ������״̬
	void CGhostManDlg::InitBFStatus();					//��ʼ��BFS�㷨״̬
	void CGhostManDlg::InitDFStatus();
	void CGhostManDlg::InitAstartatus();
	void CGhostManDlg::InitIDAstarstatus();

	void CGhostManDlg::ClearAlgorithmCursor();

	static DWORD CGhostManDlg::RandIDAGridFunction(LPARAM lParam);
	static DWORD CGhostManDlg::ExpandBFSFunction(LPARAM lParam);
	static DWORD CGhostManDlg::ExpandAstarFunction(LPARAM lParam);
	static DWORD CGhostManDlg::ExpandDFSFunction(LPARAM lParam);
	static DWORD CGhostManDlg::ExpandIDAStarFunction(LPARAM lParam); 
	static DWORD CGhostManDlg::ExpandDerrickIDAFunction(LPARAM lParam);
	
	LRESULT OnRepaintGrid(WPARAM wParam, LPARAM lParam);
	LRESULT OnPaintPanda(WPARAM wParam, LPARAM lParam);

	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnStnClickedStaticSetstart();
	afx_msg void OnStnClickedStaticSetend();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnMouseLeave();
	
	afx_msg void OnStnClickedStaticClose();
	afx_msg void OnStnClickedStaticMin();
	afx_msg void OnStnClickedStaticMax();	
	afx_msg void OnStnClickedStaticAstar();
	afx_msg void OnStnClickedStaticDynamic();
	afx_msg void OnStnClickedStaticInit();
	afx_msg void OnStnClickedStaticExec();
	afx_msg void OnStnClickedStaticStep();
	afx_msg void OnStnClickedStaticStatic();
	afx_msg void OnStnClickedStaticBfs();
	afx_msg void OnStnClickedStaticDfs();
	afx_msg void OnStnClickedStaticIdastar();
	afx_msg void OnStnClickedStaticSA();
	afx_msg void OnMove(int x, int y);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	CStatic m_btnPanda1;
	CStatic m_btnPanda2;
	CStatic m_btnPanda3;
	CStatic m_btnPanda4;
	CStatic m_btnPanda5;
	CStatic m_btnPanda6;
	CStatic m_btnPanda7;
	CStatic m_btnPanda8;
	CStatic m_btnPanda9;
};
