/*
   Programmer: Kristoffer Larson
   Date: January 26, 2014
   
   Description: 
   	Input a mathematical statement as a String and 
   	calculate the answer.
*/

import java.util.*;

public class InfixCalculator {
	private String infixExp;
	
	public InfixCalculator(String exp) {
		infixExp = exp;
	}
	
	public double evaluate() {
		infixExp = "( " + infixExp + " )";
		
		Stack<Character> opStack = new Stack<Character>(); //Operator stack
		Stack<Double> valStack = new Stack<Double>(); //Value stack
	
		String[] tokens = infixExp.split(" "); 

		for (String token: tokens) {
			if (token.length() != 1)  //Check to see there is more than one item
				valStack.push(new Double(token));
			else if (token.charAt(0) >= '0' && token.charAt(0) <= '9') //Checks for digits
				valStack.push(new Double(token));
			else if (token.equals("(")) 
				opStack.push(token.charAt(0));
			else if (token.equals(")")){ //Checks for closing parenthesis
				do {
					execute(valStack, opStack); //Performs calculations
				} while (opStack.peek() != '(');
			}
			else
				if (precedence(token.charAt(0)) > precedence(opStack.peek())) //Orders by presedence
					opStack.push(token.charAt(0));
				else {
					while (precedence(token.charAt(0)) <= precedence(opStack.peek()))
						execute(valStack, opStack);
					opStack.push(token.charAt(0));
				}
		}
		if (opStack.isEmpty()) //Empty opStack means everything is done
			System.exit(0);
		else {
			if (valStack.isEmpty()) //Empty valStack means everything is done
				System.exit(0);
			else
				return valStack.pop();
		}
		return valStack.pop();
	}
	
	public int precedence(char token) { //Operator precedence, PEMDAS
		int i;
		switch(token) {
			case '*': return i = 3; //Higher value is higher precedence
			case '/': return i = 3;
			case '%': return i = 3;
			case '+': return i = 2;
			case '-': return i = 2;
			case '(': return i = 1;
			case ')': return i = 1;
			default: return i = 0;
		}
	}
	public void execute(Stack<Double> valStack, Stack<Character> opStack) { //Performs calculations
		if (opStack.peek() == '(')
			opStack.pop();
		char op = opStack.pop();
		double operand2 = valStack.pop();
		double operand1 = valStack.pop();
		
		switch(op){
			case '+': valStack.push(operand1 + operand2); break;
			case '-': valStack.push(operand1 - operand2); break;
			case '*': valStack.push(operand1 * operand2); break;
			case '/': valStack.push(operand1 / operand2); break;
			case '%': valStack.push(operand1 % operand2); break;
			default: System.exit(0);
		}
	}
   
   public static void main(String[] args) {
      System.out.printf("All numbers must be of float type and everything must be separated by a single space.\n");
      System.out.printf("Please enter your desired simple calculation (Ex// 1.0 + 5.0) : ");
		Scanner input = new Scanner(System.in);
		String statement = input.nextLine();
		
		InfixCalculator c = new InfixCalculator(statement);
		System.out.println(c.evaluate());
	}
}
