package com.hong.hellojnidemo;

/**
 * Created by hong on 2016/7/4.
 */

public class CcallbackJavaMethod {


    public void helloFromJava() {
        System.out.println("I am java method");
    }


    public int add(int x, int y) {
        return x + y;
    }

    public void printString(String s) {
        System.out.println("s=" + s);
    }

    public native void callMethod1();
    public native void callMethod2();
    public native void callMethod3();
    public native void callMethod4();

}
