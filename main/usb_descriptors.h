// USB Descriptors for CXM3 USB File

#define TO_HST_ENDPOINTS    1
#define TO_DEV_ENDPOINTS    1


// NB. Tables are built from the bottom level up, to make linking easier

// ____________________________________________________________________________
//
// Device descriptor
// ____________________________________________________________________________
//

u8 device_descriptor[] =
{
	// see p37 of usb.org MIDI device class definition
	18,				// length of this descriptor
	1,				// 01 = device descriptor
	0x10,0x01,		// 01 10 = USB 1.1 spec
	0,				// 00 = device class code (uses interface descriptor)
	0,				// 00 = device subclass code (unused)
	0,				// 00 = device protocol code (uses interface descriptor)
	TX_BUFFER_SIZE,	// = max packet size (default 40h)
	0x35,0x12,		// 12 35 = novation vendor code
	0x20,0x00,		// 00 20 = Launchpad CC
	0x00,0x00,  	// 00 00 = device release code
	1,				// 01 = index to manufacturer string descriptor
	2,				// 02 = index to product string descriptor
	0,				// 00 = serial number (unused)
	1				// 01 = number of configurations
};


// ____________________________________________________________________________
//
// Configuration descriptor
// ____________________________________________________________________________
//

// usb spec 9.4.3: hosts request all descriptors, from the first configuration
// to the last endpoint, as one long block of data. usb spec 9.5.2: they cannot
// request the interface and endpoint descriptors in any other way.

u8 configuration_descriptor[] =
{
	// see p37-38 of usb.org MIDI device class definition
	// and p265 of usb.org USB 2.0 definition

	// Configuration descriptor
	// ------------------------
	9,			// length of this descriptor
	2,			// 02 = configuration descriptor
	0,0,		// length of total of configuration, interface, terminal and endpoint blocks
				// stick the size in here just before transmission
	2,			// 02 = number of interfaces (AudioControl, MIDIStreaming)
	1,			// 01 = configuration ID (Note: ID 0 is used for 'address state' in GET/SET_CONFIGURATION)
	0,			// 00 = no configuration string
	0x80,		// 80 = bus-powered; no remote wakeup
	30,		    // 30 decimal = 60mA max power

	// AudioControl interface descriptor
	// ---------------------------------
	9,			// length of this descriptor
	4,			// 04 = interface descriptor
	0,			// 00 = index of this interface
	0,			// 00 = index of alternate setting
	0,			// 00 = no endpoints in use
	1,			// 01 = class code (audio interface)
	1,			// 01 = subclass code (AudioControl)
	0,			// 00 = interface protocol (unused)
	3,			// 03 = interface string descriptor

	// AudioControl class-specific interface descriptor
	// ------------------------------------------------
	9,			// length of this descriptor
	0x24,		// 24 = class-specific interface descriptor
	1,			// 01 = header subtype
	0,1,		// 01 00 = version of audio class specification
	9,0,		// 00 09 = total length of class-specific descriptors
	1,			// 01 = number of streaming interfaces
	1,			// 01 = interface number

	// MIDIStreaming interface descriptor
	// ----------------------------------
	9,			// length of this descriptor
	4,			// 04 = interface descriptor
	1,			// 01 = index of this interface
	0,			// 00 = index of alternate setting
	2,			// 02 = two endpoints in use
	1,			// 01 = class code (audio interface)
	3,			// 03 = subclass code (MIDIStreaming)
	0,			// 00 = interface protocol (unused)
	3,			// 03 = interface string descriptor

	// MIDIStreaming class-specific interface descriptor
	// -------------------------------------------------
	7,		// length of this descriptor
	0x24,	// 24 = class-specific interface descriptor
	1,		// 01 = header subtype
	0,1,  	// 01 00 = version of audio class specification
	7+6+9+7+5+7+5,0,  // length of this section

	// Embedded MIDI IN jack descriptor
	// --------------------------------
	// HOST ->- MIDI Out Endpoint ->- Embedded MIDI IN jack ->- us
	6,		 // length of this descriptor
	0x24,	 // 24 = class-specific interface descriptor
	2,		 // 02 = midi in jack
	1,		 // 01 = embedded (not external)
	1,		 // 01 = id 1
	0,		 // 00 = jack string descriptor

	// Embedded MIDI OUT jack descriptor
	// ---------------------------------
	// us ->- Embedded MIDI OUT jack ->- MIDI In Endpoint ->- HOST
	9,		 // length of this descriptor
	0x24,	 // 24 = class-specific interface descriptor
	3,		 // 03 = midi out jack
	1,		 // 01 = embedded (not external)
	2,		 // 02 = id 2
	1,		 // 01 = number of input pins on this jack
	1,		 // 01 = connected to entity 1
	1,		 // 01 = connected to output 1 of entity 1
	0,		 // 00 = jack string descriptor

	// Endpoint descriptors for endpoints 1 and 2
	// ------------------------------------------
	7,		// length of this descriptor
	5,		// 05 = ENDPOINT descriptor
	0x81,	// 81 = IN Endpoint 1
	3,		// 03 = Interrupt, not shared
	TX_BUFFER_SIZE,0x00,		// xx xx = maximum payload size
	1,		// 01 = interval 1ms

	5,		// length of this descriptor
	0x25,	// 25 = class-specific endpoint descriptor
	1,		// 01 = general
	1,		// 01 = one jack
	2,		// 02 = jack id 2 (the MIDI OUT jack)

	7,		// length of this descriptor
	5,		// 05 = ENDPOINT descriptor
	0x02,	// 02 = OUT Endpoint 2
	3,		// 03 = Interrupt, not shared
	RX_BUFFER_SIZE,0x00,	  // xx xx = maximum payload size
	1,		// 01 = interval 1ms

	5,		// length of this descriptor
	0x25,	// 25 = class-specific endpoint descriptor
	1,		// 01 = general
	1,		// 01 = one jack
	1		// 01 = jack id 1 (the MIDI IN jack)
};


// ____________________________________________________________________________
//
// String descriptors
// ____________________________________________________________________________
//

// see p273-p274 of usb.org USB 2.0 definition for an explanation
// of these string descriptors.
//
// text is encoded in UTF-16LE:
// see Joel On Software p37; UnicodeECN.pdf in USB spec distribution.

const u8 string_zero[] =
{
	4,			// length of this descriptor
	3,			// 03 = string descriptor
	0x09,0x04	// language ID code zero (04 09 = US English)
};

// ____________________________________________________________________________
//

const u8 string_manufacturer[] =
{
	38,			// length of this descriptor
	3,			// 03 = string descriptor
	'F',0,'o',0, 'c',0,'u',0, 's',0,'r',0, 'i',0,'t',0,
	'e',0,' ',0, 'A',0,'.',0, 'E',0,'.',0, ' ',0,'L',0,
	't',0,'d',0
};

// ____________________________________________________________________________
//


u8 string_product[] =
{
	24,			// length of this descriptor
	3,			// 03 = string descriptor
	'L',0,'a',0, 'u',0,'n',0, 'c',0,'h',0, 'p',0,'a',0,
    'd',0,' ',0, 'S',0,' ',0, ' ',0,' ',0
};

// ____________________________________________________________________________
//

u8 string_interface[] =
{
	24,			// length of this descriptor
	3,			// 03 = string descriptor
	'L',0,'a',0, 'u',0,'n',0, 'c',0,'h',0, 'p',0,'a',0,
    'd',0,' ',0, 'S',0,' ',0, ' ',0,' ',0
};

// ____________________________________________________________________________
//
// USB descriptors : sub-categories
// ____________________________________________________________________________
//

enum {STRINGS = 4};
const u8* string_table[STRINGS] =
{
	string_zero,
	string_manufacturer,
	string_product,
	string_interface,
};

