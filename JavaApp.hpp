/*
    JavaApp.hpp

    Application built on JavaVisitor.
*/

#ifndef INCLUDED_JAVAAPP_HPP
#define INCLUDED_JAVAAPP_HPP

#include <iostream>
#include "JavaVisitorBlock.h"

class  JavaApp : public JavaVisitor {
public:

    virtual antlrcpp::Any visitMain(JavaParser::MainContext *context) override {

        std::cout << context->getStart()->toString() << '\n';
        std::cout << context->getStop()->toString() << '\n';

        auto a = context->start->getStartIndex();
        auto b = context->stop->getStopIndex();
        antlr4::misc::Interval interval(a, b);

        std::cout << context->start->getInputStream()->getText(interval) << '\n';


        visit(context->statement(0));

        return antlrcpp::Any(); 
    }

    virtual antlrcpp::Any visitStatement(JavaParser::StatementContext *context) override {

        fprintf(stderr, "DEBUG:  %s %s %d \n", __FILE__,  __FUNCTION__, __LINE__);

        return antlrcpp::Any(); 
    }

    virtual antlrcpp::Any visitFunction(JavaParser::FunctionContext *context) override {

        fprintf(stderr, "DEBUG:  %s %s %d \n", __FILE__,  __FUNCTION__, __LINE__);

        return antlrcpp::Any(); 
    }
};

#endif
