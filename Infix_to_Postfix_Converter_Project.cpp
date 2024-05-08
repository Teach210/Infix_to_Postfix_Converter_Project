#include <iostream>
#include "converter.h"

int main()
{
    InfixToPostfixConverter converter;
    std::string expressions[] = {
        "A + B - C",
        "(A + B) * C",
        "(A + B) * (C - D)",
        "A + ((B + C) * (E - F) - G) / (H - I)",
        "A + B * (C + D) - E / F * G + H"
    };

    for (const std::string& infix : expressions) {
        converter.Convert(infix);
        std::cout << "Infix Expression: " << infix << ";\n";
        std::cout << "Postfix Expression: " << converter.GetPostfixExpression() << "\n\n";
    }

    return 0;
}