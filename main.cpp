#include <iostream>
#include <sstream>
#include <iomanip>
#include <regex>

bool isValidRGB(const std::string& rgb) {
    std::regex pattern("^\\s*(\\d{1,3})\\s*,\\s*(\\d{1,3})\\s*,\\s*(\\d{1,3})\\s*$");
    if (!std::regex_match(rgb, pattern))
        return false;
    
    std::istringstream iss(rgb);
    int r, g, b;
    char comma;
    iss >> r >> comma >> g >> comma >> b;

    return (r >= 0 && r <= 255) && (g >= 0 && g <= 255) && (b >= 0 && b <= 255);
}

bool isValidHex(const std::string& hex) {
    std::regex pattern("^\\s*([0-9a-fA-F]{6})\\s*$");
    return std::regex_match(hex, pattern);
}

std::string RGBtoHex(const std::string& rgb) {
    std::istringstream iss(rgb);
    int r, g, b;
    char comma;
    iss >> r >> comma >> g >> comma >> b;

    std::ostringstream oss;
    oss << std::hex << std::setw(2) << std::setfill('0') << r
        << std::setw(2) << std::setfill('0') << g
        << std::setw(2) << std::setfill('0') << b;
    return oss.str();
}

std::string HexToRGB(const std::string& hex) {
    int r, g, b;
    std::istringstream(hex.substr(0, 2)) >> std::hex >> r;
    std::istringstream(hex.substr(2, 2)) >> std::hex >> g;
    std::istringstream(hex.substr(4, 2)) >> std::hex >> b;
    std::ostringstream oss;
    oss << r << "," << g << "," << b;
    return oss.str();
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cout << "Example usage: \n colorswap ff0000 \n colorswap 255,0,0";
        return 1;
    }

    std::string color = argv[1];

    if (isValidRGB(color)) {
        std::string hex = RGBtoHex(color);
        std::cout << hex << std::endl;
    }
    else if (isValidHex(color)) {
        std::string rgb = HexToRGB(color);
        std::cout << rgb << std::endl;
    }
    else {
        std::cout << "Invalid color value\n";
        return 1;
    }

    return 0;
}
