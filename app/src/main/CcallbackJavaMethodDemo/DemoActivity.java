package cn.itcast.ndk4;

import java.lang.reflect.Method;

import android.app.Activity;
import android.content.Context;
import android.os.Bundle;
import android.view.View;
import android.widget.Toast;

public class DemoActivity extends Activity {
	static{
		System.loadLibrary("Hello");
	}
	private DataProvider dp;
	
	public native void callDemoActivitMethod();
	
	public native void callDemoActivitMethod2();
	public void methodInDemoActivity(){
		System.out.println("methodInDemoActivity");
	}
	
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.main);
        dp = new DataProvider();
       
     /*   try {
        	 //1.��ȡ DataProvider���ֽ���
			Class clazz = getClassLoader().loadClass("cn.itcast.ndk4.DataProvider");
			//2.��ȡ����ķ���
			Method method = clazz.getDeclaredMethod("helloFromJava", new Class[]{});
			//3.�����������
			method.invoke(clazz.newInstance(), new Object[]{});
			
		} catch (Exception e) {
			e.printStackTrace();
		}*/
        
    }
    /**
     * ������һ��java����,c�������ʹ�����java����,�ڽ�������ʾһ����˾.
     * @param message
     */
    public static void showToast(Context context,String message){
    	Toast.makeText(context, message, 0).show();
    }
    
    
    public void click1(View view){
    	dp.callmethod1();
    }
    
    public void click2(View view){
    	dp.callmethod2();
    }
    
    public void click3(View view){
    	dp.callmethod3();
    }
    public void click4(View view){
    	dp.callmethod4();
    }
    
    public void click5(View view){
    	callDemoActivitMethod();
    }
    
    public void click6(View view){
    	callDemoActivitMethod2();
    }
}