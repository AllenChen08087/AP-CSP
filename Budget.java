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
        if (spending > budget_left) {
            System.out.println("This spending has exceeded your budget. Cancel purchase.");
            return false;
        } else {
            return true;
        }
    }
    //add new spendings to the arraylist and display the information to the users
    public static int addToPurchases(int purchase, int budget, ArrayList<Integer> purchases, int budget_left) {
        purchases.add(purchase);
        int sum = calculateTotal(purchases);
        budget_left = budget - sum;
        System.out.println("You've spent $" + sum);
        System.out.println("You have $" + budget_left + " left");
        return budget_left;
    }
    //ask users if they want to input more purchases
    public static boolean morePurchases(Scanner scanner) {
        System.out.println("Would you like to enter another purchase? Answer Yes or No");
        String response = scanner.nextLine();
        if (response.equals("No") || response.equals("no")) {
            return false;
        } else {
            return true;
        }
    }
    public static void summary(int budget, ArrayList<Integer> purchases, int budget_left) {
        System.out.println("Thank you for using this App");
        System.out.println("Your budget for today is $" + budget);
        System.out.println("You've spent $" + calculateTotal(purchases) + " today");
        System.out.println("You have $" + budget_left + " left");
    }
    public static void main(String[] args) {
        // variables setup
        Scanner scanner = new Scanner(System.in);
        boolean end = false;
        System.out.println("Enter your budget for the day");
        int budget = scanner.nextInt();
        int budget_left = budget;
        System.out.println("Nice, now you can input your purchases");
        ArrayList<Integer> purchases = new ArrayList<Integer>();
        // ask users to input their spendins until either the spendings exceed the
        // budget or the users stop the inputs manually
        while (!end) {
            System.out.println("Please input the amount of money you've spent");
            int purchase = scanner.nextInt();
            scanner.nextLine();
            if (exceedBudget(budget_left, purchase)) {
                budget_left=addToPurchases(purchase, budget, purchases, budget_left);
                
            }
            if(budget_left == 0){
                end = true;
            }
            if(!end){
                if(!morePurchases(scanner)) {
                    end = true;
                }
            }
        }
        // provide summary to the users on their spendings
        summary(budget, purchases, budget_left);
        scanner.close();
    }
}