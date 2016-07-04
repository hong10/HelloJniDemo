package cn.itcast.ndk4;

public class DataProvider {

	// C调用java空方法
	public void helloFromJava() {
		System.out.println("我是java的空方法");
	}

	// C调用java中的带两个int参数的方法
	public int Add(int x, int y) {
		return x+y;
	}

	// C调用java中参数为string的方法
	public void printString(String s) {
		System.out.println("s="+s);
	}
	
	
	public native void callmethod1();
	public native void callmethod2();
	public native void callmethod3();
	
	public native void callmethod4();
}
