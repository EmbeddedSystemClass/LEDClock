package wieczorek.jakub.spectral_clock_app.service;

import android.bluetooth.BluetoothAdapter;
import android.bluetooth.BluetoothDevice;
import android.bluetooth.BluetoothSocket;
import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.widget.Toast;
import android.content.Context;

import java.io.IOException;
import java.io.OutputStream;
import java.util.Set;
import java.util.UUID;

public class BTHandler
{
    private final String DEVICE_ADDRESS = "00:21:13:02:19:CA"; //MAC Address of Bluetooth Module
    private final UUID PORT_UUID = UUID.fromString("00001101-0000-1000-8000-00805f9b34fb");

    private BluetoothDevice device;
    private BluetoothSocket socket;
    private OutputStream outputStream;

    private Context appContext;

    public Boolean isBlueToothConnected;

    public BTHandler(Context aAppContext)
    {
        isBlueToothConnected = false;
        appContext = aAppContext;

        this.BTinit();
    }


    //Initializes bluetooth module
    public boolean BTinit()
    {
        boolean found = false;

        BluetoothAdapter bluetoothAdapter = BluetoothAdapter.getDefaultAdapter();

        if(bluetoothAdapter == null)
        {
            //Checks if the device supports bluetooth
            Toast.makeText(appContext, "Device doesn't support bluetooth", Toast.LENGTH_SHORT).show();
        }

        if(!bluetoothAdapter.isEnabled()) //Checks if bluetooth is enabled. If not, the program will ask permission from the user to enable it
        {
            Intent enableAdapter = new Intent(BluetoothAdapter.ACTION_REQUEST_ENABLE);
            // startActivityForResult(enableAdapter,0);

            try
            {
                Thread.sleep(1000);
            }
            catch(InterruptedException e)
            {
                e.printStackTrace();
            }
        }

        Set<BluetoothDevice> bondedDevices = bluetoothAdapter.getBondedDevices();

        if(bondedDevices.isEmpty()) //Checks for paired bluetooth devices
        {
            Toast.makeText(appContext, "Please pair the device first", Toast.LENGTH_SHORT).show();
        }
        else
        {
            for(BluetoothDevice iterator : bondedDevices)
            {
                if(iterator.getAddress().equals(DEVICE_ADDRESS))
                {
                    device = iterator;
                    found = true;
                    break;
                }
            }
        }

        return found;
    }

    public boolean SendData(String string_data)
    {
        try {
            outputStream.write(string_data.getBytes()); //transmits the value of string_data to the bluetooth module
        }
        catch (IOException e) {
            e.printStackTrace();
            return false;
        }

        return true;
    }

    public void BTTest()
    {
        Toast.makeText(appContext, "Device doesn't support bluetooth", Toast.LENGTH_SHORT).show();
    }

    public boolean BTconnect()
    {
        boolean connected = true;

        try
        {
            socket = device.createRfcommSocketToServiceRecord(PORT_UUID); //Creates a socket to handle the outgoing connection
            socket.connect();

            Toast.makeText(appContext, "Connection successful.", Toast.LENGTH_LONG).show();
        }
        catch(IOException e)
        {
            e.printStackTrace();
            connected = false;
            Toast.makeText(appContext, "Failed to connect!", Toast.LENGTH_LONG).show();
        }

        if(connected)
        {
            try
            {
                outputStream = socket.getOutputStream(); //gets the output stream of the socket
            }
            catch(IOException e)
            {
                e.printStackTrace();
            }
        }

        return connected;
    }

    public boolean BTdisconnect()
    {
        boolean connected = false;

        try
        {
            socket.close();

            Toast.makeText(appContext, "Bluetooth device disconnected", Toast.LENGTH_LONG).show();
        }
        catch(IOException e)
        {
            e.printStackTrace();
            connected = true;
        }

        return connected;
    }
}
