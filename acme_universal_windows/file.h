#pragma once









namespace acme_universal_windows
{

   /////////////////////////////////////////////////////////////////////////////
   // File - raw unbuffered disk file I/O

   class CLASS_DECL_ACME_UNIVERSAL_WINDOWS file :
      virtual public ::file::file
   {
   public:


      enum Attribute
      {
         normal =    0x00,
         readOnly =  0x01,
         hidden =    0x02,
         system =    0x04,
         volume =    0x08,
         directory = 0x10,
         archive =   0x20
      };


      bool                 m_bCloseOnDelete;
      hfile                m_hfile;


      file();
      ~file() override;


      void assert_ok() const override;
      void dump(dump_context& dumpcontext) const override;


      operator HANDLE() const;

      filesize get_position() const override;
      bool get_status(::file::file_status & rStatus) const override;
      //virtual string GetFileName() const override;
      //virtual string GetFileTitle() const override;
      ::file::path get_file_path() const override;
      void set_file_path(const ::file::path & path) override;

      void open(const ::file::path & lpszFileName, const ::file::e_open & eopen) override;

      //virtual bool GetStatus(const ::file::path & lpszFileName,::file::file_status& rStatus);

      u64 ReadHuge(void * lpBuffer, u64 dwCount);
      void WriteHuge(const void * lpBuffer, u64 dwCount);

      //virtual __pointer(::file::file) Duplicate() const;

      filesize translate(filesize offset, ::enum_seek eseek) override;
      void set_size(filesize dwNewLen) override;
      filesize get_size() const override;

      virtual memsize read(void * lpBuf, memsize nCount) override;
      virtual void write(const void * lpBuf, memsize nCount) override;

      virtual void lock(filesize dwPos, filesize dwCount) override;
      virtual void unlock(filesize dwPos, filesize dwCount) override;

      //virtual void Abort();
      virtual void flush() override;
      virtual void close() override;

      virtual bool is_opened()const  override;
      //enum BufferCommand { bufferRead, bufferWrite, bufferCommit, bufferCheck };
      //virtual u64 GetBufferPtr(::u32 nCommand, u64 nCount = 0,
      //                              void ** ppBufStart = nullptr, void ** ppBufMax = nullptr);

   };

   //namespace WinFileException
   //{

   //   ::e_status OsErrorToException(::i32 lOsError);
   //   ::e_status ErrnoToException(int nErrno);
   //   void ThrowOsError(::matter * pobject, ::i32 lOsError, const char * lpszFileName = nullptr);
   //   void ThrowErrno(::matter * pobject, int nErrno, const char * lpszFileName = nullptr);

   //}



} // namespace acme_universal_windows




