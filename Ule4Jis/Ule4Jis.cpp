// Ule4Jis.cpp : �A�v���P�[�V�����̃N���X������`���܂��B
//

#include "stdafx.h"
#include "Ule4Jis.h"
#include "Ule4JisDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Ule4JisApp

BEGIN_MESSAGE_MAP(Ule4JisApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// Ule4JisApp �R���X�g���N�V����

Ule4JisApp::Ule4JisApp()
{
	// TODO: ���̈ʒu�ɍ\�z�p�R�[�h��ǉ����Ă��������B
	// ������ InitInstance ���̏d�v�ȏ��������������ׂċL�q���Ă��������B
}


// �B��� Ule4JisApp �I�u�W�F�N�g�ł��B

Ule4JisApp theApp;


// Ule4JisApp ������

BOOL Ule4JisApp::InitInstance()
{
	// �A�v���P�[�V���� �}�j�t�F�X�g�� visual �X�^�C����L���ɂ��邽�߂ɁA
	// ComCtl32.dll Version 6 �ȍ~�̎g�p���w�肷��ꍇ�́A
	// Windows XP �� InitCommonControlsEx() ���K�v�ł��B�����Ȃ���΁A�E�B���h�E�쐬�͂��ׂĎ��s���܂��B
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// �A�v���P�[�V�����Ŏg�p���邷�ׂẴR���� �R���g���[�� �N���X���܂߂�ɂ́A
	// �����ݒ肵�܂��B
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();

	// �W��������
	// �����̋@�\���g�킸�ɍŏI�I�Ȏ��s�\�t�@�C����
	// �T�C�Y���k���������ꍇ�́A�ȉ�����s�v�ȏ�����
	// ���[�`�����폜���Ă��������B
	// �ݒ肪�i�[����Ă��郌�W�X�g�� �L�[��ύX���܂��B
	// TODO: ��Ж��܂��͑g�D���Ȃǂ̓K�؂ȕ������
	// ���̕������ύX���Ă��������B
	//	SetRegistryKey(_T("�A�v���P�[�V���� �E�B�U�[�h�Ő������ꂽ���[�J�� �A�v���P�[�V����"));

	// prevent multiple boot
	::CreateMutex(nullptr, TRUE, m_pszExeName);
	if (GetLastError() == ERROR_ALREADY_EXISTS)
	{
		CString msg;
		msg.LoadString(IDS_MSG_MULTIPLE_BOOT_ERROR);
		::MessageBox(nullptr, msg, nullptr, MB_OK | MB_ICONEXCLAMATION);
		return FALSE;
	}

	Ule4JisDlg* dlg = new Ule4JisDlg;
	m_pMainWnd = dlg;
	dlg->Create(IDD_ULE4JIS_DIALOG);
	dlg->ShowWindow(SW_SHOW);
	dlg->ShowWindow(SW_MINIMIZE);
	dlg->ShowWindow(SW_HIDE);
	CWinApp::Run();

	return FALSE;
}
