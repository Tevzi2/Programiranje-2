//
// Created by Tevz on 18/03/2023.
//

#include <Message.hpp>

Message::Message(User* sender, User* receiver, const DateTime& received,
const std::string& title, const std::string& content, Priority priority, MessageFolder folder)
    : sender(sender), received(received), title(title), content(content), priority(priority), folder(folder)
{
    receivers.push_back(receiver);
}

[[nodiscard]] Message Message::newMessage(User* sender, User* receiver, const std::string& title, const std::string& content, MessageFolder folder, Priority priority)
{
    DateTime received({12, 10, 2016}, Time::parse("00:00:00"));

    return Message(sender, receiver, received, title, content, priority, folder);
}

void Message::setTitle(const std::string& title)
{
    this->title = title;
}

void Message::setContent(const std::string& content)
{
    this->content = content;
}

void Message::setPriority(Priority priority)
{
    priority = priority;
}

void Message::setFolder(MessageFolder folder)
{
    this->folder = folder;
}

[[nodiscard]] User* Message::getSender() const
{
    return sender;
}

[[nodiscard]] std::vector<User*> Message::getReceivers() const
{
    return receivers;
}

[[nodiscard]] std::string Message::getTitle() const
{
    return title;
}

[[nodiscard]] std::string Message::getContent() const
{
    return content;
}

[[nodiscard]] Priority Message::getPriority() const
{
    return priority;
}

[[nodiscard]] MessageFolder Message::getFolder() const
{
    return folder;
}

bool Message::addReciever(User* newReceiver)
{
    if(std::find(receivers.begin(), receivers.end(), newReceiver) == receivers.end())
    {
        receivers.push_back(newReceiver);
        return true;
    }

    return false;
}

[[nodiscard]] std::string Message::toString() const
{
    std::string out =
        "Sender: " +
        sender->toString() +
        "\n| Receivers:\n";

    for(const auto& receiver : receivers)
        out += receiver->toString() + ",\n";

    out +=
        "| Title: " +
        title +
        "\n| Content: " +
        content +
        "\n| Time received: " +
        received.toString() +
        "\n| Priority: " +
        priorityToString(priority) +
        "\n| Folder: " +
        messageFolderToString(folder);

    return out;
}
