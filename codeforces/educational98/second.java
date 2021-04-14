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
         int T = 1;
         StringBuilder sb = new StringBuilder();
         while(T-->0)
         {
            int N = Integer.parseInt(infile.readLine());
            char[] arr = infile.readLine().toCharArray();
            TreeSet<Integer>[] sets = new TreeSet[2];
            sets[0] = new TreeSet<Integer>();
            sets[1] = new TreeSet<Integer>();
            int[] res = new int[N];
            for(int i=0; i < N; i++)
               sets[arr[i]-'0'].add(i);
            int curr = 1;
            while(sets[0].size() > 0)
            {
               int dex = sets[0].first();
               int tag = 0;
               if(sets[1].size() > 0 && dex > sets[1].first())
               {
                  dex = sets[1].first();
                  tag = 1;
               }
               sets[tag].remove(dex);
               res[dex] = curr;
               while(true)
               {
                  if(sets[tag^1].size() == 0 || sets[tag^1].last() < dex)
                     break;
                  dex = sets[tag^1].ceiling(dex);
                  sets[tag^1].remove(dex);
                  tag ^= 1;
                  res[dex] = curr;
               }
               curr++;
            }
            for(int dex: sets[1])
               res[dex] = curr++;
            sb.append(curr-1).append("\n");
            // for(int x: res)
            //    sb.append(x+" ");
            // sb.append("\n");
         }
         System.out.print(sb);
      }
   }