package useful;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Scanner;

public class ReadCSVFile {
	private final String path = "C:\\Users\\Bartic\\Desktop\\Licenta2017\\Licenta\\FinalApp\\CarControl\\files\\fieldData.csv";
	private ArrayList<String> csvResults = new ArrayList<String>();
	private Scanner scanner;
	
	public ReadCSVFile(){
		try {
			this.scanner = new Scanner(new File(this.path));
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} 
	}
	
	public ArrayList<String> getFieldData(){
        this.scanner.useDelimiter(",");
        while (scanner.hasNext()) 
        {
        	csvResults.add(scanner.next());
        }
        scanner.close();
        return csvResults;
	}
}
