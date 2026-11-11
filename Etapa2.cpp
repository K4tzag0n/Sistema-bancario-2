#include <iostream>
#include <string>
#include <format>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {

    const int MAX_CONTAS = 100;
    const int MAX_MOVIMENTACOES = 500;

    int conta[MAX_CONTAS];
    string nome[MAX_CONTAS];
    string cpf[MAX_CONTAS];
    int tipo[MAX_CONTAS];
    double saldo[MAX_CONTAS];
    bool ativa[MAX_CONTAS];
    
    int contaMovimentacao[MAX_MOVIMENTACOES];
    int quantidadeMovimentacoes = 0;
    double valorMovimentacao[MAX_MOVIMENTACOES];
    char tipoMovimentacao[MAX_MOVIMENTACOES];

    int quantidadeContas = 0;
    int opcao;

    // ---- ( Menu ) ---- //
    do {
        cout << "===============================================\n";
        cout << "Banco Angelim\n";
        cout << "-----------------------------------------------\n";
        cout << " Contas Registradas: " << quantidadeContas << " / " << MAX_CONTAS;
        cout << " Movimentações: " << quantidadeMovimentacoes << " / " << MAX_MOVIMENTACOES << "\n";
        cout << "\n-----------------------------------------------\n";

        cout << "1 - Cadastrar\n";
        cout << "2 - Listar contas\n";
        cout << "3 - Verificar uma conta\n";
        cout << "4 - Retirar saldo\n";
        cout << "5 - Depositar saldo\n"
        cout << "6 - Depositar em outra conta\n"
        cout << "7 - Ativar/Desativar\n";
        cout << "0 - Sair\n";
        cout << "===============================================\n";
        
        cout << "Escolha uma opção: ";

        cin >> opcao;

        if (opcao == 1) {

            if (quantidadeContas >= MAX_CONTAS) {
                cout << "Limite de contas atingido!\n";
            } else {

                cout << "Numero da conta: ";
                cin >> conta[quantidadeContas];

                while (conta[quantidadeContas] <= 0) {
                    cout << "Numero invalido, Por favor use numeros maiores que 0. Digite novamente: ";
                    cin >> conta[quantidadeContas];
                }

                cin.ignore();

                cout << "Nome: ";
                getline(cin, nome[quantidadeContas]);

                cout << "CPF: ";
                getline(cin, cpf[quantidadeContas]);

                cout << "Tipo (1-Corrente / 2-Poupanca): ";
                cin >> tipo[quantidadeContas];

                while (tipo[quantidadeContas] != 1 && tipo[quantidadeContas] != 2) {
                    cout << "Tipo invalido. Digite 1 ou 2: ";
                    cin >> tipo[quantidadeContas];
                }

                cout << "Saldo inicial: ";
                cin >> saldo[quantidadeContas];

                while (saldo[quantidadeContas] < 0) {
                    cout << "Saldo invalido. Digite novamente: ";
                    cin >> saldo[quantidadeContas];
                }

                ativa[quantidadeContas] = true;
                quantidadeContas++;

                cout << "Conta cadastrada!\n";
            }

        } else if (opcao == 2) {
            cout << "\n================";
            
            for (int n = 1; n <= quantidadeContas; n++) {
                cout << "\n---------\n";
                cout << "Conta ";
                cout << n;
                
                cout << "\nNumero da conta: ";
                cout << conta[n];
                
                cout << "\nDono: ";
                cout << nome[n];
            }
            
            //cout << "\n================\n";

        } else if (opcao == 3) {
            
            int numeroConta;
            cout << "Numero da conta: ";
            cin >> numeroConta;
                
            for (int i = 1; i <= quantidadeContas; i++) {
                if (conta[i] == numeroConta) {
                    if (ativa[i]) {
                        cout << "\nDono: ";
                        cout << nome[i];
                        
                        cout << "\nCPF: ";
                        cout << cpf[i];
                        
                        cout << "\nSaldo: ";
                        cout << saldo[i];
                        
                        cout << "\n"
                    } else {
                        cout << "Essa conta não foi registrada ou esta inativa.\n";
                    }
                }
            }
            
        } else if (opcao == 4) {
            
            if (quantidadeMovimentacoes >= MAX_MOVIMENTACOES) {
                cout >> "Foi mal, teu free trial acabou."
            } else {
                quantidadeMovimentacoes++
                
                int numeroConta;
                cout << "Numero da conta: ";
                cin >> numeroConta;
                
                int deposito;
                cout << "Quantidade: ";
                cin >> deposito;
                
                for (int i = 1; i <= quantidadeContas; i++) {
                    if (conta[i] == numeroConta) {
                        if (saldo[i] - deposito >= 0) {
                            saldo[i] = saldo[i] - deposito
                            cout << "Saldo retirado.\n"
                        } else {
                            cout << "A quantidade é maior do que há na conta.\n"
                        }
                    }
                }
            }
            
        } else if (opcao == 5) {
            
            if (quantidadeMovimentacoes >= MAX_MOVIMENTACOES) {
                cout >> "Foi mal, teu free trial acabou."
            } else {
                quantidadeMovimentacoes++
                
                int numeroConta;
                cout << "Numero da conta: ";
                cin >> numeroConta;
                
                int deposito;
                cout << "Quantidade: ";
                cin >> deposito;
                
                for (int i = 1; i <= quantidadeContas; i++) {
                    if (conta[i] == numeroConta) {
                        saldo[i] = saldo[i] + deposito
                        cout << "Saldo depositado.\n"
                    }
                }
            }
        
        } else if (opcao == 6) {
            
            if (quantidadeMovimentacoes >= MAX_MOVIMENTACOES) {
                cout >> "Foi mal, teu free trial acabou."
            } else {
                quantidadeMovimentacoes++
                
                int numeroContaPri;
                cout << "Numero da conta a transferir: ";
                cin >> numeroContaPri;
                
                int numeroContaSec;
                cout << "Numero da conta a receber: ";
                cin >> numeroContaSec;
                
                int quantDeposito;
                cout << "Quantidade do deposito: ";
                cin >> quantDeposito;
                
                if (saldo[numeroContaPri] - quantDeposito > 0) {
                    saldo[numeroContaPri] = saldo[numeroContaPri] - quantDeposito
                    saldo[numeroContaSec] = saldo[numeroContaSec] + quantDeposito
                    
                    cout << "Saldo depositado.\n"
                } else {
                    cout << "A conta não possui o suficiente para a transferencia.\n"
                }
            }
        
        } else if (opcao == 7) {

            int numero;
            cout << "Numero da conta: ";
            cin >> numero;

            for (int i = 0; i < quantidadeContas; i++) {
                if (conta[i] == numero) {

                    if (ativa[i]) {
                        ativa[i] = false;
                        cout << "Conta desativada!\n";
                    } else {
                        ativa[i] = true;
                        cout << "Conta ativada!\n";
                    }
                }
            }

        } else if (opcao == 0) {

            cout << "Programa encerrado!\n";

        } else {

            cout << "Opcao invalida!\n";
        }

    } while (opcao != 0);

    return 0;
}