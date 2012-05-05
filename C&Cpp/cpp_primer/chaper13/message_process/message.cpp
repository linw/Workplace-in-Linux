/*
 * =====================================================================================
 *
 *       Filename:    message.cpp
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012年3月20日22:15:50
 *       Compiler:    gcc
 *       Description: 
 *
 * =====================================================================================
 */
#include "message.h"
#include <iostream>
#include <string>
using namespace std;

// 复制构造函数
Message::Message(const Message& _m):
            contents(_m.contents), folders(_m.folders)
{
    put_Msg_in_Folders(folders);
};

// operator =
Message& Message::operator=(const Message& _m)            
{
    if(&_m != this){
        remove_Msg_from_Folders(); // update existing Folders
        contents = _m.contents;
        folders = _m.folders;
        put_Msg_in_Folders(_m.folders);
    }
    return *this;
};

// 析构函数
virtual Message::~Message(){
    remove_Msg_from_Folders();
};

void Message::save(Folder& _f){
    _f.add_Msg(*this);
    folders.insert(_f);    
};

void Message::remove(Folder& _f){
    _f.remove_Msg(*this);   
    folders.erase(_f);
    
};

void Message::put_Msg_in_Folders(const std::set<Folder*>& _fs){
    for(set<Folder*>::iterator iter = _fs.begin();
        iter != _fs.end(); iter ++){
        iter->add_Msg(*this);        
    }
}

void Message::remove_Msg_from_Folders(){
    for(set<Folder*>::iterator iter = folders.begin();
        iter != folders.end(); iter ++){
        iter->remove(*iter);
    }
}

