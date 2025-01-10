// jpu crypto helper library
// Copyright 2025 Adam Perkowski.
// Use of this source code is governed by the BSD 3-Clause License.
// See the LICENSE file for details.

#ifndef CRYPTO_HPP
#define CRYPTO_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <openssl/evp.h>

std::string sha512sum(const std::string& input) {
    EVP_MD_CTX* ctx = EVP_MD_CTX_new();
    unsigned char hash[EVP_MAX_MD_SIZE];
    unsigned int length;

    EVP_DigestInit_ex(ctx, EVP_sha512(), NULL);
    EVP_DigestUpdate(ctx, input.c_str(), input.length());
    EVP_DigestFinal_ex(ctx, hash, &length);

    EVP_MD_CTX_free(ctx);

    std::stringstream ss;
    for(unsigned int i = 0; i < length; i++) {
        ss << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(hash[i]);
    }
    
    return ss.str();
}

#endif // CRYPTO_HPP
