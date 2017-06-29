package gui;

import java.awt.Color;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.BorderFactory;
import javax.swing.JButton;
import javax.swing.JComboBox;
import javax.swing.JLabel;
import javax.swing.JPanel;

import pc_ArduinoComm.SendCommand;

public class SettingsPanel {
	
	private JPanel settingsPanel;
	private JComboBox portList;
	private JLabel portListTitle;
	private JLabel portListResult;
	private JButton submitPort;
	private String choosenPort=null;
	private SendCommand sendCommand;
	private JPanel panel;
	public SettingsPanel(JPanel panel, SendCommand sendCommand){
		this.sendCommand = sendCommand;
		this.panel = panel;
	}

	public void doPortList(){
		//TODO: CONSOLE
		this.portListTitle = new JLabel("Port:");
		this.portListResult = new JLabel();
		this.submitPort = new JButton("Connect");
		String[] ports = sendCommand.listPorts();
		this.portList = new JComboBox(ports);
		portList.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent e){
		    	choosenPort = (String)portList.getSelectedItem();
		    }
		});
		
		submitPort.addActionListener(new ActionListener() { 
            public void actionPerformed(ActionEvent e){
                if(!choosenPort.equals(null)){
                	if(sendCommand.init(choosenPort)){
                		portListResult.setText("You are connected on: "+choosenPort);
                	}else{
                		portListResult.setText("Connection fail");
                	}
                }
            }
        });
		
		portListTitle.setBounds(10, 10, 30, 20);
		submitPort.setBounds(130, 10, 100, 20);
		portList.setBounds(50, 10, 70, 20);
		//portListResult.setBounds(x, y, width, height);
		panel.add(portListTitle);
		panel.add(portList);
		panel.add(submitPort);
	}
	
}