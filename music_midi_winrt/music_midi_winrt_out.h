#pragma once


namespace music
{


   namespace midi
   {


      namespace winrt
      {

         class CLASS_DECL_VERIWELL_MULTIMEDIA_MUSIC_MIDI_WINRT out :
            virtual public ::music::midi::out
         {
         public:


//            HMIDIOUT       m_hmidiout;


            out(::object * pobject);
            virtual ~out();


            virtual ::multimedia::e_result open();
            virtual ::multimedia::e_result close();

            ::multimedia::e_result send_short_message(::music::midi::e_type etype, int iChannel, int iData1, int iData2);

         };


      } // namespace winrt


   } // namespace midi


} // namespace music




