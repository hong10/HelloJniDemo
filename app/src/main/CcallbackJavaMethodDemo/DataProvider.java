package cn.itcast.ndk4;

public class DataProvider {

	// C����java�շ���
	public void helloFromJava() {
		System.out.println("����java�Ŀշ���");
	}

	// C����java�еĴ�����int�����ķ���
	public int Add(int x, int y) {
		return x+y;
	}

	// C����java�в���Ϊstring�ķ���
	public void printString(String s) {
		System.out.println("s="+s);
	}
	
	
	public native void callmethod1();
	public native void callmethod2();
	public native void callmethod3();
	
	public native void callmethod4();
}
