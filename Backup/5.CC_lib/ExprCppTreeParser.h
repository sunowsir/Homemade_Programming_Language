/** \file
 *  This C header file was generated by $ANTLR version 3.4
 *
 *     -  From the grammar source file : /home/sunowsir/GitHub/2.My_Project/10.Homemade_Programming_Language/5.CC_lib/ExprCppTree.g
 *     -                            On : 2019-04-03 15:21:43
 *     -                for the parser : ExprCppTreeParserParser
 *
 * Editing it, at least manually, is not wise.
 *
 * C language generator and runtime by Jim Idle, jimi|hereisanat|idle|dotgoeshere|ws.
 *
 *
 * The parser 
ExprCppTreeParser

has the callable functions (rules) shown below,
 * which will invoke the code for the associated rule in the source grammar
 * assuming that the input stream is pointing to a token/text stream that could begin
 * this rule.
 *
 * For instance if you call the first (topmost) rule in a parser grammar, you will
 * get the results of a full parse, but calling a rule half way through the grammar will
 * allow you to pass part of a full token stream to the parser, such as for syntax checking
 * in editors and so on.
 *
 * The parser entry points are called indirectly (by function pointer to function) via
 * a parser context typedef pExprCppTreeParser, which is returned from a call to ExprCppTreeParserNew().
 *
 * The methods in pExprCppTreeParser are  as follows:
 *
 *  - 
 ExprCppTreeParser_atom_return
      pExprCppTreeParser->atom(pExprCppTreeParser)
 *  - 
 ExprCppTreeParser_notExpr_return
      pExprCppTreeParser->notExpr(pExprCppTreeParser)
 *  - 
 ExprCppTreeParser_timesExpr_return
      pExprCppTreeParser->timesExpr(pExprCppTreeParser)
 *  - 
 ExprCppTreeParser_orderExpr_return
      pExprCppTreeParser->orderExpr(pExprCppTreeParser)
 *  - 
 ExprCppTreeParser_unbalanceExpr_return
      pExprCppTreeParser->unbalanceExpr(pExprCppTreeParser)
 *  - 
 ExprCppTreeParser_balanceExpr_return
      pExprCppTreeParser->balanceExpr(pExprCppTreeParser)
 *  - 
 ExprCppTreeParser_bitAndExpr_return
      pExprCppTreeParser->bitAndExpr(pExprCppTreeParser)
 *  - 
 ExprCppTreeParser_xorExpr_return
      pExprCppTreeParser->xorExpr(pExprCppTreeParser)
 *  - 
 ExprCppTreeParser_bitOrExpr_return
      pExprCppTreeParser->bitOrExpr(pExprCppTreeParser)
 *  - 
 ExprCppTreeParser_andExpr_return
      pExprCppTreeParser->andExpr(pExprCppTreeParser)
 *  - 
 ExprCppTreeParser_orExpr_return
      pExprCppTreeParser->orExpr(pExprCppTreeParser)
 *  - 
 ExprCppTreeParser_assignExpr_return
      pExprCppTreeParser->assignExpr(pExprCppTreeParser)
 *  - 
 ExprCppTreeParser_commaExpr_return
      pExprCppTreeParser->commaExpr(pExprCppTreeParser)
 *  - 
 ExprCppTreeParser_ifcondBaseExpr_return
      pExprCppTreeParser->ifcondBaseExpr(pExprCppTreeParser)
 *  - 
 ExprCppTreeParser_elifExpr_return
      pExprCppTreeParser->elifExpr(pExprCppTreeParser)
 *  - 
 ExprCppTreeParser_elseExpr_return
      pExprCppTreeParser->elseExpr(pExprCppTreeParser)
 *  - 
 ExprCppTreeParser_ifExpr_return
      pExprCppTreeParser->ifExpr(pExprCppTreeParser)
 *  - 
 ExprCppTreeParser_forExpr_return
      pExprCppTreeParser->forExpr(pExprCppTreeParser)
 *  - 
 ExprCppTreeParser_whileExpr_return
      pExprCppTreeParser->whileExpr(pExprCppTreeParser)
 *  - 
 ExprCppTreeParser_defIdExpr_return
      pExprCppTreeParser->defIdExpr(pExprCppTreeParser)
 *  - 
 ExprCppTreeParser_defExpr_return
      pExprCppTreeParser->defExpr(pExprCppTreeParser)
 *  - 
 ExprCppTreeParser_stmt_return
      pExprCppTreeParser->stmt(pExprCppTreeParser)
 *  - 
 ExprCppTreeParser_block_base_return
      pExprCppTreeParser->block_base(pExprCppTreeParser)
 *  - 
 ExprCppTreeParser_block_return
      pExprCppTreeParser->block(pExprCppTreeParser)
 *  - 
 ExprCppTreeParser_mainBlock_return
      pExprCppTreeParser->mainBlock(pExprCppTreeParser)
 *  - 
 ExprCppTreeParser_prog_return
      pExprCppTreeParser->prog(pExprCppTreeParser)
 *
 * The return type for any particular rule is of course determined by the source
 * grammar file.
 */
// [The "BSD license"]
// Copyright (c) 2005-2009 Jim Idle, Temporal Wave LLC
// http://www.temporal-wave.com
// http://www.linkedin.com/in/jimidle
//
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions
// are met:
// 1. Redistributions of source code must retain the above copyright
//    notice, this list of conditions and the following disclaimer.
// 2. Redistributions in binary form must reproduce the above copyright
//    notice, this list of conditions and the following disclaimer in the
//    documentation and/or other materials provided with the distribution.
// 3. The name of the author may not be used to endorse or promote products
//    derived from this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
// IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
// OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
// IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
// INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
// NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
// THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#ifndef	_ExprCppTreeParser_H
#define _ExprCppTreeParser_H
/* =============================================================================
 * Standard antlr3 C runtime definitions
 */
#include    <antlr3.h>

/* End of standard antlr 3 runtime definitions
 * =============================================================================
 */

#ifdef __cplusplus
extern "C" {
#endif

// Forward declare the context typedef so that we can use it before it is
// properly defined. Delegators and delegates (from import statements) are
// interdependent and their context structures contain pointers to each other
// C only allows such things to be declared if you pre-declare the typedef.
//
typedef struct ExprCppTreeParser_Ctx_struct ExprCppTreeParser, * pExprCppTreeParser;



    #include <assert.h>


#ifdef	ANTLR3_WINDOWS
// Disable: Unreferenced parameter,							- Rules with parameters that are not used
//          constant conditional,							- ANTLR realizes that a prediction is always true (synpred usually)
//          initialized but unused variable					- tree rewrite variables declared but not needed
//          Unreferenced local variable						- lexer rule declares but does not always use _type
//          potentially unitialized variable used			- retval always returned from a rule
//			unreferenced local function has been removed	- susually getTokenNames or freeScope, they can go without warnigns
//
// These are only really displayed at warning level /W4 but that is the code ideal I am aiming at
// and the codegen must generate some of these warnings by necessity, apart from 4100, which is
// usually generated when a parser rule is given a parameter that it does not use. Mostly though
// this is a matter of orthogonality hence I disable that one.
//
#pragma warning( disable : 4100 )
#pragma warning( disable : 4101 )
#pragma warning( disable : 4127 )
#pragma warning( disable : 4189 )
#pragma warning( disable : 4505 )
#pragma warning( disable : 4701 )
#endif
typedef struct ExprCppTreeParser_atom_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    ExprCppTreeParser_atom_return;



typedef struct ExprCppTreeParser_notExpr_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    ExprCppTreeParser_notExpr_return;



typedef struct ExprCppTreeParser_timesExpr_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    ExprCppTreeParser_timesExpr_return;



typedef struct ExprCppTreeParser_orderExpr_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    ExprCppTreeParser_orderExpr_return;



typedef struct ExprCppTreeParser_unbalanceExpr_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    ExprCppTreeParser_unbalanceExpr_return;



typedef struct ExprCppTreeParser_balanceExpr_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    ExprCppTreeParser_balanceExpr_return;



typedef struct ExprCppTreeParser_bitAndExpr_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    ExprCppTreeParser_bitAndExpr_return;



typedef struct ExprCppTreeParser_xorExpr_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    ExprCppTreeParser_xorExpr_return;



typedef struct ExprCppTreeParser_bitOrExpr_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    ExprCppTreeParser_bitOrExpr_return;



typedef struct ExprCppTreeParser_andExpr_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    ExprCppTreeParser_andExpr_return;



typedef struct ExprCppTreeParser_orExpr_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    ExprCppTreeParser_orExpr_return;



typedef struct ExprCppTreeParser_assignExpr_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    ExprCppTreeParser_assignExpr_return;



typedef struct ExprCppTreeParser_commaExpr_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    ExprCppTreeParser_commaExpr_return;



typedef struct ExprCppTreeParser_ifcondBaseExpr_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    ExprCppTreeParser_ifcondBaseExpr_return;



typedef struct ExprCppTreeParser_elifExpr_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    ExprCppTreeParser_elifExpr_return;



typedef struct ExprCppTreeParser_elseExpr_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    ExprCppTreeParser_elseExpr_return;



typedef struct ExprCppTreeParser_ifExpr_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    ExprCppTreeParser_ifExpr_return;



typedef struct ExprCppTreeParser_forExpr_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    ExprCppTreeParser_forExpr_return;



typedef struct ExprCppTreeParser_whileExpr_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    ExprCppTreeParser_whileExpr_return;



typedef struct ExprCppTreeParser_defIdExpr_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    ExprCppTreeParser_defIdExpr_return;



typedef struct ExprCppTreeParser_defExpr_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    ExprCppTreeParser_defExpr_return;



typedef struct ExprCppTreeParser_stmt_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    ExprCppTreeParser_stmt_return;



typedef struct ExprCppTreeParser_block_base_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    ExprCppTreeParser_block_base_return;



typedef struct ExprCppTreeParser_block_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    ExprCppTreeParser_block_return;



typedef struct ExprCppTreeParser_mainBlock_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    ExprCppTreeParser_mainBlock_return;



typedef struct ExprCppTreeParser_prog_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    ExprCppTreeParser_prog_return;




/** Context tracking structure for 
ExprCppTreeParser

 */
struct ExprCppTreeParser_Ctx_struct
{
    /** Built in ANTLR3 context tracker contains all the generic elements
     *  required for context tracking.
     */
    pANTLR3_PARSER   pParser;

     ExprCppTreeParser_atom_return
     (*atom)	(struct ExprCppTreeParser_Ctx_struct * ctx);

     ExprCppTreeParser_notExpr_return
     (*notExpr)	(struct ExprCppTreeParser_Ctx_struct * ctx);

     ExprCppTreeParser_timesExpr_return
     (*timesExpr)	(struct ExprCppTreeParser_Ctx_struct * ctx);

     ExprCppTreeParser_orderExpr_return
     (*orderExpr)	(struct ExprCppTreeParser_Ctx_struct * ctx);

     ExprCppTreeParser_unbalanceExpr_return
     (*unbalanceExpr)	(struct ExprCppTreeParser_Ctx_struct * ctx);

     ExprCppTreeParser_balanceExpr_return
     (*balanceExpr)	(struct ExprCppTreeParser_Ctx_struct * ctx);

     ExprCppTreeParser_bitAndExpr_return
     (*bitAndExpr)	(struct ExprCppTreeParser_Ctx_struct * ctx);

     ExprCppTreeParser_xorExpr_return
     (*xorExpr)	(struct ExprCppTreeParser_Ctx_struct * ctx);

     ExprCppTreeParser_bitOrExpr_return
     (*bitOrExpr)	(struct ExprCppTreeParser_Ctx_struct * ctx);

     ExprCppTreeParser_andExpr_return
     (*andExpr)	(struct ExprCppTreeParser_Ctx_struct * ctx);

     ExprCppTreeParser_orExpr_return
     (*orExpr)	(struct ExprCppTreeParser_Ctx_struct * ctx);

     ExprCppTreeParser_assignExpr_return
     (*assignExpr)	(struct ExprCppTreeParser_Ctx_struct * ctx);

     ExprCppTreeParser_commaExpr_return
     (*commaExpr)	(struct ExprCppTreeParser_Ctx_struct * ctx);

     ExprCppTreeParser_ifcondBaseExpr_return
     (*ifcondBaseExpr)	(struct ExprCppTreeParser_Ctx_struct * ctx);

     ExprCppTreeParser_elifExpr_return
     (*elifExpr)	(struct ExprCppTreeParser_Ctx_struct * ctx);

     ExprCppTreeParser_elseExpr_return
     (*elseExpr)	(struct ExprCppTreeParser_Ctx_struct * ctx);

     ExprCppTreeParser_ifExpr_return
     (*ifExpr)	(struct ExprCppTreeParser_Ctx_struct * ctx);

     ExprCppTreeParser_forExpr_return
     (*forExpr)	(struct ExprCppTreeParser_Ctx_struct * ctx);

     ExprCppTreeParser_whileExpr_return
     (*whileExpr)	(struct ExprCppTreeParser_Ctx_struct * ctx);

     ExprCppTreeParser_defIdExpr_return
     (*defIdExpr)	(struct ExprCppTreeParser_Ctx_struct * ctx);

     ExprCppTreeParser_defExpr_return
     (*defExpr)	(struct ExprCppTreeParser_Ctx_struct * ctx);

     ExprCppTreeParser_stmt_return
     (*stmt)	(struct ExprCppTreeParser_Ctx_struct * ctx);

     ExprCppTreeParser_block_base_return
     (*block_base)	(struct ExprCppTreeParser_Ctx_struct * ctx);

     ExprCppTreeParser_block_return
     (*block)	(struct ExprCppTreeParser_Ctx_struct * ctx);

     ExprCppTreeParser_mainBlock_return
     (*mainBlock)	(struct ExprCppTreeParser_Ctx_struct * ctx);

     ExprCppTreeParser_prog_return
     (*prog)	(struct ExprCppTreeParser_Ctx_struct * ctx);
    // Delegated rules

    const char * (*getGrammarFileName)();
    void            (*reset)  (struct ExprCppTreeParser_Ctx_struct * ctx);
    void	    (*free)   (struct ExprCppTreeParser_Ctx_struct * ctx);
/* @headerFile.members() */
pANTLR3_BASE_TREE_ADAPTOR	adaptor;
pANTLR3_VECTOR_FACTORY		vectors;
/* End @headerFile.members() */
};

// Function protoypes for the constructor functions that external translation units
// such as delegators and delegates may wish to call.
//
ANTLR3_API pExprCppTreeParser ExprCppTreeParserNew         (
pANTLR3_COMMON_TOKEN_STREAM
 instream);
ANTLR3_API pExprCppTreeParser ExprCppTreeParserNewSSD      (
pANTLR3_COMMON_TOKEN_STREAM
 instream, pANTLR3_RECOGNIZER_SHARED_STATE state);

/** Symbolic definitions of all the tokens that the 
parser
 will work with.
 * \{
 *
 * Antlr will define EOF, but we can't use that as it it is too common in
 * in C header files and that would be confusing. There is no way to filter this out at the moment
 * so we just undef it here for now. That isn't the value we get back from C recognizers
 * anyway. We are looking for ANTLR3_TOKEN_EOF.
 */
#ifdef	EOF
#undef	EOF
#endif
#ifdef	Tokens
#undef	Tokens
#endif
#define EOF      -1
#define T__40      40
#define CURLY_BRACE_LEFT      4
#define CURLY_BRACE_RIGHT      5
#define ENDLINE      6
#define ID      7
#define INT      8
#define KW_DEF      9
#define KW_DO      10
#define KW_ELIF      11
#define KW_ELSE      12
#define KW_FOR      13
#define KW_IF      14
#define KW_MAIN      15
#define KW_WHILE      16
#define OPR_AND      17
#define OPR_ASSIGN      18
#define OPR_BIT_AND      19
#define OPR_BIT_OR      20
#define OPR_COMMA      21
#define OPR_DIVISOR      22
#define OPR_EQ      23
#define OPR_GE      24
#define OPR_GT      25
#define OPR_LE      26
#define OPR_LT      27
#define OPR_MINUS      28
#define OPR_MULT      29
#define OPR_NE      30
#define OPR_NOT      31
#define OPR_OR      32
#define OPR_PERCENT      33
#define OPR_PLUS      34
#define OPR_XOR      35
#define PARENTHESES_LEFT      36
#define PARENTHESES_RIGHT      37
#define TOK_BLOCK      38
#define WS      39
#ifdef	EOF
#undef	EOF
#define	EOF	ANTLR3_TOKEN_EOF
#endif

#ifndef TOKENSOURCE
#define TOKENSOURCE(lxr) lxr->pLexer->rec->state->tokSource
#endif

/* End of token definitions for ExprCppTreeParser
 * =============================================================================
 */
/** } */

#ifdef __cplusplus
}
#endif

#endif

/* END - Note:Keep extra line feed to satisfy UNIX systems */
