/**
 * bAtari-Basic
 * Copyright (c) 2021
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 */

/**
 * macros.h
 * General-purpose macros and defines
 */
typedef unsigned char BOOL;
#define false 0
#define true  1

#define _BV(N)          (1 << (N))
#define MATCH(VAR,STR)  (!strncmp(VAR, STR, strlen(STR)))
#define SMATCH(IND,STR) MATCH(statement[IND], STR)
#define EMATCH(IND,STR) (SMATCH(IND,STR) || SMATCH(IND,STR "\n") || SMATCH(IND,STR "\r"))
#define IMATCH(IND,STR) (!strncasecmp(statement[IND], STR, strlen(STR)))
#define CMATCH(IND,CHR) (statement[IND][0] == CHR)
#define WITHIN(N,A,B)   ((unsigned char)(N)>=(unsigned char)(A)&&(unsigned char)(N)<=(unsigned char)(A))
#define ISNUM(C)        WITHIN(C,'0','9')
#define COUNT(X)        (sizeof(X)/sizeof(*X))

enum {
  BS_DPC_PLUS = 28,
  BS_4K = 0,
  BS_8K = 8,
  BS_16K = 16,
  BS_32K = 32,
  BS_64K = 64
};
