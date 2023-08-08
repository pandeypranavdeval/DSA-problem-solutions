//{ Driver Code Starts
import java.io.*;
import java.util.*;


class IntArray
{
    public static int[] input(BufferedReader br, int n) throws IOException
    {
        String[] s = br.readLine().trim().split(" ");
        int[] a = new int[n];
        for(int i = 0; i < n; i++)
            a[i] = Integer.parseInt(s[i]);

        return a;
    }

    public static void print(int[] a)
    {
        for(int e : a)
            System.out.print(e + " ");
        System.out.println();
    }

    public static void print(ArrayList<Integer> a)
    {
        for(int e : a)
            System.out.print(e + " ");
        System.out.println();
    }
}

class GFG {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t;
        t = Integer.parseInt(br.readLine());
        while(t-- > 0){
            
            int n;
            n = Integer.parseInt(br.readLine());
            
            
            int[] numerator = IntArray.input(br, n);
            
            
            int[] denominator = IntArray.input(br, n);
            
            Solution obj = new Solution();
            int res = obj.countFractions(n, numerator, denominator);
            
            System.out.println(res);
            
        }
    }
}

// } Driver Code Ends


class Solution {
    public static int countFractions(int n, int[] numerator, int[] denominator) {
        int count = 0;
        Map<String, Integer> fractionMap = new HashMap<>();
        
        for (int i = 0; i < n; i++) {
            int gcd = gcd(numerator[i], denominator[i]);
            int simplifiedNumerator = numerator[i] / gcd;
            int simplifiedDenominator = denominator[i] / gcd;
            int complementNumerator = simplifiedDenominator - simplifiedNumerator;
            int complementDenominator = simplifiedDenominator;
            
            String complementKey = complementNumerator + "/" + complementDenominator;
            if (fractionMap.containsKey(complementKey)) {
                count += fractionMap.get(complementKey);
            }
            
            String fractionKey = simplifiedNumerator + "/" + simplifiedDenominator;
            fractionMap.put(fractionKey, fractionMap.getOrDefault(fractionKey, 0) + 1);
        }
        
        return count;
    }
    
    private static int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }      return gcd(b, a % b);
    }

    public static void main(String[] args) {
        int N1 = 4;
        int[] numerator1 = {1, 2, 2, 8};
        int[] denominator1 = {2, 4, 6, 12};
        System.out.println(countFractions(N1, numerator1, denominator1)); // Output: 2
        
        int N2 = 5;
        int[] numerator2 = {3, 1, 12, 81, 2};
        int[] denominator2 = {9, 10, 18, 90, 5};
        System.out.println(countFractions(N2, numerator2, denominator2)); // Output: 2
    }
}        //JAVA 8TH POTD
        
