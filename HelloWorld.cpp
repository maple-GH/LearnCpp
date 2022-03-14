#include <iostream>
#include <iomanip>

using namespace std;

class Box
{
	public:							//公共成员
		const int boxId;
		void setBox();
		void printBox();
		double getBoxArea();
		Box(int id, int len, float wid, float hei);		//构造函数，创建对象时自动调用
		Box();						//函数重载，函数名相同但传参不同 (一个函数名可以有多种用途)
		~Box();						//析构函数，销毁对象时自动调用 (无传参，不能被重载)

	protected:						//受保护成员
		int length;
		float width;
		float heigth;

	private:						//私有成员
};

Box::Box(int id, int len=0, float wid=0, float hei=0):boxId(id)		//构造函数1
{
	length = len;
	width = wid;
	heigth = hei;
	cout << "Box" << boxId << " is being created" << endl;
}

Box::Box():boxId(0)					//构造函数2 (初始化 const 成员变量'boxId'的唯一方法就是使用初始化列表)
{
	//boxId = 0;	//Error: boxId (const int) is read-only
	cout << "Box" << boxId << " is being created" << endl;
}

Box::~Box()							//析构函数
{
	cout << "Box" << boxId << " is being deleted" << endl;
}

void Box::setBox()
{
	cout << "\t Please input Box" << boxId << "'s length(int) & width(float) & heigth(float):";
	cin >> length >> width >> heigth;
}

void Box::printBox()
{
	if(0 == boxId)
	{
		cout << "\t box is not init" << endl;
	}
	else
	{
		cout << "\t length:" << length << "\t width:" << width << "\t heigth:" << heigth << endl;
	}
}

inline double Box::getBoxArea()		//内联函数，编译时将函数调用处用函数体替换(类似C语言中的宏展开)
{
	return (length*width*heigth);
}

void TestBox()
{
	Box box1(1, 1, 1.23);			//创建时调用构造函数1 'heigth'未传参时，参数使用默认值
	Box *ptrbox = new Box(2, 2, 2.1, 2.2);		//动态分配内存(堆区)，并使用构造函数1初始化
	Box boxnull;					//创建时调用构造函数2
	double BoxArea = 0;
	string PrintBoxArea = "box area";

	cout << "start TestBox" << endl;

	cout << "box" << box1.boxId << " init state" << endl;
	box1.printBox();
	box1.setBox();
	//cout << "box1's length:" << box1.length << endl;	//Error: Box.length is protected
	box1.printBox();
	BoxArea = box1.getBoxArea();
	cout.setf(ios::fixed);			//设置小数点输出精度(默认6位有效数字)
	cout << "\t box area:" << BoxArea << endl;
	cout.unsetf(ios::fixed);		//取消小数点后输出精度

	cout << "box" << ptrbox->boxId << " init state" << endl;	
	ptrbox->printBox();
	BoxArea = ptrbox->getBoxArea();
	cout << "\t " << PrintBoxArea <<":" << BoxArea << endl;
	delete ptrbox;					//释放动态分配的内存

	boxnull.printBox();

	cout << "end TestBox" << endl;
}

int main()
{
	cout << "Hello, World!" << endl;

	TestBox();

	return 0;
}
