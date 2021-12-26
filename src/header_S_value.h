
//////////////////////////////共用///////////////////////////////////

#define not -1
#define yes 1
#define no 0

//按鍵//
#define UP 3
#define DOWN 0
#define RIGHT 2
#define LEFT 1
#define SPACE 100
#define TAB 101
//按鍵//

//位置生命與攻擊種類//
#define X 0
#define Y 1
#define life 2
//#define face 3			//目前一個面向
#define category 3		//武器種類->DOG
#define Direction 2		//面向->walk
#define N_Direction 3	//下一個面向->walk
//位置.生命.攻擊種類.方向與下一個方向//
/*
#define ScreenH 480	//螢幕
#define ScreenW 640
*/
//死活//
#define LIVE 1
#define DEAD -1
//死活//

//輸贏//
#define WIN 1
#define LOOSE 0
//輸贏//

//選單用//
#define Main_menu 299
#define Main_menu_choose 44
#define Sub_menu 173
#define Sub_menu_choose 46
//選單用//

//地圖編碼//
#define BigMap 1000

#define CO1 1010
#define CO1_4 1011
#define CO1_4flab 1012
#define CO1_b1 1013

#define CO2 1020
#define BO1 1030
#define BO1_R 1031

#define LO1 1040
#define LO1_2 1041
#define LO1_3 1042
#define principleOffice 1043
#define LO2 1050
#define LO2Class 1051
#define MO1 1060
#define HO1 1070


#define  bigmap	0

#define co1		1
#define co1_4	2
#define co1_4flab	3
#define co1_b1	4
#define co2		5
#define bo1		6
#define bo1_r	7
#define lo1		8
#define lo1_2	9
#define lo1_3	10
#define lo1_principleOffice	11
#define lo2		12
#define lo2Class	13
#define mo1		14
#define ho1		15
//地圖編碼//

//人物編碼//
#define captain 0 //西貝
#define AC 1	//應化
#define AM 2	//應數
#define AP 3	//應物
#define APIBM 4	//亞太
#define CEE 5	//土環
#define CM 6	//化材
#define CS 7	//資工
#define DKHL 8	//運健休
#define ECON 9	//應經
#define EE 10	//電機
#define EFL 11	//財法
#define EL 12	//東語
#define FIM 13	//金管
#define GL 14	//政法
#define IM 15	//資管
#define LAW 16	//法律
#define LS 17	//生科
#define TCCD 18	//傳設
#define WL 19	//西語
#define NoOne 20	//無人
#define PeopleALL 20	//所有人物匯入
//人物編碼//

//事件編碼//
#define EvenCEE1 0	//土環表示西語搬走了
#define EvenTeacher 1	//找老師問西語
#define EvenEL1 2	//幫東語還六法
#define EvenWL 3	//西語加入，往法學院
#define EvenGL 4	//幫忙找政法丟的六法
#define EvenLAW1 5	//法律加入，找資工
#define EvenCS1 6	//幫資工找燈
#define EvenCS2 7	//財法出現
#define EvenEFL 8	//書給財法
#define EvenECON_FIM 9	//應經與金管事件
#define EvenEFL_GL 10	//財政法，回禮
#define EvenLO2 11	//離開法院
#define EvenEL2 12	//回禮
#define EvenTCCD1 13	//幫傳設採花
#define EvenHANA 14	//摘花與化材
#define EvenOffice 15	//警衛室與西語離開
#define EvenLAW2 16	//法律離開
#define EvenAPIBM1 17 	//幫亞太找衛星導航
#define EvenAPIBM2 18 	//還衛星導航給亞太
#define EvenDKHL1 19 	//運健休加入
#define EvenDKHL 20 	//運健休篇
#define EvenCEE2 21 	//幫土環去理學院拿殺蟲劑
#define EvenAM1 22 	//幫應數找應物拿計算機，應化出現
#define EvenAC1 23 	//找應物拿殺蟲劑，應物出現
#define EvenAP1 24 	//幫應物拿回飛行器，應化消失
#define EvenLS1 25 	//生科加入，找小雞與飛行器
#define EvenLS2 26 	//生科離開
#define EvenAP2 27 	//飛行器還給應物，得到計算機
#define EvenAM2 28 	//計算機還給應數，應化出現
#define EvenAC2 29 	//得到殺蟲劑
#define EvenCEE3 30 	//殺蟲劑給土環，亞太表示校長找，電機離開
#define EvenIM1 31 	//幫資管找亞太拿衛星導航
#define EvenAPIBM4 32 	//和亞太拿衛星導航
#define EvenIM2 33 	//拿衛星導航給資管

#define EvenThingsToCS 34 	//拿到資工的燈
#define EvenThingsForGL 35 	//拿到政法的書
#define EvenLO1 36 	//圖資進不去
#define EvenThingsToAPIBM 37 	//拿到亞太的衛星導航
#define EvenCSToThings 38 	//可以開始幫資工找燈
#define END_OF_STORY 39		//結局

#define EvenALL 40	//全部

//事件編碼//

//////////////////////////////共用///////////////////////////////////

int close_button_pressed;
