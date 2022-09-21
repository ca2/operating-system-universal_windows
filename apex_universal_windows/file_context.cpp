#include "framework.h"
#include "file_context.h"
#include "file_system.h"
#include "dir_system.h"
#include "acme_universal_windows/native_buffer.h"
#include "apex/operating_system.h"
#include "acme/filesystem/filesystem/acme_directory.h"
#include "acme/filesystem/filesystem/acme_file.h"
#include "acme/filesystem/filesystem/acme_path.h"
#include "acme/include/_c_swap.h"


namespace apex_universal_windows
{


   file_context::file_context()
   {

   }


   file_context::~file_context()
   {

   }


   void file_context::initialize(::object * pobject)
   {

      //auto estatus = 

      ::object::initialize(pobject);

      //if (!estatus)
      //{

      //   return estatus;

      //}

      __pointer(::apex::system) psystem = get_system();

      __refer(m_pfilesystem, psystem->m_pfilesystem);

      __refer(m_pdirsystem, psystem->m_pdirsystem);

      //      return ::success;

   }


   void file_context::init_system()
   {

      //auto estatus =

//      m_pfilesystem->update_module_path();

      //if (!estatus)
      //{

      //   return estatus;

      //}

      //return ::success;

   }


   void file_context::calculate_main_resource_memory()
   {

      m_memoryMainResource = as_memory("_matter.zip");

   }


   //bool file_context::FullPath(string & str, const ::string & pszFileIn)

   //{

   //   //if(::apex::file_context::FullPath(str, pszFileIn))

   //   // return true;

   //   if (::str().begins_ci(pszFileIn, "http://"))

   //   {

   //      str = pszFileIn;


   //      return true;

   //   }
   //   else if (::str().begins_ci(pszFileIn, "https://"))

   //   {

   //      str = pszFileIn;


   //      return true;

   //   }
   //   wstring wstrFileIn;
   //   wstrFileIn = utf8_to_unicode(pszFileIn);

   //   wstring wstrFileOut;
   //   bool b = windows_full_path(wstrFileOut.get_string_buffer(MAX_PATH * 8), wstrFileIn) != false;
   //   if (b)
   //   {
   //      unicode_to_utf8(str, wstrFileOut);
   //   }
   //   return b;
   //}

   //bool file_context::FullPath(wstring & wstrFullPath, const wstring & wstrPath)
   //{

   //   /*      if(::apex::file_context::FullPath(wstrFullPath, wstrPath))
   //   return true;*/

   //   if (::str().begins_ci(wstrPath, L"http://"))
   //   {
   //      wstrFullPath = wstrPath;
   //      return true;
   //   }
   //   else if (::str().begins_ci(wstrPath, L"https://"))
   //   {
   //      wstrFullPath = wstrPath;
   //      return true;
   //   }

   //   return windows_full_path(wstrFullPath, wstrPath) != false;

   //}


   //::u32 file_context::GetFileName(const ::string & pszPathName, string & str)

   //{
   //   i32 nMax = MAX_PATH * 8;
   //   wstring wstrPathName;
   //   wstrPathName = utf8_to_unicode(pszPathName);

   //   wstring wstrTitle;
   //   ::u32 user = vfxGetFileName(wstrPathName, wstrTitle.get_string_buffer(nMax), nMax);
   //   str = unicode_to_utf8(wstrTitle);
   //   return user;
   //}

   //void file_context::GetModuleShortFileName(HINSTANCE hInst, string & strShortName)
   //{
   //   vfxGetModuleShortFileName(hInst, strShortName);
   //}


   ::file::enum_type file_context::get_type(const ::file::path& path)
   {

      auto etype = ::file_context::get_type(path);

      if (etype != ::file::e_type_unknown)
      {

         return etype;

      }

      return m_psystem->m_pacmepath->get_type(path);

   }


   ::payload file_context::length(const ::file::path & path)
   {

      //::payload varRet;

      //varRet = ::file_context::length(path);

      //if (!varRet.is_null())
      //{
      // 
      //   return varRet;

      //}

      string strRelative = path;

      string strPrefix;

      auto folder = windows_runtime_folder(this, strRelative, strPrefix);

      if (folder)
      {

         auto hstrName = __hstring(strRelative);

         auto item = folder.TryGetItemAsync(hstrName).get();

         if (item)
         {

            if (item.IsOfType(winrt::Windows::Storage::StorageItemTypes::File))
            {
               
               winrt::Windows::Storage::StorageFile file=nullptr;

               item.as(file);

               if (file)
               {

                  auto basicproperties = file.GetBasicPropertiesAsync().get();

                  if (basicproperties)
                  {

                     return basicproperties.Size();

                  }

               }

            }

         }

      }

      WIN32_FILE_ATTRIBUTE_DATA data;

      if (GetFileAttributesExW(utf8_to_unicode(path), GetFileExInfoStandard, &data))
      {
         
         return make64_from32(data.nFileSizeLow, data.nFileSizeHigh);

      }

      return ::e_type_null;

   }


   ::payload file_context::length(const ::file::path & path, ::payload * pvarQuery)
   {

      // TODO: I don't remember what pvarQuery is used for, in the time of reimplementation
      // of this function. Maybe you should consider it in some case(s).

      return ::file_context::length(path, pvarQuery);

   }


   void file_context::move(const ::file::path & pszNew, const ::file::path & psz)
   {

      auto file = windows_runtime_file(this, psz, 0, 0, OPEN_EXISTING, 0);

      if (file == nullptr)
      {

         throw ::exception(error_io, "file::file_context::move Could not move file, could not open source file");

      }

      string strDirOld = psz.folder();
      string strDirNew = pszNew.folder();
      string strNameOld = psz.name();
      string strNameNew = pszNew.name();

      if (strDirOld == strDirNew)
      {

         if (strNameOld == strNameNew)
         {

            return;

         }
         else
         {

            auto hstrNameNew = __hstring(strNameNew);

            file.RenameAsync(hstrNameNew).get();

         }

      }
      else
      {

         string strPrefix;

         ::winrt::Windows::Storage::StorageFolder folder = windows_runtime_folder(this, strDirNew, strPrefix);

         if (strNameOld == strNameNew)
         {

            file.MoveAsync(folder).get();

         }
         else
         {
            
            auto hstrNameNew = __hstring(strNameNew);
            
            file.MoveAsync(folder, hstrNameNew).get();

         }

      }

   }


   void file_context::erase(const ::file::path & psz)
   {

      m_psystem->m_pacmefile->erase(psz);
      //{
      //
      //   return error_failed;

      //}

      //return ::success;

   }


   bool file_context::is_read_only(const ::file::path & psz)
   {

#ifdef WINDOWS_DESKTOP

      u32 dwAttrib = windows_get_file_attributes(psz);

      if (dwAttrib & FILE_ATTRIBUTE_READONLY)
      {

         return true;

      }

      return false;

#elif defined(_UWP)

      //throw ::exception(todo);

#else

      struct stat st;

      if (stat(psz, &st) != 0)
         return true;

      return !(st.st_mode & S_IWUSR);

#endif

      return false;

   }


   file_pointer file_context::resource_get_file(const ::file::path & path)
   {

#ifdef WINDOWS_DESKTOP

      auto pfile = create_memory_file();

      int iId = atoi(path);

      string strExtension = path.final_extension();

      strExtension.make_upper();

      const char * psz = strExtension;

      if (strExtension == "HTML")
      {

         psz = (const ::string &)RT_HTML;

      }

      __pointer(::apex::system) psystem = get_system();

      if (read_resource_as_memory(*pfile->get_primitive_memory(), (HINSTANCE) psystem->m_hinstance, iId, psz))
      {

         return pfile;

      }

#else

      throw_todo();

#endif

      return nullptr;

   }


   bool file_context::get_last_write_time(FILETIME * pfiletime, const ::string & strFilename)
   {

      WIN32_FILE_ATTRIBUTE_DATA data;

      __zero(data);

      if (!GetFileAttributesExW(wstring(strFilename), GetFileExInfoStandard, &data))
      {

         return false;

      }

      *pfiletime = data.ftLastWriteTime;

      return true;

   }


   void file_context::get_status(::file::file_status & rStatus, const ::file::path & path)
   {

      auto pathFull = m_psystem->m_pacmepath->_final(path);

      wstring wstrFullName(pathFull);

      WIN32_FIND_DATAW findFileData;
      
      HANDLE hFind = FindFirstFileW((LPWSTR)(const widechar *)wstrFullName, &findFileData);
      
      if (hFind == INVALID_HANDLE_VALUE)
      {
       
         DWORD lastError = ::GetLastError();

         auto estatus = last_error_to_status(lastError);

         throw ::exception(estatus);

      }

      VERIFY(FindClose(hFind));

      rStatus.m_attribute = (byte)(findFileData.dwFileAttributes & ~FILE_ATTRIBUTE_NORMAL);

      rStatus.m_filesize = make64_from32(findFileData.nFileSizeLow, findFileData.nFileSizeHigh);

      file_time_to_time(&rStatus.m_ctime.m_i, (file_time_t *)&findFileData.ftCreationTime);
      file_time_to_time(&rStatus.m_atime.m_i, (file_time_t *)&findFileData.ftLastAccessTime);
      file_time_to_time(&rStatus.m_mtime.m_i, (file_time_t *)&findFileData.ftLastWriteTime);

      if (rStatus.m_ctime.get_time() == 0)
      {

         rStatus.m_ctime = rStatus.m_mtime;

      }

      if (rStatus.m_atime.get_time() == 0)
      {

         rStatus.m_atime = rStatus.m_mtime;

      }

   }

   //void file_context::set_status(const ::file::path & path,const ::file::file_status& status)
   //{

   //   wstring pszFileName(path);

   //   ::u32 wAttr;
   //   FILETIME creationTime;
   //   FILETIME lastAccessTime;
   //   FILETIME lastWriteTime;
   //   LPFILETIME pCreationTime = nullptr;

   //   LPFILETIME pLastAccessTime = nullptr;

   //   LPFILETIME pLastWriteTime = nullptr;


   //   if((wAttr = windows_get_file_attributes((LPWSTR)(const widechar *)pszFileName)) == (::u32)-1L)

   //      file_exception::throw_os_error((::i32)GetLastError());

   //   if((::u32)status.m_attribute != wAttr && (wAttr & readOnly))
   //   {
   //      // set file attribute, only if currently readonly.
   //      // This way we will be able to modify the time assuming the
   //      // caller changed the file from readonly.

   //      if(!SetFileAttributesW((LPWSTR)(const widechar *)pszFileName,(::u32)status.m_attribute))

   //         file_exception::throw_os_error((::i32)GetLastError());
   //   }

   //   // last modification time
   //   if(status.m_mtime.get_time() != 0)
   //   {
   //      ::apex::TimeToFileTime(status.m_mtime,&lastWriteTime);
   //      pLastWriteTime = &lastWriteTime;


   //      // last access time
   //      if(status.m_atime.get_time() != 0)
   //      {
   //         ::apex::TimeToFileTime(status.m_atime,&lastAccessTime);
   //         pLastAccessTime = &lastAccessTime;

   //      }

   //      // create time
   //      if(status.m_ctime.get_time() != 0)
   //      {
   //         ::apex::TimeToFileTime(status.m_ctime,&creationTime);
   //         pCreationTime = &creationTime;

   //      }

   //      HANDLE hFile = ::CreateFileW((LPWSTR)(const widechar *)pszFileName,GENERIC_READ | GENERIC_WRITE,

   //         FILE_SHARE_READ,nullptr,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,
   //         nullptr);

   //      if(hFile == INVALID_HANDLE_VALUE)
   //         file_exception::throw_os_error((::i32)::GetLastError());

   //      if(!SetFileTime((HANDLE)hFile,pCreationTime,lpLastAccessTime,lpLastWriteTime))

   //         file_exception::throw_os_error((::i32)::GetLastError());

   //      if(!::CloseHandle(hFile))
   //         file_exception::throw_os_error((::i32)::GetLastError());
   //   }

   //   if((::u32)status.m_attribute != wAttr && !(wAttr & readOnly))
   //   {
   //      if(!SetFileAttributes((char *)pszFileName,(::u32)status.m_attribute))

   //         file_exception::throw_os_error((::i32)GetLastError());
   //   }
   //}


   //void file::SetStatus(const ::string & pszFileName,const ::file::file_status& status)

   //{
   //   ::u32 wAttr;
   //   FILETIME creationTime;
   //   FILETIME lastAccessTime;
   //   FILETIME lastWriteTime;
   //   LPFILETIME pCreationTime = nullptr;

   //   LPFILETIME pLastAccessTime = nullptr;

   //   LPFILETIME pLastWriteTime = nullptr;


   //   if((wAttr = GetFileAttributes((char *)pszFileName)) == (::u32)-1L)

   //      file_exception::throw_os_error((::i32)GetLastError());

   //   if((::u32)status.m_attribute != wAttr && (wAttr & readOnly))
   //   {
   //      // set file attribute, only if currently readonly.
   //      // This way we will be able to modify the time assuming the
   //      // caller changed the file from readonly.

   //      if(!SetFileAttributes((char *)pszFileName,(::u32)status.m_attribute))

   //         file_exception::throw_os_error((::i32)GetLastError());
   //   }

   //   // last modification time
   //   if(status.m_mtime.get_time() != 0)
   //   {
   //      ::apex::TimeToFileTime(status.m_mtime,&lastWriteTime);
   //      pLastWriteTime = &lastWriteTime;


   //      // last access time
   //      if(status.m_atime.get_time() != 0)
   //      {
   //         ::apex::TimeToFileTime(status.m_atime,&lastAccessTime);
   //         pLastAccessTime = &lastAccessTime;

   //      }

   //      // create time
   //      if(status.m_ctime.get_time() != 0)
   //      {
   //         ::apex::TimeToFileTime(status.m_ctime,&creationTime);
   //         pCreationTime = &creationTime;

   //      }

   //      HANDLE hFile = ::CreateFile(pszFileName,GENERIC_READ | GENERIC_WRITE,

   //         FILE_SHARE_READ,nullptr,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,
   //         nullptr);

   //      if(hFile == INVALID_HANDLE_VALUE)
   //         file_exception::throw_os_error((::i32)::GetLastError());

   //      if(!SetFileTime((HANDLE)hFile,pCreationTime,lpLastAccessTime,lpLastWriteTime))

   //         file_exception::throw_os_error((::i32)::GetLastError());

   //      if(!::CloseHandle(hFile))
   //         file_exception::throw_os_error((::i32)::GetLastError());
   //   }

   //   if((::u32)status.m_attribute != wAttr && !(wAttr & readOnly))
   //   {
   //      if(!SetFileAttributes((char *)pszFileName,(::u32)status.m_attribute))

   //         file_exception::throw_os_error((::i32)GetLastError());
   //   }
   //}

   
   void file_context::set_status(const ::file::path & path, const ::file::file_status & status)
   {

      wstring pszFileName(path);


      ::u32 wAttr;
      FILETIME creationTime;
      FILETIME lastAccessTime;
      FILETIME lastWriteTime;
      LPFILETIME pCreationTime = nullptr;

      LPFILETIME pLastAccessTime = nullptr;

      LPFILETIME pLastWriteTime = nullptr;


      if ((wAttr = windows_get_file_attributes(path)) == (::u32)INVALID_FILE_ATTRIBUTES)
      {

         DWORD dwLastError = ::GetLastError();

         throw ::file::exception(::error_io, dwLastError, path);

      }

      if ((::u32)status.m_attribute != wAttr && (wAttr & FILE_ATTRIBUTE_READONLY))
      {
         // set file attribute, only if currently readonly.
         // This way we will be able to modify the time assuming the
         // caller changed the file from readonly.

         if (!SetFileAttributesW((LPWSTR)(const widechar *)pszFileName, (::u32)status.m_attribute))
         {

            DWORD dwLastError = ::GetLastError();

            throw ::file::exception(::error_io, dwLastError, 0, pszFileName);

         }

      }

      // last modification time
      if (status.m_mtime.get_time() != 0)
      {
         
         time_to_file_time((file_time_t *) &lastWriteTime, &status.m_mtime.m_i);

         pLastWriteTime = &lastWriteTime;

         // last access time
         if (status.m_atime.get_time() != 0)
         {

            time_to_file_time((file_time_t *)&lastAccessTime, &status.m_atime.m_i);

            pLastAccessTime = &lastAccessTime;

         }

         // create time
         if (status.m_ctime.get_time() != 0)
         {

            time_to_file_time((file_time_t *)&creationTime, &status.m_ctime.m_i);

            pCreationTime = &creationTime;

         }

         HANDLE hFile = hfile_create(path, GENERIC_READ | GENERIC_WRITE,

            FILE_SHARE_READ, nullptr, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL,
            nullptr);

         if (hFile == INVALID_HANDLE_VALUE)
         {

            auto lastError = ::GetLastError();

            auto estatus = ::last_error_to_status(lastError);

            throw ::file_open_exception(estatus, path);

         }

         if (!SetFileTime((HANDLE)hFile, pCreationTime, pLastAccessTime, pLastWriteTime))
         {

            auto lastError = ::GetLastError();

            auto estatus = ::last_error_to_status(lastError);

            throw ::file::exception(estatus, path);

         }

         if (!::CloseHandle(hFile))
         {

            auto lastError = ::GetLastError();

            auto estatus = ::last_error_to_status(lastError);

            throw ::file::exception(estatus, path);

         }

      }

      if ((::u32)status.m_attribute != wAttr && !(wAttr & FILE_ATTRIBUTE_READONLY))
      {

         if (!SetFileAttributesW((LPWSTR)(const widechar *)pszFileName, (::u32)status.m_attribute))
         {

            auto lastError = ::GetLastError();

            auto estatus = ::last_error_to_status(lastError);

            throw ::file::exception(estatus, path);

         }

      }

      //return ::success;

   }


   //::e_status file_context::update_module_path()
   //{

   //   auto estatus = ::file_context::update_module_path();

   //   if(!estatus)
   //{
   //   
   //   return estatus;
   //   
   //}

   //   return estatus;

   //}

   


   file_pointer file_context::get_file(const ::payload & payloadFile, const ::file::e_open & eopenFlags)
   {

      return ::file_context::get_file(payloadFile, eopenFlags);

   }


   ::file_pointer file_context::create_native_file(const ::file::path & path, const ::file::e_open & eopen)
   {

      string strRelative = path;

      string strPrefix;

      auto folder = windows_runtime_folder(m_pcontext, strRelative, strPrefix);

      if (folder)
      {

         if (folder)
         {

            auto hstrName = __hstring(strRelative);

            auto item = folder.TryGetItemAsync(hstrName).get();

            if (item)
            {

               if (item.IsOfType(::winrt::Windows::Storage::StorageItemTypes::File))
               {

                  ::winrt::Windows::Storage::StorageFile file = nullptr;

                  item.as(file);

                  if (file)
                  {

                     auto pfile = __new(::acme_universal_windows::native_buffer(file, eopen));

                     return pfile;

                  }

               }

            }

         }

      }

      ::file_pointer pfile;

      m_pcontext->__construct(pfile);

      pfile->open(path, eopen);

      return pfile;

   }


   ::file::path file_context::dropbox_info_network_payload()
   {

      ::file::path pathJson;

      pathJson = m_psystem->m_pacmedirectory->user_appdata_local() / "Dropbox/info.json";

      return pathJson;

   }


} // namespace apex_universal_windows


