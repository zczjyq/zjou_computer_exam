# 习题1
## 判断题
(1) Java语言的主要贡献者是James Gosling。 (  )
(2) Java源文件中只能有一个类。(  )
(3) 一个源文件中必须要有public类。(  )
(4) 源文件中如果有多个类，那么至多有一个类可以是public类。(   ) 
(5) Java应用程序必须有主类。(   )
(6) Java应用程序的主类必须是public类。(   )










## 单选题

(3)下列选项中,(  )是正确的。
A. Java源文件由若干个书写形式互相独立的类组成
B. Java源文件中只能有一个类
C. 如果源文件中有多个类，那么至少有一个类必须是public类
D. Java源文件的扩展名是.txt
(4)对于下列源文件，(  )叙述是正确的。
A. 源文件名字必须是A.java
B. 源文件有错误
C. 源文件必须命名为E.java，编译无错误。有两个主类，E和A。
程序可以执行主类E也可以执行主类A
D. 源文件中的E类不是主类
public class E {
    public static void main(String[] args) {
        System.out.println("ok");
        System.out.println("您好");
    }
}
class A {
    public static void main(String[] args) {
        System.out.println("ok");
        System.out.println("您好");
    }
} 


## 答案
- TFFTT FF
- BDACC

# 习题4
## 判断题
(5) 局部变量没有默认值。(   )

## 单选题
(4) 下列叙述正确的是(  )。
A. 成员变量有默认值。
B. this可以出现在static方法中。
C. 类中的实例方法可以用类名调用。
D. 局部变量也可以用访问修饰符public、protected、private修饰。

## 答案
TTTFT TTTFF


DACAD

# 习题5
## 判断题
(1) 子类继承父类的构造方法。(   )
(3) 可以用final修饰构造方法。(   )

## 单选题

## 答案
FTFTF TTTFF
 
DABCD A

# 习题6

## 判断题
(2) static内部类不能操作外嵌类中的实例成员变量。(   )
(3) 非匿名内部类也可以实现接口。(   )
(4) 匿名类的类体中不可以声明static成员变量和static方法。(   )
(5) 匿名类只有一个不带参数的构造方法(编译器会给匿名类一个名字和构造方法)。(   )
(8) static内部类不能操作外嵌类中的实例成员变量。(   ) 
(9) 一个方法在声明时可以使用throw关键字声明要产生的若干个异常。(   )
## 单选题
(2) 下列选项中，(  )是错误的。
A. 非匿名内部类也可以有(内部)子类
B. 内部类不可以是final类
C. 不可能用匿名类声明对象，但可以直接用匿名类创建一个对象
D. 匿名子类(和子类有关的匿名类)可以继承父类的方法，也可以重写父类的方法。
(3) 下列选项中，(  )是错误的。
A. 内部类的外嵌类的成员变量在内部类中仍然有效
B. 内部类中的方法也可以调用外嵌类中的方法
C. 内部类的类体中可以声明类变量(static)
D. 外嵌类的类体中可以用内部类声明对象，作为外嵌类的成员

## 答案
TTTTT FFTFT
ABC
# 习题10
## 判断题
(1) 窗口默认被系统添加到显示器屏幕上，因此不允许将一个窗口添加到其他容器中。(   ) 

## 单选题

(1) 下列选项中,布局(  )是JPanel容器的默认布局。
A. GridLayout
B. BorderLayout
C. CardLayout
D. FlowLayout

## 答案
TFTFT TTTFT
DADBB C
