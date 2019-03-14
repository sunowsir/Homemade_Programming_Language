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
    '('! commaExpr ')'!
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
    commaExpr NEWLINE -> commaExpr | 
    NEWLINE -> 
    ;

prog: (
    stmt {
        pANTLR3_STRING s = $stmt.tree->toStringTree($stmt.tree);
        assert(s->chars);
        printf("tree \%s\n", s->chars);
    }
)+;



COMMA: ',';
TIMES: '*';
ASSIGN: '=';
PLUS: '+';
MINUS: '-';
ID: ('a'..'z'|'A'..'Z')+ ;
INT: '~'? '0'..'9'+ ;
NEWLINE: '\r'? ';'+ '\n';
WS : (' '|'\t')+ {$channel = HIDDEN;};
