package pc_ArduinoComm;

import jssc.SerialPort;
import jssc.SerialPortList;
import jssc.SerialPortException;

public class ReceivedData {

	// Declare Special Symbol Used in Serial Data Stream from Arduino
	final static String start_char = "@";
	final static String end_char = "#";
	final static String sep_char = ":";

	public static void main(String[] args) throws InterruptedException {

		// Display Available Ports -- ideas: let user choose?
		String[] portList = SerialPortList.getPortNames();
		for (int i = 0; i < portList.length; i++)
			System.out.println(portList[i]);

		// Define Serial Port # -- can be found in Device Manager or Arduino IDE
		SerialPort serialPort = new SerialPort("COM5");
		try {

			// Open Serial Port
			serialPort.openPort();

			// Define Parameter -- can be found in Device Manager
			// baudRate, iataBits, stopBits, parity
			serialPort.setParams(9600, 8, 1, 0);

			byte[] buffer;

			// Filter out bad data from Arduino initialization
			buffer = serialPort.readBytes(200);

			// Retrieve data from Arduino -- read 100 bytes
			buffer = serialPort.readBytes(100);
			for(int i=0;i<buffer.length;i++){
				System.out.println(buffer[i]);
			}
			// Convert bytes into String
			//String dataStream = new String(buffer);

			// Isolate Data Stream using symbols defined earlier
			//dataStream = dataStream.substring(dataStream.indexOf(start_char) + 1);
			//dataStream = dataStream.substring(0, dataStream.indexOf(end_char) - 1);

			// Retrieve data sent by Arduino in form of Strings
		//String[] data = dataStream.split(sep_char);

			// Display obtained data
//			for (int i = 0; i < data.length; i++)
//				System.out.println(data[i]);

		} catch (SerialPortException ex) {

			// Display Errors
			System.out.println(ex);

		}
	}
}