/*
�����

 ��������
HDC labStart= txLoadImage("��������/���������/mini.bmp");

  ������ ��������� ����
 labStart = txLoadImage ("��������/���������/2 .bmp");

��������
txDeleteDC (labStart);




string PAGE = "Menu";

  if(GetAsyncKeyState(VK_ESCAPE))
   {
    PAGE = "Menu";
   }

if PAGE = "Menu"
{
txDrawText(0,0,1300,425,"�������� �������");
    txDrawText(0,531,1300,637,"���������� ");
}

    if PAGE =   "Start"
    {
    txDrawText(0,0,1300,425,"�������� �������");
    txDrawText(0,425,1300,531,"�����");
    txDrawText(0,531,1300,637,"���������� ");
    txDrawText(0,637,1300,743,"�������� ");
    txDrawText(0,743,1300,850,"������� ");
    }

if(click_answer(425))
{
Xim = true;
}


if(click_answer(531))
{
Mat = true;
}


if(click_answer(637))
{
Bio = true;
}


if(click_answer(743))
{
His = true;
}





y1=425;
y2=y+106;

txRectangle(  ,  ,  ,  );

bool Two;


if(txMouseX() >= 422 &&
txMouseY() >= 678 &&
txMouseX() <= 873 &&
txMouseY() <= 847 &&
txMouseButtons() == 1)
{
result++;
}

if(Two)
{
 txSetColor(TX_WHITE);
 txRectangle(0,0,1300,850);
 txSelectFont("Arial", 40);
 txRectangle(422,484,873,634);
 txDrawText(422,484,873,634,"�����");
}
int questionH = 1;
int questionM = 1;
int questionF = 1;
int questionG = 1;

tx(TX_BLACK)
txClear;
txDrawText(x,y,x,y "���������");
char str[10];
sprintf(str, %d,result);
txDrawText(x,y,x,y,str);

if(question == 1) form_list = Chemistry[0];
if(question == 2) form_list = Chemistry[1];
if(question == 3) form_list = Chemistry[2];
if(question == 4) form_list = Chemistry[3];
if(question == 5) form_list = Chemistry[4];
*/
#include "TXLib.h"
#include <fstream>

using namespace std;

void DrawAnswer(int y, string text)
{
    txSetColor(TX_WHITE);
    txSetFillColor(TX_BLACK);
    txSelectFont("Arial", 40);
    txRectangle(0,y,1300,y+106);
    txDrawText( 0,y,1300,y+106,text.c_str());
}

bool click_answer(int y)
{
    return(txMouseX() >= 0 &&
    txMouseY() >= y &&
    txMouseX() <= 1300 &&
    txMouseY() <= y+106 &&
    txMouseButtons() == 1);
}
struct Form
{
    string text_question;
    int right_answer;
    string text_answer1;
    string text_answer2;
    string text_answer3;
    string text_answer4;
};
string getPart(int *pos2, string str)
{
    int pos1 = *pos2 + 1;
    *pos2 = str.find(",", pos1);
    string part = str.substr(pos1,*pos2-pos1);
    return part;
}

int main()
{
txCreateWindow (1300, 850);
txTextCursor (false);

int n = 0;
int result = 0;
int question = 1;

string filename;
string PAGE = "";
string str;

HDC Fon= txLoadImage("��������/���������.bmp");

Form form;
Form form_list[50];

while(!GetAsyncKeyState(VK_ESCAPE))
{
question = 1;
//����� ��������
while(PAGE != "Start")
{
txClear();
txBegin();
txSelectFont("Arial", 40);
//������ � ������
txDrawText(0,0,1300,425,"�������� �������");
DrawAnswer(425,"�����");
DrawAnswer(531,"����������");
DrawAnswer(637,"��������");
DrawAnswer(743,"�������");
   //�����
    if(click_answer(425))
    {
        while(txMouseButtons() == 1) txSleep(50);
        filename = "�����.txt";
        PAGE = "Start";
        Fon = txLoadImage ("��������/�����.bmp");
    }

    if(click_answer(531))
    {
        while(txMouseButtons() == 1) txSleep(50);
        filename = "����������.txt";
        PAGE = "Start";
        Fon = txLoadImage ("��������/����������.bmp");
    }

    if(click_answer(637))
    {
        while(txMouseButtons() == 1) txSleep(50);
        filename = "��������.txt";
        PAGE = "Start";
        Fon = txLoadImage ("��������/��������.bmp");
    }

    if(click_answer(743))
    {
        while(txMouseButtons() == 1) txSleep(50);
        filename = "�������.txt";
        PAGE = "Start";
        Fon = txLoadImage ("��������/�������.bmp");
    }
    txEnd();
    txSleep(50);
}
//������ �� �����
ifstream file(filename);
while(file.good())
{
    getline(file, str);
    int pos2 = -1;
    form_list[n].text_question = getPart(&pos2, str);
    form_list[n].right_answer = atoi(getPart(&pos2, str).c_str());
    form_list[n].text_answer1 = getPart(&pos2, str);
    form_list[n].text_answer2 = getPart(&pos2, str);
    form_list[n].text_answer3 = getPart(&pos2, str);
    form_list[n].text_answer4 = getPart(&pos2, str);
    n++;
}
file.close();
txEnd();
//����
while(question<=n)
{
Fon;
PAGE = "";
txBegin();
txSetFillColor(TX_BLACK);
txClear();

    form = form_list[question -1];
    //������ � ������
    txDrawText(0,0,1300,425,form.text_question.c_str());
    DrawAnswer(425,form.text_answer1.c_str());
    DrawAnswer(531,form.text_answer2.c_str());
    DrawAnswer(637,form.text_answer3.c_str());
    DrawAnswer(743,form.text_answer4.c_str());

char str[10];
sprintf(str, "������ %d/%d", question, n);
txDrawText(414,0,885,100, str);
//�����
if(click_answer(425))
{
    while(txMouseButtons() == 1) txSleep(50);
    question++;
    txSleep(150);
        if(form.right_answer == 1)
        {
            result++;
        }
}

if(click_answer(531))
{
    while(txMouseButtons() == 1) txSleep(50);
    question++;
    txSleep(150);
        if(form.right_answer == 2)
        {
            result++;
        }
}

if(click_answer(637))
{
    while(txMouseButtons() == 1) txSleep(50);
    question++;
    txSleep(150);
        if(form.right_answer == 3)
        {
            result++;
        }
}

    if(click_answer(743))
    {
    while(txMouseButtons() == 1) txSleep(50);
    question++;
    txSleep(150);
        if(form.right_answer == 4)
        {
            result++;
        }
}

txSleep(50);
txEnd;
}
//���������
txSetFillColor(TX_BLACK);
txClear();
txDrawText( 0,0,1300,425,"���������� �������");
char s[10];
sprintf(s, "%d/%d", result, n);
txDrawText(0,0,1300,850,s);

txSleep(3000);
}
txDeleteDC (Fon);

return 0;
}
