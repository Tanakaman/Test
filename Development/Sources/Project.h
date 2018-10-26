#pragma once

/// <summary>
/// �v���W�F�N�g�S�̂ŋ��L����w�b�_��\���܂�.
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

// ���������[�N�`�F�b�N�̗L�������s���܂�.
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>

// �}�N���ɂ��new�����ꏊ���o�͂��܂�.
#if _DEBUG
#define NEW	new( _NORMAL_BLOCK, __FILE__, __LINE__ )
#else
#define NEW	new
#endif

#define DEBUG_LOG( Message ) printf( "%s\n %s (%d)\n", Message, __FILE__, __LINE__ );

#define DEBUG_LOG_ERROR( Message ) printf( "%s\n %s (%d)\n", Message, __FILE__, __LINE__ );

/// <summary>
/// Release�C���^�[�t�F�[�X�p�̉���������s���܂�.
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
/// n�����z��̏��������s���܂�.
/// </summary>
template<typename A, size_t N, typename T>
static void Fill(A(&Array)[N], const T &Val)
{
    std::fill((T*)Array, (T*)(Array + N), Val);
}