// jpu crypto helper library
// Copyright 2025 Adam Perkowski.
// Use of this source code is governed by the BSD 3-Clause License.
// See the LICENSE file for details.

#ifndef CRYPTO_H
#define CRYPTO_H

#include <stdio.h>
#include <string.h>
#include <openssl/evp.h>

__jule_Str sha512sum(const __jule_Str input) {
    EVP_MD_CTX* ctx = EVP_MD_CTX_new();
    unsigned char hash[EVP_MAX_MD_SIZE];
    unsigned int length;

    EVP_DigestInit_ex(ctx, EVP_sha512(), NULL);
    EVP_DigestUpdate(ctx, input, input.len());
    EVP_DigestFinal_ex(ctx, hash, &length);

    EVP_MD_CTX_free(ctx);

    char* output = (char*)malloc((length * 2) + 1);
    if (output == NULL) {
        return __jule_Str();
    }

    for (unsigned int i = 0; i < length; i++) {
        sprintf(output + (i * 2), "%02x", hash[i]);
    }

    return output;
}

#endif // CRYPTO_H
