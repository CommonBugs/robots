/*
 *   robots
 *   Copyright (C) 2012  Thomas GREGOIRE, Quentin SANTOS
 *
 *   This program is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef UTILS_H
#define UTILS_H

#include <assert.h>
#include <stdlib.h>

/* TYPES */

static const char false = 0;
static const char true  = 1;
typedef char bool;

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;

typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;

typedef char*          string;

/* MEMORY MANAGEMENT */

static inline void* my_assert(void* ptr)
{
  assert(ptr);
  return ptr;
}

#define ALLOC(t,n)       (t*) my_assert(malloc(sizeof(t) * n))
#define REALLOC(ptr,t,n) (t*) my_assert(realloc(ptr, sizeof(t) * n))

/* DIRTY STUFF */

#define PACKED __attribute__((packed))

static inline double Angle_ToRad(double t)
{
  while (t < -180.0)
    t += 360.0;
  while (t >= 180.0)
    t -= 360.0;
  return t * 3.14159265358979323846 / 180.0;
}

#endif
