#ifndef __CX_SWITCH_H
#define __CX_SWITCH_H


struct sMultiSwitch
{
	u8 NewValue;
	u8 OldValue;
	u8 Countdown;
};

extern u8 switch_is_on(u8* SwitchState);
extern u8 switch_is_off(u8* SwitchState, u8 DebounceInterval);

extern u8 switch_multi_decode(u8 ADCValue, const u8* LookupTable, const u8 MaxIndex);
extern u8 switch_multi_init(struct sMultiSwitch* SwitchState);
extern u8 switch_multi(struct sMultiSwitch* SwitchState, u8 Value, u8 DebounceInterval);


#endif