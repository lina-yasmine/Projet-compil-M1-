rm TP
flex lexical.l  && bison -d syntaxique.y && gcc -o TP  lex.yy.c syntaxique.tab.c && ./TP<$1