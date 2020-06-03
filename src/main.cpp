#include <iostream>
#include <string>
#include <vector>

//using namespace std;

constexpr int x = 1;

namespace {
    const int x = 2;
    namespace ns1 { int x = 3; }
}

namespace ns2 { int value() { return 4; } }

namespace ns3 {
    const double x = 5.0;
    double value() { return 2 * x; }
}

namespace ns4 {
    double value() { return 6; }
}

inline namespace ns5 {
    double value() { return 7; }
}

int main() {
    const int x{8};

    {
        const int x = x; // undefined

        std::cout << "x = " << x << std::endl;
        std::cout << "::x = " << ::x << std::endl; 
        std::cout << "::ns1::x = " << ::ns1::x << std::endl; // "::" is optional

        std::cout << "ns2::value = " << ns2::value() << std::endl;
        std::cout << "ns3::value = " << ns3::value() << std::endl;
        std::cout << "ns3::x = " << ns3::x << std::endl;
        std::cout << "???::value = " << value() << std::endl; // will be taken from inline namespace
    }

    typedef std::vector<int> VecT;
    using VecA = std::vector<int>;

    const VecT vecT(5, 20);

    const std::initializer_list<int> initList{100, 200, 300, 400, 500};
    const VecA vecA{std::move(initList)};

    std::cout << "vecT: ";
    for (const auto& item : vecT) {
        std::cout << item << ", ";
    }
    std::cout << std::endl;


    std::cout << "vecA: ";
    for (const auto& item : vecA) {
        std::cout << item << ", ";
    }
    std::cout << std::endl;

    return 0;
}
