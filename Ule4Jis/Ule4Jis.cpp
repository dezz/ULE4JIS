// Ule4Jis.cpp : アプリケーションのクラス動作を定義します。
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


// Ule4JisApp コンストラクション

Ule4JisApp::Ule4JisApp()
{
	// TODO: この位置に構築用コードを追加してください。
	// ここに InitInstance 中の重要な初期化処理をすべて記述してください。
}


// 唯一の Ule4JisApp オブジェクトです。

Ule4JisApp theApp;


// Ule4JisApp 初期化

BOOL Ule4JisApp::InitInstance()
{
	// アプリケーション マニフェストが visual スタイルを有効にするために、
	// ComCtl32.dll Version 6 以降の使用を指定する場合は、
	// Windows XP に InitCommonControlsEx() が必要です。さもなければ、ウィンドウ作成はすべて失敗します。
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// アプリケーションで使用するすべてのコモン コントロール クラスを含めるには、
	// これを設定します。
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();

	// 標準初期化
	// これらの機能を使わずに最終的な実行可能ファイルの
	// サイズを縮小したい場合は、以下から不要な初期化
	// ルーチンを削除してください。
	// 設定が格納されているレジストリ キーを変更します。
	// TODO: 会社名または組織名などの適切な文字列に
	// この文字列を変更してください。
//	SetRegistryKey(_T("アプリケーション ウィザードで生成されたローカル アプリケーション"));

	// prevent multiple boot
	::CreateMutex(NULL, TRUE, m_pszExeName);
	if (::GetLastError() == ERROR_ALREADY_EXISTS) {
		CString msg;
		msg.LoadString(IDS_MSG_MULTIPLE_BOOT_ERROR);
		::MessageBox(NULL, msg, NULL, MB_OK | MB_ICONEXCLAMATION);
		return FALSE;
	}

	Ule4JisDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: ダイアログが <OK> で消された時のコードを
		//  記述してください。
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: ダイアログが <キャンセル> で消された時のコードを
		//  記述してください。
	}

	// ダイアログは閉じられました。アプリケーションのメッセージ ポンプを開始しないで
	//  アプリケーションを終了するために FALSE を返してください。
	return FALSE;
}
