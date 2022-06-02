#include "framework.h"
#include "apex/operating_system.h"
#include <Shlobj.h>
#include "acme/filesystem/filesystem/acme_directory.h"
#include "acme_universal_windows/acme_directory.h"


namespace apex_universal_windows
{


   dir_system::dir_system()
   {


   }


   dir_system::~dir_system()
   {

   }



   void dir_system::initialize(::object * pobject)
   {

      //auto estatus =
      
      ::dir_system::initialize(pobject);

      //if (!estatus)
      //{

      //   return estatus;

      //}

      m_pathInstall = m_psystem->m_pacmedirectory->install();

      //m_psystem->m_pacmedirectory->m_pplatformdir->_shell_get_special_folder_path(
        // nullptr,
         //m_strCommonAppData,
         //CSIDL_COMMON_APPDATA,
         //false);
      //shell_get_special_folder_path(
      // nullptr,
      //m_pathProfile,
      //CSIDL_PROFILE,
      //false);

      //m_pathHome = m_psystem->m_pacmedirectory->m_pplatformdir->_get_known_folder(FOLDERID_Profile);

      string strHome = getenv("USERPROFILE");

      strHome.trim();

      if (strHome.has_char())
      {

         m_pathHome = strHome;

      }
      else
      {

         m_pathHome = m_pathInstall / "home";

      }

      //m_pathCa2Config = m_psystem->m_pacmedirectory->ca2roaming();

      m_pathCa2Config = m_pathInstall / "ca2/config";

      m_strCommonAppData = m_pathInstall / "commonappdata";

      m_strAppData = m_pathInstall / "appdata";

      //m_psystem->m_pacmedirectory->m_pplatformdir->_shell_get_special_folder_path(
      //   nullptr,
      //   m_strPrograms,
      //   CSIDL_PROGRAMS,
      //   false);
      //m_psystem->m_pacmedirectory->m_pplatformdir->_shell_get_special_folder_path(
      //   nullptr,
      //   m_strCommonPrograms,
      //   CSIDL_COMMON_PROGRAMS,
      //   false);

      {

         //string strRelative;
         //strRelative = install();
         //index iFind = strRelative.find(':');
         //if (iFind >= 0)
         //{
         //   strsize iFind1 = strRelative.reverse_find("\\", iFind);
         //   strsize iFind2 = strRelative.reverse_find("/", iFind);
         //   strsize iStart = maximum(iFind1 + 1, iFind2 + 1);
         //   strRelative = strRelative.Left(iFind - 1) + "_" + strRelative.Mid(iStart, iFind - iStart) + strRelative.Mid(iFind + 1);
         //}



      }

      if (m_strTimeFolder.is_empty())
      {

         m_strTimeFolder = m_psystem->m_pacmedirectory->appdata() / "time";

      }

      if (m_strNetSeedFolder.is_empty())
      {

         m_strNetSeedFolder = m_psystem->m_pacmedirectory->install() / "net";

      }

               auto psystem = m_psystem;

         auto pacmedir = psystem->m_pacmedirectory;

pacmedir->create(m_strTimeFolder);
      //xxdebug_box("win_dir::initialize (m_strTimeFolder)", "win_dir::initialize", 0);

if (!pacmedir->is(m_strTimeFolder))
{
   throw exception(error_failed, "Time folder doesn't exist");

}

          /*     auto psystem = m_psystem;

         auto pacmedir = psystem->m_pacmedirectory;*/

pacmedir->create(m_strTimeFolder / "time");

      //xxdebug_box("win_dir::initialize", "win_dir::initialize", 0);

      //return ::success;

   }


   void dir_system::init_system()
   {

      //auto estatus = 
      
      ::dir_system::init_system();

      //if (!estatus)
      //{

      //   return estatus;

      //}


      //return ::success;

   }


} // namespace apex_universal_windows



