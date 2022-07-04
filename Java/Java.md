# 一、基础环境

2022.1最新专业版本；

官网下载：https://www.jetbrains.com/idea/

安装：勾选桌面快捷（Create Desktop Shortcut）, Add bin path, .java;

激活：**（省略）

创建新项目：jdk直接down; 创建包；创建类。

参考：https://blog.csdn.net/qq_46921028/article/details/124209921

# 二、基础知识

### 1、基础知识

1、命名规范：包名小写，类名首字母大写；

2、浅拷贝，深拷贝：浅拷贝的数字值会随着原来数组变化发生变化，因为两个数组都引用的同一个数组对象；深拷贝，需要源数组和目标数组引用不同的对象，需要new一个新的对象申请内存空间。多维数组每一维都需要分配空间。

```java
int[][] source = {{1, 2, 3, 4}, {5, 6},{0, 2, 42, -4, 5}};
int[][] destination = new int[source.length][];
for (int i = 0; i < destination.length; ++i) {
// allocating space for each row of destination array
	destination[i] = new int[source[i].length];
	for (int j = 0; j < destination[i].length; ++j) 	{
	destination[i][j] = source[i][j];
	}
}
```

3、public, protected, private: public 可以在类外访问，private只能在类中访问，对于声明的private变量在类外访问的方法就是在声明private的类中写public set/get方法，类外通过set/get方法赋值和访问。protected 可在子类中访问。

3、关键字final: 被关键字修饰的变量和方法、类：变量只能赋值一次，方法不能被覆盖（子类），类不能被继承。

4、this关键字：指向当前对象，可访问所有成员变量和成员函数；实际上可理解为成员函数的一个形参(隐式)，在调用时将对象地址作为实参传递给this.

5、static, 不管有没有创建对象，都可访问静态成员函数，普通成员函数只能在创建对象后通过对象来调用。

由public static final 修饰的成员变量--叫做全局常量，一般用于放一些系统的公共参数配置，或者人类社会的公约参数

 *   局部变量：一旦赋值以后就不能更改了。

6、构造函数：重要功能**对成员变量初始化**；**public属性**，这样才有意义，创建对象时候才能调用；**强制性**，一旦类中定义了构造函数，创建对象就一定要调用。

7、继承：@Override  检查方法重写

 			super：调用父类变量和方法，默认调用构造函数（有参构造函数就必须显示调用）；

​			继承重写：1、final/ static 不能被重写； 2、抽象方法必须被重写

​			权限问题：子类 权限 >= 父类

​			abstract: 1、抽象方法的类必须是抽象类； 2、抽象类是不能创建对象（实例化），子类必须要实现抽象方法，否则也需定义为抽象类； 3、可以使用抽象类的引用来访问抽象类的静态属性和方法(static属性)。

​			interface: 1、类似于抽象类，包含一组抽象方法（也可有实现的方法，必须加关键字default, 表默认防范）； 2、实现java的多继承； 3、变量：默认 public static final 方法：public

​			多态：1、类继承、接口（方法重写）；重载；   **？？？基类可以全方位访问派生类的变量、方法。**

```java

/**Java 实现多态有 3 个必要条件：继承、重写和向上转型。
继承：在多态中必须存在有继承关系的子类和父类。
重写：子类对父类中某些方法进行重新定义，在调用这些方法时就会调用子类的方法。
向上转型：在多态中需要将子类的引用赋给父类对象，只有这样该引用才既能可以调用父类的方法，又能调用子类的方法。
**/
package helloworld;

class A {
    A(){
        System.out.println("######A struct");
    }
    public String show(D obj) {
        System.out.println("######A and D");
        return ("A and D");
    }
    public String show(A obj) {
        System.out.println("########A and A");
        return ("A and A");
    }
}
class B extends A{
    B(){
        System.out.println("######B struct");
    }
    public String show(B obj) {
        System.out.println("#########B and B");
        return ("B and B");
    }
    @Override
    public String show(A obj) {
        System.out.println("###########B and A");
        return ("B and A");
    }
}

class C extends B{

    public String show(B obj) {
        System.out.println("&&&&&&&&c and B");
        return ("c and B");
    }
    C(){
        System.out.println("######C struct");
    }

}
class D extends B{
    D(){
        System.out.println("######D struct");
    }

}

public class JavaOop {
    public static void main(String[] args) {
        A a1 = new A();  // 声明A类变量 a1, 指向A类对象  //向上转型：将子类的引用赋给父类对象，
        System.out.println("111111111");
        A a2 = new B();  // 声明A类变量 a2, 指向B类对象
        System.out.println("222222222");
        B b = new B();   // 声明B类变量 b, 指向B类对象
        System.out.println("33333333");
        C c = new C();   // 声C类变量 c, 指向c类对象
        System.out.println("444444444");
        D d = new D();

        System.out.println(a1.show(b));// "A and A"   //父类方法
        System.out.println(a1.show(c));// "A and A"    // 父类方法
        System.out.println(a1.show(d));// "A and D"    // 重载

        System.out.println(a2.show(b));//  B and A     //A 子类重写，调用重写方法
        System.out.println(a2.show(c));//  B and A    //A 子类重写，调用重写方法
        System.out.println(a2.show(d));// "A and D    //调用父类方法，因为子类没有重写覆盖

        System.out.println(b.show(b));// "B and B"   // 调用B 类新方法
        System.out.println(b.show(c));// "B and B"    // C继承B
        System.out.println(b.show(d));// "A and D"    // 继承 show(D ong)

    }
}
```

​			封装：类； 数据隐藏：权限

​			匿名内部类；代码块；枚举；

8、API使用技巧：









