grammar ExprCppTree;

options {
    language = C;
    output = AST;
    ASTLabelType=pANTLR3_BASE_TREE;
}

/* 虚拟标记 ；
 * 注意topens{}定义的位置，
 * 放在@header{}下面会报错，原因未知。。
 */
tokens {
    TOK_BLOCK;
}

@header {
    #include <assert.h>
}

atom: 
    INT | 
    ID | 
    PARENTHESES_LEFT! commaExpr PARENTHESES_RIGHT!;

notExpr:
    (OPR_NOT^)* atom;

timesExpr: 
    notExpr ((OPR_MULT^ | OPR_DIVISOR^ | OPR_PERCENT^) notExpr)*;

orderExpr: 
    timesExpr ((OPR_PLUS^ | OPR_MINUS^) timesExpr)*;

unbalanceExpr: 
    orderExpr ((OPR_LT^ | OPR_LE^ | OPR_GT^ | OPR_GE^) orderExpr)*;

balanceExpr: 
    unbalanceExpr ((OPR_EQ^ | OPR_NE^) unbalanceExpr)*;

bitAndExpr:
    balanceExpr (OPR_BIT_AND balanceExpr)*;

xorExpr: 
    bitAndExpr (OPR_XOR^ bitAndExpr)*;

bitOrExpr:
    xorExpr (OPR_BIT_OR^ xorExpr)*;

andExpr:
    bitOrExpr (OPR_AND^ bitOrExpr)*;

orExpr:
    andExpr (OPR_OR^ andExpr)*;

assignExpr: 
    (ID OPR_ASSIGN^)* orExpr;

/* 运算表达式：逗号表达式 */

commaExpr:
    assignExpr (OPR_COMMA^ assignExpr)*;

/* if-elif-else 语句 <start>*/

ifcondBaseExpr:
    PARENTHESES_LEFT! commaExpr^ PARENTHESES_RIGHT!;


elifExpr:
    KW_ELIF^ ifcondBaseExpr block; 

elseExpr:
    KW_ELSE^ block; 

ifExpr:
    KW_IF^ ifcondBaseExpr block elifExpr* elseExpr?; 

/* if-elif-else 语句 <end>*/

/* for 语句 <start> */

forExpr: 
    KW_FOR^ 
    PARENTHESES_LEFT! 
        commaExpr ';'! commaExpr ';'! commaExpr 
    PARENTHESES_RIGHT!
    block;

/* for 语句 <end> */

/* while 语句 <start> */

whileExpr: 
    KW_WHILE^ 
    PARENTHESES_LEFT! 
        commaExpr
    PARENTHESES_RIGHT!
    block;

/* while 语句 <start> */

/* def 语句 <start> */

defIdExpr: 
    ID^ (OPR_ASSIGN! atom)?;

defExpr: 
    KW_DEF^ defIdExpr (OPR_COMMA! defIdExpr)*;

/* def 语句 <end> */

stmt: 
    commaExpr ENDLINE -> commaExpr  | 
    ifExpr ENDLINE -> ifExpr        | 
    forExpr ENDLINE -> forExpr      | 
    whileExpr ENDLINE -> whileExpr  | 
    defExpr ENDLINE -> defExpr      | 
    ENDLINE -> ;

block_base: 
    (stmt)*;

block: 
    CURLY_BRACE_LEFT block_base CURLY_BRACE_RIGHT -> ^(TOK_BLOCK block_base);

mainBlock: 
    KW_MAIN! PARENTHESES_LEFT! PARENTHESES_RIGHT!  block;

prog: (
    mainBlock {
        pANTLR3_STRING s = $mainBlock.tree->toStringTree($mainBlock.tree);
        assert(s->chars);
        printf("\033[1;32mtree \%s\n\033[0;m", s->chars);
    }
)+;




/* Keywords */

KW_MAIN:    'main';
KW_IF:      'if';
KW_ELIF:    'elif';
KW_ELSE:    'else';
KW_FOR:     'for';
KW_WHILE:   'while';
KW_DO:      'do'; 
KW_DEF:     'def';

/* Operators */

/*18*/ OPR_COMMA: ',';
/*16*/ OPR_ASSIGN: '=';
/*14*/ OPR_OR: '||';
/*13*/ OPR_AND: '&&';
/*12*/ OPR_BIT_OR: '|';
/*11*/ OPR_XOR: '^';
/*10*/ OPR_BIT_AND: '&';
/* 9*/ OPR_EQ: '==';
/* 9*/ OPR_NE: '!=';
/* 8*/ OPR_LT: '<';
/* 8*/ OPR_LE: '<=';
/* 8*/ OPR_GT: '>';
/* 8*/ OPR_GE: '>=';
/* 6*/ OPR_PLUS: '+';
/* 6*/ OPR_MINUS: '-';
/* 5*/ OPR_MULT: '*';
/* 5*/ OPR_DIVISOR: '/';
/* 5*/ OPR_PERCENT: '%';
/* 3*/ OPR_NOT: '!';

PARENTHESES_LEFT: '(';
PARENTHESES_RIGHT: ')';
CURLY_BRACE_LEFT: '{';
CURLY_BRACE_RIGHT: '}';


ID: ('a'..'z'|'A'..'Z')+ ;
INT: '~'? '0'..'9'+ ;

ENDLINE: '\r'? '\n'*;

WS : (' '|'\t')+ {$channel = HIDDEN;};
