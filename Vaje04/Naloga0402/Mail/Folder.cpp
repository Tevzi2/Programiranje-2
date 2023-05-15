#include <Folder.hpp>

std::string messageFolderToString(MessageFolder folder)
{
    const char* folderStringify[] = {
        ENUM_TO_STRING(Inbox),
        ENUM_TO_STRING(Sent),
        ENUM_TO_STRING(Drafts),
        ENUM_TO_STRING(Deleted)
    };

    return std::string(folderStringify[folder]);
}