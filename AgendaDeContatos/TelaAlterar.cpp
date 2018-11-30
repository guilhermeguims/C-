#include "TelaAlterar.h"
#include "ui_TelaAlterar.h"
#include"Agenda.h"
#include"Contato.h"
#include<QMessageBox>

TelaAlterar::TelaAlterar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TelaAlterar)
{
    ui->setupUi(this);
    ui->pushButton_alterar->setEnabled(false);
}

TelaAlterar::~TelaAlterar()
{
    delete ui;
}
//Validando Email
bool ValidoEmail(QString Email) {
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
        // Verficando se Comeca com '.' ou '@'
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
void TelaAlterar::on_pushButton_clicked()
{
  try{
    TP2::Agenda ContatoNaAgenda("AgendaDeContato.CSV");
    QString CPF = ui->lineEdit_Busca->text();
    TP2::Contato * ContatoAlterar = ContatoNaAgenda.Alterar(CPF);
    //Verificando se a LineEdit esta Vazia
    if(CPF == ""){
        QMessageBox::information(this, "Erro","Campo CPF Vazio !");
        }
    //Verificando se o Contato Existe
    if(ContatoAlterar->GetCPF()==""){
        QMessageBox::information(this, "Erro","Contato Nao Se Encontra na Agenda !");
        }
    else{
    //MOSTRANDO OS DADOS DO CONTATO NA LINEDIT
    ui->lineEdit_Nome_3->setText(ContatoAlterar->GetNome());
    ui->lineEdit_CPF_3->setText(ContatoAlterar->GetCPF());
    ui->lineEdit_CPF_3->setEnabled(false);
    ui->lineEdit_Email_3->setText(ContatoAlterar->GetEmail());
    ui->lineEdit_Logradouro->setText(ContatoAlterar->GetEndereco()->getLogradouro());
    ui->lineEdit_EnderecoNumero->setText(QString::number(ContatoAlterar->GetEndereco()->getNumero()));
    ui->LineEdit_CEP->setText(QString::number(ContatoAlterar->GetEndereco()->getCep()));
    ui->lineEdit_TelefoneNumero_2->setText(QString::number(ContatoAlterar->GetTelefone()->getNumero()));
    ui->lineEdit_DDD_2->setText(QString::number(ContatoAlterar->GetTelefone()->getDDD()));
    ui->lineEdit_DDI_2->setText(QString::number(ContatoAlterar->GetTelefone()->getDDI()));
    ui->pushButton_3->setEnabled(false); // Desativando o Botao Voltar
    ui->pushButton_alterar->setEnabled(true); //Atilvando o Botao Salvar
    ui->lineEdit_Busca->clear();//Limpando o que o Usuario digitou na LineEdit Busca
}
    }catch(std::bad_alloc&){
        QMessageBox::information(this, "Erro no Sistema","Metodo editar nao pode ser execultado");
    }
}

void TelaAlterar::on_pushButton_3_clicked()
{
    TelaAlterar::close(); //Voltando para a Tela Principal
}

void TelaAlterar::on_pushButton_alterar_clicked()
{
    try{
   //Verificando os Campos Obrigatorios
        if(ui->lineEdit_CPF_3->text()=="" || ui->lineEdit_Email_3->text()=="" || ui->lineEdit_Nome_3->text()=="" || ui->lineEdit_DDD_2->text()=="" || ui->lineEdit_DDI_2->text()=="" || ui->lineEdit_TelefoneNumero_2->text()==""){
            QMessageBox::information(this, "Erro","Campos Obrigatorios Nao Prenchidos");
        }
    else{
    TP2::Contato Individuo;
    //NOME
    QString Nome = ui->lineEdit_Nome_3->text();
    //TELEFONE
    int fone = ui->lineEdit_TelefoneNumero_2->text().toInt();
    int DDI = ui->lineEdit_DDI_2->text().toInt();
    int DDD = ui->lineEdit_DDD_2->text().toInt();
    TP2::Telefone *Num = new TP2::Telefone(DDI,DDD,fone);
    //CPF
    QString CPF = ui->lineEdit_CPF_3->text();
    //EMAIL
    QString Email = ui->lineEdit_Email_3->text();
    int Valido=0;
    if(ValidoEmail(Email)==true){
            Valido++;
        }
        else{
            QMessageBox::information(this, "Erro","Email Invalido");
        }
    //ENDERECO
    QString Logradouro = ui->lineEdit_Logradouro->text();
    int EnderecoNumero = ui->lineEdit_EnderecoNumero->text().toInt();
    int EnderecoCEP = ui->LineEdit_CEP->text().toInt();
    TP2::Endereco *EnderecoDoContato =  new TP2::Endereco(Logradouro,EnderecoNumero,EnderecoCEP);
  if(Valido==1){
    //Incluindo Na Agenda
    TP2::Agenda ContatoNaAgenda("AgendaDeContato.CSV");
    Individuo.SetNome(Nome);
    Individuo.SetTelefone(Num);
    Individuo.SetCPF(CPF);
    Individuo.SetEmail(Email);
    Individuo.SetEndereco(EnderecoDoContato);
    ContatoNaAgenda.Incluir(Individuo);
    QMessageBox::information(this,"Alteracao De Contato",Individuo.GetNome()+" Alterado Com Sucesso");
    //Limpando as LineEdits
    ui->lineEdit_Nome_3->clear();
    ui->lineEdit_CPF_3->clear();
    ui->lineEdit_Email_3->clear();
    ui->lineEdit_TelefoneNumero_2->clear();
    ui->lineEdit_DDD_2->clear();
    ui->LineEdit_CEP->clear();
    ui->lineEdit_DDI_2->clear();
    ui->lineEdit_Logradouro->clear();
    ui->lineEdit_EnderecoNumero->clear();
    ui->pushButton_alterar->setEnabled(false); //Desativando o Botao Salva
    ui->pushButton_3->setEnabled(true); //Ativando o Botao Voltar
    }
 }
    }
    catch(std::bad_alloc&){
        QMessageBox::information(this, "Erro no Sistema","Metodo Alterar nao pode ser execultado");
    }
}
