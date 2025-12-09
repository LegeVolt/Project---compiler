%{
#include "date.tab.h"
%}

%%
August           return AUGUST;
September        return SEPTEMBER;
October          return OCTOBER;
November         return NOVEMBER;
December         return DECEMBER;
20[0-9][0-9]     return YEAR;
.                return yytext[0];
%%

int yywrap(void) {
    return 1;
}