#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <graphics.h>
#include <vector>
#include <string.h>
#include <math.h>
#include <windows.h>
#include <mmsystem.h>

#define fireCounterMax 20
#define counterMax 400
#define sizeCounterMax 200

void mainMenu(int refPointX,int refPointY)//DISPLAY SIZE IS 1024X768 px
{
    circle(refPointX,refPointY,4);//TOP LEFT SCREEN MARKER
    circle(refPointX+1024,refPointY,4);//TOP RIGHT SCREEN MARKER
    circle(refPointX+1024,refPointY+768,4);//DOWN RIGHT SCREEN MARKER
    circle(refPointX,refPointY+768,4);//DOWN LEFT SCREEN MARKER

    line(refPointX,refPointY,refPointX,refPointY+768);
    line(refPointX+1024,refPointY,refPointX+1024,refPointY+768);

    settextstyle(5,HORIZ_DIR,27);//15//style 5=written text
    outtextxy(refPointX+100,refPointY+50,"NORMANDY DEFENDER 1944");
    settextstyle(5,HORIZ_DIR,14);
    outtextxy(refPointX+620,refPointY+170,"On the 6th of June");
    outtextxy(refPointX+620,refPointY+225,"On the shores of western Europe...");
    line(refPointX+150,refPointY+200,refPointX+335,refPointY+200);
    line(refPointX+335,refPointY+200,refPointX+335,refPointY+195);
    line(refPointX+335,refPointY+195,refPointX+365,refPointY+195);
    line(refPointX+365,refPointY+195,refPointX+365,refPointY+200);
    line(refPointX+365,refPointY+200,refPointX+400,refPointY+200);
    line(refPointX+400,refPointY+200,refPointX+440,refPointY+190);
    line(refPointX+440,refPointY+190,refPointX+550,refPointY+190);
    line(refPointX+550,refPointY+190,refPointX+600,refPointY+180);
    line(refPointX+335,refPointY+195,refPointX+365,refPointY+186);
    line(refPointX+339,refPointY+195,refPointX+365,refPointY+186);
    circle(refPointX+350,refPointY+193,3);
    floodfill(refPointX+350,refPointY+193,WHITE);
    line(refPointX+365,refPointY+186,refPointX+365,refPointY+183);
    line(refPointX+150,refPointY+215,refPointX+450,refPointY+215);
    line(refPointX+450,refPointY+215,refPointX+455,refPointY+220);
    line(refPointX+466,refPointY+218,refPointX+464,refPointY+227);
    circle(refPointX+463,refPointY+225,8);
    line(refPointX+475,refPointY+215,refPointX+500,refPointY+240);
    line(refPointX+475,refPointY+215,refPointX+550,refPointY+215);
    line(refPointX+550,refPointY+215,refPointX+600,refPointY+225);
    arc(refPointX+630,refPointY+204,140,215,37);
    line(refPointX+466,refPointY+231,refPointX+480,refPointY+245);
    line(refPointX+480,refPointY+245,refPointX+500,refPointY+240);
    arc(refPointX+150,refPointY+208,90,150,7);
    arc(refPointX+150,refPointY+208,210,270,7);
    line(refPointX+144,refPointY+204,refPointX+131,refPointY+200);
    line(refPointX+144,refPointY+212,refPointX+131,refPointY+216);
    line(refPointX+131,refPointY+200,refPointX+131,refPointY+216);
    arc(refPointX+155,refPointY+208,90,270,7);
    arc(refPointX+160,refPointY+208,90,270,7);
    line(refPointX+185,refPointY+205,refPointX+205,refPointY+205);
    line(refPointX+185,refPointY+210,refPointX+205,refPointY+210);
    arc(refPointX+185,refPointY+208,90,270,3);
    arc(refPointX+205,refPointY+208,-90,90,3);
    line(refPointX+235,refPointY+205,refPointX+255,refPointY+205);
    line(refPointX+235,refPointY+210,refPointX+255,refPointY+210);
    arc(refPointX+235,refPointY+208,90,270,3);
    arc(refPointX+255,refPointY+208,-90,90,3);
    line(refPointX+285,refPointY+205,refPointX+305,refPointY+205);
    line(refPointX+285,refPointY+210,refPointX+305,refPointY+210);
    arc(refPointX+285,refPointY+208,90,270,3);
    arc(refPointX+305,refPointY+208,-90,90,3);
    rectangle(refPointX+450,refPointY+195,refPointX+490,refPointY+200);
    floodfill(refPointX+455,refPointY+197,WHITE);
    rectangle(refPointX+180,refPointY+218,refPointX+280,refPointY+223);
    rectangle(refPointX+180,refPointY+215,refPointX+195,refPointY+223);
    floodfill(refPointX+182,refPointY+217,WHITE);
    floodfill(refPointX+182,refPointY+219,WHITE);
    floodfill(refPointX+220,refPointY+219,WHITE);
    rectangle(refPointX+414,refPointY+350,refPointX+614,refPointY+400);
    settextstyle(5,HORIZ_DIR,15);
    outtextxy(refPointX+463,refPointY+360,"PLAY");
    rectangle(refPointX+414,refPointY+450,refPointX+614,refPointY+500);
    outtextxy(refPointX+463,refPointY+460,"INFO");
    rectangle(refPointX+414,refPointY+550,refPointX+614,refPointY+600);
    outtextxy(refPointX+463,refPointY+560,"EXIT");
}

void infoText(int refPointX,int refPointY)
{
    /*cleardevice();//PREVIOUS VERSION OF INFO TEXT
    circle(refPointX,refPointY,4);
    circle(refPointX+1024,refPointY,4);
    circle(refPointX+1024,refPointY+768,4);
    circle(refPointX,refPointY+768,4);
    settextstyle(5,HORIZ_DIR,18);
    outtextxy(refPointX+207,refPointY+570,"Created by: Mihailo");
    outtextxy(refPointX+300,refPointY+150,"How to play:");
    outtextxy(refPointX+100,refPointY+250,"Use mouse to aim");
    outtextxy(refPointX+100,refPointY+320,"Use left mouse button to shoot");
    outtextxy(refPointX+670,refPointY+380,"Have fun!");*/

    cleardevice();
    circle(refPointX,refPointY,4);//THIS SEGMENT OF CODE USED FOR TEXT CENTERING
    circle(refPointX+1024,refPointY,4);
    circle(refPointX+1024,refPointY+768,4);
    circle(refPointX,refPointY+768,4);
    line(refPointX,refPointY,refPointX,refPointY+768);
    line(refPointX+1024,refPointY,refPointX+1024,refPointY+768);

    settextstyle(5,HORIZ_DIR,18);
    outtextxy(refPointX+182,refPointY+500,"Created by: Mihailo");
    outtextxy(refPointX+275,refPointY+80,"How to play:");
    outtextxy(refPointX+210,refPointY+180,"Use mouse to aim");
    outtextxy(refPointX+60,refPointY+250,"Use left mouse button to shoot");
    outtextxy(refPointX+20,refPointY+330,"Press escape button to quit game");
    outtextxy(refPointX+630,refPointY+410,"Have fun!");
}

void gameplayBase(int refPointX,int refPointY)
{
    circle(refPointX,refPointY,4);
    circle(refPointX+1024,refPointY,4);
    circle(refPointX+1024,refPointY+768,4);
    circle(refPointX,refPointY+768,4);

    line(refPointX+487,refPointY+500,refPointX+420,refPointY+768);// GUN BARREL
    line(refPointX+537,refPointY+500,refPointX+604,refPointY+768);// GUN BARREL

    line(refPointX+495,refPointY+600,refPointX+484,refPointY+650);// LEFT SIDE OF SIGHT
    line(refPointX+484,refPointY+650,refPointX+474,refPointY+650);// LEFT SIDE OF SIGHT
    line(refPointX+474,refPointY+650,refPointX+469,refPointY+670);// LEFT SIDE OF SIGHT
    rectangle(refPointX+469,refPointY+670,refPointX+478,refPointY+673);// LEFT SIDE OF SIGHT
    line(refPointX+469,refPointY+670,refPointX+478,refPointY+670);// LEFT SIDE OF SIGHT
    line(refPointX+478,refPointY+670,refPointX+475,refPointY+684);// LEFT SIDE OF SIGHT
    line(refPointX+495,refPointY+603,refPointX+510,refPointY+603);
    line(refPointX+493,refPointY+615,refPointX+510,refPointY+615);
    line(refPointX+490,refPointY+627,refPointX+510,refPointY+627);
    line(refPointX+487,refPointY+639,refPointX+510,refPointY+639);

    line(refPointX+529,refPointY+600,refPointX+540,refPointY+650);// RIGHT SIDE OF SIGHT
    line(refPointX+540,refPointY+650,refPointX+550,refPointY+650);// RIGHT SIDE OF SIGHT
    line(refPointX+550,refPointY+650,refPointX+555,refPointY+670);// RIGHT SIDE OF SIGHT
    rectangle(refPointX+555,refPointY+670,refPointX+546,refPointY+673);// RIGHT SIDE OF SIGHT
    line(refPointX+555,refPointY+670,refPointX+546,refPointY+670);// RIGHT SIDE OF SIGHT
    line(refPointX+546,refPointY+670,refPointX+549,refPointY+684);// RIGHT SIDE OF SIGHT
    line(refPointX+530,refPointY+609,refPointX+514,refPointY+609);
    line(refPointX+533,refPointY+621,refPointX+514,refPointY+621);
    line(refPointX+535,refPointY+633,refPointX+514,refPointY+633);

    line(refPointX+484,refPointY+650,refPointX+540,refPointY+650);// CONNECTING LINE
    line(refPointX+478,refPointY+670,refPointX+546,refPointY+670);// CONNECTING LINE
    line(refPointX+475,refPointY+684,refPointX+484,refPointY+675);
    line(refPointX+549,refPointY+684,refPointX+540,refPointY+675);
    line(refPointX+484,refPointY+675,refPointX+502,refPointY+675);
    line(refPointX+540,refPointY+675,refPointX+522,refPointY+675);
    line(refPointX+502,refPointY+675,refPointX+512,refPointY+679);
    line(refPointX+522,refPointY+675,refPointX+512,refPointY+679);
    rectangle(refPointX+475,refPointY+684,refPointX+549,refPointY+686);
    arc(refPointX+512,refPointY+517,34,146,30);//60,120,45
    arc(refPointX+512,refPointY+525,24,151,32);
    line(refPointX+506,refPointY+520,refPointX+512,refPointY+510);
    line(refPointX+512,refPointY+510,refPointX+518,refPointY+520);
    line(refPointX+506,refPointY+517,refPointX+512,refPointY+507);
    line(refPointX+512,refPointY+507,refPointX+518,refPointY+517);

    //        SetCursorPos(refPointX+512,refPointY+384);

    line(refPointX+520,refPointY+384,refPointX+540,refPointY+384);
    line(refPointX+504,refPointY+384,refPointX+484,refPointY+384);//CROSSHAIR
    line(refPointX+512,refPointY+390,refPointX+512,refPointY+405);

    /*arc(refPointX+512,refPointY+545,20,160,12);
    line(refPointX+500,refPointY+541,refPointX+490,refPointY+569);//UPPER COOLING OPENING
    line(refPointX+522,refPointY+541,refPointX+532,refPointY+570);
    arc(refPointX+512,refPointY+563,200,340,24);//565,200,340,15*/

    /*circle(refPointX+512,refPointY+540,1);
    circle(refPointX+512,refPointY+550,1);
    circle(refPointX+512,refPointY+560,1);
    circle(refPointX+512,refPointY+570,1);
    circle(refPointX+512,refPointY+580,1);
    circle(refPointX+512,refPointY+590,1);
    circle(refPointX+512,refPointY+600,1);*/
}

void drawPlane(int posX,int posY,int size)
{
        circle(posX,posY,10+size-1);//NOSE
        circle(posX,posY,(10+size-1)/2);

        line(posX-(10+size-1)/3,posY-(10+size-1),posX,posY-(10+size-1)*2.5);//BACK WINGS
        line(posX,posY-(10+size-1)*2.5,posX+(10+size-1)/3,posY-(10+size-1));

        line(posX+(10+size-1)/2,posY+(10+size-1)*0.8,posX+(10+size-1)*8.5,posY-(10+size-1)*1.5);//LEFT WING (RIGHT SIDE FOR VIEWER)
        line(posX+(10+size-1)*8.5,posY-(10+size-1)*1.5,posX+(10+size-1),posY+(10+size-1)*0.1);

        line(posX-(10+size-1)/2,posY+(10+size-1)*0.8,posX-(10+size-1)*8.5,posY-(10+size-1)*1.5);//RIGHT WING (LEFT SIDE FOR VIEWER)
        line(posX-(10+size-1)*8.5,posY-(10+size-1)*1.5,posX-(10+size-1),posY+(10+size-1)*0.1);


        /*
        circle(posX,posY,10);//NOSE   PLANE DRAWING FOR SIZE=1
        circle(posX,posY,5);

        line(posX-3,posY-9,posX,posY-25);//BACK WINGS
        line(posX,posY-25,posX+3,posY-9);

        line(posX+5,posY+7,posX+85,posY-15);//LEFT WING (RIGHT SIDE FOR VIEWER)
        line(posX+85,posY-15,posX+8,posY+1);

        line(posX-5,posY+7,posX-85,posY-15);//RIGHT WING (LEFT SIDE FOR VIEWER)
        line(posX-85,posY-15,posX-8,posY+1);*/
}

typedef struct
{
    int pointX,pointY,health,speed,size;
}EnemyWarplane;

long calculateDistance(long x1,long y1,long x2,long y2)
{
    return sqrt(pow(x1-x2,2)+pow(y1-y2,2));
}

int gameEngine(std::vector<EnemyWarplane> **enemyPlanes,long aimPositionX,long aimPositionY,int refPointX,int refPointY,int *counter,int *sizeCounter,int *playerHealth,int *numOfPlanesDestroyed,int *fireFlag,int *fireCounter, int *refreshFlag)//BRAIN OF GAMEPLAY
{
    int sizeIncFlag=0;
    int i;
    EnemyWarplane temp;
    if((*sizeCounter)==sizeCounterMax)
    {
        sizeIncFlag=1;
        (*sizeCounter)=0;
        (*refreshFlag)=1;
    }
    else
    {
        (*sizeCounter)++;
    }
    if(*fireFlag)
    {
        if(*fireCounter==fireCounterMax)
        {
            PlaySound(TEXT("audio/8bit_gunloop_explosion.wav"), NULL, SND_ASYNC);
            (*fireCounter)--;
        }
        else
        {
            if((*fireCounter)==0)
            {
                (*fireCounter)=fireCounterMax;
            }
            else
            {
                (*fireCounter)--;
            }
        }
    }
    else
    {
        *fireCounter=fireCounterMax;
    }
    if(*refreshFlag)
    {
        cleardevice();
    }
    for(i=0;i<(*enemyPlanes)->size();i++)
    {
        temp=(*enemyPlanes)->at(i);
        if(*fireFlag)
        {

            if(calculateDistance(refPointX+temp.pointX+aimPositionX+512,temp.pointY+aimPositionY,refPointX+512,refPointY+384)<=(10+temp.size-1))//TAKE refPointY INTO CONSIDERATION
            {
                temp.health--;
                if(temp.health==0)
                {
                    (*enemyPlanes)->erase((*enemyPlanes)->begin()+i);
                    (*numOfPlanesDestroyed)++;
                    continue;
                }
                else
                {
                    (*enemyPlanes)->at(i)=temp;
                }
            }
        }
        if(*refreshFlag)
        {
            drawPlane(refPointX+temp.pointX+aimPositionX+512,temp.pointY+aimPositionY,temp.size);//take refPointY into consideration
        }
        if(temp.size>=15)
        {
            (*enemyPlanes)->erase((*enemyPlanes)->begin()+i);
            (*playerHealth)=(*playerHealth)-5;
            (*refreshFlag)=1;
        }
        if((*playerHealth)==0)
        {
            return 1;
        }
        if(sizeIncFlag)
        {
            temp.size=temp.size+temp.speed;
            (*enemyPlanes)->at(i)=temp;
            *(refreshFlag)=1;
        }
    }
    (*fireFlag)=0;
    (*refreshFlag)=0;
    if((*counter)==counterMax)
    {
        temp.health=100;
        temp.pointX=-1000+rand()%2000;
        temp.pointY=50+rand()%350;//50-350
        temp.size=1;
        temp.speed=1+rand()%2;
        (*enemyPlanes)->push_back(temp);
        (*counter)=0;
        (*refreshFlag)=1;
    }
    else
    {
        (*counter)++;
    }
    return 0;
}

void endGameScreen(int numOfPlanesDestroyed,int refPointX,int refPointY)
{
    char score[50];
    int aux[7];
    int len,temp,i,j,flag;

    circle(refPointX,refPointY,4);//THIS SEGMENT OF CODE USED FOR TEXT CENTERING
    circle(refPointX+1024,refPointY,4);
    circle(refPointX+1024,refPointY+768,4);
    circle(refPointX,refPointY+768,4);
    line(refPointX,refPointY,refPointX,refPointY+768);
    line(refPointX+1024,refPointY,refPointX+1024,refPointY+768);

    settextstyle(5,HORIZ_DIR,20);
    outtextxy(refPointX+250,150,"Game Over!");//420
    settextstyle(5,HORIZ_DIR,16);
    strcpy(score,"Number of enemy planes shot down: ");//170,0
    len=strlen(score);
    temp=numOfPlanesDestroyed;
    /*if(numOfPlanesDestroyed<10)//THIS METHOD OF CONVERTING INTEGER TO STRING WORKS ONLY FOR ONE DIGIT AND TWO DIGIT NUMBERS
    {
        len=strlen(score);
        score[len]=numOfPlanesDestroyed+48;
        score[len+1]='\0';
    }
    else
    {
        temp=numOfPlanesDestroyed/10;
        len=strlen(score);
        score[len]=temp+48;
        temp=numOfPlanesDestroyed%10;
        score[len+1]=temp+48;
        score[len+2]='\0';
    }*/
    for(i=6;i>=0;i--)
    {
        aux[i]=(temp%10)+48;
        temp=temp/10;
    }
    for(i=0,j=0,flag=0;i<7;i++)
    {
        if(aux[i]!=48)
        {
            flag=1;
        }
        if(flag)
        {
            score[len+j]=aux[i];
            j++;
        }
    }
    if(flag)
    {
        score[len+j]='\0';
    }
    else
    {
        score[len]=48;
        score[len+1]='\0';
    }
    settextstyle(5,HORIZ_DIR,16);
    if(numOfPlanesDestroyed<10000)
    {
        outtextxy(refPointX+120,280,score);
    }
    else
    {
        outtextxy(refPointX+50,280,score);
    }
}

/*void drawHealthInfo(int playerHealth,int refPointX,int refPointY)//CAUSES WEIRD BUG (EMPTY SCREEN BUG)
{                                                                       //SCREEN IS EMPTY BEFORE END OF GAME
    int len,temp;                                                       //E.G. SCREEN GETS EMPTY AT 15% OF HP AFTER 3 PLANES SHOT DOWN
    char healthString[20];                                          //UNUSUAL CONNECTION (THE MORE PLANES SHOT THE SOONER BUG OCCURS)
    strcpy(healthString,"Health: ");                           // GAME GETS SKIPPED TO END GAME SCREEN
    if(playerHealth==100)
    {
        strcat(healthString,"100%");
    }
    else
    {
        if(playerHealth<10)
        {
            len=strlen(healthString);
            healthString[len]=playerHealth+48;
            healthString[len+1]='%';
            healthString[len+2]='\0';
        }
        else
        {
            temp=playerHealth/10;
            len=strlen(healthString);
            healthString[len]=temp+48;
            temp=playerHealth%10;
            healthString[len+1]=temp+48;
            healthString[len+2]='%';
            healthString[len+3]='\0';
        }
    }
    settextstyle(5,HORIZ_DIR,17);
    outtextxy(refPointX+600,refPointY+600,healthString);
}*/

void drawHealthInfoBar(int playerHealth,int refPointX,int refPointY)
{
    rectangle(refPointX+750,refPointY+500,refPointX+760,refPointY+700);//HEALTH BAR BASE

    line(refPointX+710,refPointY+720,refPointX+710,refPointY+750);
    line(refPointX+710,refPointY+720,refPointX+725,refPointY+720);
    line(refPointX+725,refPointY+720,refPointX+725,refPointY+730);
    line(refPointX+725,refPointY+730,refPointX+735,refPointY+730);
    line(refPointX+735,refPointY+730,refPointX+735,refPointY+720);
    line(refPointX+735,refPointY+720,refPointX+750,refPointY+720);//LETTER 'H'
    line(refPointX+750,refPointY+720,refPointX+750,refPointY+750);
    line(refPointX+750,refPointY+750,refPointX+735,refPointY+750);
    line(refPointX+735,refPointY+750,refPointX+735,refPointY+740);
    line(refPointX+735,refPointY+740,refPointX+725,refPointY+740);
    line(refPointX+725,refPointY+740,refPointX+725,refPointY+750);
    line(refPointX+725,refPointY+750,refPointX+710,refPointY+750);

    line(refPointX+760,refPointY+720,refPointX+760,refPointY+750);
    line(refPointX+760,refPointY+720,refPointX+780,refPointY+720);
    arc(refPointX+780,refPointY+730,-90,90,10);
    line(refPointX+770,refPointY+740,refPointX+780,refPointY+740);
    line(refPointX+770,refPointY+740,refPointX+770,refPointY+750);
    line(refPointX+770,refPointY+750,refPointX+760,refPointY+750);//LETTER 'P'
    line(refPointX+770,refPointY+728,refPointX+770,refPointY+732);
    line(refPointX+770,refPointY+728,refPointX+777,refPointY+728);
    arc(refPointX+777,refPointY+730,-90,90,2);
    line(refPointX+770,refPointY+732,refPointX+777,refPointY+732);

    line(refPointX+750,refPointY+700-playerHealth*2,refPointX+760,refPointY+700-playerHealth*2);//DRAWS CURRENT HEALTH STATUS
    floodfill(refPointX+755,refPointY+695,WHITE);//FILLS THE BAR
}

int main() // what if screen height != 768,  refresh display only when needed, consider using cod1/cod2 main menu music, find way to add icon to code blocks project
{
    POINT cursorPosition,aimPosition,cursorPositionDelta;
    std::vector<EnemyWarplane> enemyPlanes,*enemyPlanesPointer;
    enemyPlanesPointer=&enemyPlanes;
    EnemyWarplane temp;
    int counter,sizeCounter,playerHealth,gameOverFlag,numOfPlanesDestroyed,fireFlag,fireCounter,refreshFlag;
    int refPointX,refPointY,mouseClickControlFlag;
    printf("\n\n\n\n\n\n\t\t\t        *   *   *   *\n\t\t\t   NORMANDY DEFENDER 1944\n\n\t\t\tCREATED BY: MIHAILO KNEZEVIC\n\t\t\t        *   *   *   *\n");//DECORATE THIS USING ****
    initwindow(GetSystemMetrics(SM_CXSCREEN),GetSystemMetrics(SM_CYSCREEN),"",-3,-3);
    refPointX=GetSystemMetrics(SM_CXSCREEN)/2-512;//APPROX. 170 FOR 1366 PIXEL WIDTH DISPLAY
    refPointY=GetSystemMetrics(SM_CYSCREEN)-768;//GetSystemMetrics(SM_CYSCREEN)/2-384;//APPROX. 0 FOR 768 PIXEL HEIGHT DISPLAY
    if(refPointX<0||refPointY<0)
    {
        printf("\n\n\n\n\n\n\t\t     --UNSUPPORTED RESOLUTION DETECTED--\n\n\t\t  YOU NEED AT LEAST 1024X768 PIXELS DISPLAY\n\n\t\t  THE GAME WILL CLOSE AFTER YOU PRESS ENTER...");
        closegraph();
        getchar();
        return 0;
    }
    mouseClickControlFlag=1;
    srand(time(NULL));
    b:
    PlaySound(TEXT("audio/erika.wav"), NULL, SND_ASYNC|SND_LOOP);//*** MUSIC USED: https://www.youtube.com/watch?v=YcJnmn_ib1s ***
    a:
    mainMenu(refPointX,refPointY);//170,0 FOR 1366X768 SCREEN
    while(1)// MAIN MENU
    {
        if(GetAsyncKeyState(VK_LBUTTON))
        {
            if(mouseClickControlFlag)
            {
                mouseClickControlFlag=0;
                GetCursorPos(&cursorPosition);
                if(cursorPosition.x>=(refPointX+414)&&cursorPosition.x<=(refPointX+614)&&cursorPosition.y>=(refPointY+550)&&cursorPosition.y<=(refPointY+600))//CHECKS WHETHER EXIT BUTTON IS PRESSED
                {
                return 0;
                }
                if(cursorPosition.x>=(refPointX+414)&&cursorPosition.x<=(refPointX+614)&&cursorPosition.y>=(refPointY+450)&&cursorPosition.y<=(refPointY+500))//CHECKS WHETHER INFO BUTTON IS PRESSED
                {
                    infoText(refPointX,refPointY);
                    while(1)
                    {
                        if(GetAsyncKeyState(VK_LBUTTON))
                        {
                            if(mouseClickControlFlag)
                            {
                                mouseClickControlFlag=0;
                                cleardevice();
                                goto a;
                            }
                        }
                        else
                        {
                            mouseClickControlFlag=1;
                        }
                    }
                }
                if(cursorPosition.x>=(refPointX+414)&&cursorPosition.x<=(refPointX+614)&&cursorPosition.y>=(refPointY+350)&&cursorPosition.y<=(refPointY+400))//CHECKS WHETHER PLAY BUTTON IS PRESSED
                {
                    cleardevice();
                    mouseClickControlFlag=0;
                    break;
                }
            }
        }
        else
        {
            mouseClickControlFlag=1;
        }
    }
    PlaySound(NULL, NULL, SND_ASYNC|SND_LOOP);//STOPS PLAYING SOUND
    aimPosition.x=0;//X START POSITION
    aimPosition.y=0;//Y START POSITION (IN PREVIOUS VERSION Y START VALUE WAS 400)
    counter=0;
    sizeCounter=0;
    numOfPlanesDestroyed=0;
    playerHealth=100;
    fireCounter=fireCounterMax;
    while(1)// GAMEPLAY
    {
        gameplayBase(refPointX,refPointY);
        drawHealthInfoBar(playerHealth,refPointX,refPointY);
        SetCursorPos(refPointX+50,refPointY+718);
        circle(refPointX+50,refPointY+718,20);//JOYSTICK REPRESENTATION
        delay(1);
        //circle(refPointX+512,refPointY+384,5);//AIM MARKER
        gameOverFlag=gameEngine(&enemyPlanesPointer,aimPosition.x,aimPosition.y,refPointX,refPointY,&counter,&sizeCounter,&playerHealth,&numOfPlanesDestroyed,&fireFlag,&fireCounter,&refreshFlag);
        GetCursorPos(&cursorPosition);
        cursorPositionDelta.x=cursorPosition.x-refPointX-50;
        cursorPositionDelta.y=cursorPosition.y-refPointY-718;
        if(cursorPositionDelta.x!=0||cursorPositionDelta.y!=0)
        {
            refreshFlag=1;
        }
        if((aimPosition.x>-1536&&cursorPositionDelta.x>0)||(aimPosition.x<1536&&cursorPositionDelta.x<0))
        {
            aimPosition.x=aimPosition.x-cursorPositionDelta.x;
        }
        if((aimPosition.y>0&&cursorPositionDelta.y>0)||(aimPosition.y<340&&cursorPositionDelta.y<0))//400 is max value by Y axis which aim should reach
        {
            aimPosition.y=aimPosition.y-cursorPositionDelta.y;
        }
        printf("%d %d   %ld %ld\n",cursorPosition.x,cursorPosition.y,aimPosition.x,aimPosition.y);
        //circle(cursorPosition.x,cursorPosition.y,5);//MOUSE CURSOR POSITION
        if(GetAsyncKeyState(VK_LBUTTON))
        {
            if(mouseClickControlFlag)
            {
                fireFlag=1;
            }
        }
        else
        {
            mouseClickControlFlag=1;
        }
        //cleardevice();
        if(GetAsyncKeyState(VK_ESCAPE)||gameOverFlag)
        {
            enemyPlanes.clear();
            cleardevice();
            endGameScreen(numOfPlanesDestroyed,refPointX,refPointY);
            printf("\n\n&&&&  %d &&&&",playerHealth);
            mouseClickControlFlag=0;
            while(1)
            {
                if(GetAsyncKeyState(VK_LBUTTON))
                {
                    if(mouseClickControlFlag)
                    {
                        mouseClickControlFlag=0;
                        cleardevice();
                        goto b;
                    }
                }
                else
                {
                    mouseClickControlFlag=1;
                }
            }
        }
    }
    getchar();
    return 0;
}
