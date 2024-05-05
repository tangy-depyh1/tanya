// WindowsProject25.cpp : Определяет точку входа для приложения.
//

#include "framework.h"
#include "WindowsProject25.h"
#include "time.h"
#include "stdio.h"

#define MAX_LOADSTRING 100




// Глобальные переменные:
HINSTANCE hInst;                                // текущий экземпляр
WCHAR szTitle[MAX_LOADSTRING];                  // Текст строки заголовка
WCHAR szWindowClass[MAX_LOADSTRING];            // имя класса главного окна

#define DEBUG_GAME

// Отправить объявления функций, включенных в этот модуль кода:

enum Modes {
    START,
    GAME,
    VICTORY,
    LOSS,
    FINAL
};

enum Modes mode = START;

int step = 0;



ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPWSTR    lpCmdLine,
    _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Разместите код здесь.

    // Инициализация глобальных строк
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_WINDOWSPROJECT25, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance(hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WINDOWSPROJECT25));

    MSG msg;

    // Цикл основного сообщения:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int)msg.wParam;
}



//
//  ФУНКЦИЯ: MyRegisterClass()
//
//  ЦЕЛЬ: Регистрирует класс окна.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WINDOWSPROJECT25));
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_WINDOWSPROJECT25);
    wcex.lpszClassName = szWindowClass;
    wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   ФУНКЦИЯ: InitInstance(HINSTANCE, int)
//
//   ЦЕЛЬ: Сохраняет маркер экземпляра и создает главное окно
//
//   КОММЕНТАРИИ:
//
//        В этой функции маркер экземпляра сохраняется в глобальной переменной, а также
//        создается и выводится главное окно программы.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
    hInst = hInstance; // Сохранить маркер экземпляра в глобальной переменной

    HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

    if (!hWnd)
    {
        return FALSE;
    }

    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);

    return TRUE;
}




void drawDog(HDC hdc, int cx, int cy) {
    HBRUSH hBrush1;
    hBrush1 = CreateSolidBrush(RGB(0, 0, 0));
    SelectObject(hdc, hBrush1);
    Rectangle(hdc, 50 - 85 + cx, 10 - 85 + cy, 90 - 85 + cx, 20 - 85 + cy);
    Rectangle(hdc, 40 - 85 + cx, 20 - 85 + cy, 50 - 85 + cx, 30 - 85 + cy);
    Rectangle(hdc, 30 - 85 + cx, 30 - 85 + cy, 40 - 85 + cx, 50 - 85 + cy);
    Rectangle(hdc, 20 - 85 + cx, 50 - 85 + cy, 30 - 85 + cx, 60 - 85 + cy);
    Rectangle(hdc, 10 - 85 + cx, 40 - 85 + cy, 20 - 85 + cx, 50 - 85 + cy);
    Rectangle(hdc, 0 - 85 + cx, 50 - 85 + cy, 10 - 85 + cx, 60 - 85 + cy);
    Rectangle(hdc, 10 - 85 + cx, 60 - 85 + cy, 20 - 85 + cx, 80 - 85 + cy);
    Rectangle(hdc, 20 - 85 + cx, 80 - 85 + cy, 70 - 85 + cx, 90 - 85 + cy);
    Rectangle(hdc, 70 - 85 + cx, 60 - 85 + cy, 80 - 85 + cx, 80 - 85 + cy);
    Rectangle(hdc, 80 - 85 + cx, 80 - 85 + cy, 120 - 85 + cx, 90 - 85 + cy);
    Rectangle(hdc, 110 - 85 + cx, 50 - 85 + cy, 120 - 85 + cx, 90 - 85 + cy);
    Rectangle(hdc, 100 - 85 + cx, 30 - 85 + cy, 110 - 85 + cx, 50 - 85 + cy);
    Rectangle(hdc, 80 - 85 + cx, 20 - 85 + cy, 100 - 85 + cx, 30 - 85 + cy);
    Rectangle(hdc, 50 - 85 + cx, 40 - 85 + cy, 60 - 85 + cx, 60 - 85 + cy);
    Rectangle(hdc, 70 - 85 + cx, 90 - 85 + cy, 80 - 85 + cx, 100 - 85 + cy);
    Rectangle(hdc, 60 - 85 + cx, 100 - 85 + cy, 70 - 85 + cx, 110 - 85 + cy);
    Rectangle(hdc, 50 - 85 + cx, 90 - 85 + cy, 60 - 85 + cx, 140 - 85 + cy);
    Rectangle(hdc, 40 - 85 + cx, 140 - 85 + cy, 50 - 85 + cx, 150 - 85 + cy);
    Rectangle(hdc, 30 - 85 + cx, 150 - 85 + cy, 40 - 85 + cx, 160 - 85 + cy);
    Rectangle(hdc, 40 - 85 + cx, 160 - 85 + cy, 60 - 85 + cx, 170 - 85 + cy);
    Rectangle(hdc, 60 - 85 + cx, 150 - 85 + cy, 70 - 85 + cx, 160 - 85 + cy);
    Rectangle(hdc, 70 - 85 + cx, 140 - 85 + cy, 120 - 85 + cx, 150 - 85 + cy);
    Rectangle(hdc, 120 - 85 + cx, 150 - 85 + cy, 130 - 85 + cx, 160 - 85 + cy);
    Rectangle(hdc, 130 - 85 + cx, 160 - 85 + cy, 150 - 85 + cx, 170 - 85 + cy);
    Rectangle(hdc, 150 - 85 + cx, 150 - 85 + cy, 160 - 85 + cx, 160 - 85 + cy);
    Rectangle(hdc, 140 - 85 + cx, 140 - 85 + cy, 150 - 85 + cx, 150 - 85 + cy);
    Rectangle(hdc, 130 - 85 + cx, 120 - 85 + cy, 140 - 85 + cx, 140 - 85 + cy);
    Rectangle(hdc, 140 - 85 + cx, 110 - 85 + cy, 150 - 85 + cx, 120 - 85 + cy);
    Rectangle(hdc, 150 - 85 + cx, 100 - 85 + cy, 160 - 85 + cx, 110 - 85 + cy);
    Rectangle(hdc, 160 - 85 + cx, 80 - 85 + cy, 170 - 85 + cx, 100 - 85 + cy);
    Rectangle(hdc, 150 - 85 + cx, 70 - 85 + cy, 160 - 85 + cx, 80 - 85 + cy);
    Rectangle(hdc, 140 - 85 + cx, 80 - 85 + cy, 150 - 85 + cx, 90 - 85 + cy);
    Rectangle(hdc, 130 - 85 + cx, 90 - 85 + cy, 140 - 85 + cx, 100 - 85 + cy);
    Rectangle(hdc, 110 - 85 + cx, 100 - 85 + cy, 130 - 85 + cx, 110 - 85 + cy);
    Rectangle(hdc, 100 - 85 + cx, 90 - 85 + cy, 110 - 85 + cx, 100 - 85 + cy);
    DeleteObject(hBrush1);

    HPEN hPen2;
    hPen2 = CreatePen(PS_SOLID, 3, RGB(160, 82, 45));
    SelectObject(hdc, hPen2);
    HBRUSH hBrush2;
    hBrush2 = CreateSolidBrush(RGB(160, 82, 45));
    SelectObject(hdc, hBrush2);
    Rectangle(hdc, 10 - 85 + cx, 50 - 85 + cy, 20 - 85 + cx, 60 - 85 + cy);
    Rectangle(hdc, 80 - 85 + cx, 40 - 85 + cy, 100 - 85 + cx, 80 - 85 + cy);
    Rectangle(hdc, 100 - 85 + cx, 50 - 85 + cy, 110 - 85 + cx, 80 - 85 + cy);
    Rectangle(hdc, 150 - 85 + cx, 80 - 85 + cy, 160 - 85 + cx, 100 - 85 + cy);
    Rectangle(hdc, 140 - 85 + cx, 90 - 85 + cy, 150 - 85 + cx, 110 - 85 + cy);
    Rectangle(hdc, 40 - 85 + cx, 150 - 85 + cy, 60 - 85 + cx, 160 - 85 + cy);
    Rectangle(hdc, 130 - 85 + cx, 150 - 85 + cy, 150 - 85 + cx, 160 - 85 + cy);
    DeleteObject(hBrush2);
    DeleteObject(hPen2);

    HPEN hPen3;
    hPen3 = CreatePen(PS_SOLID, 3, RGB(255, 0, 0));
    SelectObject(hdc, hPen3);
    HBRUSH hBrush3;
    hBrush3 = CreateSolidBrush(RGB(255, 0, 0));
    SelectObject(hdc, hBrush3);
    Rectangle(hdc, 70 - 85 + cx, 80 - 85 + cy, 80 - 85 + cx, 90 - 85 + cy);
    Rectangle(hdc, 60 - 85 + cx, 90 - 85 + cy, 70 - 85 + cx, 100 - 85 + cy);
    DeleteObject(hPen3);
    DeleteObject(hBrush3);

    HPEN hPen4;
    hPen4 = CreatePen(PS_SOLID, 3, RGB(210, 105, 30));
    SelectObject(hdc, hPen4);
    HBRUSH hBrush4;
    hBrush4 = CreateSolidBrush(RGB(210, 105, 30));
    SelectObject(hdc, hBrush4);
    Rectangle(hdc, 20 - 85 + cx, 60 - 85 + cy, 70 - 85 + cx, 80 - 85 + cy);
    Rectangle(hdc, 30 - 85 + cx, 50 - 85 + cy, 50 - 85 + cx, 60 - 85 + cy);
    Rectangle(hdc, 40 - 85 + cx, 30 - 85 + cy, 50 - 85 + cx, 50 - 85 + cy);
    Rectangle(hdc, 50 - 85 + cx, 20 - 85 + cy, 80 - 85 + cx, 40 - 85 + cy);
    Rectangle(hdc, 80 - 85 + cx, 30 - 85 + cy, 100 - 85 + cx, 40 - 85 + cy);
    Rectangle(hdc, 60 - 85 + cx, 40 - 85 + cy, 80 - 85 + cx, 60 - 85 + cy);
    Rectangle(hdc, 80 - 85 + cx, 90 - 85 + cy, 100 - 85 + cx, 140 - 85 + cy);
    Rectangle(hdc, 50 - 85 + cx, 140 - 85 + cy, 70 - 85 + cx, 150 - 85 + cy);
    Rectangle(hdc, 60 - 85 + cx, 110 - 85 + cy, 80 - 85 + cx, 140 - 85 + cy);
    Rectangle(hdc, 70 - 85 + cx, 100 - 85 + cy, 80 - 85 + cx, 110 - 85 + cy);
    Rectangle(hdc, 100 - 85 + cx, 110 - 85 + cy, 130 - 85 + cx, 140 - 85 + cy);
    Rectangle(hdc, 100 - 85 + cx, 100 - 85 + cy, 110 - 85 + cx, 110 - 85 + cy);
    Rectangle(hdc, 130 - 85 + cx, 100 - 85 + cy, 140 - 85 + cx, 120 - 85 + cy);
    Rectangle(hdc, 120 - 85 + cx, 140 - 85 + cy, 140 - 85 + cx, 150 - 85 + cy);
    DeleteObject(hPen4);
    DeleteObject(hBrush4);

#ifdef DEBUG_GAME
    HPEN hPenZone = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
    SelectObject(hdc, hPenZone);
    SelectObject(hdc, GetStockObject(NULL_BRUSH));
    Rectangle(hdc, cx - 70, cy - 70, cx + 70, cy + 70);

    MoveToEx(hdc, cx - 70, cy, NULL);
    LineTo(hdc, cx + 70, cy);
    MoveToEx(hdc, cx, cy - 70, NULL);
    LineTo(hdc, cx, cy + 70);
    DeleteObject(hPenZone);

#endif

}
void drawFish(HDC hdc, int cx, int cy) {
    HPEN hPen5;//рыба 
    hPen5 = CreatePen(PS_SOLID, 3, RGB(255, 255, 0));
    SelectObject(hdc, hPen5);
    HBRUSH hBrush5;
    hBrush5 = CreateSolidBrush(RGB(255, 255, 0));
    SelectObject(hdc, hBrush5);
    Rectangle(hdc, 220 - 240 + cx, 20 - 65 + cy, 240 - 240 + cx, 40 - 65 + cy);
    Rectangle(hdc, 210 - 240 + cx, 30 - 65 + cy, 220 - 240 + cx, 40 - 65 + cy);
    Rectangle(hdc, 220 - 240 + cx, 20 - 65 + cy, 240 - 240 + cx, 40 - 65 + cy);
    Rectangle(hdc, 240 - 240 + cx, 20 - 65 + cy, 250 - 240 + cx, 30 - 65 + cy);
    Rectangle(hdc, 220 - 240 + cx, 20 - 65 + cy, 240 - 240 + cx, 40 - 65 + cy);
    Rectangle(hdc, 210 - 240 + cx, 90 - 65 + cy, 230 - 240 + cx, 100 - 65 + cy);
    Rectangle(hdc, 220 - 240 + cx, 100 - 65 + cy, 240 - 240 + cx, 110 - 65 + cy);
    Rectangle(hdc, 270 - 240 + cx, 50 - 65 + cy, 290 - 240 + cx, 90 - 65 + cy);
    Rectangle(hdc, 280 - 240 + cx, 90 - 65 + cy, 300 - 240 + cx, 100 - 65 + cy);
    Rectangle(hdc, 290 - 240 + cx, 100 - 65 + cy, 300 - 240 + cx, 110 - 65 + cy);
    Rectangle(hdc, 290 - 240 + cx, 30 - 65 + cy, 300 - 240 + cx, 60 - 65 + cy);
    Rectangle(hdc, 280 - 240 + cx, 40 - 65 + cy, 290 - 240 + cx, 50 - 65 + cy);
    DeleteObject(hPen5);
    DeleteObject(hBrush5);

    HPEN hPen6;
    hPen6 = CreatePen(PS_SOLID, 3, RGB(255, 165, 0));
    SelectObject(hdc, hPen6);
    HBRUSH hBrush6;
    hBrush6 = CreateSolidBrush(RGB(255, 165, 0));
    SelectObject(hdc, hBrush6);
    Rectangle(hdc, 190 - 240 + cx, 70 - 65 + cy, 220 - 240 + cx, 90 - 65 + cy);
    Rectangle(hdc, 180 - 240 + cx, 60 - 65 + cy, 190 - 240 + cx, 80 - 65 + cy);
    Rectangle(hdc, 190 - 240 + cx, 50 - 65 + cy, 200 - 240 + cx, 70 - 65 + cy);
    Rectangle(hdc, 200 - 240 + cx, 40 - 65 + cy, 220 - 240 + cx, 60 - 65 + cy);
    Rectangle(hdc, 210 - 240 + cx, 40 - 65 + cy, 220 - 240 + cx, 90 - 65 + cy);
    Rectangle(hdc, 200 - 240 + cx, 90 - 65 + cy, 210 - 240 + cx, 100 - 65 + cy);
    Rectangle(hdc, 230 - 240 + cx, 40 - 65 + cy, 240 - 240 + cx, 100 - 65 + cy);
    Rectangle(hdc, 250 - 240 + cx, 50 - 65 + cy, 260 - 240 + cx, 90 - 65 + cy);
    DeleteObject(hPen6);
    DeleteObject(hBrush6);

    HPEN hPen7;
    hPen7 = CreatePen(PS_SOLID, 3, RGB(255, 0, 0));
    SelectObject(hdc, hPen7);
    HBRUSH hBrush7;
    hBrush7 = CreateSolidBrush(RGB(255, 0, 0));
    SelectObject(hdc, hBrush7);
    Rectangle(hdc, 220 - 240 + cx, 40 - 65 + cy, 230 - 240 + cx, 90 - 65 + cy);
    Rectangle(hdc, 240 - 240 + cx, 40 - 65 + cy, 250 - 240 + cx, 100 - 65 + cy);
    Rectangle(hdc, 260 - 240 + cx, 60 - 65 + cy, 270 - 240 + cx, 80 - 65 + cy);
    DeleteObject(hPen7);
    DeleteObject(hBrush7);

    HPEN hPen8;
    hPen8 = CreatePen(PS_SOLID, 3, RGB(0, 0, 0));
    SelectObject(hdc, hPen8);
    HBRUSH hBrush8;
    hBrush8 = CreateSolidBrush(RGB(0, 0, 0));
    SelectObject(hdc, hBrush8);
    Rectangle(hdc, 200 - 240 + cx, 60 - 65 + cy, 210 - 240 + cx, 70 - 65 + cy);
    DeleteObject(hPen8);
    DeleteObject(hBrush8);

#ifdef DEBUG_GAME
    HPEN hPenZone = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
    SelectObject(hdc, hPenZone);
    SelectObject(hdc, GetStockObject(NULL_BRUSH));
    Rectangle(hdc, cx - 50, cy - 50, cx + 50, cy + 50);

    MoveToEx(hdc, cx - 50, cy, NULL);
    LineTo(hdc, cx + 50, cy);
    MoveToEx(hdc, cx, cy - 50, NULL);
    LineTo(hdc, cx, cy + 50);

    DeleteObject(hPenZone);
#endif

}
void drawMoney(HDC hdc, int cx, int cy) {
    HPEN hPen9;//монека 
    hPen9 = CreatePen(PS_SOLID, 3, RGB(0, 0, 0));
    SelectObject(hdc, hPen9);
    HBRUSH hBrush9;
    hBrush9 = CreateSolidBrush(RGB(0, 0, 0));
    SelectObject(hdc, hBrush9);
    Rectangle(hdc, 220 - 235 + cx, 120 - 160 + cy, 250 - 235 + cx, 130 - 160 + cy);
    Rectangle(hdc, 210 - 235 + cx, 130 - 160 + cy, 220 - 235 + cx, 140 - 160 + cy);
    Rectangle(hdc, 200 - 235 + cx, 140 - 160 + cy, 210 - 235 + cx, 150 - 160 + cy);
    Rectangle(hdc, 190 - 235 + cx, 150 - 160 + cy, 200 - 235 + cx, 170 - 160 + cy);
    Rectangle(hdc, 200 - 235 + cx, 170 - 160 + cy, 210 - 235 + cx, 180 - 160 + cy);
    Rectangle(hdc, 210 - 235 + cx, 180 - 160 + cy, 220 - 235 + cx, 190 - 160 + cy);
    Rectangle(hdc, 220 - 235 + cx, 190 - 160 + cy, 250 - 235 + cx, 200 - 160 + cy);
    Rectangle(hdc, 250 - 235 + cx, 180 - 160 + cy, 260 - 235 + cx, 190 - 160 + cy);
    Rectangle(hdc, 260 - 235 + cx, 170 - 160 + cy, 270 - 235 + cx, 180 - 160 + cy);
    Rectangle(hdc, 270 - 235 + cx, 150 - 160 + cy, 280 - 235 + cx, 170 - 160 + cy);
    Rectangle(hdc, 260 - 235 + cx, 140 - 160 + cy, 270 - 235 + cx, 150 - 160 + cy);
    Rectangle(hdc, 250 - 235 + cx, 130 - 160 + cy, 260 - 235 + cx, 140 - 160 + cy);
    DeleteObject(hPen9);
    DeleteObject(hBrush9);

    HPEN hPen10;
    hPen10 = CreatePen(PS_SOLID, 3, RGB(255, 215, 0));
    SelectObject(hdc, hPen10);
    HBRUSH hBrush10;
    hBrush10 = CreateSolidBrush(RGB(255, 215, 0));
    SelectObject(hdc, hBrush10);
    Rectangle(hdc, 210 - 235 + cx, 150 - 160 + cy, 220 - 235 + cx, 170 - 160 + cy);
    Rectangle(hdc, 220 - 235 + cx, 140 - 160 + cy, 250 - 235 + cx, 150 - 160 + cy);
    Rectangle(hdc, 250 - 235 + cx, 150 - 160 + cy, 260 - 235 + cx, 170 - 160 + cy);
    Rectangle(hdc, 220 - 235 + cx, 170 - 160 + cy, 250 - 235 + cx, 180 - 160 + cy);
    DeleteObject(hPen10);
    DeleteObject(hBrush10);

    HPEN hPen11;
    hPen11 = CreatePen(PS_SOLID, 3, RGB(255, 255, 0));
    SelectObject(hdc, hPen11);
    HBRUSH hBrush11;
    hBrush11 = CreateSolidBrush(RGB(255, 255, 0));
    SelectObject(hdc, hBrush11);
    Rectangle(hdc, 220 - 235 + cx, 130 - 160 + cy, 250 - 235 + cx, 140 - 160 + cy);
    Rectangle(hdc, 200 - 235 + cx, 150 - 160 + cy, 210 - 235 + cx, 170 - 160 + cy);
    Rectangle(hdc, 220 - 235 + cx, 180 - 160 + cy, 250 - 235 + cx, 190 - 160 + cy);
    Rectangle(hdc, 260 - 235 + cx, 150 - 160 + cy, 270 - 235 + cx, 170 - 160 + cy);
    Rectangle(hdc, 220 - 235 + cx, 150 - 160 + cy, 250 - 235 + cx, 170 - 160 + cy);
    Rectangle(hdc, 210 - 235 + cx, 140 - 160 + cy, 220 - 235 + cx, 150 - 160 + cy);
    Rectangle(hdc, 250 - 235 + cx, 140 - 160 + cy, 260 - 235 + cx, 150 - 160 + cy);
    Rectangle(hdc, 210 - 235 + cx, 170 - 160 + cy, 220 - 235 + cx, 180 - 160 + cy);
    Rectangle(hdc, 250 - 235 + cx, 170 - 160 + cy, 260 - 235 + cx, 180 - 160 + cy);
    DeleteObject(hPen11);
    DeleteObject(hBrush11);

#ifdef DEBUG_GAME
    HPEN hPenZone = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
    SelectObject(hdc, hPenZone);
    SelectObject(hdc, GetStockObject(NULL_BRUSH));
    Rectangle(hdc, cx - 30, cy - 30, cx + 30, cy + 30);

    MoveToEx(hdc, cx - 50, cy, NULL);
    LineTo(hdc, cx + 50, cy);
    MoveToEx(hdc, cx, cy - 50, NULL);
    LineTo(hdc, cx, cy + 50);

    DeleteObject(hPenZone);
#endif
}
void drawZelie_zam(HDC hdc, int cx, int cy) {
    HPEN hPen12;//зелье замедления 
    hPen12 = CreatePen(PS_SOLID, 3, RGB(0, 0, 0));
    SelectObject(hdc, hPen12);
    HBRUSH hBrush12;
    hBrush12 = CreateSolidBrush(RGB(0, 0, 0));
    SelectObject(hdc, hBrush12);
    Rectangle(hdc, 350 - 375 + cx, 20 - 75 + cy, 360 - 375 + cx, 40 - 75 + cy);
    Rectangle(hdc, 360 - 375 + cx, 20 - 75 + cy, 370 - 375 + cx, 30 - 75 + cy);
    Rectangle(hdc, 360 - 375 + cx, 40 - 75 + cy, 370 - 375 + cx, 60 - 75 + cy);
    Rectangle(hdc, 350 - 375 + cx, 60 - 75 + cy, 360 - 375 + cx, 80 - 75 + cy);
    Rectangle(hdc, 340 - 375 + cx, 80 - 75 + cy, 350 - 375 + cx, 100 - 75 + cy);
    Rectangle(hdc, 330 - 375 + cx, 100 - 75 + cy, 340 - 375 + cx, 120 - 75 + cy);
    Rectangle(hdc, 340 - 375 + cx, 120 - 75 + cy, 410 - 375 + cx, 130 - 75 + cy);
    Rectangle(hdc, 410 - 375 + cx, 100 - 75 + cy, 420 - 375 + cx, 120 - 75 + cy);
    Rectangle(hdc, 400 - 375 + cx, 80 - 75 + cy, 410 - 375 + cx, 100 - 75 + cy);
    Rectangle(hdc, 390 - 375 + cx, 60 - 75 + cy, 400 - 375 + cx, 80 - 75 + cy);
    Rectangle(hdc, 380 - 375 + cx, 40 - 75 + cy, 390 - 375 + cx, 60 - 75 + cy);
    Rectangle(hdc, 380 - 375 + cx, 20 - 75 + cy, 400 - 375 + cx, 30 - 75 + cy);
    Rectangle(hdc, 390 - 375 + cx, 30 - 75 + cy, 400 - 375 + cx, 40 - 75 + cy);
    DeleteObject(hPen12);
    DeleteObject(hBrush12);

    HPEN hPen13;
    hPen13 = CreatePen(PS_SOLID, 3, RGB(255, 20, 147));
    SelectObject(hdc, hPen13);
    HBRUSH hBrush13;
    hBrush13 = CreateSolidBrush(RGB(255, 20, 147));
    SelectObject(hdc, hBrush13);
    Rectangle(hdc, 370 - 375 + cx, 20 - 75 + cy, 380 - 375 + cx, 30 - 75 + cy);
    Rectangle(hdc, 370 - 375 + cx, 40 - 75 + cy, 380 - 375 + cx, 50 - 75 + cy);
    Rectangle(hdc, 360 - 375 + cx, 60 - 75 + cy, 370 - 375 + cx, 70 - 75 + cy);
    Rectangle(hdc, 380 - 375 + cx, 70 - 75 + cy, 390 - 375 + cx, 80 - 75 + cy);
    Rectangle(hdc, 360 - 375 + cx, 80 - 75 + cy, 370 - 375 + cx, 90 - 75 + cy);
    Rectangle(hdc, 350 - 375 + cx, 90 - 75 + cy, 400 - 375 + cx, 120 - 75 + cy);
    Rectangle(hdc, 340 - 375 + cx, 100 - 75 + cy, 350 - 375 + cx, 120 - 75 + cy);
    Rectangle(hdc, 400 - 375 + cx, 100 - 75 + cy, 410 - 375 + cx, 120 - 75 + cy);
    DeleteObject(hPen13);
    DeleteObject(hBrush13);

#ifdef DEBUG_GAME
    HPEN hPenZone = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
    SelectObject(hdc, hPenZone);
    SelectObject(hdc, GetStockObject(NULL_BRUSH));
    Rectangle(hdc, cx - 70, cy - 70, cx + 70, cy + 70);

    MoveToEx(hdc, cx - 70, cy, NULL);
    LineTo(hdc, cx + 70, cy);
    MoveToEx(hdc, cx, cy - 70, NULL);
    LineTo(hdc, cx, cy + 70);

    DeleteObject(hPenZone);
#endif


}
void drawZelie_ysk(HDC hdc, int cx, int cy) {
    HPEN hPen14;//зелье ускорения 
    hPen14 = CreatePen(PS_SOLID, 3, RGB(0, 0, 0));
    SelectObject(hdc, hPen14);
    HBRUSH hBrush14;
    hBrush14 = CreateSolidBrush(RGB(0, 0, 0));
    SelectObject(hdc, hBrush14);
    Rectangle(hdc, 450 - 475 + cx, 20 - 75 + cy, 470 - 475 + cx, 30 - 75 + cy);
    Rectangle(hdc, 450 - 475 + cx, 30 - 75 + cy, 460 - 475 + cx, 40 - 75 + cy);
    Rectangle(hdc, 460 - 475 + cx, 40 - 75 + cy, 470 - 475 + cx, 60 - 75 + cy);
    Rectangle(hdc, 450 - 475 + cx, 60 - 75 + cy, 460 - 475 + cx, 80 - 75 + cy);
    Rectangle(hdc, 440 - 475 + cx, 80 - 75 + cy, 450 - 475 + cx, 100 - 75 + cy);
    Rectangle(hdc, 430 - 475 + cx, 100 - 75 + cy, 440 - 475 + cx, 120 - 75 + cy);
    Rectangle(hdc, 440 - 475 + cx, 120 - 75 + cy, 510 - 475 + cx, 130 - 75 + cy);
    Rectangle(hdc, 510 - 475 + cx, 100 - 75 + cy, 520 - 475 + cx, 120 - 75 + cy);
    Rectangle(hdc, 500 - 475 + cx, 80 - 75 + cy, 510 - 475 + cx, 100 - 75 + cy);
    Rectangle(hdc, 490 - 475 + cx, 60 - 75 + cy, 500 - 475 + cx, 80 - 75 + cy);
    Rectangle(hdc, 480 - 475 + cx, 40 - 75 + cy, 490 - 475 + cx, 60 - 75 + cy);
    Rectangle(hdc, 480 - 475 + cx, 20 - 75 + cy, 500 - 475 + cx, 30 - 75 + cy);
    Rectangle(hdc, 490 - 475 + cx, 30 - 75 + cy, 500 - 475 + cx, 40 - 75 + cy);
    DeleteObject(hPen14);
    DeleteObject(hBrush14);

    HPEN hPen15;
    hPen15 = CreatePen(PS_SOLID, 3, RGB(152, 251, 152));
    SelectObject(hdc, hPen15);
    HBRUSH hBrush15;
    hBrush15 = CreateSolidBrush(RGB(152, 251, 152));
    SelectObject(hdc, hBrush15);
    Rectangle(hdc, 450 - 475 + cx, 90 - 75 + cy, 500 - 475 + cx, 120 - 75 + cy);
    Rectangle(hdc, 440 - 475 + cx, 100 - 75 + cy, 450 - 475 + cx, 120 - 75 + cy);
    Rectangle(hdc, 500 - 475 + cx, 100 - 75 + cy, 510 - 475 + cx, 120 - 75 + cy);
    Rectangle(hdc, 460 - 475 + cx, 80 - 75 + cy, 470 - 475 + cx, 90 - 75 + cy);
    Rectangle(hdc, 480 - 475 + cx, 70 - 75 + cy, 490 - 475 + cx, 80 - 75 + cy);
    Rectangle(hdc, 470 - 475 + cx, 40 - 75 + cy, 480 - 475 + cx, 50 - 75 + cy);
    Rectangle(hdc, 470 - 475 + cx, 20 - 75 + cy, 480 - 475 + cx, 30 - 75 + cy);
    DeleteObject(hPen15);
    DeleteObject(hBrush15);

#ifdef DEBUG_GAME
    HPEN hPenZone = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
    SelectObject(hdc, hPenZone);
    SelectObject(hdc, GetStockObject(NULL_BRUSH));

    Rectangle(hdc, cx - 70, cy - 70, cx + 70, cy + 70);

    MoveToEx(hdc, cx - 70, cy, NULL);
    LineTo(hdc, cx + 70, cy);
    MoveToEx(hdc, cx, cy - 70, NULL);
    LineTo(hdc, cx, cy + 70);

    DeleteObject(hPenZone);
#endif

}
void drawCat(HDC hdc, int cx, int cy) {
    HPEN hPen16;//кошка 
    hPen16 = CreatePen(PS_SOLID, 3, RGB(0, 0, 0));
    SelectObject(hdc, hPen16);
    HBRUSH hBrush16;
    hBrush16 = CreateSolidBrush(RGB(0, 0, 0));
    SelectObject(hdc, hBrush16);
    Rectangle(hdc, 530 - 630 + cx, 20 - 100 + cy, 540 - 630 + cx, 110 - 100 + cy);
    Rectangle(hdc, 540 - 630 + cx, 20 - 100 + cy, 550 - 630 + cx, 30 - 100 + cy);
    Rectangle(hdc, 550 - 630 + cx, 30 - 100 + cy, 560 - 630 + cx, 40 - 100 + cy);
    Rectangle(hdc, 560 - 630 + cx, 40 - 100 + cy, 570 - 630 + cx, 50 - 100 + cy);
    Rectangle(hdc, 570 - 630 + cx, 50 - 100 + cy, 590 - 630 + cx, 60 - 100 + cy);
    Rectangle(hdc, 590 - 630 + cx, 40 - 100 + cy, 600 - 630 + cx, 50 - 100 + cy);
    Rectangle(hdc, 600 - 630 + cx, 30 - 100 + cy, 610 - 630 + cx, 40 - 100 + cy);
    Rectangle(hdc, 610 - 630 + cx, 20 - 100 + cy, 630 - 630 + cx, 30 - 100 + cy);
    Rectangle(hdc, 620 - 630 + cx, 20 - 100 + cy, 630 - 630 + cx, 110 - 100 + cy);
    Rectangle(hdc, 610 - 630 + cx, 110 - 100 + cy, 620 - 630 + cx, 120 - 100 + cy);
    Rectangle(hdc, 540 - 630 + cx, 110 - 100 + cy, 550 - 630 + cx, 120 - 100 + cy);
    Rectangle(hdc, 550 - 630 + cx, 120 - 100 + cy, 560 - 630 + cx, 130 - 100 + cy);
    Rectangle(hdc, 560 - 630 + cx, 130 - 100 + cy, 600 - 630 + cx, 140 - 100 + cy);
    Rectangle(hdc, 570 - 630 + cx, 140 - 100 + cy, 580 - 630 + cx, 150 - 100 + cy);
    Rectangle(hdc, 600 - 630 + cx, 120 - 100 + cy, 610 - 630 + cx, 130 - 100 + cy);
    Rectangle(hdc, 530 - 630 + cx, 20 - 100 + cy, 540 - 630 + cx, 110 - 100 + cy);
    Rectangle(hdc, 550 - 630 + cx, 160 - 100 + cy, 560 - 630 + cx, 170 - 100 + cy);
    Rectangle(hdc, 560 - 630 + cx, 170 - 100 + cy, 670 - 630 + cx, 180 - 100 + cy);
    Rectangle(hdc, 610 - 630 + cx, 160 - 100 + cy, 620 - 630 + cx, 170 - 100 + cy);
    Rectangle(hdc, 620 - 630 + cx, 140 - 100 + cy, 630 - 630 + cx, 160 - 100 + cy);
    Rectangle(hdc, 630 - 630 + cx, 130 - 100 + cy, 650 - 630 + cx, 140 - 100 + cy);
    Rectangle(hdc, 560 - 630 + cx, 150 - 100 + cy, 590 - 630 + cx, 160 - 100 + cy);
    Rectangle(hdc, 630 - 630 + cx, 110 - 100 + cy, 660 - 630 + cx, 120 - 100 + cy);
    Rectangle(hdc, 660 - 630 + cx, 120 - 100 + cy, 670 - 630 + cx, 130 - 100 + cy);
    Rectangle(hdc, 670 - 630 + cx, 130 - 100 + cy, 680 - 630 + cx, 170 - 100 + cy);
    Rectangle(hdc, 550 - 630 + cx, 80 - 100 + cy, 560 - 630 + cx, 100 - 100 + cy);
    Rectangle(hdc, 600 - 630 + cx, 80 - 100 + cy, 610 - 630 + cx, 100 - 100 + cy);
    Rectangle(hdc, 575 - 630 + cx, 100 - 100 + cy, 585 - 630 + cx, 110 - 100 + cy);
    Rectangle(hdc, 680 - 630 + cx, 140 - 100 + cy, 700 - 630 + cx, 150 - 100 + cy);
    Rectangle(hdc, 700 - 630 + cx, 120 - 100 + cy, 710 - 630 + cx, 140 - 100 + cy);
    Rectangle(hdc, 680 - 630 + cx, 110 - 100 + cy, 700 - 630 + cx, 120 - 100 + cy);
    Rectangle(hdc, 670 - 630 + cx, 90 - 100 + cy, 680 - 630 + cx, 110 - 100 + cy);
    Rectangle(hdc, 680 - 630 + cx, 80 - 100 + cy, 700 - 630 + cx, 90 - 100 + cy);
    Rectangle(hdc, 700 - 630 + cx, 90 - 100 + cy, 710 - 630 + cx, 100 - 100 + cy);
    Rectangle(hdc, 710 - 630 + cx, 100 - 100 + cy, 720 - 630 + cx, 110 - 100 + cy);
    Rectangle(hdc, 720 - 630 + cx, 110 - 100 + cy, 730 - 630 + cx, 150 - 100 + cy);
    Rectangle(hdc, 710 - 630 + cx, 150 - 100 + cy, 720 - 630 + cx, 160 - 100 + cy);
    Rectangle(hdc, 680 - 630 + cx, 160 - 100 + cy, 710 - 630 + cx, 170 - 100 + cy);
    DeleteObject(hPen16);
    DeleteObject(hBrush16);

    HPEN hPen17;
    hPen17 = CreatePen(PS_SOLID, 3, RGB(255, 192, 203));
    SelectObject(hdc, hPen17);
    HBRUSH hBrush17;
    hBrush17 = CreateSolidBrush(RGB(255, 192, 203));
    SelectObject(hdc, hBrush17);
    Rectangle(hdc, 540 - 630 + cx, 100 - 100 + cy, 560 - 630 + cx, 110 - 100 + cy);
    Rectangle(hdc, 600 - 630 + cx, 100 - 100 + cy, 620 - 630 + cx, 110 - 100 + cy);
    DeleteObject(hPen17);
    DeleteObject(hBrush17);

    HPEN hPen18;
    hPen18 = CreatePen(PS_SOLID, 3, RGB(255, 222, 173));
    SelectObject(hdc, hPen18);
    HBRUSH hBrush18;
    hBrush18 = CreateSolidBrush(RGB(255, 222, 173));
    SelectObject(hdc, hBrush18);
    Rectangle(hdc, 540 - 630 + cx, 30 - 100 + cy, 550 - 630 + cx, 90 - 100 + cy);
    Rectangle(hdc, 550 - 630 + cx, 40 - 100 + cy, 560 - 630 + cx, 80 - 100 + cy);
    Rectangle(hdc, 560 - 630 + cx, 50 - 100 + cy, 570 - 630 + cx, 90 - 100 + cy);
    Rectangle(hdc, 570 - 630 + cx, 60 - 100 + cy, 590 - 630 + cx, 70 - 100 + cy);
    Rectangle(hdc, 590 - 630 + cx, 50 - 100 + cy, 600 - 630 + cx, 90 - 100 + cy);
    Rectangle(hdc, 600 - 630 + cx, 40 - 100 + cy, 610 - 630 + cx, 80 - 100 + cy);
    Rectangle(hdc, 610 - 630 + cx, 30 - 100 + cy, 620 - 630 + cx, 90 - 100 + cy);
    Rectangle(hdc, 580 - 630 + cx, 140 - 100 + cy, 590 - 630 + cx, 150 - 100 + cy);
    Rectangle(hdc, 560 - 630 + cx, 160 - 100 + cy, 590 - 630 + cx, 170 - 100 + cy);
    Rectangle(hdc, 620 - 630 + cx, 120 - 100 + cy, 660 - 630 + cx, 130 - 100 + cy);
    Rectangle(hdc, 650 - 630 + cx, 160 - 100 + cy, 670 - 630 + cx, 170 - 100 + cy);
    Rectangle(hdc, 680 - 630 + cx, 150 - 100 + cy, 700 - 630 + cx, 160 - 100 + cy);
    Rectangle(hdc, 710 - 630 + cx, 120 - 100 + cy, 720 - 630 + cx, 140 - 100 + cy);
    Rectangle(hdc, 700 - 630 + cx, 110 - 100 + cy, 720 - 630 + cx, 120 - 100 + cy);
    DeleteObject(hPen18);
    DeleteObject(hBrush18);

#ifdef DEBUG_GAME
    HPEN hPenZone = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
    SelectObject(hdc, hPenZone);
    SelectObject(hdc, GetStockObject(NULL_BRUSH));
    Rectangle(hdc, cx - 70, cy - 70, cx + 70, cy + 70);

    MoveToEx(hdc, cx - 70, cy, NULL);
    LineTo(hdc, cx + 70, cy);
    MoveToEx(hdc, cx, cy - 70, NULL);
    LineTo(hdc, cx, cy + 70);

    DeleteObject(hPenZone);
#endif

}

void drawStart(HDC hdc) {
    drawDog(hdc, 500, 330);
    drawCat(hdc, 950, 355);
    drawFish(hdc, 1100, 480);
    drawMoney(hdc, 420, 480);
    drawZelie_zam(hdc, 660, 100);
    drawZelie_ysk(hdc, 760, 100);
    drawFish(hdc, 500, 590);
    drawFish(hdc, 700, 590);
    drawFish(hdc, 900, 590);
    drawFish(hdc, 300, 590);
    drawFish(hdc, 100, 590);
    drawFish(hdc, 1100, 590);
    drawFish(hdc, 1300, 590);
    drawFish(hdc, 1500, 590);

    HFONT hFont = CreateFont(50, 0, 0, 0, 0, 0, 0, 0,
        DEFAULT_CHARSET, 0, 0, 0, 0, L"Courier New");
    SelectObject(hdc, hFont);
    SetTextColor(hdc, RGB(199, 21, 133));
    TCHAR strT[100] = L"Badger for gold";

    TextOut(hdc, 500, 170, (LPCWSTR)strT, _tcslen(strT));
}

void drawVictory(HDC hdc) {
    int y = 0;
    do {
        int x = 0;
        do {
            drawCat(hdc, x, y);
            x += 200;
        } while (x <= 1500);
        y += 180;
    } while (y <= 1500);
}

void drawLoss(HDC hdc) {
    int y = 0;
    do {
        int x = 0;
        do {
            drawDog(hdc, x, y);
            x += 250;
        } while (x <= 2000);
        y += 180;
    } while (y <= 900);
}

void drawFinal(HDC hdc) {
    drawDog(hdc, 600, 355);
    drawDog(hdc, 410, 355);
    drawDog(hdc, 250, 355);
    drawDog(hdc, 50, 355);
    drawCat(hdc, 1050, 355);
    drawCat(hdc, 850, 355);
    drawCat(hdc, 1250, 355);
    drawCat(hdc, 1450, 355);
    drawCat(hdc, 1050, 355);
    drawMoney(hdc, 550, 200);
    drawMoney(hdc, 650, 200);
    drawMoney(hdc, 750, 200);
    drawMoney(hdc, 850, 200);
    drawMoney(hdc, 950, 200);
    drawMoney(hdc, 450, 200);
    drawMoney(hdc, 350, 200);
    drawMoney(hdc, 250, 200);
    drawMoney(hdc, 150, 200);
    drawMoney(hdc, 1050, 200);
    drawMoney(hdc, 1150, 200);
    drawMoney(hdc, 1250, 200);
    drawMoney(hdc, 1350, 200);
    drawMoney(hdc, 50, 200);
    drawMoney(hdc, 1450, 200);
    drawMoney(hdc, 550, 500);
    drawMoney(hdc, 650, 500);
    drawMoney(hdc, 750, 500);
    drawMoney(hdc, 850, 500);
    drawMoney(hdc, 950, 500);
    drawMoney(hdc, 450, 500);
    drawMoney(hdc, 350, 500);
    drawMoney(hdc, 250, 500);
    drawMoney(hdc, 150, 500);
    drawMoney(hdc, 1050, 500);
    drawMoney(hdc, 1150, 500);
    drawMoney(hdc, 1250, 500);
    drawMoney(hdc, 1350, 500);
    drawMoney(hdc, 50, 500);
    drawMoney(hdc, 1450, 500);



    HFONT hFont = CreateFont(60, 0, 0, 0, 0, 0, 0, 0,
        DEFAULT_CHARSET, 0, 0, 0, 0, L"Courier New");
    SelectObject(hdc, hFont);
    SetTextColor(hdc, RGB(255, 105, 180));
    TCHAR strT[400] = L"Badger for gold. Автор:Уварова Татьяна Исдо-12 ";

    TextOut(hdc, 0, 0, (LPCWSTR)strT, _tcslen(strT));
}


typedef struct Zelie_zam {
    int X;
    int Y;
    int Visible;
}GAMEOBJECT4;
#define NUM_ZELIE_ZAMES 3
GAMEOBJECT4 Zelie_zames[NUM_ZELIE_ZAMES] = {
{100,700,1},
{500,200,1},
{1050,400,1}
};

typedef struct Cat {
    int X;
    int Y;
    int Helth;
    int HasZelie_ysk;
    int Visible;
    int HasZelie_zam;
    int HasMoney;
}CAT;
CAT Cat = { 100, 200, 3, 0, 1, 0, 0 };

typedef struct Zelie_ysk {
    int X;
    int Y;
    int Visible;
} GAMEOBJECT;
#define NUM_ZELIE_YSKS 3
GAMEOBJECT Zelie_ysks[NUM_ZELIE_YSKS] = {
    {400, 400,1},
    {520, 350, 1},
    {640, 300, 1}
};

typedef struct GameObject1 {
    int X;
    int Y;
    int Visible;
} GAMEOBJECT1;
GAMEOBJECT1 Money = { 300,600,1 };

typedef struct GameObject2 {
    int X;
    int Y;
    int Visible;

}GAMEOBJECT2;
#define NUM_FISHES 4
GAMEOBJECT2 Fishes[NUM_FISHES] = {
    {700, 200, 1},
    {600, 600, 1},
    {1200, 150, 1},
    {1400, 700, 1}
};

typedef struct GameObject3 {
    int X;
    int Y;
    int Visible;
}GAMEOBJECT3;
GAMEOBJECT3 Dog = { 800, 500, 1 };

typedef struct Zelie_zamFlying {
    int X;
    int Y;
    int VX;
    int VY;
    int Visible;
} ZELIE_ZAMFLYING;
ZELIE_ZAMFLYING Zelie_zamFlying = { 0, 0, 30, 0, 0 };

int CountVisibleZelie_ysk() {
    int count = 0;
    int i = 0;
    do {
        if (Zelie_ysks[i].Visible) {
            ++count;
        }
        ++i;
    } while (i < NUM_ZELIE_YSKS);
    return count;
}

void  TryToEatZelie_ysk() {
    for (int i = 0; i < NUM_ZELIE_YSKS; i++) {
        if (Zelie_ysks[i].Visible) {
            if (Cat.X - 20 < Zelie_ysks[i].X
                && Cat.X + 20 > Zelie_ysks[i].X
                && Cat.Y - 20 < Zelie_ysks[i].Y
                && Cat.Y + 20 > Zelie_ysks[i].Y) {
                Zelie_ysks[i].Visible = 0;
            }
        }
    }
}

void  TryToTakeMoney() {
    if (Money.Visible) {
        if (Cat.X - 20 < Money.X
            && Cat.X + 20 > Money.X
            && Cat.Y - 20 < Money.Y
            && Cat.Y + 20 > Money.Y) {
            Money.Visible = 0;
            Cat.HasMoney++;
        }
    }
}

void TryToEatFish() {
    for (int i = 0; i < NUM_FISHES; i++) {
        if (Fishes[i].Visible) {
            if (Cat.X - 30 < Fishes[i].X
                && Cat.X + 30 > Fishes[i].X
                && Cat.Y - 30 < Fishes[i].Y
                && Cat.Y + 30 > Fishes[i].Y) {

                Fishes[i].Visible = 0;
                Cat.Helth += 4;
            }
        }
    }
}

void GoDirection() {
    int dx = 0, dy = 0;
    if (Dog.Visible) {
        if (Cat.X > Dog.X)
            dx = 3;
        if (Cat.X < Dog.X)
            dx = -3;
        if (Cat.Y > Dog.Y)
            dy = 3;
        if (Cat.Y < Dog.Y)
            dy = -3;
        Dog.X += dx;
        Dog.Y += dy;

    }
}

void MoveZelie_zamFlying() {
    if (Zelie_zamFlying.Visible) {
        Zelie_zamFlying.X += Zelie_zamFlying.VX;
        Zelie_zamFlying.Y += Zelie_zamFlying.VY;
    }
}

void CatAndDog() {
    if (Dog.Visible) {
        if (Cat.X - 40 < Dog.X
            && Cat.X + 40 > Dog.X
            && Cat.Y - 40 < Dog.Y
            && Cat.Y + 40 > Dog.Y&&Cat.HasZelie_zam) {
            Cat.HasZelie_zam = 0;
            Dog.Visible = 0;
        }
        if (Cat.X - 40 < Dog.X
            && Cat.X + 40 > Dog.X
            && Cat.Y - 40 < Dog.Y
            && Cat.Y + 40 > Dog.Y) {
            Cat.Helth--;
            Cat.Visible == 0;
        }
    }
}

void TryToTakeZelie_zam() {
    if (!Cat.HasZelie_zam) {
        for (int i = 0; i < NUM_ZELIE_ZAMES; i++) {
            if (Zelie_zames[i].Visible) {
                if (Zelie_zames[i].X - 20 < Cat.X
                    && Zelie_zames[i].X + 20 > Cat.X
                    && Zelie_zames[i].Y - 20 < Cat.Y
                    && Zelie_zames[i].Y + 20 > Cat.Y) {
                    Zelie_zames[i].Visible = 0;
                    Cat.HasZelie_zam = 1;
                }
            }
        }
    }
}

void ContactDogAndZelie_zamFlying() {
    if (Dog.Visible) {
        if (Zelie_zamFlying.Visible) {
            if (Zelie_zamFlying.X - 20 < Dog.X
                && Zelie_zamFlying.X + 20 > Dog.X
                && Zelie_zamFlying.Y - 20 < Dog.Y
                && Zelie_zamFlying.Y + 20 > Dog.Y) {
                Dog.Visible = 0;
                Zelie_zamFlying.Visible = 0;
            }
        }
    }
}

void ContactCatAndDog() {
    if (Dog.Visible) {
        if (Cat.X - 20 < Dog.X
            && Cat.X + 20 > Dog.X
            && Cat.Y - 20 < Dog.Y
            && Cat.Y + 20 > Dog.Y) {
            if (Cat.HasZelie_zam) {
                Dog.Visible = 0;
                Cat.HasZelie_zam = 0;
            }
            else {
                Cat.Helth--;
            }
        }
    }
}

void drawStatus(HDC hdc) {
    HFONT hFont = CreateFont(35, 0, 0, 0, 0, 0, 0, 0,
        DEFAULT_CHARSET, 0, 0, 0, 0, L"Courier New");

    SelectObject(hdc, hFont);
    SetTextColor(hdc, RGB(128, 0, 128));

    char str[180];
    sprintf_s(str, "Helth = %d, Zelie_zam = %s, Money = %d",
        Cat.Helth,
        Cat.HasZelie_zam ? "YES" : "NO",
        Cat.HasMoney);

    TCHAR  strT[180];
    OemToCharBuff(str, strT, 180);
    TextOut(hdc, 430, 0, (LPCWSTR)strT, _tcslen(strT));

    DeleteObject(hFont);
}


void drawGame(HDC hdc) {
    if (Cat.Helth > 0) {
        drawCat(hdc, Cat.X, Cat.Y);
    }

    for (int i = 0; i < NUM_ZELIE_YSKS; i++) {
        if (Zelie_ysks[i].Visible) {
            drawZelie_ysk(hdc, Zelie_ysks[i].X, Zelie_ysks[i].Y);
        }
    }

    if (Money.Visible) {
        drawMoney(hdc, Money.X, Money.Y);
    }

    for (int i = 0; i < NUM_FISHES; i++) {
        if (Fishes[i].Visible) {
            drawFish(hdc, Fishes[i].X, Fishes[i].Y);
        }
    }

    if (Dog.Visible) {
        drawDog(hdc, Dog.X, Dog.Y);
    }
    for (int i = 0; i < NUM_ZELIE_ZAMES; i++) {
        if (Zelie_zames[i].Visible) {
            drawZelie_zam(hdc, Zelie_zames[i].X, Zelie_zames[i].Y);
        }
    }

    if (Zelie_zamFlying.Visible) {
        drawZelie_zam(hdc, Zelie_zamFlying.X, Zelie_zamFlying.Y);
    }

    drawStatus(hdc);
}


void drawFon(HDC hdc) {
    //пасхалко
    HBRUSH MQ;
    MQ = CreateSolidBrush RGB(230, 230, 250);
    SelectObject(hdc, MQ);
    Rectangle(hdc, -1, -1, 2000, 1000);
}
void KeepGame() {
    FILE* fout;
    fopen_s(&fout, "GameState.txt", "wt");
    if (fout == NULL) {
        return;
    }
    fprintf(fout, "%d %d %d %d %d\n", Cat.X, Cat.Y, Cat.Helth, Cat.HasZelie_ysk, Cat.HasZelie_zam);
    for (int i = 0; i < NUM_ZELIE_YSKS; i++) {
        fprintf(fout, "%d %d %d\n", Zelie_ysks[i].X, Zelie_ysks[i].Y, Zelie_ysks[i].Visible);
    }
    fprintf(fout, "\n\n\n");

    fprintf(fout, "%d %d %d\n", Money.X, Money.Y, Money.Visible);
    
    fprintf(fout, "\n\n\n");
    for (int i = 0; i < NUM_FISHES; i++) {
        fprintf(fout, "%d %d %d\n", Fishes[i].X, Fishes[i].Y, Fishes[i].Visible);
    }
    fprintf(fout, "\n\n\n");
    for (int i = 0; i < NUM_ZELIE_ZAMES; i++) {
        fprintf(fout, "%d %d %d\n", Zelie_zames[i].X, Zelie_zames[i].Y, Zelie_zames[i].Visible);
    }
    fprintf(fout, "\n\n\n");
    fprintf(fout, "%d %d %d\n", Dog.X, Dog.Y, Dog.Visible);
    fprintf(fout, "\n\n\n");
    fprintf(fout, "%d %d %d\n", Zelie_zamFlying.X, Zelie_zamFlying.Y, Zelie_zamFlying.Visible);




    fclose(fout);


}
void LoadGame() {
    FILE* fin;
    fopen_s(&fin, "GameState.txt", "rt");
    if (fin == NULL) {
        return;
    }
    fscanf_s(fin, "%d %d %d %d %d\n", &Cat.X, &Cat.Y, &Cat.Helth, &Cat.HasZelie_ysk, &Cat.HasZelie_zam);
    for (int i = 0; i < NUM_ZELIE_YSKS; i++) {
        fscanf_s(fin, "%d %d %d\n", &Zelie_ysks[i].X, &Zelie_ysks[i].Y, &Zelie_ysks[i].Visible);
    }

    fscanf_s(fin, "%d %d %d\n", &Money.X, &Money.Y, &Money.Visible);

    for (int i = 0; i < NUM_FISHES; i++) {
        fscanf_s(fin, "%d %d %d\n", &Fishes[i].X, &Fishes[i].Y, &Fishes[i].Visible);
    }
    for (int i = 0; i < NUM_ZELIE_ZAMES; i++) {
        fscanf_s(fin, "%d %d %d\n", &Zelie_zames[i].X, &Zelie_zames[i].Y, &Zelie_zames[i].Visible);
    }
    fscanf_s(fin, "%d %d %d\n", &Dog.X, &Dog.Y, &Dog.Visible);
    fscanf_s(fin, "%d %d %d\n", &Zelie_zamFlying.X, &Zelie_zamFlying.Y, &Zelie_zamFlying.Visible);

    fclose(fin);
}





LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
    {
        int wmId = LOWORD(wParam);
        // Разобрать выбор в меню:
        switch (wmId)
        {
        case IDM_ABOUT:
            DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
            break;
        case IDM_EXIT:
            DestroyWindow(hWnd);
            break;
        default:
            return DefWindowProc(hWnd, message, wParam, lParam);
        }
    }
    break;
    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);
        drawFon(hdc);
        if (mode == START)
            drawStart(hdc);
        if (mode == GAME)
            drawGame(hdc);
        if (mode == VICTORY)
            drawVictory(hdc);
        if (mode == LOSS)
            drawLoss(hdc);
        if (mode == FINAL)
            drawFinal(hdc);

        EndPaint(hWnd, &ps);
    }
    break;
    case WM_KEYDOWN:
    {
        if (mode == START) {
            mode = GAME;
        }
        else if (mode == GAME) {
            switch (wParam)
            {
            case VK_SPACE:
                if (Cat.HasZelie_zam) {
                    Cat.HasZelie_zam = 0;
                    Zelie_zamFlying.Visible = 1;
                    Zelie_zamFlying.X = Cat.X;
                    Zelie_zamFlying.Y = Cat.Y;
                }
                break;
            case 0x4B://k
                KeepGame();//тут был я
                break;
            case 0x4c://l
                LoadGame();
                break;
            case VK_UP:
                Cat.Y -= 10;
                break;
            case VK_DOWN:
                Cat.Y += 10;
                break;
            case VK_LEFT:
                Cat.X -= 10;
                break;
            case VK_RIGHT:
                Cat.X += 10;
                break;
            }

            TryToTakeMoney();
            TryToEatFish();
            TryToTakeZelie_zam();
            TryToEatZelie_ysk();
            if (CountVisibleZelie_ysk() == 0) {
                mode = VICTORY;//победа
            }
            GoDirection();
            CatAndDog();
            if (Cat.Helth == 0 || Cat.Visible == 0) {
                mode = LOSS;//победа 
            }
        }
        else if (mode == VICTORY || mode == LOSS) {
            step++;
            if (step > 10)
                mode = FINAL;
        }
        InvalidateRect(hWnd, NULL, TRUE);
        break;
    }
    case WM_CREATE:
        srand(time(NULL));
        SetTimer(hWnd, 1, 1000, NULL);
        break;
    case WM_TIMER:
        if (mode == GAME) {
            MoveZelie_zamFlying();
            ContactDogAndZelie_zamFlying();
            ContactCatAndDog();
            CatAndDog();
            TryToTakeMoney();
            TryToEatFish();
            TryToTakeZelie_zam();
            TryToEatZelie_ysk();
            if (Cat.Helth == 0 || Cat.Visible == 0) {
                mode = LOSS;//проигрыш
            }
            if (Zelie_ysks[0].Visible == 0 && Zelie_ysks[1].Visible == 0 && Zelie_ysks[2].Visible == 0 ) {
                mode = VICTORY;
            }
            if (CountVisibleZelie_ysk() == 0) {
                mode = VICTORY;//победа
            }
        }
        else if (mode == VICTORY || mode == LOSS) {
            step++;
            if (step > 10)
                mode = FINAL;
        }
        InvalidateRect(hWnd, NULL, TRUE);
        break;


    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// Обработчик сообщений для окна "О программе".
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
