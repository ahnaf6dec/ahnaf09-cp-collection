#include <iostream>
#include <string>

char getMEX(const std::string& s) {
    uint32_t m = 0;
    for (char c : s) if (c >= 'a' && c <= 'z') m |= (1U << (c - 'a'));
    return (~m & 0x3FFFFFF) ? 'a' + __builtin_ctz(~m & 0x3FFFFFF) : '\0';
}

int main() {
    std::cout << getMEX("bcdefghijklmnopqrstuvwxyz") << "\n";
}
