#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;
//FUNCAO QUE DIVIDE O IP EM 4 OCTETOS
vector<string> SeparadorDeBlocos(string ip){ 
    	//Separando o IP em 4 Octetos 
	        vector<string> Octeto;
            string Aux; 
      
	           for(int i = 0;i<ip.length();i++){
	                if(ip[i]!=46){
  	   	               Aux+=ip[i];} //Se o Caracter for indiferente do delimitador armazena ele na String
		            else{
		 	           Octeto.push_back(Aux); //Apos Encontrar o Delimitator Armazenar o Octeto em vector de string
		 	           Aux.clear();}
  	                if(i==ip.length()-1){ 
  		               Octeto.push_back(Aux);}
  		   
	            }
    return Octeto; //Retorno Da Função	
}
//FUNCAO VERIFICACAO DE IP VALIDO
bool IPValido (string ip){
	
	int Erro = 0;
	int Delimitador = 0; 
	int ErroDelimitador = 0;
	
	       //Verificando se contém Caracteres Invalidos  TABELA ASCII 33:45 e 47
	       
	                for(int i = 33;i<=45;i++){
		                 for(int j = 0;j<=ip.length();j++){
		 	                 if(ip[j]==i||ip[j]==47){
		 	  	                Erro++;}
			              }
		            }
	
	       //Verificando se contém Caracteres Invalidos  TABELA ASCII 58:127
	       
	                for(int i = 58;i<=127;i++){
		                for(int j = 0;j<=ip.length();j++){
		 	                if(ip[j]==i){
		 	  	               Erro++;}
			            }
		            }
	
	       //Verificando se possui mais de 3 delimitador '.' ASCII 46
	       
	                for(int i = 0;i<=ip.length();i++){
	   	                 if(ip[i]==46){
	   	   	             Delimitador++;}
			        }
	
	       //Verificando se tem dois delimitador juntos
	       
	                for(int i = 0;i<=ip.length();i++){
	   	                if(ip[i]==46 && ip[i+1]==46){
	   	   	               ErroDelimitador++;}
			        }
	   
	       //Verificando se os octetos são maiores que 255 
	       
	           vector<string> Octeto = SeparadorDeBlocos(ip);
               string Aux; 
	           char x[Octeto.size()];
	                for(int i=0;i<Octeto.size();i++){
	    	            Aux= Octeto[i];
	    	             for(int j=0;j<=Aux.length();j++){
	    	                 x[j]=Aux[j];}
	    	            int Num = atoi(x);
	    	            if(Num>255){
	    	         	Erro++;}
			        }
		
	       //VERIFICANDO SE O ULTIMO OCTETO ESTÁ VAZIO
	         string oc=Octeto[3];
	         
	             if(oc.length()==0){
	         	    Erro++;}
           //TRATANDO OS ERROS
           
	           if(Erro>0 || Delimitador != 3 || ErroDelimitador > 0){
		          return false;} //Verificando se o IP é valido
	           else{
		          return true;}
}
//FUNÇÃO DE CONVERSÃO BINARIA
string  ConversaoBinario(string ip){
	
            //Separando por Blocos
	        vector<string> Octeto = SeparadorDeBlocos(ip);
	        vector<int> OctetoInt;
	        string Aux;
	        int BlocoInt;
        	int Qposicao;
	        int Soma;
	        ip.clear();
	  
         	//BLOCO 1
         	
	        string Aux1 = Octeto[0];
	        char Bloco1[Aux1.length()];
	
	       //Conversao String para Char  
		      
            for(int i = 0;i<Aux1.length();i++){		
		        Bloco1[i] = Aux1[i];}
		     
        	BlocoInt = atoi(Bloco1); //Conversao char para decimal
            itoa(BlocoInt,Bloco1,2); //Conversao Para Binário
            Aux1.clear();
    
	        for(int i = 0;i<=7;i++){
		        if(Bloco1[i] =='1' || Bloco1[i] =='0'){
		        Aux1+=Bloco1[i];
		        Qposicao++;}
	        }
	
	       //Completando com 0 a esquerda
	       
	        Soma = 8-Qposicao;
	        
            for(int i=0;i<Soma;i++){
		        Aux+=48;}
		        
	            Qposicao =0;
	            Aux = Aux+Aux1;
	            ip=Aux;
	            ip+='.';
	            Aux.clear();
	
	
	       //BLOCO 2
	       
	       string Aux2 = Octeto[1];
	       char Bloco2[Aux2.length()];
	       
	      //Conversao String para Char  
		     
           for(int i = 0;i<Aux2.length();i++){		
		       Bloco2[i] = Aux2[i];}
		     
	       BlocoInt = atoi(Bloco2); //Conversao char para decimal
           itoa(BlocoInt,Bloco2,2); //Conversao Para Binário
           Aux2.clear();
           
	       for(int i = 0;i<=7;i++){
		       if(Bloco2[i] =='1' || Bloco2[i] =='0'){
		          Aux2+=Bloco2[i];
		          Qposicao++;}	       
		   }
		   
	     //Completando com 0 a esquerda
	     
	      Soma = 8-Qposicao;
	      
           for(int i=0;i<Soma;i++){
		       Aux+=48;}
		       
	           Qposicao =0;
	           Aux = Aux+Aux2;
	           ip+=Aux;
	           ip+='.';
	           Aux.clear();
	
	
	     //BLOCO 3
	     
	     string Aux3 = Octeto[2];
	     char Bloco3[Aux3.length()];
	     
	    //Conversao String para Char 
		    
        for(int i = 0;i<Aux3.length();i++){		
		     Bloco3[i] = Aux3[i];}
		     
	    BlocoInt = atoi(Bloco3); //Conversao char para decimal
        itoa(BlocoInt,Bloco3,2); //Conversao Para Binário
        Aux3.clear();
        
	    for(int i = 0;i<=7;i++){
		    if(Bloco3[i] =='1' || Bloco3[i] =='0'){
		       Aux3+=Bloco3[i];
		       Qposicao++;}
	    }
	    
	   //Completando com 0 a esquerda
	   
	    Soma = 8-Qposicao;
	    
         for(int i=0;i<Soma;i++){
		     Aux+=48;}
		     
	    Qposicao =0;
	    Aux = Aux+Aux3;
	    ip+=Aux;
	    ip+='.';
	    Aux.clear();
	
	
       //BLOCO 4
       
	    string Aux4 = Octeto[3];
	    char Bloco4[Aux4.length()];
	    
	   //Conversao String para Char 
	       
        for(int i = 0;i<Aux4.length();i++){		
		     Bloco4[i] = Aux4[i];}
		     
	    BlocoInt = atoi(Bloco4); //Conversao char para decimal
        itoa(BlocoInt,Bloco4,2); //Conversao Para Binário
        Aux4.clear();
        
	    for(int i = 0;i<=7;i++){
		    if(Bloco4[i] =='1' || Bloco4[i] =='0'){
		       Aux4+=Bloco4[i];
		       Qposicao++;}
	    }
	    
 	   //Completando com 0 a esquerda
 	   
	    Soma = 8-Qposicao;
	    
        for(int i=0;i<Soma;i++){
		    Aux+=48;}
		    
	      Qposicao =0;
	      Aux = Aux+Aux4;
	      ip+=Aux;
	      Aux.clear();
		
	return ip;
	    
}
//FUNCAO PARA CRIAR A MASCARA DE REDE
string MascaraRede (int cdr){

         string soma;
         string ip;
         
         //CRIANDO A MASCARA DO CDR INFORMADO
         
           for(int i = 0;i<cdr;i++){
  	           ip+='1';}
		
          for(int i = cdr;i<32;i++){
  	          ip+='0';}
		
        //COLOCANDO O DELIMITADOR
        
         soma = ip;
         ip.clear();
         
           for(int i = 0;i<soma.length();i++){
  	           if(i==7 || i==15 || i == 23){	
			   ip+=soma[i];
			   ip+=46;}
			  else{
			  	ip+=soma[i];}
	       }
		
  return ip;
  
}
//FUNCAO PARA ACHAR O ENDEREÇO DA REDE
string EnderecoDeRede(string ip,string mascara){
	
               string soma;
        
               //CONVERTENDO PARA BINÁRIO
               
               ip = ConversaoBinario(ip);
  
              //RETIRANDO OS DELIMITADORES DO IP
              
              vector<string> ipnew = SeparadorDeBlocos(ip);
              ip.clear();// Resetando a String
              ip+= ipnew[0];
              ip+= ipnew[1];
              ip+= ipnew[2];
              ip+= ipnew[3];
  
             //RETIRANDO OS DELIMITADORES DA MASCARA
             
             vector<string> mascaranew = SeparadorDeBlocos(mascara);
             mascara.clear();// Resetando a String
             mascara+= mascaranew[0];
             mascara+= mascaranew[1];
             mascara+= mascaranew[2];
             mascara+= mascaranew[3];
  
            //OPERACAO AND COM IP E MASCARA
            
               for(int i = 0;i<ip.length();i++){
  	               if(ip[i]==49 && mascara[i]==49){
  	   	              soma+=49;}
		           else{
		 	          soma+=48;}
		       }
		
  
              ip.clear();
              
              for(int i = 0;i<soma.length();i++){
  	               if(i==7 || i==15 || i == 23){	
			          ip+=soma[i];
			          ip+=46;}
			       else{
			  	     ip+=soma[i];}
			  }
  return ip;
}
//FUNCAO PARA ACHAR O ENDEREÇO DE BROADCAST
string EnderecoBroadcast (string ip,string mascara){
	
           string soma;
           
           //CONVERTENDO PARA BINÁRIO
           
           ip = ConversaoBinario(ip);
  
          //RETIRANDO OS DELIMITADORES DO IP
          
          vector<string> ipnew = SeparadorDeBlocos(ip);
          ip.clear();// Resetando a String
          ip+= ipnew[0];
          ip+= ipnew[1];
          ip+= ipnew[2];
          ip+= ipnew[3];
  
          //RETIRANDO OS DELIMITADORES DA MASCARA
          
          vector<string> mascaranew = SeparadorDeBlocos(mascara);
          mascara.clear();// Resetando a String
          mascara+= mascaranew[0];
          mascara+= mascaranew[1];
          mascara+= mascaranew[2];
          mascara+= mascaranew[3];

          for(int i = 0;i<ip.length();i++){
  	          if(mascara[i]==49){
  	   	         soma+=48;}
  	          if(mascara[i]==48){
  	   	         soma+=49;}
          }
          
         //OPERACAO OR COM IP E MASCARA
         
          for(int i = 0;i<ip.length();i++){
  	          if(ip[i]==48 && soma[i]==48){
  	   	         soma[i]=48;}
		      else{
		         soma[i]=49;}
		  }
		
       //COLOCANDO O DELIMITADOR
       
        ip.clear();
        
         for(int i = 0;i<soma.length();i++){
  	          if(i==7 || i==15 || i == 23){	
			     ip+=soma[i];
			     ip+=46;}
			  else{
			  	 ip+=soma[i];}
     	}
		
  return ip;
}
//MENU DO PROGRAMA
int Menu(int opcao){
	
	     cout<<"==========================================================\n";
	     cout<<"========== Calculadora de IPV4 ===========================\n";
	     cout<<"===    1-Enderecamento com Classe                     ====\n";
	     cout<<"===    2-Enderecamento sem Classe - Mascara Decimal   ====\n";
	     cout<<"===    3-Enderecamento sem Classe - Mascara CIDR      ====\n";
	     cout<<"===    4-Finalizar Programa                           ====\n";
	     cout<<"==========================================================\n";
	     cout<<"Informe a Opcao Desejada -> ";
	     cin>>opcao;
	     return opcao;
}
//FUNCAO PARA CONVERTER DE BINARIO PARA DECIMAL
string ConversaoDecimal(string x){
   
	//Separando por Blocos
	vector<string> Octeto = SeparadorDeBlocos(x);
	string IpInverso;
	string IpDecimal;
	int Soma=0;
	
	//BLOCO 1
	
	string Aux1 = Octeto[0]; // Posicao 0 Do Vector que separou o IP
		
	//Ivertendo a String para Conversao
	    
        for(int i=7;i>=0;i--){		
	        IpInverso+= Aux1[i];}
		      
	    for(int i=0;i<=IpInverso.length();i++){
	    	if(IpInverso[i]==49){
	    	  Soma = Soma +(pow(2,i));}
	    }
	    
		char Bloco1[Aux1.length()];
		itoa(Soma,Bloco1,10); //Conversao Para Decimal
		IpDecimal = string(Bloco1);
		IpDecimal+='.';
		Soma = 0; //Zerando a Soma
		IpInverso.clear();
    
	
	 //BLOCO 2
	 
	string Aux2 = Octeto[1]; // Posicao 0 Do Vector que separou o IP
	
	//Ivertendo a String para Conversao
	    
        for(int i=7;i>=0;i--){		
		    IpInverso+= Aux2[i];}
		      
	    for(int i=0;i<=IpInverso.length();i++){
	    	if(IpInverso[i]==49){
	    	  Soma = Soma +(pow(2,i));}
	    }
	    
		char Bloco2[Aux2.length()];
		itoa(Soma,Bloco2,10); //Conversao Para Decimal
		IpDecimal+= string(Bloco2);
		IpDecimal+='.';
		Soma = 0; //Zerando a Soma
		IpInverso.clear();
		
		
		
	//BLOCO 3
	
	string Aux3 = Octeto[2]; // Posicao 0 Do Vector que separou o IP
	
	//Ivertendo a String para Conversao
	    
        for(int i=7;i>=0;i--){	
		 IpInverso+= Aux3[i];}
		      
	    for(int i=0;i<=IpInverso.length();i++){
	    	if(IpInverso[i]==49){
	    	 Soma = Soma +(pow(2,i));}
	    }
	    
		char Bloco3[Aux3.length()];
		itoa(Soma,Bloco3,10); //Conversao Para Decimal
		IpDecimal+= string(Bloco3);
		IpDecimal+='.';
		Soma = 0; //Zerando a Soma
		IpInverso.clear();			

     
    //BLOCO 4
	 
	string Aux4 = Octeto[3]; // Posicao 0 Do Vector que separou o IP
	
	//Ivertendo a String para Conversao
	    
       for(int i=7;i>=0;i--){	
		   IpInverso+= Aux4[i];}
		      
	    for(int i=0;i<=IpInverso.length();i++){
	    	if(IpInverso[i]==49){
	    	  Soma = Soma +(pow(2,i));}
	    }
	    
		char Bloco4[Aux4.length()];
		itoa(Soma,Bloco4,10); //Conversao Para Decimal
		IpDecimal+= string(Bloco4);
		Soma = 0; //Zerando a Soma
		IpInverso.clear();	
		
	return IpDecimal;
}
//FUNCAO PARA IDENTIFICAR O CIDR
int IdentificadorCIDR(string mascara){
    
	int num=0;
    
    //Verificando a mascara em Binario onde tem 1
    
     for(int i =0;mascara[i]!='\0';i++){
  	      if(mascara[i]==49){
  	    	 num++;}
      }
      
  return num;//RETORNA A QUANTIDADE DE 1 QUE TEM A MASCARA LOGO É O CIDR
}
//FUNCAO PARA ACHAR O ENDEREÇO INICIAL DA REDE
string EnderecoIPV4I(string ip){
	
	ip[ip.length()-1]=49;
	return ip;
}
//FUNCAO PARA ACHAR O ENDEREÇO FINAL DA REDE
string EnderecoIPV4F(string ip){
	
	ip[ip.length()-1]=48;
	return ip;
}
//FUNCAO PARA VALIDAR MASCARA
bool MascaraValida(string masc){
	
	int Erro=0;
	
	//Verificando se tem 0 no meio dos 1 
	  
	  for(int i = 0;i<masc.length();i++){
	  	   if(masc[i]=='0'){
	  	   	    for(int x = i;x<masc.length();x++){
	  	   	    	 if(masc[x]=='1'){
	  	   	    	 	  Erro++;}
						  }
					 }
			 }
	if(Erro>0){
		return false;
	}
	else{
		return true;
	}
}
int main (){
  
  //DECLARANDO VARIAVEIS
  int opcao_menu,cidr,nhost;
  string EnderecoIP,EnderecoRede,Mascara,EnderecoB,BroadCast,IPFinal,IPInicial;
  string MascaraD,EnderecoRedeD,BroadCastD,IPFinalD,IPInicialD;
  string MascaraAux;
  bool Estado,Masc;
  int Erro,Bloco1;
     
     //Menu Opções
     do{
  	   
	    opcao_menu = Menu(opcao_menu);
  	   
        switch(opcao_menu){ 
	     
        default:
        	cout<<"\nERRO: OPCAO INVALIDA\nTente Novamente !"<<endl;
        	break;
        	
        case 1:
        	
        	 //Verificando o IP
        	 
                 do{
                   cout<<"Formato a ser Digitado (xxx.xxx.xxx.xxx)"<<endl;
                   cout<<"Informe um Endereco de IP: ";
                   
                   cin>>EnderecoIP;
                   
                   Estado = IPValido(EnderecoIP);
                   
                   if(Estado== false){
                   cout<<"IP INVALIDO TENTE NOVAMENTE\n";}
                   }while(Estado == false);
                   
             //Identificando a Classe do IP
            
                do{
            	  Erro =0;
                  char Classe;
                  
                  cout<<"Informe a Classe do seu IP: ";
                  cin>>Classe;
                  
                  vector<string> BlocoIp = SeparadorDeBlocos(EnderecoIP);
                  string Aux = BlocoIp[0]; 
				              
                 //Conversao String para Char
                   char Bloco[Aux.length()];
                       for(int i = 0;i<=Aux.length();i++){
					       Bloco[i] = Aux[i];}
					       
				 Bloco1 = atoi(Bloco); //Conversao char para decimal
				 				
				    if((Bloco1>=0 && Bloco1 <=127)&&(Classe=='a'|| Classe =='A')){
				    	
				    	 cidr=8; //Mascara Padrao do CIDR
				    	 EnderecoB = ConversaoBinario(EnderecoIP);
				         Mascara = MascaraRede(cidr);
				         EnderecoRede = EnderecoDeRede(EnderecoIP,Mascara);
				         BroadCast = EnderecoBroadcast(EnderecoIP,Mascara);
				         
				         cout<<"\n======================================================================"<<endl;
				         cout<<"                         Notacao Binaria                            \n"<<endl;
				         cout<<" IP...........................: "<<EnderecoB<<endl;
				         cout<<" Mascara......................: "<<Mascara<<endl;
				         cout<<" Endereco De Rede.............: "<<EnderecoRede<<endl;
				         cout<<" Endereco De Broadcast........: "<<BroadCast<<endl;
				         cout<<"\n======================================================================\n"<<endl;
				         
				         MascaraD = ConversaoDecimal(Mascara);
				         EnderecoRedeD = ConversaoDecimal(EnderecoRede);
				         BroadCastD = ConversaoDecimal(BroadCast);
				         nhost = pow(2,(32-cidr));
				         
				         cout<<"\n======================================================================"<<endl;
				         cout<<"                         Notacao Decimal                               \n"<<endl;
				         cout<<" IP...........................: "<<EnderecoIP<<endl;
				         cout<<" Mascara......................: "<<MascaraD<<endl;
				         cout<<" Endereco De Rede.............: "<<EnderecoRedeD<<endl;
				         cout<<" Endereco De Broadcast........: "<<BroadCastD<<endl;
				         cout<<" Numero De Hosts Por Rede.....: "<<nhost<<endl;
				         cout<<"\n======================================================================\n"<<endl;
					}
					else if((Bloco1>=128 && Bloco1 <=191)&&(Classe=='b'|| Classe =='B')){
						
					     cidr=16;
				    	 EnderecoB = ConversaoBinario(EnderecoIP);
				         Mascara = MascaraRede(cidr);
				         EnderecoRede = EnderecoDeRede(EnderecoIP,Mascara);
				         BroadCast = EnderecoBroadcast(EnderecoIP,Mascara);
				         
				         cout<<"\n======================================================================"<<endl;
				         cout<<"                         Notacao Binaria                            \n"<<endl;
				         cout<<" IP...........................: "<<EnderecoB<<endl;
				         cout<<" Mascara......................: "<<Mascara<<endl;
				         cout<<" Endereco De Rede.............: "<<EnderecoRede<<endl;
				         cout<<" Endereco De Broadcast........: "<<BroadCast<<endl;
				         cout<<"\n======================================================================\n"<<endl;
				         
				         MascaraD = ConversaoDecimal(Mascara);
				         EnderecoRedeD = ConversaoDecimal(EnderecoRede);
				         BroadCastD = ConversaoDecimal(BroadCast);
				         nhost = pow(2,(32-cidr));
				         
				         cout<<"\n======================================================================"<<endl;
				         cout<<"                         Notacao Decimal                               \n"<<endl;
				         cout<<" IP...........................: "<<EnderecoIP<<endl;
				         cout<<" Mascara......................: "<<MascaraD<<endl;
				         cout<<" Endereco De Rede.............: "<<EnderecoRedeD<<endl;
				         cout<<" Endereco De Broadcast........: "<<BroadCastD<<endl;
				         cout<<" Numero De Hosts Por Rede.....: "<<nhost<<endl;
				         cout<<"\n======================================================================\n"<<endl;
					}
					else if((Bloco1>=192 && Bloco1 <=223)&&(Classe=='C'|| Classe =='c')){
						
						 cidr=24;
				    	 EnderecoB = ConversaoBinario(EnderecoIP);
				         Mascara = MascaraRede(cidr);
				         EnderecoRede = EnderecoDeRede(EnderecoIP,Mascara);
				         BroadCast = EnderecoBroadcast(EnderecoIP,Mascara);
				         
				         cout<<"\n======================================================================"<<endl;
				         cout<<"                         Notacao Binaria                            \n"<<endl;
				         cout<<" IP...........................: "<<EnderecoB<<endl;
				         cout<<" Mascara......................: "<<Mascara<<endl;
				         cout<<" Endereco De Rede.............: "<<EnderecoRede<<endl;
				         cout<<" Endereco De Broadcast........: "<<BroadCast<<endl;
				         cout<<"\n======================================================================\n"<<endl;
				         
				         MascaraD = ConversaoDecimal(Mascara);
				         EnderecoRedeD = ConversaoDecimal(EnderecoRede);
				         BroadCastD = ConversaoDecimal(BroadCast);
				         nhost = pow(2,(32-cidr));
				         
				         cout<<"\n======================================================================"<<endl;
				         cout<<"                         Notacao Decimal                               \n"<<endl;
				         cout<<" IP...........................: "<<EnderecoIP<<endl;
				         cout<<" Mascara......................: "<<MascaraD<<endl;
				         cout<<" Endereco De Rede.............: "<<EnderecoRedeD<<endl;
				         cout<<" Endereco De Broadcast........: "<<BroadCastD<<endl;
				         cout<<" Numero De Hosts Por Rede.....: "<<nhost<<endl;
				         cout<<"\n======================================================================\n"<<endl;
					}
					else{
						 Erro = 1;
						 cout<<"\nClasse Informada Errada ou IP Nao Pertecente a Classe Informada "<<endl;
						 cout<<"Classe A -> 0 a 127 \n";
						 cout<<"Classe B -> 128 a 191 \n";
						 cout<<"Classe C -> 192 a 223  \n";
						 cout<<"OBS: IPS FORA DESSA FAIXA NAO ENTRA NESSA OPCAO DO PROGRAMA"<<endl;						 
					}
		  }while(Erro!=0);	 	
        break; //FIM DA OPCAO 1
        
        case 2:
        	 
			     do{
                   cout<<"Formato a ser Digitado (xxx.xxx.xxx.xxx)"<<endl;
                   cout<<"Informe um Endereco de IP: ";
                   cin>>EnderecoIP;
                   
                   Estado = IPValido(EnderecoIP);
                   
                   if(Estado== false){
                   cout<<"IP INVALIDO TENTE NOVAMENTE\n";}
                   }while(Estado == false);
                 do{
                   cout<<"Informe a Mascara desse IP: ";
                   cin>>MascaraD;
                   
                   string AuxMasc = ConversaoBinario(MascaraD);
                   Masc = MascaraValida(AuxMasc);
                   Estado = IPValido(MascaraD);
                   
                   vector<string> BlocoIp = SeparadorDeBlocos(MascaraD);
                   string Aux = BlocoIp[0]; 
					            
                 //Conversao String para Char
                 char Bloco[Aux.length()];
                       for(int i = 0;i<=Aux.length();i++){
					       Bloco[i] = Aux[i];}
				  Bloco1 = atoi(Bloco); //Conversao char para decimal
				  
                   if(Estado == false || Bloco1<255 || Masc == false){
                   cout<<"MASCARA INVALIDA TENTE NOVAMENTE\n";}
                   }while(Estado == false || Bloco1<255 || Masc == false);
                   
                         EnderecoB = ConversaoBinario(EnderecoIP);
                         MascaraAux= ConversaoBinario(MascaraD);
                         cidr = IdentificadorCIDR(MascaraAux);
				         Mascara = MascaraRede(cidr);
				         EnderecoRede = EnderecoDeRede(EnderecoIP,Mascara);
				         BroadCast = EnderecoBroadcast(EnderecoIP,Mascara);
				         IPInicial = EnderecoIPV4I(EnderecoRede);
				         IPFinal = EnderecoIPV4F(BroadCast);
				         
				         cout<<"\n======================================================================"<<endl;
				         cout<<"                         Notacao Binaria                            \n"<<endl;
				         cout<<" IP...........................: "<<EnderecoB<<endl;
				         cout<<" Mascara......................: "<<Mascara<<endl;
				         cout<<" Endereco De Rede.............: "<<EnderecoRede<<endl;
				         cout<<" Endereco De Broadcast........: "<<BroadCast<<endl;
				         cout<<" Endereco IPV4 Inicial........: "<<IPInicial<<endl;
				         cout<<" Endereco IPV4 Final..........: "<<IPFinal<<endl;
				         cout<<"\n======================================================================\n"<<endl;
				         
				         EnderecoRedeD = ConversaoDecimal(EnderecoRede);
				         BroadCastD = ConversaoDecimal(BroadCast);
				         IPFinalD  =  ConversaoDecimal(IPFinal);
						 IPInicialD =  ConversaoDecimal(IPInicial);
				         nhost = pow(2,(32-cidr))-2;
				         
				         cout<<"\n======================================================================"<<endl;
				         cout<<"                         Notacao Decimal                               \n"<<endl;
				         cout<<" IP...........................: "<<EnderecoIP<<endl;
				         cout<<" Mascara......................: "<<MascaraD<<endl;
				         cout<<" Endereco De Rede.............: "<<EnderecoRedeD<<endl;
				         cout<<" Endereco De Broadcast........: "<<BroadCastD<<endl;
				         cout<<" Endereco IPV4 Inicial........: "<<IPInicialD<<endl;
				         cout<<" Endereco IPV4 Final..........: "<<IPFinalD<<endl;
				         cout<<" Numero De Hosts Por Rede.....: "<<nhost<<endl;
				         cout<<"\n======================================================================\n"<<endl;
				         break;
				         
				
         case 3:
        	 do{
                   cout<<"Formato a ser Digitado (xxx.xxx.xxx.xxx)"<<endl;
                   cout<<"Informe um Endereco de IP: ";
                   cin>>EnderecoIP;
                   Estado = IPValido(EnderecoIP);
                   if(Estado== false){
                   cout<<"IP INVALIDO TENTE NOVAMENTE\n";}
                   }while(Estado == false);
                   do{
                   cout<<"Informe o CIDR (8 ate 32): ";
                   cin>>cidr;
                   if(cidr<=7 || cidr>32){
                   cout<<"CIDR INVALIDO TENTE NOVAMENTE\n";}
                   }while(cidr<=7 || cidr>32);
                   
                         EnderecoB = ConversaoBinario(EnderecoIP);
				         Mascara = MascaraRede(cidr);
				         EnderecoRede = EnderecoDeRede(EnderecoIP,Mascara);
				         BroadCast = EnderecoBroadcast(EnderecoIP,Mascara);
				         IPInicial = EnderecoIPV4I(EnderecoRede);
				         IPFinal = EnderecoIPV4F(BroadCast);
				         
				         cout<<"\n======================================================================"<<endl;
				         cout<<"                         Notacao Binaria                            \n"<<endl;
				         cout<<" IP...........................: "<<EnderecoB<<endl;
				         cout<<" Mascara......................: "<<Mascara<<endl;
				         cout<<" Endereco De Rede.............: "<<EnderecoRede<<endl;
				         cout<<" Endereco De Broadcast........: "<<BroadCast<<endl;
				         cout<<" Endereco IPV4 Inicial........: "<<IPInicial<<endl;
				         cout<<" Endereco IPV4 Final..........: "<<IPFinal<<endl;
				         cout<<"\n======================================================================\n"<<endl;
				         
				         EnderecoRedeD = ConversaoDecimal(EnderecoRede);
				         BroadCastD = ConversaoDecimal(BroadCast);
				         IPFinalD  =  ConversaoDecimal(IPFinal);
						 IPInicialD =  ConversaoDecimal(IPInicial);
						 MascaraD = ConversaoDecimal(Mascara);
				         nhost = pow(2,(32-cidr))-2;
				         
				         cout<<"\n======================================================================"<<endl;
				         cout<<"                         Notacao Decimal                               \n"<<endl;
				         cout<<" IP...........................: "<<EnderecoIP<<endl;
				         cout<<" Mascara......................: "<<MascaraD<<endl;
				         cout<<" Endereco De Rede.............: "<<EnderecoRedeD<<endl;
				         cout<<" Endereco De Broadcast........: "<<BroadCastD<<endl;
				         cout<<" Endereco IPV4 Inicial........: "<<IPInicialD<<endl;
				         cout<<" Endereco IPV4 Final..........: "<<IPFinalD<<endl;
				         cout<<" Numero De Hosts Por Rede.....: "<<nhost<<endl;
				         cout<<"\n======================================================================\n"<<endl;
				         break;
				         
        	
     case 4:
     	cout<<"Finalizando a Calculadora"<<endl;
     break; //Finalizando o Programa.
    }
	  
	} while(opcao_menu !=4);
  return 0;
}
