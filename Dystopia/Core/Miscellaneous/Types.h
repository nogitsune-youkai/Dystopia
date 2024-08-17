#pragma once
#include <stdint.h>

/*
This file is used to specify data types for use in other classes
*/
constexpr auto Reserved = 0; // reserved values shouldn't be used 

using UCHAR = uint8_t; // 8 bit value
using USHORT = uint16_t; // 16 bit value
using ULONG = uint32_t; // 32 bit value
using ULONGLONG = uint64_t; // 64 bit value