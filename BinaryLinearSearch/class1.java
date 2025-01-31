import java.util.Scanner;
import java.util.ArrayList;

// Linear Search
// class Main{
//     void linearSearch(int arr[], int size, int toSearch, boolean flag){
//         for(int i = 0; i < size; i++){
//             if(arr[i] == toSearch){
//                 flag = true;
//                 System.out.println("value found at " + i + " index");
//                 break;
//             }
//         }
//         if(flag != true){
//             System.out.println("value not found");
//         }
//     }
// }


// public class class1 {
//     public static void main(String[] args) {
//         Main obj = new Main();
//         Scanner scan = new Scanner(System.in);
//         boolean flag = false;
//         int arr [] = {75, 90, 25, 98, 23, 11};
//         int size = arr.length;
//         System.out.println("Enter a number to find in array");
//         int toSearch = scan.nextInt();
//         obj.linearSearch(arr, size, toSearch, flag);
//     }
// }




// Linear Search and Find all occurence

// int arr2[] = new int[size];
// arr2[count] = i;
// count++;
class Main{
    void linearSearch(int arr1[], ArrayList<Integer> arr2 , int size, int toSearch){
        for(int i = 0; i < arr1.length; i++){
            if (arr1[i] == toSearch) {
                arr2.add(i);
            }
        }
        if (arr2.isEmpty()) {
            System.out.println("Given input " + toSearch +  " Not found");
        }else{
            System.out.println( "value " + toSearch + " found at "  +  arr2 + " index in array");
        }
    }
}


public class class1 {
    public static void main(String[] args) {
        Main obj = new Main();
        // int count = 0;
        Scanner scan = new Scanner(System.in);
        int arr1[] = {1, 3, 5, 7, 1, 6, 1};
        int size = arr1.length;
        ArrayList<Integer> arr2 = new ArrayList<>();
        System.out.println("Enter a number you want to serch");      
        int toSearch = scan.nextInt();
        obj.linearSearch(arr1, arr2, size, toSearch);
    }
}
