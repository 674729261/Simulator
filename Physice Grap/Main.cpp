#include "myEngine.h"
#include "Object.h"
#include "Vector2.h"
#include "myObject.h"
#include "System.h"
/*
Shitful
2292683261QQ
*/

inline bool exit_function()
{
	return false;
}

int main(void)
{
	/*
	Object test(2.0, 0.0, 1.0);
	FixedObj center(0.0, 0.0, 3.0);
	FixedObj center2(-1.0, -3.0, 3.0);
	test.set_vel(0.0, 1.0);
	MultiCenteredEngine eng(640, 480, 20, 6000);
	eng.join(&test);
	eng.join_center(&center);
	eng.join_center(&center2);
	eng.set_scale(40);
	eng.init();
	eng.begin(exit_function);
	*/

	Object A(1.5, 0.0, 160);//x,y,质量
	Object B(-2, 0.0, 160);

	Star C(0.0, 3.0, 0.7);

	B.set_vel(0.05, 0.35);//给定速度
	A.set_vel(0, -0.5);

	A.set_radius(0.6);
	B.set_radius(0.6);

	C.set_radius(0.4);
	C.set_vel(-1.0, 0.0);
	//Engine意思是引擎，程序里却是当“体系”来用的
	//System是系统，程序里是当“引擎”来用的
	//刚开始写的时候没想那么多，System的内容本来是整合在Engine里的（捂脸）

	GravityEngine engine(3000);//把A,B两个恒星当作两个互相作用的物体，加入到体系engine中
	MultiCenteredEngine mc(6000);//再把行星C视作物体加入到体系mc中
	//这么做的效果就是AB只会彼此作用而不受C的作用，而C同时受到AB作用，模拟出双星星系的效果
	//事实上不鼓励一下子加多个Engine,最好自己继承Engine搞个新的类
	engine.join(&B);
	engine.join(&A);

	mc.join(&C);
	mc.join_center(&A);
	mc.join_center(&B);

	System Simu(16);//创建系统，把上面的2个体系加进去(16的是画面刷新周期(毫秒))
	Simu.Regist(&engine);
	Simu.Regist(&mc);
	Simu.set_scale(50);//缩放系数
	Simu.set_viewpoint(0.0, -3.0);
	Simu.init(640, 480);
	Simu.begin(exit_function);//exit_function是退出判断函数，当它返回true时，程序就结束了
	
	return 0;
}