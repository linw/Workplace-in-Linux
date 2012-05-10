#ifndef _REMOVE_ANNOTATION_H
#define _REMOVE_ANNOTATION_H
#include <iostream>
#include <string.h>
#include <list.h>

using namespace std;
/* 该程序用于去除程序代码中的注释语句
 *
 */
class RemoveAnnotation{

//程序实现利用单例模式
private:
    static RemoveAnnotation * instance;
    RemoveAnnotation(const char* xmlFilePath);
public:
    static RemoveAnnotation* getInstance();

//设置变量
private:
    string singleline_annot_tag;    //单行注释符号
    string multiline_annot_tag_l;   //多行注释符号（左）
    string multiline_annot_tag_r;   //多行注释符号（右）
    list<string> quotation_marks;   //引号列表,保存程序中所有可被忽略的注释标号

//设置私有函数用于包装方法
private:
    /*
     * 用于处理单行注释
     * line 读入一行数据
     * return 处理后的结果(string)
     */
    string parseSingleLineAnnot(const string& line);   
    /*
     * 用于处理多行行注释
     * line 读入一行数据
     * return 处理后的结果(string)
     */
    string parseMutilLineAnnot();
};
#endif