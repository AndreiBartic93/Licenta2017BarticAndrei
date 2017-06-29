package pc_ArduinoComm;


import java.util.Scanner;
import java.io.*;
import java.util.*;
import jssc.*;




public class SendCommand {
	
	private static SerialPort serialPort;
	private static Scanner scan = new Scanner(System.in);
	
	private static final String PORT_NAMES[] = { 
	        "COM1",
	        "COM2",
			"COM3",
			"COM4",
	        "COM5",
	        "COM6",
	        "COM7",
	        "COM8",
	        "COM9",
	        "COM10"
	};
	
	public String[] listPorts(){
		
		String[] portNames = SerialPortList.getPortNames();
		if(portNames.length == 0){
			System.out.println("No ports Available");
		//	System.exit(0);
		}
		System.out.println("Available ports:");
		for(int i = 0;i<portNames.length;i++){
			System.out.println(portNames[i]);
		}
		return portNames;
	}
	
	public boolean init(String portName){
		this.serialPort = new SerialPort(portName);
		try{
			serialPort.openPort();
			serialPort.setParams(SerialPort.BAUDRATE_9600,
                    SerialPort.DATABITS_8,
                    SerialPort.STOPBITS_1,
                    SerialPort.PARITY_NONE);
			serialPort.setFlowControlMode(SerialPort.FLOWCONTROL_RTSCTS_IN | 
                    SerialPort.FLOWCONTROL_RTSCTS_OUT);
			return true;
		}catch(SerialPortException ex){
			 System.out.println("Error in writing data to port: " + ex.getMessage());
		}
		return false;
	}
	
	public boolean writeCommand(String command) throws SerialPortException{
		return serialPort.writeString(command);
	}
	
	public byte[] readSerial() throws SerialPortException{
			return serialPort.readBytes();
		
	}
	
//	public static void main(String[] args) throws SerialPortException{
//		SendCommand t = new SendCommand();
//		byte command;
//		if(t.init()){
//			while(true){
//				System.out.println("Command: ");
//				command = scan.nextByte();
//				t.writeCommand(command);
//			}
//		}
//	}

	
}