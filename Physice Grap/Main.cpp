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

	Object A(1.5, 0.0, 160);//x,y,����
	Object B(-2, 0.0, 160);

	Star C(0.0, 3.0, 0.7);

	B.set_vel(0.05, 0.35);//�����ٶ�
	A.set_vel(0, -0.5);

	A.set_radius(0.6);
	B.set_radius(0.6);

	C.set_radius(0.4);
	C.set_vel(-1.0, 0.0);
	//Engine��˼�����棬������ȴ�ǵ�����ϵ�����õ�
	//System��ϵͳ���������ǵ������桱���õ�
	//�տ�ʼд��ʱ��û����ô�࣬System�����ݱ�����������Engine��ģ�������

	GravityEngine engine(3000);//��A,B�������ǵ��������������õ����壬���뵽��ϵengine��
	MultiCenteredEngine mc(6000);//�ٰ�����C����������뵽��ϵmc��
	//��ô����Ч������ABֻ��˴����ö�����C�����ã���Cͬʱ�ܵ�AB���ã�ģ���˫����ϵ��Ч��
	//��ʵ�ϲ�����һ���ӼӶ��Engine,����Լ��̳�Engine����µ���
	engine.join(&B);
	engine.join(&A);

	mc.join(&C);
	mc.join_center(&A);
	mc.join_center(&B);

	System Simu(16);//����ϵͳ���������2����ϵ�ӽ�ȥ(16���ǻ���ˢ������(����))
	Simu.Regist(&engine);
	Simu.Regist(&mc);
	Simu.set_scale(50);//����ϵ��
	Simu.set_viewpoint(0.0, -3.0);
	Simu.init(640, 480);
	Simu.begin(exit_function);//exit_function���˳��жϺ�������������trueʱ������ͽ�����
	
	return 0;
}