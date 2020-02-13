/*
 * utils.h
 *
 * Created on: Feb 9, 2020
 *      Author: seif_
 */
#ifndef UTILS_H_
#define UTILS_H_

#include "std_types.h"

#define SETBIT(num, bit) (num) |= (1<<bit)

#define CLRBIT(num, bit) (num) &= ~(1<<bit)

#define TOGGLEBIT(num, bit) (num) ^= (1<<bit)

#define GETBIT(num, bit) (((num)>>(bit)) & 0x01)		//((((num) & (1 << bit)) != 0) ? 1:0)

#define OFFSET(base, offset) *(volatile u32*)(base + offset)

#define CONCBIT(B7,B6,B5,B4,B3,B2,B1,B0) CONCBIT_HELPER(B7,B6,B5,B4,B3,B2,B1,B0)
#define CONCBIT_HELPER(B7,B6,B5,B4,B3,B2,B1,B0)  (0b##B7##B6##B5##B4##B3##B2##B1##B0)

#endif /* UTILS_H_ */
