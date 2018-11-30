#include "TelaIncluir.h"
#include "ui_TelaIncluir.h"
#include"Contato.h"
#include"Agenda.h"
#include"Telefone.h"
#include"Endereco.h"
#include<QMessageBox>
TelaIncluir::TelaIncluir(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TelaIncluir)
{
    ui->setupUi(this);
}
TelaIncluir::~TelaIncluir()
{
    delete ui;
}
//Validando CPF
bool CPFValido(QString CPF) {
    int Tamanho = CPF.size(); //Tamanho Do CPF
    int DigitoDois = 0;
    int DigitoUm = 0;
    // Verifica se Tem 11 Digitos
        if(Tamanho!=11){
            return false; //CPF Invalido
        }
        else{
          //Separando o CPF Em Digitos
          int Num1 = CPF[0].digitValue();
          int Num2 = CPF[1].digitValue();
          int Num3 = CPF[2].digitValue();
          int Num4 = CPF[3].digitValue();
          int Num5 = CPF[4].digitValue();
          int Num6 = CPF[5].digitValue();
          int Num7 = CPF[6].digitValue();
          int Num8 = CPF[7].digitValue();
          int Num9 = CPF[8].digitValue();
          int Num10 = CPF[9].digitValue();
          int Num11 = CPF[10].digitValue();

          int Soma;
          int Resto;
          //Mutiplica os 9 Primeiros Digitos por uma Sequencia de 10 até 2
          Soma=(Num1*10)+(Num2*9)+(Num3*8)+(Num4*7)+(Num5*6)+(Num6*5)+(Num7*4)+(Num8*3)+(Num9*2);
          //Pega o Resultado da Soma Multiplica por 10 e Diividi por 11 e Pegue o Resto
          Resto = (Soma*10)%11;
          //Verifica se o Resto é 10 , Caso For Considere o Primeiro Digito Verifcador como 0
          if(Resto == 10){
               if(Num10 == 0){
                   DigitoUm++; //Digito Valido
               }
          }
          // Verifica se o Resto é Igual ao Primeiro Digito Verificador do CPF
          if(Resto == Num10){
               DigitoUm++; //Digito Valido
          }
          // Se o Primeiro Digito Verificador For Válido , Verificar o Segundo
          if(DigitoUm == 1){
               //Mutiplica os 10 Primeiros Digitos por uma Sequencia de 11 até 2
              Soma=(Num1*11)+(Num2*10)+(Num3*9)+(Num4*8)+(Num5*7)+(Num6*6)+(Num7*5)+(Num8*4)+(Num9*3)+(Num10*2);
              //Pega o Resultado da Soma Multiplica por 10 e Diividi por 11 e Pegue o Resto
              Resto = (Soma*10)%11;
               //Verifica se o Resto é 10 , Caso For Considere o Segundo Digito Verifcador como 0
              if(Resto == 10){
                   if(Num11 == 0){
                       DigitoDois++; //Digito Valido
                   }
              }
               // Verifica se o Resto é Igual ao Segundo Digito Verificador do CPF
              if(Resto == Num11){
                   DigitoDois++;
              }

          }
        }
     // Condiçao para o CPF ser Válido
    if(DigitoUm==1 && DigitoDois == 1){
        return true; //CPF Válido
    }
    else{
        return false; //CPF Invalido
    }

}
//Validando Email
bool EmailValido(QString Email) {
  std::string Aux = Email.toStdString();
  int Arroba = 0;
  int Encontrado = 0;
  int Erro = 0;
  int Tamanho = Aux.size();
  for(int i =0;i<=Tamanho;i++){
     //Caracteres Da Tabela ASCII Que Nao Podem Ser Usados
        // Tabela ASCII DO 33 AO 45
        for(int j=33;j<=44;j++){
         if(Aux[i]==j){
         return false;  //Email Invalido
            }
        }
        // Tabela ASCII 47
        if(Aux[i]==47){
         return false;  //Email Invalido
        }
        // Tabela ASCII DO 58 AO 63
        for(int j=58;j<=63;j++){
            if(Aux[i]==j){
            return false;  //Email Invalido
            }
        }
        // Tabela ASCII DO 91 AO 94
        for(int j=91;j<=94;j++){
            if(Aux[i]==j){
            return false;  //Email Invalido
            }
        }
         // Tabela ASCII 96
        if(Aux[i]==96){
         return false;  //Email Invalido
        }
        // Tabela ASCII DO 123 AO 254
        for(int j=123;j<=254;j++){
            if(Aux[i]==j){
            return false;  //Email Invalido
            }
        }
        // Verficando se Começa com '.' ou '@'
        if(Aux[0]=='.' || Aux[0]=='@' || Aux[0]==' '){
            return false;  //Email Invalido
        }
        //Verifica se o Email Termina com Ponto
        if(Aux[Tamanho-1]=='.'){
            Erro++;
        }
        // Verificando se Tem '@'
        else if(Aux[i] =='@' && Aux[i+1]!='.'){
             Arroba++;
                  // Verfica se Depois do '@' tem o '.'
                   for(int j = i+2;j<=Tamanho;j++){
                      if(Aux[j]=='.' && Aux[j+1]!='.'){
                           Encontrado++;
                      }
                      // Verifica se Tem '.' e '.' Juntos
                      if(Aux[j]=='.' && Aux[j+1]=='.'){
                          Erro++;
                      }

     }
}
  }
  // Testa se o Email passou em todos os testes pra ser Valido
  if(Arroba==1 && Encontrado>0 && Erro==0){
      return true; // Email Valido
  }
  else{
      return false; //Email Invalido
  }
}
void TelaIncluir::on_pushButton_Incluir_clicked()
{
    try{
    TP2::Agenda ContatoNaAgenda("AgendaDeContato.CSV");
    TP2::Contato Individuo;
    int Valido=0; //Variavel pra Verificar CPF e Email
    //NOME
    QString Nome = ui->lineEdit_Nome->text();
    //TELEFONE
    int fone = ui->lineEdit_TelefoneNumero->text().toInt();
    int DDI = ui->lineEdit_DDI->text().toInt();
    int DDD = ui->lineEdit_DDD->text().toInt();
    TP2::Telefone *Num = new TP2::Telefone(DDI,DDD,fone);
    //CPF
    QString CPF = ui->lineEdit_CPF->text();
    //Relaliza a Busca e Verifica se o CPF ja Foi Cadastrado para Outro Usuario
    std::list<TP2::Contato> * ContatoDaAgenda = ContatoNaAgenda.Consultar(CPF);
    if(!ContatoDaAgenda->empty()){
       QMessageBox::information(this, "Erro","CPF Ja Se Encontra na Agenda");
    }
    else{
    if(CPFValido(CPF)==true){
        Valido++;
    }
    else{
        QMessageBox::information(this, "Erro","CPF Invalido");
    }
   }
    //Email
    QString Email = ui->lineEdit_Email->text();
    if(EmailValido(Email)==true){
        Valido++;
    }
    else{
        QMessageBox::information(this, "Erro","Email Invalido");
    }
    //ENDERECO
    QString Logradouro = ui->lineEdit_EnderecoLogradouro->text();
    int EnderecoNumero = ui->lineEdit_EnderecoNumero->text().toInt();
    int EnderecoCEP = ui->LineEdit_CEP->text().toInt();
    TP2::Endereco *EnderecoDoContato =  new TP2::Endereco(Logradouro,EnderecoNumero,EnderecoCEP);
    //Verificando os Campos Obrigatorios
    if(ui->lineEdit_CPF->text()=="" || ui->lineEdit_Email->text()=="" || ui->lineEdit_Nome->text()=="" || ui->lineEdit_DDD->text()=="" || ui->lineEdit_DDI->text()=="" || ui->lineEdit_TelefoneNumero->text()==""){
        QMessageBox::information(this, "Erro","Campos Obrigatorios Nao Prenchidos");
    }
    else if(Valido==2){ //So Vai Incluir se o Email e o CPF for Validos
    //Incluindo Na Agenda
    Individuo.SetNome(Nome);
    Individuo.SetTelefone(Num);
    Individuo.SetCPF(CPF);
    Individuo.SetEmail(Email);
    Individuo.SetEndereco(EnderecoDoContato);
    ContatoNaAgenda.Incluir(Individuo);
    QMessageBox::information(this,"Inclusao De Contato",Individuo.GetNome()+" Incluido Com Sucesso");
    //Limpando as LineEdits
    ui->lineEdit_Nome->clear();
    ui->lineEdit_CPF->clear();
    ui->lineEdit_Email->clear();
    ui->lineEdit_TelefoneNumero->clear();
    ui->lineEdit_DDD->clear();
    ui->LineEdit_CEP->clear();
    ui->lineEdit_DDI->clear();
    ui->lineEdit_EnderecoLogradouro->clear();
    ui->lineEdit_EnderecoNumero->clear();
    }
    }catch(std::bad_alloc&){
        QMessageBox::information(this, "Erro no Sistema","Metodo Incluir nao pode ser execultado");
    }
}

void TelaIncluir::on_pushButton_Voltar_clicked()
{
     TelaIncluir::close();  //Voltando para Tela Principal
}

