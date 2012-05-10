#include <iostream>
#include "tinyxml.h"
using namespace std;
int main()
{
    //______________________________________________________________________
    // Read information from xml file.
    
    // define xml file path, as follow , we use relative path,
    // but you can use absolute path also.
    const char* filepath = "phonebookdata.xml";
    TiXmlDocument doc(filepath);
    bool loadOkay = doc.LoadFile();
    // faile to load 'phonebookdata.xml'.
    if (!loadOkay) {	
        printf( "Could not load test file %s. Error='%s'. Exiting.\n", filepath,doc.ErrorDesc() );
        exit( 1 );
    }
    
    // get dom root of 'phonebookdata.xml', here root should be 'phonebook'.
    TiXmlElement* root = doc.RootElement();
    
    printf("_______________________________________\n\n");
    printf("     contacted person information      \n\n");
    // trace every items below root.
    for( TiXmlNode*  item = root->FirstChild( "item" );
			 item;
             item = item->NextSibling( "item" ) ) {
                 printf("_______________________________________\n");
                 
                 // read name.
                 TiXmlNode* child = item->FirstChild();
                 const char* name = child->ToElement()->GetText();
                 if (name) {
                     printf("name:%s\n",name);
                 } else {
                     printf("name:\n");
                 }
                 
                 // read address.
                 child = item->IterateChildren(child);
                 const char* addr = child->ToElement()->GetText();
                 if (addr) {
                     printf("addr:%s\n",addr);
                 } else {
                     printf("addr:\n");
                 }
                 
                 
                 // read telephone no.
                 child = item->IterateChildren(child);
                 const char* tel = child->ToElement()->GetText();
                 if (tel) {
                     printf("tel:%s\n",tel);
                 } else {
                     printf("tel:\n");
                 }
                 
                 // read e-mail.
                 child = item->IterateChildren(child);
                 const char* email = child->ToElement()->GetText();
                 if(email) {
                     printf("email:%s\n",email);
                 } else {
                     printf("email:\n");
                 }
                 
                 printf("\n");
                 
             }
             //______________________________________________________________________
             
             
             //______________________________________________________________________
             // Add information to xml file and save it.
             TiXmlElement* writeRoot = doc.RootElement();
             TiXmlNode* newNode = new TiXmlElement("item");
             
             const TiXmlNode* name4NewNode = new TiXmlElement("name");
             newNode->InsertEndChild(*name4NewNode)->InsertEndChild(TiXmlText("pipi"));
             
             const TiXmlNode* addr4NewNode = new TiXmlElement("addr");
             newNode->InsertEndChild(*addr4NewNode)->InsertEndChild(TiXmlText("Shaanxi Xianyang"));
             
             const TiXmlNode* tel4NewNode = new TiXmlElement("tel");
             newNode->InsertEndChild(*tel4NewNode)->InsertEndChild(TiXmlText("02937310627"));
             
             const TiXmlNode* email4NewNode = new TiXmlElement("email");
             newNode->InsertEndChild(*email4NewNode)->InsertEndChild(TiXmlText("pipi@home.com"));
             
             writeRoot->InsertEndChild(*newNode);
             doc.SaveFile();
             //______________________________________________________________________
             return 0;

}