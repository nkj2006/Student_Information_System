//
// Created by Mr.N on 2023/8/3.
//

#ifndef STU_INFO_ARRY_MAIN_H
#define STU_INFO_ARRY_MAIN_H

#include <iostream>
#include <fstream>
#include <cstring>

struct Student {
    int id;             //ѧ��
    char name[10];      //����
    char gender[5];     //�Ա�
    int age;            //����
    int score_C;        //C���Գɼ�
    int score_math;     //��ѧ�ɼ�
    int score_english;  //Ӣ��ɼ�
    char tel[12];       //�绰
};
typedef struct Student stu;

/*����ڵ�*/
struct Node {
    stu data;
    struct Node *next;
};
typedef struct Node node;

node *init_LinkList();          //��ʼ������������ͷ
node *list = init_LinkList();   //��ʼ������list

int g_count = 0;                //��ʾ����;

void show_menu();                   //�˵�����
void user_input();                  //�û�����
void help();                        //��������
void add(node *pNode, stu value);   //�����Ϣ
void search_info(node *pNode, int pos);         //������Ϣ��ͨ��ID����
void show_stu_info(node *pNode);                //��ʾ��Ϣ
void delete_stuInfo(node *pNode, int target);   //ɾ��ѧ����Ϣ
void save(node *pNode);                         //������Ϣ
void change_stuInfo(node *pNode, int target);    //�޸���Ϣ

/*��������*/
auto load_file = [](node *pNode) -> void {
    //���ļ�
    FILE *fp = fopen("stu.txt", "r");
    stu tempData = {};
    if (fp == nullptr)
        fopen("stu.txt", "w+");

    //���ļ�
    while (fscanf(fp, "%d\t%s\t%s\t%d\t%d\t\t%d\t\t%d\t\t%s\n", &tempData.id, tempData.name, tempData.gender,
                  &tempData.age, &tempData.score_C, &tempData.score_math, &tempData.score_english, tempData.tel) !=
           EOF) {
        add(pNode, tempData);
    }
    //�ر��ļ�
    fclose(fp);
};

#endif //STU_INFO_ARRY_MAIN_H
