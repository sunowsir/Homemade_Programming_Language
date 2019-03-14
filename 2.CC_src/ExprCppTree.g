grammar ExprCppTree;

options {
    language = C;
    output = AST;
    ASTLabelType=pANTLR3_BASE_TREE;
}

@header {
    #include <assert.h>
}

atom: 
    INT | 
    ID | 
    PARENTHESES_LEFT! commaExpr PARENTHESES_RIGHT!
    ;

multExpr: 
    atom (TIMES^ atom)*;

expr: 
    multExpr ((PLUS^ | MINUS^) multExpr)*;

assignExpr: 
    (ID ASSIGN^)* expr;

commaExpr:
    assignExpr (COMMA^ assignExpr)*;

stmt: 
    commaExpr ENDLINE -> commaExpr | 
    ENDLINE -> | 
    block
    ;

block_base: 
    (stmt)*;

block: 
    CURLY_BRACE_LEFT block_base CURLY_BRACE_RIGHT ENDBLOCK -> ^(BLOCK block_base);

prog: (
    block {
        pANTLR3_STRING s = $block.tree->toStringTree($block.tree);
        assert(s->chars);
        printf("tree \%s\n", s->chars);
    }
)+;


PARENTHESES_LEFT: '(';
PARENTHESES_RIGHT: ')';
CURLY_BRACE_LEFT: '{';
CURLY_BRACE_RIGHT: '}';
BLOCK: '{}';

COMMA: ',';
TIMES: '*';
ASSIGN: '=';
PLUS: '+';
MINUS: '-';

ID: ('a'..'z'|'A'..'Z')+ ;
INT: '~'? '0'..'9'+ ;

ENDLINE: ';'+ '\n';
ENDBLOCK: '\n';

WS : (' '|'\t')+ {$channel = HIDDEN;};
