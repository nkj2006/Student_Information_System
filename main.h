//
// Created by Mr.N on 2023/8/3.
//

#ifndef STU_INFO_ARRY_MAIN_H
#define STU_INFO_ARRY_MAIN_H

#include <iostream>
#include <fstream>
#include <cstring>

struct Student {
    int id;             //学号
    char name[10];      //姓名
    char gender[5];     //性别
    int age;            //年龄
    int score_C;        //C语言成绩
    int score_math;     //数学成绩
    int score_english;  //英语成绩
    char tel[12];       //电话
};
typedef struct Student stu;

/*链表节点*/
struct Node {
    stu data;
    struct Node *next;
};
typedef struct Node node;

node *init_LinkList();          //初始化链表并穿件表头
node *list = init_LinkList();   //初始化链表list

int g_count = 0;                //表示人数;

void show_menu();                   //菜单界面
void user_input();                  //用户输入
void help();                        //帮助界面
void add(node *pNode, stu value);   //添加信息
void search_info(node *pNode, int pos);         //查找信息：通过ID查找
void show_stu_info(node *pNode);                //显示信息
void delete_stuInfo(node *pNode, int target);   //删除学生信息
void save(node *pNode);                         //保存信息
void change_stuInfo(node *pNode, int target);    //修改信息

/*加载数据*/
auto load_file = [](node *pNode) -> void {
    //打开文件
    FILE *fp = fopen("stu.txt", "r");
    stu tempData = {};
    if (fp == nullptr)
        fopen("stu.txt", "w+");

    //读文件
    while (fscanf(fp, "%d\t%s\t%s\t%d\t%d\t\t%d\t\t%d\t\t%s\n", &tempData.id, tempData.name, tempData.gender,
                  &tempData.age, &tempData.score_C, &tempData.score_math, &tempData.score_english, tempData.tel) !=
           EOF) {
        add(pNode, tempData);
    }
    //关闭文件
    fclose(fp);
};

#endif //STU_INFO_ARRY_MAIN_H
