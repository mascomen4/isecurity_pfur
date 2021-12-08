#include <iostream>
#include <string>
#include <random>
#include <cassert>

std::string encrypt(const std::string& key, const std::string& open_text){
    std::string encrypted;

    encrypted = "";

    for (int i=0; i < key.length(); i++){
        encrypted += open_text[i] ^ key[i];
    }

    return encrypted;
}

std::string decipher(const std::string& key, const std::string& encrypted){
    std::string open_text;
    open_text = "";

    for (int i=0; i < key.length(); i++){
        open_text += key[i] ^ encrypted[i];
    }

    return open_text;
}


void gen_key(const std::string& message, std::string& key){
    assert (key.empty());

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(0, 1000000);

    for (int i=0; i < message.size(); i++){
        key += (char)(distr(gen));
    }
}


int main() {
    std::string key = "";
    std::string message = "Штирлиц - Вы Герой!!";
    std::cout << message << std::endl;

    gen_key(message, key);

    std::string encr = encrypt(key, message);
    std::cout << encr << std::endl;

    auto opened = decipher(key, encr);
    std::cout << opened << std::endl;

// 05 0C 17 7F 0E 4E 37 D2 94 10 09 2E 22 55 F4 D3 07 BB BC 54
//    std::string key2 = "";
//    auto opened2 = decipher(key2, encr);
//    std::cout << opened2 << std::endl;

    return 0;
}
