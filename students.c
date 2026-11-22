#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//学生结构体 
typedef struct {
    char number[15];
    char name[13];
    float scores[3];
    float total;
    float average;
} Student;

//结构体指针
void calculateScores(Student *students, int count);
void sortByTotal(Student *students,int count);
void passCount(Student *students,int count);
void printStudents(Student *students,int count);

int main() {
    int count;
    printf("请输入学生人数：");
    if (scanf("%d",&count) !=1 || count<=0) {
        printf("输入无效，程序退出。\n");
        return 1;
    }
    //使用mallo.c动态申请结构体数组
    Student *students = (Student *)malloc(count*sizeof(Student));
    if (students == NULL) {
        printf("内存运行失败！\n");
        return 1;
    }
        //运行时输入学生信息
    int i;
    printf("请依次输入%d个学生的信息(学号 姓名 成绩1 成绩2 成绩3):\n",count);
    for ( i=0;i<count;i++) {
        printf("第%d个学生",i+1);
        scanf("%s %s %f %f %f",students[i].number,students[i].name,
        &students[i].scores[0],&students[i].scores[1],&students[i].scores[2]);
    }
    //计算总分和平均分
    calculateScores(students,count);

    //按总分降序排序
    sortByTotal(students,count);

    //统计及格人数（假设总分及格线为180，及平均分60分及格）
    int passedCount = countPassed(students,count);

    //打印结果
    printf("\n---学生成绩排序结果---\n");
    printfStudents(students,count);
    printf("\n及格人数:%d 人\n",passedCount);

    //释放动态分布的内存
    free(students);
    printf("内存已成功释放。\n");

    return 0;
}

//计算总分和平均分的函数（参数用结构体指针）
int i;
int j;
void sortByTotal(Student *students,int count) {
    for ( i=0;i<count-1;i++) {
        for ( j = 0;j<count-1;i++) {
            if (students[j].total < students[j+1].total) {
                //交换整个结构体
                Student temp = students[j];
                students[j] = students[j+1];
                students[j+1] = temp;
            }
        }
    }
}

//统计及格人数的函数
int countPassed(Student *students,int count) {
    int n =0;
    int i;
    for ( i = 0;i<count; i++) {
        //假设平均分>=60即为及格
        if (students[i].average >=60.0) {
            n++;
        }
    }
    return n;
}

//打印学生信息的辅助函数
int i;
void printfStudents(const Student *students, int count) {
    for ( i = 0; i<count; i++) {
        printf("学号:%s | 姓名:%s | 成绩:%.1f %.1f %.1f | 总分:%.1f | 平均分:%.2f\n",
        students[i].number,students[i].name,
        students[i].scores[0],students[i].scores[1],students[i].scores[2],
        students[i].total,students[i].average);
    
    }
}
