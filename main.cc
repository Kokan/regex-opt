#include <iostream>

#include "libregex.hh"

int main(int argc, const char* const* argv)
{
    std::string regex;
    if(argc != 2)
    {
        std::cout << "Please insert your regex> ";
        std::cin >> regex;
    }
    else
    {
        std::string regex = argv[1];
    }

    try {

        unsigned pos=0;

        regexopt_choices tree = RegexOptParse(regex, pos);

        DumpRegexOptTree(std::cout, tree);
    }
    catch(const char *s)
    {
        std::cout << "Error: " << s << std::endl;
        return -1;
    }
    catch(const std::string& s)
    {
        std::cout << "Error: " << s.c_str() << std::endl;
        return -1;
    }
    return 0;
}
