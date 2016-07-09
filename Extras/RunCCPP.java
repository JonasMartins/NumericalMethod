import java.io.BufferedReader;
import java.io.InputStreamReader;

public class RunCCPP {
	
	public static String resultString;

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		//String compileFileCommand = "javac "+fileName;

		/**
		 * 	// Exemplo de test usando java....
		 *	compileJavaFile("Test.java"); 
		 *	runJavaFile("Test"); 
		 * 
		 * 	Assim basta rodar essa classe, ou instanciar objetos dela, para rodar
		 * 	os programas em C ou C++, veja que é importante salvar sempre o output em um txt
		 * 	assim como é feito no Householder abaixo, 
		 * 
		 * 	O mesmo vale para aquivos em C, o único trabalho seu agora é ler a saída do txt e colocar
		 * 	na interface do programa de saída, ou só mostrar o arquivo, o importante  que vc
		 * 	agora pode rodar esses programas em c direto do java.
		 * 
		 * */
		

		// Exemlpo rodando o Householder
		compileCPPFile("Householder1.cpp -o Householder1 Householder2.cpp -o Householder2 Main.cpp -o Main");
		runCPPFile("Main Matrix.txt");


		
	}

	static void compileCFile(String fileName) {
		String compileFileCommand = "gcc " + fileName;

		resultString = "";
		try {
			System.out.println("Compiling C File");

			Process processCompile = Runtime.getRuntime().exec(compileFileCommand);

			BufferedReader brCompileError = new BufferedReader(new InputStreamReader(processCompile.getErrorStream()));
			String errorCompile = brCompileError.readLine();
			if (errorCompile != null)
				System.out.println("Error Compiler = " + errorCompile);

			resultString += errorCompile + "\n";

			BufferedReader brCompileRun = new BufferedReader(new InputStreamReader(processCompile.getErrorStream()));
			String outputCompile = brCompileRun.readLine();
			if (outputCompile != null)
				System.out.println("Output Compiler = " + outputCompile);

			resultString += outputCompile + "\n";

		} catch (Exception e) {
			// TODO: handle exception
			System.out.println("Exception ");
			System.out.println(e.getMessage());
		}
	}

	static void runCFile(String fileName) {
		String runFileCommand = "./" + fileName.split(".c")[0];

		try {

			System.out.println("Running C File");

			Process processRun = Runtime.getRuntime().exec(runFileCommand);

			BufferedReader brRun = new BufferedReader(new InputStreamReader(processRun.getErrorStream()));
			String errorRun = brRun.readLine();
			if (errorRun != null)
				System.out.println("Error Run = " + errorRun);

			BufferedReader brResult = new BufferedReader(new InputStreamReader(processRun.getInputStream()));
			String outputRun = brResult.readLine();
			if (outputRun != null)
				System.out.println("Output Run = " + outputRun);

		} catch (Exception e) {
			// TODO: handle exception
			System.out.println("Exception ");
			System.out.println(e.getMessage());
		}
	}

	static void compileCPPFile(String fileName) {
		String compileFileCommand = "g++ " + fileName;
		try {

			System.out.println("Compiling CPP File");

			Process processCompile = Runtime.getRuntime().exec(compileFileCommand);

			BufferedReader brCompileError = new BufferedReader(new InputStreamReader(processCompile.getErrorStream()));
			String errorCompile = brCompileError.readLine();
			if (errorCompile != null)
				System.out.println("Error Compiler = " + errorCompile);

			resultString += errorCompile + "\n";

			BufferedReader brCompileRun = new BufferedReader(new InputStreamReader(processCompile.getErrorStream()));
			String outputCompile = brCompileRun.readLine();
			if (outputCompile != null)
				System.out.println("Output Compiler = " + outputCompile);

			resultString += outputCompile + "\n";

		} catch (Exception e) {
			// TODO: handle exception
			System.out.println("Exception ");
			System.out.println(e.getMessage());
		}
	}

	static void runCPPFile(String fileName) {
		String runFileCommand = "./" + fileName.split(".cpp")[0];

		try {
			System.out.println("Running CPP File");

			Process processRun = Runtime.getRuntime().exec(runFileCommand);

			BufferedReader brRun = new BufferedReader(new InputStreamReader(processRun.getErrorStream()));
			String errorRun = brRun.readLine();
			if (errorRun != null)
				System.out.println("Error Run = " + errorRun);

			BufferedReader brResult = new BufferedReader(new InputStreamReader(processRun.getInputStream()));
			String outputRun = brResult.readLine();
			if (outputRun != null)
				System.out.println("Output Run = " + outputRun);

		} catch (Exception e) {
			// TODO: handle exception
			System.out.println("Exception ");
			System.out.println(e.getMessage());
		}
	}

	static void compileJavaFile(String fileName) {
		String compileFileCommand = "javac " + fileName;
		try {
			System.out.println("Executing Java File");

			Process compileProcess = Runtime.getRuntime().exec(compileFileCommand);

			String line = "";
			BufferedReader bri = new BufferedReader(new InputStreamReader(compileProcess.getInputStream()));
			BufferedReader bre = new BufferedReader(new InputStreamReader(compileProcess.getErrorStream()));
			while ((line = bri.readLine()) != null) {
				System.out.println(line);
			}
			bri.close();
			while ((line = bre.readLine()) != null) {
				System.out.println(line);
			}
			bre.close();
			compileProcess.waitFor();
			System.out.println("Done.");
		} catch (Exception e) {
			// TODO: handle exception
			System.out.println("Exception ");
			System.out.println(e.getMessage());
		}
	}

	static void runJavaFile(String fileName) {
		String runFileCommand = "java " + fileName.split(".java")[0];
		try {
			System.out.println("runFileCommand : " + runFileCommand);
			System.out.println("Running Java File");

			Process runProcess = Runtime.getRuntime().exec(runFileCommand);

			BufferedReader reader = new BufferedReader(new InputStreamReader(runProcess.getInputStream()));
			String line = reader.readLine();
			System.out.println("line = " + line);
			while (line != null) {
				System.out.println(line);
				line = reader.readLine();
			}

		} catch (Exception e) {
			// TODO: handle exception
			System.out.println("Exception ");
			System.out.println(e.getMessage());
		}
	}

}

