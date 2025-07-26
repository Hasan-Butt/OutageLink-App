#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include "data.h"
class fileManager
{
public:
    fileManager();

    void loadReports(Report* reports, int& size, const char* key);

    void saveReports(const Report* arr, int size, const char* key);

    void loadResources(Resource* resources, int& count, const char* key = nullptr);
    void saveResources(const Resource* resources, int count, const char* key = nullptr);

    void loadRequests(Request requests[], int& count);
    void saveRequests(const Request requests[], int count);

    void loadAnnouncements(Announcement announcements[], int& count);
    void saveAnnouncements(const Announcement announcements[], int count);
};

#endif // FILEMANAGER_H
