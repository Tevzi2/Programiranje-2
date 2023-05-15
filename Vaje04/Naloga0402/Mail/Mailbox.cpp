//
// Created by Tevz on 18/03/2023.
//

#include <Mailbox.hpp>

Mailbox::Mailbox()
{
    ;
}

[[nodiscard]] std::vector<Message> Mailbox::getMessages() const
{
    return messages;
}

void Mailbox::addMessage(const Message& message)
{
    messages.push_back(message);
}

[[nodiscard]] std::string Mailbox::toString() const
{
    std::string out =
        "Messages:\n";

    for(const auto& message : messages)
    {
        out += message.toString() + ",\n";
    }

    return out;
}

[[nodiscard]] std::vector<Message> Mailbox::getByFolderType(MessageFolder folder) const
{
    std::vector<Message> foundMessages;

    for(const auto& message : messages)
    {
        if(folder == message.getFolder())
            foundMessages.push_back(message);
    }

    return foundMessages;
}