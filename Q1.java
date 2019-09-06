import java.util.Scanner;

class Q1 {
    // native method
    public native void calcDiloma(double cgpa);
    public native void calcDegree(double cgpa);

    // load library
    static {
        System.loadLibrary("CQ1");
    }

    public static void main(String[] args) {
        // initiate Q1 instance
        Q1 q1 = new Q1();

        // initiate Scanner instance
        Scanner scanner = new Scanner(System.in);
        System.out.printf("Please select which programme: \n");
        System.out.printf("\t1 - Diploma\n");
        System.out.printf("\t2 - Degree\n");
        System.out.printf("\nYour Input: ");

        // declare choice variable
        int choice = scanner.nextInt();

        if (choice == 1) { // Diploma
            System.out.printf("\n==========\n");
            System.out.printf("\n  Diploma \n");
            System.out.printf("\n==========\n");
            System.out.printf("\nPlease input your CGPA: ");
            // declare and assign input cgpa
            double cgpa = scanner.nextDouble();
            // pass cgpa into native function
            q1.calcDiloma(cgpa);
        } else if (choice == 2) { // Degree
            System.out.printf("\n==========\n");
            System.out.printf("\n  Degree  \n");
            System.out.printf("\n==========\n");
            System.out.printf("\nPlease input your CGPA: ");
            // declare and assign input cgpa
            double cgpa = scanner.nextDouble();
            // pass cgpa into native function
            q1.calcDegree(cgpa);
        } else {
            System.out.printf("Wrong Input, exiting....\n");
        }

    }
}