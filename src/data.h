#ifndef DATA_H
#define DATA_H
#include<QString>
#include <QDateTime>
struct Report {
    QString type;      // "Power", "Water", "Internet"
    QString area;      // e.g. "Street 5, Sector F"
    QString message;  // e.g. "No electricity since 3PM"
    int hour, minute, day, month, year;
    QString submittedBy;
};

struct Resource {
    QString item;         // e.g. "UPS"
    QString owner;        // e.g. "Ali"
    QString availability; // e.g. "Until 9 PM"
    bool isAssigned = false;        // true if checked out
    QString assignedTo;             // who took it
    QDateTime dueDateTime;          // when it’s due back
};

struct Request {
    QString request;  // e.g. "Need phone charging"
    QString name;     // e.g. "Hasan"
    QString location; // e.g. "Street 5"
};

struct User {
    QString username;
    QString salt;
    QString hash;

};

struct Announcement {
    QString text;
    QDateTime timestamp;
    QString postedBy;
};

#endif // DATA_H
