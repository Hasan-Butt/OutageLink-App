#include "encryption.h"

encryption::encryption() {}

void encryption::xorCrypt(QByteArray& data, const QByteArray& key) {
    int len = data.size();
    int klen = key.size();
    for (int i = 0; i < len; ++i) {
        data[i] = data[i] ^ key[i % klen];
    }
}
