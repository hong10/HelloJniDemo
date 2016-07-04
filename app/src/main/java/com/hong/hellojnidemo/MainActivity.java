package com.hong.hellojnidemo;

import android.content.Context;
import android.os.Bundle;
import android.support.design.widget.FloatingActionButton;
import android.support.design.widget.Snackbar;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.Toolbar;
import android.view.View;
import android.view.Menu;
import android.view.MenuItem;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {

    public native String helloJni();

    private TransportData transportData;

    static {
        System.loadLibrary("hello");
        System.loadLibrary("transport");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        transportData = new TransportData();

    }

    public void callbackC(View view) {
        Toast.makeText(this, helloJni(), Toast.LENGTH_LONG).show();
    }

    public void CAdd(View view) {
        int result = transportData.add(3, 6);
        toast(this, "result = " + result);
    }

    public void CString(View view) {
        String msg = transportData.sayHelloInC("hong");
        toast(this, msg);
    }

    public void CArray(View view) {
        int[] array = {1, 2, 3, 4, 5};
        transportData.inMethod(array);
        for (int i = 0; i < array.length; i++) {
            System.out.println("java " + array[i]);
        }

    }

    private void toast(Context context, String msg) {
        Toast.makeText(context, msg, Toast.LENGTH_LONG).show();
    }
}
