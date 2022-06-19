#include <iostream>
#include <vector>

void CheckBinNumber(int *value, int *size);
int BinOn(int *value,int *size);

int main() {
    int number = 0;
    std::cout << "Give me number, that you want to check: ";
    std::cin >> number;
    int bitSizeValue = sizeof(number) *  8;

    std::cout << "Number: " << number << " is : ";
    CheckBinNumber(&number, &bitSizeValue);
    std::cout << "It has " << BinOn(&number, &bitSizeValue) << " bits ON" << std::endl;



    return 0;
}

void CheckBinNumber(int *value, int *size){
    int mask = 1;
    std::vector<std::string>bits;

    for (int i = 0; i < *size; ++i) {
        if((*value & mask) == mask){
            bits.emplace_back("1");
        }
        else{
            bits.emplace_back("0");
        }
        mask <<=1;
    }

    int count = 0;
    std::reverse(bits.begin(), bits.end());
    for (auto i :  bits) {
        std::cout << i;
        count++;
        if(count == 4) {
            std::cout << " ";
            count = 0;
        }
    }
    std::cout << std::endl;

}

int BinOn(int *value, int *size){
    int mask = 1;
    int suma = 0;
    for (int i = 0; i < *size; ++i) {
        if((mask & *value) == mask){
            suma +=1;
        }
        mask <<= 1;
    }
    return suma;
}