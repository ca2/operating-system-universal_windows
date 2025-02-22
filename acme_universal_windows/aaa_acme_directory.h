// Create on 2021-03-21 20:00 <3ThomasBS_
// Copied by camilo from operating_system-windows on 2021-09-01 22:01 ThomasMonth!! <3ThomasBS_
#pragma once


#include "acme_windows_common/directory_system.h"


namespace acme_universal_windows
{


   class CLASS_DECL_ACME_UNIVERSAL_WINDOWS directory_system :
      virtual public ::acme_windows_common::directory_system
   {
   public:


      directory_system();
      ~directory_system() override;


      //::file::path module_folder() override;


      ::file::path install() override;
      ::file::path default_install() override;
      ::file::path beforeca2() override;
      ::file::path module() override;
      ::file::path relative(::file::path path) override;
      //::string appid() override;
      ::file::path appdata() override; // appdata
      ::file::path archive() override;
      ::file::path tool() override;
      ::file::path public_system() override;
      ::file::path system() override;
      ::file::path config() override;
      ::file::path local() override;
      ::file::path sensitive() override;
      ::file::path localconfig() override; // #vcs C:\\Users\\user\\AppData\\Roaming\\ca2\\localconfig
      ::file::path ca2roaming() override; // writable root (non-bin, non-exe)
      ::file::path ca2appdata() override; // writable root (non-bin, non-exe)
      ::file::path roaming() override;
      ::file::path program_data() override;
      ::file::path public_root() override; // writable common root (non-bin, non-exe)
      ::file::path bookmark() override;
      ::file::path home() override;
      ::file::path pathfind(const string& pszEnv, const string& pszTopic, const string& pszMode) override;
      ::file::path program_files_x86() override;
      ::file::path program_files() override;
      //virtual ::file::path program_data() override;
      ::file::path stage(string strAppId, string strPlatform, string strConfiguration) override;
      ::file::path sys_temp() override;
      ::string dir_root() override;
      //virtual ::file::path home() override;
      //virtual ::file::path program_data() override;
      //virtual ::file::path roaming() override;
      ::file::path get_memory_map_base_folder_path() override;
      //virtual ::file::path ca2appdata() override;
      //virtual ::file::path ca2roaming() override;
      //virtual ::file::path localconfig() override;
      string system_short_name() override;

      //::file::path default_install() override;
      //::file::path inplace_install(string strAppId, string strPlatform, string strConfiguration) override;
      //virtual ::file::path inplace_install(string strAppId, string strPlatform, string strConfiguration) override;
      ::file::path inplace_install(string strAppId, string strPlatform, string strConfiguration) override;
      ::file::path inplace_matter_install(string strAppId, string strPlatform, string strConfiguration) override;


      void set_path_install_folder(const ::string & pszPath) override;

      //virtual  bool        _shell_get_special_folder_path(HWND hwnd, ::file::path& str, int csidl, bool fCreate);
      //virtual ::file::path _shell_get_special_folder_path(int csidl, bool fCreate = true, ::windowing::window* pwindow = nullptr);
      //virtual ::file::path _get_known_folder(REFKNOWNFOLDERID kfid);

      //virtual ::file::path pathfind(const string& pszEnv, const string& pszTopic, const string& pszMode) override;

      ::file::path user_appdata_local() override;

      //bool is(const ::file::path & path) override;
      //bool _is(bool & bDir, const ::file::path & path) override;

      ::file::e_type _file_type(const ::file::path & path) override;

// From acme/filesystem/file/dir.cpp by camilo 
// From acme_posix/directory_system.h
// on 2021-08-09 03:20 BRT
// <3ThomasBorregaardSorensen!!


// namespace posix
// {


// class CLASS_DECL_ACME_POSIX directory_system :
// virtual public ::directory_system
// {

// public:

// directory_system();
// ~directory_system() override;

      //virtual string name(const char * path1) override;


      //virtual ::file::path module_folder() override;
      
      //bool create(const char * path) override;

      //bool _create(const char * path) override;

      //bool create_directory(const char * path) override;

      //::e_status _create_directory(const char * path) override;

      //void rls(::file::path_array & stra, const scoped_string & str) override;

      //void rls_dir(::file::path_array & stra, const scoped_string & str) override;

      //void ls(::file::path_array & stra, const scoped_string & str) override;

      //void ls_dir(::file::path_array & stra, const scoped_string & str) override;

      //void ls_file(::file::path_array & stra, const scoped_string & str) override;

      bool enumerate(::file::listing & listing) override;

      //int make_path(const scoped_string & str) override;

      //::file::path get_current() override;


   };


} // namespace acme_universal_windows



