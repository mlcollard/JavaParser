/*
    java.cpp

    A Java parser
*/

#include <iostream>
#include <fstream>
#include "JavaLexer.h"
#include "JavaParser.h"

int main(int argc, char* argv[]) {

    // setup input
    std::ifstream file(argv[1]);
    antlr4::ANTLRInputStream input(file);

    // setup lexer
    JavaLexer lexer(&input);
    antlr4::CommonTokenStream tokens(&lexer);

    JavaParser parser(&tokens);
    parser.setTrace(true);
    try {
        antlr4::tree::ParseTree* tree = parser.main();
        // std::cout << tree->toStringTree() << '\n';
        return 0;
    } catch (std::invalid_argument &e) {
        std::cout << e.what() << '\n';
        return 1;
    }

    return 0;
}
