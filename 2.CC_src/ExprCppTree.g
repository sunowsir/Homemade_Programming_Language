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
    TOK_IF;
    TOK_ELIF;
    TOK_ELSE;
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

commaExpr:
    assignExpr (OPR_COMMA^ assignExpr)*;

stmt: 
    commaExpr ENDLINE -> commaExpr | 
    block | 
    ENTER -> |
    ENDLINE -> ;

block_base: 
    (stmt)*;

block: 
    CURLY_BRACE_LEFT block_base CURLY_BRACE_RIGHT ENDLINE -> ^(TOK_BLOCK block_base);

mainBlock: 
    KW_MAIN! block;

prog: (
    mainBlock {
        pANTLR3_STRING s = $mainBlock.tree->toStringTree($mainBlock.tree);
        assert(s->chars);
        printf("\033[1;32mtree \%s\n\033[0;m", s->chars);
    }
)+;





/* Keywords */

KW_MAIN: 'main';
KW_IF: 'if';
KW_ELIF: 'elif';
KW_ELSE: 'else';


/* Operators */

/*18*/OPR_COMMA: ',';
/*16*/OPR_ASSIGN: '=';
/*14*/OPR_OR: '||';
/*13*/OPR_AND: '&&';
/*12*/OPR_BIT_OR: '|';
/*11*/OPR_XOR: '^';
/*10*/OPR_BIT_AND: '&';
/* 9*/OPR_EQ: '==';
/* 9*/OPR_NE: '!=';
/* 8*/OPR_LT: '<';
/* 8*/OPR_LE: '<=';
/* 8*/OPR_GT: '>';
/* 8*/OPR_GE: '>=';
/* 6*/OPR_PLUS: '+';
/* 6*/OPR_MINUS: '-';
/* 5*/OPR_MULT: '*';
/* 5*/OPR_DIVISOR: '/';
/* 5*/OPR_PERCENT: '%';
/* 3*/OPR_NOT: '!';

PARENTHESES_LEFT: '(';
PARENTHESES_RIGHT: ')';
CURLY_BRACE_LEFT: '{';
CURLY_BRACE_RIGHT: '}';


ID: ('a'..'z'|'A'..'Z')+ ;
INT: '~'? '0'..'9'+ ;

ENDLINE: '\r'? ';'+ '\n';
ENTER: '\n';

WS : (' '|'\t')+ {$channel = HIDDEN;};
