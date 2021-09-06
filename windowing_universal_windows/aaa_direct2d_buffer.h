﻿#pragma once


#include <wrl/client.h>
#include <d3d11_1.h>
#include <d2d1_1.h>
#include <dwrite_1.h>
#include <wincodec.h>

//
//namespace draw2d_direct2d
//{
//
//
//   class plugin;
//
//
//} // namespace draw2d_direct2d
//
//
//namespace universal_windows
//{
//
//
//   inline void throw_if_failed(HRESULT hr)
//   {
//
//      if (FAILED(hr))
//      {
//
//         throw hresult_exception(hr);
//
//      }
//
//   }
//
//
//} // namespace universal_windows
//
//
//namespace windowing_universal_windows
//{
//
//
//
//   enum enum_phase
//   {
//
//      e_phase_draw,
//      e_phase_present,
//
//   };
//
//   // Helper class that initializes DirectX APIs for both 2D and 3D rendering.
//   // Some of the code in this class may be omitted if only 2D or only 3D rendering is being used.
//   class direct2d_buffer :
//      virtual public ::matter
//   {
//   public:
//
//
//      enum_phase                                            m_ephase;
//
//      ///__pointer(::draw2d_direct2d::plugin)               m_pplugin;
//      
//      ::logic::bit                                          m_bCoreWindowVisible;
//
//      bool                                                  m_b3D;
//      ::aura::system *                                      m_psystem;
//      ::mutex                                               m_mutexDc;
//      size_i32                                              m_size;
//      ::size_i32                                            m_sizeBuffer;
//      __pointer(::windowing_universal_windows::window)      m_pwindow;
//      bool                                                  m_bInitialized;
//      bool                                                  m_bInit;
//      ::image_pointer                                       m_pimage;
//      bool                                                  m_bCreated;
//      ::winrt::Windows::Foundation::Rect                    m_windowBounds;
//
//
//      direct2d_buffer();
//      ~direct2d_buffer() override;
//
//
//      ::aura::application * get_application() const
//      {
//
//         return get_application();
//
//      }
//
//
//      virtual bool defer_init();
//
//      virtual void Initialize(::winrt::Windows::UI::Core::CoreWindow window, float dpi);
//      virtual void HandleDeviceLost();
//      virtual void CreateDeviceIndependentResources();
//      virtual void CreateDeviceResources();
//      virtual void SetDpi(float dpi);
//      virtual void OnChangeDpi(float dpi);
//      virtual void UpdateForWindowSizeChange();
//      virtual void CreateWindowSizeDependentResources();
//      virtual void DestroyWindowSizeDependentResources();
//      //virtual HRESULT Render();
//      virtual void Present();
//      void ValidateDevice();
//
//      virtual void OnWindowSizeChange();
//
//      //virtual void defer_resize_top_level_windows();
//
//      ID2D1DeviceContext* get_device_context();
//
//   //protected private:
//      winrt::agile_ref<::winrt::Windows::UI::Core::CoreWindow>  m_window;
//
//      // DirectWrite & Windows Imaging Component Objects.
//      Microsoft::WRL::ComPtr<IDWriteFactory1>         m_dwriteFactory;
//      Microsoft::WRL::ComPtr<IWICImagingFactory2>     m_wicFactory;
//
//      // DirectX Core Objects. Required for 2D and 3D.
//      //Microsoft::WRL::ComPtr<ID3D11Device1>           m_d3dDevice;
//      //Microsoft::WRL::ComPtr<ID3D11DeviceContext1>    m_d3dContext;
//      Microsoft::WRL::ComPtr<IDXGISwapChain1>         m_swapChain;
//      Microsoft::WRL::ComPtr<ID3D11RenderTargetView>  m_d3dRenderTargetView;
//
//      // Direct2D Rendering Objects. Required for 2D.
//      //Microsoft::WRL::ComPtr<ID2D1Device>             m_d2dDevice;
//      Microsoft::WRL::ComPtr<ID2D1DeviceContext>      m_pd2d1devicecontext;
//      Microsoft::WRL::ComPtr<ID2D1Bitmap1>            m_d2dTargetBitmap;
//
//      // Direct3D Rendering Objects. Required for 3D.
//      Microsoft::WRL::ComPtr<ID3D11DepthStencilView>  m_d3dDepthStencilView;
//      // Cached renderer properties.
//      D3D_FEATURE_LEVEL                               m_featureLevel;
//      ::winrt::Windows::Foundation::Size                       m_renderTargetSize;
//      float                                           m_dpi;
//      float                                           m_dpiIni;
//      //bool                                            m_windowSizeChangeInProgress;
//
//
//
//      //Microsoft::WRL::ComPtr<ID2D1SolidColorBrush>                    m_blackBrush;
//      //Microsoft::WRL::ComPtr<IDWriteTextFormat>                       m_textFormat;
//      //Microsoft::WRL::ComPtr<IDWriteTypography>                       m_textTypography;
//      //Microsoft::WRL::ComPtr<IDWriteTextLayout>                       m_textLayout;
//      //SampleOverlay^                                                  m_sampleOverlay;
//
//
//   };
//
//
//} // namespace windowing_universal_windows
//
//
//
//
//
////CLASS_DECL_AURA ::mutex & draw2d_mutex();