/**
 * macros.h
 * General-purpose macros and defines
 *
 * Provided under the GPL v2 license. See the included LICENSE.txt for details.
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
