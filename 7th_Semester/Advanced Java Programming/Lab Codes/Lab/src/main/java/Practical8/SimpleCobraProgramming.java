package Practical8;

import org.apache.commons.cli.*;

public class SimpleCobraProgramming {
    public static void main(String[] args) {
        // Create Options object to define the command-line options
        Options options = new Options();

        // Define options (flags)
        options.addOption("h", "help", false, "Show help");
        options.addOption("v", "version", false, "Show version");
        options.addOption("n", "name", true, "Your name");

        // Create a parser to parse the command-line arguments
        CommandLineParser parser = new DefaultParser();
        HelpFormatter formatter = new HelpFormatter();

        try {
            // Parse the command-line arguments
            CommandLine cmd = parser.parse(options, args);

            // If help option is present, print usage information
            if (cmd.hasOption("h")) {
                formatter.printHelp("CobraDemo", options);
                return;
            }

            // If version option is present, print version
            if (cmd.hasOption("v")) {
                System.out.println("CobraDemo version 1.0");
                return;
            }

            // If name option is provided, print greeting message
            if (cmd.hasOption("n")) {
                String name = cmd.getOptionValue("n");
                System.out.println("Hello, " + name + "!");
            } else {
                System.out.println("Use -n option to provide your name.");
            }

        } catch (ParseException e) {
            System.out.println("Error parsing arguments: " + e.getMessage());
            formatter.printHelp("CobraDemo", options);
        }
    }
}
