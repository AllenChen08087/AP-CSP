import java.util.ArrayList;
import java.util.Scanner;

public class Budget {

    // procedure: calculate the total spending based on an arraylist
    public static int calculateTotal(ArrayList<Integer> list) {
        int sum = 0;
        for (int i = 0; i < list.size(); i++) {
            sum = sum + list.get(i);
        }
        return sum;
    }

    // procedure: check if the spending will exceed the budget, and return true or
    // false based on the budget left and the spending
    public static boolean exceedBudget(int budget_left, int spending) {
        if (budget_left < spending) {
            System.out.println("This spending has exceed your budget, you need to cancel this purchase");
            return true;
        } else {
            
            return false;
        }
    }
    //ask if users would like to enter more purchases
    public static boolean morePurchases (Scanner scanner){
        System.out.println("Would you like to enter another purchase? Answer Yes or No");
        String response = scanner.nextLine();
        if (response.equals("No") || response.equals("no")) {
            return false;
        }else {
            return true;
        }
       
    }

    public static void main(String[] args) {

        // variables setup
        Scanner scanner = new Scanner(System.in);
        boolean end = false;
        System.out.println("Enter your budget for the day");
        int budget = scanner.nextInt();
        int budget_left = budget;
        int sum = 0;
        System.out.println("Nice, now you can input your purchases");
        ArrayList<Integer> purchases = new ArrayList<Integer>();

        // ask users to input their spendins until either the spendings exceed the
        // budget or the users stop the inputs manually
        while (end == false) {
            // ask users to input their purchase, and add it to the arrylist
            System.out.println("Please input the amount of money you've spent");
            int purchase = scanner.nextInt();
            scanner.nextLine();
            // check if the spendings exceed the budget
            if (!exceedBudget(budget_left, purchase)) {
                purchases.add(purchase);
                sum = calculateTotal(purchases);
                budget_left = budget - sum;
                System.out.println("You have $" + budget_left + " left");
                System.out.println("You've spent $" + sum);
                if (budget_left == 0) {
                    end = true;
                }
            }
            // check if the users want to continue inputting purchases
            if (morePurchases(scanner)&&end == false) {
                end = false;
            }
            else{
                end = true;
            }

        }
        // provide summary to the users on their spendings
        System.out.println("Thank you for using this App");
        System.out.println("Your budget for today is $" + budget);
        System.out.println("You've spent $" + calculateTotal(purchases) + " today");
        System.out.println("You have $" + budget_left + " left");

        scanner.close();
    }
}