/*
 * =====================================================================================
 *
 *       Filename:    testTinyxml.cpp
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012年07月09日 16时52分04秒
 *       Compiler:    gcc
 *       Description: 
 *
 * =====================================================================================
 */
#include "tinyxml.h"

int main()
{
  TiXmlDocument* doc = new TiXmlDocument();
  TiXmlElement* root = new TiXmlElement("");
  doc->LinkEndChild(root);
  root->SetValue("Root");
  doc->SaveFile("./export.xml");
  delete doc;
  return 0;
}
