#pragma once

#include <Message.hpp>
#include <User.hpp>
#include <vector>
#include <Folder.hpp>

class Mailbox {
    public:
        Mailbox();

        [[nodiscard]] std::vector<Message> getMessages() const;

        void addMessage(const Message& message);

        [[nodiscard]] std::string toString() const;

        [[nodiscard]] std::vector<Message> getByFolderType(MessageFolder folder) const;

    private:
        std::vector<Message> messages;
};
