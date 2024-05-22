import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;
import java.util.Scanner;

// the most concerns are the same as for C++ - we can intrduce piixel class and Image class and rework code to have  better isolatiion and encapsulation
public class main{

    // Function to process the input file and generate the output file
    public static void processFile(String inputFileName, String outputFileName, int[] favoriteColor, int[] unfavoriteColor) {
        try (BufferedReader inputFile = new BufferedReader(new FileReader(inputFileName));
             BufferedWriter outputFile = new BufferedWriter(new FileWriter(outputFileName))) {

            String line;
            while ((line = inputFile.readLine()) != null) {
                String[] pixels = line.trim().split(" ");
                for (String pixel : pixels) {
                    int[] rgb = Arrays.stream(pixel.split(",")).mapToInt(Integer::parseInt).toArray();
                    if (Arrays.equals(rgb, unfavoriteColor)) {
                        rgb = favoriteColor;
                    }
                    outputFile.write(Arrays.toString(rgb).replaceAll("\\[|\\]|\\s", "") + " ");
                }
                outputFile.newLine();
            }
            System.out.println("Output file generated successfully: " + outputFileName);
        } catch (IOException e) {
            System.err.println("Error: " + e.getMessage());
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter input file name: ");
        String inputFileName = scanner.nextLine();

        System.out.print("Enter favorite color (R G B): ");
        int[] favoriteColor = Arrays.stream(scanner.nextLine().split(" ")).mapToInt(Integer::parseInt).toArray();

        System.out.print("Enter output file name: ");
        String outputFileName = scanner.nextLine();

        System.out.print("Enter unfavorite color (optional, R G B): ");
        int[] unfavoriteColor = null;
        String unfavColorInput = scanner.nextLine();
        if (!unfavColorInput.isEmpty()) {
            unfavoriteColor = Arrays.stream(unfavColorInput.split(" ")).mapToInt(Integer::parseInt).toArray();
        }

        processFile(inputFileName, outputFileName, favoriteColor, unfavoriteColor);

        scanner.close();
    }
}
