/*
	Hansi Seitaj
	CmpSc472, Final Lab
	04/29/2022
	The purpose of this lab is to store text messages in an efficient method.
*/

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;


class CmpSc472_MsgMapping
{
    File file;
    //to store unique words
    List<String> words;
    
    //this list will have an integer array
    //each array in the list represents a message words positions referencing words in words list
    List<int[]> messages;
    int numberOfMessages;
    static Scanner sc;
    
    //constructor with file name argument;
    public CmpSc472_MsgMapping(String fileName)
    {
        this.file = new File(fileName);
        //reading text file using scanner class
        try {
            this.sc = new Scanner(file);
            this.messages = new ArrayList<int[]>();
            this.words = new ArrayList<String>();
        } 
        catch (FileNotFoundException e) 
        {
            //e.printStackTrace();
        	//sc.close();
        	System.out.println("\nFile is not found! Please try again!");
        	System.exit(-1);
        }
    }
    
    /*  
     * Checking whether the word already present in words list or not
     * This method will return word index if present other wise return -1
    */
    public int isWordInList(String word)
    {
        for(String w: this.words)
        {
            if(w.equals(word))
                return words.indexOf(w);
        }
        return -1;
    }

    //reading text file
    public void readFile()
    {
        //reading each line in the text file
        while(sc.hasNextLine())
        {
        	//converting all the messages into lower case to remove word doubles
            String message = this.sc.nextLine().toLowerCase();
            
            //removing  '.' from the message if present
            message = message.charAt(message.length()-1)=='.'?message.substring(0,message.length()-1):message;
            
            //seperating words and stored in word array
            String[] word = message.split(" ");
            
            //number of words in a message
            int numberOfWords = word.length;
            
            //creating message words array
            int[] messageWords = new int[numberOfWords];
            int i=0;
            
            for(String w : word)
            {
                int index = isWordInList(w);
                //if word not present in the list
                if(index==-1)
                {
                    this.words.add(w);
                    messageWords[i] = this.words.size()-1;
                }
                //if word already present store index of that word
                else
                {
                    messageWords[i] = index;
                }
                
                i+=1;
            }
            
            this.numberOfMessages+=1;
            //adding postions array of each message in a list messages
            this.messages.add(messageWords);
        }
        System.out.println("\nBelow are the unique words in the text file entered with " + numberOfMessages + " total number of sentences: ");
        System.out.println(this.words+"\n");
    }
    // use this run method test the program
    public void run()
    {
        readFile();
        boolean sentinel = true; 
        while(sentinel)
        {
            System.out.print("Enter Message number to display or -1 to Exit: ");

            this.sc = new Scanner(System.in);
            int number = sc.nextInt();
            if(number == -1)
            {
                sentinel = false;
                System.out.println("Thank you for using the program!");
                sc.close();
            }
            else if(number > this.numberOfMessages || number <= 0)
            {
                System.out.println("Invalid Message number!");
                System.out.println();
            }
            else
            {
                int[] m = this.messages.get(number-1);
                for(int i = 0; i < m.length-1; i++) 
                {
                	//If there is the first word the sentence, capitalize the first letter
                	if (i == 0) 
                	{
                		String first = words.get(m[0]); 
                		System.out.print(first.substring(0, 1).toUpperCase() + first.substring(1) + " ");
                		//i++;
                	}
                	else 
                	{
                		System.out.print(words.get(m[i]) + " ");
                	}
                }
                System.out.print(words.get(m[m.length-1]) + ".\n");
                System.out.println();
            }
        }
    }
    
    public static void main(String[] args) 
    {
        //provide text file name if it is in current directory or
        // provide the path of text file directory
    	System.out.print("Please enter the path or the filename you want to open: ");

        sc = new Scanner(System.in);
        String filename = sc.nextLine();
       
        //creating instance of Lab1_MsgMapping object with text file name
        CmpSc472_MsgMapping lab = new CmpSc472_MsgMapping(filename);
        lab.run();
        sc.close();
    }

}
