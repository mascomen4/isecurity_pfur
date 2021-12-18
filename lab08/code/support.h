//
// Created by ivan on 17.12.2021.
//

#ifndef CODE_SUPPORT_H
#define CODE_SUPPORT_H

void gen_key(const std::string& message, std::string& key);

std::string encrypt(const std::string& key, const std::string& open_text);

std::string decipher(const std::string& key, const std::string& encrypted);

#endif //CODE_SUPPORT_H
