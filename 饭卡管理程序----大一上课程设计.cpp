/*

主要参考资料
[1]谭浩强．C程序设计(第四版)．北京：清华大学出版社，2010 
[2]谭浩强．C程序设计题解与上机指导(第四版)．北京：清华大学出版社，2010
[3] Herbert Schildt．C语言大全（第四版）．北京：电子工业出版社, 2004
[4]Samuel P.Harbison Ⅲ,Guy L.Steele．C语言参考手册(第5版)．北京：机械工业出版社，2003
[5]C语言课程设计指导书

*/

#include <stdio.h>
#include <string.h>

struct Card {
    int id;
    char name[20];
    float balance;
    int lost;
};

struct Card cards[100];
int count = 0;

void menu() {
    printf("-----------------------------------\n");
    printf("请输入选项编号（1-6）：\n");
    printf("-----------------------------------\n");
    printf("1 —— 建立饭卡文件\n");
    printf("2 —— 买饭\n");
    printf("3 —— 续钱\n");
    printf("4 —— 添加新饭卡\n");
    printf("5 —— 注销旧饭卡\n");
    printf("6 —— 设置与解除挂失\n");
    printf("-----------------------------------\n");
}

void createFile() {
    printf("建立饭卡文件\n");
    printf("请输入人数：");
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("请输入第%d个人的饭卡号、姓名、金额、挂失信息(0:未挂失, 1:挂失)：\n", i + 1);
        scanf("%d%s%f%d", &cards[count].id, cards[count].name, &cards[count].balance, &cards[count].lost);
        count++;
    }
}

void buyMeal() {
    printf("买饭\n");
    printf("请输入饭卡号和饭费：\n");
    int id;
    float cost;
    scanf("%d%f", &id, &cost);
    for (int i = 0; i < count; i++) {
        if (cards[i].id == id) {
            if (cards[i].lost) {
                printf("本卡已冻结！\n");
                return;
            }
            if (cards[i].balance < 5) {
                printf("余额不够，请续钱！\n");
                return;
            }
            printf("买饭前余额：%.2f\n", cards[i].balance);
            cards[i].balance -= cost;
            printf("买饭后余额：%.2f\n", cards[i].balance);
            return;
        }
    }
    printf("未找到该饭卡号！\n");
}

void addMoney() {
    printf("续钱\n");
    printf("请输入饭卡号和续钱金额：\n");
    int id;
    float amount;
    scanf("%d%f", &id, &amount);
    for (int i = 0; i < count; i++) {
        if (cards[i].id == id) {
            printf("续钱前余额：%.2f\n", cards[i].balance);
            cards[i].balance += amount;
            printf("续钱后余额：%.2f\n", cards[i].balance);
            return;
        }
    }
    printf("未找到该饭卡号！\n");
}

void addCard() {
    printf("添加新饭卡\n");
    struct Card newCard;
    printf("请输入饭卡号、姓名、金额、挂失信息(0:未挂失, 1:挂失)：\n");
    scanf("%d%s%f%d", &newCard.id, newCard.name, &newCard.balance, &newCard.lost);
    for (int i = 0; i < count; i++) {
        if (cards[i].id == newCard.id) {
            printf("饭卡号不能重复！\n");
            return;
        }
    }
    cards[count++] = newCard;
    printf("新饭卡添加成功！\n");
}

void removeCard() {
    printf("注销旧饭卡\n");
    printf("请输入饭卡号：\n");
    int id;
    scanf("%d", &id);     
    for (int i = 0; i < count; i++) {
        if (cards[i].id == id) { 
            for (int j = i; j < count - 1; j++) {
                cards[j] = cards[j + 1];
            }
            count--;
            printf("饭卡注销成功！\n");
            return;
        }
    }
    printf("未找到该饭卡号！\n");
}

void setLost() {
    printf("设置与解除挂失\n");
    printf("请输入饭卡号和挂失信息(0:未挂失, 1:挂失)：\n");
    int id, lost;
    scanf("%d%d", &id, &lost);
    for (int i = 0; i < count; i++) {
        if (cards[i].id == id) {
            cards[i].lost = lost;
            printf("挂失信息更新成功！\n");
            return;
        }
    }
    printf("未找到该饭卡号！\n");
}

int main() {
    int choice;
    do {
        menu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                createFile();
                break;
            case 2:
                buyMeal();
                break;
            case 3:
                addMoney();
                break;
            case 4:
                addCard();
                break;
            case 5:
                removeCard();
                break;
            case 6:
                setLost();
                break;
            default:
                printf("无效选项，请重新输入！\n");
        }
    } while (choice >= 1 && choice <= 6);
    return 0;
}




/*

实习总结： 
	通过此次饭卡管理程序设计的实践任务，我在专业意识、职业技术技能以及思想素质等方面得到了全面提升。
这次实习不仅让我掌握了更多的技术细节，也让我更加深刻地理解了程序设计的价值与意义。
一、专业意识的提升
	在本次程序设计过程中，我深刻认识到软件开发中严谨性与逻辑性的重要性。饭卡管理程序看似功能简单，
	但其中涉及了数据结构、用户交互设计和逻辑实现的多个方面。例如，如何保证饭卡号的唯一性、挂失功能的准确性，
	以及用户操作的容错性，这些都让我认识到程序设计不仅仅是编写代码，更是为用户提供可靠、高效的解决方案。
	通过此次实践，我更加理解了程序员需要具备的细致和责任感，这种专业意识将持续引领我的学习与职业发展。
二、职业技术技能的提升
	在完成本程序设计的过程中，我得到了许多技术技能的提升：
1.	数据结构的应用：通过使用结构体存储饭卡信息，我熟悉了如何在C语言中管理复杂数据，
	并加深了对结构化编程的理解。
2.	用户界面设计：设计中文菜单界面时，我体会到如何让程序与用户友好交互，例如明确提示输入信息，
	避免用户误操作。
3.	逻辑处理与异常检测：在功能实现时，如"买饭"功能中检查余额不足、"添加新饭卡"时验证饭卡号的唯一性，
	我学会了如何通过细致的逻辑处理提高程序的健壮性。
4.	代码优化：通过模块化设计，我熟悉了如何将不同功能分离成函数，使代码结构更加清晰且易于维护。
	这些技能的锻炼让我在程序设计能力上有了显著提升，也为我今后承担更复杂的开发任务打下了基础。
三、思想素质的提高
	在任务执行过程中，面对功能需求的复杂性和多样性，我培养了更加严谨的思维习惯。比如，在处理用户输入时，
	我反复推敲如何兼顾程序的容错性与简洁性；在调试和测试中，我不断优化代码逻辑，以确保功能的正确性与稳
	定性。这种严谨与耐心的提升，不仅体现在程序设计中，也体现在我对待其他问题时的思考方式上。此外，在处
	理程序运行中出现的错误和挑战时，我学会了分析问题的根本原因，积累了冷静面对技术问题的宝贵经验。
四、总结与展望
	此次饭卡管理程序设计的实践，不仅提升了我的技术能力，也让我对编程工作有了更全面的认知。我意识到，
	程序设计的核心不仅在于实现功能，更在于解决实际问题、优化用户体验。在未来的学习和工作中，我将继续
	提升自己的专业能力，深入学习更高效的数据结构与算法，增强代码质量和工程实践能力，努力成为一名优秀
	的软件开发工程师。

*/
