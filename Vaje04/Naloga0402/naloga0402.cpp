#include <iostream>
#include <Mailbox.hpp>
#include <Message.hpp>
#include <User.hpp>

int main()
{
    User john("John", "Doe", "john.doe@mail.com");
    User jane("Jane", "Doe", "jane.doe@mail.com");
    User becky("Becky", "Smith", "becky.smith2004@google.mail.com");

    Mailbox mailbox;

    mailbox.addMessage(Message::newMessage(&jane, &john, "Hello", "Welcome to the mail service!", Inbox));
    mailbox.addMessage(Message::newMessage(&becky, &john, "Hi John!", "I'm so glad you've got a mail!", Inbox));

    Message response = Message::newMessage(&john, &jane, "Thanks!", "Thanks for your welcome messages", Sent);
    response.addReciever(&becky);
    mailbox.addMessage(response);

    std::cout << mailbox.toString() << std::endl;

    std::cout << "Messages in Inbox: " << std::endl;
    auto inboxMessages = mailbox.getByFolderType(Inbox);
    for(const auto& message : inboxMessages)
    {
        std::cout << message.toString() << std::endl;
    }
}