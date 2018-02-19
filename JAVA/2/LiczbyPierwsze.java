public class LiczbyPierwsze {
 private final static int POTEGA2 = 21;
 private final static int MAKS=1<<POTEGA2;
 private final static int[] SITO = new int[MAKS];
 
 static {
 for(int i=1; i<MAKS;i+=1) {
			SITO[i]=0;
		}
		for(int i=2;i<(MAKS);i+=2) {
			SITO[i] = 2;
		}
		for(int i=3;i<MAKS; i+=1) {
			if (SITO[i]==0) {
				for(int j=i;j<MAKS;j+=i) {
					if(SITO[j]==0)	{
						SITO[j]=i;
					}
				}
			}
		}
 
 }
 
 public static boolean czyPierwsza(long x) {
             
     if (x== -9223372036854775808L){

         return false;
     }

     if (x<1) {             
         return false;
     }             

     if (x<MAKS){
         return SITO[(int)x]==x;                 
     }             
     else{
         if (x%2==0){
            return false;
         }
         if (x%3==0){
            return false;
         }
         for(long u=5; u!=(long)Math.sqrt(x); u+=6) {
             if (x%u==0 || x%(u+2)==0) {  
                 return false;                         
             }
         }     
         return true;                    
     }        
 }
 
public static long[] naCzynnikiPierwsze(long x){
    int potega=0;
    if (x<0){
        while(x<=(-1*Math.pow(2,potega))){
            potega+=1;
        }
        potega+=1;
    }
    else {
        while(x>=Math.pow(2, potega)){
            potega+=1;
        }
    }
    long[] LISTA = new long[potega];
    int licznik=0;
    
    if(x==1 || x==0 || x==-1){
        LISTA[0]=x;
        return LISTA;
     }
    
    if(x==-x){
     x/=2;
     x*=-1;
     LISTA[licznik]=-1;
     LISTA[licznik+1]=2;
     licznik+=2;
    }
    
    if (x<0){
        LISTA[0]=-1;
        x*=-1;
        licznik=1;
    }
    
    if (x<MAKS){
        while(x>1){
            LISTA[licznik]= SITO[(int)x];
            x/=SITO[(int)x];
            licznik++;
        }
        return LISTA;
    }
    else{
        while(x%2==0 && x>0){
            LISTA[licznik]=2;
            x/=2;
            licznik++;
        }
        while(x%3==0 && x>0){
            LISTA[licznik]= 3;
            x/=3;
            licznik++;
        }
        for(long i=5;i*i<=x;i+=6){
            while(x%i==0){
                LISTA[licznik]=i;
                x/=i;
                licznik++;
            }
            while(x%(i+2)==0){
                LISTA[licznik]=i+2;
                x/=(i+2);
                licznik++;
            }  
        }
        
        if(x>1){
            LISTA[licznik]=x;
        }
        
        return LISTA;
        }
    }
}
    




      
//		
//         
//		
//		
//		//ROZKLAD NA CZYNNIKIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIi
//		
//		public static long[] naCzynnikiPierwsze(long x) {
//                    
//                    
//			//long[] LISTA = new long[65];
//                        
//                        
//                        
//			

//                        
//                        if(x==-x){
//                            x/=2;
//                            x*=-1;
//                            LISTA[licznik]=-1;
//                            licznik+=1;
//                            LISTA[licznik]=2;
//                            licznik+=1;
//                            
//                        }
//			if (x<0){
//				LISTA[0]=-1;
//				x=x*-1;
//				licznik=1;
//			}
//			while(x>1){
//				if(x<MAKS){
//					LISTA[licznik]=SITO[(int)x];
//					x/=SITO[(int)x];
//					licznik+=1;
//                                        
//				}
//				else{
//                                    if(x%2==0){
//                                        LISTA[licznik]=2;
//                                        x/=2;
//                                        licznik+=1;
//                                        continue;
//                                    }
//                                    
//                                    if(x%3==0){
//                                        LISTA[licznik]=3;
//                                        x/=3;
//                                        licznik+=1;    
//                                        continue;
//                                    }
//				
//                                    for(int i=5;i<=(long)(Math.sqrt(x));i+=1){
//                                        if (x%i==0){
//                                            LISTA[licznik]=i;					
//                                            x/=i;					
//                                            licznik+=1;
//                                            break;
//                                            
//					}
//                                        
//                                        if (x%(i+2) ==0){
//                                            LISTA[licznik]=i;					
//                                            x/=(i+2);					
//                                            licznik+=1;					
//                                            break;
//					}
//                                        //break;
//                                    }
//				}
//			}
//			return LISTA;
//			
//		}
//		
//		//WYPISYWANIEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEe
//		
//		public static void Wypisz(long[] LISTA){
//			int i =0;
//			while(LISTA[i]!=0){
//				if(LISTA[i+1]==0){
//					System.out.print(LISTA[i]);
//				}
//				else{
//					System.out.print(LISTA[i]+" * ");
//				}
//				i+=1;
//			}
//		}
//		
//	public static void main(String[] args) {
//		
//		//SITOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOo
//		
//		for(int i=1; i<MAKS;i+=1) {
//			SITO[i]=0;
//		}
//		for(int i=2;i<(MAKS);i+=2) {
//			SITO[i] = 2;
//		}
//		for(int i=3;i<MAKS; i+=1) {
//			if (SITO[i]==0) {
//				for(int j=i;j<MAKS;j+=i) {
//					if(SITO[j]==0)	{
//						SITO[j]=i;
//					}
//				}
//			}
//		}
//                
//		
//		
//		long liczba= 9223372036854775785L;
//		if(czyPierwsza(liczba)){
//			System.out.println("Liczba "+liczba+" jest pierwsza");
//		}
//		else {
//			Wypisz(naCzynnikiPierwsze(liczba));
//		}
//		
//	}		
//}