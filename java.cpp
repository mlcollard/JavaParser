/*
    java.cpp

    A Java parser
*/

#include <iostream>
#include <fstream>
#include "JavaLexer.h"
#include "JavaParser.h"
#include "JavaApp.hpp"

int main(int argc, char* argv[]) {

    // setup input
    std::ifstream file(argv[1]);
    antlr4::ANTLRInputStream input(file);

    // setup lexer
    JavaLexer lexer(&input);
    antlr4::CommonTokenStream tokens(&lexer);

    JavaParser parser(&tokens);

    // tree pattern
    auto tree = parser.main();
    std::string treePattern = "<name>";
    try {
        auto p = parser.compileParseTreePattern(treePattern, JavaParser::RuleFunction);
        return 0;
    } catch (std::invalid_argument &e) {
        std::cout << e.what() << '\n';
        return 1;
    } catch (const char* msg) {
        std::cout << msg << '\n';
    }
    // auto matches = p.findAll(tree, xpath);

    // XPath
    // antlr4::tree::xpath::XPath path(&parser, "//name");
    // auto results = path.evaluate(parser.main());
    // for (const auto result : results) {
    //     std::cout << result->getText() << '\n';

    //     std::cout << "PARENT: " << result->parent->getText() << '\n';

    //     for (const auto child : result->children) {

    //         std::cout << "CHILD: " << child->getText() << '\n';
    //     }
    // }

    // visitor
    // JavaApp visitor;
    // visitor.visit(parser.main());

    // parser.setTrace(true);
    // try {
    //     antlr4::tree::ParseTree* tree = parser.main();
    //     // std::cout << tree->toStringTree() << '\n';
    //     return 0;
    // } catch (std::invalid_argument &e) {
    //     std::cout << e.what() << '\n';
    //     return 1;
    // }

    return 0;
}
