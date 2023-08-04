/**
 * ===================================================================
 * @brief 本程序由C/C++混合编写，替换了C的接收函数为C++的std::cin,
 *         以及使用了C++的文件流读写操作
 * @author Mr.N
 * @date 2023/8/3
 * @copyright Mr.N
 * ===================================================================
 * 状态：已完成，维护中                  工具：CLion 2023.1.4/MinGW64/CMake
 * ===================================================================
 * */

#include "main.h"

#pragma clang diagnostic push
#pragma ide diagnostic ignored "LoopDoesntUseConditionVariableInspection"
#pragma ide diagnostic ignored "EndlessLoop"

/*整个程序的起源-----main函数*/
int main() {
    load_file(list);
    while (true) {
        show_menu();
        user_input();
    }
}

/*菜单页面*/
void show_menu() {
    system("cls");
    printf("\n\n");
    printf("*****************************************************\n");
    printf("*----------------------Mr.N-------------------------*\n");
    printf("*                 学生信息管理系统                  *\n");
    printf("*****************************************************\n");
    printf("********************系统功能菜单*********************\n");
    printf("----------------------     --------------------------\n");
    printf("*****************************************************\n");
    printf("**    1、使用帮助       *     2、增加学生信息      **\n");
    printf("*****************************************************\n");
    printf("**    3、查询学生信息   *     4、删除学生信息      **\n");
    printf("*****************************************************\n");
    printf("**    5、保存当前信息   *     6、显示当前信息      **\n");
    printf("*****************************************************\n");
    printf("**    7、修改学生信息   *     8、刷新学生信息      **\n");
    printf("*****************************************************\n");
    printf("**    9、退出系统       *     0、显示当前人数      **\n");
    printf("*****************************************************\n");
    printf("----------------------     --------------------------\n");
    printf("您的选择->");
}

/*帮助文档*/
void help() {
    printf("\n这是一个学生信息管理系统，为了帮助您更快的了解使用它，请先仔细阅读以下注意事项：\n");
    printf("\n                  注意事项:                    \n ");
    printf("\n       1、请根据提示进行操作！\n");
    printf("\n       2、初次使用请先选择增加学生信息！\n");
    printf("\n       3、修改或者增加学生信息后切记保存！\n");
    printf("\n       4、如果数据有错误，请先修改再保存！\n");
    printf("\n       5、若您之前使用过，下次进入系统请先刷新学生信息！\n");
    printf("\n       6、在添加学生时，用两个字符代表不同的性别，比如男用‘M’代替,女用‘W’代替!\n");
    printf("\n       7、保存或者刷新时，输入的文件名后缀请使用.txt,比如: stu.txt,系统会在源程序\n");
    printf("\n          “学生管理系统.exe”的相同目录建立一个.txt文件来保存学生信息，您可以查看\n");
    printf("\n          该文件，但非专业人员不要轻易改动，否则会造成刷新数据异常或刷新失败！\n");
    printf("\n       8、学生信息包括：姓名、学号、性别、年龄、C语言成绩、高数成绩、英语成绩、电话等！\n");
    printf("\n       9、使用遇到任何问题请与我们联系，邮箱：fanxianx069108@126.com\n");
    printf("\n       10、最后感谢您的使用！\n");
    system("pause");
}

/**
 * @brief 用户输入 无需多言
 */
void user_input() {
    int user_choice, user_key;
    stu tempData = {};//初始化临时结构体变量
    line:
    user_choice = 0;
    std::cin >> user_choice;
    switch (user_choice) {
        case 0:
            printf("当前人数：%d\n", g_count);
            system("pause");
            break;
        case 1:
            system("cls");
            help();
            break;
        case 2:
        line_2:
            printf("请输入 学号、姓名、性别、年龄、C语言成绩、高数成绩、英语成绩、电话 等信息：\n->");
            std::cin >> tempData.id >> tempData.name >> tempData.gender >> tempData.age >> tempData.score_C
                     >> tempData.score_math
                     >> tempData.score_english >> tempData.tel;

            if (strlen(tempData.tel) != 11) {
                printf("电话号码长度错误!\n->");
                goto line_2;
            }

            add(list, tempData);
            break;
        case 3:
            printf("输入学号:");
            std::cin >> user_key;
            search_info(list, user_key);
            break;
        case 4:
            user_key = 0;
            printf("需要删除的学号ID：");
            std::cin >> user_key;
            delete_stuInfo(list, user_key);
            break;
        case 5:
            save(list);
            break;
        case 6:
            show_stu_info(list);
            break;
        case 7:
            printf("输入需要修改的学号：");
            std::cin >> user_key;
            change_stuInfo(list, user_key);
            break;
        case 8:
            main();//调用自己实现刷新。相当于重新启动程序
            break;
        case 9:
            printf("感谢您的使用!  Thanks for your used!\n");
            system("pause");
            exit(0);
            break;
        default:
            printf("输入有误，请重新输入:");
            goto line;
    }
}

/**
 * @brief 初始化链表
 * @return node*
 */
node *init_LinkList() {
    node *newList = (node *) malloc(sizeof(node) * 1);
    newList->next = nullptr;
    newList->data = {};
    return newList;
}

/**
 * @brief 添加学生信息-----链表尾插法
 * @param pNode 链表形参
 * @param value 插入的数据
 */
void add(node *pNode, stu value) {
    node *newNode = (node *) malloc(sizeof(node) * 1);
    if (newNode == nullptr) {
        printf("Memory error!\n");
        system("pause");
        return;
    } else {
        newNode->data = value;
        newNode->next = nullptr;
        node *temp = pNode;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = newNode;
        g_count++;
    }
}

/**
 * @brief 显示学生信息：遍历链表
 * @param pNode 链表形参-----表示要遍历的链表
 */
void show_stu_info(node *pNode) {
    node *temp = pNode->next;
    if (temp == nullptr) {
        printf("数据库为空！\n");
        system("pause");
        return;
    } else {
        printf("学号\t姓名\t性别\t年龄\tC语言成绩\t高数成绩\t英语成绩\t电话\n");
        printf("===========================================================================================\n");
        while (temp != nullptr) {
            printf("%d\t%s\t%s\t%d\t%d\t\t%d\t\t%d\t\t%s\n", temp->data.id, temp->data.name, temp->data.gender,
                   temp->data.age, temp->data.score_C, temp->data.score_math,
                   temp->data.score_english, temp->data.tel);
            temp = temp->next;
        }
    }
    printf("\n");
    system("pause");
}

/**
 * @brief 查找信息
 * @param pNode 链表形参
 * @param pos 查找的目标
 */
void search_info(node *pNode, int pos) {
    node *temp = pNode->next;
    if (temp == nullptr) {
        printf("数据库为空!\n");
        return;
    }

    while (temp->data.id != pos) {
        temp = temp->next;

        if (temp == nullptr) {
            printf("未找到指定学号!\n");
            system("pause");
            return;
        }
    }
    printf("Search success!\n");
    printf("Address:%p\n", &temp->data.id);
    printf("学号\t姓名\t性别\t年龄\tC语言成绩\t高数成绩\t英语成绩\t电话\n");
    printf("===========================================================================================\n");
    printf("%d\t%s\t%s\t%d\t%d\t\t%d\t\t%d\t\t%s\n", temp->data.id, temp->data.name, temp->data.gender, temp->data.age,
           temp->data.score_C, temp->data.score_math,
           temp->data.score_english, temp->data.tel);
    system("pause");
}

/**
 * @brief 删除操作
 * @param pNode 删除的目标链表
 * @param target 删除的目标节点
 */
void delete_stuInfo(node *pNode, int target) {
    node *pTempNodeFront = pNode, *pTempNode = pNode->next;
    if (pTempNode == nullptr) {
        printf("数据库为空!\n");
        return;
    }
    while (pTempNode->data.id != target) {
        pTempNodeFront = pTempNode;
        pTempNode = pTempNode->next;

        if (pTempNode == nullptr) {
            printf("未找到指定ID!\n");
            system("pause");
            return;
        }
    }
    /*找到了*/
    pTempNodeFront->next = pTempNode->next;//绕过目标节点
    free(pTempNode);//释放内存 达到删除节点的目的

    g_count--;//人数减少

    printf("Success!\n");
    system("pause");
}

/**
 * @brief 保存文件
 * @param pNode 链表形参
 */
void save(node *pNode) {
    std::ofstream ofs;
    node *pMove = pNode->next;
    ofs.open("stu.txt", std::ios::out);
    if (ofs.fail()) {
        printf("文件打开失败！\n");
        return;
    } else {
        while (pMove) {
            ofs << pMove->data.id << "\t" << pMove->data.name << "\t"
                << pMove->data.gender << "\t" << pMove->data.age << "\t"
                << pMove->data.score_C << "\t" << pMove->data.score_math << "\t"
                << pMove->data.score_english << "\t" << pMove->data.tel << std::endl;

            pMove = pMove->next;
        }
        printf("保存成功!\n");
        system("pause");
        ofs.close();
    }
}

/**
 * @brief 修改学生信息
 * @param pNode 链表形参
 * @param target 目标学号
 */
void change_stuInfo(node *pNode, int target) {
    node *temp = pNode->next;
    if (temp == nullptr) {
        printf("数据库为空!\n");
        return;
    }

    stu tempData = {};
    while (temp->data.id != target) {
        temp = temp->next;

        if (temp == nullptr) {
            printf("学号不存在\n");
            return;
        } else {
            printf("Search success!\n");
            printf("ID:%d\n", target);
            printf("学号\t姓名\t性别\t年龄\tC语言成绩\t高数成绩\t英语成绩\t电话\n");
            printf("%s\t%s\t%d\t\t%d\t\t%d\t\t%d\t\t%s\n", temp->data.name, temp->data.gender, temp->data.age,
                   temp->data.score_C, temp->data.score_math,
                   temp->data.score_english, temp->data.tel);
            printf("输入新的信息：");
            std::cin >> tempData.id >> tempData.name >> tempData.gender >> tempData.age >> tempData.score_C
                     >> tempData.score_math
                     >> tempData.score_english >> tempData.tel;
            temp->data = tempData;
        }
    }
}

#pragma clang diagnostic pop