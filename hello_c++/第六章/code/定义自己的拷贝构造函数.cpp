#include <iostream>
#include <fstream>
using namespace std;

// 键盘类，因为结构简单，我们使用 struct 来定义
struct Keyboard
{
 // 键盘的型号
 string m_strModel;
};


// 定义了拷贝构造函数的电脑类
class Computer
{
   public:
      // 默认构造函数
      Computer(): m_pKeyboard(nullptr),m_strModel("")
      {}
      // 拷贝构造函数，参数是 const 修饰的 Computer 类的引用

      Computer(const Computer& com): m_strModel(com.m_strModel) 
      // 直接使用初始化属性列表完成对象类型成员变量m_strModel 的复制
      {
         // 创建新对象，完成指针类型成员变量 m_pKeyboard 的复制
         // 获得已有对象 com 的指针类型成员变量 m_pKeyboard
         Keyboard* pOldKeyboard = com.GetKeyboard();
         // 以 pOldKeyboard 所指向的 Keyboard 对象为蓝本，
         // 创建一个新的 Keyboard 对象，并让 m_Keyboard 指向这个对象
         if( nullptr != pOldKeyboard )
         // 这里 Keyboard 对象的复制使用的是 Keyboard 类的默认拷贝构造函数
         m_pKeyboard = new Keyboard(*(pOldKeyboard));
         else
         m_pKeyboard = nullptr; // 如果没有键盘
      }
      // 析构函数，
      // 对于对象类型的成员变量 m_strModel，会被自动销毁，无需在析构函数中进行处理
      // 对于指针类型的成员变量 m_pKeyboard，则需要在析构函数中主动销毁
      ~Computer()
      {
         delete m_pKeyboard;
         m_pKeyboard = nullptr;
      }
         // 成员函数，设置或获得键盘对象指针
      void SetKeyboard(Keyboard* pKeyboard)
      {
         m_pKeyboard = pKeyboard;
      }
      Keyboard* GetKeyboard() const
      {
         return m_pKeyboard;
      }
   private:
      // 指针类型的成员变量
      Keyboard* m_pKeyboard;
      // 对象类型的成员变量
      string m_strModel;
};