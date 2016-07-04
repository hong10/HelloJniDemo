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
        	 //1.获取 DataProvider的字节码
			Class clazz = getClassLoader().loadClass("cn.itcast.ndk4.DataProvider");
			//2.获取里面的方法
			Method method = clazz.getDeclaredMethod("helloFromJava", new Class[]{});
			//3.调用这个方法
			method.invoke(clazz.newInstance(), new Object[]{});
			
		} catch (Exception e) {
			e.printStackTrace();
		}*/
        
    }
    /**
     * 开放了一个java方法,c代码可以使用这个java方法,在界面上显示一个土司.
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