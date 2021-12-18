//
// Created by ivan on 17.12.2021.
//
#include <iostream>
#include <random>
#include <cassert>
#include "support.h"

void gen_key(const std::string& message, std::string& key){
    assert (key.empty());

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(0, 1000000);

    for (int i=0; i < message.size(); i++){
        key += (char)(distr(gen));
    }
}

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