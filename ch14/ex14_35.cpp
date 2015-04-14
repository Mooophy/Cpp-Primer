#include <iostream>
#include <string>

class GetInput {
public:
    GetInput(std::istream &i = std::cin) : is(i) { }
    std::string operator()() const {
        std::string str;
        std::getline(is, str);
        return is ? str : std::string();
    }

private:
    std::istream &is;
};

int main()
{
    GetInput getInput;
    std::cout << getInput() << std::endl;
}
