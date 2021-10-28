grammar Java;

options {
    language=Cpp;
    tokenVocab=JavaLexer;
}

main : (statement)* ;

statement : if_stmt | else_stmt | while_stmt | return_stmt | block | expr_stmt | empty_stmt |
            continue_stmt | break_stmt | goto_stmt | function ;

function_header : (STATIC | CONST)* (name)+ LPAREN (expr | COMMA)* RPAREN ;

function : function_header block ;

goto_stmt : GOTO (NAME | CASE (expr)*)? ;

return_stmt : RETURN (expr)* stmt_end ;

continue_stmt : CONTINUE (expr)* stmt_end ;

break_stmt : BREAK (expr)* stmt_end ;

empty_stmt : stmt_end ;

stmt_end : SEMICOLON ;

while_stmt : WHILE LPAREN (expr)* RPAREN statement ;

if_stmt : IF LPAREN (expr)* RPAREN statement ;

else_stmt : ELSE statement ;

expr_stmt : expr stmt_end ;

name : NAME ;

call : name LPAREN (expr | COMMA)? RPAREN ;

block : LCURLY (statement)* RCURLY ;

expr : (name | NUMBER | STRING | operators | call | LPAREN (expr)* RPAREN)+ ;

operators : OPERATORS | COMMA | NEW ;







