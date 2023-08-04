/**
 * ===================================================================
 * @brief ��������C/C++��ϱ�д���滻��C�Ľ��պ���ΪC++��std::cin,
 *         �Լ�ʹ����C++���ļ�����д����
 * @author Mr.N
 * @date 2023/8/3
 * @copyright Mr.N
 * ===================================================================
 * ״̬������ɣ�ά����                  ���ߣ�CLion 2023.1.4/MinGW64/CMake
 * ===================================================================
 * */

#include "main.h"

#pragma clang diagnostic push
#pragma ide diagnostic ignored "LoopDoesntUseConditionVariableInspection"
#pragma ide diagnostic ignored "EndlessLoop"

/*�����������Դ-----main����*/
int main() {
    load_file(list);
    while (true) {
        show_menu();
        user_input();
    }
}

/*�˵�ҳ��*/
void show_menu() {
    system("cls");
    printf("\n\n");
    printf("*****************************************************\n");
    printf("*----------------------Mr.N-------------------------*\n");
    printf("*                 ѧ����Ϣ����ϵͳ                  *\n");
    printf("*****************************************************\n");
    printf("********************ϵͳ���ܲ˵�*********************\n");
    printf("----------------------     --------------------------\n");
    printf("*****************************************************\n");
    printf("**    1��ʹ�ð���       *     2������ѧ����Ϣ      **\n");
    printf("*****************************************************\n");
    printf("**    3����ѯѧ����Ϣ   *     4��ɾ��ѧ����Ϣ      **\n");
    printf("*****************************************************\n");
    printf("**    5�����浱ǰ��Ϣ   *     6����ʾ��ǰ��Ϣ      **\n");
    printf("*****************************************************\n");
    printf("**    7���޸�ѧ����Ϣ   *     8��ˢ��ѧ����Ϣ      **\n");
    printf("*****************************************************\n");
    printf("**    9���˳�ϵͳ       *     0����ʾ��ǰ����      **\n");
    printf("*****************************************************\n");
    printf("----------------------     --------------------------\n");
    printf("����ѡ��->");
}

/*�����ĵ�*/
void help() {
    printf("\n����һ��ѧ����Ϣ����ϵͳ��Ϊ�˰�����������˽�ʹ������������ϸ�Ķ�����ע�����\n");
    printf("\n                  ע������:                    \n ");
    printf("\n       1���������ʾ���в�����\n");
    printf("\n       2������ʹ������ѡ������ѧ����Ϣ��\n");
    printf("\n       3���޸Ļ�������ѧ����Ϣ���мǱ��棡\n");
    printf("\n       4����������д��������޸��ٱ��棡\n");
    printf("\n       5������֮ǰʹ�ù����´ν���ϵͳ����ˢ��ѧ����Ϣ��\n");
    printf("\n       6�������ѧ��ʱ���������ַ�����ͬ���Ա𣬱������á�M������,Ů�á�W������!\n");
    printf("\n       7���������ˢ��ʱ��������ļ�����׺��ʹ��.txt,����: stu.txt,ϵͳ����Դ����\n");
    printf("\n          ��ѧ������ϵͳ.exe������ͬĿ¼����һ��.txt�ļ�������ѧ����Ϣ�������Բ鿴\n");
    printf("\n          ���ļ�������רҵ��Ա��Ҫ���׸Ķ�����������ˢ�������쳣��ˢ��ʧ�ܣ�\n");
    printf("\n       8��ѧ����Ϣ������������ѧ�š��Ա����䡢C���Գɼ��������ɼ���Ӣ��ɼ����绰�ȣ�\n");
    printf("\n       9��ʹ�������κ���������������ϵ�����䣺fanxianx069108@126.com\n");
    printf("\n       10������л����ʹ�ã�\n");
    system("pause");
}

/**
 * @brief �û����� �������
 */
void user_input() {
    int user_choice, user_key;
    stu tempData = {};//��ʼ����ʱ�ṹ�����
    line:
    user_choice = 0;
    std::cin >> user_choice;
    switch (user_choice) {
        case 0:
            printf("��ǰ������%d\n", g_count);
            system("pause");
            break;
        case 1:
            system("cls");
            help();
            break;
        case 2:
        line_2:
            printf("������ ѧ�š��������Ա����䡢C���Գɼ��������ɼ���Ӣ��ɼ����绰 ����Ϣ��\n->");
            std::cin >> tempData.id >> tempData.name >> tempData.gender >> tempData.age >> tempData.score_C
                     >> tempData.score_math
                     >> tempData.score_english >> tempData.tel;

            if (strlen(tempData.tel) != 11) {
                printf("�绰���볤�ȴ���!\n->");
                goto line_2;
            }

            add(list, tempData);
            break;
        case 3:
            printf("����ѧ��:");
            std::cin >> user_key;
            search_info(list, user_key);
            break;
        case 4:
            user_key = 0;
            printf("��Ҫɾ����ѧ��ID��");
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
            printf("������Ҫ�޸ĵ�ѧ�ţ�");
            std::cin >> user_key;
            change_stuInfo(list, user_key);
            break;
        case 8:
            main();//�����Լ�ʵ��ˢ�¡��൱��������������
            break;
        case 9:
            printf("��л����ʹ��!  Thanks for your used!\n");
            system("pause");
            exit(0);
            break;
        default:
            printf("������������������:");
            goto line;
    }
}

/**
 * @brief ��ʼ������
 * @return node*
 */
node *init_LinkList() {
    node *newList = (node *) malloc(sizeof(node) * 1);
    newList->next = nullptr;
    newList->data = {};
    return newList;
}

/**
 * @brief ���ѧ����Ϣ-----����β�巨
 * @param pNode �����β�
 * @param value ���������
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
 * @brief ��ʾѧ����Ϣ����������
 * @param pNode �����β�-----��ʾҪ����������
 */
void show_stu_info(node *pNode) {
    node *temp = pNode->next;
    if (temp == nullptr) {
        printf("���ݿ�Ϊ�գ�\n");
        system("pause");
        return;
    } else {
        printf("ѧ��\t����\t�Ա�\t����\tC���Գɼ�\t�����ɼ�\tӢ��ɼ�\t�绰\n");
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
 * @brief ������Ϣ
 * @param pNode �����β�
 * @param pos ���ҵ�Ŀ��
 */
void search_info(node *pNode, int pos) {
    node *temp = pNode->next;
    if (temp == nullptr) {
        printf("���ݿ�Ϊ��!\n");
        return;
    }

    while (temp->data.id != pos) {
        temp = temp->next;

        if (temp == nullptr) {
            printf("δ�ҵ�ָ��ѧ��!\n");
            system("pause");
            return;
        }
    }
    printf("Search success!\n");
    printf("Address:%p\n", &temp->data.id);
    printf("ѧ��\t����\t�Ա�\t����\tC���Գɼ�\t�����ɼ�\tӢ��ɼ�\t�绰\n");
    printf("===========================================================================================\n");
    printf("%d\t%s\t%s\t%d\t%d\t\t%d\t\t%d\t\t%s\n", temp->data.id, temp->data.name, temp->data.gender, temp->data.age,
           temp->data.score_C, temp->data.score_math,
           temp->data.score_english, temp->data.tel);
    system("pause");
}

/**
 * @brief ɾ������
 * @param pNode ɾ����Ŀ������
 * @param target ɾ����Ŀ��ڵ�
 */
void delete_stuInfo(node *pNode, int target) {
    node *pTempNodeFront = pNode, *pTempNode = pNode->next;
    if (pTempNode == nullptr) {
        printf("���ݿ�Ϊ��!\n");
        return;
    }
    while (pTempNode->data.id != target) {
        pTempNodeFront = pTempNode;
        pTempNode = pTempNode->next;

        if (pTempNode == nullptr) {
            printf("δ�ҵ�ָ��ID!\n");
            system("pause");
            return;
        }
    }
    /*�ҵ���*/
    pTempNodeFront->next = pTempNode->next;//�ƹ�Ŀ��ڵ�
    free(pTempNode);//�ͷ��ڴ� �ﵽɾ���ڵ��Ŀ��

    g_count--;//��������

    printf("Success!\n");
    system("pause");
}

/**
 * @brief �����ļ�
 * @param pNode �����β�
 */
void save(node *pNode) {
    std::ofstream ofs;
    node *pMove = pNode->next;
    ofs.open("stu.txt", std::ios::out);
    if (ofs.fail()) {
        printf("�ļ���ʧ�ܣ�\n");
        return;
    } else {
        while (pMove) {
            ofs << pMove->data.id << "\t" << pMove->data.name << "\t"
                << pMove->data.gender << "\t" << pMove->data.age << "\t"
                << pMove->data.score_C << "\t" << pMove->data.score_math << "\t"
                << pMove->data.score_english << "\t" << pMove->data.tel << std::endl;

            pMove = pMove->next;
        }
        printf("����ɹ�!\n");
        system("pause");
        ofs.close();
    }
}

/**
 * @brief �޸�ѧ����Ϣ
 * @param pNode �����β�
 * @param target Ŀ��ѧ��
 */
void change_stuInfo(node *pNode, int target) {
    node *temp = pNode->next;
    if (temp == nullptr) {
        printf("���ݿ�Ϊ��!\n");
        return;
    }

    stu tempData = {};
    while (temp->data.id != target) {
        temp = temp->next;

        if (temp == nullptr) {
            printf("ѧ�Ų�����\n");
            return;
        } else {
            printf("Search success!\n");
            printf("ID:%d\n", target);
            printf("ѧ��\t����\t�Ա�\t����\tC���Գɼ�\t�����ɼ�\tӢ��ɼ�\t�绰\n");
            printf("%s\t%s\t%d\t\t%d\t\t%d\t\t%d\t\t%s\n", temp->data.name, temp->data.gender, temp->data.age,
                   temp->data.score_C, temp->data.score_math,
                   temp->data.score_english, temp->data.tel);
            printf("�����µ���Ϣ��");
            std::cin >> tempData.id >> tempData.name >> tempData.gender >> tempData.age >> tempData.score_C
                     >> tempData.score_math
                     >> tempData.score_english >> tempData.tel;
            temp->data = tempData;
        }
    }
}

#pragma clang diagnostic pop