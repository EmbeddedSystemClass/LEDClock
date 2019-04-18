package wieczorek.jakub.spectral_clock_app;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;

import wieczorek.jakub.spectral_clock_app.service.BTHandler;

public class MainActivity extends AppCompatActivity
{
    private Button onyksButton;
    private Button clockButton;
    private Button angleButton;

    private Button connectButton;
    private Button disconnectButton;

    private BTHandler bluetooth;
    private View.OnClickListener onClickListener;

    @Override
    protected void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        bluetooth = new BTHandler(this.getApplicationContext());


        initButtons();
        createOnClickListener();
        linkListenerToButtons();
    }

    private void linkListenerToButtons()
    {
        onyksButton.setOnClickListener(onClickListener);
        clockButton.setOnClickListener(onClickListener);
        angleButton.setOnClickListener(onClickListener);

        connectButton.setOnClickListener(onClickListener);
        disconnectButton.setOnClickListener(onClickListener);
    }

    private void initButtons()
    {
        onyksButton = findViewById(R.id.onyksButton);
        clockButton = findViewById(R.id.clockButton);
        angleButton = findViewById(R.id.angleButton);

        connectButton = findViewById(R.id.connectButton);
        disconnectButton = findViewById(R.id.disconnectButton);

        enablePictureButtons(false);
        enableConnect(true);
    }

    private Boolean connect()
    {
        connectButton.setEnabled(false); // cannot disable i dont know why
        Boolean isConnected = bluetooth.BTconnect();
        connectButton.setEnabled(true);

        return isConnected;
    }

    private void createOnClickListener()
    {
        this.onClickListener = new View.OnClickListener()
        {
            @Override
            public void onClick(View aView)
            {
                switch(aView.getId())
                {
                    case R.id.connectButton:
                    {
                        Boolean isConnected = connect();

                        if(isConnected)
                        {
                            enablePictureButtons(isConnected);
                            enableConnect(false);
                        }

                        break;
                    }
                    case R.id.disconnectButton:
                    {
                        Boolean isConnected = bluetooth.BTdisconnect();
                        if(!isConnected)
                        {
                            enablePictureButtons(isConnected);
                            enableConnect(true);
                        }

                        break;
                    }
                    case R.id.clockButton:
                    {
                        bluetooth.SendData("B");

                        break;
                    }
                    case R.id.angleButton:
                    {
                        bluetooth.SendData("A");

                        break;
                    }
                    case R.id.onyksButton:
                    {
                        bluetooth.SendData("C");

                        break;
                    }
                }
            }
        };
    }


    public void enableConnect(boolean aEnable)
    {
        connectButton.setEnabled(aEnable);
        disconnectButton.setEnabled(!aEnable);
    }

    public void enablePictureButtons(boolean aEnable)
    {
        onyksButton.setEnabled(aEnable);
        clockButton.setEnabled(aEnable);
        angleButton.setEnabled(aEnable);
    }
}
