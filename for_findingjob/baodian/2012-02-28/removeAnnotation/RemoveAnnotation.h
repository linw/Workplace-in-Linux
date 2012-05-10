#ifndef _REMOVE_ANNOTATION_H
#define _REMOVE_ANNOTATION_H
#include <iostream>
#include <string.h>
#include <list.h>

using namespace std;
/* �ó�������ȥ����������е�ע�����
 *
 */
class RemoveAnnotation{

//����ʵ�����õ���ģʽ
private:
    static RemoveAnnotation * instance;
    RemoveAnnotation(const char* xmlFilePath);
public:
    static RemoveAnnotation* getInstance();

//���ñ���
private:
    string singleline_annot_tag;    //����ע�ͷ���
    string multiline_annot_tag_l;   //����ע�ͷ��ţ���
    string multiline_annot_tag_r;   //����ע�ͷ��ţ��ң�
    list<string> quotation_marks;   //�����б�,������������пɱ����Ե�ע�ͱ��

//����˽�к������ڰ�װ����
private:
    /*
     * ���ڴ�����ע��
     * line ����һ������
     * return �����Ľ��(string)
     */
    string parseSingleLineAnnot(const string& line);   
    /*
     * ���ڴ��������ע��
     * line ����һ������
     * return �����Ľ��(string)
     */
    string parseMutilLineAnnot();
};
#endif