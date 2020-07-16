
// Copyright (c) 2020 Paul Raffer.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#if __cplusplus >= 201103L

#ifndef RAFFER_SYSTEM_SYSTEM_HPP
#define RAFFER_SYSTEM_SYSTEM_HPP

#define raffer_cpplib_system__ 202005L


#include <cstdio>


namespace raffer // interface
{

enum class os
{
	AIX,
	Android,
	Amdahl_UTS,
	AmigaOS,
	Appollo_AEGIS,
	Appollo_Domain_OS,
	Bada,
	BeOS,
	Blue_Gene,
	BSD_Environment,
	BSD_OS,
	ConvexOS,
	Cygwin_Environment,
	DG_UX,
	DragonFly,
	DYNIX_ptx,
	eCos,
	EMX_Environment,
	FreeBSD,
	GNU, GNU_Hurd = GNU,
	GNU_kFreeBSD,
	GNU_Linux,
	HI_UX_MPP,
	HI_UX,
	IBM_OS_400,
	INTEGRITY,
	Interix_Environment,
	IRIX,
	Linux_kernel,
	LynxOS,
	MacOS,
	Microware_OS_9,
	MINIX,
	MorphOS,
	MPE_iX,
	MSDOS,
	NetBSD,
	NonStop,
	Nucleus_RTOS,
	OpenBSD,
	OS_2,
	Palm_OS,
	Plan_9,
	Pyramid_DC_OSx,
	QNX,
	Reliant_UNIX,
	SCO_OpenServer,
	Solaris,
	Stratus_VOS,
	SVR4_Environment,
	Syllable,
	Symbian_OS,
	Tru64,
	Ultrix,
	UNICOS,
	UNICOS_mp,
	UNIX_Environment,
	UnixWare,
	U_Win_Environment,
	VMS,
	VxWorks,
	Windows,
	Windows_CE,
	Wind_U_Environment,
	z_OS,
};


auto clear_screen() -> int;


auto enable_unicode(FILE const * file) -> int;
auto disable_unicode(FILE const * file) -> int;

auto enable_unicode_stdio() -> void;
auto disable_unicode_stdio() -> void;


enum class key
{
	left_mouse_button       = 0x01,
	right_mouse_button      = 0x02,
	controlbreak_processing = 0x03,
	middle_mouse_button     = 0x04,
	x1_mouse_button         = 0x05,
	x2_mouse_button         = 0x06,
//	[undefined]             = 0x07,
	backspace               = 0x08,
	tab                     = 0x09,
//	[reserved]              = 0x0A,
//	[reserved]              = 0x0B,
	clear                   = 0x0C,
	enter                   = 0x0D,
//	[undefined]             = 0x0E,
//	[undefined]             = 0x0F,
	shift                   = 0x10,
	ctrl                    = 0x11,
	alt                     = 0x12,
	pause                   = 0x13,
	caps_lock               = 0x14,
	ime_kana_mode           = 0x15,
	ime_hangul_mode         = 0x16,
	ime_junja_mode          = 0x17,
	ime_final_mode          = 0x18,
	ime_hanja_mode          = 0x19,
	ime_kanji_mode          = 0x19,
	ime_off                 = 0x1A,
	esc                     = 0x1B,
	ime_convert             = 0x1C,
	ime_nonconvert          = 0x1D,
	ime_accept              = 0x1E,
	ime_mode_change_request = 0x1F,
	spacebar                = 0x20,
	page_up                 = 0x21,
	page_down               = 0x22,
	end                     = 0x23,
	home                    = 0x24,
	left_arrow              = 0x25,
	up_arrow                = 0x26,
	right_arrow             = 0x27,
	down_arrow              = 0x28,
	select                  = 0x29,
	print                   = 0x2A,
	execute                 = 0x2B,
	print_screen            = 0x2C,
	ins                     = 0x2D,
	del                     = 0x2E,
	help                    = 0x2F,
	
	_0 = '0', _1, _2, _3, _4, _5, _6, _7, _8, _9,
	
//	[undefined]             = 0x3A,
//	...                       ...
//	[undefined]             = 0x40,
	
	A = 'A', B, C, D, E, F, G, H, I, J, K, L,
	M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z,
	
	left_windows            = 0x5B,
	right_windows           = 0x5C,
	applications            = 0x5D,
//	[reserved]              = 0x5E,
	computer_sleep          = 0x5F,
	
	numpad_0 = 0x60, numpad_1, numpad_2,
	numpad_4, numpad_5, numpad_6,
	numpad_7, numpad_8, numpad_9,
	
	multiply                = 0x6A,
	add                     = 0x6B,
	seperator               = 0x6C,
	subtract                = 0x6D,
	decimal                 = 0x6E,
	divide                  = 0x6F,
	
	F1 = 0x70, F2, F3, F4, F5, F6, F7, F8, F9, F10, F11, F12,
	F13, F14, F15, F16, F17, F18, F19, F20, F21, F22, F23, F24,
	
//	[unassigned]            = 0x88,
//	...                       ...
//	[unassigned]            = 0x8F,
	
	num_lock                = 0x90,
	scroll_lock             = 0x91,
	
//	[OEM specific]          = 0x92,
//	...                       ...
//	[OEM specific]          = 0x96,
	
//	[unassigned]            = 0x97,
//	...                       ...
//	[unassigned]            = 0x9F,
	
	left_shift              = 0xA0,
	right_shift             = 0xA1,
	left_ctrl               = 0xA2,
	right_ctrl              = 0xA3,
	left_alt                = 0xA4,
	right_alt               = 0xA5,
	
	browser_back            = 0xA6,
	browser_forward         = 0xA7,
	browser_refresh         = 0xA8,
	browser_stop            = 0xA9,
	browser_search          = 0xAA,
	browser_favorites       = 0xAB,
	browser_home            = 0xAC,
	
	volume_mute             = 0xAD,
	volume_down             = 0xAE,
	volume_up               = 0xAF,
	
	media_next_track        = 0xB0,
	media_previous_track    = 0xB1,
	media_stop              = 0xB2,
	media_play_pause        = 0xB3,
	
	start_mail              = 0xB4,
	select_media            = 0xB5,
	start_application_1     = 0xB6,
	start_application_2     = 0xB7,
//	[reserved]              = 0xB8,
//	[reserved]              = 0xB9,
	
	oem_1                   = 0xBA,
	oem_plus                = 0xBB,
	oem_comma               = 0xBC,
	oem_minus               = 0xBD,
	oem_period              = 0xBE,
	oem_2                   = 0xBF,
	oem_3                   = 0xC0,
//	[reserved]              = 0xC1,
//	...                       ...
//	[reserved]              = 0xD7,
//	[unassigned]            = 0xD8,
//	...                       ...
//	[unassigned]            = 0xDA,
	oem_4                   = 0xDB,
	oem_5                   = 0xDC,
	oem_6                   = 0xDD,
	oem_7                   = 0xDE,
	oem_8                   = 0xDF,
//	[reserved]              = 0xE0,
//	[OEM specific]          = 0xE1,
	oem_102                 = 0xE2,
//	[OEM specific]          = 0xE3,
//	[OEM specific]          = 0xE4,
	ime_process             = 0xE5,
//	[OEM specific]          = 0xE6,
	packet                  = 0xE7,
//	[unassigned]            = 0xE8,
//	[OEM specific]          = 0xE9,
//	...                       ...
//	[OEM specific]          = 0xF5,
	attn                    = 0xF6,
	crsel                   = 0xF7,
	exsel                   = 0xF8,
	erase_eof               = 0xF9,
	play                    = 0xFA,
	zoom                    = 0xFB,
	noname                  = 0xFC,
	pa1                     = 0xFD,
	oem_clear               = 0xFE,
};

auto is_down(key k) -> bool;
auto is_up(key k) -> bool;

} // namespace raffer


#endif // RAFFER_SYSTEM_SYSTEM_HPP

#endif // __cplusplus >= 201103L
