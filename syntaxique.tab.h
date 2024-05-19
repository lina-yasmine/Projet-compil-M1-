/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_SYNTAXIQUE_TAB_H_INCLUDED
# define YY_YY_SYNTAXIQUE_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    mc_var = 258,                  /* mc_var  */
    mc_dec = 259,                  /* mc_dec  */
    mc_inst = 260,                 /* mc_inst  */
    mc_read = 261,                 /* mc_read  */
    mc_write = 262,                /* mc_write  */
    mc_int = 263,                  /* mc_int  */
    mc_float = 264,                /* mc_float  */
    mc_const = 265,                /* mc_const  */
    mc_struct = 266,               /* mc_struct  */
    mc_if = 267,                   /* mc_if  */
    mc_else = 268,                 /* mc_else  */
    mc_for = 269,                  /* mc_for  */
    mc_while = 270,                /* mc_while  */
    idf = 271,                     /* idf  */
    entier = 272,                  /* entier  */
    entier_sign = 273,             /* entier_sign  */
    reel = 274,                    /* reel  */
    reel_sign = 275,               /* reel_sign  */
    chaineC = 276,                 /* chaineC  */
    and = 277,                     /* and  */
    or = 278,                      /* or  */
    negation = 279,                /* negation  */
    sup = 280,                     /* sup  */
    inf = 281,                     /* inf  */
    sup_eg = 282,                  /* sup_eg  */
    inf_eg = 283,                  /* inf_eg  */
    egal = 284,                    /* egal  */
    not_egal = 285,                /* not_egal  */
    slash = 286,                   /* slash  */
    plus = 287,                    /* plus  */
    minus = 288,                   /* minus  */
    multiply = 289,                /* multiply  */
    pnt_vir = 290,                 /* pnt_vir  */
    virgule = 291,                 /* virgule  */
    aff = 292,                     /* aff  */
    square_brackets_o = 293,       /* square_brackets_o  */
    square_brackets_f = 294,       /* square_brackets_f  */
    curly_brackets_o = 295,        /* curly_brackets_o  */
    curly_brackets_f = 296,        /* curly_brackets_f  */
    round_brackets_o = 297,        /* round_brackets_o  */
    round_brackets_f = 298,        /* round_brackets_f  */
    pnt = 299,                     /* pnt  */
    double_pnt = 300               /* double_pnt  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 41 "syntaxique.y"

int num;
float real;
char car;
char * str;
struct {
char * type;
char * val;
char *t;
} EXP;


#line 122 "syntaxique.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_SYNTAXIQUE_TAB_H_INCLUDED  */
