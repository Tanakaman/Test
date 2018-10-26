#pragma once

/// <summary>
/// プロジェクト全体で共有するヘッダを表します.
/// </summary>

#define _CRT_SECURE_NO_WARNINGS

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <mmsystem.h>
#include <string.h>
#include <process.h>
#include <time.h>
#include <stdlib.h>
#include <assert.h>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <dxgi.h>
#include <dxgiformat.h>
#include <windef.h>
#include <xutility>
#include "DxLib.h"

// メモリリークチェックの有効化を行います.
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>

// マクロによりnewした場所を出力します.
#if _DEBUG
#define NEW	new( _NORMAL_BLOCK, __FILE__, __LINE__ )
#else
#define NEW	new
#endif

#define DEBUG_LOG( Message ) printf( "%s\n %s (%d)\n", Message, __FILE__, __LINE__ );

#define DEBUG_LOG_ERROR( Message ) printf( "%s\n %s (%d)\n", Message, __FILE__, __LINE__ );

/// <summary>
/// Releaseインターフェース用の解放処理を行います.
/// </summary>
template<class T>
static void SafeRelease(T* Target)
{
    if ( Target != nullptr )
    {
        Target->Release();
        Target = nullptr;
    }
};

/// <summary>
/// n次元配列の初期化を行います.
/// </summary>
template<typename A, size_t N, typename T>
static void Fill(A(&Array)[N], const T &Val)
{
    std::fill((T*)Array, (T*)(Array + N), Val);
}