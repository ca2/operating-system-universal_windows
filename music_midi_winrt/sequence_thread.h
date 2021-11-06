#pragma once



namespace music
{


   namespace midi
   {


      namespace winrt
      {


         class CLASS_DECL_VERIWELL_MULTIMEDIA_MUSIC_MIDI_WINRT sequence_thread :
            virtual public ::music::midi::sequence_thread
         {
         public:


            sequence_thread(::object * pobject);
            virtual ~sequence_thread();


            void install_message_routing(::message::sender * pinterface);

            ::music::midi::sequence * get_sequence();
            void Stop(imedia_time msEllapse);

            bool PostMidiSequenceEvent(::music::midi::sequence * pseq, ::music::midi::sequence::e_event event);

            bool PostMidiSequenceEvent(::music::midi::sequence * pseq, ::music::midi::sequence::e_event event, LPMIDIHDR lpmh);

            void PostNotifyEvent(::music::midi::player::e_notify_event eevent);

            void PrerollRateAndWait(double rate = 0.0);
            void PrerollAndWait(imedia_position tkStart);
            void PlayRate(double dRate = 0.0);
            void Play(imedia_position tkStart);
            void PostGMReset();
            void PostTempoChange();
            void SendTempoChange();

            //void ExecuteCommand(smart_pointer < ::music::midi::player::command > pcommand);
            void _ExecuteCommand(::music::midi::player::command * pcommand);

            virtual bool init_thread() override;
            virtual void term_thread() override;

            //DECLARE_MESSAGE_HANDLER(OnCommand);
            DECLARE_MESSAGE_HANDLER(OnMidiSequenceEvent);

         };


      } // namespace winrt


   } // namespace midi_winrt


} // namespace music





