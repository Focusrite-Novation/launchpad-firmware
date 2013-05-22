void midi_parsers_init(void);
void midi_parsers_poll(void);

extern u8 Challenge[4];
extern u8 DataIn[540], DataOut[540];
extern u8 UserByte;
extern u8 DutyCycleMultiplier;
extern void midi_noteon(u8 d1, u8 d2);
extern void midi_d100 (u8 d1, u8 d2);
extern void midi_runningupdate (u8 d1, u8 d2);
extern void MIDISysex (u8 refcable, u8* data, u16 count);
extern void MIDIData( u8 refcable, u8 status, u8 d1, u8 d2);
extern u8 CalculateXY(u8 d1);