﻿// WindowsDesktop1.cpp : Defines the entry point_i32 for the application.
//

#include "framework.h"
//#include "WindowsDesktop1.h"
//
//#define MAX_LOADSTRING 100
//
//// Global Variables:
//HINSTANCE hInst;                                // current instance
//WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
////WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name
//
//// Forward declarations of functions included in this code module:
//ATOM                MyRegisterClass(HINSTANCE hInstance);
//BOOL                InitInstance(HINSTANCE, int);
//lresult CALLBACK    WndProc(HWND, ::u32, wparam, lparam);
//INT_PTR CALLBACK    About(HWND, ::u32, wparam, lparam);

////int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
////   _In_opt_ HINSTANCE hPrevInstance,
////   _In_ LPWSTR    lpCmdLine,
////   _In_ int       nCmdShow)
//   int windows_desktop1_main(HINSTANCE hInstance,int       nCmdShow)
//{
//   //__UNREFERENCED_PARAMETER(hPrevInstance);
//   //__UNREFERENCED_PARAMETER(lpCmdLine);
//
//   // TODO: Place code here.
//
//   // Initialize global strings
//   wcscpy(szTitle, L"123");
//   //wcscpy(szWindowClass, );
//   MyRegisterClass(hInstance);
//
//   // Perform application initialization:
//   if (!InitInstance(hInstance, nCmdShow))
//   {
//      return false;
//   }
//
//   //HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WINDOWSDESKTOP1));
//
//   MSG msg;
//
//   // Main message loop:
//   while (mq_get_message(&msg, nullptr, 0, 0))
//   {
//      //if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
//      {
//         TranslateMessage(&msg);
//         DispatchMessage(&msg);
//      }
//   }
//
//   return (int)msg.wParam;
//}
//


//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
//   WNDPROC get_window_procedure();
//ATOM MyRegisterClass(HINSTANCE hInstance)
//{
//   WNDCLASSEXW wcex = {};
//
//   wcex.cbSize = sizeof(WNDCLASSEX);
//
//   wcex.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
//   wcex.lpfnWndProc = WndProc;
//   //wcex.lpfnWndProc = get_window_procedure();
//   wcex.cbClsExtra = 0;
//   wcex.cbWndExtra = 0;
//   wcex.hInstance = hInstance;
//   //wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WINDOWSDESKTOP1));
//    //wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
//   wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW);
//   //wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_WINDOWSDESKTOP1);
//   wcex.lpszClassName = L"WindowsDestkop1";
//   //wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));
//
//   return RegisterClassExW(&wcex);
//}
//
////
////   FUNCTION: InitInstance(HINSTANCE, int)
////
////   PURPOSE: Saves instance handle and creates main window
////
////   COMMENTS:
////
////        In this function, we save the instance handle in a global variable and
////        create and display the main program window.
////
////BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
////{
////   hInst = hInstance; // Store instance handle in our global variable
////
////   HWND hWnd = CreateWindowW(L"WindowsDestkop1", szTitle, WS_OVERLAPPED,
////      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);
////
////   if (!hWnd)
////   {
////      return false;
////   }
////
////   ShowWindow(hWnd, nCmdShow);
////   UpdateWindow(hWnd);
////
////   return true;
////}
//
////
////  FUNCTION: WndProc(HWND, ::u32, wparam, lparam)
////
////  PURPOSE: Processes messages for the main window.
////
////  e_message_command  - process the application menu
////  e_message_paint    - Paint the main window
////  e_message_destroy  - post a quit message and return
////
////
//lresult CALLBACK WndProc(HWND hWnd, ::u32 message, wparam wParam, lparam lParam)
//{
//
//   switch (message)
//   {
//
//   //case e_message_paint:
//   //{
//   //   PAINTSTRUCT ps;
//   //   HDC hdc = BeginPaint(hWnd, &ps);
//   //   // TODO: Add any drawing code that uses hdc here...
//   //   EndPaint(hWnd, &ps);
//   //}
//   break;
//   case e_message_destroy:
//      PostQuitMessage(0);
//      break;
//   default:
//      return DefWindowProc(hWnd, message, wParam, lParam);
//   }
//   return 0;
//}
//
//// Message handler for about box.
//INT_PTR CALLBACK About(HWND hDlg, ::u32 message, wparam wParam, lparam lParam)
//{
//   __UNREFERENCED_PARAMETER(lParam);
//   switch (message)
//   {
//   case WM_INITDIALOG:
//      return (INT_PTR)true;
//
//   case e_message_command:
//      if (LOWORD(wParam) == e_dialog_result_ok || LOWORD(wParam) == e_dialog_result_cancel)
//      {
//         EndDialog(hDlg, LOWORD(wParam));
//         return (INT_PTR)true;
//      }
//      break;
//   }
//   return (INT_PTR)false;
//}
