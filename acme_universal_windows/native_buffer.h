// Adapted for composition by camilo on 2021-09-01 22:17 <3ThomasBS__!
#pragma once


#include "acme/filesystem/file/file.h"
#include "acme/prototype/prototype/memory.h"
#undef ___new
#include <winrt/Windows.Storage.h>


namespace acme_universal_windows
{


   class CLASS_DECL_ACME_UNIVERSAL_WINDOWS native_buffer :
      virtual public ::file::file
   {
   public:

            
      bool                                                                 m_bCloseOnDelete;
      ::file::path                                                         m_strFileName;
      ::winrt::Windows::Storage::StorageFile                               m_file = nullptr;
      ::winrt::Windows::Storage::StorageFolder                             m_folder = nullptr;
      ::winrt::Windows::Storage::Streams::IRandomAccessStream              m_stream = nullptr;
      ::file::e_open                                                       m_eopen;

      memory                                                               m_memoryBuffer;


      native_buffer(::winrt::Windows::Storage::StorageFile file, ::file::e_open eopen);
      ~native_buffer() override;

      //void assert_ok() const override;
      //void dump(dump_context & dumpcontext) const override;

      filesize get_position() const override;
      ::file::file_status get_status() const override;
      //virtual string GetFileName() const;
      //virtual string GetFileTitle() const;
      ::file::path get_file_path() const override;
      //void set_file_path(const ::file::path & pathNewName) override;
      void open(::winrt::Windows::Storage::StorageFolder folder, const ::file::path & pathFileArgument, ::file::e_open eopen);
      void open(const ::file::path & lpszfileName, ::file::e_open eopen, ::pointer < ::file::exception > * ppfileexception = nullptr) override;
      void open(::winrt::Windows::Storage::StorageFile file, ::file::e_open eopen);

      //virtual bool GetStatus(const ::file::path & lpszfileName,::file::file_status& rStatus);

      ///unsigned long long ReadHuge(void * lpBuffer,unsigned long long dwCount);
      //void WriteHuge(const void * lpBuffer,unsigned long long dwCount);

      //virtual ::pointer<::file::file>Duplicate() const;

      //void put_byte_back(unsigned char unsigned char) override;

      void translate(filesize lOff, ::enum_seek eseek) override;
      void set_size(filesize dwNewLen) override;
      filesize size() const override;

      memsize read(void * lpBuf, memsize nCount) override;
      void write(const void * lpBuf, memsize nCount) override;

      void lock(filesize dwPos, filesize dwCount) override;
      void unlock(filesize dwPos, filesize dwCount) override;

      //virtual void Abort();
      void flush() override;
      void close() override;

      bool is_opened() const override;
      //enum BufferCommand { bufferRead,bufferWrite,bufferCommit,bufferCheck };
      //virtual unsigned long long GetBufferPtr(unsigned int nCommand,unsigned long long nCount = 0,
      //                              void ** ppBufStart = nullptr,void ** ppBufMax = nullptr);

   };


} // namespace acme_universal_windows




