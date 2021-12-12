#define WIDE /*20*/	15						//宽
#define LONG /*100*/50					//长

#define REFRESHTIME 250					//单位：ms地图刷新时间，与蛇的(初始)移动速度成正比


#define FOOD_PROBALITY 5				//食物产生几率（倒数）



#define OBSTACLE_NUM 15					//障碍数量上限	
#define OBSTACLE_PROBALITY 10			//障碍产生几率（倒数）
#define OBSTACLE_TIME 8					//障碍提醒时间
#define OBSTACLE_DISTANCE_TIME 30		//障碍产生时间间隔

#define OBSTACLE_EXTEND true			//障碍是否延伸	
#define OBSTACLE_EXTEND_POSSIBILITY	2	//障碍延伸的几率（倒数）	
#define OBSTACLE_EXTEND_TIME 5			//障碍每次延伸判定时间（正相关）	
#define OBSTACLE_EXTEND_DISTANCE 2		//障碍延伸距离最大值，0为无限制
//以下都不支持中文字符
#define HEAD 'o'						//自定义蛇的头
#define BODY 'O'						//自定义蛇的身体
#define _FOOD 'G'						//自定义食物
#define OBSTACLE 'X'					//自定义障碍图标

#define _SPEED true						//是否速度自增
#define ALL_LEVEL 50					//速度分级（不改变区间，只改变分级详细度）
#define WHOLETIME 60000					//单位：ms达到对大速度的大约时间(偏高）
#define MINUS 30						//与速度最大值成反比，过低会卡死（最好大于WAITTIME）	
#define WAITTIME 5						//单位：ms键盘监视器刷新时间，影响丝滑度