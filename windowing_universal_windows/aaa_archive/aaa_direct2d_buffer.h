#pragma once


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
//      ///::pointer<::draw2d_direct2d::plugin>              m_pplugin;
//      
//      ::boolean                                          m_bCoreWindowVisible;
//
//      bool                                                  m_b3D;
//      ::aura::system *                                      system();
//      ::mutex                                               m_mutexDc;
//      int_size                                              m_size;
//      ::int_size                                            m_sizeBuffer;
//      ::pointer<::windowing_universal_windows::window>     m_pwindow;
//      bool                                                  m_bInitialized;
//      bool                                                  m_bInit;
//      ::image::image_pointer                                       m_pimage;
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
//      comptr<IDWriteFactory1>         m_dwriteFactory;
//      comptr<IWICImagingFactory2>     m_wicFactory;
//
//      // DirectX Core Objects. Required for 2D and 3D.
//      //comptr<ID3D11Device1>           m_d3dDevice;
//      //comptr<ID3D11DeviceContext1>    m_d3dContext;
//      comptr<IDXGISwapChain1>         m_swapChain;
//      comptr<ID3D11RenderTargetView>  m_d3dRenderTargetView;
//
//      // Direct2D Rendering Objects. Required for 2D.
//      //comptr<ID2D1Device>             m_d2dDevice;
//      comptr<ID2D1DeviceContext>      m_pd2d1devicecontext;
//      comptr<ID2D1Bitmap1>            m_d2dTargetBitmap;
//
//      // Direct3D Rendering Objects. Required for 3D.
//      comptr<ID3D11DepthStencilView>  m_d3dDepthStencilView;
//      // Cached renderer properties.
//      D3D_FEATURE_LEVEL                               m_featureLevel;
//      ::winrt::Windows::Foundation::Size                       m_renderTargetSize;
//      float                                           m_dpi;
//      float                                           m_dpiIni;
//      //bool                                            m_windowSizeChangeInProgress;
//
//
//
//      //comptr<ID2D1SolidColorBrush>                    m_blackBrush;
//      //comptr<IDWriteTextFormat>                       m_textFormat;
//      //comptr<IDWriteTypography>                       m_textTypography;
//      //comptr<IDWriteTextLayout>                       m_textLayout;
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
