#pragma once

class RealFunction{
    public:
        virtual ~RealFunction() {} 
        virtual double evaluate ( double x ) = 0;

};
