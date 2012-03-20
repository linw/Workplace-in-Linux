/*
 * =====================================================================================
 *
 *       Filename:    message.h
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012年3月20日21:47:35
 *       Compiler:    gcc
 *       Description: 
 *
 * =====================================================================================
 */
#ifndef _CHAPER13_MESSAGE_H
#define _CHAPER13_MESSAGE_H


#include <iostream>
#include <string>
using namespace std;

class Message
{
public:
    // folders is initialized to the empty set automatically
    Message(const string& str = ""): contents(str) { }

    // copy control: we must manage pointers to this Message
    // from the Folders pointed to by folders
    Message(const Message&);
    Message& operator=(const Message&);
    virtual ~Message();
    // add/remove this Message from specified Folder's set of messages
    void save(Folder&);
    void remove(Folder&);
private:
    string contents;    // actual message text
    set<Folder*> folders;   // Folders that have this Message

    void put_Msg_in_Folders(const std::set<Folder*>&);
    void remove_Msg_from_Folders();
};
#endif
