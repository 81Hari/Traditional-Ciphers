import java.util.Scanner;

public class SubstitutionCipher{
	
	private String ori, ori1, plain_text;
	private String sub, cipher_text;
	
	public SubstitutionCipher() {
	
		ori = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
		sub = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
		plain_text = "";
		cipher_text = "";
	}
	
	
	public boolean check()
	{
		int flag;
		
		for(int i=0;i<ori.length();i++) {
			
			flag=0;
			
			for(int j=0;j<sub.length();j++) {
				if(ori.charAt(i)==sub.charAt(j)) {
					flag++;
				}
					
			}
			
			if (flag!=1) // if a character is repeated more than once then some duplication happened, So we need to do the subsitution again. 
			{
				
				System.out.println(sub);
				return true;
			}
				
		}
		return false;
			
	}
	public boolean substitution(Scanner in) {
	
		boolean flag;
		for(int i=0;i<ori.length();i++) {
		
			System.out.print(ori.charAt(i) + " mapped to ");
			sub = sub.substring(0,i)+in.next().charAt(0)+sub.substring(i+1); //Strings are immutable
			System.out.println("");
		}
		sub = sub.toUpperCase();
		System.out.println("");
		flag = check();
		if(flag) {
			System.out.println("Error, Do the mapping again. Without duplication and use only alphabets");
			return false;
		}
		return true;	
	}
	
	public void encrypt(Scanner in) {
		System.out.print("Enter Plain Text: ");
		plain_text = in.next();
		int j;
		for(int i=0;i<plain_text.length();i++) {
			if(Character.isLowerCase(plain_text.charAt(i)))
			{
				j = ori.indexOf(Character.toUpperCase(plain_text.charAt(i)));
				cipher_text = cipher_text + Character.toLowerCase(sub.charAt(j));
			}
			else
			{
				j = ori.indexOf(plain_text.charAt(i));
				cipher_text = cipher_text + sub.charAt(j);
			}
			
		}
		System.out.println("");
		System.out.println("Cipher Text: " + cipher_text);
			
		
		
	}
	
	public void decrypt(Scanner in) {
		System.out.print("Enter Cipher Text: ");
		cipher_text = in.next();
		int j;
		for(int i=0;i<cipher_text.length();i++) {
			if(Character.isLowerCase(cipher_text.charAt(i)))
			{
				j = sub.indexOf(Character.toUpperCase(cipher_text.charAt(i)));
				plain_text = plain_text + Character.toLowerCase(ori.charAt(j));
			}
			else
			{
				j = sub.indexOf(cipher_text.charAt(i));
				plain_text = plain_text + ori.charAt(j);
			}
			
		}
		System.out.println("");
		System.out.println("Plain Text: " + plain_text);
		
	}
	
	
	
	public static void main(String[] args) {
		
		Scanner input = new Scanner(System.in);
		System.out.println("\t\t SUBSITUTION CIPHER \n");
		System.out.println("Fill the Subsitution Table");
		
		SubstitutionCipher SC = new SubstitutionCipher();
		while(true) {
			if(SC.substitution(input))
			{
				break;
			}
		}
		System.out.println("1. Encryption");
		System.out.println("2. Decryption");
		System.out.println("3. Cryptanalysis (Statistical Properties of English Text)\n");
		System.out.print("Enter Service Number: ");
		
		
		int ch;
		ch = input.nextInt();
		System.out.println("");
		switch(ch) {
		
		case 1: SC.encrypt(input); break;
		case 2: SC.decrypt(input);break;
		default:System.out.println("Invalid input");
		
		
		}
		
		
		
		
	}
}
