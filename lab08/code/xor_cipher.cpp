//
// Created by ivan on 17.12.2021.
//

#include <iostream>
#include <string>
#include <vector>
#include "support.h"

// Function that takes a string and translates it to the sequence of numbers
std::vector<int> string_to_numbers(const std::string& msg){
    setlocale (LC_ALL, "rus");

    std::vector<int> seq;

    std::cout << "Msg length: " << msg.length() << std::endl;

    for (wchar_t symbol : msg){
        // Since it's Russian, we have to add static_cast.
//        std::cout << static_cast<unsigned char> (symbol) << " ";
        std::wcout << symbol << " ";
        seq.push_back( (int)(static_cast<unsigned int> (static_cast<unsigned char> (symbol))) );
    }
    std::cout << std::endl;

    return seq;
}


// Function that takes a HEX sequence and translates it to the numbers
std::vector<int> hexseq_to_numbers(const std::vector<std::string>& hex_seq){
    setlocale (LC_ALL, "rus");

    std::vector<int> seq;

    seq.reserve(hex_seq.size());
    for (const std::string& hex : hex_seq) {
            seq.push_back( stoi(hex, nullptr, 16) );
        }

    return seq;
}


// Function that takes 2 seqs of numbers and performs XOR.
std::vector<int> perform_xor(const std::vector<int>& lh, const std::vector<int>& rh){
    std::vector<int> seq;

    seq.reserve(lh.size());
    for ( int i = 0; i < lh.size(); i++ ){
            seq.push_back(lh[i] xor rh[i]);
        }

    return seq;
}


// Function that takes a seq of numbers and makes it to the complete string
std::string seq_to_string(const std::vector<int>& seq){
    setlocale (LC_ALL, "rus");

    std::string res;

    for (const int& i : seq) {
        res += (char)static_cast<unsigned char> (i);

    }

    return res;
}


std::string retrieve_msg(const std::vector<int>& encrypted1, const std::vector<int>& encrypted2,
                        const std::vector<int>& msg1_seq){
    auto c1_xor_c2 = perform_xor(encrypted1, encrypted2);
    auto deciphered_msg = perform_xor(c1_xor_c2, msg1_seq);
    std::string msg2 = seq_to_string(deciphered_msg);
    return msg2;
}

int main()
{
    // We need to use it to change char conversions to Russian
    std::setlocale (LC_ALL, "Russian");

    std::cout << "Encrypting program... " << std::endl;

//    wchar_t msg2_char[] = L"ВСеверныйфилиалБанка";
//    wchar_t msg_char[] = L"НаВашисходящийот1204";
//
//    for (auto a : msg_char){
//        std::wcout << a << " ";
//    }

    std::string msg = "НаВашисходящийот1204";
    std::cout << msg << std::endl;
    std::string msg2 = "ВСеверныйфилиалБанка";
    std::vector<std::string> key = {"05", "0C", "17", "7F", "0E", "4E", "37", "D2", "94", "10", "09", "2E", "22", "57", "FF", "C8", "0B", "B2", "70", "54"};

    auto msg_seq = string_to_numbers(msg);
    auto msg2_seq = string_to_numbers(msg2);
    auto key_seq = hexseq_to_numbers(key);

//    for (const auto& el : key_seq) {
//        std::cout << el << std::endl;
//    }

    // This is encrypted now
    auto encrypted = perform_xor(msg_seq, key_seq);
    auto encrypted2 = perform_xor(msg2_seq, key_seq);

//    for (const auto& el : encrypted) {
//        std::cout << el << std::endl;
//    }

    // This is deciphered now
    auto org_seq = perform_xor(encrypted, key_seq);

    std::string retrieved_msg2 = retrieve_msg(encrypted, encrypted2, msg_seq);
    std::cout << "Retrieved msg2 without key: " << retrieved_msg2 << std::endl;

//    for (const auto& el : org_seq) {
//        std::cout << el << std::endl;
//    }

    std::string org_msg = seq_to_string(org_seq);

    std::cout << "Символы ключа: " << seq_to_string(key_seq) << std::endl;
    std::cout << "Зашифрованное сообщение 1: " << seq_to_string(encrypted) << std::endl;
    std::cout << "Расшифрованное сообщение 1 с помощью ключа: "  << org_msg << std::endl;
    return 0;
}
