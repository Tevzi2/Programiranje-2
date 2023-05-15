#pragma once

#include <User.hpp>
#include <DateTime.hpp>
#include <string>
#include <algorithm>
#include <Folder.hpp>
#include <Priority.hpp>

class Message {
    public:
        Message(User* sender, User* receiver, const DateTime& received,
            const std::string& title, const std::string& content, Priority priority, MessageFolder folder);

        [[nodiscard]] static Message newMessage(User* sender, User* receiver, const std::string& title, const std::string& content, MessageFolder folder, Priority priority = Normal);

        void setTitle(const std::string& title);

        void setContent(const std::string& content);

        void setPriority(Priority priority);

        void setFolder(MessageFolder folder);

        [[nodiscard]] User* getSender() const;

        [[nodiscard]] std::vector<User*> getReceivers() const;

        [[nodiscard]] std::string getTitle() const;

        [[nodiscard]] std::string getContent() const;

        [[nodiscard]] Priority getPriority() const;

        [[nodiscard]] MessageFolder getFolder() const;

        bool addReciever(User* newReceiver);

        [[nodiscard]] std::string toString() const;

    private:
        User* sender;
        std::vector<User*> receivers;
        const DateTime received;
        std::string title;
        std::string content;
        Priority priority;
        MessageFolder folder;
};
