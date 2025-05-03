#ifndef MESSAGE
#define MESSAGE

#include<iostream>
#include<string>
#include<ctime>

class Message
{
    private:
    std::string sender;
    std::string receiver;
    std::string content;
    std::time_t timestamp;

    public:
    Message(std::string s, std::string r, std::string c)
    : sender(s), receiver(r), content(c)
    {
        timestamp=time(nullptr);
    }

    Message(std::string s, std::string r, std::string c, std::time_t t)
    : sender(s), receiver(r), content(c), timestamp(t){}

    std::string getSender() const
    {
        return sender;
    }

    std::string getReceiver() const
    {
        return receiver;
    }

    std::string getContent() const
    {
        return content;
    }

    std::time_t getTimestamp() const
    {
        return timestamp;
    }

};

#endif
