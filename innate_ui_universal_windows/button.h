// Created by camilo on 2024-09-13 00:36 <3ThomasBorregaardSorensen!!
#pragma once


#include "apex/innate_ui/button.h"
#include "window.h"


namespace innate_ui_universal_windows
{


   class CLASS_DECL_INNATE_UI_UNIVERSAL_WINDOWS button :
      virtual public ::innate_ui_universal_windows::window,
      virtual public ::innate_ui::button
   {
   public:



      button();
      ~button() override;


      void _create_child(window * pwindowParent) override;

      bool _on_command() override;

      void set_icon(::innate_ui::icon * picon) override;

   };


} // namespace innate_ui_universal_windows




