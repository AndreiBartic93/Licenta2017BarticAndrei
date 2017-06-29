package gui;

import java.awt.Color;

import javax.swing.BorderFactory;
import javax.swing.JPanel;

import pc_ArduinoComm.SendCommand;

public class MainPanelGenerator {
	
	private JPanel mainPanel;
	private ButtonGenerator buttonGenerator;
	SettingsPanel settingsPanel;// = new SettingsPanel(mainPanel,sendCommand);
	EnvironmentDataPanel environmentPanel;
	private SendCommand sendcommand;
	
	public MainPanelGenerator(SendCommand sendCommand){
		this.sendcommand = sendCommand;
		this.mainPanel = new JPanel();
		this.buttonGenerator = new ButtonGenerator(sendCommand);
		this.environmentPanel = new EnvironmentDataPanel(mainPanel,sendCommand);
		this.settingsPanel = new SettingsPanel(mainPanel,sendCommand);
		mainPanel.setLayout(null);
		mainPanel.setVisible(true);
	}
	
	public JPanel createMainPanel(){
		this.mainPanel.add(buttonGenerator.doGearOne());
		this.mainPanel.add(buttonGenerator.doGearTwo());
		this.mainPanel.add(buttonGenerator.doGearThree());
		this.mainPanel.add(buttonGenerator.doGearFour());
		this.mainPanel.add(buttonGenerator.doGearFive());
		this.mainPanel.add(buttonGenerator.doGearSix());
		this.mainPanel.add(buttonGenerator.doForwardButton());
		this.mainPanel.add(buttonGenerator.doBackwardButton());
		this.mainPanel.add(buttonGenerator.doLeftButton());
		this.mainPanel.add(buttonGenerator.doRightButton());
		this.mainPanel.add(buttonGenerator.doManualButton());
		this.mainPanel.add(buttonGenerator.doAutoButton());
		this.mainPanel.add(buttonGenerator.doLowBeamButton());
		this.mainPanel.add(buttonGenerator.doHighBeamButton());
		this.mainPanel.add(buttonGenerator.doCloseLights()
				);
		settingsPanel.doPortList();
	environmentPanel.doEnvironmentData();
		return mainPanel;
	}
	
	
}