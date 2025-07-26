#ifndef ENCRYPTION_H
#define ENCRYPTION_H

#include <QByteArray>
#include <QString>

class encryption
{
public:
    encryption();

    /// XOR encrypt/decrypt in place
    void xorCrypt(QByteArray& data, const QByteArray& key);

    /// Encrypt: XOR, then Base64 encode
    QString encryptString(const QString& plain, const char* key) {
        QByteArray buf = plain.toUtf8();
        xorCrypt(buf, QByteArray(key));
        return QString::fromUtf8(buf.toBase64());
    }

    /// Decrypt: Base64 decode, then XOR
    QString decryptString(const QString& cipher, const char* key) {
        QByteArray buf = QByteArray::fromBase64(cipher.toUtf8());
        xorCrypt(buf, QByteArray(key));
        return QString::fromUtf8(buf);
    }
};

#endif // ENCRYPTION_H
