#pragma once


namespace music
{


   namespace midi
   {


      namespace winrt
      {


         class CLASS_DECL_VERIWELL_MULTIMEDIA_MUSIC_MIDI_WINRT midi :
            virtual public ::music::midi::midi
         {
         public:


            //::apex::library                 m_library;
            //midi_listener_set             m_listenerptra;
            //uint32_t                      m_uiMidiOutDevice;


            midi(::object * pobject);
            virtual ~midi();


            //virtual ::multimedia::e_result enumerate_midi_devices();


            //void RemoveListener(midi_listener * plistener);
            //void AddListener(midi_listener * plistener);
            //uint32_t GetMidiOutDevice();
            //void SetMidiOutDevice(uint32_t uiDevice);
            //bool Initialize();


            //bool IsSoftKaraokeFile(const char * lpszPathName);
            //bool IsXFFile(const char * lpcszPathName);


            //virtual bool veriwell_multimedia_music_midi_factory_exchange(::factory_map * pfactorymap);


            //void mmsystem_LogMidiInCaps(UINT_PTR i, MIDIINCAPSW caps);
            //void mmsystem_GetMidiInDeviceInterface(UINT_PTR i);
            //void mmsystem_LogMidiOutCaps(UINT_PTR i, MIDIOUTCAPSW caps);
            //void mmsystem_GetMidiOutDeviceInterface(UINT_PTR i);

            //using ::music::midi::midi::translate_os_result;
            //virtual ::multimedia::e_result translate_os_result(string & strMessage, string & strOsMessage, ::music::midi::object * pobject, int64_t iOsResult, const string & strContext, const string & strText);


         };


      } // namespace winrt


   } // namespace midi


} // namespace music




