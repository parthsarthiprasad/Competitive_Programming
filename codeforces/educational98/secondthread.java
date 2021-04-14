//Level 5
import java.util.*;
import java.io.*;
import java.math.*;

   public class D
   {
      public static void main(String hi[]) throws Exception
      {
         BufferedReader infile = new BufferedReader(new InputStreamReader(System.in));
         StringTokenizer st = new StringTokenizer(infile.readLine());
         int T = Integer.parseInt(st.nextToken());
         StringBuilder sb = new StringBuilder();
         while(T-->0)
         {
            int N = Integer.parseInt(infile.readLine());
            char[] arr = infile.readLine().toCharArray();
            int count0 = 0;
            int count1 = 0;
            int finans = 0;
            for(int i=0;i<N;i++){
                if(arr[i]=='0'){
                    if(count1>0){
                        count1--;
                        count0++;
                    }else{
                        finans++;
                        count0++;
                    }
                }else{
                    if(count0>0){
                        count1++;
                        count0--;
                    }else{
                        count1++;
                        finans++;
                    }
                }
            }

            System.out.println(finans);
            // for(int x: res)
            //    sb.append(x+" ");
            // sb.append("\n");
         }
         
      }
   }