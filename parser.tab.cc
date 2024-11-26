// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.



// First part of user prologue.
#line 2 "parser.y"

    #include <cstdio>
    #include <cstdlib>
    #include "ast.hpp"
    #include <string>

    int yylex();
    int yylineo();
    void yyerror(const char *s) {
        fprintf(stderr, "Error at line %i: %s\n",yylineo(), s);
    }

#line 54 "parser.tab.cc"


#include "parser.tab.hh"




#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif


// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif



// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yy_stack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

namespace yy {
#line 132 "parser.tab.cc"

  /// Build a parser object.
  parser::parser ()
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr)
#else

#endif
  {}

  parser::~parser ()
  {}

  parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------.
  | symbol.  |
  `---------*/

  // basic_symbol.
  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value (that.value)
  {}


  /// Constructor for valueless symbols.
  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t)
    : Base (t)
    , value ()
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, YY_RVREF (value_type) v)
    : Base (t)
    , value (YY_MOVE (v))
  {}


  template <typename Base>
  parser::symbol_kind_type
  parser::basic_symbol<Base>::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }


  template <typename Base>
  bool
  parser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return this->kind () == symbol_kind::S_YYEMPTY;
  }

  template <typename Base>
  void
  parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    value = YY_MOVE (s.value);
  }

  // by_kind.
  parser::by_kind::by_kind () YY_NOEXCEPT
    : kind_ (symbol_kind::S_YYEMPTY)
  {}

#if 201103L <= YY_CPLUSPLUS
  parser::by_kind::by_kind (by_kind&& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {
    that.clear ();
  }
#endif

  parser::by_kind::by_kind (const by_kind& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {}

  parser::by_kind::by_kind (token_kind_type t) YY_NOEXCEPT
    : kind_ (yytranslate_ (t))
  {}



  void
  parser::by_kind::clear () YY_NOEXCEPT
  {
    kind_ = symbol_kind::S_YYEMPTY;
  }

  void
  parser::by_kind::move (by_kind& that)
  {
    kind_ = that.kind_;
    that.clear ();
  }

  parser::symbol_kind_type
  parser::by_kind::kind () const YY_NOEXCEPT
  {
    return kind_;
  }


  parser::symbol_kind_type
  parser::by_kind::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }



  // by_state.
  parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  parser::symbol_kind_type
  parser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  parser::stack_symbol_type::stack_symbol_type ()
  {}

  parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.value))
  {
#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.value))
  {
    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    value = that.value;
    return *this;
  }

  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    value = that.value;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);

    // User destructor.
    YY_USE (yysym.kind ());
  }

#if YYDEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YY_USE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " (";
        YY_USE (yykind);
        yyo << ')';
      }
  }
#endif

  void
  parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  parser::yypop_ (int n) YY_NOEXCEPT
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  parser::state_type
  parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  parser::yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  parser::yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::operator() ()
  {
    return parse ();
  }

  int
  parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';
    YY_STACK_PRINT ();

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            yyla.kind_ = yytranslate_ (yylex (&yyla.value));
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* If YYLEN is nonzero, implement the default value of the
         action: '$$ = $1'.  Otherwise, use the top of the stack.

         Otherwise, the following line sets YYLHS.VALUE to garbage.
         This behavior is undocumented and Bison users should not rely
         upon it.  */
      if (yylen)
        yylhs.value = yystack_[yylen - 1].value;
      else
        yylhs.value = yystack_[0].value;


      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2: // programa: declaracao-lista $end
#line 32 "parser.y"
                          { 
        printf("Parsed a programa\n"); 
        (yylhs.value.ast) = new ASTNode("programa");
        (yylhs.value.ast)->insertChildren((yystack_[1].value.ast));
        AST* tree = new AST((yylhs.value.ast));
        tree->printTree();
    }
#line 594 "parser.tab.cc"
    break;

  case 3: // declaracao-lista: declaracao-lista declaracao
#line 41 "parser.y"
                                { 
        printf("Parsed a declaracao-lista\n"); 
        (yylhs.value.ast) = new ASTNode("declaracao-lista");
        (yylhs.value.ast)->insertChildren((yystack_[0].value.ast));
        }
#line 604 "parser.tab.cc"
    break;

  case 4: // declaracao-lista: declaracao
#line 46 "parser.y"
               { 
        printf("Parsed a declaracao-lista\n"); 
        (yylhs.value.ast) = new ASTNode("declaracao-lista");
        (yylhs.value.ast)->insertChildren((yystack_[0].value.ast));
        }
#line 614 "parser.tab.cc"
    break;

  case 5: // declaracao: var-declaracao
#line 53 "parser.y"
                   { 
        printf("Parsed a declaracao\n"); 
        (yylhs.value.ast) = new ASTNode("declaracao");
        (yylhs.value.ast)->insertChildren((yystack_[0].value.ast));
        }
#line 624 "parser.tab.cc"
    break;

  case 6: // declaracao: fun-declaracao
#line 58 "parser.y"
                   { 
        printf("Parsed a declaracao\n"); 
        (yylhs.value.ast) = new ASTNode("declaracao");
        (yylhs.value.ast)->insertChildren((yystack_[0].value.ast));
    }
#line 634 "parser.tab.cc"
    break;

  case 7: // var-declaracao: tipo-especificador ID PV
#line 65 "parser.y"
                             { 
        printf("Parsed a var-declaracao\n"); 
        (yylhs.value.ast) = new ASTNode("var-declaracao");
        (yylhs.value.ast)->insertChildren((yystack_[2].value.ast));
        (yylhs.value.ast)->insertChildren(new ASTNode((yystack_[1].value.name)));
    }
#line 645 "parser.tab.cc"
    break;

  case 8: // var-declaracao: tipo-especificador ID OB NUMBER CB PV
#line 71 "parser.y"
                                          { 
        printf("Parsed a var-declaracao\n"); 
        (yylhs.value.ast) = new ASTNode("var-declaracao");
        (yylhs.value.ast)->insertChildren((yystack_[5].value.ast));
        (yylhs.value.ast)->insertChildren(new ASTNode((yystack_[4].value.name)));
        (yylhs.value.ast)->insertChildren(new ASTNode((yystack_[3].value.name)));
        (yylhs.value.ast)->insertChildren(new ASTNode((yystack_[2].value.name)));
        (yylhs.value.ast)->insertChildren(new ASTNode((yystack_[1].value.name)));
    }
#line 659 "parser.tab.cc"
    break;

  case 9: // tipo-especificador: INT
#line 82 "parser.y"
        { 
        printf("Parsed a tipo-especificador \n") ;
        (yylhs.value.ast) = new ASTNode((yystack_[0].value.name));
    }
#line 668 "parser.tab.cc"
    break;

  case 10: // tipo-especificador: VOID
#line 86 "parser.y"
         { 
        printf("Parsed a tipo-especificador \n") ;
        (yylhs.value.ast) = new ASTNode((yystack_[0].value.name));
    }
#line 677 "parser.tab.cc"
    break;

  case 11: // fun-declaracao: tipo-especificador ID OP params CP composto-decl
#line 93 "parser.y"
                                                     { printf("Parsed a fun-declaracao\n"); }
#line 683 "parser.tab.cc"
    break;

  case 12: // params: params-lista
#line 96 "parser.y"
                 { printf("Parsed a params\n"); }
#line 689 "parser.tab.cc"
    break;

  case 13: // params: VOID
#line 97 "parser.y"
         { printf("Parsed a params\n"); }
#line 695 "parser.tab.cc"
    break;

  case 14: // params-lista: params-lista COMMA param
#line 100 "parser.y"
                             { printf("Parsed a params-lista\n"); }
#line 701 "parser.tab.cc"
    break;

  case 15: // params-lista: param
#line 101 "parser.y"
          { printf("Parsed a params-lista\n"); }
#line 707 "parser.tab.cc"
    break;

  case 16: // param: tipo-especificador ID
#line 104 "parser.y"
                          { printf("Parsed a param\n"); }
#line 713 "parser.tab.cc"
    break;

  case 17: // param: tipo-especificador ID OB CB
#line 105 "parser.y"
                                { printf("Parsed a param\n"); }
#line 719 "parser.tab.cc"
    break;

  case 18: // composto-decl: OCB local-declaracoes statement-lista CCB
#line 108 "parser.y"
                                              { printf("Parsed a composto-decl\n"); }
#line 725 "parser.tab.cc"
    break;

  case 19: // local-declaracoes: local-declaracoes var-declaracao
#line 111 "parser.y"
                                     { printf("Parsed a local-declaracoes\n"); }
#line 731 "parser.tab.cc"
    break;

  case 21: // local-declaracoes: %empty
#line 112 "parser.y"
                  { /* This is the base case for recursion */ }
#line 737 "parser.tab.cc"
    break;

  case 22: // statement-lista: statement-lista statement
#line 115 "parser.y"
                              { printf("Parsed a statement-lista\n"); }
#line 743 "parser.tab.cc"
    break;

  case 24: // statement-lista: %empty
#line 116 "parser.y"
                  { /* This is the base case for recursion */ }
#line 749 "parser.tab.cc"
    break;

  case 25: // statement: expressao-decl
#line 119 "parser.y"
                   { printf("Parsed a statement\n"); }
#line 755 "parser.tab.cc"
    break;

  case 26: // statement: composto-decl
#line 120 "parser.y"
                  { printf("Parsed a statement\n"); }
#line 761 "parser.tab.cc"
    break;

  case 27: // statement: selecao-decl
#line 121 "parser.y"
                 { printf("Parsed a statement\n"); }
#line 767 "parser.tab.cc"
    break;

  case 28: // statement: iteracao-decl
#line 122 "parser.y"
                  { printf("Parsed a statement\n"); }
#line 773 "parser.tab.cc"
    break;

  case 29: // statement: retorno-decl
#line 123 "parser.y"
                 { printf("Parsed a statement\n"); }
#line 779 "parser.tab.cc"
    break;

  case 31: // expressao-decl: expressao PV
#line 126 "parser.y"
                 { printf("Parsed a expressao-decl\n"); }
#line 785 "parser.tab.cc"
    break;

  case 32: // expressao-decl: PV
#line 127 "parser.y"
       { printf("Parsed a expressao-decl\n"); }
#line 791 "parser.tab.cc"
    break;

  case 33: // selecao-decl: IF OP expressao CP statement
#line 130 "parser.y"
                                 { printf("Parsed a selecao-decl\n"); }
#line 797 "parser.tab.cc"
    break;

  case 34: // selecao-decl: IF OP expressao CP statement ELSE statement
#line 131 "parser.y"
                                                { printf("Parsed a selecao-decl\n"); }
#line 803 "parser.tab.cc"
    break;

  case 35: // iteracao-decl: WHILE OP expressao CP statement
#line 134 "parser.y"
                                    { printf("Parsed a iteracao-decl\n"); }
#line 809 "parser.tab.cc"
    break;

  case 36: // retorno-decl: RETURN PV
#line 137 "parser.y"
              { printf("Parsed a retorno-decl\n"); }
#line 815 "parser.tab.cc"
    break;

  case 37: // retorno-decl: RETURN expressao
#line 138 "parser.y"
                     { printf("Parsed a retorno-decl\n"); }
#line 821 "parser.tab.cc"
    break;

  case 38: // expressao: var EQUAL expressao
#line 141 "parser.y"
                        { printf("Parsed a expressao\n"); }
#line 827 "parser.tab.cc"
    break;

  case 39: // expressao: simples-expressao
#line 142 "parser.y"
                      { printf("Parsed a expressao\n"); }
#line 833 "parser.tab.cc"
    break;

  case 40: // var: ID
#line 145 "parser.y"
       { printf("Parsed a var\n"); }
#line 839 "parser.tab.cc"
    break;

  case 41: // var: ID OB expressao CB
#line 146 "parser.y"
                       { printf("Parsed a var\n"); }
#line 845 "parser.tab.cc"
    break;

  case 42: // simples-expressao: soma-expressao RELOP soma-expressao
#line 149 "parser.y"
                                        { printf("Parsed a simplex-exmpressao\n"); }
#line 851 "parser.tab.cc"
    break;

  case 43: // simples-expressao: soma-expressao
#line 150 "parser.y"
                   { printf("Parsed a simples-expressao\n"); }
#line 857 "parser.tab.cc"
    break;

  case 45: // soma-expressao: soma-expressao soma termo
#line 154 "parser.y"
                              { printf("Parsed a soma-expressao\n"); }
#line 863 "parser.tab.cc"
    break;

  case 46: // soma-expressao: termo
#line 155 "parser.y"
          { printf("Parsed a soma-expressao\n"); }
#line 869 "parser.tab.cc"
    break;

  case 47: // soma: PLUS
#line 158 "parser.y"
         { printf("Parsed a soma\n"); }
#line 875 "parser.tab.cc"
    break;

  case 48: // soma: MINUS
#line 159 "parser.y"
          { printf("Parsed a subtracao\n"); }
#line 881 "parser.tab.cc"
    break;

  case 49: // termo: termo mult fator
#line 162 "parser.y"
                     { printf("Parsed a termo\n"); }
#line 887 "parser.tab.cc"
    break;

  case 50: // termo: fator
#line 163 "parser.y"
          { printf("Parsed a termo\n"); }
#line 893 "parser.tab.cc"
    break;

  case 51: // mult: TIMES
#line 166 "parser.y"
          { printf("Parsed a mult\n"); }
#line 899 "parser.tab.cc"
    break;

  case 52: // mult: DIV
#line 167 "parser.y"
        { printf("Parsed a div\n"); }
#line 905 "parser.tab.cc"
    break;

  case 53: // fator: OP expressao CP
#line 170 "parser.y"
                    { printf("Parsed a fator\n"); }
#line 911 "parser.tab.cc"
    break;

  case 54: // fator: var
#line 171 "parser.y"
        { printf("Parsed a fator\n"); }
#line 917 "parser.tab.cc"
    break;

  case 55: // fator: ativacao
#line 172 "parser.y"
             { printf("Parsed a fator\n"); }
#line 923 "parser.tab.cc"
    break;

  case 56: // fator: NUMBER
#line 173 "parser.y"
           { printf("Parsed a fator\n"); }
#line 929 "parser.tab.cc"
    break;

  case 57: // ativacao: ID OP args CP
#line 176 "parser.y"
                  { printf("Parsed a ativacao\n"); }
#line 935 "parser.tab.cc"
    break;

  case 58: // args: arg-lista
#line 179 "parser.y"
              { printf("Parsed a args\n"); }
#line 941 "parser.tab.cc"
    break;

  case 59: // args: %empty
#line 180 "parser.y"
                  { /* This is the base case for recursion */ }
#line 947 "parser.tab.cc"
    break;

  case 60: // arg-lista: arg-lista COMMA expressao
#line 182 "parser.y"
                              { printf("Parsed a arg-lista\n"); }
#line 953 "parser.tab.cc"
    break;

  case 61: // arg-lista: expressao
#line 183 "parser.y"
              { printf("Parsed a arg-lista\n"); }
#line 959 "parser.tab.cc"
    break;


#line 963 "parser.tab.cc"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        std::string msg = YY_("syntax error");
        error (YY_MOVE (msg));
      }


    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
              {
                yyn = yytable_[yyn];
                if (0 < yyn)
                  break;
              }
          }

        // Pop the current state because it cannot handle the error token.
        if (yystack_.size () == 1)
          YYABORT;

        yy_destroy_ ("Error: popping", yystack_[0]);
        yypop_ ();
        YY_STACK_PRINT ();
      }
    {
      stack_symbol_type error_token;


      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    YY_STACK_PRINT ();
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.what ());
  }

#if YYDEBUG || 0
  const char *
  parser::symbol_name (symbol_kind_type yysymbol)
  {
    return yytname_[yysymbol];
  }
#endif // #if YYDEBUG || 0









  const signed char parser::yypact_ninf_ = -41;

  const signed char parser::yytable_ninf_ = -60;

  const signed char
  parser::yypact_[] =
  {
      35,   -41,   -41,    16,    61,   -41,   -41,     7,   -41,   -41,
     -41,   -41,   -11,   -41,    70,    28,    18,    40,    43,    64,
     -41,    62,    65,    60,    35,    68,    66,   -41,   -41,   -41,
     -41,   -41,    35,   -41,    76,    36,    52,   -41,   -41,    71,
      51,    72,   -18,   -41,     6,   -41,   -41,   -41,   -41,   -41,
     -41,   -41,    75,    69,   -41,     1,    63,   -41,   -41,     6,
     -41,   -41,     6,    10,     6,    73,   -41,     6,    53,   -41,
     -41,    53,   -41,   -41,    53,    77,    78,   -41,    79,    82,
      74,   -41,   -41,   -41,    67,    63,   -41,    25,    25,   -41,
       6,   -41,    81,   -41,   -41,    25,   -41
  };

  const signed char
  parser::yydefact_[] =
  {
       0,     9,    10,     0,     0,     4,     5,     0,     6,     1,
       2,     3,     0,     7,     0,     0,    10,     0,     0,    12,
      15,     0,    16,     0,     0,     0,     0,    20,    11,    14,
       8,    17,    23,    19,     0,     0,     0,    44,    56,     0,
       0,     0,    40,    32,     0,    18,    26,    22,    25,    27,
      28,    29,     0,    54,    39,    43,    46,    50,    55,     0,
      36,    37,     0,     0,     0,     0,    31,     0,     0,    47,
      48,     0,    51,    52,     0,     0,     0,    61,     0,    58,
       0,    53,    38,    54,    42,    45,    49,     0,     0,    57,
       0,    41,    33,    35,    60,     0,    34
  };

  const signed char
  parser::yypgoto_[] =
  {
     -41,   -41,   -41,    91,    80,   -12,   -41,   -41,   -41,    83,
      85,   -41,   -41,   -30,   -41,   -41,   -41,   -41,   -40,     3,
     -41,    33,   -41,    31,   -41,    29,   -41,   -41,   -41
  };

  const signed char
  parser::yydefgoto_[] =
  {
       0,     3,     4,     5,     6,     7,     8,    18,    19,    20,
      46,    32,    35,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    71,    56,    74,    57,    58,    78,    79
  };

  const signed char
  parser::yytable_[] =
  {
      61,    63,    17,    64,    65,    68,    13,    37,    14,    38,
      15,    37,    17,    38,    69,    70,     9,    42,    12,    75,
      34,    42,    76,    77,    80,    44,    37,    82,    38,    44,
     -59,    21,    39,   -30,    40,    41,    42,    37,   -13,    38,
       1,     2,    43,    39,    44,    40,    41,    42,    27,   -30,
      94,    22,    37,    43,    38,    44,    38,    92,    93,    27,
      45,    10,    42,    23,    42,    96,     1,     2,    60,    13,
      44,    83,    44,    15,    83,     1,    16,    83,    72,    73,
      69,    70,    24,    27,    25,    30,    26,    36,    31,    95,
      59,    62,    66,    81,    67,    11,    91,    87,    88,    89,
      90,    84,    85,    86,     0,     0,     0,    29,    28,     0,
       0,     0,    33
  };

  const signed char
  parser::yycheck_[] =
  {
      40,    19,    14,    21,    44,     4,    17,     1,    19,     3,
      21,     1,    24,     3,    13,    14,     0,    11,    11,    59,
      32,    11,    62,    63,    64,    19,     1,    67,     3,    19,
      20,     3,     7,     8,     9,    10,    11,     1,    20,     3,
       5,     6,    17,     7,    19,     9,    10,    11,    23,    24,
      90,    11,     1,    17,     3,    19,     3,    87,    88,    23,
      24,     0,    11,    20,    11,    95,     5,     6,    17,    17,
      19,    68,    19,    21,    71,     5,     6,    74,    15,    16,
      13,    14,    18,    23,    22,    17,    21,    11,    22,     8,
      19,    19,    17,    20,    25,     4,    22,    20,    20,    20,
      18,    68,    71,    74,    -1,    -1,    -1,    24,    23,    -1,
      -1,    -1,    32
  };

  const signed char
  parser::yystos_[] =
  {
       0,     5,     6,    29,    30,    31,    32,    33,    34,     0,
       0,    31,    11,    17,    19,    21,     6,    33,    35,    36,
      37,     3,    11,    20,    18,    22,    21,    23,    38,    37,
      17,    22,    39,    32,    33,    40,    11,     1,     3,     7,
       9,    10,    11,    17,    19,    24,    38,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    51,    53,    54,    19,
      17,    46,    19,    19,    21,    46,    17,    25,     4,    13,
      14,    50,    15,    16,    52,    46,    46,    46,    55,    56,
      46,    20,    46,    47,    49,    51,    53,    20,    20,    20,
      18,    22,    41,    41,    46,     8,    41
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    28,    29,    30,    30,    31,    31,    32,    32,    33,
      33,    34,    35,    35,    36,    36,    37,    37,    38,    39,
      39,    39,    40,    40,    40,    41,    41,    41,    41,    41,
      41,    42,    42,    43,    43,    44,    45,    45,    46,    46,
      47,    47,    48,    48,    48,    49,    49,    50,    50,    51,
      51,    52,    52,    53,    53,    53,    53,    54,    55,    55,
      56,    56
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     2,     2,     1,     1,     1,     3,     6,     1,
       1,     6,     1,     1,     3,     1,     2,     4,     4,     2,
       0,     0,     2,     0,     0,     1,     1,     1,     1,     1,
       0,     2,     1,     5,     7,     5,     2,     2,     3,     1,
       1,     4,     3,     1,     1,     3,     1,     1,     1,     3,
       1,     1,     1,     3,     1,     1,     1,     4,     1,     0,
       3,     1
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "NUMBER", "RELOP",
  "INT", "VOID", "IF", "ELSE", "RETURN", "WHILE", "ID", "FOR", "PLUS",
  "MINUS", "TIMES", "DIV", "PV", "COMMA", "OP", "CP", "OB", "CB", "OCB",
  "CCB", "EQUAL", "VEJODEPOIS", "ERROR", "$accept", "programa",
  "declaracao-lista", "declaracao", "var-declaracao", "tipo-especificador",
  "fun-declaracao", "params", "params-lista", "param", "composto-decl",
  "local-declaracoes", "statement-lista", "statement", "expressao-decl",
  "selecao-decl", "iteracao-decl", "retorno-decl", "expressao", "var",
  "simples-expressao", "soma-expressao", "soma", "termo", "mult", "fator",
  "ativacao", "args", "arg-lista", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const unsigned char
  parser::yyrline_[] =
  {
       0,    32,    32,    41,    46,    53,    58,    65,    71,    82,
      86,    93,    96,    97,   100,   101,   104,   105,   108,   111,
     111,   112,   115,   115,   116,   119,   120,   121,   122,   123,
     123,   126,   127,   130,   131,   134,   137,   138,   141,   142,
     145,   146,   149,   150,   151,   154,   155,   158,   159,   162,
     163,   166,   167,   170,   171,   172,   173,   176,   179,   180,
     182,   183
  };

  void
  parser::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
  parser::yy_reduce_print_ (int yyrule) const
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG

  parser::symbol_kind_type
  parser::yytranslate_ (int t) YY_NOEXCEPT
  {
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
    static
    const signed char
    translate_table[] =
    {
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27
    };
    // Last valid token kind.
    const int code_max = 282;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= code_max)
      return static_cast <symbol_kind_type> (translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

} // yy
#line 1387 "parser.tab.cc"

#line 184 "parser.y"


