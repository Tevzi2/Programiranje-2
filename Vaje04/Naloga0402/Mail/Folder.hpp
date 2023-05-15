#pragma once

#include <string>

#ifndef ENUM_TO_STRING
#define ENUM_TO_STRING(e) #e
#endif

enum MessageFolder
{
    Inbox,
    Sent,
    Drafts,
    Deleted
};

std::string messageFolderToString(MessageFolder folder);